/****************************************************************************
** Meta object code from reading C++ file 'game_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../game_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Game_window_t {
    QByteArrayData data[22];
    char stringdata0[372];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_window_t qt_meta_stringdata_Game_window = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Game_window"
QT_MOC_LITERAL(1, 12, 14), // "goToMainWindow"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "showCurrentStat"
QT_MOC_LITERAL(4, 44, 27), // "showCurrentDateFatigueMoney"
QT_MOC_LITERAL(5, 72, 22), // "on_quit_button_clicked"
QT_MOC_LITERAL(6, 95, 15), // "setPetStat_show"
QT_MOC_LITERAL(7, 111, 21), // "DateFatigueMoney_show"
QT_MOC_LITERAL(8, 133, 17), // "on_market_clicked"
QT_MOC_LITERAL(9, 151, 8), // "get_item"
QT_MOC_LITERAL(10, 160, 4), // "Item"
QT_MOC_LITERAL(11, 165, 4), // "item"
QT_MOC_LITERAL(12, 170, 20), // "on_inventory_clicked"
QT_MOC_LITERAL(13, 191, 20), // "on_mini_game_clicked"
QT_MOC_LITERAL(14, 212, 8), // "use_item"
QT_MOC_LITERAL(15, 221, 7), // "itemNum"
QT_MOC_LITERAL(16, 229, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(17, 253, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(18, 277, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(19, 301, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(20, 325, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(21, 349, 22) // "on_save_button_clicked"

    },
    "Game_window\0goToMainWindow\0\0showCurrentStat\0"
    "showCurrentDateFatigueMoney\0"
    "on_quit_button_clicked\0setPetStat_show\0"
    "DateFatigueMoney_show\0on_market_clicked\0"
    "get_item\0Item\0item\0on_inventory_clicked\0"
    "on_mini_game_clicked\0use_item\0itemNum\0"
    "on_pushButton_4_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_8_clicked\0on_save_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game_window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    1,  106,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,
      20,    0,  118,    2, 0x08 /* Private */,
      21,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Game_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goToMainWindow(); break;
        case 1: _t->showCurrentStat(); break;
        case 2: _t->showCurrentDateFatigueMoney(); break;
        case 3: _t->on_quit_button_clicked(); break;
        case 4: _t->setPetStat_show(); break;
        case 5: _t->DateFatigueMoney_show(); break;
        case 6: _t->on_market_clicked(); break;
        case 7: _t->get_item((*reinterpret_cast< Item(*)>(_a[1]))); break;
        case 8: _t->on_inventory_clicked(); break;
        case 9: _t->on_mini_game_clicked(); break;
        case 10: _t->use_item((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_4_clicked(); break;
        case 12: _t->on_pushButton_6_clicked(); break;
        case 13: _t->on_pushButton_7_clicked(); break;
        case 14: _t->on_pushButton_5_clicked(); break;
        case 15: _t->on_pushButton_8_clicked(); break;
        case 16: _t->on_save_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Game_window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game_window::goToMainWindow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Game_window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game_window::showCurrentStat)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Game_window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game_window::showCurrentDateFatigueMoney)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Game_window::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Game_window.data,
    qt_meta_data_Game_window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Game_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Game_window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Game_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Game_window::goToMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Game_window::showCurrentStat()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Game_window::showCurrentDateFatigueMoney()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
