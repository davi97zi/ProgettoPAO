/********************************************************************************
** Form generated from reading UI file 'changecharacter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGECHARACTER_H
#define UI_CHANGECHARACTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_5;
    QLabel *label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(673, 591);
        gridLayoutWidget = new QWidget(Form);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 20, 631, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_9);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_5->addWidget(pushButton_4);


        verticalLayout_4->addLayout(verticalLayout_5);


        gridLayout->addLayout(verticalLayout_4, 1, 3, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_7);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);


        gridLayout->addLayout(verticalLayout_3, 1, 2, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_10);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_11);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_6->addWidget(pushButton_5);


        gridLayout->addLayout(verticalLayout_6, 1, 4, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 5);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label_8->setText(QApplication::translate("Form", "Nome4", Q_NULLPTR));
        label_9->setText(QApplication::translate("Form", "Tipologia4", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Form", "Scegli", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "Nome2", Q_NULLPTR));
        label_5->setText(QApplication::translate("Form", "Tipologia2", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Form", "Scegli", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "Nome1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "Tipologia1", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "Scegli", Q_NULLPTR));
        label_6->setText(QApplication::translate("Form", "Nome3", Q_NULLPTR));
        label_7->setText(QApplication::translate("Form", "Tipologia3", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Form", "Scegli", Q_NULLPTR));
        label_10->setText(QApplication::translate("Form", "Nome5", Q_NULLPTR));
        label_11->setText(QApplication::translate("Form", "Tipologia5", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Form", "Scegli", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "Seleziona il personaggio", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGECHARACTER_H
