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

void MainWindow::initiateAbilities()
{
    groupAbility = new QGroupBox("Abilities");
    groupAbility->setAlignment(Qt::AlignHCenter);
    gridAbility = new QGridLayout;

    GridHeader *labelAbility = new GridHeader("Ability");
    GridHeader *labelAbilityRoll = new GridHeader("Roll");
    GridHeader *labelAbilityRace = new GridHeader("Race");
    GridHeader *labelAbilityValue = new GridHeader("Value");
    GridHeader *labelAbilityBonus = new GridHeader("Bonus");

    radioSTR = new QRadioButton("STR");
    radioSTR->setFixedWidth(45);
    connect(radioSTR,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));

    radioDEX = new QRadioButton("DEX");
    radioDEX->setFixedWidth(45);
    connect(radioDEX,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));

    radioCON = new QRadioButton("CON");
    radioCON->setFixedWidth(45);
    connect(radioCON,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));

    radioINT = new QRadioButton("INT");
    radioINT->setFixedWidth(45);
    connect(radioINT,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));

    radioWIS = new QRadioButton("WIS");
    radioWIS->setFixedWidth(45);
    connect(radioWIS,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));

    radioCHA = new QRadioButton("CHA");
    radioCHA->setFixedWidth(45);
    connect(radioCHA,SIGNAL(toggled(bool)),this,SLOT(updateAbilities()));

    spinRollSTR = new QSpinBox;
    spinRollSTR->setValue(14);
    spinRollSTR->setMinimum(4);
    spinRollSTR->setMaximum(24);
    spinRollSTR->setAlignment(Qt::AlignHCenter);
    spinRollSTR->setFixedWidth(45);
    connect(spinRollSTR,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollDEX = new QSpinBox;
    spinRollDEX->setValue(14);
    spinRollDEX->setMinimum(4);
    spinRollDEX->setMaximum(24);
    spinRollDEX->setAlignment(Qt::AlignHCenter);
    spinRollDEX->setFixedWidth(45);
    connect(spinRollDEX,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollCON = new QSpinBox;
    spinRollCON->setValue(14);
    spinRollCON->setMinimum(4);
    spinRollCON->setMaximum(24);
    spinRollCON->setAlignment(Qt::AlignHCenter);
    spinRollCON->setFixedWidth(45);
    connect(spinRollCON,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollINT = new QSpinBox;
    spinRollINT->setValue(14);
    spinRollINT->setMinimum(4);
    spinRollINT->setMaximum(24);
    spinRollINT->setAlignment(Qt::AlignHCenter);
    spinRollINT->setFixedWidth(45);
    connect(spinRollINT,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollWIS = new QSpinBox;
    spinRollWIS->setValue(14);
    spinRollWIS->setMinimum(4);
    spinRollWIS->setMaximum(24);
    spinRollWIS->setAlignment(Qt::AlignHCenter);
    spinRollWIS->setFixedWidth(45);
    connect(spinRollWIS,SIGNAL(valueChanged(int)),this,SLOT(updateAbilities()));

    spinRollCHA = new QSpinBox;
    spinRollCHA->setValue(14);
    spinRollCHA->setMinimum(4);
    spinRollCHA->setMaximum(24);
    spinRollCHA->setAlignment(Qt::AlignHCenter);
    spinRollCHA->setFixedWidth(45);
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

    groupAbility->setLayout(gridAbility);
}

void MainWindow::updateAlignment()
{
    alignmentL->setEnabled(true);
    alignmentN1->setEnabled(true);
    alignmentC->setEnabled(true);
    alignmentG->setEnabled(true);
    alignmentN2->setEnabled(true);
    alignmentE->setEnabled(true);

    int classIndex = coreClasses->currentIndex();
    switch (classIndex) {
    case 1: //Barbarian
        // Any non-lawful
        alignmentL->setEnabled(false);
        break;
    case 2: // Bard
        break;
    case 3: // Cleric
        // Some Bullshit about one step from diety
        // TO DO - include deity in character. Too
        // Hard for now.
        break;
    case 4: // Druid
        // Any neutral
        if (alignmentN1->isChecked() && !alignmentN2->isChecked())
        {
            alignmentL->setEnabled(false);
            alignmentC->setEnabled(false);
        }
        else if (!alignmentN1->isChecked() && alignmentN2->isChecked())
        {
            alignmentG->setEnabled(false);
            alignmentE->setEnabled(false);
        }
        break;
    case 5: // Fighter
        break;
    case 6: // Monk
        // Any lawful
        alignmentN1->setEnabled(false);
        alignmentC->setEnabled(false);
        break;
    case 7: // Paladin
        // Lawful good
        alignmentN1->setEnabled(false);
        alignmentC->setEnabled(false);
        alignmentN2->setEnabled(false);
        alignmentE->setEnabled(false);
        alignmentL->setChecked(true);
        alignmentG->setChecked(true);
        break;
    case 8: // Ranger
        break;
    case 9: // Rogue
        break;
    case 10: // Sorcerer
        break;
    case 11: // Wizard
        break;
    case 0: // No class selection
        break;
    }
}



void MainWindow::initiateAlignment()
{
    // Initial Alignment
    layoutLNC = new QVBoxLayout;
    layoutLNC->addWidget(alignmentL);
    layoutLNC->addWidget(alignmentN1);
    layoutLNC->addWidget(alignmentC);

    layoutGNE = new QVBoxLayout;
    layoutGNE->addWidget(alignmentG);
    layoutGNE->addWidget(alignmentN2);
    layoutGNE->addWidget(alignmentE);

    groupAlignmentLNC->setLayout(layoutLNC);
    groupAlignmentGNE->setLayout(layoutGNE);

    layoutAlignment->addWidget(groupAlignmentLNC);
    layoutAlignment->addWidget(groupAlignmentGNE);

    alignmentN1->setChecked(true);
    alignmentN2->setChecked(true);
}

void MainWindow::initiateHitDie()
{
    groupHit = new QGroupBox("Hit Dice");
    groupHit->setFixedWidth(leftWidth);
    groupHit->setAlignment(Qt::AlignHCenter);

    labelHitDie = new QLabel("1d8");

    spinHit = new QSpinBox();
    spinHit->setValue(0);
    spinHit->setSuffix(" HP");
    spinHit->setAlignment(Qt::AlignHCenter);

    layoutHit = new QHBoxLayout;
    layoutHit->addWidget(labelHitDie);
    layoutHit->addWidget(spinHit);

    groupHit->setLayout(layoutHit);
}

void MainWindow::updateHitDie()
{
    int classIndex = coreClasses->currentIndex();
    switch (classIndex) {
    case 1: //Barbarian
        labelHitDie->setText("1d12");
        spinHit->setMaximum(12);
        break;
    case 2: // Bard
        labelHitDie->setText("1d8");
        spinHit->setMaximum(8);
        break;
    case 3: // Cleric
        labelHitDie->setText("1d8");
        spinHit->setMaximum(8);
        break;
    case 4: // Druid
        labelHitDie->setText("1d8");
        spinHit->setMaximum(8);
        break;
    case 5: // Fighter
        labelHitDie->setText("1d10");
        spinHit->setMaximum(10);
        break;
    case 6: // Monk
        labelHitDie->setText("1d8");
        spinHit->setMaximum(8);
        break;
    case 7: // Paladin
        labelHitDie->setText("1d10");
        spinHit->setMaximum(10);
        break;
    case 8: // Ranger
        labelHitDie->setText("1d10");
        spinHit->setMaximum(10);
        break;
    case 9: // Rogue
        labelHitDie->setText("1d8");
        spinHit->setMaximum(8);
        break;
    case 10: // Sorcerer
        labelHitDie->setText("1d6");
        spinHit->setMaximum(6);
        break;
    case 11: // Wizard
        labelHitDie->setText("1d6");
        spinHit->setMaximum(6);
        break;
    case 0: // No class selection
        labelHitDie->setText("1d8");
        spinHit->setMaximum(8);
        break;
    }
}

void MainWindow::initiateGold()
{
    groupGold = new QGroupBox("Starting Gold");
    groupHit->setFixedWidth(leftWidth);
    groupHit->setAlignment(Qt::AlignHCenter);

    labelGoldDie = new QLabel("3d6 x 10 gp");

    spinGold = new QSpinBox;
    spinGold->setMaximum(180);
    spinGold->setValue(105);
    spinGold->setSuffix(" gp");
    spinGold->setAlignment(Qt::AlignHCenter);

    layoutGold = new QHBoxLayout;
    layoutGold->addWidget(labelGoldDie);
    layoutGold->addWidget(spinGold);

    groupGold->setLayout(layoutGold);
}

void MainWindow::updateGold()
{
    int classIndex = coreClasses->currentIndex();
    switch (classIndex) {
    case 1: //Barbarian
        labelGoldDie->setText("3d6 x 10 gp");
        spinGold->setMaximum(180);
        spinGold->setValue(105);
        break;
    case 2: // Bard
        labelGoldDie->setText("3d6 x 10 gp");
        spinGold->setMaximum(180);
        spinGold->setValue(105);
        break;
    case 3: // Cleric
        labelGoldDie->setText("4d6 x 10 gp");
        spinGold->setMaximum(240);
        spinGold->setValue(180);
        break;
    case 4: // Druid
        labelGoldDie->setText("2d6 x 10 gp");
        spinGold->setMaximum(120);
        spinGold->setValue(70);
        break;
    case 5: // Fighter
        labelGoldDie->setText("5d6 x 10 gp");
        spinGold->setMaximum(300);
        spinGold->setValue(175);
        break;
    case 6: // Monk
        labelGoldDie->setText("1d6 x 10 gp");
        spinGold->setMaximum(60);
        spinGold->setValue(35);
        break;
    case 7: // Paladin
        labelGoldDie->setText("5d6 x 10 gp");
        spinGold->setMaximum(300);
        spinGold->setValue(175);
        break;
    case 8: // Ranger
        labelGoldDie->setText("5d6 x 10 gp");
        spinGold->setMaximum(300);
        spinGold->setValue(175);
        break;
    case 9: // Rogue
        labelGoldDie->setText("4d6 x 10 gp");
        spinGold->setMaximum(240);
        spinGold->setValue(140);
        break;
    case 10: // Sorcerer
        labelGoldDie->setText("2d6 x 10 gp");
        spinGold->setMaximum(120);
        spinGold->setValue(70);
        break;
    case 11: // Wizard
        labelGoldDie->setText("2d6 x 10 gp");
        spinGold->setMaximum(120);
        spinGold->setValue(70);
        break;
    case 0: // No class selection
        labelGoldDie->setText("3d6 x 10 gp");
        spinGold->setMaximum(180);
        spinGold->setValue(105);
        break;
    }
}

void MainWindow::initiateSkill()
{
    int i(1);
    rowAcrobatics = new SkillRow("Acrobatics",i++);
    rowAppraise = new SkillRow("Appraise",i++);
    rowBluff = new SkillRow("Bluff",i++);
    rowClimb = new SkillRow("Climb",i++);
    rowCraft = new SkillRow("Craft",i++);
    rowDiplomacy = new SkillRow("Diplomacy",i++);
    rowDisableDevice = new SkillRow("Disable Device",i++);
    rowDisguise = new SkillRow("Disguise",i++);
    rowEscapeArtist = new SkillRow("Escape Artist",i++);
    rowFly = new SkillRow("Fly",i++);
    rowHandleAnimal = new SkillRow("Handle Animal",i++);
    rowHeal = new SkillRow("Heal",i++);
    rowIntimidate = new SkillRow("Intimidate",i++);
    rowKnArcana = new SkillRow("Kn. Arcana",i++);
    rowKnDungeoneering = new SkillRow("Kn. Dungeoneering",i++);
    rowKnEngineering = new SkillRow("Kn. Engineering",i++);
    rowKnGeography = new SkillRow("Kn. Geography",i++);
    rowKnHistory = new SkillRow("Kn. Hystory",i++);
    rowKnLocal = new SkillRow("Kn. Local",i++);
    rowKnNature = new SkillRow("Kn. Nature",i++);
    rowKnNobility = new SkillRow("Kn. Nobility",i++);
    rowKnPlanes = new SkillRow("Kn. Planes",i++);
    rowKnReligion = new SkillRow("Kn. Religion",i++);
    rowLinguistics = new SkillRow("Linguistics",i++);
    rowPerception = new SkillRow("Perception",i++);
    rowPerform = new SkillRow("Perform",i++);
    rowProfession = new SkillRow("Profession",i++);
    rowRide = new SkillRow("Ride",i++);
    rowSenseMotive = new SkillRow("Sense Motive",i++);
    rowSleighOfHand = new SkillRow("Sleight of Hand",i++);
    rowSpellcraft = new SkillRow("Spellcraft",i++);
    rowStealth = new SkillRow("Stealth",i++);
    rowSurvival = new SkillRow("Survival",i++);
    rowSwim = new SkillRow("Swim",i++);
    rowUseMagicDevice = new SkillRow("Use Magic Device",i++);

    updateSkill();

    layoutSkillRow = new QVBoxLayout;

    QWidget *scrollAreaContent = new QWidget;
    scrollAreaContent->setLayout(layoutSkillRow);
    scrollAreaSkill = new QScrollArea;
    scrollAreaSkill->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaSkill->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollAreaSkill->setWidgetResizable(true);
    scrollAreaSkill->setFixedWidth(400);
    scrollAreaSkill->setWidget(scrollAreaContent);

    layoutSkillRow->addLayout(layoutLabelSkill);
    layoutSkillRow->addLayout(rowAcrobatics);
    layoutSkillRow->addLayout(rowAppraise);
    layoutSkillRow->addLayout(rowBluff);
    layoutSkillRow->addLayout(rowClimb);
    layoutSkillRow->addLayout(rowCraft);
    layoutSkillRow->addLayout(rowDiplomacy);
    layoutSkillRow->addLayout(rowDisableDevice);
    layoutSkillRow->addLayout(rowDisguise);
    layoutSkillRow->addLayout(rowEscapeArtist);
    layoutSkillRow->addLayout(rowFly);
    layoutSkillRow->addLayout(rowHandleAnimal);
    layoutSkillRow->addLayout(rowHeal);
    layoutSkillRow->addLayout(rowIntimidate);
    layoutSkillRow->addLayout(rowKnArcana);
    layoutSkillRow->addLayout(rowKnDungeoneering);
    layoutSkillRow->addLayout(rowKnEngineering);
    layoutSkillRow->addLayout(rowKnGeography);
    layoutSkillRow->addLayout(rowKnHistory);
    layoutSkillRow->addLayout(rowKnLocal);
    layoutSkillRow->addLayout(rowKnNature);
    layoutSkillRow->addLayout(rowKnNobility);
    layoutSkillRow->addLayout(rowKnPlanes);
    layoutSkillRow->addLayout(rowKnReligion);
    layoutSkillRow->addLayout(rowLinguistics);
    layoutSkillRow->addLayout(rowPerception);
    layoutSkillRow->addLayout(rowPerform);
    layoutSkillRow->addLayout(rowProfession);
    layoutSkillRow->addLayout(rowRide);
    layoutSkillRow->addLayout(rowSenseMotive);
    layoutSkillRow->addLayout(rowSleighOfHand);
    layoutSkillRow->addLayout(rowSpellcraft);
    layoutSkillRow->addLayout(rowStealth);
    layoutSkillRow->addLayout(rowSurvival);
    layoutSkillRow->addLayout(rowSwim);
    layoutSkillRow->addLayout(rowUseMagicDevice);
}

void MainWindow::resetClassSkill()
{
    rowAcrobatics->resetClassSkill();
    rowAppraise->resetClassSkill();
    rowBluff->resetClassSkill();
    rowClimb->resetClassSkill();;
    rowCraft->resetClassSkill();
    rowDiplomacy->resetClassSkill();
    rowDisableDevice->resetClassSkill();
    rowDisguise->resetClassSkill();
    rowEscapeArtist->resetClassSkill();
    rowFly->resetClassSkill();
    rowHandleAnimal->resetClassSkill();
    rowHeal->resetClassSkill();
    rowIntimidate->resetClassSkill();
    rowKnArcana->resetClassSkill();
    rowKnDungeoneering->resetClassSkill();
    rowKnEngineering->resetClassSkill();
    rowKnGeography->resetClassSkill();
    rowKnHistory->resetClassSkill();
    rowKnLocal->resetClassSkill();
    rowKnNature->resetClassSkill();
    rowKnNobility->resetClassSkill();
    rowKnPlanes->resetClassSkill();
    rowKnReligion->resetClassSkill();
    rowLinguistics->resetClassSkill();
    rowPerception->resetClassSkill();
    rowPerform->resetClassSkill();
    rowProfession->resetClassSkill();
    rowRide->resetClassSkill();
    rowSenseMotive->resetClassSkill();
    rowSleighOfHand->resetClassSkill();
    rowSpellcraft->resetClassSkill();
    rowStealth->resetClassSkill();
    rowSurvival->resetClassSkill();
    rowSwim->resetClassSkill();
    rowUseMagicDevice->resetClassSkill();
}

void MainWindow::makeNewChar()
{
    setWindowTitle("Wheezy Character Creation");
    setFixedWidth(700);

    leftWidth = 250;

    // Name
    charName = new QLineEdit("Full Name");
    charName->setFixedWidth(leftWidth);

    // Core race selection
    coreRaces = new QComboBox;
    coreRaces->setFixedWidth(leftWidth);
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
    // Changes to class skills, BAB, saves and special abilities.
    coreClasses = new QComboBox;
    coreClasses->setFixedWidth(leftWidth);
    coreClasses->addItem("Choose a Class");
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

    connect(coreClasses,SIGNAL(activated(int)),this,SLOT(updateClassChoice()));

    // Alignment selection
    layoutAlignment = new QHBoxLayout;

    groupAlignmentLNC = new QGroupBox("Lawful/Chaotic");
    groupAlignmentLNC->setFixedWidth(leftWidth/2 - 10);
    groupAlignmentLNC->setFixedHeight(120);

    groupAlignmentGNE = new QGroupBox("Good/Evil");
    groupAlignmentGNE->setFixedWidth(leftWidth/2 - 10);
    groupAlignmentGNE->setFixedHeight(120);

    alignmentL = new QRadioButton("Lawful");
    alignmentN1 = new QRadioButton("Neutral");
    alignmentC = new QRadioButton("Chaotic");
    alignmentG = new QRadioButton("Good");
    alignmentN2 = new QRadioButton("Neutral");
    alignmentE = new QRadioButton("Evil");

    initiateAlignment();

    connect(alignmentL,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentN1,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentC,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentG,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentN2,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentE,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));

    // Ability scores
    initiateAbilities();

    // Number of feats and name
    QGroupBox *groupFeat = new QGroupBox("Feats");
    groupFeat->setFixedWidth(leftWidth);
    groupFeat->setAlignment(Qt::AlignHCenter);

    QLineEdit *textFeat = new QLineEdit;
    QLineEdit *textFeat2 = new QLineEdit;
    QLineEdit *textFeat3 = new QLineEdit;

    QVBoxLayout *layoutFeat = new QVBoxLayout;
    layoutFeat->addWidget(textFeat);
    layoutFeat->addWidget(textFeat2);
    layoutFeat->addWidget(textFeat3);

    groupFeat->setLayout(layoutFeat);

    // Hit Dice
    initiateHitDie();

    // Starting Gold
    initiateGold();

    // Layout for left part of page
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(charName);
    leftLayout->addWidget(coreRaces);
    leftLayout->addWidget(coreClasses);
    leftLayout->addLayout(layoutAlignment);
    leftLayout->addWidget(groupAbility);
    leftLayout->addWidget(groupFeat);
    leftLayout->addWidget(groupHit);
    leftLayout->addWidget(groupGold);

    // ///////////////////// Skill section

    QLabel *labelClassSkill = new QLabel("Class \nSkill");
    labelClassSkill->setFixedWidth(35);
    QLabel *labelSkill = new QLabel("Skill");
    labelSkill->setFixedWidth(120);
    QLabel *labelSkillRank = new QLabel("Rank");
    labelSkillRank->setFixedWidth(45);
    QLabel *labelSkillClass = new QLabel("Class");
    labelSkillClass->setFixedWidth(35);
    QLabel *labelSkillAbility = new QLabel("Ability");
    labelSkillAbility->setFixedWidth(35);
    QLabel *labelSkillTotal = new QLabel("Total");
    labelSkillTotal->setFixedWidth(35);

    layoutLabelSkill = new QGridLayout;
    layoutLabelSkill->addWidget(labelClassSkill,0,0);
    layoutLabelSkill->addWidget(labelSkill,0,1);
    layoutLabelSkill->addWidget(labelSkillRank,0,2);
    layoutLabelSkill->addWidget(labelSkillClass,0,3);
    layoutLabelSkill->addWidget(labelSkillAbility,0,4);
    layoutLabelSkill->addWidget(labelSkillTotal,0,5);

    initiateSkill();

    // Layout for overall page
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addWidget(scrollAreaSkill);

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

void MainWindow::updateClassChoice()
{
    if (coreClasses->currentIndex() == 1) // For Barbarian
    {
        alignmentN1->setChecked(true);
    }
    else if (coreClasses->currentIndex() == 6) // For Monk
    {
        alignmentL->setChecked(true);
    }
    else
    {
        alignmentN1->setChecked(true);
        alignmentN2->setChecked(true);
    }
    updateAlignment();
    updateHitDie();
    updateGold();
    updateSkill();
}

void MainWindow::updateSkill()
{
    resetClassSkill();

    int currentClass(coreClasses->currentIndex());

    rowAcrobatics->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                           spinBonusCON->value(), spinBonusINT->value(),
                                           spinBonusWIS->value(), spinBonusCHA->value());

    rowAppraise->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                         spinBonusCON->value(), spinBonusINT->value(),
                                         spinBonusWIS->value(), spinBonusCHA->value());

    rowBluff->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                      spinBonusCON->value(), spinBonusINT->value(),
                                      spinBonusWIS->value(), spinBonusCHA->value());

    rowClimb->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                      spinBonusCON->value(), spinBonusINT->value(),
                                      spinBonusWIS->value(), spinBonusCHA->value());

    rowCraft->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                      spinBonusCON->value(), spinBonusINT->value(),
                                      spinBonusWIS->value(), spinBonusCHA->value());

    rowDiplomacy->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                          spinBonusCON->value(), spinBonusINT->value(),
                                          spinBonusWIS->value(), spinBonusCHA->value());

    rowDisableDevice->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                              spinBonusCON->value(), spinBonusINT->value(),
                                              spinBonusWIS->value(), spinBonusCHA->value());

    rowDisguise->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                         spinBonusCON->value(), spinBonusINT->value(),
                                         spinBonusWIS->value(), spinBonusCHA->value());

    rowEscapeArtist->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                             spinBonusCON->value(), spinBonusINT->value(),
                                             spinBonusWIS->value(), spinBonusCHA->value());

    rowFly->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                    spinBonusCON->value(), spinBonusINT->value(),
                                    spinBonusWIS->value(), spinBonusCHA->value());

    rowHandleAnimal->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                             spinBonusCON->value(), spinBonusINT->value(),
                                             spinBonusWIS->value(), spinBonusCHA->value());

    rowHeal->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                     spinBonusCON->value(), spinBonusINT->value(),
                                     spinBonusWIS->value(), spinBonusCHA->value());

    rowIntimidate->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                           spinBonusCON->value(), spinBonusINT->value(),
                                           spinBonusWIS->value(), spinBonusCHA->value());

    rowKnArcana->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                         spinBonusCON->value(), spinBonusINT->value(),
                                         spinBonusWIS->value(), spinBonusCHA->value());

    rowKnDungeoneering->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                                spinBonusCON->value(), spinBonusINT->value(),
                                                spinBonusWIS->value(), spinBonusCHA->value());

    rowKnEngineering->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                              spinBonusCON->value(), spinBonusINT->value(),
                                              spinBonusWIS->value(), spinBonusCHA->value());

    rowKnGeography->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                            spinBonusCON->value(), spinBonusINT->value(),
                                            spinBonusWIS->value(), spinBonusCHA->value());

    rowKnHistory->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                          spinBonusCON->value(), spinBonusINT->value(),
                                          spinBonusWIS->value(), spinBonusCHA->value());

    rowKnLocal->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                        spinBonusCON->value(), spinBonusINT->value(),
                                        spinBonusWIS->value(), spinBonusCHA->value());

    rowKnNature->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                         spinBonusCON->value(), spinBonusINT->value(),
                                         spinBonusWIS->value(), spinBonusCHA->value());

    rowKnNobility->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                           spinBonusCON->value(), spinBonusINT->value(),
                                           spinBonusWIS->value(), spinBonusCHA->value());

    rowKnPlanes->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                         spinBonusCON->value(), spinBonusINT->value(),
                                         spinBonusWIS->value(), spinBonusCHA->value());

    rowKnReligion->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                           spinBonusCON->value(), spinBonusINT->value(),
                                           spinBonusWIS->value(), spinBonusCHA->value());

    rowLinguistics->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                            spinBonusCON->value(), spinBonusINT->value(),
                                            spinBonusWIS->value(), spinBonusCHA->value());

    rowPerception->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                           spinBonusCON->value(), spinBonusINT->value(),
                                           spinBonusWIS->value(), spinBonusCHA->value());

    rowPerform->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                        spinBonusCON->value(), spinBonusINT->value(),
                                        spinBonusWIS->value(), spinBonusCHA->value());

    rowProfession->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                           spinBonusCON->value(), spinBonusINT->value(),
                                           spinBonusWIS->value(), spinBonusCHA->value());

    rowRide->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                     spinBonusCON->value(), spinBonusINT->value(),
                                     spinBonusWIS->value(), spinBonusCHA->value());

    rowSenseMotive->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                            spinBonusCON->value(), spinBonusINT->value(),
                                            spinBonusWIS->value(), spinBonusCHA->value());

    rowSleighOfHand->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                             spinBonusCON->value(), spinBonusINT->value(),
                                             spinBonusWIS->value(), spinBonusCHA->value());

    rowSpellcraft->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                           spinBonusCON->value(), spinBonusINT->value(),
                                           spinBonusWIS->value(), spinBonusCHA->value());

    rowStealth->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                        spinBonusCON->value(), spinBonusINT->value(),
                                        spinBonusWIS->value(), spinBonusCHA->value());

    rowSurvival->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                         spinBonusCON->value(), spinBonusINT->value(),
                                         spinBonusWIS->value(), spinBonusCHA->value());

    rowSwim->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                     spinBonusCON->value(), spinBonusINT->value(),
                                     spinBonusWIS->value(), spinBonusCHA->value());

    rowUseMagicDevice->updateRow(currentClass, spinBonusSTR->value(), spinBonusDEX->value(),
                                               spinBonusCON->value(), spinBonusINT->value(),
                                               spinBonusWIS->value(), spinBonusCHA->value());

}
