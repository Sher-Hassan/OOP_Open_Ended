#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include <iostream>

int main() {
    Teacher teacher1("John Doe", "john.doe@example.com", "1234567890");
    Course c1("CS101", "Introduction to Computer Science", teacher1);
    Course c2("CS102", "Introduction to Computer Engineering", teacher1);

    Student student1("Bravo", "Bravo@gmail.com");
    Student student2("Danny", "Danny@gmail.com");

    cout << "Student 1: " <<endl<< student1.getName() << ", " << student1.getEmail() << endl;
    student1.enrollCourse(c1);
    student1.enrollCourse(c2);
    student1.viewCourses();

    cout << "Student 2: " <<endl<< student2.getName() << ", " << student2.getEmail() << endl;
    student2.enrollCourse(c1);
    student2.viewCourses();

    //student1.dropCa ourse(c1.getCourseCode());

    student2.viewCourses();

    return 0;
 }