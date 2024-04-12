// main.cpp - All code execution and termination occurs in this file.

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "roster.h"
#include "degree.h"

int main() {
    // Student data array
    const std::string studentData[] = {
            "1,John,Doe,JohnDoe123@gm ail.com,21,29,36,40,SECURITY",
            "2,Jane,Doe,Doe_Jane3@gmailcom,5,21,30,42,SOFTWARE",
            "3,Bob,Burger,Burger_flippin_master101yahoo.com,16,31,10,34,NETWORK",
            "4,Spongebob,Squarepants,Squarepants.Sponge@comcast.net,20,40,52,65,SOFTWARE",
            "5,Peter,Griffin,birdtheword@outlook.com,18,32,31,36,NETWORK"
    };

    // Parse student data
    std::vector<std::array<std::string, 9>> dataByCategory;
    int start = 0;
    for (std::string data : studentData) {
        int numParameters = 0;
        std::array<std::string, 9> parameters = {};
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == ',') {
                std::string parameter = data.substr(start, i - start);
                start = i + 1;
                parameters[numParameters] = parameter;
                numParameters++;
            } else if ((data[i] != ',') && (data.length() - i == 1)) {
                std::string parameter = data.substr(start, (data.length()) - start);
                start = 0;
                parameters[numParameters] = parameter;
                numParameters = 0;
            }
        }
        dataByCategory.push_back(parameters);
    }

    // Create a roster class instance with 5 student objects
    Roster *classRoster = new Roster(5);

    // Create student objects
    for (int i = 0; i < 5; i++) {
        classRoster->add(
                dataByCategory[i][0],  // studentID
                dataByCategory[i][1],  // firstName
                dataByCategory[i][2],  // lastName
                dataByCategory[i][3],  // emailAddress
                std::stoi(dataByCategory[i][4]),  // age
                std::stoi(dataByCategory[i][5]), // daysInCourse1
                std::stoi(dataByCategory[i][6]),  // daysInCourse2
                std::stoi(dataByCategory[i][7]), // daysInCourse3
                dataByCategory[i][8] // degreeProgram
                );
    }


    // Print class roster
    classRoster->printAll();
    std::cout << std::endl;
    // Print invalid emails
    classRoster->printInvalidEmails();
    std::cout << std::endl;
    // Print average days in course
    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->getStudentID(i));
    }
    std::cout << std::endl;
    // Print students with SOFTWARE degree program
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    std::cout << std::endl;
    // Remove student A3
    classRoster->remove("A3");
    std::cout << std::endl;
    // Print updated full roster
    classRoster->printAll();
    std::cout << std::endl;
    // Expected error (A3 no longer exists)
    classRoster->remove("A3");
    // Call destructor and clean allocated memory
    delete classRoster;

    return 0;
}
