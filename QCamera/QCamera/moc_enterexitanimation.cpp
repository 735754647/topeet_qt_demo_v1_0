/****************************************************************************
** Meta object code from reading C++ file 'enterexitanimation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "enterexitanimation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enterexitanimation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Enterexitanimation_t {
    QByteArrayData data[5];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Enterexitanimation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Enterexitanimation_t qt_meta_stringdata_Enterexitanimation = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Enterexitanimation"
QT_MOC_LITERAL(1, 19, 10), // "slot_close"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "exit_annimation"
QT_MOC_LITERAL(4, 47, 11) // "slot_update"

    },
    "Enterexitanimation\0slot_close\0\0"
    "exit_annimation\0slot_update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Enterexitanimation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Enterexitanimation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Enterexitanimation *_t = static_cast<Enterexitanimation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_close(); break;
        case 1: _t->exit_annimation(); break;
        case 2: _t->slot_update(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Enterexitanimation::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Enterexitanimation.data,
      qt_meta_data_Enterexitanimation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Enterexitanimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enterexitanimation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Enterexitanimation.stringdata0))
        return static_cast<void*>(const_cast< Enterexitanimation*>(this));
    return QWidget::qt_metacast(_clname);
}

int Enterexitanimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
