#include <QApplication>
#include <QPushButton>
#include "Circle.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.resize(1000, 800);
    window.show();
    window.setWindowTitle(
            QApplication::translate("Wrapper", "Graphics"));
    return app.exec();
}
