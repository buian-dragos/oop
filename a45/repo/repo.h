#pragma once

#include "../d-arr/temp-dyn.h"
#include "../domain/event.h"
#include "../domain/user.h"
#include "cstring"

class EventRepo{
private:
    DynamicArray<Event> d_array;
    void read_file();
public:
    EventRepo();

//  append an event to the array
    void add_event(Event ev);

//  remove an existing event
    void remove_event(int index);

//  update an existing event
    void update_event(Event new_ev,int index);
    std::string list();

//  return the index of an event
    int index(Event ev);

//  return the event at a given index
    Event get_item(int index);
    int get_size();
};

class UserRepo{
private:
    DynamicArray<User> d_array;
    void read_file();
public:
    UserRepo();
//    std::string list();
    int get_size();

//  add an event to the user with the given id
    void add_id(int id,const Event& new_elem);

//  remove an event from the user with the given id
    void remove_event(int id, Event event);
    User get_item(int index);
};