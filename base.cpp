#include <iostream>

#include "base.h"

//int ID;

Baseclass::Baseclass(){};

Baseclass::Baseclass(std::string n, std::string email, std::string a) : name(n), email(email), address(a) {}; // for teacher

Baseclass::Baseclass(std::string n, std::string email, std::string a, short rln) : name(n), email(email), address(a), rollnumber(rln){

    std::ifstream readobj_studentid("id.txt");

    if ( readobj_studentid.is_open() ) {
        readobj_studentid>>Baseclass::student_id;
        //ID = Baseclass::student_id; 
    }
    else {
        std::cout<<"Error while opening the Student ID file\n";
    }
    readobj_studentid.close();

    std::ofstream writeobj_studentid("id.txt");
    if (!writeobj_studentid.is_open()){
        std::cout<<"error while opening the student id file\n";
    }
    
    Baseclass::student_id++;
    writeobj_studentid<<Baseclass::student_id;
    writeobj_studentid.close();
        
}; // for studnets

void Baseclass::set_basic_info()
{
    // Baseclass::name;
    // Baseclass::email;
    // Baseclass::address;
}

void Baseclass::get_basic_info() const {
    std::cout << "ID: " << Baseclass::student_id <<std::endl;
    std::cout << "Roll Number: "<< Baseclass::rollnumber <<"\n";
    std::cout << "Name: " << Baseclass::name << std::endl;
    std::cout << "Email: " << Baseclass::email << std::endl;
    std::cout << "Address: " << Baseclass::address << std::endl;
}


void Baseclass::update_name(std::string newmane) {Baseclass::name = newmane;}
void Baseclass::update_email(std::string newemaila) {Baseclass::email=newemaila;}
void Baseclass::update_address(std::string newaddress) {Baseclass::address=newaddress;}
