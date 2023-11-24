#include "repo/repo.h"
#include "service/service.h"
#include "ui/ui.h"
#include "tests.h"


int main() {
    EventRepo eventRepo;
    UserRepo userRepo;
    AdminService adminService(eventRepo);

	Ui ui;
    return 0;
}