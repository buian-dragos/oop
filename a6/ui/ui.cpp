#include "ui.h"
#include "../service/service.h"

#include <iostream>
#include <string>

void Ui::admin_menu()
{
    int option;
    EventRepo eventRepo;
    AdminService aserv(eventRepo);
    std::string nm;
    std::string old_nm;
    std::string desc;
    std::string dt;
    std::string old_dt;
    int n_p;
    std::string lnk;
    while (true)
    {
        std::cout << "\n1. List events\n";
        std::cout << "2. Add event\n";
        std::cout << "3. Delete event\n";
        std::cout << "4. Update event\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> option;
        switch (option)
        {
            case 1:
                std::cout << aserv.list_events();
                break;
            case 2:
                std::cout << "Title: ";
                std::cin >> nm;
                std::cout << "Description: ";
                std::cin >> desc;
                std::cout << "Date: ";
                std::cin >> dt;
                std::cout << "Number of people: ";
                std::cin >> n_p;
                std::cout << "Link: ";
                std::cin >> lnk;
                aserv.add_event(nm, desc, dt, n_p, lnk);
                break;
            case 3:
                std::cout << "Title: ";
                std::cin >> nm;
                std::cout << "Date: ";
                std::cin >> dt;
                aserv.delete_event(nm, dt);
                break;
            case 4:
                std::cout << "Title: ";
                std::cin >> old_nm;
                std::cout << "Date: ";
                std::cin >> old_dt;
                std::cout << "New title: ";
                std::cin >> nm;
                std::cout << "New description: ";
                std::cin >> desc;
                std::cout << "New date: ";
                std::cin >> dt;
                std::cout << "New number of people: ";
                std::cin >> n_p;
                std::cout << "New link: ";
                std::cin >> lnk;
                aserv.update_event(old_nm,old_dt,nm,desc,dt,n_p,lnk);
                break;
            case 0:
                exit(0);
            default:
                break;
        }
    }
}

void Ui::user_menu(std::string user, std::string pass)
{
    EventRepo eventRepo;
    UserRepo userRepo;
    UserService userv(eventRepo,userRepo);
    userv.check_login(user,pass);
    int condition;
    std::string month,nm,dt;
    while (true){
        std::cout << "\n1. See events\n";
        std::cout << "2. Check my list\n";
        std::cout << "3. Delete event\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> condition;
        switch (condition) {
            case 1:
                std::cout << "('*' to show all)\nChoose a month: ";
                std::cin >> month;
                if ((month != "*") && ((month[0] != '0' && month[0] != '1') || (month[1] < '0' || month[2] > '9')))
                    std::cout << "Invalid month!\n";
                else {
                    std::string command;
                    bool run = true;
                    std::vector<Event> temp = userv.iterate_events(month);
                    while (run){
                        for (auto event : temp){
                            ShellExecute(NULL, NULL, event.get_link().c_str(), NULL, NULL, SW_SHOWNORMAL);
                            std::cout << event.to_string();
                            std::cout << "(commands: \"next\",\"add\",\"menu\")\n>";
                            std::cin >> command;
                            if (command == "add"){
                                userv.add_to_list(event);
                            }
                            else if (command == "menu"){
                                run = false;
                                break;
                            }

                        }
                    }
                }
                break;
            case 2:
                std::cout << "My list:\n" << userv.check_list();
                break;
            case 3:
                std::cout << "Title: ";
                std::cin >> nm;
                std::cout << "Date: ";
                std::cin >> dt;
                userv.remove_event(Event(nm,"",dt,0,""));
                break;
            case 0:
                return;
            default:
                break;

        }
    }
}

Ui::Ui() {
    std::string option,user,pass;

    std::cout << "Username: ";
    std::cin >> user;
    std::cout << "Password: ";
    std::cin >> pass;
    if (user == "admin" && pass == "admin")
        admin_menu();
    else{
        user_menu(user,pass);
    }
}
