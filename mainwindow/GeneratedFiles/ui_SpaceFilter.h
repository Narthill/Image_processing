/********************************************************************************
** Form generated from reading UI file 'SpaceFilter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPACEFILTER_H
#define UI_SPACEFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpaceFilter
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_kheight;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *kheightSpinBox;
    QFrame *line;
    QSlider *kheightSlider;
    QGroupBox *groupBox_kwidth;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *kwidthSpinBox;
    QFrame *line_2;
    QSlider *kwidthSlider;
    QGroupBox *groupBox_ksize;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *ksizeSpinBox;
    QFrame *line_3;
    QSlider *ksizeSlider;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *closeBtn;

    void setupUi(QWidget *SpaceFilter)
    {
        if (SpaceFilter->objectName().isEmpty())
            SpaceFilter->setObjectName(QStringLiteral("SpaceFilter"));
        SpaceFilter->resize(610, 480);
        verticalLayout_2 = new QVBoxLayout(SpaceFilter);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(SpaceFilter);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(SpaceFilter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_kheight = new QGroupBox(groupBox);
        groupBox_kheight->setObjectName(QStringLiteral("groupBox_kheight"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_kheight);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        kheightSpinBox = new QSpinBox(groupBox_kheight);
        kheightSpinBox->setObjectName(QStringLiteral("kheightSpinBox"));

        horizontalLayout_3->addWidget(kheightSpinBox);

        line = new QFrame(groupBox_kheight);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        kheightSlider = new QSlider(groupBox_kheight);
        kheightSlider->setObjectName(QStringLiteral("kheightSlider"));
        kheightSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(kheightSlider);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBox_kheight);

        groupBox_kwidth = new QGroupBox(groupBox);
        groupBox_kwidth->setObjectName(QStringLiteral("groupBox_kwidth"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_kwidth);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        kwidthSpinBox = new QSpinBox(groupBox_kwidth);
        kwidthSpinBox->setObjectName(QStringLiteral("kwidthSpinBox"));

        horizontalLayout_6->addWidget(kwidthSpinBox);

        line_2 = new QFrame(groupBox_kwidth);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_2);

        kwidthSlider = new QSlider(groupBox_kwidth);
        kwidthSlider->setObjectName(QStringLiteral("kwidthSlider"));
        kwidthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(kwidthSlider);


        horizontalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_3->addWidget(groupBox_kwidth);

        groupBox_ksize = new QGroupBox(groupBox);
        groupBox_ksize->setObjectName(QStringLiteral("groupBox_ksize"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_ksize);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        ksizeSpinBox = new QSpinBox(groupBox_ksize);
        ksizeSpinBox->setObjectName(QStringLiteral("ksizeSpinBox"));

        horizontalLayout_8->addWidget(ksizeSpinBox);

        line_3 = new QFrame(groupBox_ksize);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_3);

        ksizeSlider = new QSlider(groupBox_ksize);
        ksizeSlider->setObjectName(QStringLiteral("ksizeSlider"));
        ksizeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(ksizeSlider);


        horizontalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout_3->addWidget(groupBox_ksize);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 2);

        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        closeBtn = new QPushButton(SpaceFilter);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SpaceFilter);

        QMetaObject::connectSlotsByName(SpaceFilter);
    } // setupUi

    void retranslateUi(QWidget *SpaceFilter)
    {
        SpaceFilter->setWindowTitle(QApplication::translate("SpaceFilter", "SpaceFilter", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SpaceFilter", "\345\235\207\345\200\274\346\273\244\346\263\242", Q_NULLPTR)
         << QApplication::translate("SpaceFilter", "\351\253\230\346\226\257\346\273\244\346\263\242", Q_NULLPTR)
         << QApplication::translate("SpaceFilter", "\344\270\255\345\200\274\346\273\244\346\263\242", Q_NULLPTR)
         << QApplication::translate("SpaceFilter", "\346\213\211\346\231\256\346\213\211\346\226\257\346\273\244\346\263\242", Q_NULLPTR)
        );
        groupBox->setTitle(QApplication::translate("SpaceFilter", "\346\273\244\346\263\242\346\240\270\345\217\202\346\225\260", Q_NULLPTR));
        groupBox_kheight->setTitle(QApplication::translate("SpaceFilter", "\346\240\270\351\253\230", Q_NULLPTR));
        groupBox_kwidth->setTitle(QApplication::translate("SpaceFilter", "\346\240\270\345\256\275", Q_NULLPTR));
        groupBox_ksize->setTitle(QApplication::translate("SpaceFilter", "\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("SpaceFilter", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SpaceFilter: public Ui_SpaceFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPACEFILTER_H
