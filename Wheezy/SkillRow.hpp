#ifndef SKILLROW_HPP
#define SKILLROW_HPP

#include <QtWidgets>

class SkillRow: public QHBoxLayout
{
    Q_OBJECT

public:
    SkillRow(QString skill);
    void updateRow(bool classSkill, int abilityBonus[], int index);
    void resetClassSkill();
    void resetRank();
    int getRank();
    int getTotal();

    QSpinBox *spinRank;
public slots:
    void updateTotal();

private:
    QCheckBox *checkCS;
    QLabel *name;
    QSpinBox *spinClass;
    QSpinBox *spinAbility;
    QSpinBox *spinTotal;
};

#endif // SKILLROW_HPP
