/****************************************************************************
** Meta object code from reading C++ file 'draw_scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/draw/draw_scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'draw_scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_draw_scene_t {
    QByteArrayData data[10];
    char stringdata[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_draw_scene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_draw_scene_t qt_meta_stringdata_draw_scene = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 20),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 14),
QT_MOC_LITERAL(4, 48, 10),
QT_MOC_LITERAL(5, 59, 18),
QT_MOC_LITERAL(6, 78, 13),
QT_MOC_LITERAL(7, 92, 4),
QT_MOC_LITERAL(8, 97, 8),
QT_MOC_LITERAL(9, 106, 9)
    },
    "draw_scene\0preview_path_cliqued\0\0"
    "QGraphicsItem*\0item_ready\0QGraphicsPathItem*\0"
    "draw_ziguigui\0nada\0drawPath\0itemtoadd\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_draw_scene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       4,    1,   47,    2, 0x06,
       4,    1,   50,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   53,    2, 0x0a,
       8,    1,   56,    2, 0x0a,
       8,    1,   59,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, 0x80000000 | 5,    9,

       0        // eod
};

void draw_scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        draw_scene *_t = static_cast<draw_scene *>(_o);
        switch (_id) {
        case 0: _t->preview_path_cliqued((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 1: _t->item_ready((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 2: _t->item_ready((*reinterpret_cast< QGraphicsPathItem*(*)>(_a[1]))); break;
        case 3: _t->draw_ziguigui((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->drawPath((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 5: _t->drawPath((*reinterpret_cast< QGraphicsPathItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (draw_scene::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&draw_scene::preview_path_cliqued)) {
                *result = 0;
            }
        }
        {
            typedef void (draw_scene::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&draw_scene::item_ready)) {
                *result = 1;
            }
        }
        {
            typedef void (draw_scene::*_t)(QGraphicsPathItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&draw_scene::item_ready)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject draw_scene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_draw_scene.data,
      qt_meta_data_draw_scene,  qt_static_metacall, 0, 0}
};


const QMetaObject *draw_scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *draw_scene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_draw_scene.stringdata))
        return static_cast<void*>(const_cast< draw_scene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int draw_scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void draw_scene::preview_path_cliqued(QGraphicsItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void draw_scene::item_ready(QGraphicsItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void draw_scene::item_ready(QGraphicsPathItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
