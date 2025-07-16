#include "Seat.h"
Seat::Seat() : reserved(false) {}
bool Seat::isAvailable() const { return !reserved; }
void Seat::reserve() { reserved = true; }
void Seat::cancel() { reserved = false; }
