#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
// Abstract base class for Admin and Customer
class User {
protected:
    string username;
    string password;

public:
    virtual void displayMenu() = 0;
    virtual ~User() {}
};
#endif