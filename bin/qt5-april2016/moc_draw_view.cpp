/****************************************************************************
** Meta object code from reading C++ file 'draw_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/draw/draw_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'draw_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_draw_view_t {
    QByteArrayData data[9];
    char stringdata[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_draw_view_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_draw_view_t qt_meta_stringdata_draw_view = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 12),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 20),
QT_MOC_LITERAL(4, 45, 14),
QT_MOC_LITERAL(5, 60, 6),
QT_MOC_LITERAL(6, 67, 7),
QT_MOC_LITERAL(7, 75, 10),
QT_MOC_LITERAL(8, 86, 11)
    },
    "draw_view\0sceneClicked\0\0preview_path_cliqued\0"
    "QGraphicsItem*\0zoomIn\0zoomOut\0rotateLeft\0"
    "rotateRight\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_draw_view[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       3,    1,   47,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   50,    2, 0x0a,
       6,    0,   51,    2, 0x0a,
       7,    0,   52,    2, 0x0a,
       8,    0,   53,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void draw_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        draw_view *_t = static_cast<draw_view *>(_o);
        switch (_id) {
        case 0: _t->sceneClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->preview_path_cliqued((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 2: _t->zoomIn(); break;
        case 3: _t->zoomOut(); break;
        case 4: _t->rotateLeft(); break;
        case 5: _t->rotateRight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (draw_view::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&draw_view::sceneClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (draw_view::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&draw_view::preview_path_cliqued)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject draw_view::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_draw_view.data,
      qt_meta_data_draw_view,  qt_static_metacall, 0, 0}
};


const QMetaObject *draw_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *draw_view::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_draw_view.stringdata))
        return static_cast<void*>(const_cast< draw_view*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int draw_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void draw_view::sceneClicked(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void draw_view::preview_path_cliqued(QGraphicsItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
