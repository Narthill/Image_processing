/********************************************************************************
** Form generated from reading UI file 'imageOrVideo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEORVIDEO_H
#define UI_IMAGEORVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageOrVideo
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *imageBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *videoBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *imageOrVideo)
    {
        if (imageOrVideo->objectName().isEmpty())
            imageOrVideo->setObjectName(QStringLiteral("imageOrVideo"));
        imageOrVideo->resize(357, 271);
        centralWidget = new QWidget(imageOrVideo);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        imageBtn = new QPushButton(centralWidget);
        imageBtn->setObjectName(QStringLiteral("imageBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageBtn->sizePolicy().hasHeightForWidth());
        imageBtn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(imageBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        videoBtn = new QPushButton(centralWidget);
        videoBtn->setObjectName(QStringLiteral("videoBtn"));
        sizePolicy.setHeightForWidth(videoBtn->sizePolicy().hasHeightForWidth());
        videoBtn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(videoBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 3);

        horizontalLayout_2->addLayout(verticalLayout);

        imageOrVideo->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(imageOrVideo);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        imageOrVideo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(imageOrVideo);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        imageOrVideo->setStatusBar(statusBar);
        menuBar = new QMenuBar(imageOrVideo);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 357, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        imageOrVideo->setMenuBar(menuBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());

        retranslateUi(imageOrVideo);

        QMetaObject::connectSlotsByName(imageOrVideo);
    } // setupUi

    void retranslateUi(QMainWindow *imageOrVideo)
    {
        imageOrVideo->setWindowTitle(QApplication::translate("imageOrVideo", "imageOrVideo", Q_NULLPTR));
        imageBtn->setText(QApplication::translate("imageOrVideo", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR));
        videoBtn->setText(QApplication::translate("imageOrVideo", "\350\247\206\351\242\221\345\244\204\347\220\206", Q_NULLPTR));
        menu->setTitle(QApplication::translate("imageOrVideo", "\345\205\263\344\272\216", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("imageOrVideo", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class imageOrVideo: public Ui_imageOrVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEORVIDEO_H
