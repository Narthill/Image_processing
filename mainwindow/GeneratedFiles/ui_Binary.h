/********************************************************************************
** Form generated from reading UI file 'Binary.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARY_H
#define UI_BINARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Binary
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *BinarySpinBox;
    QSlider *BinarySlider;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *yesBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *Binary)
    {
        if (Binary->objectName().isEmpty())
            Binary->setObjectName(QStringLiteral("Binary"));
        Binary->resize(325, 143);
        verticalLayout_2 = new QVBoxLayout(Binary);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BinarySpinBox = new QSpinBox(Binary);
        BinarySpinBox->setObjectName(QStringLiteral("BinarySpinBox"));

        horizontalLayout->addWidget(BinarySpinBox);

        BinarySlider = new QSlider(Binary);
        BinarySlider->setObjectName(QStringLiteral("BinarySlider"));
        BinarySlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(BinarySlider);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        yesBtn = new QPushButton(Binary);
        yesBtn->setObjectName(QStringLiteral("yesBtn"));

        horizontalLayout_2->addWidget(yesBtn);

        closeBtn = new QPushButton(Binary);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Binary);

        QMetaObject::connectSlotsByName(Binary);
    } // setupUi

    void retranslateUi(QWidget *Binary)
    {
        Binary->setWindowTitle(QApplication::translate("Binary", "Binary", Q_NULLPTR));
        yesBtn->setText(QApplication::translate("Binary", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("Binary", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Binary: public Ui_Binary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARY_H
