/********************************************************************************
** Form generated from reading UI file 'DctTransformation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCTTRANSFORMATION_H
#define UI_DCTTRANSFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DctTransformation
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *dctSpinBox;
    QSlider *dctSlider;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *yLabel;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *uLabel;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *vLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *DctTransformation)
    {
        if (DctTransformation->objectName().isEmpty())
            DctTransformation->setObjectName(QStringLiteral("DctTransformation"));
        DctTransformation->resize(892, 402);
        verticalLayout_3 = new QVBoxLayout(DctTransformation);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        groupBox = new QGroupBox(DctTransformation);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dctSpinBox = new QDoubleSpinBox(groupBox);
        dctSpinBox->setObjectName(QStringLiteral("dctSpinBox"));

        horizontalLayout->addWidget(dctSpinBox);

        dctSlider = new QSlider(groupBox);
        dctSlider->setObjectName(QStringLiteral("dctSlider"));
        dctSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(dctSlider);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_11->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox_2 = new QGroupBox(DctTransformation);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        yLabel = new QLabel(groupBox_2);
        yLabel->setObjectName(QStringLiteral("yLabel"));

        horizontalLayout_3->addWidget(yLabel);


        horizontalLayout_6->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(DctTransformation);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        uLabel = new QLabel(groupBox_3);
        uLabel->setObjectName(QStringLiteral("uLabel"));

        horizontalLayout_4->addWidget(uLabel);


        horizontalLayout_6->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(DctTransformation);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        vLabel = new QLabel(groupBox_4);
        vLabel->setObjectName(QStringLiteral("vLabel"));

        horizontalLayout_5->addWidget(vLabel);


        horizontalLayout_6->addWidget(groupBox_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        sureBtn = new QPushButton(DctTransformation);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout_2->addWidget(sureBtn);

        closeBtn = new QPushButton(DctTransformation);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(1, 6);

        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(DctTransformation);

        QMetaObject::connectSlotsByName(DctTransformation);
    } // setupUi

    void retranslateUi(QWidget *DctTransformation)
    {
        DctTransformation->setWindowTitle(QApplication::translate("DctTransformation", "DctTransformation", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DctTransformation", "DCT\351\230\210\345\200\274", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DctTransformation", "Y\351\200\232\351\201\223\351\242\221\350\260\261", Q_NULLPTR));
        yLabel->setText(QString());
        groupBox_3->setTitle(QApplication::translate("DctTransformation", "U\351\200\232\351\201\223\351\242\221\350\260\261", Q_NULLPTR));
        uLabel->setText(QString());
        groupBox_4->setTitle(QApplication::translate("DctTransformation", "V\351\200\232\351\201\223\351\242\221\350\260\261", Q_NULLPTR));
        vLabel->setText(QString());
        sureBtn->setText(QApplication::translate("DctTransformation", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("DctTransformation", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DctTransformation: public Ui_DctTransformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCTTRANSFORMATION_H
