#pragma once
#include "string"
#include "../domain/event.h"
#include "../domain/user.h"


class Validation{
private:
    std::string message;
public:
    Validation(std::string msg);
    std::string getMessage();
};

class Event_User_Validator{
public:
    static void validate(Event ev);
    static void validate(User us);
};