
#ifndef UNTITLED_AA_H
#define UNTITLED_AA_H
using namespace std;
#include <iostream>


class Room {
private:
    int roomNumber_;
    string roomType_;
    int maxGuests_;
    bool isOccupied_;
    double pricePerNight_;


public:
    Room(int roomNumber, string roomType, int maxGuests, double pricePerNight) {
        roomNumber_ = roomNumber;
        roomType_ = roomType;
        maxGuests_ = maxGuests;
        pricePerNight_ = pricePerNight;

        if (roomType == "Elite") {
            pricePerNight_ = 500;
        }

        isOccupied_ = false;
    }


    bool checkAvailability() const {
        if (roomType_ == "Standard" && maxGuests_ >= 3) {
            cout << "Sorry, there are no rooms available with this room type and guest number." << endl;
            return false;
        }

        if (isOccupied_) {
            cout << "Sorry, this room is already occupied." << endl;
            return false;
        }

        return true;
    }

    void bookRoom() {
        isOccupied_ = true;
        cout << "Room booked successfully." << endl;
    }

    int getRoomNumber() const {
        return roomNumber_;
    }

    string getRoomType() const {
        return roomType_;
    }

    int getMaxGuests() const {
        return maxGuests_;
    }

    double getPricePerNight() const {
        return pricePerNight_;
    }

    void setRoomNumber(int roomNumber) {
        roomNumber_ = roomNumber;
    }

    void setRoomType(string roomType) {
        roomType_ = roomType;
    }

    void setMaxGuests(int maxGuests) {
        maxGuests_ = maxGuests;
    }

    void setPricePerNight(double pricePerNight) {
        pricePerNight_ = pricePerNight;
    }
};



//class Reception {
//private:
//    string name_;
//    int id_;
//    int phoneNumber_;
//
//public:
//    Reception() {
//        cout << "Welcome to our hotel. Please provide the following information:" << endl;
//    }
//
//    void setName(string name) {
//        name_ = name;
//    }
//
//    void setId(int id) {
//        id_ = id;
//    }
//
//    void setPhoneNumber(int phoneNumber) {
//        phoneNumber_ = phoneNumber;
//    }
//
//    string getName() const {
//        return name_;
//    }
//
//    int getId() const {
//        return id_;
//    }
//
//    int getPhoneNumber() const {
//        return phoneNumber_;
//    }
//};
//
//
//
//
//
//
//
#endif //UNTITLED_ROOM_H
