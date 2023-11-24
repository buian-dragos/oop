//#include "old_service.h"
//
//std::string AdminService::list_events()
//{
//    return dv.list();
//}
//
//void AdminService::add_event(std::string title, std::string desc, std::string dt, int nr_part, std::string link)
//{
//    Event new_event(title, desc, dt, nr_part, link);
//    if (dv.index(title,dt)!=-1) {
//        std::cout << "Event arleady exists\n";
//        return;
//    }
//    dv.add(new_event);
//}
//
//void AdminService::delete_event(std::string title, std::string dt)
//{   int index = dv.index(title,dt);
//    if (index == -1) {
//        std::cout << "Event doesn't exists\n";
//        return;
//    }
//    dv.remove(index);
//}
//
//void AdminService::update_event(std::string old_title, std::string old_dt, std::string title, std::string desc, std::string dt, int nr_part, std::string link)
//{
//    Event new_event(title, desc, dt, nr_part, link);
//    int index = dv.index(old_title, old_dt);
//    if (index == -1) {
//        std::cout << "Event doesn't exists";
//        return;
//    }
//    dv.update(new_event,index);
//}
//
//void AdminService::memory()
//{
//    add_event("Event1", "Desc1", "10.01.2024", 200, "link1");
//    add_event("Event2", "Desc2", "4.11.2023", 600, "link2");
//    add_event("Event3", "Desc3", "11.02.2024", 3, "link3");
//    add_event("Event4", "Desc4", "24.12.2023", 700000, "link4");
//    add_event("Event5", "Desc5", "10.10.2023", 111, "link5");
//    add_event("Event6", "Desc6", "9.07.2020", 400, "link6");
//    add_event("Event7", "Desc7", "01.01.2030", 1, "link7");
//    add_event("Event8", "Desc8", "10.07.2023", 200, "link8");
//    add_event("Event9", "Desc9", "11.02.2024", 333, "link9");
//    add_event("Event10", "Desc10", "4.08.2023", 20000, "link10");
//}
