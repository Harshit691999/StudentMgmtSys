#include <iostream>
#include <string>
#include "student.h"
#include "base.h"
#include "teacher.h"
#include "fileheader.h"

void searchStudentRecord()
{
    int id;
    std::cout << "\tEnter id to search: ";
    std::cin >> id;
    studentclass ss;
    ss.search_student(&id);
    //delete ss;
}

void viewRecords()
{
    studentclass *readallrecord = new studentclass;
    (*readallrecord).see_all_records();
    delete readallrecord;
}

void deleteStudentRecord()
{
    int id;
    std::cout<<"\tEnter id to delete record: ";std::cin>>id;
    studentclass s;
    s.deleterecord(id);
}

void updateStudentRecord()
{
/*     int id;
    std::cout << "\t\tEnter id for which you want to update record: ";
    std::cin >> id;
    studentclass *ss = new studentclass;
    (*ss).update_record(id); */
    int id;
    float smarks, sattendance;
    std::cout<<"Enter the id: ";std::cin>>id;
    std::cout<<"Enter the marks to update: "; std::cin>>smarks;
    std::cout<<"Enter the Attendance to update: "; std::cin>>sattendance;
    //float sa = 92.5f;
    //float sb = 89.34f;
    //studentclass *ss = new studentclass;
    studentclass ss;
    ss.search_update(id,sattendance,smarks);
    //delete ss;

}

void addStudent()
{
    std::string sname, semail, saddress;
    short srln;
    std::cin.ignore();
    std::cout << "\t\tEnter Name: ";
    getline(std::cin, sname);
    std::cout << "\t\tEnter Email address: ";
    getline(std::cin, semail);
    std::cout << "\t\tEnter Address: ";
    getline(std::cin, saddress);
    std::cout << "\t\tEnter RollNumber: ";
    std::cin >> srln;
    studentclass *news = new studentclass(sname, semail, saddress, srln);
    (*news).writer_infile();
    delete news;
    std::cout<<"\n";
}

void scrud_menu() // these are file functions
{
    int choice;
    do
    {
        std::cout << "Select from following options\n";
        std::cout << "\t1. Add Student Record\n";
        std::cout << "\t2. Read Students Record\n";
        std::cout << "\t3. Search Student Record\n";
        std::cout << "\t4. Update Student Record\n";
        std::cout << "\t5. Delete Student Record\n";
        std::cout << "\t6. Exit\n";
        std::cout << "\tEnter your choice: ";
        std::cin >> choice;
        std::cout<<"\n";

        switch (choice)
        {
        case (1):
            addStudent();
            break;

        case (2):
            viewRecords();
            break;

        case (3):
            searchStudentRecord();
            break;

        case (4):
            updateStudentRecord();
            break;
        case (5):
            deleteStudentRecord();
            break;
        case (6):
            exit(1000);
            // std::cout<<"You are on main menu\n";
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    } while (choice != 6);
}

void teachermenu()
{
    std::cout << "Welcome to Teacher's Menu\n";
    std::cout << "Choose from the options\n";
    std::cout << "\t1. Add Student Record\n";
    std::cout << "\t2. Set Student Attendance\n";
    std::cout << "\t3. Set Student Overallscore\n";
}

int main()
{

    scrud_menu();

    return 0;

    /* searchStudentRecord();

    writeobj_student.open("student.txt", std::ios::app);   // it show we can open file in main as well

    studentclass *s3 = new studentclass("Ram","Ram@gmail.com","Dubai",7);
    s3->get_student_details();

    std::cout<<"\n\n";

    studentclass s1("Harshit","harshit.gupta@gmail","Delhi 2323",12);
    studentclass s2("Rahul","rahul@gmail.com","Mumbai 232",14);

    teacherclass t1;

    t1.teacher_set_attendance(&s1,80);
    t1.teacher_set_overallscore(s1,90);
    s1.writer_infile();
    s1.get_student_details();

    std::cout<<"\n\n";

    t1.teacher_set_attendance(&s2,90);
    t1.teacher_set_overallscore(s2,100);
    s2.writer_infile();
    s2.get_student_details();

    (*s3).writer_infile();

    delete s3;

    writeobj_student.close(); // we can close file here as well



    std::ifstream readobj_student;
    readobj_student.open("student.txt");
    std::string ro;
    ro = readobj_student.get();
    while ( ! readobj_student.eof() )
    {
        std::cout<<ro;
        ro = readobj_student.get();
    }

    readobj_student.close();

    srud_menu();
 */
}
