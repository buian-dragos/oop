#include "gui.h"
#include "../repo/repo.h"
#include "../service/service.h"
#include "QPushButton"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QString"

void Gui::admin_gui() {
    resize(800,600);
    EventRepo eventRepo;
    AdminService aserv(eventRepo);

    QListWidget* eventListWidget;
    QPushButton* listButton, *addButton, *deleteButton, *updateButton, *exitButton;

    eventListWidget = new QListWidget{this};
    listButton = new QPushButton{"List events"};
    addButton = new QPushButton{"Add event"};
    deleteButton = new QPushButton{"Delete event"};
    exitButton = new QPushButton{"Exit"};

    QVBoxLayout* mainLayout = new QVBoxLayout();

    mainLayout->addWidget(eventListWidget);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(listButton,0,0);
    buttonsLayout->addWidget(addButton,1,0);
    buttonsLayout->addWidget(deleteButton,2,0);
    buttonsLayout->addWidget(exitButton,3,0);

    mainLayout->addLayout(buttonsLayout);

    QWidget* mainWindow = new QWidget();
    mainWindow->setLayout(mainLayout);
    setCentralWidget(mainWindow);

    for (auto ev : eventRepo.get_arr()){
        eventListWidget->addItem(QString(ev.to_string().c_str()));
    }

}

Gui::Gui(QWidget *parent) : QMainWindow(parent) {
    admin_gui();
}
