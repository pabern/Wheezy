#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtWidgets>

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
public slots:
    void makeNewChar();
private:
    // Constructor
    QWidget *centralZone;

    // Character creation
    QComboBox *coreRaces;
    QComboBox *coreClasses;
    QLineEdit *charName;
    QComboBox *alignment1;
    QComboBox *alignment2;
    QStandardItemModel *modelAbility;

};

#endif // MAINWINDOW_HPP
