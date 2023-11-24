#include "service.h"
#include "fstream"
#include "cstdlib"

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
    save_file();
}

void UserService::add_to_list(Event ev) {
    ev.inc_part();
    event_repo.inc_pt(ev);
    user_repo.add_id(id, ev);
    save_file();
}

void UserService::update_file_type(int ft) {
    file_type = ft;
    save_file();

}

void HTML_file::open_file() {
    std::system("start ../repo/list.html");
}
void HTML_file::save_file() {
    std::ofstream f("../repo/list.html");
    f << "<!DOCTYPE html>\n";
    f << "<html>\n";
    f << "\t<title>User Event List</title>\n";
    f << "<body>\n";
    f << "<table border=\"1\">\n";
    f << "\t<tr>\n";
    f << "\t\t<td>Name</td>\n";
    f << "\t\t<td>Description</td>\n";
    f << "\t\t<td>Date</td>\n";
    f << "\t\t<td>Participants</td>\n";
    f << "\t\t<td>Link</td>\n";
    f << "\t</tr>\n";
    for (auto ev : user_repo.get_item(id).get_array()){
        f << "\t<tr>\n";
        f << "\t\t<td>" << ev.get_name() << "</td>\n";
        f << "\t\t<td>" << ev.get_desc() << "</td>\n";
        f << "\t\t<td>" << ev.get_date() << "</td>\n";
        f << "\t\t<td>" << ev.get_part() << "</td>\n";
        f << "\t\t<td><a href=\"" << ev.get_link() << "\">Link</a></td>\n";
        f << "\t</tr>\n";
    }
    f << "</table>\n";
    f << "</body>\n";
    f << "</html>\n";

    f.close();
}

HTML_file::~HTML_file() {

}

void CSV_file::save_file() {
    std::ofstream f("../repo/list.csv");
    for (auto ev : user_repo.get_item(id).get_array()){
        f << ev.to_csv();
    }
    f.close();
}

void CSV_file::open_file() {
    std::system("start excel.exe ../repo/list.csv");
}

CSV_file::~CSV_file() {

}
