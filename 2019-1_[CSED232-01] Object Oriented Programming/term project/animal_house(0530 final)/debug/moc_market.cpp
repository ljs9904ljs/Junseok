/****************************************************************************
** Meta object code from reading C++ file 'market.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../market.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'market.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_market_t {
    QByteArrayData data[19];
    char stringdata0[356];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_market_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_market_t qt_meta_stringdata_market = {
    {
QT_MOC_LITERAL(0, 0, 6), // "market"
QT_MOC_LITERAL(1, 7, 7), // "buyItem"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 4), // "Item"
QT_MOC_LITERAL(4, 21, 4), // "item"
QT_MOC_LITERAL(5, 26, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(6, 49, 28), // "on_buy_cold_medicine_clicked"
QT_MOC_LITERAL(7, 78, 21), // "on_buy_peptic_clicked"
QT_MOC_LITERAL(8, 100, 22), // "on_buy_vita500_clicked"
QT_MOC_LITERAL(9, 123, 28), // "on_buy_sleeping_pill_clicked"
QT_MOC_LITERAL(10, 152, 22), // "on_buy_bicycle_clicked"
QT_MOC_LITERAL(11, 175, 21), // "on_buy_clover_clicked"
QT_MOC_LITERAL(12, 197, 21), // "on_buy_effort_clicked"
QT_MOC_LITERAL(13, 219, 22), // "on_buy_ginseng_clicked"
QT_MOC_LITERAL(14, 242, 20), // "on_buy_Lotto_clicked"
QT_MOC_LITERAL(15, 263, 23), // "on_buy_airplane_clicked"
QT_MOC_LITERAL(16, 287, 23), // "on_buy_calculus_clicked"
QT_MOC_LITERAL(17, 311, 22), // "on_buy_steriod_clicked"
QT_MOC_LITERAL(18, 334, 21) // "on_buy_honorP_clicked"

    },
    "market\0buyItem\0\0Item\0item\0"
    "on_back_button_clicked\0"
    "on_buy_cold_medicine_clicked\0"
    "on_buy_peptic_clicked\0on_buy_vita500_clicked\0"
    "on_buy_sleeping_pill_clicked\0"
    "on_buy_bicycle_clicked\0on_buy_clover_clicked\0"
    "on_buy_effort_clicked\0on_buy_ginseng_clicked\0"
    "on_buy_Lotto_clicked\0on_buy_airplane_clicked\0"
    "on_buy_calculus_clicked\0on_buy_steriod_clicked\0"
    "on_buy_honorP_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_market[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void market::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<market *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buyItem((*reinterpret_cast< Item(*)>(_a[1]))); break;
        case 1: _t->on_back_button_clicked(); break;
        case 2: _t->on_buy_cold_medicine_clicked(); break;
        case 3: _t->on_buy_peptic_clicked(); break;
        case 4: _t->on_buy_vita500_clicked(); break;
        case 5: _t->on_buy_sleeping_pill_clicked(); break;
        case 6: _t->on_buy_bicycle_clicked(); break;
        case 7: _t->on_buy_clover_clicked(); break;
        case 8: _t->on_buy_effort_clicked(); break;
        case 9: _t->on_buy_ginseng_clicked(); break;
        case 10: _t->on_buy_Lotto_clicked(); break;
        case 11: _t->on_buy_airplane_clicked(); break;
        case 12: _t->on_buy_calculus_clicked(); break;
        case 13: _t->on_buy_steriod_clicked(); break;
        case 14: _t->on_buy_honorP_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (market::*)(Item );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&market::buyItem)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject market::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_market.data,
    qt_meta_data_market,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *market::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *market::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_market.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int market::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void market::buyItem(Item _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
