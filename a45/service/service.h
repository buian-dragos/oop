#pragma once
#include "../repo/repo.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>


class AdminService{
private:
    EventRepo event_repo;
public:
    explicit AdminService(const EventRepo& er);

//  returns a string representation of the events in the repo
    std::string list_events();

//  add a new event to the repo
//  a message will be shown if the event already exists
    void add_event(std::string title, std::string desc, std::string	dt, int nr_part, std::string link);

//  delete and event from the repo
//  a message will be shown if the event does not exist
    void delete_event(std::string title, std::string dt);

//  update and event
//  a message will be shown if the event does not exist
    void update_event(std::string old_title, std::string old_dt, std::string title, std::string desc, std::string	dt, int nr_part, std::string link);
};

class UserService{
private:
    EventRepo event_repo;
    UserRepo user_repo;
    int id;
public:
    explicit UserService(const EventRepo& er,const UserRepo& ur);

//  checks if a username/password combination exists
//  if it does not exist a message will be shown and the program will exit
//  if it exists, the id will be updated with the correct user id
    void check_login(std::string user, std::string pass);

//  iterates through the events in the repo with a given month ('*' to see all)
//  the link for each event will be opened in the browser
//  user has the following commands ("next" -  see next event, "add" - add event to user list, "menu" -  return)
    void iterate_events(std::string month);


//    int number_of_events();

// removes an event from the users list
// a message will be shown if the event does not exist
    void remove_event(Event event);

//  returns a string representation of the events in the users list
    std::string check_list();
};