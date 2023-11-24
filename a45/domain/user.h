#pragma once
#include <string>
#include "event.h"
#include "../d-arr/temp-dyn.h"

class User{
private:
    std::string username;
    std::string password;
    DynamicArray<Event> event_list;

public:
    User();
    User(std::string user, std::string pass, const DynamicArray<Event>& e_l);
    std::string get_user();
    std::string get_pass();
    std::string get_list();
    DynamicArray<Event> get_array();

//  add event to user list
    void add_event(const Event& ev);

//  remove event from user list
    void remove_event(Event event);
};