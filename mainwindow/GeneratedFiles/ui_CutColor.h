/********************************************************************************
** Form generated from reading UI file 'CutColor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTCOLOR_H
#define UI_CUTCOLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CutColor
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *nSpinBox;
    QSlider *nSlider;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *CutColor)
    {
        if (CutColor->objectName().isEmpty())
            CutColor->setObjectName(QStringLiteral("CutColor"));
        CutColor->resize(356, 95);
        verticalLayout_3 = new QVBoxLayout(CutColor);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CutColor);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nSpinBox = new QSpinBox(CutColor);
        nSpinBox->setObjectName(QStringLiteral("nSpinBox"));

        horizontalLayout_2->addWidget(nSpinBox);

        nSlider = new QSlider(CutColor);
        nSlider->setObjectName(QStringLiteral("nSlider"));
        nSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(nSlider);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sureBtn = new QPushButton(CutColor);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout->addWidget(sureBtn);

        closeBtn = new QPushButton(CutColor);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(CutColor);

        QMetaObject::connectSlotsByName(CutColor);
    } // setupUi

    void retranslateUi(QWidget *CutColor)
    {
        CutColor->setWindowTitle(QApplication::translate("CutColor", "CutColor", Q_NULLPTR));
        label->setText(QApplication::translate("CutColor", "\347\274\251\345\207\217\347\255\211\347\272\247", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("CutColor", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("CutColor", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CutColor: public Ui_CutColor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTCOLOR_H
