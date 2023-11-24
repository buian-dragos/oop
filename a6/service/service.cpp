#include "service.h"


AdminService::AdminService(const EventRepo& er) {
    event_repo = er;
}
std::string AdminService::list_events()
{
    return event_repo.list();
}

void AdminService::add_event(std::string title, std::string desc, std::string dt, int nr_part, std::string link)
{
    Event new_event(title, desc, dt, nr_part, link);
    if (event_repo.index(new_event)!=-1) {
        std::cout << "Event arleady exists\n";
        return;
    }
    event_repo.add_event(new_event);
}

void AdminService::delete_event(std::string title, std::string dt)
{   int index = event_repo.index(Event(title,"",dt,0,""));
    if (index == -1) {
        std::cout << "Event doesn't exists\n";
        return;
    }
    event_repo.remove_event(index);
}

void AdminService::update_event(std::string old_title, std::string old_dt, std::string title, std::string desc, std::string dt, int nr_part, std::string link)
{
    Event new_event(title, desc, dt, nr_part, link);
    event_repo.update_event(new_event,event_repo.index(Event(old_title,"",old_dt,1,"")));
}


UserService::UserService(const EventRepo &er,const UserRepo& ur) {
    event_repo = er;
    user_repo = ur;
}

/*
void UserService::iterate_events(std::string month) {
    std::string command;
    Event current;
    bool add = true;
    for (int i = 0; i < event_repo.get_size(); i++){
        current = event_repo.get_item(i);
        ShellExecute(NULL, NULL, current.get_link().c_str(), NULL, NULL, SW_SHOWNORMAL);
        if (month == "*" || month == current.get_mnth()){
            std::cout << current.to_string();
            std::cout << "(commands: \"next\",\"add\",\"menu\")\n>";
            std::cin >> command;
            if (command == "next"){

            }
            else if (command == "add"){
                DynamicArray<Event> e_l = user_repo.get_item(id).get_array();
                add = true;
                for (int j = 0; j < e_l.get_size(); j++){
                    if (e_l.get_item(i).is_equal(current)){
                        std::cout << "Event is already in user list!\n";
                        add = false;
                        break;
                    }
                }
                if (add) {
                    Event new_event(current.get_name(),current.get_desc(),current.get_date(),current.get_part() + 1,current.get_link());
                    std::cout << new_event.to_string();
                    event_repo.update_event(new_event,i);
                    user_repo.add_id(id, new_event);
                }
            } else if (command == "menu")
                return;
            else {
                i--;
                std::cout << "Invalid command!\n";
            }
        }
        if (i == event_repo.get_size() - 1)
            i = -1;
    }
}
*/
std::vector<Event> UserService::iterate_events(std::string month) {
    std::vector<Event> temp;
    for (auto event : event_repo.get_arr()){
        if (month == "*" || month == event.get_mnth())
            temp.push_back(event);
    }
    return temp;
}

void UserService::check_login(std::string user, std::string pass) {
    for (int i = 0; i < user_repo.get_size(); i++){
        if (user == user_repo.get_item(i).get_user() && pass == user_repo.get_item(i).get_pass()) {
            id = i;
            return;
        }
    }
    std::cout << "Invalid username/password";
    exit(0);
}

std::string UserService::check_list() {
    return user_repo.get_item(id).get_list();
}

void UserService::remove_event(Event event) {
    event.dec_part();
    event_repo.dec_pt(event);
    user_repo.remove_event(id,event);
}

void UserService::add_to_list(Event ev) {
    ev.inc_part();
    event_repo.inc_pt(ev);
    user_repo.add_id(id,ev);
}
