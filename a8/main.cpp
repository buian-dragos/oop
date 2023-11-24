#include <QApplication>
#include <QPushButton>
#include "ui/ui.h"
#include "gui/gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    Ui ui;
    Gui gui;
    gui.show();

    return QApplication::exec();
}
