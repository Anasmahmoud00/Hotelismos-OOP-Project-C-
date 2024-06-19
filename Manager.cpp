#include "Manager.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
using namespace std;

Manager::Manager(string id) : Person() {
    while (id != "202202029") {
        cout << "Incorrect ID, please enter the correct ID:" << endl;
        cin >> id;
    }
    managerId = id;
}

void Manager::setBalance(int num) {
    balance = num;
}

void Manager::setEmptyRooms(int num) {
    empty_rooms = num;
}

void Manager::setBookedRooms(int num) {
    booked_rooms = num;
}

int Manager::getEmptyRooms() {
    return empty_rooms;
}

int Manager::getBalance() {
    return balance;
}

int Manager::getBookedRooms() {
    return booked_rooms;
}

void Manager::searchGuestData() {
    string file_name = "guest.csv";
    string guestID;
    cout << "Enter the ID for the guest: " << endl;
    cin >> guestID;
    string line;
    string filename = "guest.csv";
    ifstream file(filename);
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, gender;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, gender, ',');
        if (id == guestID) {
            cout << "Name: " << name << endl;
            cout << "Gender: " << gender << endl;
            return;
        }
    }
    cout << "Guest ID not found." << endl;
}

void Manager::searchStaffData() {
    string file_name = "staff.csv";
    string staffID;
    cout << "Enter the ID for the staff: " << endl;
    cin >> staffID;
    string line;
    ifstream file(file_name);
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, gender;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, gender, ',');
        if (id == staffID) {
            cout << "Name: " << name << endl;
            cout << "Gender: " << gender << endl;
            return;
        }
    }
    cout << "Staff ID not found." << endl;


}





