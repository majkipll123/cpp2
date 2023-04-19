//dziedziczenie i funkcje wirtualne 
//biblioteka qt budowa w qmake 
//pisanie GUI
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}