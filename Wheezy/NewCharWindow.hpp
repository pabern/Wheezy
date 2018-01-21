#ifndef NEWCHARWINDOW_HPP
#define NEWCHARWINDOW_HPP

#include <QtWidgets>
#include <fstream>
#include <limits>
#include <string>
#include "GridHeader.hpp"
#include "SkillRow.hpp"
#include "AbilityRow.hpp"

class NewCharWindow: public QHBoxLayout
{
    Q_OBJECT

public:
    NewCharWindow();

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
    void updateRaceChoice();
    void updateAbilities();
    void updateClassChoice();
    void updateAlignment();
    void updateAlignment(std::ifstream& file);
    void updateHitDie(std::ifstream& file);
    void updateGold(std::ifstream& file);
    void updateFeats(std::ifstream& file);
    void updateSkill(std::ifstream& file);
    void resetClassSkill();
    void resetRanks();
    void updateRanksLeft();

    // For saving
    int getRanksLeft();
    QString getCharName();
    QString getCoreRaces();
    QString getCoreClasses();
    std::string getAlignment();
    void writeAbilities(std::ostream& file);
    std::string getFeats();
    int getHit();
    int getGold();
    void writeSkills(std::ofstream& file);

private:
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

    QSpinBox *ranksLeft;
    int ranksLeftValue;
    QHBoxLayout *layoutName;

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

    // Feats
    QGroupBox *groupFeat;
    QVBoxLayout * layoutFeat;
    QLineEdit *lineFeat1;
    QLineEdit *lineFeat2;
    QLineEdit *lineFeat3;
    int numberFeats;

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

    SkillRow *tableSkills[35];
};

#endif // NEWCHARWINDOW_HPP
