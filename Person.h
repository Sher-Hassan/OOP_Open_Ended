#include <string>
using namespace std;

class Person {
protected:
    string name;
    string email;
public:
    Person(string name, string email);
    string getName() const;
    string getEmail() const;
};
