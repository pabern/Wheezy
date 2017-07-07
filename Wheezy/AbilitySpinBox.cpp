#include "AbilitySpinBox.hpp"

AbilitySpinBox::AbilitySpinBox()
{
    setValue(0);
    setReadOnly(true);
    setButtonSymbols(QAbstractSpinBox::NoButtons);
    setAlignment(Qt::AlignHCenter);
    setFixedWidth(35);
    setMinimum(-10);
}

AbilitySpinBox::AbilitySpinBox(QString)
{
    setValue(14);
    setMinimum(4);
    setMaximum(24);
    setAlignment(Qt::AlignHCenter);
    setFixedWidth(45);
}
