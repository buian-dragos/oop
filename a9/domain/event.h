#pragma once

#include <string>

class Event {
private:
    std::string name;
    std::string description;
    std::string date;
    int number_of_people;
    std::string link;

public:
    Event();
    Event(std::string nm, std::string desc, std::string dt, int n_p,std::string lnk);
    int get_part() {return number_of_people;}
    std::string get_name() {return name;}
    std::string get_date() {return date;}
    std::string get_desc() {return description;}
    std::string get_link();
    std::string get_mnth();

//  returns the number of participants to a given event
//    int get_part();

    void inc_part(){
        number_of_people++;
    }
    void dec_part(){
        number_of_people--;
    }

    bool is_equal(Event ev);
    std::string to_string();

    std::string to_csv();
};