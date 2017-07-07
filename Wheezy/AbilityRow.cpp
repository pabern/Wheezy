#include "AbilityRow.hpp"

using namespace std;

AbilityRow::AbilityRow(QString ability)
{
    // Radio button for selection when half-X or human
    radio = new QRadioButton(ability);
    radio->setFixedWidth(45);

    // Editable spin box for roll input
    spinRoll = new AbilitySpinBox("Roll");

    // Other un-editable spin boxes for modifiers and totals
    spinRace = new AbilitySpinBox;
    spinValue = new AbilitySpinBox;
    spinBonus = new AbilitySpinBox;

    addWidget(radio);
    addWidget(spinRoll);
    addWidget(spinRace);
    addWidget(spinValue);
    addWidget(spinBonus);
}

void AbilityRow::setRaceValue(int value)
{
    spinRace->setValue(value);
}

bool AbilityRow::isChecked()
{
    return radio->isChecked();
}

void AbilityRow::updateTotalsAndBonus()
{
    spinValue->setValue(spinRoll->value()+spinRace->value());
    spinBonus->setValue((spinValue->value()/2) - 5 + (spinValue->value()%2));
}

int AbilityRow::getBonus()
{
    return spinBonus->value();
}
