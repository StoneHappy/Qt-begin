#include <iostream>
#include <Series/a_QtMeatObjectEx/exwidget.h>
#include <qapplication.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ExWidget w;

    w.show();

    return a.exec();
}
