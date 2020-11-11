/****************************************************************************
** Meta object code from reading C++ file 'schoolplanner.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "schoolplanner.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schoolplanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SchoolPlanner_t {
    QByteArrayData data[15];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SchoolPlanner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SchoolPlanner_t qt_meta_stringdata_SchoolPlanner = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SchoolPlanner"
QT_MOC_LITERAL(1, 14, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(4, 61, 4), // "arg1"
QT_MOC_LITERAL(5, 66, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(6, 93, 5), // "index"
QT_MOC_LITERAL(7, 99, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(8, 126, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(9, 150, 24), // "on_actionRooms_triggered"
QT_MOC_LITERAL(10, 175, 25), // "on_actionGroups_triggered"
QT_MOC_LITERAL(11, 201, 27), // "on_actionTeachers_triggered"
QT_MOC_LITERAL(12, 229, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(13, 252, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(14, 276, 26) // "on_actionClasses_triggered"

    },
    "SchoolPlanner\0on_actionOpen_triggered\0"
    "\0on_comboBox_activated\0arg1\0"
    "on_tableView_doubleClicked\0index\0"
    "on_actionSave_As_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionRooms_triggered\0"
    "on_actionGroups_triggered\0"
    "on_actionTeachers_triggered\0"
    "on_actionNew_triggered\0on_actionExit_triggered\0"
    "on_actionClasses_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SchoolPlanner[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       5,    1,   73,    2, 0x08 /* Private */,
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SchoolPlanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SchoolPlanner *_t = static_cast<SchoolPlanner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionOpen_triggered(); break;
        case 1: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_actionSave_As_triggered(); break;
        case 4: _t->on_actionSave_triggered(); break;
        case 5: _t->on_actionRooms_triggered(); break;
        case 6: _t->on_actionGroups_triggered(); break;
        case 7: _t->on_actionTeachers_triggered(); break;
        case 8: _t->on_actionNew_triggered(); break;
        case 9: _t->on_actionExit_triggered(); break;
        case 10: _t->on_actionClasses_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject SchoolPlanner::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SchoolPlanner.data,
      qt_meta_data_SchoolPlanner,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SchoolPlanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SchoolPlanner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SchoolPlanner.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SchoolPlanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
