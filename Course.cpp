#include "Course.h"
#include <iostream>
#include "Student.h"

Course::Course(const string& courseCode, const string& courseName, Teacher& teacher)
    : courseCode(courseCode), courseName(courseName), teacher(teacher) {}

const string& Course::getCourseCode() const { return courseCode; }



const string& Course::getCourseName() const { return courseName; }

void Course::addStudent(Student& student) { studentsEnrolled.push_back(&student); }

void Course::viewStudents() {
    for(auto& student : studentsEnrolled) {
        cout << student->getName() << endl;
    }
}
