#ifndef SKILLROW_HPP
#define SKILLROW_HPP

#include <QtWidgets>

class SkillRow : public QHBoxLayout
{
    Q_OBJECT

public:
    SkillRow(QString skill, int index);
    void updateRow(int currentClass, int bonusSTR, int bonusDEX, int bonusCON, int bonusINT, int bonusWIS, int bonusCHA);
    void resetClassSkill();

public slots:
    void updateTotal();

private:
    QCheckBox *checkCS;
    QLabel *name;
    QSpinBox *spinRank;
    QSpinBox *spinClass;
    QSpinBox *spinAbility;
    QSpinBox *spinTotal;
    int skillIndex;
};

#endif // SKILLROW_HPP
