#include "AbilitySpinBox.hpp"

AbilitySpinBox::AbilitySpinBox()
{
    setValue(0);
    setReadOnly(true);
    setButtonSymbols(QAbstractSpinBox::NoButtons);
    setAlignment(Qt::AlignHCenter);
    setMinimum(-10);
}