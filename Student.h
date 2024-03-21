#include "Person.h"
#include "Course.h"
#include <vector>
using namespace std;

class Student : public Person {
private:
    vector<const Course*> coursesEnrolled;
public:
    Student(string name, string email);
    void enrollCourse(const Course& course);
    void dropCourse(const string& courseCode);
    void viewCourses();
};
