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

void MainWindow::createAbilities()
{
    gridAbility = new QGridLayout;

    GridHeader *labelAbility = new GridHeader("Ability");
    GridHeader *labelAbilityRoll = new GridHeader("Roll");
    GridHeader *labelAbilityRace = new GridHeader("Race");
    GridHeader *labelAbilityValue = new GridHeader("Value");
    GridHeader *labelAbilityBonus = new GridHeader("Bonus");

    radioSTR = new QRadioButton("STR");
    connect(radioSTR,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));
    radioDEX = new QRadioButton("DEX");
    connect(radioDEX,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));
    radioCON = new QRadioButton("CON");
    connect(radioCON,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));
    radioINT = new QRadioButton("INT");
    connect(radioINT,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));
    radioWIS = new QRadioButton("WIS");
    connect(radioWIS,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));
    radioCHA = new QRadioButton("CHA");
    connect(radioCHA,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));

    spinRollSTR = new QSpinBox;
    spinRollSTR->setValue(14);
    spinRollSTR->setMinimum(4);
    spinRollSTR->setMaximum(24);
    connect(spinRollSTR,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollDEX = new QSpinBox;
    spinRollDEX->setValue(14);
    spinRollDEX->setMinimum(4);
    spinRollDEX->setMaximum(24);
    connect(spinRollDEX,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollCON = new QSpinBox;
    spinRollCON->setValue(14);
    spinRollCON->setMinimum(4);
    spinRollCON->setMaximum(24);
    connect(spinRollCON,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollINT = new QSpinBox;
    spinRollINT->setValue(14);
    spinRollINT->setMinimum(4);
    spinRollINT->setMaximum(24);
    connect(spinRollINT,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollWIS = new QSpinBox;
    spinRollWIS->setValue(14);
    spinRollWIS->setMinimum(4);
    spinRollWIS->setMaximum(24);
    connect(spinRollWIS,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollCHA = new QSpinBox;
    spinRollCHA->setValue(14);
    spinRollCHA->setMinimum(4);
    spinRollCHA->setMaximum(24);
    connect(spinRollCHA,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRaceSTR = new AbilitySpinBox;
    spinRaceDEX = new AbilitySpinBox;
    spinRaceCON = new AbilitySpinBox;
    spinRaceINT = new AbilitySpinBox;
    spinRaceWIS = new AbilitySpinBox;
    spinRaceCHA = new AbilitySpinBox;

    spinValueSTR = new AbilitySpinBox;
    spinValueDEX = new AbilitySpinBox;
    spinValueCON = new AbilitySpinBox;
    spinValueINT = new AbilitySpinBox;
    spinValueWIS = new AbilitySpinBox;
    spinValueCHA = new AbilitySpinBox;

    spinBonusSTR = new AbilitySpinBox;
    spinBonusDEX = new AbilitySpinBox;
    spinBonusCON = new AbilitySpinBox;
    spinBonusINT = new AbilitySpinBox;
    spinBonusWIS = new AbilitySpinBox;
    spinBonusCHA = new AbilitySpinBox;

    updateAbilities();

    int row(0);
    int col(0);
    gridAbility->addWidget(labelAbility,row,col++);
    gridAbility->addWidget(labelAbilityRoll,row,col++);
    gridAbility->addWidget(labelAbilityRace,row,col++);
    gridAbility->addWidget(labelAbilityValue,row,col++);
    gridAbility->addWidget(labelAbilityBonus,row,col);
    row = 1;
    col = 0;
    gridAbility->addWidget(radioSTR,row++,col);
    gridAbility->addWidget(radioDEX,row++,col);
    gridAbility->addWidget(radioCON,row++,col);
    gridAbility->addWidget(radioINT,row++,col);
    gridAbility->addWidget(radioWIS,row++,col);
    gridAbility->addWidget(radioCHA,row++,col);
    row = 1;
    col = 1;
    gridAbility->addWidget(spinRollSTR,row++,col);
    gridAbility->addWidget(spinRollDEX,row++,col);
    gridAbility->addWidget(spinRollCON,row++,col);
    gridAbility->addWidget(spinRollINT,row++,col);
    gridAbility->addWidget(spinRollWIS,row++,col);
    gridAbility->addWidget(spinRollCHA,row++,col);
    row = 1;
    col = 2;
    gridAbility->addWidget(spinRaceSTR,row++,col);
    gridAbility->addWidget(spinRaceDEX,row++,col);
    gridAbility->addWidget(spinRaceCON,row++,col);
    gridAbility->addWidget(spinRaceINT,row++,col);
    gridAbility->addWidget(spinRaceWIS,row++,col);
    gridAbility->addWidget(spinRaceCHA,row++,col);
    row = 1;
    col = 3;
    gridAbility->addWidget(spinValueSTR,row++,col);
    gridAbility->addWidget(spinValueDEX,row++,col);
    gridAbility->addWidget(spinValueCON,row++,col);
    gridAbility->addWidget(spinValueINT,row++,col);
    gridAbility->addWidget(spinValueWIS,row++,col);
    gridAbility->addWidget(spinValueCHA,row++,col);
    row = 1;
    col = 4;
    gridAbility->addWidget(spinBonusSTR,row++,col);
    gridAbility->addWidget(spinBonusDEX,row++,col);
    gridAbility->addWidget(spinBonusCON,row++,col);
    gridAbility->addWidget(spinBonusINT,row++,col);
    gridAbility->addWidget(spinBonusWIS,row++,col);
    gridAbility->addWidget(spinBonusCHA,row++,col);
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
    coreRaces->addItem("Choose a Race");
    coreRaces->addItem("Dwarf");
    coreRaces->addItem("Elf");
    coreRaces->addItem("Gnome");
    coreRaces->addItem("Half Elf");
    coreRaces->addItem("Halfling");
    coreRaces->addItem("Half Orc");
    coreRaces->addItem("Human");

    connect(coreRaces,SIGNAL(activated(int)),this,SLOT(updateAbilities()));

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

    createAbilities();

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

void MainWindow::updateAbilities()
{
    int abilityIndex = coreRaces->currentIndex();
    switch (abilityIndex) {
    case 1:
        spinRaceSTR->setValue(0);
        spinRaceDEX->setValue(0);
        spinRaceCON->setValue(2);
        spinRaceINT->setValue(0);
        spinRaceWIS->setValue(2);
        spinRaceCHA->setValue(-2);
        break;
    case 2:
        spinRaceSTR->setValue(0);
        spinRaceDEX->setValue(2);
        spinRaceCON->setValue(-2);
        spinRaceINT->setValue(2);
        spinRaceWIS->setValue(0);
        spinRaceCHA->setValue(0);
        break;
    case 3:
        spinRaceSTR->setValue(-2);
        spinRaceDEX->setValue(0);
        spinRaceCON->setValue(2);
        spinRaceINT->setValue(0);
        spinRaceWIS->setValue(0);
        spinRaceCHA->setValue(2);
        break;
    case 4:
        spinRaceSTR->setValue(0);
        spinRaceDEX->setValue(0);
        spinRaceCON->setValue(0);
        spinRaceINT->setValue(0);
        spinRaceWIS->setValue(0);
        spinRaceCHA->setValue(0);

        if (radioSTR->isChecked())
        {
            spinRaceSTR->setValue(2);
        }
        else if (radioDEX->isChecked())
        {
            spinRaceDEX->setValue(2);
        }
        else if (radioCON->isChecked())
        {
            spinRaceCON->setValue(2);
        }
        else if (radioINT->isChecked())
        {
            spinRaceINT->setValue(2);
        }
        else if (radioWIS->isChecked())
        {
            spinRaceWIS->setValue(2);
        }
        else if (radioCHA->isChecked())
        {
            spinRaceCHA->setValue(2);
        }
        break;
    case 5:
        spinRaceSTR->setValue(-2);
        spinRaceDEX->setValue(2);
        spinRaceCON->setValue(0);
        spinRaceINT->setValue(0);
        spinRaceWIS->setValue(0);
        spinRaceCHA->setValue(2);
        break;
    case 6:
        spinRaceSTR->setValue(0);
        spinRaceDEX->setValue(0);
        spinRaceCON->setValue(0);
        spinRaceINT->setValue(0);
        spinRaceWIS->setValue(0);
        spinRaceCHA->setValue(0);

        if (radioSTR->isChecked())
        {
            spinRaceSTR->setValue(2);
        }
        else if (radioDEX->isChecked())
        {
            spinRaceDEX->setValue(2);
        }
        else if (radioCON->isChecked())
        {
            spinRaceCON->setValue(2);
        }
        else if (radioINT->isChecked())
        {
            spinRaceINT->setValue(2);
        }
        else if (radioWIS->isChecked())
        {
            spinRaceWIS->setValue(2);
        }
        else if (radioCHA->isChecked())
        {
            spinRaceCHA->setValue(2);
        }
        break;
    case 7:
        spinRaceSTR->setValue(0);
        spinRaceDEX->setValue(0);
        spinRaceCON->setValue(0);
        spinRaceINT->setValue(0);
        spinRaceWIS->setValue(0);
        spinRaceCHA->setValue(0);

        if (radioSTR->isChecked())
        {
            spinRaceSTR->setValue(2);
        }
        else if (radioDEX->isChecked())
        {
            spinRaceDEX->setValue(2);
        }
        else if (radioCON->isChecked())
        {
            spinRaceCON->setValue(2);
        }
        else if (radioINT->isChecked())
        {
            spinRaceINT->setValue(2);
        }
        else if (radioWIS->isChecked())
        {
            spinRaceWIS->setValue(2);
        }
        else if (radioCHA->isChecked())
        {
            spinRaceCHA->setValue(2);
        }
        break;
    case 0:
        spinRaceSTR->setValue(0);
        spinRaceDEX->setValue(0);
        spinRaceCON->setValue(0);
        spinRaceINT->setValue(0);
        spinRaceWIS->setValue(0);
        spinRaceCHA->setValue(0);
        break;
    default:
        break;
    }
    spinValueSTR->setValue(spinRollSTR->value()+spinRaceSTR->value());
    spinValueDEX->setValue(spinRollDEX->value()+spinRaceDEX->value());
    spinValueCON->setValue(spinRollCON->value()+spinRaceCON->value());
    spinValueINT->setValue(spinRollINT->value()+spinRaceINT->value());
    spinValueWIS->setValue(spinRollWIS->value()+spinRaceWIS->value());
    spinValueCHA->setValue(spinRollCHA->value()+spinRaceCHA->value());

    spinBonusSTR->setValue((spinValueSTR->value()/2) - 5 + (spinValueSTR->value()%2));
    spinBonusDEX->setValue((spinValueDEX->value()/2) - 5 + (spinValueDEX->value()%2));
    spinBonusCON->setValue((spinValueCON->value()/2) - 5 + (spinValueCON->value()%2));
    spinBonusINT->setValue((spinValueINT->value()/2) - 5 + (spinValueINT->value()%2));
    spinBonusWIS->setValue((spinValueWIS->value()/2) - 5 + (spinValueWIS->value()%2));
    spinBonusCHA->setValue((spinValueCHA->value()/2) - 5 + (spinValueCHA->value()%2));
}
