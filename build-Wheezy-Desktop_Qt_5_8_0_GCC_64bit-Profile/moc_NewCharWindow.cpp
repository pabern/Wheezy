/****************************************************************************
** Meta object code from reading C++ file 'NewCharWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Wheezy/NewCharWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewCharWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NewCharWindow_t {
    QByteArrayData data[15];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewCharWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewCharWindow_t qt_meta_stringdata_NewCharWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NewCharWindow"
QT_MOC_LITERAL(1, 14, 16), // "updateRaceChoice"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "updateAbilities"
QT_MOC_LITERAL(4, 48, 17), // "updateClassChoice"
QT_MOC_LITERAL(5, 66, 15), // "updateAlignment"
QT_MOC_LITERAL(6, 82, 14), // "std::ifstream&"
QT_MOC_LITERAL(7, 97, 4), // "file"
QT_MOC_LITERAL(8, 102, 12), // "updateHitDie"
QT_MOC_LITERAL(9, 115, 10), // "updateGold"
QT_MOC_LITERAL(10, 126, 11), // "updateFeats"
QT_MOC_LITERAL(11, 138, 11), // "updateSkill"
QT_MOC_LITERAL(12, 150, 15), // "resetClassSkill"
QT_MOC_LITERAL(13, 166, 10), // "resetRanks"
QT_MOC_LITERAL(14, 177, 15) // "updateRanksLeft"

    },
    "NewCharWindow\0updateRaceChoice\0\0"
    "updateAbilities\0updateClassChoice\0"
    "updateAlignment\0std::ifstream&\0file\0"
    "updateHitDie\0updateGold\0updateFeats\0"
    "updateSkill\0resetClassSkill\0resetRanks\0"
    "updateRanksLeft"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewCharWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       5,    1,   78,    2, 0x0a /* Public */,
       8,    1,   81,    2, 0x0a /* Public */,
       9,    1,   84,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      12,    0,   93,    2, 0x0a /* Public */,
      13,    0,   94,    2, 0x0a /* Public */,
      14,    0,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewCharWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewCharWindow *_t = static_cast<NewCharWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateRaceChoice(); break;
        case 1: _t->updateAbilities(); break;
        case 2: _t->updateClassChoice(); break;
        case 3: _t->updateAlignment(); break;
        case 4: _t->updateAlignment((*reinterpret_cast< std::ifstream(*)>(_a[1]))); break;
        case 5: _t->updateHitDie((*reinterpret_cast< std::ifstream(*)>(_a[1]))); break;
        case 6: _t->updateGold((*reinterpret_cast< std::ifstream(*)>(_a[1]))); break;
        case 7: _t->updateFeats((*reinterpret_cast< std::ifstream(*)>(_a[1]))); break;
        case 8: _t->updateSkill((*reinterpret_cast< std::ifstream(*)>(_a[1]))); break;
        case 9: _t->resetClassSkill(); break;
        case 10: _t->resetRanks(); break;
        case 11: _t->updateRanksLeft(); break;
        default: ;
        }
    }
}

const QMetaObject NewCharWindow::staticMetaObject = {
    { &QHBoxLayout::staticMetaObject, qt_meta_stringdata_NewCharWindow.data,
      qt_meta_data_NewCharWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewCharWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewCharWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewCharWindow.stringdata0))
        return static_cast<void*>(const_cast< NewCharWindow*>(this));
    return QHBoxLayout::qt_metacast(_clname);
}

int NewCharWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHBoxLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
