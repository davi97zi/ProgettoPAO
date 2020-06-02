/********************************************************************************
** Form generated from reading UI file 'partita.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTITA_H
#define UI_PARTITA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Partita
{
public:
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Partita)
    {
        if (Partita->objectName().isEmpty())
            Partita->setObjectName(QStringLiteral("Partita"));
        Partita->resize(400, 300);
        verticalLayoutWidget_4 = new QWidget(Partita);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(60, 40, 291, 211));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 21, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(187, 95));
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_4->addWidget(label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_2 = new QLabel(verticalLayoutWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        pushButton = new QPushButton(verticalLayoutWidget_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(verticalLayoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label = new QLabel(verticalLayoutWidget_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        pushButton_2 = new QPushButton(verticalLayoutWidget_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_3 = new QLabel(verticalLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        pushButton_3 = new QPushButton(verticalLayoutWidget_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(Partita);

        QMetaObject::connectSlotsByName(Partita);
    } // setupUi

    void retranslateUi(QWidget *Partita)
    {
        Partita->setWindowTitle(QApplication::translate("Partita", "Form", Q_NULLPTR));
        label_7->setText(QApplication::translate("Partita", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("Partita", "Nome1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Partita", "Desc1", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Partita", "Scegli", Q_NULLPTR));
        label_4->setText(QApplication::translate("Partita", "Nome2", Q_NULLPTR));
        label->setText(QApplication::translate("Partita", "Desc2", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Partita", "Scegli", Q_NULLPTR));
        label_6->setText(QApplication::translate("Partita", "Nome3", Q_NULLPTR));
        label_3->setText(QApplication::translate("Partita", "Desc3", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Partita", "Scegli", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Partita: public Ui_Partita {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTITA_H
