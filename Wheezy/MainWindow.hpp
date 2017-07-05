#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtWidgets>
#include <fstream>
#include <string>
#include "AbilitySpinBox.hpp"
#include "GridHeader.hpp"
#include "SkillRow.hpp"

using namespace std;

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void initiateAbilities();
    void initiateAlignment();
    void initiateHitDie();
    void updateHitDie();
    void initiateGold();
    void updateGold();
    void initiateSkill();
    void resetClassSkill();
    void initiateRaces();
    void initiateClasses();

public slots:
    void makeNewChar();
    void updateAbilities();
    void updateClassChoice();
    void updateAlignment();
    void updateSkill();

private:
    // Constructor
    QWidget *centralZone;

    // Character creation
    int leftWidth;
    QComboBox *coreRaces;
    QComboBox *coreClasses;
    QLineEdit *charName;

    QStandardItemModel *modelAbility;

    // Alignment
    QHBoxLayout *layoutAlignment;
    QGroupBox *groupAlignmentLNC;
    QGroupBox *groupAlignmentGNE;
    QVBoxLayout *layoutLNC;
    QVBoxLayout *layoutGNE;
    QRadioButton *alignmentL;
    QRadioButton *alignmentN1;
    QRadioButton *alignmentC;
    QRadioButton *alignmentG;
    QRadioButton *alignmentN2;
    QRadioButton *alignmentE;

    // Ability section
    QGroupBox *groupAbility;
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

    // Hit Die
    QGroupBox *groupHit;
    QHBoxLayout *layoutHit;
    QLabel *labelHitDie;
    QSpinBox *spinHit;

    // Gold
    QGroupBox *groupGold;
    QHBoxLayout *layoutGold;
    QLabel *labelGoldDie;
    QSpinBox *spinGold;

    // Skill section
    QVBoxLayout *layoutSkillRow;
    QGridLayout *layoutLabelSkill;
    QScrollArea *scrollAreaSkill;
    SkillRow *rowAcrobatics;
    SkillRow *rowAppraise;
    SkillRow *rowBluff;
    SkillRow *rowClimb;
    SkillRow *rowCraft;
    SkillRow *rowDiplomacy;
    SkillRow *rowDisableDevice;
    SkillRow *rowDisguise;
    SkillRow *rowEscapeArtist;
    SkillRow *rowFly;
    SkillRow *rowHandleAnimal;
    SkillRow *rowHeal;
    SkillRow *rowIntimidate;
    SkillRow *rowKnArcana;
    SkillRow *rowKnDungeoneering;
    SkillRow *rowKnEngineering;
    SkillRow *rowKnGeography;
    SkillRow *rowKnHistory;
    SkillRow *rowKnLocal;
    SkillRow *rowKnNature;
    SkillRow *rowKnNobility;
    SkillRow *rowKnPlanes;
    SkillRow *rowKnReligion;
    SkillRow *rowLinguistics;
    SkillRow *rowPerception;
    SkillRow *rowPerform;
    SkillRow *rowProfession;
    SkillRow *rowRide;
    SkillRow *rowSenseMotive;
    SkillRow *rowSleighOfHand;
    SkillRow *rowSpellcraft;
    SkillRow *rowStealth;
    SkillRow *rowSurvival;
    SkillRow *rowSwim;
    SkillRow *rowUseMagicDevice;

};

#endif // MAINWINDOW_HPP
