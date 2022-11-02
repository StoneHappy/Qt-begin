#include "Series/e_ExQProgressBar/ExQProgressBar.h"
#include "a_QtMeatObjectEx/ExWidget.h"
#include "b_QStringEx/ExQString.h"
#include "c_QtQStringFunEx/ExQStringFun.h"
#include "d_ExQSlider/ExQSlider.h"
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

namespace QtBegin {
    namespace c_QtQStringFunEx {
        int main(int argc, char *argv[])
        {
            QApplication a(argc, argv);

            ExQStringFun w;

            w.show();

            return a.exec();
        }
    }
}

namespace QtBegin {
    namespace d_ExQSlider {
        int main(int argc, char *argv[])
        {
            QApplication a(argc, argv);

            ExQSlider w;

            w.show();

            return a.exec();
        }
    }
}

namespace QtBegin {
    namespace e_ExQProgressBar {
        int main(int argc, char *argv[])
        {
            QApplication a(argc, argv);

            ExQProgressBar w;

            w.show();

            return a.exec();
        }
    }
}