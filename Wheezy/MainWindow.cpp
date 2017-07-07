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

// SLOTS

void MainWindow::makeNewChar()
{
    setWindowTitle("Wheezy Character Creation");
    setFixedWidth(700);
    QAction *actionSaveChar = new QAction("Save",this);
    menuChar->addAction(actionSaveChar);
    connect(actionSaveChar,SIGNAL(triggered(bool)),this,SLOT(saveNewChar()));

    // Actual layout creation
    NewCharWindow *layoutNewChar = new NewCharWindow;

    centralZone->setLayout(layoutNewChar);

    // Set central widget
    // Last line of window construction
    setCentralWidget(centralZone);
}

void MainWindow::saveNewChar()
{
    // TO DO : Implement functions to get what I need to save.

    /*
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
    */
}
