#include "user.h"
#include <algorithm>

User::User(std::string user, std::string pass, const std::vector<Event>& e_l) {
    username = user;
    password = pass;
    event_list = e_l;
}

//User::User() {
//    username = "";
//    password = "";
//}

std::string User::get_user() {
    return username;
}

std::string User::get_pass() {
    return password;
}

std::string User::get_list() {
    std::string rs;
    for (auto event : event_list){
        rs.append(event.to_string());
        rs.append("\n");
    }
    return rs;
}

void User::add_event(const Event& ev) {
    event_list.push_back(ev);
}

std::vector<Event> User::get_array() {
    return event_list;
}

void User::remove_event(const Event& event) {
    int i = 0;
    for (auto ev : event_list){
        if (ev.is_equal(event))
            break;
        i++;
    }
    event_list.erase(event_list.begin() + i);
}

