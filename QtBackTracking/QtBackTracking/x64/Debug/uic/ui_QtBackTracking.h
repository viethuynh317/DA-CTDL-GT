/********************************************************************************
** Form generated from reading UI file 'QtBackTracking.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTBACKTRACKING_H
#define UI_QTBACKTRACKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtBackTrackingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtBackTrackingClass)
    {
        if (QtBackTrackingClass->objectName().isEmpty())
            QtBackTrackingClass->setObjectName(QString::fromUtf8("QtBackTrackingClass"));
        QtBackTrackingClass->resize(600, 400);
        menuBar = new QMenuBar(QtBackTrackingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtBackTrackingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtBackTrackingClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtBackTrackingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtBackTrackingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtBackTrackingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtBackTrackingClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtBackTrackingClass->setStatusBar(statusBar);

        retranslateUi(QtBackTrackingClass);

        QMetaObject::connectSlotsByName(QtBackTrackingClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtBackTrackingClass)
    {
        QtBackTrackingClass->setWindowTitle(QApplication::translate("QtBackTrackingClass", "QtBackTracking", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtBackTrackingClass: public Ui_QtBackTrackingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTBACKTRACKING_H
