/****************************************************************************
** Meta object code from reading C++ file 'systeme.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../class/systeme.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systeme.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_systeme_t {
    QByteArrayData data[10];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_systeme_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_systeme_t qt_meta_stringdata_systeme = {
    {
QT_MOC_LITERAL(0, 0, 7), // "systeme"
QT_MOC_LITERAL(1, 8, 16), // "changeStateVanne"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "string"
QT_MOC_LITERAL(4, 33, 8), // "nomVanne"
QT_MOC_LITERAL(5, 42, 16), // "changeStatePompe"
QT_MOC_LITERAL(6, 59, 8), // "nomPompe"
QT_MOC_LITERAL(7, 68, 9), // "emptyTank"
QT_MOC_LITERAL(8, 78, 7), // "nomTank"
QT_MOC_LITERAL(9, 86, 10) // "breakPompe"

    },
    "systeme\0changeStateVanne\0\0string\0"
    "nomVanne\0changeStatePompe\0nomPompe\0"
    "emptyTank\0nomTank\0breakPompe"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_systeme[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
       9,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, 0x80000000 | 3,    6,

       0        // eod
};

void systeme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<systeme *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeStateVanne((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->changeStatePompe((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->emptyTank((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 3: _t->breakPompe((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject systeme::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_systeme.data,
    qt_meta_data_systeme,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *systeme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *systeme::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_systeme.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int systeme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
