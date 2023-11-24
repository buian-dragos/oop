#include "gui.h"
#include "../repo/repo.h"
#include "../service/service.h"
#include "QPushButton"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QString"
#include "QLineEdit"
#include "QLabel"
#include "QGroupBox"
#include "iostream"
#include "unistd.h"


Gui::Gui(QWidget *parent) : QMainWindow(parent) {
    user = new QLineEdit{};
    pass = new QLineEdit{};
    file = new QLineEdit{};
    QLabel* pass_label = new QLabel("Password");
    QLabel* user_label = new QLabel("Username");
    QLabel* file_label = new QLabel("1-CSV,2-HTML");

    loginButton = new QPushButton{"Login"};
    QGridLayout* editLayout = new QGridLayout();
    editLayout->addWidget(user_label,0,0);
    editLayout->addWidget(user,1,0);
    editLayout->addWidget(pass_label,2,0);
    editLayout->addWidget(pass,3,0);
    editLayout->addWidget(file_label,4,0);
    editLayout->addWidget(file,5,0);
    editLayout->addWidget(loginButton,6,0);
    QWidget* mainWindow = new QWidget();
    mainWindow->setLayout(editLayout);
    setCentralWidget(mainWindow);
    connnectSignalsAndSlots();
}

void Gui::create() {
    if (user->text() == QString("admin") && pass->text() == QString("admin")) {
        setCursor(Qt::WaitCursor);
        AdminGui* adg = new AdminGui;
        setCursor(Qt::ArrowCursor);
        close();
    } else{
        setCursor(Qt::WaitCursor);
        UserGui* usg = new UserGui(user->text(),pass->text(),file->text());
        setCursor(Qt::ArrowCursor);
        close();
    }
}

void Gui::connnectSignalsAndSlots() {
    QObject::connect(loginButton, &QPushButton::clicked,this, &Gui::create);
}

void AdminGui::init_admin() {
    resize(800,600);
    EventRepo eventRepo;
    aserv = AdminService(eventRepo);


    eventListWidget = new QListWidget{};
    listButton = new QPushButton{"List events"};
    addButton = new QPushButton{"Add event"};
    deleteButton = new QPushButton{"Delete event"};
    updateButton = new QPushButton{"Update Event"};
    exitButton = new QPushButton{"Exit"};

    lineEdit = new QLineEdit();

    QVBoxLayout* mainLayout = new QVBoxLayout();

    mainLayout->addWidget(eventListWidget);

    QGridLayout* buttonsLayout = new QGridLayout();
    buttonsLayout->addWidget(lineEdit,0,0);
    buttonsLayout->addWidget(listButton,1,0);
    buttonsLayout->addWidget(addButton,2,0);
    buttonsLayout->addWidget(deleteButton,3,0);
    buttonsLayout->addWidget(updateButton,4,0);
    buttonsLayout->addWidget(exitButton,5,0);

    mainLayout->addLayout(buttonsLayout);

    QWidget* mainWindow = new QWidget();
    mainWindow->setLayout(mainLayout);
    setCentralWidget(mainWindow);
}

AdminGui::AdminGui(QWidget *parent) : QMainWindow(parent) {
    init_admin();
    connnectSignalsAndSlots();
    this->show();
}

void AdminGui::connnectSignalsAndSlots() {
    QObject::connect(listButton,&QPushButton::clicked,this,&AdminGui::list);
    QObject::connect(addButton,&QPushButton::clicked,this,&AdminGui::add_ev);
    QObject::connect(deleteButton,&QPushButton::clicked,this,&AdminGui::del_ev);
    QObject::connect(updateButton,&QPushButton::clicked,this,&AdminGui::upd_ev);
    QObject::connect(exitButton,&QPushButton::clicked,this,&AdminGui::ext);
}

void AdminGui::list() {
    for (auto ev : aserv.get_events()){
        eventListWidget->addItem(QString(ev.to_string().c_str()));
    }
}

void AdminGui::add_ev() {
//    if (aserv.add_new(lineEdit->text()))
    eventListWidget->addItem(lineEdit->text());
}

void AdminGui::del_ev() {
    QListWidgetItem* selectedItem = eventListWidget->currentItem();
    if (selectedItem) {
        delete eventListWidget->takeItem(eventListWidget->row(selectedItem));
    }
}

void AdminGui::ext() {
    exit(0);
}

void AdminGui::upd_ev() {
    QListWidgetItem* selectedItem = eventListWidget->currentItem();
    if (selectedItem) {
        selectedItem->setText(lineEdit->text());
    }
}

void UserGui::init_user() {
    resize(800,600);
    EventRepo eventRepo;
    UserRepo userRepo;
    userv = UserService(eventRepo,userRepo);


    userv.update_file_type(file_type);

    QLabel* monthLabel =  new QLabel{"Month: ('*' - show all)"};
    month = new QLineEdit();
    eventListWidget = new QListWidget{};
    iterateButton = new QPushButton{"Iterate events"};
    addEventButton = new QPushButton{"Add event"};
    removeButton = new QPushButton{"Remove event"};
    nextButton = new QPushButton{"Next"};
    stopButton = new QPushButton{"Stop iterating"};
    openButton = new QPushButton{"Open file"};
    checkButton = new QPushButton{"Check list"};

    QVBoxLayout* mainLayout = new QVBoxLayout();

    mainLayout->addWidget(eventListWidget);

    QGridLayout* buttonsLayout = new QGridLayout();
    QGridLayout* testLayout = new QGridLayout();

//    buttonsLayout->addWidget(iterateButton,0,0);
    buttonsLayout->addWidget(checkButton,2,0);
    buttonsLayout->addWidget(removeButton,3,0);
    buttonsLayout->addWidget(openButton,4,0);

    testLayout->addWidget(iterateButton,0,0);
    testLayout->addWidget(monthLabel,0,1);
    testLayout->addWidget(month,0,2);

    testLayout->addWidget(nextButton,1,0);
    testLayout->addWidget(addEventButton,1,1);
    testLayout->addWidget(stopButton,1,2);

    buttonsLayout->addLayout(testLayout,1,0);

    mainLayout->addLayout(buttonsLayout);

    QWidget* mainWindow = new QWidget();
    mainWindow->setLayout(mainLayout);
    setCentralWidget(mainWindow);
}

UserGui::UserGui(QString username, QString password, QString fileType) {
    this->file_type = fileType.toInt();
    init_user();
    userv.check_login(username.toStdString(),password.toStdString());
    connnectSignalsAndSlots();
    show();
}

void UserGui::connnectSignalsAndSlots() {
    QObject::connect(iterateButton,&QPushButton::clicked,this,&UserGui::iterate);
    QObject::connect(nextButton,&QPushButton::clicked,this,&UserGui::next_ev);
    QObject::connect(addEventButton,&QPushButton::clicked,this,&UserGui::add_list_ev);
    QObject::connect(checkButton,&QPushButton::clicked,this,&UserGui::check_ev);
    QObject::connect(removeButton,&QPushButton::clicked,this,&UserGui::rem_ev);
    QObject::connect(openButton,&QPushButton::clicked,this,&UserGui::open_file);
}

void UserGui::iterate() {
    std::string mnt = month->text().toStdString();
    temp = userv.iterate_events(mnt);
    index = 0;
    eventListWidget->clear();
}

void UserGui::next_ev() {
    eventListWidget->clear();
    eventListWidget->addItem(temp[index].to_string().c_str());
    index++;
    if (index == temp.size())
        index = 0;
}

void UserGui::add_list_ev() {
    int temp_index = index - 1;
    if (index == -1)
        temp_index = temp.size() - 1;
    userv.add_to_list(temp[temp_index]);
}

void UserGui::check_ev() {
    eventListWidget->clear();
    for (auto event : userv.get_event_list()){
        eventListWidget->addItem(event.to_string().c_str());
    }
}

void UserGui::rem_ev() {
    QListWidgetItem* selectedItem = eventListWidget->currentItem();
    if (selectedItem) {
        int selectedIndex = eventListWidget->row(selectedItem);
        userv.remove_event(userv.get_event_list()[selectedIndex]);
        delete eventListWidget->takeItem(eventListWidget->row(selectedItem));
    }
}

void UserGui::open_file() {
    userv.view_list();
}
