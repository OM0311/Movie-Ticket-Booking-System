#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <vector>
#include "Seat.h"
using namespace std;
// Represnets movie title, showtime, and seating chart
class Movie {
private:
    string title;
    string showtime;
    vector<vector<Seat>> seats;

public:
    Movie(string t, string st, int rows = 5, int cols = 5);
    string getTitle() const;
    string getShowtime() const;
    void displaySeats() const; // seat availability
    bool reserveSeat(int row, int col); // tries to reserve seat
    bool cancelSeat(int row, int col); //cancels reservation
};
#endif