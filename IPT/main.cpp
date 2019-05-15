#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.show();
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}




//int main(int argc, char* argv[])
//{
//    QApplication app(argc, argv);

//    cvImage win;
//    win.show();

//    QObject::connect(&win, SIGNAL(closed()),
//                     &app, SLOT(quit()) );

//    return app.exec();
//}
