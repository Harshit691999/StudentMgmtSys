#ifndef STUDENT_H
#define STUDENT_H

#include "base.h"
#include "fileheader.h"

class studentclass: public Baseclass
{
    private:

        float attendance = 0.0f, overallscore= 0.0f;
    
    public:

        explicit studentclass(){};
        explicit studentclass(std::string&, std::string&, std::string&, short&);

        // void set_rollnumber(int);

        void set_attendance(float); // to set student attendance
        void set_overallscore(float); // to set student overscore, need to apply formula to calculate score 
        void writer_infile(); // this will write data in file
        void writer_infile_dat(); // this will write the binary data in file
        void search_student(int*);
        void deleterecord(int&); 
        void search_update(int&, float&, float& ); //accepting the reference to id
        void read_from_file(const std::ifstream&);



        void get_rollnumber() const;
        void get_overallscore() const;
        void get_attendace() const;
        short get_student_id() const;
        
        void get_student_details() const; // this can be accessed by both student and teacher as both can see details.
        void see_all_records();
};

#endif