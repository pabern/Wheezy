#include "MainWindow.hpp"

using namespace std;

MainWindow::MainWindow()
{
    // Attributes of main window
    setWindowTitle("Welcome to Wheezy !");
    // setFixedSize(1500,750);

    // Menus
    // Character creation menu
    menuChar = menuBar()->addMenu("Character");

    QAction *actionNewChar = new QAction("New",this);
    menuChar->addAction(actionNewChar);

    connect(actionNewChar,SIGNAL(triggered(bool)),this,SLOT(makeNewChar()));

    // Obligatory first line
    // Container for ALL other widgets of main window
    centralZone = new QWidget;

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}

void MainWindow::initiateRaces()
{
    /*QFile fileRaces("://races");
    if (!fileRaces.open(QIODevice::ReadOnly))
    {
        qFatal("Failed to open file");
    }

    QTextStream streamRaces(&fileRaces);
    QString race;
    while (!streamRaces.atEnd())
    {
        streamRaces >> race;
        coreRaces->addItem(race);
        // Skip rest of line
        streamRaces.readLine();
    }*/

    // Read the different races from races file
    // TO DO : Relative path. Try to use resource file... Can't make it work.
    ifstream fluxRaces;
    fluxRaces.open("/home/pat/CodingProjects/Wheezy/Wheezy/Wheezy/races");

    if (fluxRaces)
    {
        coreRaces = new QComboBox;
        coreRaces->setFixedWidth(leftWidth);

        // Read all lines until End Of File and adding a new item for each.
        string race;
        // Make sure we start from the beginning
        fluxRaces.seekg(ios::beg);
        while(fluxRaces.peek() != EOF)
        {
            fluxRaces >> race;
            // Change string to QString
            QString raceQ = QString::fromStdString(race);
            coreRaces->addItem(raceQ);

            // Skip the rest of the line
            fluxRaces.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        fluxRaces.close();
    }
    else
    {
        qDebug() << "Problème de lecture";
        fluxRaces.close();
    }

    // Update abilities depending on race selection
    // TO DO : Other things might be affected by race
    connect(coreRaces,SIGNAL(activated(int)),this,SLOT(updateRaceChoice()));
}

void MainWindow::initiateClasses()
{
    // Read the different classes from races file
    // TO DO : Relative path.
    ifstream fluxClasses;
    fluxClasses.open("/home/pat/CodingProjects/Wheezy/Wheezy/Wheezy/classes");

    if (fluxClasses)
    {
        coreClasses = new QComboBox;
        coreClasses->setFixedWidth(leftWidth);

        // Read all lines until End Of File and adding a new item for each.
        string classes;
        fluxClasses.seekg(ios::beg);
        while(fluxClasses.peek() != EOF)
        {
            fluxClasses >> classes;
            // Change string to QString
            QString classesQ = QString::fromStdString(classes);
            coreClasses->addItem(classesQ);

            // Skip the rest of the line
            fluxClasses.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        fluxClasses.close();
    }
    else
    {
        qDebug() << "Problème de lecture";
        fluxClasses.close();
    }

    // Update all the things affected by class change
    // TO DO : Changes to class skills, BAB, saves and special abilities
    connect(coreClasses,SIGNAL(activated(int)),this,SLOT(updateClassChoice()));
}

void MainWindow::initiateAlignment()
{
    // Lawful, Chaotic group
    // QGroupBox necessary with radio buttons
    groupAlignmentLNC = new QGroupBox("Lawful/Chaotic");
    groupAlignmentLNC->setFixedWidth(leftWidth/2 - 10);
    groupAlignmentLNC->setFixedHeight(120);

    alignmentL = new QRadioButton("Lawful");
    alignmentN1 = new QRadioButton("Neutral");
    alignmentC = new QRadioButton("Chaotic");

    layoutLNC = new QVBoxLayout;
    layoutLNC->addWidget(alignmentL);
    layoutLNC->addWidget(alignmentN1);
    layoutLNC->addWidget(alignmentC);

    groupAlignmentLNC->setLayout(layoutLNC);

    // Good, Evil group
    // QGroupBox necessary with radio buttons
    groupAlignmentGNE = new QGroupBox("Good/Evil");
    groupAlignmentGNE->setFixedWidth(leftWidth/2 - 10);
    groupAlignmentGNE->setFixedHeight(120);

    alignmentG = new QRadioButton("Good");
    alignmentN2 = new QRadioButton("Neutral");
    alignmentE = new QRadioButton("Evil");

    layoutGNE = new QVBoxLayout;
    layoutGNE->addWidget(alignmentG);
    layoutGNE->addWidget(alignmentN2);
    layoutGNE->addWidget(alignmentE);

    groupAlignmentGNE->setLayout(layoutGNE);

    // Merge of both groups
    layoutAlignment = new QHBoxLayout;
    layoutAlignment->addWidget(groupAlignmentLNC);
    layoutAlignment->addWidget(groupAlignmentGNE);

    // Each time a radio is pressed, they need to be updated
    connect(alignmentL,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentN1,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentC,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));

    connect(alignmentG,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentN2,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
    connect(alignmentE,SIGNAL(toggled(bool)),this,SLOT(updateAlignment()));
}

void MainWindow::initiateAbilities()
{
    // QGroupBox necessary with radio buttons
    groupAbility = new QGroupBox("Abilities");
    groupAbility->setAlignment(Qt::AlignHCenter);

    // Grid headers with special characteristics
    GridHeader *labelAbility = new GridHeader("Ability");
    GridHeader *labelAbilityRoll = new GridHeader("Roll");
    GridHeader *labelAbilityRace = new GridHeader("Race");
    GridHeader *labelAbilityValue = new GridHeader("Value");
    GridHeader *labelAbilityBonus = new GridHeader("Bonus");

    // Layout for ability labels
    layoutLabelAbility = new QHBoxLayout;
    layoutLabelAbility->addWidget(labelAbility);
    layoutLabelAbility->addWidget(labelAbilityRoll);
    layoutLabelAbility->addWidget(labelAbilityRace);
    layoutLabelAbility->addWidget(labelAbilityValue);
    layoutLabelAbility->addWidget(labelAbilityBonus);

    // Each ability is created row by row
    abilitySTR = new AbilityRow("STR");
    abilityDEX = new AbilityRow("DEX");
    abilityCON = new AbilityRow("CON");
    abilityINT = new AbilityRow("INT");
    abilityWIS = new AbilityRow("WIS");
    abilityCHA = new AbilityRow("CHA");

    // TO DO : Find a way to keep the radios private, yet connect them to updateAbilities.
    // Maybe move update abilities in the row...
    connect(abilitySTR->radio,SIGNAL(toggled(bool)),this,SLOT(updateRaceChoice()));
    connect(abilityDEX->radio,SIGNAL(toggled(bool)),this,SLOT(updateRaceChoice()));
    connect(abilityCON->radio,SIGNAL(toggled(bool)),this,SLOT(updateRaceChoice()));
    connect(abilityINT->radio,SIGNAL(toggled(bool)),this,SLOT(updateRaceChoice()));
    connect(abilityWIS->radio,SIGNAL(toggled(bool)),this,SLOT(updateRaceChoice()));
    connect(abilityCHA->radio,SIGNAL(toggled(bool)),this,SLOT(updateRaceChoice()));

    connect(abilitySTR->spinRoll,SIGNAL(valueChanged(int)),this,SLOT(updateRaceChoice()));
    connect(abilityDEX->spinRoll,SIGNAL(valueChanged(int)),this,SLOT(updateRaceChoice()));
    connect(abilityCON->spinRoll,SIGNAL(valueChanged(int)),this,SLOT(updateRaceChoice()));
    connect(abilityINT->spinRoll,SIGNAL(valueChanged(int)),this,SLOT(updateRaceChoice()));
    connect(abilityWIS->spinRoll,SIGNAL(valueChanged(int)),this,SLOT(updateRaceChoice()));
    connect(abilityCHA->spinRoll,SIGNAL(valueChanged(int)),this,SLOT(updateRaceChoice()));

    // Then added to the layout
    layoutAbility = new QVBoxLayout;
    layoutAbility->addLayout(layoutLabelAbility);
    layoutAbility->addLayout(abilitySTR);
    layoutAbility->addLayout(abilityDEX);
    layoutAbility->addLayout(abilityCON);
    layoutAbility->addLayout(abilityINT);
    layoutAbility->addLayout(abilityWIS);
    layoutAbility->addLayout(abilityCHA);

    groupAbility->setLayout(layoutAbility);

    // The abilities are updated when created, so the initial totals are OK
    updateAbilities();
}

void MainWindow::initiateFeats()
{
    // A group, some line edits, nothing fancy
    groupFeat = new QGroupBox("Feats");
    groupFeat->setFixedWidth(leftWidth);
    groupFeat->setAlignment(Qt::AlignHCenter);

    lineFeat1 = new QLineEdit;
    lineFeat2 = new QLineEdit;
    lineFeat3 = new QLineEdit;

    layoutFeat = new QVBoxLayout;
    layoutFeat->addWidget(lineFeat1);
    layoutFeat->addWidget(lineFeat2);
    layoutFeat->addWidget(lineFeat3);

    groupFeat->setLayout(layoutFeat);
}

void MainWindow::initiateHitDie()
{
    // Nothing fancy here
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

void MainWindow::initiateGold()
{
    // Nothing fancy here
    groupGold = new QGroupBox("Starting Gold");
    groupGold->setFixedWidth(leftWidth);
    groupGold->setAlignment(Qt::AlignHCenter);

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

void MainWindow::initiateSkill()
{
    // Labels
    labelClassSkill = new GridHeader("Class \nSkill");
    labelClassSkill->setFixedWidth(35);

    labelSkill = new GridHeader("Skill");
    labelSkill->setFixedWidth(120);

    labelSkillRank = new GridHeader("Rank");
    labelSkillRank->setFixedWidth(45);

    labelSkillClass = new GridHeader("Class");
    labelSkillClass->setFixedWidth(35);

    labelSkillAbility = new GridHeader("Ability");
    labelSkillAbility->setFixedWidth(35);

    labelSkillTotal = new GridHeader("Total");
    labelSkillTotal->setFixedWidth(35);

    layoutLabelSkill = new QHBoxLayout;
    layoutLabelSkill->addWidget(labelClassSkill);
    layoutLabelSkill->addWidget(labelSkill);
    layoutLabelSkill->addWidget(labelSkillRank);
    layoutLabelSkill->addWidget(labelSkillClass);
    layoutLabelSkill->addWidget(labelSkillAbility);
    layoutLabelSkill->addWidget(labelSkillTotal);

    // Initialization of all skills
    // TO DO : Maybe put the names in a file and have a for to reduce the lines.
    int i(0);
    tableSkills[i++] = new SkillRow("Acrobatics");
    tableSkills[i++] = new SkillRow("Appraise");
    tableSkills[i++] = new SkillRow("Bluff");
    tableSkills[i++] = new SkillRow("Climb");
    tableSkills[i++] = new SkillRow("Craft");
    tableSkills[i++] = new SkillRow("Diplomacy");
    tableSkills[i++] = new SkillRow("Disable Device");
    tableSkills[i++] = new SkillRow("Disguise");
    tableSkills[i++] = new SkillRow("Escape Artist");
    tableSkills[i++] = new SkillRow("Fly");
    tableSkills[i++] = new SkillRow("Handle Animal");
    tableSkills[i++] = new SkillRow("Heal");
    tableSkills[i++] = new SkillRow("Intimidate");
    tableSkills[i++] = new SkillRow("Kn. Arcana");
    tableSkills[i++] = new SkillRow("Kn. Dungeoneering");
    tableSkills[i++] = new SkillRow("Kn. Engineering");
    tableSkills[i++] = new SkillRow("Kn. Geography");
    tableSkills[i++] = new SkillRow("Kn. Hystory");
    tableSkills[i++] = new SkillRow("Kn. Local");
    tableSkills[i++] = new SkillRow("Kn. Nature");
    tableSkills[i++] = new SkillRow("Kn. Nobility");
    tableSkills[i++] = new SkillRow("Kn. Planes");
    tableSkills[i++] = new SkillRow("Kn. Religion");
    tableSkills[i++] = new SkillRow("Linguistics");
    tableSkills[i++] = new SkillRow("Perception");
    tableSkills[i++] = new SkillRow("Perform");
    tableSkills[i++] = new SkillRow("Profession");
    tableSkills[i++] = new SkillRow("Ride");
    tableSkills[i++] = new SkillRow("Sense Motive");
    tableSkills[i++] = new SkillRow("Sleight of Hand");
    tableSkills[i++] = new SkillRow("Spellcraft");
    tableSkills[i++] = new SkillRow("Stealth");
    tableSkills[i++] = new SkillRow("Survival");
    tableSkills[i++] = new SkillRow("Swim");
    tableSkills[i++] = new SkillRow("Use Magic Device");

    // Creation of layout and scroll area to navguate all skills
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
    for (int j = 0; j <= 34; j++)
    {
        layoutSkillRow->addLayout(tableSkills[j]);
        connect(tableSkills[j]->spinRank,SIGNAL(valueChanged(int)),this,SLOT(updateRanksLeft()));
    }
}

void MainWindow::setRaceValues(int STR, int DEX, int CON, int INT, int WIS, int CHA)
{
    abilitySTR->setRaceValue(STR);
    abilityDEX->setRaceValue(DEX);
    abilityCON->setRaceValue(CON);
    abilityINT->setRaceValue(INT);
    abilityWIS->setRaceValue(WIS);
    abilityCHA->setRaceValue(CHA);
}

// SLOTS

void MainWindow::makeNewChar()
{
    setWindowTitle("Wheezy Character Creation");
    setFixedWidth(700);
    QAction *actionSaveChar = new QAction("Save",this);
    menuChar->addAction(actionSaveChar);
    connect(actionSaveChar,SIGNAL(triggered(bool)),this,SLOT(saveChar()));

    leftWidth = 250;

    //***** Name *****
    charName = new QLineEdit("Full Name");
    charName->setFixedWidth(leftWidth - 45);

    ranksLeft = new QSpinBox;
    ranksLeft->setFixedWidth(35);
    ranksLeft->setAlignment(Qt::AlignHCenter);
    ranksLeft->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ranksLeft->setMinimum(-35);

    layoutName = new QHBoxLayout;
    layoutName->addWidget(charName);
    layoutName->addWidget(ranksLeft);


    //***** Races *****
    initiateRaces();

    //***** Classes *****
    initiateClasses();

    //***** Alignment *****
    initiateAlignment();

    //***** Ability scores *****
    initiateAbilities();

    //***** Feats *****
    initiateFeats();

    //***** Hit Dice *****
    initiateHitDie();

    //***** Starting Gold *****
    initiateGold();

    //***** Skills *****
    initiateSkill();

    //***** End of initialization phase *****
    // All layout are updated to null
    updateClassChoice();

    //***** Layout *****
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(layoutName);
    leftLayout->addWidget(coreRaces);
    leftLayout->addWidget(coreClasses);
    leftLayout->addLayout(layoutAlignment);
    leftLayout->addWidget(groupAbility);
    leftLayout->addWidget(groupFeat);
    leftLayout->addWidget(groupHit);
    leftLayout->addWidget(groupGold);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addWidget(scrollAreaSkill);

    centralZone->setLayout(layout);

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}

void MainWindow::updateRaceChoice()
{
    updateAbilities();
    updateClassChoice(); // To change the feats in case of Human.
}

void MainWindow::updateAbilities()
{
    int raceIndex = coreRaces->currentIndex();

    // We read the races file until we get to the line that matches the selected
    // index then read the values
    ifstream fluxRaces;
    fluxRaces.open("/home/pat/CodingProjects/Wheezy/Wheezy/Wheezy/races");

    string races;
    if (fluxRaces)
    {
        fluxRaces.seekg(ios::beg);
        for (int i = 0; i < raceIndex; ++i)
        {
            fluxRaces.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        fluxRaces >> races;
        // Store the values
        fluxRaces >> raceSTR;
        fluxRaces >> raceDEX;
        fluxRaces >> raceCON;
        fluxRaces >> raceINT;
        fluxRaces >> raceWIS;
        fluxRaces >> raceCHA;

        fluxRaces.close();
    }
    else
    {
        qDebug() << "Problème de lecture";
        fluxRaces.close();
    }

    // Set the values
    if (raceSTR == 0 && raceDEX == 0 && raceCON == 0 && raceINT == 0 && raceWIS == 0 && raceCHA == 0)
    {
        if (abilitySTR->isChecked())
        {
            setRaceValues(2,0,0,0,0,0);
        }
        else if (abilityDEX->isChecked())
        {
            setRaceValues(0,2,0,0,0,0);
        }
        else if (abilityCON->isChecked())
        {
            setRaceValues(0,0,2,0,0,0);
        }
        else if (abilityINT->isChecked())
        {
            setRaceValues(0,0,0,2,0,0);
        }
        else if (abilityWIS->isChecked())
        {
            setRaceValues(0,0,0,0,2,0);
        }
        else if (abilityCHA->isChecked())
        {
            setRaceValues(0,0,0,0,0,2);
        }
    }
    else
    {
        setRaceValues(raceSTR,raceDEX,raceCON,raceINT,raceWIS,raceCHA);
    }

    // Update values of table
    abilitySTR->updateTotalsAndBonus();
    abilityDEX->updateTotalsAndBonus();
    abilityCON->updateTotalsAndBonus();
    abilityINT->updateTotalsAndBonus();
    abilityWIS->updateTotalsAndBonus();
    abilityCHA->updateTotalsAndBonus();
}

void MainWindow::updateClassChoice()
{
    int classIndex = coreClasses->currentIndex();

    ifstream fluxClasses;
    fluxClasses.open("/home/pat/CodingProjects/Wheezy/Wheezy/Wheezy/classes");

    string classes;
    int checkedAlignment;
    if (fluxClasses)
    {
        fluxClasses.seekg(ios::beg);
        for (int i = 0; i < classIndex; ++i)
        {
            fluxClasses.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        fluxClasses >> classes;
        fluxClasses >> checkedAlignment;
    }
    else
    {
        qDebug() << "Problème de lecture";
        fluxClasses.close();
    }

    switch (checkedAlignment) {
    case 0: // Base
        break;
    case 1: // Monk - Only lawful
        alignmentL->setChecked(true);
        alignmentN2->setChecked(true);
        break;
    case 2: // Paladin - Lawful Good
        alignmentL->setChecked(true);
        alignmentG->setChecked(true);
        break;
    case 3: // Barbarian - Cannot be lawful
        alignmentN1->setChecked(true);
        break;
    default:
        break;
    }

    updateAlignment(fluxClasses);
    updateHitDie(fluxClasses);
    updateGold(fluxClasses);
    updateFeats(fluxClasses);
    updateSkill(fluxClasses);
}

void MainWindow::updateAlignment()
{
    alignmentL->setEnabled(true);
    alignmentN1->setEnabled(true);
    alignmentC->setEnabled(true);
    alignmentG->setEnabled(true);
    alignmentN2->setEnabled(true);
    alignmentE->setEnabled(true);

    // Set enable for radios
    bool enL;
    if (enLint == -1)
    {
        // Cleric
        // button "Diety" that pops a box where he can choose his diety maybe ?
        // One away from diety max
        enL = true;
        alignmentL->setEnabled(enL);
        alignmentN1->setEnabled(enN1);
        alignmentC->setEnabled(enC);
        alignmentG->setEnabled(enG);
        alignmentN2->setEnabled(enN2);
        alignmentE->setEnabled(enE);
    }
    else if (enLint == -2)
    {
        // Case of Druid
        // Something neutral
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
    }
    else
    {
        if (enLint == 1)
        {
            enL = true;
        }
        else
        {
            enL = false;
        }
        alignmentL->setEnabled(enL);
        alignmentN1->setEnabled(enN1);
        alignmentC->setEnabled(enC);
        alignmentG->setEnabled(enG);
        alignmentN2->setEnabled(enN2);
        alignmentE->setEnabled(enE);
    }
}

void MainWindow::updateAlignment(ifstream &file)
{
    file >> enLint;
    file >> enN1;
    file >> enC;
    file >> enG;
    file >> enN2;
    file >> enE;

    updateAlignment();

}

void MainWindow::updateHitDie(ifstream &file)
{
    string diceText;
    int diceValue;

    file >> diceText;
    file >> diceValue;

    QString diceTextQ = QString::fromStdString(diceText);

    labelHitDie->setText(diceTextQ);
    spinHit->setMaximum(diceValue);
}

void MainWindow::updateGold(ifstream &file)
{
    string goldText;
    int maxValue;
    int meanValue;

    file >> goldText;
    file >> maxValue;
    file >> meanValue;

    QString goldTextQ = QString::fromStdString(goldText);

    labelGoldDie->setText(goldTextQ + " x 10 gp");
    spinGold->setMaximum(maxValue);
    spinGold->setValue(meanValue);
}

void MainWindow::updateFeats(ifstream &file)
{
    file >> numberFeats;

    int raceIndex = coreRaces->currentIndex();

    // We read the races file until we get to the line that matches the selected
    // index then read the values
    ifstream fluxRaces;
    fluxRaces.open("/home/pat/CodingProjects/Wheezy/Wheezy/Wheezy/races");

    string races;
    int temp;
    int additionalFeat;
    if (fluxRaces)
    {
        fluxRaces.seekg(ios::beg);
        for (int i = 0; i < raceIndex; ++i)
        {
            fluxRaces.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        fluxRaces >> races;
        // Store the values
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;

        fluxRaces >> additionalFeat;

        fluxRaces.close();
    }
    else
    {
        qDebug() << "Problème de lecture";
        fluxRaces.close();
    }

    numberFeats += additionalFeat;

    switch (numberFeats) {
    case 0:
        lineFeat1->setEnabled(false);
        lineFeat2->setEnabled(false);
        lineFeat3->setEnabled(false);
        break;
    case 1:
        lineFeat1->setEnabled(true);
        lineFeat2->setEnabled(false);
        lineFeat3->setEnabled(false);
        break;
    case 2:
        lineFeat1->setEnabled(true);
        lineFeat2->setEnabled(true);
        lineFeat3->setEnabled(false);
        break;
    case 3:
        lineFeat1->setEnabled(true);
        lineFeat2->setEnabled(true);
        lineFeat3->setEnabled(true);
        break;
    default:
        break;
    }
}

void MainWindow::updateSkill(ifstream &file)
{
    resetClassSkill();
    resetRanks();

    int abilityBonus[6];
    abilityBonus[0] = abilitySTR->getBonus();
    abilityBonus[1] = abilityDEX->getBonus();
    abilityBonus[2] = abilityCON->getBonus();
    abilityBonus[3] = abilityINT->getBonus();
    abilityBonus[4] = abilityWIS->getBonus();
    abilityBonus[5] = abilityCHA->getBonus();

    bool classSkill;

    for (int j = 0; j <= 34; j++)
    {
        file >> classSkill;
        tableSkills[j]->updateRow(classSkill, abilityBonus,j);
    }

    file >> ranksLeftValue;
    int raceIndex = coreRaces->currentIndex();

    // We read the races file until we get to the line that matches the selected
    // index then read the values
    ifstream fluxRaces;
    fluxRaces.open("/home/pat/CodingProjects/Wheezy/Wheezy/Wheezy/races");

    string races;
    int temp;
    int additionalRank;
    if (fluxRaces)
    {
        fluxRaces.seekg(ios::beg);
        for (int i = 0; i < raceIndex; ++i)
        {
            fluxRaces.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        fluxRaces >> races;
        // Store the values
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;
        fluxRaces >> temp;

        fluxRaces >> additionalRank;

        fluxRaces.close();
    }
    else
    {
        qDebug() << "Problème de lecture";
        fluxRaces.close();
    }

    ranksLeftValue += additionalRank;
    ranksLeft->setValue(ranksLeftValue);
    updateRanksLeft();
}

void MainWindow::resetClassSkill()
{
    for (int j = 0; j <= 34; j++)
    {
        tableSkills[j]->resetClassSkill();
    }
}

void MainWindow::resetRanks()
{
    for (int j = 0; j <= 34; j++)
    {
        tableSkills[j]->resetRank();
    }
}

void MainWindow::updateRanksLeft()
{
    int sum(0);
    int temp;
    for (int j = 0; j <= 34; j++)
    {
        temp = tableSkills[j]->getRank();
        sum += temp;
    }
    ranksLeft->setValue(ranksLeftValue - sum);
}

void MainWindow::saveChar()
{
    if (ranksLeft->value() > 0)
    {
        ofstream streamSave;
        streamSave.open("/home/pat/CodingProjects/Wheezy/Wheezy/Wheezy/" + charName->text().toStdString());

        if (streamSave)
        {
            // Name, race & class
            streamSave << charName->text().toStdString() << endl;
            streamSave << coreRaces->currentText().toStdString() << endl;
            streamSave << coreClasses->currentText().toStdString() << endl;

            // Alignment
            if (alignmentL->isChecked())
            {
                streamSave << "Lawful ";
            }
            else if (alignmentN1->isChecked())
            {
                streamSave << "Neutral ";
            }
            else
            {
                streamSave << "Chaotic ";
            }
            if (alignmentG->isChecked())
            {
                streamSave << "Good" << endl;
            }
            else if (alignmentN2->isChecked())
            {
                streamSave << "Neutral" << endl;
            }
            else
            {
                streamSave << "Evil" << endl;
            }

            // Abilities
            streamSave << abilitySTR->getValue() << " "
                       << abilityDEX->getValue() << " "
                       << abilityCON->getValue() << " "
                       << abilityINT->getValue() << " "
                       << abilityWIS->getValue() << " "
                       << abilityCHA->getValue()
                       << endl;

            // Feats
            switch (numberFeats) {
            case 1:
                streamSave << lineFeat1->text().toStdString() << endl;
                break;
            case 2:
                streamSave << lineFeat1->text().toStdString() << endl;
                streamSave << lineFeat2->text().toStdString() << endl;
                break;
            case 3:
                streamSave << lineFeat1->text().toStdString() << endl;
                streamSave << lineFeat2->text().toStdString() << endl;
                streamSave << lineFeat3->text().toStdString() << endl;
                break;
            default:
                break;
            }

            // Hit Dice & starting gold
            streamSave << spinHit->value() << endl;
            streamSave << spinGold->value() << endl;

            // Skills
            for (int j = 0; j <= 34; j++)
            {
                streamSave << tableSkills[j]->getRank() << " " << tableSkills[j]->getTotal() << endl;
            }
        }
        else
        {
            qFatal("Can't open file to save on");
        }
    }
    else
    {
        QMessageBox::information(this,"You did a booboo ! ",
        "Make sure the amount of ranks used doesn't become negative. Check next to your name !");
    }
}
