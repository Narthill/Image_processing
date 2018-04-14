/********************************************************************************
** Form generated from reading UI file 'videoProcessing.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPROCESSING_H
#define UI_VIDEOPROCESSING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoProcessing
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionsaveAs;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *videoLabel;
    QVBoxLayout *verticalLayout;
    QSlider *videoSlider;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *playBtn;
    QPushButton *pauseBtn;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *videoProcessing)
    {
        if (videoProcessing->objectName().isEmpty())
            videoProcessing->setObjectName(QStringLiteral("videoProcessing"));
        videoProcessing->resize(611, 531);
        actionopen = new QAction(videoProcessing);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionsave = new QAction(videoProcessing);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionsaveAs = new QAction(videoProcessing);
        actionsaveAs->setObjectName(QStringLiteral("actionsaveAs"));
        centralWidget = new QWidget(videoProcessing);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        videoLabel = new QLabel(centralWidget);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));
        videoLabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout_2->addWidget(videoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        videoSlider = new QSlider(centralWidget);
        videoSlider->setObjectName(QStringLiteral("videoSlider"));
        videoSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(videoSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        playBtn = new QPushButton(centralWidget);
        playBtn->setObjectName(QStringLiteral("playBtn"));

        horizontalLayout->addWidget(playBtn);

        pauseBtn = new QPushButton(centralWidget);
        pauseBtn->setObjectName(QStringLiteral("pauseBtn"));

        horizontalLayout->addWidget(pauseBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_2);

        videoProcessing->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(videoProcessing);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 611, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        videoProcessing->setMenuBar(menuBar);
        mainToolBar = new QToolBar(videoProcessing);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        videoProcessing->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(videoProcessing);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        videoProcessing->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionopen);
        menu->addSeparator();
        menu->addAction(actionsave);
        menu->addAction(actionsaveAs);

        retranslateUi(videoProcessing);

        QMetaObject::connectSlotsByName(videoProcessing);
    } // setupUi

    void retranslateUi(QMainWindow *videoProcessing)
    {
        videoProcessing->setWindowTitle(QApplication::translate("videoProcessing", "videoProcessing", Q_NULLPTR));
        actionopen->setText(QApplication::translate("videoProcessing", "\346\211\223\345\274\200\350\247\206\351\242\221", Q_NULLPTR));
        actionsave->setText(QApplication::translate("videoProcessing", "\344\277\235\345\255\230", Q_NULLPTR));
        actionsaveAs->setText(QApplication::translate("videoProcessing", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        videoLabel->setText(QString());
        playBtn->setText(QApplication::translate("videoProcessing", "\346\222\255\346\224\276", Q_NULLPTR));
        pauseBtn->setText(QApplication::translate("videoProcessing", "\346\232\202\345\201\234", Q_NULLPTR));
        menu->setTitle(QApplication::translate("videoProcessing", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("videoProcessing", "\350\247\206\351\242\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class videoProcessing: public Ui_videoProcessing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPROCESSING_H
