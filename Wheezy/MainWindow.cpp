#include "MainWindow.hpp"

#include <QDebug>

MainWindow::MainWindow()
{
    // Attributes of main window
    setWindowTitle("Welcome to Wheezy !");

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

    // Layout for left part of page
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(charName);
    leftLayout->addWidget(coreRaces);
    leftLayout->addWidget(coreClasses);
    leftLayout->addLayout(alignmentLayout);
    leftLayout->addLayout(gridAbility);

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

    // Acrobatics
    QLabel *labelAcrobatics = new QLabel;
    labelAcrobatics->setText("Acrobatics");

    QSpinBox *spinAcrobaticsRank = new QSpinBox;
    spinAcrobaticsRank->setValue(0);
    spinAcrobaticsRank->setMinimum(0);
    spinAcrobaticsRank->setMaximum(1); // Level is maximum

    QSpinBox *spinAcrobaticsClass = new QSpinBox;
    spinAcrobaticsClass->setValue(0);
    spinAcrobaticsClass->setReadOnly(true);
    spinAcrobaticsClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinAcrobaticsAbility = new QSpinBox;
    spinAcrobaticsAbility->setValue(0);
    spinAcrobaticsAbility->setReadOnly(true);
    spinAcrobaticsAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinAcrobaticsOther = new QSpinBox;
    spinAcrobaticsOther->setValue(0);
    spinAcrobaticsOther->setReadOnly(true);
    spinAcrobaticsOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinAcrobaticsTotal = new QSpinBox;
    spinAcrobaticsTotal->setValue(0);
    spinAcrobaticsTotal->setReadOnly(true);
    spinAcrobaticsTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Appraise
    QLabel *labelAppraise = new QLabel;
    labelAppraise->setText("Appraise");

    QSpinBox *spinAppraiseRank = new QSpinBox;
    spinAppraiseRank->setValue(0);
    spinAppraiseRank->setMinimum(0);
    spinAppraiseRank->setMaximum(1); // Level is maximum

    QSpinBox *spinAppraiseClass = new QSpinBox;
    spinAppraiseClass->setValue(0);
    spinAppraiseClass->setReadOnly(true);
    spinAppraiseClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinAppraiseAbility = new QSpinBox;
    spinAppraiseAbility->setValue(0);
    spinAppraiseAbility->setReadOnly(true);
    spinAppraiseAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinAppraiseOther = new QSpinBox;
    spinAppraiseOther->setValue(0);
    spinAppraiseOther->setReadOnly(true);
    spinAppraiseOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinAppraiseTotal = new QSpinBox;
    spinAppraiseTotal->setValue(0);
    spinAppraiseTotal->setReadOnly(true);
    spinAppraiseTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Bluff
    QLabel *labelBluff = new QLabel;
    labelBluff->setText("Bluff");

    QSpinBox *spinBluffRank = new QSpinBox;
    spinBluffRank->setValue(0);
    spinBluffRank->setMinimum(0);
    spinBluffRank->setMaximum(1); // Level is maximum

    QSpinBox *spinBluffClass = new QSpinBox;
    spinBluffClass->setValue(0);
    spinBluffClass->setReadOnly(true);
    spinBluffClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinBluffAbility = new QSpinBox;
    spinBluffAbility->setValue(0);
    spinBluffAbility->setReadOnly(true);
    spinBluffAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinBluffOther = new QSpinBox;
    spinBluffOther->setValue(0);
    spinBluffOther->setReadOnly(true);
    spinBluffOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinBluffTotal = new QSpinBox;
    spinBluffTotal->setValue(0);
    spinBluffTotal->setReadOnly(true);
    spinBluffTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Climb
    QLabel *labelClimb = new QLabel;
    labelClimb->setText("Climb");

    QSpinBox *spinClimbRank = new QSpinBox;
    spinClimbRank->setValue(0);
    spinClimbRank->setMinimum(0);
    spinClimbRank->setMaximum(1); // Level is maximum

    QSpinBox *spinClimbClass = new QSpinBox;
    spinClimbClass->setValue(0);
    spinClimbClass->setReadOnly(true);
    spinClimbClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinClimbAbility = new QSpinBox;
    spinClimbAbility->setValue(0);
    spinClimbAbility->setReadOnly(true);
    spinClimbAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinClimbOther = new QSpinBox;
    spinClimbOther->setValue(0);
    spinClimbOther->setReadOnly(true);
    spinClimbOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinClimbTotal = new QSpinBox;
    spinClimbTotal->setValue(0);
    spinClimbTotal->setReadOnly(true);
    spinClimbTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Craft 1
    QLabel *labelCraft1 = new QLabel;
    labelCraft1->setText("Craft1");

    QSpinBox *spinCraft1Rank = new QSpinBox;
    spinCraft1Rank->setValue(0);
    spinCraft1Rank->setMinimum(0);
    spinCraft1Rank->setMaximum(1); // Level is maximum

    QSpinBox *spinCraft1Class = new QSpinBox;
    spinCraft1Class->setValue(0);
    spinCraft1Class->setReadOnly(true);
    spinCraft1Class->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinCraft1Ability = new QSpinBox;
    spinCraft1Ability->setValue(0);
    spinCraft1Ability->setReadOnly(true);
    spinCraft1Ability->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinCraft1Other = new QSpinBox;
    spinCraft1Other->setValue(0);
    spinCraft1Other->setReadOnly(true);
    spinCraft1Other->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinCraft1Total = new QSpinBox;
    spinCraft1Total->setValue(0);
    spinCraft1Total->setReadOnly(true);
    spinCraft1Total->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Craft 2
    QLabel *labelCraft2 = new QLabel;
    labelCraft2->setText("Craft2");

    QSpinBox *spinCraft2Rank = new QSpinBox;
    spinCraft2Rank->setValue(0);
    spinCraft2Rank->setMinimum(0);
    spinCraft2Rank->setMaximum(1); // Level is maximum

    QSpinBox *spinCraft2Class = new QSpinBox;
    spinCraft2Class->setValue(0);
    spinCraft2Class->setReadOnly(true);
    spinCraft2Class->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinCraft2Ability = new QSpinBox;
    spinCraft2Ability->setValue(0);
    spinCraft2Ability->setReadOnly(true);
    spinCraft2Ability->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinCraft2Other = new QSpinBox;
    spinCraft2Other->setValue(0);
    spinCraft2Other->setReadOnly(true);
    spinCraft2Other->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinCraft2Total = new QSpinBox;
    spinCraft2Total->setValue(0);
    spinCraft2Total->setReadOnly(true);
    spinCraft2Total->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Diplomacy
    QLabel *labelDiplomacy = new QLabel;
    labelDiplomacy->setText("Diplomacy");

    QSpinBox *spinDiplomacyRank = new QSpinBox;
    spinDiplomacyRank->setValue(0);
    spinDiplomacyRank->setMinimum(0);
    spinDiplomacyRank->setMaximum(1); // Level is maximum

    QSpinBox *spinDiplomacyClass = new QSpinBox;
    spinDiplomacyClass->setValue(0);
    spinDiplomacyClass->setReadOnly(true);
    spinDiplomacyClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDiplomacyAbility = new QSpinBox;
    spinDiplomacyAbility->setValue(0);
    spinDiplomacyAbility->setReadOnly(true);
    spinDiplomacyAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDiplomacyOther = new QSpinBox;
    spinDiplomacyOther->setValue(0);
    spinDiplomacyOther->setReadOnly(true);
    spinDiplomacyOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDiplomacyTotal = new QSpinBox;
    spinDiplomacyTotal->setValue(0);
    spinDiplomacyTotal->setReadOnly(true);
    spinDiplomacyTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Disable Device
    QLabel *labelDisableDevice = new QLabel;
    labelDisableDevice->setText("DisableDevice");

    QSpinBox *spinDisableDeviceRank = new QSpinBox;
    spinDisableDeviceRank->setValue(0);
    spinDisableDeviceRank->setMinimum(0);
    spinDisableDeviceRank->setMaximum(1); // Level is maximum

    QSpinBox *spinDisableDeviceClass = new QSpinBox;
    spinDisableDeviceClass->setValue(0);
    spinDisableDeviceClass->setReadOnly(true);
    spinDisableDeviceClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDisableDeviceAbility = new QSpinBox;
    spinDisableDeviceAbility->setValue(0);
    spinDisableDeviceAbility->setReadOnly(true);
    spinDisableDeviceAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDisableDeviceOther = new QSpinBox;
    spinDisableDeviceOther->setValue(0);
    spinDisableDeviceOther->setReadOnly(true);
    spinDisableDeviceOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDisableDeviceTotal = new QSpinBox;
    spinDisableDeviceTotal->setValue(0);
    spinDisableDeviceTotal->setReadOnly(true);
    spinDisableDeviceTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Disguise
    QLabel *labelDisguise = new QLabel;
    labelDisguise->setText("Disguise");

    QSpinBox *spinDisguiseRank = new QSpinBox;
    spinDisguiseRank->setValue(0);
    spinDisguiseRank->setMinimum(0);
    spinDisguiseRank->setMaximum(1); // Level is maximum

    QSpinBox *spinDisguiseClass = new QSpinBox;
    spinDisguiseClass->setValue(0);
    spinDisguiseClass->setReadOnly(true);
    spinDisguiseClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDisguiseAbility = new QSpinBox;
    spinDisguiseAbility->setValue(0);
    spinDisguiseAbility->setReadOnly(true);
    spinDisguiseAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDisguiseOther = new QSpinBox;
    spinDisguiseOther->setValue(0);
    spinDisguiseOther->setReadOnly(true);
    spinDisguiseOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinDisguiseTotal = new QSpinBox;
    spinDisguiseTotal->setValue(0);
    spinDisguiseTotal->setReadOnly(true);
    spinDisguiseTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Escape Artist
    QLabel *labelEscapeArtist = new QLabel;
    labelEscapeArtist->setText("EscapeArtist");

    QSpinBox *spinEscapeArtistRank = new QSpinBox;
    spinEscapeArtistRank->setValue(0);
    spinEscapeArtistRank->setMinimum(0);
    spinEscapeArtistRank->setMaximum(1); // Level is maximum

    QSpinBox *spinEscapeArtistClass = new QSpinBox;
    spinEscapeArtistClass->setValue(0);
    spinEscapeArtistClass->setReadOnly(true);
    spinEscapeArtistClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinEscapeArtistAbility = new QSpinBox;
    spinEscapeArtistAbility->setValue(0);
    spinEscapeArtistAbility->setReadOnly(true);
    spinEscapeArtistAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinEscapeArtistOther = new QSpinBox;
    spinEscapeArtistOther->setValue(0);
    spinEscapeArtistOther->setReadOnly(true);
    spinEscapeArtistOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinEscapeArtistTotal = new QSpinBox;
    spinEscapeArtistTotal->setValue(0);
    spinEscapeArtistTotal->setReadOnly(true);
    spinEscapeArtistTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Fly
    QLabel *labelFly = new QLabel;
    labelFly->setText("Fly");

    QSpinBox *spinFlyRank = new QSpinBox;
    spinFlyRank->setValue(0);
    spinFlyRank->setMinimum(0);
    spinFlyRank->setMaximum(1); // Level is maximum

    QSpinBox *spinFlyClass = new QSpinBox;
    spinFlyClass->setValue(0);
    spinFlyClass->setReadOnly(true);
    spinFlyClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinFlyAbility = new QSpinBox;
    spinFlyAbility->setValue(0);
    spinFlyAbility->setReadOnly(true);
    spinFlyAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinFlyOther = new QSpinBox;
    spinFlyOther->setValue(0);
    spinFlyOther->setReadOnly(true);
    spinFlyOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinFlyTotal = new QSpinBox;
    spinFlyTotal->setValue(0);
    spinFlyTotal->setReadOnly(true);
    spinFlyTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Handle Animal
    QLabel *labelHandleAnimal = new QLabel;
    labelHandleAnimal->setText("HandleAnimal");

    QSpinBox *spinHandleAnimalRank = new QSpinBox;
    spinHandleAnimalRank->setValue(0);
    spinHandleAnimalRank->setMinimum(0);
    spinHandleAnimalRank->setMaximum(1); // Level is maximum

    QSpinBox *spinHandleAnimalClass = new QSpinBox;
    spinHandleAnimalClass->setValue(0);
    spinHandleAnimalClass->setReadOnly(true);
    spinHandleAnimalClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinHandleAnimalAbility = new QSpinBox;
    spinHandleAnimalAbility->setValue(0);
    spinHandleAnimalAbility->setReadOnly(true);
    spinHandleAnimalAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinHandleAnimalOther = new QSpinBox;
    spinHandleAnimalOther->setValue(0);
    spinHandleAnimalOther->setReadOnly(true);
    spinHandleAnimalOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinHandleAnimalTotal = new QSpinBox;
    spinHandleAnimalTotal->setValue(0);
    spinHandleAnimalTotal->setReadOnly(true);
    spinHandleAnimalTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Heal
    QLabel *labelHeal = new QLabel;
    labelHeal->setText("Heal");

    QSpinBox *spinHealRank = new QSpinBox;
    spinHealRank->setValue(0);
    spinHealRank->setMinimum(0);
    spinHealRank->setMaximum(1); // Level is maximum

    QSpinBox *spinHealClass = new QSpinBox;
    spinHealClass->setValue(0);
    spinHealClass->setReadOnly(true);
    spinHealClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinHealAbility = new QSpinBox;
    spinHealAbility->setValue(0);
    spinHealAbility->setReadOnly(true);
    spinHealAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinHealOther = new QSpinBox;
    spinHealOther->setValue(0);
    spinHealOther->setReadOnly(true);
    spinHealOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinHealTotal = new QSpinBox;
    spinHealTotal->setValue(0);
    spinHealTotal->setReadOnly(true);
    spinHealTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Intimidate
    QLabel *labelIntimidate = new QLabel;
    labelIntimidate->setText("Intimidate");

    QSpinBox *spinIntimidateRank = new QSpinBox;
    spinIntimidateRank->setValue(0);
    spinIntimidateRank->setMinimum(0);
    spinIntimidateRank->setMaximum(1); // Level is maximum

    QSpinBox *spinIntimidateClass = new QSpinBox;
    spinIntimidateClass->setValue(0);
    spinIntimidateClass->setReadOnly(true);
    spinIntimidateClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinIntimidateAbility = new QSpinBox;
    spinIntimidateAbility->setValue(0);
    spinIntimidateAbility->setReadOnly(true);
    spinIntimidateAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinIntimidateOther = new QSpinBox;
    spinIntimidateOther->setValue(0);
    spinIntimidateOther->setReadOnly(true);
    spinIntimidateOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinIntimidateTotal = new QSpinBox;
    spinIntimidateTotal->setValue(0);
    spinIntimidateTotal->setReadOnly(true);
    spinIntimidateTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // KnArcana
    QLabel *labelKnArcana = new QLabel;
    labelKnArcana->setText("KnArcana");

    QSpinBox *spinKnArcanaRank = new QSpinBox;
    spinKnArcanaRank->setValue(0);
    spinKnArcanaRank->setMinimum(0);
    spinKnArcanaRank->setMaximum(1); // Level is maximum

    QSpinBox *spinKnArcanaClass = new QSpinBox;
    spinKnArcanaClass->setValue(0);
    spinKnArcanaClass->setReadOnly(true);
    spinKnArcanaClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnArcanaAbility = new QSpinBox;
    spinKnArcanaAbility->setValue(0);
    spinKnArcanaAbility->setReadOnly(true);
    spinKnArcanaAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnArcanaOther = new QSpinBox;
    spinKnArcanaOther->setValue(0);
    spinKnArcanaOther->setReadOnly(true);
    spinKnArcanaOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnArcanaTotal = new QSpinBox;
    spinKnArcanaTotal->setValue(0);
    spinKnArcanaTotal->setReadOnly(true);
    spinKnArcanaTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // KnDungeoneering
    QLabel *labelKnDungeoneering = new QLabel;
    labelKnDungeoneering->setText("KnDungeoneering");

    QSpinBox *spinKnDungeoneeringRank = new QSpinBox;
    spinKnDungeoneeringRank->setValue(0);
    spinKnDungeoneeringRank->setMinimum(0);
    spinKnDungeoneeringRank->setMaximum(1); // Level is maximum

    QSpinBox *spinKnDungeoneeringClass = new QSpinBox;
    spinKnDungeoneeringClass->setValue(0);
    spinKnDungeoneeringClass->setReadOnly(true);
    spinKnDungeoneeringClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnDungeoneeringAbility = new QSpinBox;
    spinKnDungeoneeringAbility->setValue(0);
    spinKnDungeoneeringAbility->setReadOnly(true);
    spinKnDungeoneeringAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnDungeoneeringOther = new QSpinBox;
    spinKnDungeoneeringOther->setValue(0);
    spinKnDungeoneeringOther->setReadOnly(true);
    spinKnDungeoneeringOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnDungeoneeringTotal = new QSpinBox;
    spinKnDungeoneeringTotal->setValue(0);
    spinKnDungeoneeringTotal->setReadOnly(true);
    spinKnDungeoneeringTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // KnEngineering
    QLabel *labelKnEngineering = new QLabel;
    labelKnEngineering->setText("KnEngineering");

    QSpinBox *spinKnEngineeringRank = new QSpinBox;
    spinKnEngineeringRank->setValue(0);
    spinKnEngineeringRank->setMinimum(0);
    spinKnEngineeringRank->setMaximum(1); // Level is maximum

    QSpinBox *spinKnEngineeringClass = new QSpinBox;
    spinKnEngineeringClass->setValue(0);
    spinKnEngineeringClass->setReadOnly(true);
    spinKnEngineeringClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnEngineeringAbility = new QSpinBox;
    spinKnEngineeringAbility->setValue(0);
    spinKnEngineeringAbility->setReadOnly(true);
    spinKnEngineeringAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnEngineeringOther = new QSpinBox;
    spinKnEngineeringOther->setValue(0);
    spinKnEngineeringOther->setReadOnly(true);
    spinKnEngineeringOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnEngineeringTotal = new QSpinBox;
    spinKnEngineeringTotal->setValue(0);
    spinKnEngineeringTotal->setReadOnly(true);
    spinKnEngineeringTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // KnGeography
    QLabel *labelKnGeography = new QLabel;
    labelKnGeography->setText("KnGeography");

    QSpinBox *spinKnGeographyRank = new QSpinBox;
    spinKnGeographyRank->setValue(0);
    spinKnGeographyRank->setMinimum(0);
    spinKnGeographyRank->setMaximum(1); // Level is maximum

    QSpinBox *spinKnGeographyClass = new QSpinBox;
    spinKnGeographyClass->setValue(0);
    spinKnGeographyClass->setReadOnly(true);
    spinKnGeographyClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnGeographyAbility = new QSpinBox;
    spinKnGeographyAbility->setValue(0);
    spinKnGeographyAbility->setReadOnly(true);
    spinKnGeographyAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnGeographyOther = new QSpinBox;
    spinKnGeographyOther->setValue(0);
    spinKnGeographyOther->setReadOnly(true);
    spinKnGeographyOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnGeographyTotal = new QSpinBox;
    spinKnGeographyTotal->setValue(0);
    spinKnGeographyTotal->setReadOnly(true);
    spinKnGeographyTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // KnHistory
    QLabel *labelKnHistory = new QLabel;
    labelKnHistory->setText("KnHistory");

    QSpinBox *spinKnHistoryRank = new QSpinBox;
    spinKnHistoryRank->setValue(0);
    spinKnHistoryRank->setMinimum(0);
    spinKnHistoryRank->setMaximum(1); // Level is maximum

    QSpinBox *spinKnHistoryClass = new QSpinBox;
    spinKnHistoryClass->setValue(0);
    spinKnHistoryClass->setReadOnly(true);
    spinKnHistoryClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnHistoryAbility = new QSpinBox;
    spinKnHistoryAbility->setValue(0);
    spinKnHistoryAbility->setReadOnly(true);
    spinKnHistoryAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnHistoryOther = new QSpinBox;
    spinKnHistoryOther->setValue(0);
    spinKnHistoryOther->setReadOnly(true);
    spinKnHistoryOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnHistoryTotal = new QSpinBox;
    spinKnHistoryTotal->setValue(0);
    spinKnHistoryTotal->setReadOnly(true);
    spinKnHistoryTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // KnLocal
    QLabel *labelKnLocal = new QLabel;
    labelKnLocal->setText("KnLocal");

    QSpinBox *spinKnLocalRank = new QSpinBox;
    spinKnLocalRank->setValue(0);
    spinKnLocalRank->setMinimum(0);
    spinKnLocalRank->setMaximum(1); // Level is maximum

    QSpinBox *spinKnLocalClass = new QSpinBox;
    spinKnLocalClass->setValue(0);
    spinKnLocalClass->setReadOnly(true);
    spinKnLocalClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnLocalAbility = new QSpinBox;
    spinKnLocalAbility->setValue(0);
    spinKnLocalAbility->setReadOnly(true);
    spinKnLocalAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnLocalOther = new QSpinBox;
    spinKnLocalOther->setValue(0);
    spinKnLocalOther->setReadOnly(true);
    spinKnLocalOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnLocalTotal = new QSpinBox;
    spinKnLocalTotal->setValue(0);
    spinKnLocalTotal->setReadOnly(true);
    spinKnLocalTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // KnNature
    QLabel *labelKnNature = new QLabel;
    labelKnNature->setText("KnNature");

    QSpinBox *spinKnNatureRank = new QSpinBox;
    spinKnNatureRank->setValue(0);
    spinKnNatureRank->setMinimum(0);
    spinKnNatureRank->setMaximum(1); // Level is maximum

    QSpinBox *spinKnNatureClass = new QSpinBox;
    spinKnNatureClass->setValue(0);
    spinKnNatureClass->setReadOnly(true);
    spinKnNatureClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnNatureAbility = new QSpinBox;
    spinKnNatureAbility->setValue(0);
    spinKnNatureAbility->setReadOnly(true);
    spinKnNatureAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnNatureOther = new QSpinBox;
    spinKnNatureOther->setValue(0);
    spinKnNatureOther->setReadOnly(true);
    spinKnNatureOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnNatureTotal = new QSpinBox;
    spinKnNatureTotal->setValue(0);
    spinKnNatureTotal->setReadOnly(true);
    spinKnNatureTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // KnNobility
    QLabel *labelKnNobility = new QLabel;
    labelKnNobility->setText("KnNobility");

    QSpinBox *spinKnNobilityRank = new QSpinBox;
    spinKnNobilityRank->setValue(0);
    spinKnNobilityRank->setMinimum(0);
    spinKnNobilityRank->setMaximum(1); // Level is maximum

    QSpinBox *spinKnNobilityClass = new QSpinBox;
    spinKnNobilityClass->setValue(0);
    spinKnNobilityClass->setReadOnly(true);
    spinKnNobilityClass->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnNobilityAbility = new QSpinBox;
    spinKnNobilityAbility->setValue(0);
    spinKnNobilityAbility->setReadOnly(true);
    spinKnNobilityAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnNobilityOther = new QSpinBox;
    spinKnNobilityOther->setValue(0);
    spinKnNobilityOther->setReadOnly(true);
    spinKnNobilityOther->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QSpinBox *spinKnNobilityTotal = new QSpinBox;
    spinKnNobilityTotal->setValue(0);
    spinKnNobilityTotal->setReadOnly(true);
    spinKnNobilityTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QGridLayout *gridSkill = new QGridLayout;
    gridSkill->addWidget(labelSkill,0,0);
    gridSkill->addWidget(labelSkillRank,0,1);
    gridSkill->addWidget(labelSkillClass,0,2);
    gridSkill->addWidget(labelSkillAbility,0,3);
    gridSkill->addWidget(labelSkillOther,0,4);
    gridSkill->addWidget(labelSkillTotal,0,5);
    gridSkill->addWidget(labelSkill,0,6);
    gridSkill->addWidget(labelSkillRank,0,7);
    gridSkill->addWidget(labelSkillClass,0,8);
    gridSkill->addWidget(labelSkillAbility,0,9);
    gridSkill->addWidget(labelSkillOther,0,10);
    gridSkill->addWidget(labelSkillTotal,0,11);

    gridSkill->addWidget(labelAcrobatics,2,0);
    gridSkill->addWidget(spinAcrobaticsRank,2,1);
    gridSkill->addWidget(spinAcrobaticsClass,2,2);
    gridSkill->addWidget(spinAcrobaticsAbility,2,3);
    gridSkill->addWidget(spinAcrobaticsOther,2,4);
    gridSkill->addWidget(spinAcrobaticsTotal,2,5);

    gridSkill->addWidget(labelAppraise,3,0);
    gridSkill->addWidget(spinAppraiseRank,3,1);
    gridSkill->addWidget(spinAppraiseClass,3,2);
    gridSkill->addWidget(spinAppraiseAbility,3,3);
    gridSkill->addWidget(spinAppraiseOther,3,4);
    gridSkill->addWidget(spinAppraiseTotal,3,5);

    gridSkill->addWidget(labelBluff,4,0);
    gridSkill->addWidget(spinBluffRank,4,1);
    gridSkill->addWidget(spinBluffClass,4,2);
    gridSkill->addWidget(spinBluffAbility,4,3);
    gridSkill->addWidget(spinBluffOther,4,4);
    gridSkill->addWidget(spinBluffTotal,4,5);

    gridSkill->addWidget(labelCraft1,5,0);
    gridSkill->addWidget(spinCraft1Rank,5,1);
    gridSkill->addWidget(spinCraft1Class,5,2);
    gridSkill->addWidget(spinCraft1Ability,5,3);
    gridSkill->addWidget(spinCraft1Other,5,4);
    gridSkill->addWidget(spinCraft1Total,5,5);

    gridSkill->addWidget(labelCraft2,6,0);
    gridSkill->addWidget(spinCraft2Rank,6,1);
    gridSkill->addWidget(spinCraft2Class,6,2);
    gridSkill->addWidget(spinCraft2Ability,6,3);
    gridSkill->addWidget(spinCraft2Other,6,4);
    gridSkill->addWidget(spinCraft2Total,6,5);

    gridSkill->addWidget(labelDiplomacy,7,0);
    gridSkill->addWidget(spinDiplomacyRank,7,1);
    gridSkill->addWidget(spinDiplomacyClass,7,2);
    gridSkill->addWidget(spinDiplomacyAbility,7,3);
    gridSkill->addWidget(spinDiplomacyOther,7,4);
    gridSkill->addWidget(spinDiplomacyTotal,7,5);

    gridSkill->addWidget(labelDisableDevice,8,0);
    gridSkill->addWidget(spinDisableDeviceRank,8,1);
    gridSkill->addWidget(spinDisableDeviceClass,8,2);
    gridSkill->addWidget(spinDisableDeviceAbility,8,3);
    gridSkill->addWidget(spinDisableDeviceOther,8,4);
    gridSkill->addWidget(spinDisableDeviceTotal,8,5);

    gridSkill->addWidget(labelDisguise,9,0);
    gridSkill->addWidget(spinDisguiseRank,9,1);
    gridSkill->addWidget(spinDisguiseClass,9,2);
    gridSkill->addWidget(spinDisguiseAbility,9,3);
    gridSkill->addWidget(spinDisguiseOther,9,4);
    gridSkill->addWidget(spinDisguiseTotal,9,5);

    gridSkill->addWidget(labelEscapeArtist,10,0);
    gridSkill->addWidget(spinEscapeArtistRank,10,1);
    gridSkill->addWidget(spinEscapeArtistClass,10,2);
    gridSkill->addWidget(spinEscapeArtistAbility,10,3);
    gridSkill->addWidget(spinEscapeArtistOther,10,4);
    gridSkill->addWidget(spinEscapeArtistTotal,10,5);

    gridSkill->addWidget(labelFly,11,0);
    gridSkill->addWidget(spinFlyRank,11,1);
    gridSkill->addWidget(spinFlyClass,11,2);
    gridSkill->addWidget(spinFlyAbility,11,3);
    gridSkill->addWidget(spinFlyOther,11,4);
    gridSkill->addWidget(spinFlyTotal,11,5);

    gridSkill->addWidget(labelHandleAnimal,12,0);
    gridSkill->addWidget(spinHandleAnimalRank,12,1);
    gridSkill->addWidget(spinHandleAnimalClass,12,2);
    gridSkill->addWidget(spinHandleAnimalAbility,12,3);
    gridSkill->addWidget(spinHandleAnimalOther,12,4);
    gridSkill->addWidget(spinHandleAnimalTotal,12,5);

    gridSkill->addWidget(labelHeal,13,0);
    gridSkill->addWidget(spinHealRank,13,1);
    gridSkill->addWidget(spinHealClass,13,2);
    gridSkill->addWidget(spinHealAbility,13,3);
    gridSkill->addWidget(spinHealOther,13,4);
    gridSkill->addWidget(spinHealTotal,13,5);

    gridSkill->addWidget(labelIntimidate,14,0);
    gridSkill->addWidget(spinIntimidateRank,14,1);
    gridSkill->addWidget(spinIntimidateClass,14,2);
    gridSkill->addWidget(spinIntimidateAbility,14,3);
    gridSkill->addWidget(spinIntimidateOther,14,4);
    gridSkill->addWidget(spinIntimidateTotal,14,5);

    gridSkill->addWidget(labelKnArcana,15,0);
    gridSkill->addWidget(spinKnArcanaRank,15,1);
    gridSkill->addWidget(spinKnArcanaClass,15,2);
    gridSkill->addWidget(spinKnArcanaAbility,15,3);
    gridSkill->addWidget(spinKnArcanaOther,15,4);
    gridSkill->addWidget(spinKnArcanaTotal,15,5);

    gridSkill->addWidget(labelKnDungeoneering,16,0);
    gridSkill->addWidget(spinKnDungeoneeringRank,16,1);
    gridSkill->addWidget(spinKnDungeoneeringClass,16,2);
    gridSkill->addWidget(spinKnDungeoneeringAbility,16,3);
    gridSkill->addWidget(spinKnDungeoneeringOther,16,4);
    gridSkill->addWidget(spinKnDungeoneeringTotal,16,5);

    gridSkill->addWidget(labelKnEngineering,17,0);
    gridSkill->addWidget(spinKnEngineeringRank,17,1);
    gridSkill->addWidget(spinKnEngineeringClass,17,2);
    gridSkill->addWidget(spinKnEngineeringAbility,17,3);
    gridSkill->addWidget(spinKnEngineeringOther,17,4);
    gridSkill->addWidget(spinKnEngineeringTotal,17,5);

    gridSkill->addWidget(labelKnGeography,18,0);
    gridSkill->addWidget(spinKnGeographyRank,18,1);
    gridSkill->addWidget(spinKnGeographyClass,18,2);
    gridSkill->addWidget(spinKnGeographyAbility,18,3);
    gridSkill->addWidget(spinKnGeographyOther,18,4);
    gridSkill->addWidget(spinKnGeographyTotal,18,5);

    gridSkill->addWidget(labelKnHistory,19,0);
    gridSkill->addWidget(spinKnHistoryRank,19,1);
    gridSkill->addWidget(spinKnHistoryClass,19,2);
    gridSkill->addWidget(spinKnHistoryAbility,19,3);
    gridSkill->addWidget(spinKnHistoryOther,19,4);
    gridSkill->addWidget(spinKnHistoryTotal,19,5);

    gridSkill->addWidget(labelKnLocal,20,0);
    gridSkill->addWidget(spinKnLocalRank,20,1);
    gridSkill->addWidget(spinKnLocalClass,20,2);
    gridSkill->addWidget(spinKnLocalAbility,20,3);
    gridSkill->addWidget(spinKnLocalOther,20,4);
    gridSkill->addWidget(spinKnLocalTotal,20,5);

    gridSkill->addWidget(labelKnNature,21,0);
    gridSkill->addWidget(spinKnNatureRank,21,1);
    gridSkill->addWidget(spinKnNatureClass,21,2);
    gridSkill->addWidget(spinKnNatureAbility,21,3);
    gridSkill->addWidget(spinKnNatureOther,21,4);
    gridSkill->addWidget(spinKnNatureTotal,21,5);

    gridSkill->addWidget(labelKnNobility,22,0);
    gridSkill->addWidget(spinKnNobilityRank,22,1);
    gridSkill->addWidget(spinKnNobilityClass,22,2);
    gridSkill->addWidget(spinKnNobilityAbility,22,3);
    gridSkill->addWidget(spinKnNobilityOther,22,4);
    gridSkill->addWidget(spinKnNobilityTotal,22,5);

    // Layout for overall page
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addLayout(gridSkill);

    centralZone->setLayout(layout);

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}
