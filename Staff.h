#pragma once
#ifndef UNTITLED2_STAFF_H
#define UNTITLED2_STAFF_H
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class Staff : public Person {
private:
    string Position;
    string Email;
public:
    Staff();
    void getInformation();
    int generateRandomNumber(int min, int max);
};
#endif //UNTITLED2_STAFF_H