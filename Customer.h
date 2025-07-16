#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
// Represents Customer user
class Customer : public User {
public:
    void displayMenu() override;
};
#endif