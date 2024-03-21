// Baseclass.h
#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>
#include "fileheader.h"

//extern int ID;

// this class is just to store the comman data.
class Baseclass {
protected:
    std::string name;
    std::string email;
    std::string address;
    short rollnumber, student_id;

public:

    explicit Baseclass(); // default to not initialize

    explicit Baseclass(std::string, std::string, std::string); // for teacher object

    explicit Baseclass(std::string,std::string,std::string,short); // for student object
    
    void set_basic_info();

    void update_name(std::string);
    void update_email(std::string);
    void update_address(std::string);

    void set_name();
    void set_email();
    void set_address();
    void set_rollnumber();
    void set_studentid();

    void get_basic_info() const;
    void get_name() const;
    void get_email() const;
    void get_address() const;
    void get_rollnumber() const;
    void get_studentid() const;
};

#endif // BASECLASS_H
