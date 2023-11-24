#include <QApplication>
#include <QPushButton>
#include "ui/ui.h"
#include "gui/gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    Ui ui;
    Gui gui;
//    AdminGui adminGui;
    gui.show();
//    adminGui.show();

    return QApplication::exec();
}
