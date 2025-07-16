#ifndef TICKET_SYSTEM_H
#define TICKET_SYSTEM_H
#include <vector>
#include "Movie.h"
#include "Customer.h"
#include "Admin.h"
// Main controller class for running the booking system as a whole
class TicketSystem {
private:
    vector<Movie> movies; //list of all movies

public:
    TicketSystem();
    void start();
    void runCustomer();
    void runAdmin();
    void listMovies();
    void bookTicket();
    void cancelTicket();
    void addMovie();
    void removeMovie();
    void resetSeats();
};
#endif