/****************************************************************************
** Meta object code from reading C++ file 'rock_scissors_paper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rock_scissors_paper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rock_scissors_paper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Rock_Scissors_Paper_t {
    QByteArrayData data[13];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rock_Scissors_Paper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rock_Scissors_Paper_t qt_meta_stringdata_Rock_Scissors_Paper = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Rock_Scissors_Paper"
QT_MOC_LITERAL(1, 20, 11), // "moneyChange"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 25), // "on_ProgressButton_clicked"
QT_MOC_LITERAL(4, 59, 21), // "change_opponent_image"
QT_MOC_LITERAL(5, 81, 15), // "on_Rock_clicked"
QT_MOC_LITERAL(6, 97, 19), // "on_Scissors_clicked"
QT_MOC_LITERAL(7, 117, 16), // "on_Paper_clicked"
QT_MOC_LITERAL(8, 134, 9), // "win_event"
QT_MOC_LITERAL(9, 144, 10), // "lose_event"
QT_MOC_LITERAL(10, 155, 9), // "tie_event"
QT_MOC_LITERAL(11, 165, 23), // "on_Retry_Button_clicked"
QT_MOC_LITERAL(12, 189, 25) // "on_Get_out_Button_clicked"

    },
    "Rock_Scissors_Paper\0moneyChange\0\0"
    "on_ProgressButton_clicked\0"
    "change_opponent_image\0on_Rock_clicked\0"
    "on_Scissors_clicked\0on_Paper_clicked\0"
    "win_event\0lose_event\0tie_event\0"
    "on_Retry_Button_clicked\0"
    "on_Get_out_Button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rock_Scissors_Paper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
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

void Rock_Scissors_Paper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Rock_Scissors_Paper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moneyChange(); break;
        case 1: _t->on_ProgressButton_clicked(); break;
        case 2: _t->change_opponent_image(); break;
        case 3: _t->on_Rock_clicked(); break;
        case 4: _t->on_Scissors_clicked(); break;
        case 5: _t->on_Paper_clicked(); break;
        case 6: _t->win_event(); break;
        case 7: _t->lose_event(); break;
        case 8: _t->tie_event(); break;
        case 9: _t->on_Retry_Button_clicked(); break;
        case 10: _t->on_Get_out_Button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Rock_Scissors_Paper::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rock_Scissors_Paper::moneyChange)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Rock_Scissors_Paper::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Rock_Scissors_Paper.data,
    qt_meta_data_Rock_Scissors_Paper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Rock_Scissors_Paper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rock_Scissors_Paper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rock_Scissors_Paper.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Rock_Scissors_Paper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Rock_Scissors_Paper::moneyChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
