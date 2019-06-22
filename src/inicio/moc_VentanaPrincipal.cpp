/****************************************************************************
** Meta object code from reading C++ file 'VentanaPrincipal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "VentanaPrincipal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VentanaPrincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VentanaPrincipal_t {
    QByteArrayData data[14];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaPrincipal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaPrincipal_t qt_meta_stringdata_VentanaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VentanaPrincipal"
QT_MOC_LITERAL(1, 17, 17), // "on_submit_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 26), // "on_crearSalaButton_clicked"
QT_MOC_LITERAL(4, 63, 20), // "on_continuar_clicked"
QT_MOC_LITERAL(5, 84, 27), // "on_elegirSalaButton_clicked"
QT_MOC_LITERAL(6, 112, 25), // "on_comenzarButton_clicked"
QT_MOC_LITERAL(7, 138, 24), // "on_comenzarJuego_clicked"
QT_MOC_LITERAL(8, 163, 21), // "on_editarMapa_clicked"
QT_MOC_LITERAL(9, 185, 25), // "on_mapa_cellDoubleClicked"
QT_MOC_LITERAL(10, 211, 3), // "row"
QT_MOC_LITERAL(11, 215, 6), // "column"
QT_MOC_LITERAL(12, 222, 22), // "on_guardarMapa_clicked"
QT_MOC_LITERAL(13, 245, 21) // "on_pushButton_clicked"

    },
    "VentanaPrincipal\0on_submit_clicked\0\0"
    "on_crearSalaButton_clicked\0"
    "on_continuar_clicked\0on_elegirSalaButton_clicked\0"
    "on_comenzarButton_clicked\0"
    "on_comenzarJuego_clicked\0on_editarMapa_clicked\0"
    "on_mapa_cellDoubleClicked\0row\0column\0"
    "on_guardarMapa_clicked\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    2,   71,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VentanaPrincipal *_t = static_cast<VentanaPrincipal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_submit_clicked(); break;
        case 1: _t->on_crearSalaButton_clicked(); break;
        case 2: _t->on_continuar_clicked(); break;
        case 3: _t->on_elegirSalaButton_clicked(); break;
        case 4: _t->on_comenzarButton_clicked(); break;
        case 5: _t->on_comenzarJuego_clicked(); break;
        case 6: _t->on_editarMapa_clicked(); break;
        case 7: _t->on_mapa_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->on_guardarMapa_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject VentanaPrincipal::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VentanaPrincipal.data,
      qt_meta_data_VentanaPrincipal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal.stringdata0))
        return static_cast<void*>(const_cast< VentanaPrincipal*>(this));
    return QWidget::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
