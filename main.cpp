#include "statki.h"
#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Statki w;
    menu s;
    s.show();
    //w.show();
    //w.hide();
    //w.open_menu();
    return a.exec();

}
