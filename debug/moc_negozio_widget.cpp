/****************************************************************************
** Meta object code from reading C++ file 'negozio_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/negozio_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'negozio_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Negozio_widget_t {
    QByteArrayData data[6];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Negozio_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Negozio_widget_t qt_meta_stringdata_Negozio_widget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Negozio_widget"
QT_MOC_LITERAL(1, 15, 21), // "personaggioAcquistato"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "newMatch"
QT_MOC_LITERAL(4, 47, 15), // "stampaDaNegozio"
QT_MOC_LITERAL(5, 63, 13) // "proseguiMatch"

    },
    "Negozio_widget\0personaggioAcquistato\0"
    "\0newMatch\0stampaDaNegozio\0proseguiMatch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Negozio_widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   38,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void Negozio_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Negozio_widget *_t = static_cast<Negozio_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->personaggioAcquistato((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->newMatch(); break;
        case 2: _t->stampaDaNegozio((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->proseguiMatch(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Negozio_widget::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Negozio_widget::personaggioAcquistato)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Negozio_widget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Negozio_widget::newMatch)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Negozio_widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Negozio_widget.data,
      qt_meta_data_Negozio_widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Negozio_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Negozio_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Negozio_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Negozio_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Negozio_widget::personaggioAcquistato(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Negozio_widget::newMatch()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
