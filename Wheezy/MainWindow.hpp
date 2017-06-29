#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtWidgets>
#include "AbilitySpinBox.hpp"
#include "GridHeader.hpp"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void createAbilities();
    void createSkill(QString name,int row);


public slots:
    void makeNewChar();
    void updateAbilities();

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

    // Ability section
    QGridLayout *gridAbility;

    QRadioButton *radioSTR;
    QRadioButton *radioDEX;
    QRadioButton *radioCON;
    QRadioButton *radioINT;
    QRadioButton *radioWIS;
    QRadioButton *radioCHA;

    QSpinBox *spinRollSTR;
    QSpinBox *spinRollDEX;
    QSpinBox *spinRollCON;
    QSpinBox *spinRollINT;
    QSpinBox *spinRollWIS;
    QSpinBox *spinRollCHA;

    AbilitySpinBox *spinRaceSTR;
    AbilitySpinBox *spinRaceDEX;
    AbilitySpinBox *spinRaceCON;
    AbilitySpinBox *spinRaceINT;
    AbilitySpinBox *spinRaceWIS;
    AbilitySpinBox *spinRaceCHA;

    AbilitySpinBox *spinValueSTR;
    AbilitySpinBox *spinValueDEX;
    AbilitySpinBox *spinValueCON;
    AbilitySpinBox *spinValueINT;
    AbilitySpinBox *spinValueWIS;
    AbilitySpinBox *spinValueCHA;

    AbilitySpinBox *spinBonusSTR;
    AbilitySpinBox *spinBonusDEX;
    AbilitySpinBox *spinBonusCON;
    AbilitySpinBox *spinBonusINT;
    AbilitySpinBox *spinBonusWIS;
    AbilitySpinBox *spinBonusCHA;

    // Skill section
    QCheckBox *boxAcrobatics;
    QGridLayout *gridSkill;

};

#endif // MAINWINDOW_HPP
