/********************************************************************************
** Form generated from reading UI file 'Histogram.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAM_H
#define UI_HISTOGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Histogram
{
public:
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *Rlabel;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *Glabel;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *Blabel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *getHistBtn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *Res_Rlabel;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *Res_Glabel;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *Res_Blabel;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *getEquHisBtn;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sureBtn;
    QPushButton *closeBtn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Histogram)
    {
        if (Histogram->objectName().isEmpty())
            Histogram->setObjectName(QStringLiteral("Histogram"));
        Histogram->resize(743, 617);
        verticalLayout_10 = new QVBoxLayout(Histogram);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(Histogram);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Rlabel = new QLabel(groupBox);
        Rlabel->setObjectName(QStringLiteral("Rlabel"));
        Rlabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout_2->addWidget(Rlabel);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Histogram);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Glabel = new QLabel(groupBox_2);
        Glabel->setObjectName(QStringLiteral("Glabel"));
        Glabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout_4->addWidget(Glabel);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Histogram);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Blabel = new QLabel(groupBox_3);
        Blabel->setObjectName(QStringLiteral("Blabel"));
        Blabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout_3->addWidget(Blabel);


        horizontalLayout->addWidget(groupBox_3);


        verticalLayout_8->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        getHistBtn = new QPushButton(Histogram);
        getHistBtn->setObjectName(QStringLiteral("getHistBtn"));

        horizontalLayout_3->addWidget(getHistBtn);


        verticalLayout_8->addLayout(horizontalLayout_3);

        verticalLayout_8->setStretch(0, 8);
        verticalLayout_8->setStretch(1, 1);

        verticalLayout_9->addLayout(verticalLayout_8);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_4 = new QGroupBox(Histogram);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        Res_Rlabel = new QLabel(groupBox_4);
        Res_Rlabel->setObjectName(QStringLiteral("Res_Rlabel"));
        Res_Rlabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout_5->addWidget(Res_Rlabel);


        horizontalLayout_2->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(Histogram);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        Res_Glabel = new QLabel(groupBox_5);
        Res_Glabel->setObjectName(QStringLiteral("Res_Glabel"));
        Res_Glabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout_7->addWidget(Res_Glabel);


        horizontalLayout_2->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(Histogram);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        Res_Blabel = new QLabel(groupBox_6);
        Res_Blabel->setObjectName(QStringLiteral("Res_Blabel"));
        Res_Blabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout_6->addWidget(Res_Blabel);


        horizontalLayout_2->addWidget(groupBox_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        getEquHisBtn = new QPushButton(Histogram);
        getEquHisBtn->setObjectName(QStringLiteral("getEquHisBtn"));

        horizontalLayout_4->addWidget(getEquHisBtn);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 8);
        verticalLayout->setStretch(1, 1);

        verticalLayout_9->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        sureBtn = new QPushButton(Histogram);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout_5->addWidget(sureBtn);

        closeBtn = new QPushButton(Histogram);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_5->addWidget(closeBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_9->addLayout(horizontalLayout_5);


        verticalLayout_10->addLayout(verticalLayout_9);


        retranslateUi(Histogram);

        QMetaObject::connectSlotsByName(Histogram);
    } // setupUi

    void retranslateUi(QWidget *Histogram)
    {
        Histogram->setWindowTitle(QApplication::translate("Histogram", "Histogram", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Histogram", "R\351\200\232\351\201\223", Q_NULLPTR));
        Rlabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Histogram", "G\351\200\232\351\201\223", Q_NULLPTR));
        Glabel->setText(QString());
        groupBox_3->setTitle(QApplication::translate("Histogram", "B\351\200\232\351\201\223", Q_NULLPTR));
        Blabel->setText(QString());
        getHistBtn->setText(QApplication::translate("Histogram", "\347\224\237\346\210\220\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Histogram", "\345\235\207\350\241\241\345\214\226\345\220\216R\351\200\232\351\201\223", Q_NULLPTR));
        Res_Rlabel->setText(QString());
        groupBox_5->setTitle(QApplication::translate("Histogram", "\345\235\207\350\241\241\345\214\226\345\220\216G\351\200\232\351\201\223", Q_NULLPTR));
        Res_Glabel->setText(QString());
        groupBox_6->setTitle(QApplication::translate("Histogram", "\345\235\207\350\241\241\345\214\226\345\220\216B\351\200\232\351\201\223", Q_NULLPTR));
        Res_Blabel->setText(QString());
        getEquHisBtn->setText(QApplication::translate("Histogram", "\345\235\207\350\241\241\345\214\226\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("Histogram", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("Histogram", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Histogram: public Ui_Histogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_H
