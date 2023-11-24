#include "repo.h"
#include <fstream>
#include "iostream"

EventRepo::EventRepo() {
    if (d_array.empty())
        read_file();
}

void EventRepo::read_file() {
    std::ifstream f("../repo/events.txt");
    std::string name,desc,date,link;
    int n_p,ct=0,bt=0;
    char* token;
    for (std::string line; std::getline(f, line); )
    {
        token = strtok( &line[0], ";" );
        while (token != NULL){
            switch (ct) {
                case 0:
                    name = token;
                    break;
                case 1:
                    desc = token;
                    break;
                case 2:
                    date = token;
                    break;
                case 3:
                    n_p = atoi(token);
                    break;
                case 4:
                    link = token;
//                    std::cout << name << " "<< desc << " "<< date << " "<< n_p << " "<< link << "\n";
                    ct = -1;
                    add_event(Event(name,desc,date,n_p,link));
                    break;
                default:
                    break;
            }
            ct++;
            token = strtok(NULL,";");

        }
    }
}

void EventRepo::add_event(Event ev) {
    d_array.push_back(ev);
}

std::string EventRepo::list() {
    std::string rs;
    for (auto event : d_array){
        rs.append(event.to_string());
        rs.append("\n");
    }
    return rs;
}

int EventRepo::index(Event ev) {
    int i = 0;
    for (auto event : d_array){
        if (event.is_equal(ev))
            return i;
        i++;
    }
    return -1;
}

void EventRepo::remove_event(int index) {
    d_array.erase(d_array.begin() + index);
}

void EventRepo::update_event(Event new_ev, int index) {
    d_array[index] = new_ev;
}

Event EventRepo::get_item(int index) {
    return d_array[index];
}

int EventRepo::get_size() {
    return d_array.size();
}

std::vector<Event> EventRepo::get_arr() {
    return d_array;
}

void UserRepo::read_file() {
    EventRepo er;
    bool user_pass = true;
    std::ifstream f ("../repo/users.txt");
    std::string user,pass,title,date;
    int ct = 0,k=0,index;
    char* token;
    for (std::string line; std::getline(f, line); ) {
        if (user_pass) {
            token = strtok( &line[0], ";" );
            user = token;
            token = strtok(NULL,";");
            pass = token;
            user_pass = false;
        } else {
            std::vector<Event> d_arr; // initialize an empty array
            token = strtok( &line[0], ";" );
            while (token != NULL){
                if (ct%2 == 0)
                    title = token;
                else {
                    date = token;
                    index = er.index(Event(title,"",date,0,""));
                    if (index != -1){
                        d_arr.push_back(er.get_item(index)); // add event to the array
                    }
                }
                ct++;
                token = strtok(NULL,";");
            }
            d_array.push_back(User(user,pass,d_arr));
            user_pass = true;
        }
    }
}

UserRepo::UserRepo() {
    if (d_array.empty())
        read_file();
}

int UserRepo::get_size() {
    return d_array.size();
}

User UserRepo::get_item(int index) {
    return d_array[index];
}

void UserRepo::add_id(int id, const Event &new_elem) {
    d_array[id].add_event(new_elem);
}

void UserRepo::remove_event(int id, Event event) {
    d_array[id].remove_event(event);
}
