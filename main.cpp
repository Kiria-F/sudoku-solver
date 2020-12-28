#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    w.setFieldValue(3, 3, 5);
//    qDebug() << w.getFieldValue(3, 3);
    return a.exec();
}
