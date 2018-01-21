#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtWidgets>
#include "NewCharWindow.hpp"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void makeNewChar();
    void saveNewChar();

private:
    // Constructor
    QWidget *centralZone;

    QMenu *menuChar;
    QAction *actionNewChar;
    QAction *actionSaveChar;

    NewCharWindow *layoutNewChar;
};

#endif // MAINWINDOW_HPP
