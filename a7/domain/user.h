#pragma once
#include <string>
#include <vector>
#include "event.h"

class User{
private:
    std::string username;
    std::string password;
    std::vector<Event> event_list;

public:
//    User();
    User(std::string user, std::string pass, const std::vector<Event>& e_l);
    std::string get_user();
    std::string get_pass();
    std::string get_list();
    std::vector<Event> get_array();

//  add event to user list
    void add_event(const Event& ev);

//  remove event from user list
    void remove_event(const Event& event);
};