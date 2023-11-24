#include "user.h"

User::User(std::string user, std::string pass, const DynamicArray<Event>& e_l) {
    username = user;
    password = pass;
    event_list = e_l;
}

User::User() {
    username = "";
    password = "";
}

std::string User::get_user() {
    return username;
}

std::string User::get_pass() {
    return password;
}

std::string User::get_list() {
    return event_list.list();
}

void User::add_event(const Event& ev) {
    event_list.add(ev);
}

DynamicArray<Event> User::get_array() {
    return event_list;
}

void User::remove_event(Event event) {
    int index = event_list.index(event);
    for (int i = index; i < event_list.get_size() - 1;i++){
        event_list.set_elem(i,event_list.get_item(i + 1));
    }
    event_list.dec_size();
}

