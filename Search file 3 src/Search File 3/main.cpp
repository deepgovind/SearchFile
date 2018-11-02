#include "mainwindow.h"
#include <QApplication>
#include "globlefun.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.setFixedHeight(31);
    w.setFixedWidth(261);

     W1 = &w;
    return a.exec();
}
