#include "Teacher.h"
#include <vector>
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    Teacher& teacher;
    vector<Student*> studentsEnrolled;
public:
    Course(const string& courseCode, const string& courseName, Teacher& teacher);
    const string& getCourseCode() const;
    const string& getCourseName() const;
    Teacher& getTeacher() const;
    void addStudent(Student& student);
    void removeStudent(const string& studentName);
    void viewStudents();
};
