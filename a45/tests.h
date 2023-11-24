#include "repo/repo.h"
#include "service/service.h"
//#include <assert.h>

void test_admin(){
    EventRepo eventRepo;
    AdminService aserv(eventRepo);

    aserv.add_event("aaa","bbb","01.01.2001",2,"https://www.timesnewroman.ro/");

    aserv.add_event("aaa", "aaa", "01.01.2001",200,"invalid");

    aserv.list_events();

    aserv.update_event("aaa","01.01.2001","TNR","bbb","01.01.2001",2,"https://www.timesnewroman.ro/");

    aserv.update_event("aaa","01.01.2001","nu","bbb","01.01.2001",2,"https://www.timesnewroman.ro/");

    aserv.list_events();

    aserv.delete_event("TNR","01.01.2001");

    aserv.delete_event("TNR","01.01.2001");

    aserv.list_events();
}

void test_user() {
    EventRepo eventRepo;
    UserRepo userRepo;
    UserService userv(eventRepo,userRepo);
    userv.check_login("user1","pass1");

    userv.check_list();

    userv.iterate_events("*");

    userv.iterate_events("07");

    userv.remove_event(Event("aaa","bbb","01.01.2001",2,"invalid"));

    userv.remove_event(Event("Untold","","03.08.2023",0,""));

    userv.check_login("invalid","invalid");
}

void run_tests(){
    test_admin();
    test_user();
}
