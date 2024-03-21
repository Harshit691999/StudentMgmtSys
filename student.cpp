#include <iostream>
#include <string>
#include "student.h"

using std::string;

std::ofstream writeobj_student;
std::ifstream readobj_student;

// writeobj_student.open("student.txt");  // open function can be used inside the function only as open is the members function of ofstream

studentclass::studentclass(string& name, string& email, string& address, short& rln) : Baseclass::Baseclass(name, email, address, rln){};

// void studentclass::set_rollnumber(int rln)
// {
//     rollnumber = rln;
// }

void studentclass::set_attendance(float set_att)
{
    studentclass::attendance = set_att;
}

void studentclass::set_overallscore(float set_overallscore)
{
    studentclass::overallscore = set_overallscore;
}

void studentclass::writer_infile()
{
    writeobj_student.open("student.txt", std::ios::app); // can be shifted to main function as well.
    if (writeobj_student.is_open())
    {
        // writeobj_student<<Baseclass::student_id<<Baseclass::rollnumber;
        writeobj_student << Baseclass::student_id << ","; // it will work as primary key while searching and updating from file
        writeobj_student << Baseclass::rollnumber << ",";
        writeobj_student << Baseclass::name << ",";
        writeobj_student << Baseclass::email << ",";
        writeobj_student << Baseclass::address << ",";
        writeobj_student << studentclass::attendance << ",";
        writeobj_student << studentclass::overallscore << ",";
        writeobj_student << "\n";
    }
    writeobj_student.close();
}

void studentclass::writer_infile_dat()
{
    writeobj_student.open("newstudent.dat", std::ios::binary | std::ios::app);
    if (writeobj_student.is_open())
    {
        writeobj_student.write((char *)this, sizeof(this));
    }
    writeobj_student.close();
}

void studentclass::get_rollnumber() const
{
    std::cout << "Roll number is: " << studentclass::rollnumber << "\n";
}

void studentclass::get_student_details() const
{
    Baseclass::get_basic_info();
    std::cout << "Total Attendance: " << studentclass::attendance << "\n";
    std::cout << "Overall score: " << studentclass::overallscore << "\n";
}

void studentclass::see_all_records()

{
    std::string read;
    readobj_student.open("student.txt", std::ios::in);
    if (!readobj_student.is_open())
    {
        std::cout << "File does not exixts\n";
    }
    else
    {
        while (getline(readobj_student, read))
        {
            std::cout << "\t\t" << read << "\n";
        }
    }
    readobj_student.close();
    std::cout << "\n\n";
}

void studentclass::read_from_file(const std::ifstream &rof)
{
    // readobj_student will read all the content in a line and then make conversion 
    // accordingly
    char comma;
    readobj_student >> comma >> this->rollnumber >> comma;
    getline(readobj_student, this->name, ',');
    getline(readobj_student, this->email, ',');
    getline(readobj_student, this->address, ',');
    readobj_student >> this->attendance >> comma >> this->overallscore >> comma;
}

void studentclass::search_student(int *ptr)
{
    readobj_student.open("student.txt", std::ios::in);
    
    if (!readobj_student.is_open())
    {
        std::cout << "Error while opening the file\n";
    }
    /* else {
        //readobj_student.seekg(0);
        read_from_file(readobj_student);
        while (student_id!=*ptr)
        {
            read_from_file(readobj_student);
        }
        get_student_details();
    } */

    /* else if ( *ptr > ID )
    {
        std::cout<<"the value of ID is: "<<ID<<"\n";
        std::cout<<"\t\tID does not exists\n";
    } */

    else
    {
        while (readobj_student >> this->student_id)
        {
            read_from_file(readobj_student);
            if (student_id == *ptr)
            {
                get_student_details();
                break;
            }
        }
    }
    /* else {
        std::string line;
        while (getline(readobj_student,line))
        {
            if ( (int(line[0])-48) == *ptr )
            In the above line of code I am converting the index 0 of string
            that will be treaed as char to int and then subtracting the ascii
            value from it to get numberical values.
            {
                std::cout<<line<<"\n";
                readobj_student.close();
                break;
            }
        }
    } */

    readobj_student.close();
    std::cout << "\n\n";
}

void studentclass::search_update(int &refid, float &newatten, float &score)
{
    bool updated = false;
    readobj_student.open("student.txt", std::ios::in | std::ios::out);
    std::ofstream tempfile;
    tempfile.open("temp.txt", std::ios::out | std::ios::app);

    if (!readobj_student.is_open() || !tempfile.is_open())
    {
        std::cout << "Error while opening the file\n";
    }
    else
    {
        while (readobj_student >> student_id)
        {
            read_from_file(readobj_student);
            if (student_id == refid)
            {
                this->attendance = newatten;
                (*this).overallscore = score;
                updated = true;
            }
            tempfile << student_id << ",";
            tempfile << rollnumber << ",";
            tempfile << name << ",";
            tempfile << email << ",";
            tempfile << address << ",";
            tempfile << attendance << ",";
            tempfile << overallscore << ",";
            tempfile << "\n";
        }
    }
    readobj_student.close();
    tempfile.close();
    if (updated)
    {
        std::remove("student.txt");
        std::rename("temp.txt", "student.txt");
    }
}

void studentclass::deleterecord(int& id)
{
    readobj_student.open("student.txt",std::ios::in);
    std::ofstream tempfile;
    tempfile.open("tempfile.txt",std::ios::out|std::ios::app);
    if (!readobj_student.is_open() || !tempfile.is_open())
    {
        std::cout << "Error while opening the file\n";
    }
    else 
    {
        while(readobj_student>>this->student_id)
        {
            read_from_file(readobj_student);
            if (student_id != id )
            {
                tempfile << student_id << ",";
                tempfile << rollnumber << ",";
                tempfile << name << ",";
                tempfile << email << ",";
                tempfile << address << ",";
                tempfile << attendance << ",";
                tempfile << overallscore << ",";
                tempfile << "\n";
            }
        }
        
    }
    readobj_student.close();
    tempfile.close();
    std::remove("student.txt");
    std::rename("tempfile.txt","student.txt");
}

/* void studentclass::update_record(int& id)
{
    readobj_student.open("student.txt",std::ios::in);
    if ( !readobj_student.is_open() )
    {
        std::cout<<"Error while opening the file\n";
    }
    else {
        std::string line;
        while (getline(readobj_student,line))
        {
            if ( (int(line[0])-48) == id ) break;
            // In the above line of code I am converting the index 0 of string
            // that will be treaed as char to int and then subtracting the ascii
            // value from it to get numberical values.
            string *ptrstr = &line;
            const string del = ",";
            string *buffer = new string;
            short bufferindex = 0, counter = 0;
            while ( *ptrstr != "\0" )
            {
                if ( *ptrstr != del ) {
                    *(buffer+bufferindex) = *ptrstr;
                    bufferindex ++;
                }
                else {
                    *(buffer+bufferindex) = "\0";
                    if ( counter == 1 ) this->name = *buffer ;
                    if ( counter == 2 ) this->email = *buffer;
                    if ( counter == 3 ) this->address = *buffer;
                    // if ( counter == 4 ) this->overallscore = (float)*buffer;
                    // if ( counter == 5 ) this->attendance = *buffer;
                }
            }
        }
    }
} */