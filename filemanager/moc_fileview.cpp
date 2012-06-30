/****************************************************************************
** Meta object code from reading C++ file 'fileview.h'
**
** Created: Thu Jul 28 23:25:54 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fileview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fileview[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x0a,
      45,   10,    9,    9, 0x0a,
      74,    9,    9,    9, 0x0a,
      88,    9,    9,    9, 0x0a,
     100,    9,    9,    9, 0x0a,
     112,    9,    9,    9, 0x0a,
     127,    9,    9,    9, 0x0a,
     140,    9,    9,    9, 0x0a,
     154,    9,    9,    9, 0x0a,
     173,    9,    9,    9, 0x0a,
     193,    9,    9,    9, 0x0a,
     214,    9,    9,    9, 0x0a,
     234,    9,    9,    9, 0x0a,
     248,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_fileview[] = {
    "fileview\0\0index\0listDoubleClick(QModelIndex)\0"
    "treeDoubleClick(QModelIndex)\0detailClick()\0"
    "listClick()\0backClick()\0forwardClick()\0"
    "aheadClick()\0displayMenu()\0"
    "triggerdelAction()\0triggercopyAction()\0"
    "triggerpasteAction()\0triggeropenAction()\0"
    "changeModel()\0on_closeButton_clicked()\0"
};

const QMetaObject fileview::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fileview,
      qt_meta_data_fileview, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fileview::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fileview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fileview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fileview))
        return static_cast<void*>(const_cast< fileview*>(this));
    return QWidget::qt_metacast(_clname);
}

int fileview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: listDoubleClick((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: treeDoubleClick((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: detailClick(); break;
        case 3: listClick(); break;
        case 4: backClick(); break;
        case 5: forwardClick(); break;
        case 6: aheadClick(); break;
        case 7: displayMenu(); break;
        case 8: triggerdelAction(); break;
        case 9: triggercopyAction(); break;
        case 10: triggerpasteAction(); break;
        case 11: triggeropenAction(); break;
        case 12: changeModel(); break;
        case 13: on_closeButton_clicked(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
