#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtWidgets>
#include <fstream>
#include <limits>
#include <string>
#include "GridHeader.hpp"
#include "SkillRow.hpp"
#include "AbilityRow.hpp"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    // Initiations
    void initiateRaces();
    void initiateClasses();
    void initiateAlignment();
    void initiateAbilities();
    void initiateFeats();
    void initiateHitDie();
    void initiateGold();
    void initiateSkill();

    // Functions to lighten
    void setRaceValues(int STR, int DEX, int CON, int INT, int WIS, int CHA);

public slots:
    // Updates and resets
    void makeNewChar();
    void updateRaceChoice();
    void updateAbilities();
    void updateClassChoice();
    void updateAlignment();
    void updateAlignment(std::ifstream& file);
    void updateHitDie(std::ifstream& file);
    void updateGold(std::ifstream& file);
    void updateFeats(std::ifstream& file);
    void updateSkill();
    void resetClassSkill();

private:
    // Constructor
    QWidget *centralZone;

    // Character creation
    int leftWidth;
    QComboBox *coreRaces;
    int raceSTR;
    int raceDEX;
    int raceCON;
    int raceINT;
    int raceWIS;
    int raceCHA;
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

    int enLint;
    bool enN1;
    bool enC;
    bool enG;
    bool enN2;
    bool enE;

    // Ability section
    QGroupBox *groupAbility;
    QHBoxLayout *layoutLabelAbility;
    QVBoxLayout *layoutAbility;

    AbilityRow *abilitySTR;
    AbilityRow *abilityDEX;
    AbilityRow *abilityCON;
    AbilityRow *abilityINT;
    AbilityRow *abilityWIS;
    AbilityRow *abilityCHA;

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
    QHBoxLayout *layoutLabelSkill;
    QScrollArea *scrollAreaSkill;

    GridHeader *labelClassSkill;
    GridHeader *labelSkill;
    GridHeader *labelSkillRank;
    GridHeader *labelSkillClass;
    GridHeader *labelSkillAbility;
    GridHeader *labelSkillTotal;

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

    // Feats
    QGroupBox *groupFeat;
    QVBoxLayout * layoutFeat;
    QLineEdit *lineFeat1;
    QLineEdit *lineFeat2;
    QLineEdit *lineFeat3;

};

#endif // MAINWINDOW_HPP
