#include "a.h"
#include "ConferenceRoom.h"
#include "Floor.h"
#include "Reception.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include"Meeting.h"
#include"housekeaper.h"
#include "Room.h"
#include "Feedback.h"
#include "Payment.h"
#include "Security.h"
#include "Staff.h"
#include "Manager.h"
#include "Person.h"
#include <filesystem>

using namespace std;

namespace fs = filesystem;

class CsvWriter {
public:
    void writeData(string filename, vector<vector<string>> data) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            for (vector<string> row : data) {
                for (string cell : row) {
                    file << cell << ",";
                }
                file << "\n";
            }
            file.close();
            cout << "Data written to " << filename << endl;
        }
        else {
            cout << "Unable to open file " << filename << endl;
        }
    }
};

class CsvReader {
public:
    vector<vector<string>> readData(string filename) {
        vector<vector<string>> data;
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                vector<string> row;
                string cell;
                for (char c : line) {
                    if (c != ',') {
                        cell += c;
                    }
                    else {
                        row.push_back(cell);
                        cell = "";
                    }
                }
                row.push_back(cell);
                data.push_back(row);
            }
            file.close();
            cout << "Data read from " << filename << endl;
        }
        else {
            cout << "Unable to open file " << filename << endl;
        }
        return data;
    }

    void searchData(string filename, int column, string value) {
        vector<vector<string>> data = readData(filename);
        bool found = false;
        for (vector<string> row : data) {
            if (row.size() > column && row[column] == value) {
                for (string cell : row) {
                    cout << cell << ",";
                }
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No data found for " << value << " in column " << column << endl;
        }
    }
};

Feedback::Feedback(int id, int rate,  string& com)
    : GuestID(id), rating(rate), comments(com) {}

int Feedback::getGuestID()  {
    return GuestID;
}

int Feedback::getRating()  {
    return rating;
}

string Feedback::getComments()  {
    return comments;
}

void Feedback::setRating(int rate) {
    rating = rate;
}

void Feedback::setComments( string& com) {
    comments = com;
}




Payment::Payment(double paymentAmount, string paymentMethod, int paymentDate, int guestID) : paymentAmount(paymentAmount), paymentMethod(paymentMethod), paymentDate(paymentDate), guestID(guestID) {}


void Payment::setPaymentAmount(double amount) {
    paymentAmount = amount;
}


double Payment::getPaymentAmount()  {
    return paymentAmount;
}


void Payment::setPaymentMethod(string method) {
    paymentMethod = method;
}


string Payment::getPaymentMethod()  {
    return paymentMethod;
}


void Payment::setPaymentDate(int date) {
    paymentDate = date;
}


int Payment::getPaymentDate()  {
    return paymentDate;
}



void Payment::setGuestID(int gguestID) {
    guestID = gguestID;
}

//

class Transportation {
public:
    Transportation(string taxiType, string destination, double distance)
        : taxiType_(taxiType), destination_(destination), distance_(distance) {}

    double calculateCost() {
        double costPerKm = (taxiType_ == "elite") ? 2.0 : 1.0;
        return distance_ * costPerKm;
    }

    string getDestination() const {
        return destination_;
    }

private:
    string taxiType_;
    string destination_;
    double distance_;
};

bool Security::verifyPayment(int pReceipt) {
    for (int i = 0; i < 10; i++) {
        if (receipts[i] == pReceipt) {
            return true;
        }
    }
    return false;
}
//text box
void printBox(const string& text) {
    int width = text.length() + 4;
    cout << string(width, '*') << endl;
    cout << "* " << text << " *" << endl;
    cout << string(width, '*') << endl;
}


int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

