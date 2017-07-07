#ifndef ABILITYROW_HPP
#define ABILITYROW_HPP

#include <QtWidgets>
#include <fstream>
#include <limits>
#include <string>
#include "AbilitySpinBox.hpp"

class AbilityRow: public QHBoxLayout
{
    Q_OBJECT

public:
    AbilityRow(QString ability);
    void setRaceValue(int value);
    bool isChecked();
    void updateTotalsAndBonus();
    int getBonus();

    QRadioButton *radio;
    AbilitySpinBox *spinRoll;

private:
    AbilitySpinBox *spinRace;
    AbilitySpinBox *spinValue;
    AbilitySpinBox *spinBonus;
};

#endif // ABILITYROW_HPP
