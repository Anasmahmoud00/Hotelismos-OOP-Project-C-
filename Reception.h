
#ifndef UNTITLED_RECEPTION_H
#define UNTITLED_RECEPTION_H
using namespace std;
#include <iostream>


class Reception {
private:
    string name_;
    int id_;
    int phoneNumber_;

public:
    Reception() {
        cout << "Welcome to our hotel. Please provide the following information:" << endl;
    }

    void setName(string name) {
        name_ = name;
    }

    void setId(int id) {
        id_ = id;
    }

    void setPhoneNumber(int phoneNumber) {
        phoneNumber_ = phoneNumber;
    }

    string getName() const {
        return name_;
    }

    int getId() const {
        return id_;
    }

    int getPhoneNumber() const {
        return phoneNumber_;
    }
};









#endif //UNTITLED_RECEPTION_H