int main() {

    string roomType;
    char  x;
    cout << "Enter (G) For Guest Department and (A) for  Adminstration Departmrnt:" << endl ;
    cin >> x;
    if (x == 'G' ) {
        char get;
        cout << "Enter 'u' if you want to book a room for a holiday, and 'm' if you want to book a room for a meeting: "<< endl;
        cin >> get;
        while ((get != 'u') && (get != 'm')) {
            cout << "Invalid input. Please enter either 'u' or 'm': ";
            cin >> get;
        }


        if (get == 'u') {
            ofstream outfile;
            outfile.open("hotel_data.txt", ios::app);

            Reception reception;
            string name;
            cout << "Name: ";
            cin >> name;
            reception.setName(name);
            outfile << "Name: " << name << endl;

            int id;
            cout << "ID: ";
            while (!(cin >> id)) {
                cout << "Invalid input, please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            reception.setId(id);
            outfile << "ID: " << id << endl;

            int phoneNumber;
            cout << "Phone Number: ";
            while (!(cin >> phoneNumber)) {
                cout << "Invalid input, please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            reception.setPhoneNumber(phoneNumber);
            outfile << "Phone Number: " << phoneNumber << endl;

            ifstream infile;
            infile.open("hotel_data.txt");
            vector<int> roomNumbers;
            string line;
            while (getline(infile, line)) {
                if (line.find("Room Number: ") != string::npos) {
                    int roomNumber = stoi(line.substr(13));
                    roomNumbers.push_back(roomNumber);
                }
            }
            infile.close();
            ///end
            int roomNumber;
            cout << endl << "Welcome, " << reception.getName() << ". Please select a room:" << endl;
            cout << "Room Number: ";
            while (!(cin >> roomNumber)) {
                bool roomNumberExists = false;
                for (int i = 0; i < roomNumbers.size(); i++) {
                    if (roomNumbers[i] == roomNumber) {
                        roomNumberExists = true;
                        break;
                    }
                }

                if (roomNumberExists) {
                    string message = "Sorry, this room number is already taken. Please enter a different room number: ";
                    printBox(message);
                    
                }
                else {
                    outfile << "Room Number: " << roomNumber << endl;
                    break;
                }
            }

            string message = "Now you can choose your room type \n Elite for 200$ per Night \n Standard for 120$ per Night    ";
            printBox(message);


            cout << "Room Type (Standard, Elite): ";
            while (!(cin >> roomType) || (roomType != "Standard" && roomType != "Elite")) {
                string message = "Invalid input, please enter either 'Standard' or 'Elite': ";
                printBox(message);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            outfile << "Room Type: " << roomType << endl;

            int guestNumber;
            cout << "Number of Guests: ";
            while (!(cin >> guestNumber) || guestNumber < 1) {
                cout << "Invalid input, please enter a positive integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            outfile << "Number of Guests: " << guestNumber << endl;

            Room room(roomNumber, roomType, guestNumber, 100.0);

            double paymentAmount;
            string paymentMethod;
            int paymentDate;
            int guestID;

            Payment p1;


            if (room.checkAvailability()) {
                room.bookRoom();
                if (roomType == "Standard") {
                    p1.setPaymentAmount(120.0);
                }
                if (roomType == "Elite") {
                    p1.setPaymentAmount(200.0);
                }
                cout << "Enter payment method: ";
                cin >> paymentMethod;
                cout << "Enter payment date : ";
                cin >> paymentDate;
                cout << "Enter guest ID: ";
                cin >> guestID;
                cout << "Your Transaction is Successful! , your Receipt ID is : " << p1.getRandomNum() << endl;
                cout << "Room Booked: Yes" << endl;
            }
            else {
                outfile << "Room Booked: No" << endl;
            }

            outfile << endl;
            outfile.close();


            ExtraService e1;
            e1.AvailableService();
            cout << e1.get_service_type();
            cout << e1.get_service_cost();
            e1.get_service_date();
            cout << "\n";
            housekeaper k1;
        }
        if (get == 'm')
        {
            int pReceipt2;
            Security s1;
            cout << "Enter payment receipt: ";
            cin >> pReceipt2;
            if (s1.verifyPayment(pReceipt2)) {
                cout << "You are allowed to enter" << endl;
                Meeting m1;
                // housekeaper k1;
            }
            else {
                cout << "Payment not verified please pay below" << endl;
                double paymentAmount2;
                string paymentMethod2;
                int paymentDate2;
                int guestID2;
                Payment p2;
                p2.setPaymentAmount(100.0);
                cout << "Enter payment method: ";
                cin >> paymentMethod2;
                cout << "Enter payment date : ";
                cin >> paymentDate2;
                cout << "Enter guest ID: ";
                cin >> guestID2;
                cout << "Your Transaction is Successful! , your Receipt ID is : " << p2.getRandomNum() << endl;
                Meeting m1;
               // housekeaper k1;
            }
        }
        cout << "Now Please give us your feedback" << endl;
        int id;
        int r;
        string com;
        cout << "Please enter your id: ";
        cin >> id;
        cout << "Please enter your rating from 1 to 5: ";
        cin >> r;
            //to take sentences
        cin.ignore(); // to consume the newline character left by cin >>
        cout << "If you have any comments, please write them here: ";
            getline(cin, com);
            // cin >> com
            Feedback feedback(id, r, com);
        cout << "Thank you for your feedback!" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "If you have a trip please type (Y) ";
        char trip;
        if ((trip = 'Y') || (trip = 'y')) {

                string taxiType, destination;
                double distance;

                cout << "Enter taxi type (standard or elite): ";
                cin >> taxiType;

                cout << "Enter destination: ";
                cin >> destination;

                cout << "Enter distance (in km): ";
                cin >> distance;

                Transportation transport(taxiType, destination, distance);

                cout << "Cost for trip to " << transport.getDestination() << " is $" << transport.calculateCost() << endl;

          } else {
                cout << "Thank you for your visit, we hope to see you again soon!" << endl;
          }
    } if (x == 'A') {
        int choose;
        string mood;
        string id;
        cout << "Choose the mood that you want: (Staff - Manager)" << endl;
        cin >> mood;
        while (mood != "manager" && mood != "Manager" && mood != "Staff" && mood != "staff") {
            cout << "Invalid input, please enter the correct input: " << endl;
            cin >> mood;
        }
        if (mood == "Manager" || mood == "manager") {
            cout << "Enter the ID: " << endl;
            cin >> id;
            Manager anas(id);
            cout << "The total balance of the hotel: " << anas.getBalance() << "\n" << "The total empty rooms: " << anas.getEmptyRooms() << "\n" << "The total booked rooms: " << anas.getBookedRooms() << endl;
            cout << "You have the following abilities: \n1) Search for Guest data \n 2) Search for staff data " << endl;
            cin >> choose;
            if (choose == 1) {
                anas.searchGuestData();


            }
        }
        else if (mood == "Staff" || mood == "staff") {
            string position;
            cout << "Choose (Housekeeper - Receptionist)" << endl;
            cin >> position;
            while (position != "Houskeeper" && position != "houskeeper" && position != "Receptionist" && position != "receptionist") {
                cout << "Invalid input, please re-enter: " << endl;
                cin >> position;
            }
            if (position == "Houskeeper" || position == "houskeeper") {
                int randomNumber = generateRandomNumber(1, 200);
                cout << "The randomly generated number is: " << randomNumber << endl;
            }
            if (position == "Staff" || position == "staff") {
                Staff s;
                cout << "You have " << s.generateRandomNumber(1, 10) << " people in the reception to check-in or check-out" << endl;
            }
        }

    }
             return 0;
}




