/****************************************************************************
** Meta object code from reading C++ file 'speedquiz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../speedquiz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'speedquiz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpeedQuiz_t {
    QByteArrayData data[11];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpeedQuiz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpeedQuiz_t qt_meta_stringdata_SpeedQuiz = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SpeedQuiz"
QT_MOC_LITERAL(1, 10, 11), // "moneyChange"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 25), // "on_progressButton_clicked"
QT_MOC_LITERAL(4, 49, 8), // "TimeIsUp"
QT_MOC_LITERAL(5, 58, 19), // "on_Answer_1_clicked"
QT_MOC_LITERAL(6, 78, 19), // "on_Answer_2_clicked"
QT_MOC_LITERAL(7, 98, 19), // "on_Answer_3_clicked"
QT_MOC_LITERAL(8, 118, 19), // "on_Answer_4_clicked"
QT_MOC_LITERAL(9, 138, 19), // "on_GameOver_clicked"
QT_MOC_LITERAL(10, 158, 16) // "on_Retry_clicked"

    },
    "SpeedQuiz\0moneyChange\0\0on_progressButton_clicked\0"
    "TimeIsUp\0on_Answer_1_clicked\0"
    "on_Answer_2_clicked\0on_Answer_3_clicked\0"
    "on_Answer_4_clicked\0on_GameOver_clicked\0"
    "on_Retry_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpeedQuiz[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void SpeedQuiz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpeedQuiz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moneyChange(); break;
        case 1: _t->on_progressButton_clicked(); break;
        case 2: _t->TimeIsUp(); break;
        case 3: _t->on_Answer_1_clicked(); break;
        case 4: _t->on_Answer_2_clicked(); break;
        case 5: _t->on_Answer_3_clicked(); break;
        case 6: _t->on_Answer_4_clicked(); break;
        case 7: _t->on_GameOver_clicked(); break;
        case 8: _t->on_Retry_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpeedQuiz::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpeedQuiz::moneyChange)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SpeedQuiz::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_SpeedQuiz.data,
    qt_meta_data_SpeedQuiz,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SpeedQuiz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpeedQuiz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpeedQuiz.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SpeedQuiz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SpeedQuiz::moneyChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
