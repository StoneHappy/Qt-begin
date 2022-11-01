#include "a_QtMeatObjectEx/ExWidget.h"
#include "b_QStringEx/ExQString.h"
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


namespace QtBegin {
    namespace b_QStringEx {
        int main(int argc, char *argv[])
        {
            QApplication a(argc, argv);

            ExQString w;

            w.show();

            return a.exec();
        }
    }
}