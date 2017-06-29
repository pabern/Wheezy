#include "MainWindow.hpp"

#include <QDebug>

MainWindow::MainWindow()
{
    // Attributes of main window
    setWindowTitle("Welcome to Wheezy !");
    // setFixedSize(1500,750);

    // Menus
    // Character creation menu
    QMenu *menuCharCreation = menuBar()->addMenu("Creation");

    QAction *actionNewChar = new QAction("New character",this);
    menuCharCreation->addAction(actionNewChar);
    connect(actionNewChar,SIGNAL(triggered(bool)),this,SLOT(makeNewChar()));

    // Obligatory first line
    // Container for ALL other widgets of main window
    centralZone = new QWidget;

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}

void MainWindow::createSkill(QString name,int row)
{
    int col(0);
    if (row > 18)
    {
        row -= 18;
        col = 6;
    }

    QLabel *label = new QLabel;
    label->setText(name);

    QSpinBox *spinRank = new QSpinBox;
    spinRank->setValue(0);
    spinRank->setMinimum(0);
    spinRank->setMaximum(1); // Level is maximum

    QSpinBox *spinClass = new QSpinBox;
    spinClass->setValue(0);
    spinClass->setReadOnly(true);
    spinClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinAbility = new QSpinBox;
    spinAbility->setValue(0);
    spinAbility->setReadOnly(true);
    spinAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinOther = new QSpinBox;
    spinOther->setValue(0);
    spinOther->setReadOnly(true);
    spinOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinTotal = new QSpinBox;
    spinTotal->setValue(0);
    spinTotal->setReadOnly(true);
    spinTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    gridSkill->addWidget(label,row,col);
    gridSkill->addWidget(spinRank,row,col+1);
    gridSkill->addWidget(spinClass,row,col+2);
    gridSkill->addWidget(spinAbility,row,col+3);
    gridSkill->addWidget(spinOther,row,col+4);
    gridSkill->addWidget(spinTotal,row,col+5);

}

