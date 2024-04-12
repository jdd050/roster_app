#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "student.h"

class Roster {
public:
    Roster(int classSize);
    std::string getStudentID(int i);
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, std::string degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
private:
    Student *classRosterArray[5];
    int classSize = 0;
    int index = 0;
};

#endif //ROSTER_H
