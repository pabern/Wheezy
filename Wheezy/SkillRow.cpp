#include "SkillRow.hpp"

SkillRow::SkillRow(QString skill)
{
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

void SkillRow::updateRow(bool classSkill, int abilityBonus[], int index)
{

    checkCS->setChecked(classSkill);

    switch (index) {
    case 3:case 33:
        spinAbility->setValue(abilityBonus[0]);
        break;
    case 0:case 6:case 8:case 9:case 27:case 29:case 31:
        spinAbility->setValue(abilityBonus[1]);
        break;
    case 1:case 4:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:
    case 23:case 30:
        spinAbility->setValue(abilityBonus[3]);
        break;
    case 11:case 24:case 26:case 28:case 32:
        spinAbility->setValue(abilityBonus[4]);
        break;
    case 2:case 5:case 7:case 10:case 12:case 25:case 34:
        spinAbility->setValue(abilityBonus[5]);
        break;
    default:
        break;
    }
    updateTotal();
}

void SkillRow::resetClassSkill()
{
    if (checkCS->isChecked())
    {
        checkCS->setChecked(false);
    }
}

void SkillRow::resetRank()
{
    spinRank->setValue(0);
}

int SkillRow::getRank()
{
    return spinRank->value();
}

int SkillRow::getTotal()
{
    return spinTotal->value();
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
