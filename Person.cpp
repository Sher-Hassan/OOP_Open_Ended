#include "Person.h"

Person::Person(string name, string email) : name(name), email(email) {}

string Person::getName() const { return name; }

string Person::getEmail() const { return email; }
