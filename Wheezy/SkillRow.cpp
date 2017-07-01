#include "SkillRow.hpp"

SkillRow::SkillRow(QString skill, int index)
{
    skillIndex = index;

    checkCS = new QCheckBox;
    checkCS->setEnabled(false);
    checkCS->setFixedWidth(35);

    name = new QLabel(skill);
    name->setFixedWidth(120);

    spinRank = new QSpinBox;
    spinRank->setValue(0);
    spinRank->setMinimum(0);
    spinRank->setMaximum(1); // Level is maximum
    spinRank->setFixedWidth(45);

    connect(spinRank,SIGNAL(valueChanged(int)),this,SLOT(updateTotal()));

    spinClass = new QSpinBox;
    spinClass->setValue(0);
    spinClass->setReadOnly(true);
    spinClass->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinClass->setFixedWidth(35);

    spinAbility = new QSpinBox;
    spinAbility->setValue(0);
    spinAbility->setReadOnly(true);
    spinAbility->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinAbility->setFixedWidth(35);

    spinTotal = new QSpinBox;
    spinTotal->setValue(0);
    spinTotal->setReadOnly(true);
    spinTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinTotal->setFixedWidth(35);

    addWidget(checkCS);
    addWidget(name);
    addWidget(spinRank);
    addWidget(spinClass);
    addWidget(spinAbility);
    addWidget(spinTotal);
}

