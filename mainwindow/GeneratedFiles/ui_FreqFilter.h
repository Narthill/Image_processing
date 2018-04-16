/********************************************************************************
** Form generated from reading UI file 'FreqFilter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQFILTER_H
#define UI_FREQFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FreqFilter
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *srcLabel;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *dstLabel;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *filterLabel;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *lowRbtn;
    QRadioButton *highRbtn;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *rGroupBox;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *rSpinBox;
    QSlider *rSlider;
    QGroupBox *btwGroupBox;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *btwSpinBox;
    QSlider *btwSlider;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *closeBtn;
    QButtonGroup *highOrlow;

    void setupUi(QWidget *FreqFilter)
    {
        if (FreqFilter->objectName().isEmpty())
            FreqFilter->setObjectName(QStringLiteral("FreqFilter"));
        FreqFilter->resize(939, 746);
        verticalLayout_5 = new QVBoxLayout(FreqFilter);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(8);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        groupBox_3 = new QGroupBox(FreqFilter);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        srcLabel = new QLabel(groupBox_3);
        srcLabel->setObjectName(QStringLiteral("srcLabel"));
        srcLabel->setMinimumSize(QSize(428, 317));

        verticalLayout_4->addWidget(srcLabel);


        verticalLayout_11->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(FreqFilter);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        dstLabel = new QLabel(groupBox_5);
        dstLabel->setObjectName(QStringLiteral("dstLabel"));
        dstLabel->setMinimumSize(QSize(428, 317));

        verticalLayout_3->addWidget(dstLabel);


        verticalLayout_11->addWidget(groupBox_5);

        verticalLayout_11->setStretch(0, 1);
        verticalLayout_11->setStretch(1, 1);

        horizontalLayout_11->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(8);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        groupBox = new QGroupBox(FreqFilter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        filterLabel = new QLabel(groupBox);
        filterLabel->setObjectName(QStringLiteral("filterLabel"));
        filterLabel->setMinimumSize(QSize(428, 317));

        verticalLayout_2->addWidget(filterLabel);


        verticalLayout_10->addWidget(groupBox);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(8);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        comboBox = new QComboBox(FreqFilter);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_4->addWidget(comboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lowRbtn = new QRadioButton(FreqFilter);
        highOrlow = new QButtonGroup(FreqFilter);
        highOrlow->setObjectName(QStringLiteral("highOrlow"));
        highOrlow->addButton(lowRbtn);
        lowRbtn->setObjectName(QStringLiteral("lowRbtn"));

        horizontalLayout_2->addWidget(lowRbtn);

        highRbtn = new QRadioButton(FreqFilter);
        highOrlow->addButton(highRbtn);
        highRbtn->setObjectName(QStringLiteral("highRbtn"));

        horizontalLayout_2->addWidget(highRbtn);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_9->addLayout(horizontalLayout_3);

        groupBox_4 = new QGroupBox(FreqFilter);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        rGroupBox = new QGroupBox(groupBox_4);
        rGroupBox->setObjectName(QStringLiteral("rGroupBox"));
        horizontalLayout_7 = new QHBoxLayout(rGroupBox);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        rSpinBox = new QSpinBox(rGroupBox);
        rSpinBox->setObjectName(QStringLiteral("rSpinBox"));

        horizontalLayout_5->addWidget(rSpinBox);

        rSlider = new QSlider(rGroupBox);
        rSlider->setObjectName(QStringLiteral("rSlider"));
        rSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(rSlider);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_6->addWidget(rGroupBox);

        btwGroupBox = new QGroupBox(groupBox_4);
        btwGroupBox->setObjectName(QStringLiteral("btwGroupBox"));
        horizontalLayout_8 = new QHBoxLayout(btwGroupBox);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btwSpinBox = new QSpinBox(btwGroupBox);
        btwSpinBox->setObjectName(QStringLiteral("btwSpinBox"));

        horizontalLayout_6->addWidget(btwSpinBox);

        btwSlider = new QSlider(btwGroupBox);
        btwSlider->setObjectName(QStringLiteral("btwSlider"));
        btwSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(btwSlider);


        horizontalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_6->addWidget(btwGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 1);
        verticalLayout_6->setStretch(2, 1);

        verticalLayout_9->addWidget(groupBox_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sureBtn = new QPushButton(FreqFilter);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout->addWidget(sureBtn);

        closeBtn = new QPushButton(FreqFilter);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_9->addLayout(horizontalLayout);

        verticalLayout_9->setStretch(0, 2);
        verticalLayout_9->setStretch(2, 1);

        verticalLayout_10->addLayout(verticalLayout_9);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 1);

        horizontalLayout_11->addLayout(verticalLayout_10);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout_11);


        retranslateUi(FreqFilter);

        QMetaObject::connectSlotsByName(FreqFilter);
    } // setupUi

    void retranslateUi(QWidget *FreqFilter)
    {
        FreqFilter->setWindowTitle(QApplication::translate("FreqFilter", "FreqFilter", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("FreqFilter", "\345\216\237\345\233\276\347\232\204\351\242\221\350\260\261\345\233\276", Q_NULLPTR));
        srcLabel->setText(QString());
        groupBox_5->setTitle(QApplication::translate("FreqFilter", "\347\224\237\346\210\220\345\233\276\347\232\204\351\242\221\350\260\261\345\233\276", Q_NULLPTR));
        dstLabel->setText(QString());
        groupBox->setTitle(QApplication::translate("FreqFilter", "\346\273\244\346\263\242\346\250\241\346\235\277\347\232\204\351\242\221\350\260\261\345\233\276", Q_NULLPTR));
        filterLabel->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("FreqFilter", "\351\253\230\346\226\257\346\273\244\346\263\242", Q_NULLPTR)
         << QApplication::translate("FreqFilter", "\347\220\206\346\203\263\346\273\244\346\263\242", Q_NULLPTR)
         << QApplication::translate("FreqFilter", "\345\267\264\347\211\271\346\262\203\346\226\257\346\273\244\346\263\242", Q_NULLPTR)
        );
        lowRbtn->setText(QApplication::translate("FreqFilter", "\344\275\216\351\200\232", Q_NULLPTR));
        highRbtn->setText(QApplication::translate("FreqFilter", "\351\253\230\351\200\232", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("FreqFilter", "\345\217\202\346\225\260", Q_NULLPTR));
        rGroupBox->setTitle(QApplication::translate("FreqFilter", "\351\200\232\345\270\246\345\215\212\345\276\204", Q_NULLPTR));
        btwGroupBox->setTitle(QApplication::translate("FreqFilter", "\345\267\264\347\211\271\346\262\203\346\226\257\346\254\241\346\225\260", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("FreqFilter", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("FreqFilter", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FreqFilter: public Ui_FreqFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQFILTER_H
