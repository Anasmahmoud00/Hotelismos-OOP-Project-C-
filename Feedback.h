#pragma once
#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <string>

using namespace std;

class Feedback {
public:
    Feedback(int id, int rate,  string& com);
    int getGuestID() ;
    int getRating() ;
    string getComments() ;
    void setRating(int rate);
    void setComments( string& com);

private:
    int GuestID;
    int rating;
    string comments;
};

#endif // FEEDBACK_H