void SkillRow::updateRow(int currentClass, int bonusSTR, int bonusDEX,
                                           int bonusCON, int bonusINT,
                                           int bonusWIS, int bonusCHA)
{
    // REPLACE IF WITH SWITCH
    // REMOVE bonusCON cause no skill with con

    // Acrobatics
    if (skillIndex == 1)
    {
        spinAbility->setValue(bonusDEX);

        if (currentClass == 1 || currentClass == 2 ||
            currentClass == 6 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }

    } // Appraise
    else if (skillIndex == 2 )
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 9 || currentClass == 11)
        {
            checkCS->setChecked(true);
        }

    } // Bluff
    else if (skillIndex == 3)
    {
        spinAbility->setValue(bonusCHA);

        if (currentClass == 2 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Climb
    else if (skillIndex == 4)
    {
        spinAbility->setValue(bonusSTR);

        if (currentClass != 3 && currentClass != 7 &&
            currentClass != 10 && currentClass != 11)
        {
            checkCS->setChecked(true);
        }
    } // Craft
    else if (skillIndex == 5)
    {
        spinAbility->setValue(bonusINT);
        checkCS->setChecked(true);
    } // Diplomacy
    else if (skillIndex == 6)
    {
        spinAbility->setValue(bonusCHA);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 7 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Disable Device
    else if (skillIndex == 7)
    {
        spinAbility->setValue(bonusDEX);

        if (currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Disguise
    else if (skillIndex == 8)
    {
        spinAbility->setValue(bonusCHA);

        if (currentClass == 2 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Escape Artist
    else if (skillIndex == 9)
    {
        spinAbility->setValue(bonusDEX);

        if (currentClass == 2 || currentClass == 6 ||
            currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Fly
    else if (skillIndex == 10)
    {
        spinAbility->setValue(bonusDEX);

        if (currentClass == 4 || currentClass == 10 ||
            currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Handle Animal
    else if (skillIndex == 11)
    {
        spinAbility->setValue(bonusCHA);

        if (currentClass == 1 || currentClass == 4 ||
            currentClass == 5 || currentClass == 7 ||
            currentClass == 8 || currentClass == 10)
        {
            checkCS->setChecked(true);
        }
    } // Heal
    else if (skillIndex == 12)
    {
        spinAbility->setValue(bonusWIS);

        if (currentClass == 3 || currentClass == 4 ||
            currentClass == 7 || currentClass == 8)
        {
            checkCS->setChecked(true);
        }
    } // Intimidate
    else if (skillIndex == 13)
    {
        spinAbility->setValue(bonusCHA);

        if (currentClass == 1 || currentClass == 2 ||
            currentClass == 5 || currentClass == 6 ||
            currentClass == 8 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Arcana
    else if (skillIndex == 14)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 10 || currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Dungeoneering
    else if (skillIndex == 15)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 5 ||
            currentClass == 8 || currentClass == 9 ||
            currentClass == 10 || currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Engineering
    else if (skillIndex == 16)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 5 ||
            currentClass == 10 || currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Geography
    else if (skillIndex == 17)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 4 ||
            currentClass == 8 || currentClass == 10 ||
            currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. History
    else if (skillIndex == 18)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 6 || currentClass == 10 ||
            currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Local
    else if (skillIndex == 19)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 9 ||
            currentClass == 10 || currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Nature
    else if (skillIndex == 20)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 1 || currentClass == 2 ||
            currentClass == 4 || currentClass == 8 ||
            currentClass == 10 || currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Nobility
    else if (skillIndex == 21)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 7 || currentClass == 10 ||
            currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Planes
    else if (skillIndex == 22)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 10 || currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Kn. Religion
    else if (skillIndex == 23)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 6 || currentClass == 7 ||
            currentClass == 10 || currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Linguistics
    else if (skillIndex == 24)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 9 || currentClass == 10 ||
            currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Perception
    else if (skillIndex == 25)
    {
        spinAbility->setValue(bonusWIS);

        if (currentClass == 1 || currentClass == 2 ||
            currentClass == 4 || currentClass == 6 ||
            currentClass == 8 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Perform
    else if (skillIndex == 26)
    {
        spinAbility->setValue(bonusCHA);

        if (currentClass == 2 || currentClass == 6 ||
            currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Prof
    else if (skillIndex == 27)
    {
        spinAbility->setValue(bonusWIS);

        if (currentClass != 1)
        {
            checkCS->setChecked(true);
        }
    } // Ride
    else if (skillIndex == 28)
    {
        spinAbility->setValue(bonusDEX);

        if (currentClass == 1 || currentClass == 4 ||
            currentClass == 5 || currentClass == 6 ||
            currentClass == 7 || currentClass == 8 ||
            currentClass == 10)
        {
            checkCS->setChecked(true);
        }
    } // Sense Motive
    else if (skillIndex == 29)
    {
        spinAbility->setValue(bonusWIS);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 6 || currentClass == 7 ||
            currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Sleight of Hand
    else if (skillIndex == 30)
    {
        spinAbility->setValue(bonusDEX);

        if (currentClass == 2 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Spellcraft
    else if (skillIndex == 31)
    {
        spinAbility->setValue(bonusINT);

        if (currentClass == 2 || currentClass == 3 ||
            currentClass == 4 || currentClass == 7 ||
            currentClass == 8 || currentClass == 10 ||
            currentClass == 11)
        {
            checkCS->setChecked(true);
        }
    } // Stealth
    else if (skillIndex == 32)
    {
        spinAbility->setValue(bonusDEX);

        if (currentClass == 2 || currentClass == 6 ||
            currentClass == 8 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Survival
    else if (skillIndex == 33)
    {
        spinAbility->setValue(bonusWIS);

        if (currentClass == 1 || currentClass == 4 ||
            currentClass == 5 || currentClass == 8)
        {
            checkCS->setChecked(true);
        }
    } // Swim
    else if (skillIndex == 34)
    {
        spinAbility->setValue(bonusSTR);

        if (currentClass == 1 || currentClass == 4 ||
            currentClass == 5 || currentClass == 6 ||
            currentClass == 8 || currentClass == 9)
        {
            checkCS->setChecked(true);
        }
    } // Use Magic Device
    else if (skillIndex == 35)
    {
        spinAbility->setValue(bonusCHA);

        if (currentClass == 2 || currentClass == 9 ||
            currentClass == 10)
        {
            checkCS->setChecked(true);
        }
    }

    updateTotal();
}

void SkillRow::resetClassSkill()
{
    checkCS->setChecked(false);
}

void SkillRow::updateTotal()
{
    if (checkCS->isChecked() && spinRank->value()>0)
    {
        spinClass->setValue(3);
    }
    else
    {
        spinClass->setValue(0);
    }
    spinTotal->setValue(spinRank->value() + spinClass->value() + spinAbility->value());
}
