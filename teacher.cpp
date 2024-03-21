#include "teacher.h"
using namespace std;


teacherclass::teacherclass(){};

teacherclass::teacherclass(std::string name, std::string email, std::string address): Baseclass::Baseclass(name, email, address) {};

void teacherclass::editStudentInfo(studentclass &sop,string newn, string newemail, string newaddress)
{
    //std::cout<<"I will update student record\n\n";
    sop.Baseclass::update_name(newn);
    sop.Baseclass::update_email(newemail);
    sop.Baseclass::update_address(newaddress);
}

void teacherclass::teacher_set_attendance(studentclass *sop, float att)
{
    (*sop).studentclass::set_attendance(att);
}

void teacherclass::teacher_set_overallscore(studentclass &sop, float oas)
{   
    sop.studentclass::set_overallscore(oas);
    //sop.overallscore;
}

// now I know why we are using functio instead of data members, as data members are protected and can be shared among classed not with their object 
// not even with their own object