#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
//Represents Admin User
class Admin : public User {
public:
    void displayMenu() override;
};
#endif