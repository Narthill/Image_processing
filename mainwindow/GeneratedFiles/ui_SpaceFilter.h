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
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_sigmaX;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *sigmaXspinBox;
    QSlider *sigmaXSlider;
    QGroupBox *groupBox_sigmaY;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QSpinBox *sigmaYspinBox;
    QSlider *sigmaYSlider;
    QGroupBox *groupBox_kheight;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *kheightSpinBox;
    QFrame *line;
    QSlider *kheightSlider;
    QGroupBox *groupBox_kwidth;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *kwidthSpinBox;
    QFrame *line_2;
    QSlider *kwidthSlider;
    QGroupBox *groupBox_ksize;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *ksizeSpinBox;
    QFrame *line_3;
    QSlider *ksizeSlider;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;

    void setupUi(QWidget *SpaceFilter)
    {
        if (SpaceFilter->objectName().isEmpty())
            SpaceFilter->setObjectName(QStringLiteral("SpaceFilter"));
        SpaceFilter->resize(583, 619);
        verticalLayout_8 = new QVBoxLayout(SpaceFilter);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        comboBox = new QComboBox(SpaceFilter);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(137, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(SpaceFilter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_sigmaX = new QGroupBox(groupBox);
        groupBox_sigmaX->setObjectName(QStringLiteral("groupBox_sigmaX"));
        verticalLayout = new QVBoxLayout(groupBox_sigmaX);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        sigmaXspinBox = new QSpinBox(groupBox_sigmaX);
        sigmaXspinBox->setObjectName(QStringLiteral("sigmaXspinBox"));

        horizontalLayout_9->addWidget(sigmaXspinBox);

        sigmaXSlider = new QSlider(groupBox_sigmaX);
        sigmaXSlider->setObjectName(QStringLiteral("sigmaXSlider"));
        sigmaXSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(sigmaXSlider);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_6->addWidget(groupBox_sigmaX);

        groupBox_sigmaY = new QGroupBox(groupBox);
        groupBox_sigmaY->setObjectName(QStringLiteral("groupBox_sigmaY"));
        verticalLayout_2 = new QVBoxLayout(groupBox_sigmaY);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        sigmaYspinBox = new QSpinBox(groupBox_sigmaY);
        sigmaYspinBox->setObjectName(QStringLiteral("sigmaYspinBox"));

        horizontalLayout_11->addWidget(sigmaYspinBox);

        sigmaYSlider = new QSlider(groupBox_sigmaY);
        sigmaYSlider->setObjectName(QStringLiteral("sigmaYSlider"));
        sigmaYSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(sigmaYSlider);


        verticalLayout_2->addLayout(horizontalLayout_11);


        verticalLayout_6->addWidget(groupBox_sigmaY);

        groupBox_kheight = new QGroupBox(groupBox);
        groupBox_kheight->setObjectName(QStringLiteral("groupBox_kheight"));
        verticalLayout_3 = new QVBoxLayout(groupBox_kheight);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
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


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_6->addWidget(groupBox_kheight);

        groupBox_kwidth = new QGroupBox(groupBox);
        groupBox_kwidth->setObjectName(QStringLiteral("groupBox_kwidth"));
        verticalLayout_4 = new QVBoxLayout(groupBox_kwidth);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
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


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_6->addWidget(groupBox_kwidth);

        groupBox_ksize = new QGroupBox(groupBox);
        groupBox_ksize->setObjectName(QStringLiteral("groupBox_ksize"));
        verticalLayout_5 = new QVBoxLayout(groupBox_ksize);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
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


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_6->addWidget(groupBox_ksize);

        verticalSpacer = new QSpacerItem(20, 127, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        verticalLayout_7->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeBtn = new QPushButton(SpaceFilter);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_7->addLayout(horizontalLayout);


        verticalLayout_8->addLayout(verticalLayout_7);


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
        groupBox_sigmaX->setTitle(QApplication::translate("SpaceFilter", "sigmaX\345\200\274", Q_NULLPTR));
        groupBox_sigmaY->setTitle(QApplication::translate("SpaceFilter", "sigmaY\345\200\274", Q_NULLPTR));
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
