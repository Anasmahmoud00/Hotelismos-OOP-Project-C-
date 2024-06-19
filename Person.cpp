#include <iostream>
#include <string>
#include "Person.h"
using namespace std;


Person::Person() {
    string n, g;
    int a;
    cout << "Enter your name and age respectively: " << endl;
    cin >> n >> a;
    Name = n;
    while (true) {
        cout << "Please enter your gender: ";
        cin >> g;
        if (!cin.fail()) { 
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please try again." << endl;
    }
}
int Person::getAge() {
    return Age;
}
string Person::getGender() {
    return Gender;
}
string Person::getName() {
    return Name;
}