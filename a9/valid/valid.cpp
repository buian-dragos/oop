#include "valid.h"

Validation::Validation(std::string msg) {
    message = msg;
}

std::string Validation::getMessage() {
    return message;
}

void Event_User_Validator::validate(Event ev) {
    std::string err;
    if (ev.get_part() < 0)
        err += std::string("There can not be a negative number of participants!\n");

    if (ev.get_link().size() < 10)
        err += std::string("Link too short!\n");

    if (ev.get_name().size() < 1)
        err += std::string("Invalid name!\n");

    if (ev.get_desc().size() < 1)
        err += std::string("Invalid description!\n");

    if (ev.get_date().size() != 10)
        err += std::string("Invalid date format\n");

    if (err.size() > 0)
        throw Validation(err);
}

void Event_User_Validator::validate(User us) {
    std::string err;
    if (us.get_user().size() < 1)
        err += std::string("Invalid username!\n");

    if (us.get_pass().size() < 1)
        err += std::string("Invalid password!\n");

    if (err.size() > 0)
        throw Validation(err);
}
