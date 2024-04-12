#include <array>
#include <iostream>
#include <string>
#include "student.h"

// Student class member function definitions

// Constructor
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysToCompleteCourses[0] = 0;
    this->daysToCompleteCourses[1] = 0;
    this->daysToCompleteCourses[2] = 0;
    this->degreeProgram;
}

// getters
std::string Student::getID() { return studentID; }
std::string Student::getFirstName() { return firstName; }
std::string Student::getLastName() { return lastName; }
std::string Student::getEmail() { return emailAddress; }
int Student::getAge() { return age; }
int Student::getDaysToComplete1() { return this->daysToCompleteCourses[0]; }
int Student::getDaysToComplete2() { return this->daysToCompleteCourses[1]; }
int Student::getDaysToComplete3() { return this->daysToCompleteCourses[2]; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

// setters
void Student::setID(std::string id) {
    this->studentID = id;
}

void Student::setFirstName(std::string first) {
    this->firstName = first;
}

void Student::setLastName(std::string last) {
    this->lastName = last;
}

void Student::setEmail(std::string email) {
    this->emailAddress = email;
}

void Student::setAge(int studentAge) {
    this->age = studentAge;
}

void Student::setDaysToComplete(int time1, int time2, int time3) {
    this->daysToCompleteCourses[0] = time1;
    this->daysToCompleteCourses[1] = time2;
    this->daysToCompleteCourses[2] = time3;
}

void Student::setDegreeProgram(DegreeProgram program) {
    this->degreeProgram = program;
}

// Member functions
// functions that print respective parameters of the student
void Student::PrintID() {
    std::cout << this->studentID << std::endl;
}

void Student::PrintFirstName() {
    std::cout << this->firstName << std::endl;
}

void Student::PrintLastName() {
    std::cout << this->lastName << std::endl;
}
void Student::PrintEmail() {
    std::cout << this->emailAddress << std::endl;
}

void Student::PrintAge() {
    std::cout << this->age << std::endl;
}
void Student::PrintDaysToComplete() {
    std::cout << this->daysToCompleteCourses << std::endl;
}

void Student::PrintDegreeProgram() {
    if (this->degreeProgram == SECURITY) {
        std::cout << "SECURITY" << std::endl;
    } else if (this->degreeProgram == NETWORK) {
        std::cout << "NETWORK" << std::endl;
    } else if (this->degreeProgram == SOFTWARE) {
        std::cout << "SOFTWARE" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
    }
}

void Student::PrintStudentInfo() {
    std::cout << "ID: " << this->studentID;
    std::cout << "  First Name: " << this->firstName;
    std::cout << "  Last Name: " << this->lastName;
    std::cout << "  Email Address: " << this->emailAddress;
    std::cout << "  Age: " << this->age;
    std::cout << "  Days in Courses: {" << this->daysToCompleteCourses[0] << ", " << this->daysToCompleteCourses[1] << ", " << this->daysToCompleteCourses[2] << "}";
    std::cout << " Degree Program: ";
    if (this->degreeProgram == SECURITY) {
        std::cout << "SECURITY" << std::endl;
    } else if (this->degreeProgram == NETWORK) {
        std::cout << "NETWORK" << std::endl;
    } else if (this->degreeProgram == SOFTWARE) {
        std::cout << "SOFTWARE" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
    }
}