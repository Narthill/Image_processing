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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EdgeDetection
{
public:
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
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
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *gSpinBox;
    QSlider *gSlider;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *EdgeDetection)
    {
        if (EdgeDetection->objectName().isEmpty())
            EdgeDetection->setObjectName(QStringLiteral("EdgeDetection"));
        EdgeDetection->resize(315, 241);
        verticalLayout_9 = new QVBoxLayout(EdgeDetection);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        tabWidget = new QTabWidget(EdgeDetection);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_6 = new QHBoxLayout(tab);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        modelSpinBox = new QSpinBox(tab);
        modelSpinBox->setObjectName(QStringLiteral("modelSpinBox"));

        horizontalLayout->addWidget(modelSpinBox);

        modelSlider = new QSlider(tab);
        modelSlider->setObjectName(QStringLiteral("modelSlider"));
        modelSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(modelSlider);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bigSpinBox = new QSpinBox(tab);
        bigSpinBox->setObjectName(QStringLiteral("bigSpinBox"));

        horizontalLayout_2->addWidget(bigSpinBox);

        bigSlider = new QSlider(tab);
        bigSlider->setObjectName(QStringLiteral("bigSlider"));
        bigSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(bigSlider);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        smallSpinBox = new QSpinBox(tab);
        smallSpinBox->setObjectName(QStringLiteral("smallSpinBox"));

        horizontalLayout_3->addWidget(smallSpinBox);

        smallSlider = new QSlider(tab);
        smallSlider->setObjectName(QStringLiteral("smallSlider"));
        smallSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(smallSlider);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_7 = new QHBoxLayout(tab_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gSpinBox = new QSpinBox(tab_2);
        gSpinBox->setObjectName(QStringLiteral("gSpinBox"));

        horizontalLayout_5->addWidget(gSpinBox);

        gSlider = new QSlider(tab_2);
        gSlider->setObjectName(QStringLiteral("gSlider"));
        gSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(gSlider);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        verticalLayout_7->addLayout(verticalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_7);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_8->addWidget(tabWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        sureBtn = new QPushButton(EdgeDetection);
        sureBtn->setObjectName(QStringLiteral("sureBtn"));

        horizontalLayout_4->addWidget(sureBtn);

        closeBtn = new QPushButton(EdgeDetection);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_4->addWidget(closeBtn);


        verticalLayout_8->addLayout(horizontalLayout_4);


        verticalLayout_9->addLayout(verticalLayout_8);


        retranslateUi(EdgeDetection);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(EdgeDetection);
    } // setupUi

    void retranslateUi(QWidget *EdgeDetection)
    {
        EdgeDetection->setWindowTitle(QApplication::translate("EdgeDetection", "EdgeDetection", Q_NULLPTR));
        label->setText(QApplication::translate("EdgeDetection", "\346\250\241\346\235\277\345\244\247\345\260\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("EdgeDetection", "\345\274\272\351\230\210\345\200\274", Q_NULLPTR));
        label_3->setText(QApplication::translate("EdgeDetection", "\345\274\261\351\230\210\345\200\274", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EdgeDetection", "Canny\350\276\271\347\274\230\346\243\200\346\265\213\350\256\276\345\256\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("EdgeDetection", "\351\253\230\346\226\257\346\250\241\347\263\212\346\250\241\346\235\277\345\244\247\345\260\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("EdgeDetection", "\351\253\230\346\226\257\346\250\241\347\263\212\350\256\276\345\256\232", Q_NULLPTR));
        sureBtn->setText(QApplication::translate("EdgeDetection", "\347\241\256\345\256\232", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("EdgeDetection", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EdgeDetection: public Ui_EdgeDetection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDGEDETECTION_H
