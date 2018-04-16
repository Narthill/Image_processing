/********************************************************************************
** Form generated from reading UI file 'LoglinearGrayScale.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGLINEARGRAYSCALE_H
#define UI_LOGLINEARGRAYSCALE_H

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

class Ui_LoglinearGrayScale
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *cSpinBox;
    QSlider *cSlider;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *LoglinearGrayScale)
    {
        if (LoglinearGrayScale->objectName().isEmpty())
            LoglinearGrayScale->setObjectName(QStringLiteral("LoglinearGrayScale"));
        LoglinearGrayScale->resize(322, 123);
        verticalLayout_3 = new QVBoxLayout(LoglinearGrayScale);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LoglinearGrayScale);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cSpinBox = new QSpinBox(LoglinearGrayScale);
        cSpinBox->setObjectName(QStringLiteral("cSpinBox"));

        horizontalLayout_2->addWidget(cSpinBox);

        cSlider = new QSlider(LoglinearGrayScale);
        cSlider->setObjectName(QStringLiteral("cSlider"));
        cSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(cSlider);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sureBtn = new QPushButton(LoglinearGrayScale);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout->addWidget(sureBtn);

        closeBtn = new QPushButton(LoglinearGrayScale);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(LoglinearGrayScale);

        QMetaObject::connectSlotsByName(LoglinearGrayScale);
    } // setupUi

    void retranslateUi(QWidget *LoglinearGrayScale)
    {
        LoglinearGrayScale->setWindowTitle(QApplication::translate("LoglinearGrayScale", "LoglinearGrayScale", Q_NULLPTR));
        label->setText(QApplication::translate("LoglinearGrayScale", "\345\270\270\346\225\260C", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("LoglinearGrayScale", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("LoglinearGrayScale", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoglinearGrayScale: public Ui_LoglinearGrayScale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGLINEARGRAYSCALE_H
