#include "Student.h"
#include <iostream>

Student::Student(string name, string email) : Person(name, email) {}

void Student::enrollCourse(const Course& course) {
    coursesEnrolled.push_back(&course);
}

void Student::dropCourse(const string& courseCode) {
    for (auto it = coursesEnrolled.begin(); it != coursesEnrolled.end(); ++it) {
        if ((*it)->getCourseCode() == courseCode) {
            coursesEnrolled.erase(it);
            break;
        }
    }
}

void Student::viewCourses() {
if (coursesEnrolled.empty()) {
        cout << "No courses enrolled." << endl;
    } else {
        cout << "Courses enrolled: ";
        for (const auto& course : coursesEnrolled) {
            cout << course->getCourseCode() << " " << course->getCourseName() << " ";
            cout << "Taught by: " << course->getTeacher().getName() << endl;
        }
        cout << endl;
    }
}
