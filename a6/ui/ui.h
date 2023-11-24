#pragma once
#include "string"

class Ui {
private:
    void admin_menu();
    void user_menu(std::string user, std::string pass);
public:
    Ui();
};