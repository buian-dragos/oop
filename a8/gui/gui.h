#pragma once
#include "qlistwidget.h"
#include "qpushbutton.h"
#include "QMainWindow"
#include "QApplication"
#include "QPushButton"

class Gui: public QMainWindow{
private:
    void admin_gui();

public:
    Gui(QWidget *parent = nullptr);

};