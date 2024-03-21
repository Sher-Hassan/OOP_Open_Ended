#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    string email;
public:
    Person(string name, string email) : name(name), email(email) {}
    string getName() const { return name; }
    string getEmail() const { return email; }
};

class Course;

class Student : public Person {
private:
    vector<const Course*> coursesEnrolled;
public:
    Student(string name, string email) : Person(name, email) {}
    void enrollCourse(const Course& course);
    void dropCourse(const string& courseCode);
    void viewCourses();
};
class Teacher : public Person {
private:
    string teacherID;
    vector<string> coursesTaught;
public:
    Teacher(string name, string email, string teacherID) : Person(name, email), teacherID(teacherID) {}
    string getTeacherID() const { return teacherID; }
    void assignCourse(string course) { coursesTaught.push_back(course); }
    void removeCourse(string course);
    void viewCourses();
};

class Course {
private:
    string courseCode;
    string courseName;
    Teacher& teacher;
    vector<Student*> studentsEnrolled;
public:
    Course(const string& courseCode, const string& courseName, Teacher& teacher)
        : courseCode(courseCode), courseName(courseName), teacher(teacher) {}
    const string& getCourseCode() const { return courseCode; }
    const string& getCourseName() const { return courseName; }
    Teacher& getTeacher() const { return teacher; }
    void addStudent(Student& student) { studentsEnrolled.push_back(&student); }
    void removeStudent(const string& studentName);
    void viewStudents();
};
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

void Course::removeStudent(const string& studentName) {
    for(auto it = studentsEnrolled.begin(); it != studentsEnrolled.end(); ++it) {
        if((*it)->getName() == studentName) {
            studentsEnrolled.erase(it);
            break;
        }
    }
}

void Course::viewStudents() {
    for(auto& student : studentsEnrolled) {
        cout << student->getName() << endl;
    }
}

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

    //student1.dropCourse(c1.getCourseCode());

    student2.viewCourses();

    return 0;
}