/********************************************************************************
** Form generated from reading UI file 'PieceWiselinearGrayScale.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIECEWISELINEARGRAYSCALE_H
#define UI_PIECEWISELINEARGRAYSCALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_PieceWiselinearGrayScale
{
public:
    QVBoxLayout *verticalLayout_3;
    QChartView *ChartView_1;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_13;
    QSpinBox *X1_SpinBox;
    QSlider *X1_Slider;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QSpinBox *Y1_SpinBox;
    QSlider *Y1_Slider;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_14;
    QSpinBox *X2_SpinBox;
    QSlider *X2_Slider;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_15;
    QSpinBox *Y2_SpinBox;
    QSlider *Y2_Slider;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *PieceWiselinearGrayScale)
    {
        if (PieceWiselinearGrayScale->objectName().isEmpty())
            PieceWiselinearGrayScale->setObjectName(QStringLiteral("PieceWiselinearGrayScale"));
        PieceWiselinearGrayScale->resize(496, 448);
        verticalLayout_3 = new QVBoxLayout(PieceWiselinearGrayScale);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ChartView_1 = new QChartView(PieceWiselinearGrayScale);
        ChartView_1->setObjectName(QStringLiteral("ChartView_1"));

        verticalLayout_3->addWidget(ChartView_1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox = new QGroupBox(PieceWiselinearGrayScale);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_2->addWidget(label_13);

        X1_SpinBox = new QSpinBox(groupBox);
        X1_SpinBox->setObjectName(QStringLiteral("X1_SpinBox"));

        verticalLayout_2->addWidget(X1_SpinBox);

        X1_Slider = new QSlider(groupBox);
        X1_Slider->setObjectName(QStringLiteral("X1_Slider"));
        X1_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(X1_Slider);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout->addWidget(label_10);

        Y1_SpinBox = new QSpinBox(groupBox);
        Y1_SpinBox->setObjectName(QStringLiteral("Y1_SpinBox"));

        verticalLayout->addWidget(Y1_SpinBox);

        Y1_Slider = new QSlider(groupBox);
        Y1_Slider->setObjectName(QStringLiteral("Y1_Slider"));
        Y1_Slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(Y1_Slider);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PieceWiselinearGrayScale);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_4->addWidget(label_14);

        X2_SpinBox = new QSpinBox(groupBox_2);
        X2_SpinBox->setObjectName(QStringLiteral("X2_SpinBox"));

        verticalLayout_4->addWidget(X2_SpinBox);

        X2_Slider = new QSlider(groupBox_2);
        X2_Slider->setObjectName(QStringLiteral("X2_Slider"));
        X2_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(X2_Slider);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_5->addWidget(label_15);

        Y2_SpinBox = new QSpinBox(groupBox_2);
        Y2_SpinBox->setObjectName(QStringLiteral("Y2_SpinBox"));

        verticalLayout_5->addWidget(Y2_SpinBox);

        Y2_Slider = new QSlider(groupBox_2);
        Y2_Slider->setObjectName(QStringLiteral("Y2_Slider"));
        Y2_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(Y2_Slider);


        horizontalLayout_3->addLayout(verticalLayout_5);


        horizontalLayout_4->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        sureBtn = new QPushButton(PieceWiselinearGrayScale);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout_2->addWidget(sureBtn);

        closeBtn = new QPushButton(PieceWiselinearGrayScale);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_2->addWidget(closeBtn);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 6);
        verticalLayout_3->setStretch(1, 1);

        retranslateUi(PieceWiselinearGrayScale);

        QMetaObject::connectSlotsByName(PieceWiselinearGrayScale);
    } // setupUi

    void retranslateUi(QWidget *PieceWiselinearGrayScale)
    {
        PieceWiselinearGrayScale->setWindowTitle(QApplication::translate("PieceWiselinearGrayScale", "PieceWiselinearGrayScale", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("PieceWiselinearGrayScale", "\346\213\220\347\202\2711", Q_NULLPTR));
        label_13->setText(QApplication::translate("PieceWiselinearGrayScale", "X1", Q_NULLPTR));
        label_10->setText(QApplication::translate("PieceWiselinearGrayScale", "Y1", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("PieceWiselinearGrayScale", "\346\213\220\347\202\2712", Q_NULLPTR));
        label_14->setText(QApplication::translate("PieceWiselinearGrayScale", "X2", Q_NULLPTR));
        label_15->setText(QApplication::translate("PieceWiselinearGrayScale", "Y2", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("PieceWiselinearGrayScale", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("PieceWiselinearGrayScale", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PieceWiselinearGrayScale: public Ui_PieceWiselinearGrayScale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIECEWISELINEARGRAYSCALE_H
