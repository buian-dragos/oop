#include "event.h"

Event::Event()
{
    name = "";
    description = "";
    date = "";
    number_of_people = 0;
}

Event::Event(std::string nm, std::string desc, std::string dt, int n_p, std::string lnk)
{
    name = nm;
    description = desc;
    date = dt;
    number_of_people = n_p;
    link = lnk;
}

//std::string Event::get_name()
//{
//    return name;
//}
//
//std::string Event::get_date()
//{
//    return date;
//}
//
//std::string Event::get_desc()
//{
//    return description;
//}

std::string Event::get_link()
{
    return link;
}

bool Event::is_equal(Event ev) {
    if (name == ev.name && date==ev.date)
        return true;
    return false;
}

std::string Event::to_string() {
    std::string rs;
    rs.append(name);
    rs.append(" ");
    rs.append(description);
    rs.append(" ");
    rs.append(date);
    rs.append(" ");
    rs.append(std::to_string(number_of_people));
    rs.append(" ");
    rs.append(link);
    rs.append("\n");
    return rs;
}

std::string Event::get_mnth() {
    char mnth[4];
    mnth[0] = date[3];
    mnth[1] = date[4];
    mnth[2] = '\0';
    return mnth;
}

std::string Event::to_csv() {
    std::string rs;
    rs.append(name);
    rs.append(",");
    rs.append(description);
    rs.append(",");
    rs.append(date);
    rs.append(",");
    rs.append(std::to_string(number_of_people));
    rs.append(",");
    rs.append(link);
    rs.append("\n");
    return rs;
}

//int Event::get_part() {
//    return number_of_people;
//}


