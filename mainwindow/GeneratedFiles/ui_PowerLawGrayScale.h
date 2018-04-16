/********************************************************************************
** Form generated from reading UI file 'PowerLawGrayScale.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERLAWGRAYSCALE_H
#define UI_POWERLAWGRAYSCALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PowerLawGrayScale
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *indexSpinBox;
    QSlider *indexSlider;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *PowerLawGrayScale)
    {
        if (PowerLawGrayScale->objectName().isEmpty())
            PowerLawGrayScale->setObjectName(QStringLiteral("PowerLawGrayScale"));
        PowerLawGrayScale->resize(294, 115);
        verticalLayout_3 = new QVBoxLayout(PowerLawGrayScale);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(PowerLawGrayScale);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        indexSpinBox = new QDoubleSpinBox(PowerLawGrayScale);
        indexSpinBox->setObjectName(QStringLiteral("indexSpinBox"));

        horizontalLayout_3->addWidget(indexSpinBox);

        indexSlider = new QSlider(PowerLawGrayScale);
        indexSlider->setObjectName(QStringLiteral("indexSlider"));
        indexSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(indexSlider);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sureBtn = new QPushButton(PowerLawGrayScale);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout->addWidget(sureBtn);

        closeBtn = new QPushButton(PowerLawGrayScale);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(PowerLawGrayScale);

        QMetaObject::connectSlotsByName(PowerLawGrayScale);
    } // setupUi

    void retranslateUi(QWidget *PowerLawGrayScale)
    {
        PowerLawGrayScale->setWindowTitle(QApplication::translate("PowerLawGrayScale", "PowerLawGrayScale", Q_NULLPTR));
        label_2->setText(QApplication::translate("PowerLawGrayScale", "\346\214\207\346\225\260", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("PowerLawGrayScale", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("PowerLawGrayScale", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PowerLawGrayScale: public Ui_PowerLawGrayScale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERLAWGRAYSCALE_H