void MainWindow::makeNewChar()
{
    // Name
    charName = new QLineEdit;
    charName->setText("Full Name");

    // Core race selection
    coreRaces = new QComboBox;
    coreRaces->addItem("Dwarf");
    coreRaces->addItem("Elf");
    coreRaces->addItem("Gnome");
    coreRaces->addItem("Half Elf");
    coreRaces->addItem("Half Orc");
    coreRaces->addItem("Halfling");
    coreRaces->addItem("Human");

    // Core class selection
    coreClasses = new QComboBox;
    coreClasses->addItem("Barbarian");
    coreClasses->addItem("Bard");
    coreClasses->addItem("Cleric");
    coreClasses->addItem("Druid");
    coreClasses->addItem("Fighter");
    coreClasses->addItem("Monk");
    coreClasses->addItem("Paladin");
    coreClasses->addItem("Ranger");
    coreClasses->addItem("Rogue");
    coreClasses->addItem("Sorcerer");
    coreClasses->addItem("Wizard");

    // Alignment selection
    alignment1 = new QComboBox;
    alignment1->addItem("Lawful");
    alignment1->addItem("Neutral");
    alignment1->addItem("Chaotic");

    alignment2 = new QComboBox;
    alignment2->addItem("Good");
    alignment2->addItem("Neutral");
    alignment2->addItem("Evil");

    QHBoxLayout *alignmentLayout = new QHBoxLayout;
    alignmentLayout->addWidget(alignment1);
    alignmentLayout->addWidget(alignment2);

    // Ability scores
    QLabel *labelAbility = new QLabel;
    labelAbility->setText("Ability");
    QLabel *labelAbilityRoll = new QLabel;
    labelAbilityRoll->setText("Roll");
    QLabel *labelAbilityRace = new QLabel;
    labelAbilityRace->setText("Race");
    QLabel *labelAbilityValue = new QLabel;
    labelAbilityValue->setText("Value");
    QLabel *labelAbilityBonus = new QLabel;
    labelAbilityBonus->setText("Bonus");

    QLabel *labelSTR = new QLabel;
    labelSTR->setText("STR");
    QLabel *labelDEX = new QLabel;
    labelDEX->setText("DEX");
    QLabel *labelCON = new QLabel;
    labelCON->setText("CON");
    QLabel *labelINT = new QLabel;
    labelINT->setText("INT");
    QLabel *labelWIS = new QLabel;
    labelWIS->setText("WIS");
    QLabel *labelCHA = new QLabel;
    labelCHA->setText("CHA");

    // Probably could do a custom class derived from QSPinBox for this...
    QSpinBox *spinSTRRoll = new QSpinBox;
    spinSTRRoll->setValue(14);
    spinSTRRoll->setMinimum(4);
    spinSTRRoll->setMaximum(24);
    QSpinBox *spinDEXRoll = new QSpinBox;
    spinDEXRoll->setValue(14);
    spinDEXRoll->setMinimum(4);
    spinDEXRoll->setMaximum(24);
    QSpinBox *spinCONRoll = new QSpinBox;
    spinCONRoll->setValue(14);
    spinCONRoll->setMinimum(4);
    spinCONRoll->setMaximum(24);
    QSpinBox *spinINTRoll = new QSpinBox;
    spinINTRoll->setValue(14);
    spinINTRoll->setMinimum(4);
    spinINTRoll->setMaximum(24);
    QSpinBox *spinWISRoll = new QSpinBox;
    spinWISRoll->setValue(14);
    spinWISRoll->setMinimum(4);
    spinWISRoll->setMaximum(24);
    QSpinBox *spinCHARoll = new QSpinBox;
    spinCHARoll->setValue(14);
    spinCHARoll->setMinimum(4);
    spinCHARoll->setMaximum(24);

    QSpinBox *spinSTRRace = new QSpinBox;
    spinSTRRace->setValue(0);
    spinSTRRace->setReadOnly(true);
    spinSTRRace->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinDEXRace = new QSpinBox;
    spinDEXRace->setValue(0);
    spinDEXRace->setReadOnly(true);
    spinDEXRace->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinCONRace = new QSpinBox;
    spinCONRace->setValue(0);
    spinCONRace->setReadOnly(true);
    spinCONRace->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinINTRace = new QSpinBox;
    spinINTRace->setValue(0);
    spinINTRace->setReadOnly(true);
    spinINTRace->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinWISRace = new QSpinBox;
    spinWISRace->setValue(0);
    spinWISRace->setReadOnly(true);
    spinWISRace->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinCHARace = new QSpinBox;
    spinCHARace->setValue(0);
    spinCHARace->setReadOnly(true);
    spinCHARace->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinSTRValue = new QSpinBox;
    spinSTRValue->setValue(0);
    spinSTRValue->setReadOnly(true);
    spinSTRValue->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinDEXValue = new QSpinBox;
    spinDEXValue->setValue(0);
    spinDEXValue->setReadOnly(true);
    spinDEXValue->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinCONValue = new QSpinBox;
    spinCONValue->setValue(0);
    spinCONValue->setReadOnly(true);
    spinCONValue->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinINTValue = new QSpinBox;
    spinINTValue->setValue(0);
    spinINTValue->setReadOnly(true);
    spinINTValue->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinWISValue = new QSpinBox;
    spinWISValue->setValue(0);
    spinWISValue->setReadOnly(true);
    spinWISValue->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinCHAValue = new QSpinBox;
    spinCHAValue->setValue(0);
    spinCHAValue->setReadOnly(true);
    spinCHAValue->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinSTRBonus = new QSpinBox;
    spinSTRBonus->setValue(0);
    spinSTRBonus->setReadOnly(true);
    spinSTRBonus->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinDEXBonus = new QSpinBox;
    spinDEXBonus->setValue(0);
    spinDEXBonus->setReadOnly(true);
    spinDEXBonus->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinCONBonus = new QSpinBox;
    spinCONBonus->setValue(0);
    spinCONBonus->setReadOnly(true);
    spinCONBonus->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinINTBonus = new QSpinBox;
    spinINTBonus->setValue(0);
    spinINTBonus->setReadOnly(true);
    spinINTBonus->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinWISBonus = new QSpinBox;
    spinWISBonus->setValue(0);
    spinWISBonus->setReadOnly(true);
    spinWISBonus->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QSpinBox *spinCHABonus = new QSpinBox;
    spinCHABonus->setValue(0);
    spinCHABonus->setReadOnly(true);
    spinCHABonus->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QGridLayout *gridAbility = new QGridLayout;
    gridAbility->addWidget(labelAbility,0,0);
    gridAbility->addWidget(labelAbilityRoll,0,1);
    gridAbility->addWidget(labelAbilityRace,0,2);
    gridAbility->addWidget(labelAbilityValue,0,3);
    gridAbility->addWidget(labelAbilityBonus,0,4);

    gridAbility->addWidget(labelSTR,1,0);
    gridAbility->addWidget(labelDEX,2,0);
    gridAbility->addWidget(labelCON,3,0);
    gridAbility->addWidget(labelINT,4,0);
    gridAbility->addWidget(labelWIS,5,0);
    gridAbility->addWidget(labelCHA,6,0);

    gridAbility->addWidget(spinSTRRoll,1,1);
    gridAbility->addWidget(spinDEXRoll,2,1);
    gridAbility->addWidget(spinCONRoll,3,1);
    gridAbility->addWidget(spinINTRoll,4,1);
    gridAbility->addWidget(spinWISRoll,5,1);
    gridAbility->addWidget(spinCHARoll,6,1);

    gridAbility->addWidget(spinSTRRace,1,2);
    gridAbility->addWidget(spinDEXRace,2,2);
    gridAbility->addWidget(spinCONRace,3,2);
    gridAbility->addWidget(spinINTRace,4,2);
    gridAbility->addWidget(spinWISRace,5,2);
    gridAbility->addWidget(spinCHARace,6,2);

    gridAbility->addWidget(spinSTRValue,1,3);
    gridAbility->addWidget(spinDEXValue,2,3);
    gridAbility->addWidget(spinCONValue,3,3);
    gridAbility->addWidget(spinINTValue,4,3);
    gridAbility->addWidget(spinWISValue,5,3);
    gridAbility->addWidget(spinCHAValue,6,3);

    gridAbility->addWidget(spinSTRBonus,1,4);
    gridAbility->addWidget(spinDEXBonus,2,4);
    gridAbility->addWidget(spinCONBonus,3,4);
    gridAbility->addWidget(spinINTBonus,4,4);
    gridAbility->addWidget(spinWISBonus,5,4);
    gridAbility->addWidget(spinCHABonus,6,4);

    // Number of feats and name
    QLabel *labelFeat = new QLabel;
    labelFeat->setText("Feats");

    QSpinBox *spinFeat = new QSpinBox;
    spinFeat->setValue(0);
    spinFeat->setReadOnly(true);
    spinFeat->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QLineEdit *textFeat = new QLineEdit;
    QLineEdit *textFeat2 = new QLineEdit;
    QLineEdit *textFeat3 = new QLineEdit;

    QGridLayout *layoutFeat = new QGridLayout;
    layoutFeat->addWidget(labelFeat,1,0);
    layoutFeat->addWidget(spinFeat,1,1);
    layoutFeat->addWidget(textFeat,0,2);
    layoutFeat->addWidget(textFeat2,1,2);
    layoutFeat->addWidget(textFeat3,2,2);

    // Hit Dice
    QLabel *labelHit = new QLabel;
    labelHit->setText("Hit Dice");

    QSpinBox *spinHit = new QSpinBox;
    spinHit->setValue(0);

    QGridLayout *layoutHit = new QGridLayout;
    layoutHit->addWidget(labelHit,0,0);
    layoutHit->addWidget(spinHit,0,1);

    // Starting Gold
    QLabel *labelGold = new QLabel;
    labelGold->setText("Starting gold");

    QSpinBox *spinGold = new QSpinBox;
    spinGold->setValue(0);

    QGridLayout *layoutGold = new QGridLayout;
    layoutGold->addWidget(labelGold,0,0);
    layoutGold->addWidget(spinGold,0,1);


    // Layout for left part of page
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(charName);
    leftLayout->addWidget(coreRaces);
    leftLayout->addWidget(coreClasses);
    leftLayout->addLayout(alignmentLayout);
    leftLayout->addLayout(gridAbility);
    leftLayout->addLayout(layoutFeat);
    leftLayout->addLayout(layoutHit);
    leftLayout->addLayout(layoutGold);

    // ///////////////////// Skill section

    QLabel *labelSkill = new QLabel;
    labelSkill->setText("Skill");
    QLabel *labelSkillRank = new QLabel;
    labelSkillRank->setText("Rank");
    QLabel *labelSkillClass = new QLabel;
    labelSkillClass->setText("Class");
    QLabel *labelSkillAbility = new QLabel;
    labelSkillAbility->setText("Ability");
    QLabel *labelSkillOther = new QLabel;
    labelSkillOther->setText("Other");
    QLabel *labelSkillTotal = new QLabel;
    labelSkillTotal->setText("Total");

    gridSkill = new QGridLayout;

    createSkill("Acrobatics",1);
    createSkill("Appraise",2);
    createSkill("Bluff",3);
    createSkill("Climb",4);
    createSkill("Craft",5);
    createSkill("Diplomacy",6);
    createSkill("Disable Device",7);
    createSkill("Disguise",8);
    createSkill("Escape Artist",9);
    createSkill("Fly",10);
    createSkill("Handle Animal",11);
    createSkill("Heal",12);
    createSkill("Intimidate",13);
    createSkill("KnArcana",14);
    createSkill("KnDungeon",15);
    createSkill("KnEngineering",16);
    createSkill("KnGeography",17);
    createSkill("KnHistory",18);
    createSkill("KnLocal",19);
    createSkill("KnNature",20);
    createSkill("KnNobility",21);
    createSkill("KnPlanes",22);
    createSkill("KnReligion",23);
    createSkill("Linguistics",24);
    createSkill("Perception",25);
    createSkill("Perform",26);
    createSkill("Profession",27);
    createSkill("Ride",28);
    createSkill("Sense Motive",29);
    createSkill("Sleight of Hand",30);
    createSkill("Spellcraft",31);
    createSkill("Stealth",32);
    createSkill("Survival",33);
    createSkill("Swim",34);
    createSkill("Use Magic Device",35);

    gridSkill->addWidget(labelSkill,0,0);
    gridSkill->addWidget(labelSkillRank,0,1);
    gridSkill->addWidget(labelSkillClass,0,2);
    gridSkill->addWidget(labelSkillAbility,0,3);
    gridSkill->addWidget(labelSkillOther,0,4);
    gridSkill->addWidget(labelSkillTotal,0,5);

    // Layout for overall page
    QGridLayout *layout = new QGridLayout;
    layout->addLayout(leftLayout,0,0,11,1);
    layout->addLayout(gridSkill,0,1,19,2);

    centralZone->setLayout(layout);

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}
