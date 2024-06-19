//
// Created by 20106 on 5/6/2023.
//

//#include "Reception.h"
//Room::Room(int roomNumber, std::string roomType, int maxGuests, double pricePerNight) {
//    roomNumber_ = roomNumber;
//    roomType_ = roomType;
//    maxGuests_ = maxGuests;
//    pricePerNight_ = pricePerNight;
//
//    if (roomType == "Elite") {
//        pricePerNight_ = 500;
//    }
//
//    isOccupied_ = false;
//}
//
//bool Room::checkAvailability() const {
//    if (roomType_ == "Standard" && maxGuests_ >= 3) {
//        std::cout << "Sorry, there are no rooms available with this room type and guest number." << std::endl;
//        return false;
//    }
//
//    if (isOccupied_) {
//        std::cout << "Sorry, this room is already occupied." << std::endl;
//        return false;
//    }
//
//    return true;
//}
//
//void Room::bookRoom() {
//    isOccupied_ = true;
//    std::cout << "Room booked successfully." << std::endl;
//}
//
//int Room::getRoomNumber() const {
//    return roomNumber_;
//}
//
//std::string Room::getRoomType() const {
//    return roomType_;
//}
//
//int Room::getMaxGuests() const {
//    return maxGuests_;
//}
//
//double Room::getPricePerNight() const {
//    return pricePerNight_;
//}
//
//void Room::setRoomNumber(int roomNumber) {
//    roomNumber_ = roomNumber;
//}
//
//void Room::setRoomType(std::string roomType) {
//    roomType_ = roomType;
//}
//
//void Room::setMaxGuests(int maxGuests) {
//    maxGuests_ = maxGuests;
//}
//
//void Room::setPricePerNight(double pricePerNight) {
//    pricePerNight_ = pricePerNight;
//}
//
//#include <iostream>
//
//
//int main() {
//    Room room(101, "Standard", 2, 250.0);
//
//    if (room.checkAvailability()) {
//        room.bookRoom();
//    }
//
//    std::cout << "Room number: " << room.getRoomNumber() << std::endl;
//    std::cout << "Room type: " << room.getRoomType() << std::endl;
//    std::cout << "Max guests: " << room.getMaxGuests() << std::endl;
//    std::cout << "Price per night: " << room.getPricePerNight() << std::endl;
//
//    return 0;
//}