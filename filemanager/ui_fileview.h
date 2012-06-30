/********************************************************************************
** Form generated from reading UI file 'fileview.ui'
**
** Created: Thu Jul 28 23:25:47 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEVIEW_H
#define UI_FILEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fileview
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *backButton;
    QToolButton *forwardButton;
    QToolButton *aheadButton;
    QToolButton *listButton;
    QToolButton *detailButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QListView *listView;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *closeButton;

    void setupUi(QWidget *fileview)
    {
        if (fileview->objectName().isEmpty())
            fileview->setObjectName(QString::fromUtf8("fileview"));
        fileview->resize(480, 243);
        verticalLayout = new QVBoxLayout(fileview);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backButton = new QToolButton(fileview);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setEnabled(true);
        backButton->setStyleSheet(QString::fromUtf8("border-style: flat;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/buttons/images/left-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(24, 24));
        backButton->setAutoRaise(true);

        horizontalLayout->addWidget(backButton);

        forwardButton = new QToolButton(fileview);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        forwardButton->setStyleSheet(QString::fromUtf8("border-style: flat;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/buttons/images/right-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon1);
        forwardButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(forwardButton);

        aheadButton = new QToolButton(fileview);
        aheadButton->setObjectName(QString::fromUtf8("aheadButton"));
        aheadButton->setStyleSheet(QString::fromUtf8("border-style: flat;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/buttons/images/up-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        aheadButton->setIcon(icon2);
        aheadButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(aheadButton);

        listButton = new QToolButton(fileview);
        listButton->setObjectName(QString::fromUtf8("listButton"));
        listButton->setStyleSheet(QString::fromUtf8("border-style: flat;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/buttons/images/viewlist-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        listButton->setIcon(icon3);
        listButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(listButton);

        detailButton = new QToolButton(fileview);
        detailButton->setObjectName(QString::fromUtf8("detailButton"));
        detailButton->setStyleSheet(QString::fromUtf8("border-style: flat;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/buttons/images/viewdetailed-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        detailButton->setIcon(icon4);
        detailButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(detailButton);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(fileview);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listView = new QListView(page);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        treeView = new QTreeView(page_2);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_3->addWidget(treeView);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        closeButton = new QPushButton(fileview);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setFlat(false);

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(fileview);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fileview);
    } // setupUi

    void retranslateUi(QWidget *fileview)
    {
        fileview->setWindowTitle(QApplication::translate("fileview", "Widget", 0, QApplication::UnicodeUTF8));
        backButton->setText(QString());
        forwardButton->setText(QString());
        aheadButton->setText(QString());
        listButton->setText(QString());
        detailButton->setText(QString());
        closeButton->setText(QApplication::translate("fileview", "exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class fileview: public Ui_fileview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEVIEW_H
