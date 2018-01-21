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

    // QAction *actionNewChar = new QAction("New",this);
    actionNewChar = new QAction("New",this);
    menuChar->addAction(actionNewChar);

    connect(actionNewChar,SIGNAL(triggered(bool)),this,SLOT(makeNewChar()));

    // Obligatory first line
    // Container for ALL other widgets of main window
    centralZone = new QWidget;

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}

// SLOTS

void MainWindow::makeNewChar()
{
    setWindowTitle("Wheezy Character Creation");
    setFixedWidth(700);
    actionSaveChar = new QAction("Save",this);

    menuChar->removeAction(actionNewChar);
    menuChar->addAction(actionSaveChar);
    connect(actionSaveChar,SIGNAL(triggered(bool)),this,SLOT(saveNewChar()));

    // Actual layout creation
    layoutNewChar = new NewCharWindow;

    centralZone->setLayout(layoutNewChar);

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}

void MainWindow::saveNewChar()
{
    if (layoutNewChar->getRanksLeft() >= 0)
    {
        ofstream streamSave;
        streamSave.open("/home/pat/CodingProjects/Wheezy/Wheezy/Wheezy/" + layoutNewChar->getCharName().toStdString());

        if (streamSave)
        {
            // Name, race & class
            streamSave << layoutNewChar->getCharName().toStdString() << endl;
            streamSave << layoutNewChar->getCoreRaces().toStdString() << endl;
            streamSave << layoutNewChar->getCoreClasses().toStdString() << endl;

            // Alignment
            streamSave << layoutNewChar->getAlignment() << endl;

            // Abilities
            layoutNewChar->writeAbilities(streamSave);

            // Feats
            streamSave << layoutNewChar->getFeats() << endl;

            // Hit Dice & starting gold
            streamSave << layoutNewChar->getHit()<< endl;
            streamSave << layoutNewChar->getGold() << endl;

            // Skills
            layoutNewChar->writeSkills(streamSave);
            QMessageBox::information(this,"Saved","Your character was saved.");
        }
        else
        {
            qFatal("Can't open file to save on");
        }
    }
    else
    {
        QMessageBox::information(this,"Sneaky","You put too much rank ! Check next to your name !");
    }
}
