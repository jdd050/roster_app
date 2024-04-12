#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"

// Roster class member function definitions

// constructor
Roster::Roster(int class_size) {
    this->classSize = class_size;
    this->index = 0;
    for (int i = 0; i < this->classSize; i++) {
        this->classRosterArray[i] = new Student;
    }
}

// gets the student's ID
std::string Roster::getStudentID(int i) {
    std::string id = classRosterArray[i]->getID();
    return id;
}
// adds a student to the roster
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, std::string degreeProgram) {

    if (this->index == this->classSize - 1) {
        classRosterArray[this->index] = new Student();
    }

    classRosterArray[this->index]->setID(studentID);
    classRosterArray[this->index]->setFirstName(firstName);
    classRosterArray[this->index]->setLastName(lastName);
    classRosterArray[this->index]->setEmail(emailAddress);
    classRosterArray[this->index]->setAge(age);
    classRosterArray[this->index]->setDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);
    // degree program checks
    if (degreeProgram == "SECURITY") {
        classRosterArray[this->index]->setDegreeProgram(DegreeProgram::SECURITY);
    } else if (degreeProgram == "NETWORK") {
        classRosterArray[this->index]->setDegreeProgram(DegreeProgram::NETWORK);
    } else if (degreeProgram == "SOFTWARE") {
        classRosterArray[this->index]->setDegreeProgram(DegreeProgram::SOFTWARE);
    } else {
        std::cout << "Unknown Degree." << std::endl;
    }
    this->index++;
}

// removes a student from the roster
void Roster::remove(std::string studentID) {
    bool studentExists = false;
    // iterate through all students
    for (int i = 0; i < this->classSize; i++) {
        if (this->classRosterArray[i] == nullptr) {
            continue;
        } else if (studentID == this->classRosterArray[i]->getID()) {
            this->classRosterArray[i] = nullptr;
            studentExists = true;
            break;
        }
    }
    if (studentExists == false) {
        std::cout << "Error: Student " << studentID << " not found." << std::endl;
    } else {
        std::cout << "Student " << studentID << " successfully removed.";
    }
}

// prints all current students in the roster
void Roster::printAll() {
    std::cout << "All current students in the roster: " << std::endl;
    for (int i = 0; i < this->classSize; i++) {
        if (this->classRosterArray[i] == nullptr) {
            continue;
        } else {
            this->classRosterArray[i]->PrintStudentInfo();
        }
    }
}

// print average number of days for a student's 3 courses
void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i < this->classSize; i++) {
        if (studentID == this->classRosterArray[i]->getID()) {
            double averageDays = (classRosterArray[i]->getDaysToComplete1() + classRosterArray[i]->getDaysToComplete2() + classRosterArray[i]->getDaysToComplete3()) / 3.0;
            std::cout << studentID << "'s average day(s) in courses: " << averageDays << std::endl;
        }
    }
}

// prints invalid emails
void Roster::printInvalidEmails() {
    for (int i = 0; i < this->classSize; i++) {
        std::string emailAddress = this->classRosterArray[i]->getEmail();
        if ((emailAddress.find(' ') != std::string::npos) || (emailAddress.find('.') == std::string::npos) || (emailAddress.find('@') == std::string::npos)) {
            std::cout << this->classRosterArray[i]->getID() << "'s email address: \"" << emailAddress << "\" is invalid." << std::endl;
        }
    }
}

// prints all students within a specified degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    std::string degreeString;
    if (degreeProgram == DegreeProgram::SECURITY) {
        degreeString = "SECURITY";
    } else if (degreeProgram == DegreeProgram::NETWORK) {
        degreeString = "NETWORK";
    } else if (degreeProgram == DegreeProgram::SOFTWARE) {
        degreeString = "SOFTWARE";
    } else {
        degreeString = "ERROR";
    }

    std::cout << "Students with the " << degreeString << " program:" << std::endl;
    int numOfStudents = 0;
    for (int i = 0; i < this->classSize; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->PrintStudentInfo();
            numOfStudents++;
        }
    }
    if (numOfStudents == 0) {
        std::cout << "No students with the " << degreeString << " program found." << std::endl;
    }
}

// deallocate memory that was dynamically allocated
Roster::~Roster() {
    for (int i = 0; i < this->classSize; i++) {
        delete this->classRosterArray[i];
    }
}