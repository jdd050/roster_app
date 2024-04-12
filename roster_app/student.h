#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"

class Student {
public:
    // constructor
    Student();
    // getters
    std::string getID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmail();
    int getAge();
    int getDaysToComplete1();
    int getDaysToComplete2();
    int getDaysToComplete3();
    DegreeProgram getDegreeProgram();
    // setters
    void setID(std::string id);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int time1, int time2, int time3);
    void setDegreeProgram(DegreeProgram program);
    // member functions
    void PrintID();
    void PrintFirstName();
    void PrintLastName();
    void PrintEmail();
    void PrintAge();
    void PrintDaysToComplete();
    void PrintDegreeProgram();
    void PrintStudentInfo();
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToCompleteCourses[3];
    DegreeProgram degreeProgram;
};

#endif //STUDENT_H