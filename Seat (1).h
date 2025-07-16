#ifndef SEAT_H
#define SEAT_H
//Represents a single seat in movie theater
class Seat {
private:
    bool reserved;

public:
    Seat();
    bool isAvailable() const; // checks if seat is available
    void reserve(); // marks seat reserved
    void cancel(); // cancels the seat reservation
};
#endif