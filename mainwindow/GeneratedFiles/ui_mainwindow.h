/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *action_Gray;
    QAction *action_Binary;
    QAction *action_Hist;
    QAction *action_filter;
    QAction *action_Dct;
    QAction *actionsaveas;
    QAction *action_Sobel;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *openBtn;
    QPushButton *turnBtn;
    QPushButton *disposeBtn;
    QPushButton *grayBtn;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_former;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *formerView;
    QGroupBox *groupBox_res;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *resultView;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_image;
    QMenu *menu_video;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1294, 778);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionopen->setCheckable(false);
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        action_Gray = new QAction(MainWindow);
        action_Gray->setObjectName(QStringLiteral("action_Gray"));
        action_Binary = new QAction(MainWindow);
        action_Binary->setObjectName(QStringLiteral("action_Binary"));
        action_Hist = new QAction(MainWindow);
        action_Hist->setObjectName(QStringLiteral("action_Hist"));
        action_filter = new QAction(MainWindow);
        action_filter->setObjectName(QStringLiteral("action_filter"));
        action_Dct = new QAction(MainWindow);
        action_Dct->setObjectName(QStringLiteral("action_Dct"));
        actionsaveas = new QAction(MainWindow);
        actionsaveas->setObjectName(QStringLiteral("actionsaveas"));
        action_Sobel = new QAction(MainWindow);
        action_Sobel->setObjectName(QStringLiteral("action_Sobel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        openBtn = new QPushButton(centralWidget);
        openBtn->setObjectName(QStringLiteral("openBtn"));

        verticalLayout->addWidget(openBtn);

        turnBtn = new QPushButton(centralWidget);
        turnBtn->setObjectName(QStringLiteral("turnBtn"));

        verticalLayout->addWidget(turnBtn);

        disposeBtn = new QPushButton(centralWidget);
        disposeBtn->setObjectName(QStringLiteral("disposeBtn"));

        verticalLayout->addWidget(disposeBtn);

        grayBtn = new QPushButton(centralWidget);
        grayBtn->setObjectName(QStringLiteral("grayBtn"));

        verticalLayout->addWidget(grayBtn);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_former = new QGroupBox(centralWidget);
        groupBox_former->setObjectName(QStringLiteral("groupBox_former"));
        horizontalLayout = new QHBoxLayout(groupBox_former);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formerView = new QGraphicsView(groupBox_former);
        formerView->setObjectName(QStringLiteral("formerView"));

        horizontalLayout->addWidget(formerView);


        horizontalLayout_3->addWidget(groupBox_former);

        groupBox_res = new QGroupBox(centralWidget);
        groupBox_res->setObjectName(QStringLiteral("groupBox_res"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_res);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        resultView = new QGraphicsView(groupBox_res);
        resultView->setObjectName(QStringLiteral("resultView"));

        horizontalLayout_2->addWidget(resultView);


        horizontalLayout_3->addWidget(groupBox_res);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1294, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_image = new QMenu(menuBar);
        menu_image->setObjectName(QStringLiteral("menu_image"));
        menu_video = new QMenu(menuBar);
        menu_video->setObjectName(QStringLiteral("menu_video"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_image->menuAction());
        menuBar->addAction(menu_video->menuAction());
        menu->addAction(actionopen);
        menu->addSeparator();
        menu->addAction(actionsave);
        menu->addAction(actionsaveas);
        menu_image->addAction(action_Gray);
        menu_image->addAction(action_Binary);
        menu_image->addAction(action_Hist);
        menu_image->addAction(action_filter);
        menu_image->addAction(action_Dct);
        menu_image->addAction(action_Sobel);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionopen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        actionopen->setIconText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        actionsave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\347\224\237\346\210\220\346\226\207\344\273\266", Q_NULLPTR));
        action_Gray->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\345\214\226", Q_NULLPTR));
        action_Binary->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226", Q_NULLPTR));
        action_Hist->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\345\217\212\345\235\207\350\241\241\345\214\226", Q_NULLPTR));
        action_filter->setText(QApplication::translate("MainWindow", "\346\273\244\346\263\242", Q_NULLPTR));
        action_Dct->setText(QApplication::translate("MainWindow", "\347\246\273\346\225\243\344\275\231\345\274\246\345\217\230\346\215\242", Q_NULLPTR));
        actionsaveas->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        action_Sobel->setText(QApplication::translate("MainWindow", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        openBtn->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\345\203\217", Q_NULLPTR));
        turnBtn->setText(QApplication::translate("MainWindow", "\347\277\273\350\275\254\345\233\276\345\203\217", Q_NULLPTR));
        disposeBtn->setText(QApplication::translate("MainWindow", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        grayBtn->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\345\214\226", Q_NULLPTR));
        label->setText(QString());
        groupBox_former->setTitle(QApplication::translate("MainWindow", "\345\216\237\345\233\276", Q_NULLPTR));
        groupBox_res->setTitle(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\233\276", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_image->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217", Q_NULLPTR));
        menu_video->setTitle(QApplication::translate("MainWindow", "\350\247\206\351\242\221", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
