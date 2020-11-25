/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_getSQLit_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "on_data"
QT_MOC_LITERAL(4, 40, 17), // "on_xbar_1_clicked"
QT_MOC_LITERAL(5, 58, 17), // "on_xbar_2_clicked"
QT_MOC_LITERAL(6, 76, 17), // "on_zizu_1_clicked"
QT_MOC_LITERAL(7, 94, 17), // "on_zizu_2_clicked"
QT_MOC_LITERAL(8, 112, 22), // "on_zhifangtu_1_clicked"
QT_MOC_LITERAL(9, 135, 22), // "on_zhifangtu_2_clicked"
QT_MOC_LITERAL(10, 158, 20), // "on_jichatu_1_clicked"
QT_MOC_LITERAL(11, 179, 20), // "on_jichatu_2_clicked"
QT_MOC_LITERAL(12, 200, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(13, 224, 18), // "on_zhengya_clicked"
QT_MOC_LITERAL(14, 243, 15) // "on_fuya_clicked"

    },
    "MainWindow\0on_getSQLit_clicked\0\0on_data\0"
    "on_xbar_1_clicked\0on_xbar_2_clicked\0"
    "on_zizu_1_clicked\0on_zizu_2_clicked\0"
    "on_zhifangtu_1_clicked\0on_zhifangtu_2_clicked\0"
    "on_jichatu_1_clicked\0on_jichatu_2_clicked\0"
    "on_pushButton_4_clicked\0on_zhengya_clicked\0"
    "on_fuya_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_getSQLit_clicked(); break;
        case 1: _t->on_data(); break;
        case 2: _t->on_xbar_1_clicked(); break;
        case 3: _t->on_xbar_2_clicked(); break;
        case 4: _t->on_zizu_1_clicked(); break;
        case 5: _t->on_zizu_2_clicked(); break;
        case 6: _t->on_zhifangtu_1_clicked(); break;
        case 7: _t->on_zhifangtu_2_clicked(); break;
        case 8: _t->on_jichatu_1_clicked(); break;
        case 9: _t->on_jichatu_2_clicked(); break;
        case 10: _t->on_pushButton_4_clicked(); break;
        case 11: _t->on_zhengya_clicked(); break;
        case 12: _t->on_fuya_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
