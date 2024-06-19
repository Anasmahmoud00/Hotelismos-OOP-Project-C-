#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H
#include <string>
#include <ctime>
using namespace std;
class Payment {
public:
    Payment() {
        getRandomNum();
    }
    Payment(double paymentAmount, string paymentMethod, int paymentDate, int guestID);
    void setPaymentAmount(double amount);
    double getPaymentAmount();
    void setPaymentMethod(string method);
    string getPaymentMethod();
    void setPaymentDate(int date);
    int getPaymentDate();
    void setGuestID(int guestID);
    int getGuestID();
    int getRandomNum() {
        srand(time(NULL));
        int receipts[10] = { 520, 521, 522, 523, 524, 525, 526, 527, 528 };
        int RanIndex = rand() % 10;
        return receipts[RanIndex];
    }


private:
    double paymentAmount;
    string paymentMethod;
    int paymentDate;
    int guestID;
};
#endif