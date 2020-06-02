/********************************************************************************
** Form generated from reading UI file 'battaglia.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTAGLIA_H
#define UI_BATTAGLIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Battaglia
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;

    void setupUi(QWidget *Battaglia)
    {
        if (Battaglia->objectName().isEmpty())
            Battaglia->setObjectName(QStringLiteral("Battaglia"));
        Battaglia->resize(410, 320);
        verticalLayoutWidget_2 = new QWidget(Battaglia);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(17, 20, 371, 281));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_6 = new QPushButton(verticalLayoutWidget_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_2->addWidget(pushButton_6, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(verticalLayoutWidget_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_2->addWidget(pushButton_7, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_2->addWidget(pushButton_8, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_3->addLayout(verticalLayout, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);


        retranslateUi(Battaglia);

        QMetaObject::connectSlotsByName(Battaglia);
    } // setupUi

    void retranslateUi(QWidget *Battaglia)
    {
        Battaglia->setWindowTitle(QApplication::translate("Battaglia", "Form", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Battaglia", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Battaglia", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Battaglia", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Battaglia", "PushButton", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Battaglia", "PushButton", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Battaglia", "PushButton", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Battaglia", "PushButton", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Battaglia", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Battaglia: public Ui_Battaglia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTAGLIA_H
