#include "statki.h"

#include <QApplication>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    Statki w;
    w.show();
    return a.exec();

}
