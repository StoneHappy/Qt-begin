#include "a_QtMeatObjectEx/exwidget.h"
#include <qapplication.h>

namespace QtBegin {
    namespace a_QtMetaObjectEx {
        int main(int argc, char *argv[])
        {
            QApplication a(argc, argv);

            ExWidget w;

            w.show();

            return a.exec();
        }
    }
}