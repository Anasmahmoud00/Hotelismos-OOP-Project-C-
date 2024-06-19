#pragma once
#ifndef UNTITLED2_PERSON_H
#define UNTITLED2_PERSON_H
#include <iostream>
#include <string>
using namespace std;




class Person {
private:
    string Name;
    string Gender;
    int Age;
public:
    Person();
    int getAge();
    string getName();
    string getGender();
};
#endif //UNTITLED2_PERSON_H