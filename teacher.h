#pragma once

#include <iostream>
#include <string>

#include "base.h"
#include "student.h"
#include "fileheader.h"


class teacherclass:public Baseclass
{
    public:
    
        explicit teacherclass();
        explicit teacherclass(std::string, std::string, std::string);
        
        void editStudentInfo(studentclass& ,std::string, std::string, std::string);
        void teacher_set_attendance(studentclass *, float);
        void teacher_set_overallscore(studentclass&, float);
};