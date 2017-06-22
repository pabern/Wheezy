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



    // Overall page layout for character creation
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(charName);
    layout->addWidget(coreRaces);
    layout->addWidget(coreClasses);
    layout->addLayout(alignmentLayout);
    layout->addWidget(viewAbility);

    centralZone->setLayout(layout);

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}
