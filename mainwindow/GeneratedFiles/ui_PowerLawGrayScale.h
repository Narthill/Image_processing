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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PowerLawGrayScale
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *kSpinBox;
    QSlider *kSlider;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *indexSpinBox;
    QSlider *indexSlider;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;

    void setupUi(QWidget *PowerLawGrayScale)
    {
        if (PowerLawGrayScale->objectName().isEmpty())
            PowerLawGrayScale->setObjectName(QStringLiteral("PowerLawGrayScale"));
        PowerLawGrayScale->resize(422, 145);
        verticalLayout_4 = new QVBoxLayout(PowerLawGrayScale);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(PowerLawGrayScale);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        kSpinBox = new QSpinBox(PowerLawGrayScale);
        kSpinBox->setObjectName(QStringLiteral("kSpinBox"));

        horizontalLayout_2->addWidget(kSpinBox);

        kSlider = new QSlider(PowerLawGrayScale);
        kSlider->setObjectName(QStringLiteral("kSlider"));
        kSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(kSlider);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(PowerLawGrayScale);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

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


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeBtn = new QPushButton(PowerLawGrayScale);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(PowerLawGrayScale);

        QMetaObject::connectSlotsByName(PowerLawGrayScale);
    } // setupUi

    void retranslateUi(QWidget *PowerLawGrayScale)
    {
        PowerLawGrayScale->setWindowTitle(QApplication::translate("PowerLawGrayScale", "PowerLawGrayScale", Q_NULLPTR));
        label->setText(QApplication::translate("PowerLawGrayScale", "\345\272\225\347\232\204\345\200\215\346\225\260K", Q_NULLPTR));
        label_2->setText(QApplication::translate("PowerLawGrayScale", "\346\214\207\346\225\260", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("PowerLawGrayScale", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PowerLawGrayScale: public Ui_PowerLawGrayScale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERLAWGRAYSCALE_H
