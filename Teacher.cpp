#include "Teacher.h"
#include <iostream>

Teacher::Teacher(string name, string email, string teacherID) : Person(name, email), teacherID(teacherID) {}

string Teacher::getTeacherID() const { return teacherID; }

void Teacher::assignCourse(string course) { coursesTaught.push_back(course); }

void Teacher::removeCourse(string course) {
    for (int i = 0; i < coursesTaught.size(); i++) {
        if (coursesTaught[i] == course) {
            coursesTaught.erase(coursesTaught.begin() + i);
            break;
        }
    }
}

void Teacher::viewCourses() {
      if (coursesTaught.empty()) {
        cout << "No courses taught." << endl;
    } else {
        cout << "Courses taught: ";
        for (int i = 0; i < coursesTaught.size(); i++) {
            cout << coursesTaught[i] << " ";
        }
        cout << endl;
    }
}
