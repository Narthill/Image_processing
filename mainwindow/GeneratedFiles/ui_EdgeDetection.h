/********************************************************************************
** Form generated from reading UI file 'EdgeDetection.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDGEDETECTION_H
#define UI_EDGEDETECTION_H

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

class Ui_EdgeDetection
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpinBox *modelSpinBox;
    QSlider *modelSlider;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *bigSpinBox;
    QSlider *bigSlider;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *smallSpinBox;
    QSlider *smallSlider;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;

    void setupUi(QWidget *EdgeDetection)
    {
        if (EdgeDetection->objectName().isEmpty())
            EdgeDetection->setObjectName(QStringLiteral("EdgeDetection"));
        EdgeDetection->resize(360, 221);
        verticalLayout_6 = new QVBoxLayout(EdgeDetection);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(EdgeDetection);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        modelSpinBox = new QSpinBox(EdgeDetection);
        modelSpinBox->setObjectName(QStringLiteral("modelSpinBox"));

        horizontalLayout->addWidget(modelSpinBox);

        modelSlider = new QSlider(EdgeDetection);
        modelSlider->setObjectName(QStringLiteral("modelSlider"));
        modelSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(modelSlider);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(EdgeDetection);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bigSpinBox = new QSpinBox(EdgeDetection);
        bigSpinBox->setObjectName(QStringLiteral("bigSpinBox"));

        horizontalLayout_2->addWidget(bigSpinBox);

        bigSlider = new QSlider(EdgeDetection);
        bigSlider->setObjectName(QStringLiteral("bigSlider"));
        bigSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(bigSlider);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(EdgeDetection);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        smallSpinBox = new QSpinBox(EdgeDetection);
        smallSpinBox->setObjectName(QStringLiteral("smallSpinBox"));

        horizontalLayout_3->addWidget(smallSpinBox);

        smallSlider = new QSlider(EdgeDetection);
        smallSlider->setObjectName(QStringLiteral("smallSlider"));
        smallSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(smallSlider);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        closeBtn = new QPushButton(EdgeDetection);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_4->addWidget(closeBtn);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(EdgeDetection);

        QMetaObject::connectSlotsByName(EdgeDetection);
    } // setupUi

    void retranslateUi(QWidget *EdgeDetection)
    {
        EdgeDetection->setWindowTitle(QApplication::translate("EdgeDetection", "EdgeDetection", Q_NULLPTR));
        label->setText(QApplication::translate("EdgeDetection", "\346\250\241\346\235\277\345\244\247\345\260\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("EdgeDetection", "\345\274\272\351\230\210\345\200\274", Q_NULLPTR));
        label_3->setText(QApplication::translate("EdgeDetection", "\345\274\261\351\230\210\345\200\274", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("EdgeDetection", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EdgeDetection: public Ui_EdgeDetection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDGEDETECTION_H
