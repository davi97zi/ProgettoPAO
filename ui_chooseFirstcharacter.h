/********************************************************************************
** Form generated from reading UI file 'chooseFirstcharacter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEFIRSTCHARACTER_H
#define UI_CHOOSEFIRSTCHARACTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseCharacter
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_5;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_7;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *chooseCharacter)
    {
        if (chooseCharacter->objectName().isEmpty())
            chooseCharacter->setObjectName(QStringLiteral("chooseCharacter"));
        chooseCharacter->setWindowModality(Qt::NonModal);
        chooseCharacter->resize(741, 580);
        gridLayoutWidget = new QWidget(chooseCharacter);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 30, 611, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_8);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_9);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_10);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_4->addWidget(pushButton_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(chooseCharacter);

        QMetaObject::connectSlotsByName(chooseCharacter);
    } // setupUi

    void retranslateUi(QWidget *chooseCharacter)
    {
        chooseCharacter->setWindowTitle(QApplication::translate("chooseCharacter", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("chooseCharacter", "Scegli il tuo primo personaggio", Q_NULLPTR));
        label_3->setText(QApplication::translate("chooseCharacter", "Nome1", Q_NULLPTR));
        label_8->setText(QApplication::translate("chooseCharacter", "Tipologia1", Q_NULLPTR));
        label_5->setText(QApplication::translate("chooseCharacter", "Descrizione1", Q_NULLPTR));
        pushButton->setText(QApplication::translate("chooseCharacter", "Scegli", Q_NULLPTR));
        label_2->setText(QApplication::translate("chooseCharacter", "Nome2", Q_NULLPTR));
        label_9->setText(QApplication::translate("chooseCharacter", "Tipologia2", Q_NULLPTR));
        label_6->setText(QApplication::translate("chooseCharacter", "Descrizione2", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("chooseCharacter", "Scegli", Q_NULLPTR));
        label_4->setText(QApplication::translate("chooseCharacter", "Nome3", Q_NULLPTR));
        label_10->setText(QApplication::translate("chooseCharacter", "Tipologia3", Q_NULLPTR));
        label_7->setText(QApplication::translate("chooseCharacter", "Descrizione3", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("chooseCharacter", "Scegli", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chooseCharacter: public Ui_chooseCharacter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEFIRSTCHARACTER_H
