#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    // Needed
    QApplication app(argc, argv);

    // Main window creation
    MainWindow window;
    // Main window show
    window.show();

    // App run. Needed.
    return app.exec();
}
