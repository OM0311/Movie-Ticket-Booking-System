#include "Movie.h"
#include <iostream>
using namespace std;

Movie::Movie(string t, string st, int rows, int cols) : title(t), showtime(st), seats(rows, vector<Seat>(cols)) {}
string Movie::getTitle() const { return title; }
string Movie::getShowtime() const { return showtime; }

void Movie::displaySeats() const {
    for (int i = 0; i < seats.size(); ++i) {
        for (int j = 0; j < seats[i].size(); ++j) {
            cout << (seats[i][j].isAvailable() ? "[O]" : "[X]") << " ";
        }
        cout << endl;
    }
}

bool Movie::reserveSeat(int row, int col) {
    //Reserves seat if it's valid and not taken
    if (row >= 0 && row < seats.size() && col >= 0 && col < seats[0].size()) {
        if (seats[row][col].isAvailable()) {
            seats[row][col].reserve();
            return true;
        }
    }
    return false;
}

bool Movie::cancelSeat(int row, int col) {
    //cancels reservation if seat is currently taken
    if (row >= 0 && row < seats.size() && col >= 0 && col < seats[0].size()) {
        if (!seats[row][col].isAvailable()) {
            seats[row][col].cancel();
            return true;
        }
    }
    return false;
}
