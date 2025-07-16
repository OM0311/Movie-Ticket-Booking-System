#include "TicketSystem.h"
#include <iostream>
using namespace std;
// Constructor initializes movie list
TicketSystem::TicketSystem() {
    movies.emplace_back("Superman", "12:00 PM");
    movies.emplace_back("The Fantastic Four", "2:00 PM");
    movies.emplace_back("Together", "4:00 PM");
    movies.emplace_back("Smurfs", "6:00 PM");
    movies.emplace_back("F1", "8:00 PM");
    movies.emplace_back("Jaws", "10:00 PM");
}
// Loop that lets user pick between Customer or Admin mode
void TicketSystem::start() {
    int mode;
    do {
        cout << "\nSelect Mode:\n1. Customer\n2. Admin\n3. Exit\nChoice: ";
        cin >> mode;
        if (mode == 1) runCustomer();
        else if (mode == 2) runAdmin();
    } while (mode != 3);

    cout << "Exiting program.\n";
}

void TicketSystem::runCustomer() {
    Customer c;
    int choice;
    do {
        c.displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: listMovies(); break;
            case 2: bookTicket(); break;
            case 3: cancelTicket(); break;
        }
    } while (choice != 4);
}

void TicketSystem::runAdmin() {
    Admin a;
    int choice;
    do {
        a.displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: addMovie(); break;
            case 2: removeMovie(); break;
            case 3: resetSeats(); break;
        }
    } while (choice != 4);
}
// Lists all current movies
void TicketSystem::listMovies() {
    for (int i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i].getTitle() << " at " << movies[i].getShowtime() << endl;
    }
}
// Reserves a seat for a selected movie
void TicketSystem::bookTicket() {
    listMovies();
    int choice, row, col;
    cout << "Choose a movie: ";
    cin >> choice;
    if (choice >= 1 && choice <= movies.size()) {
        movies[choice - 1].displaySeats();
        cout << "Enter row and column to reserve: ";
        cin >> row >> col;
        if (movies[choice - 1].reserveSeat(row, col))
            cout << "Seat reserved.\n";
        else
            cout << "Seat unavailable.\n";
    }
}
// Cancels seat reservation
void TicketSystem::cancelTicket() {
    listMovies();
    int choice, row, col;
    cout << "Choose a movie: ";
    cin >> choice;
    if (choice >= 1 && choice <= movies.size()) {
        cout << "Enter row and column to cancel: ";
        cin >> row >> col;
        if (movies[choice - 1].cancelSeat(row, col))
            cout << "Seat canceled.\n";
        else
            cout << "That seat is not currently reserved.\n";
    }
}
// Adds new movie to list
void TicketSystem::addMovie() {
    string title, time;
    cout << "Enter movie title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter showtime: ";
    getline(cin, time);
    movies.emplace_back(title, time);
    cout << "Movie added.\n";
}
// Resets all seats for movie
void TicketSystem::removeMovie() {
    listMovies();
    int choice;
    cout << "Enter movie number to remove: ";
    cin >> choice;
    if (choice >= 1 && choice <= movies.size()) {
        movies.erase(movies.begin() + choice - 1);
        cout << "Movie removed.\n";
    }
}

void TicketSystem::resetSeats() {
    listMovies();
    int choice;
    cout << "Enter movie number to reset seats: ";
    cin >> choice;
    if (choice >= 1 && choice <= movies.size()) {
        string title = movies[choice - 1].getTitle();
        string time = movies[choice - 1].getShowtime();
        movies[choice - 1] = Movie(title, time);
        cout << "Seats reset.\n";
    }
}
