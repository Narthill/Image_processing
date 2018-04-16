/********************************************************************************
** Form generated from reading UI file 'LinearGrayScale.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARGRAYSCALE_H
#define UI_LINEARGRAYSCALE_H

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

class Ui_LinearGrayScale
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *contrastSpinBox;
    QSlider *contrastSlider;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *brightSpinBox;
    QSlider *brightSlider;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *LinearGrayScale)
    {
        if (LinearGrayScale->objectName().isEmpty())
            LinearGrayScale->setObjectName(QStringLiteral("LinearGrayScale"));
        LinearGrayScale->resize(319, 164);
        verticalLayout_4 = new QVBoxLayout(LinearGrayScale);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(LinearGrayScale);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        contrastSpinBox = new QSpinBox(LinearGrayScale);
        contrastSpinBox->setObjectName(QStringLiteral("contrastSpinBox"));

        horizontalLayout->addWidget(contrastSpinBox);

        contrastSlider = new QSlider(LinearGrayScale);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(contrastSlider);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LinearGrayScale);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        brightSpinBox = new QSpinBox(LinearGrayScale);
        brightSpinBox->setObjectName(QStringLiteral("brightSpinBox"));

        horizontalLayout_2->addWidget(brightSpinBox);

        brightSlider = new QSlider(LinearGrayScale);
        brightSlider->setObjectName(QStringLiteral("brightSlider"));
        brightSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(brightSlider);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        sureBtn = new QPushButton(LinearGrayScale);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout_3->addWidget(sureBtn);

        closeBtn = new QPushButton(LinearGrayScale);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_3->addWidget(closeBtn);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(LinearGrayScale);

        QMetaObject::connectSlotsByName(LinearGrayScale);
    } // setupUi

    void retranslateUi(QWidget *LinearGrayScale)
    {
        LinearGrayScale->setWindowTitle(QApplication::translate("LinearGrayScale", "LinearGrayScale", Q_NULLPTR));
        label_2->setText(QApplication::translate("LinearGrayScale", "\345\257\271\346\257\224\345\272\246", Q_NULLPTR));
        label->setText(QApplication::translate("LinearGrayScale", "\344\272\256\345\272\246", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("LinearGrayScale", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("LinearGrayScale", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LinearGrayScale: public Ui_LinearGrayScale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARGRAYSCALE_H
