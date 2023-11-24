#pragma once
#include "qlistwidget.h"
#include "qpushbutton.h"
#include "QMainWindow"
#include "QApplication"
#include "QPushButton"
#include "QString"
#include "QLineEdit"
#include "vector"
#include "../domain/event.h"
#include "../service/service.h"

class Gui: public QMainWindow{
private:
    QLineEdit* user, *pass,*file;
    QPushButton* loginButton;
public:
    Gui(QWidget *parent = nullptr);
    void connnectSignalsAndSlots();
public slots:
    void create();
};

class AdminGui: public QMainWindow{
private:
    AdminService aserv;
    QListWidget* eventListWidget;
    QPushButton* listButton, *addButton, *deleteButton, *updateButton, *exitButton;
    QLineEdit* lineEdit;
    void init_admin();
public:
    AdminGui(QWidget *parent = nullptr);
    void connnectSignalsAndSlots();
public slots:
    void list();
    void add_ev();
    void del_ev();
    void ext();
    void upd_ev();
};

class UserGui: public QMainWindow{
private:
    UserService userv;
    std::vector<Event> temp;
    int file_type,index;
    QLineEdit* month;
    QListWidget* eventListWidget;
    QPushButton* iterateButton, *nextButton, *addEventButton, *stopButton, *checkButton, *removeButton,*openButton;
    void init_user();
public:
    void connnectSignalsAndSlots();
    UserGui(QString username, QString password,QString fileType);
public slots:
    void iterate();
    void next_ev();
    void add_list_ev();
    void check_ev();
    void rem_ev();
    void open_file();
};