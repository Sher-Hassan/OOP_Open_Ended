#include "Person.h"
#include <vector>
using namespace std;

class Teacher : public Person {
private:
    string teacherID;
    vector<string> coursesTaught;
public:
    Teacher(string name, string email, string teacherID);
    string getTeacherID() const;
    void assignCourse(string course);
    void removeCourse(string course);
    void viewCourses();
};
