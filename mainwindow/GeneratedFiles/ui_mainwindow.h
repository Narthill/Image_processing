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
    QAction *action_Filter;
    QAction *action_Dct;
    QAction *actionsaveas;
    QAction *action_Sobel;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_former;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *formerView;
    QPushButton *clearFormer;
    QGroupBox *groupBox_res;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *resultView;
    QPushButton *clearResult;
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
        action_Filter = new QAction(MainWindow);
        action_Filter->setObjectName(QStringLiteral("action_Filter"));
        action_Dct = new QAction(MainWindow);
        action_Dct->setObjectName(QStringLiteral("action_Dct"));
        actionsaveas = new QAction(MainWindow);
        actionsaveas->setObjectName(QStringLiteral("actionsaveas"));
        action_Sobel = new QAction(MainWindow);
        action_Sobel->setObjectName(QStringLiteral("action_Sobel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_former = new QGroupBox(centralWidget);
        groupBox_former->setObjectName(QStringLiteral("groupBox_former"));
        groupBox_former->setCursor(QCursor(Qt::ArrowCursor));
        groupBox_former->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(groupBox_former);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formerView = new QGraphicsView(groupBox_former);
        formerView->setObjectName(QStringLiteral("formerView"));

        verticalLayout_2->addWidget(formerView);

        clearFormer = new QPushButton(groupBox_former);
        clearFormer->setObjectName(QStringLiteral("clearFormer"));
        clearFormer->setLayoutDirection(Qt::LeftToRight);
        clearFormer->setAutoRepeatDelay(300);

        verticalLayout_2->addWidget(clearFormer);


        horizontalLayout_3->addWidget(groupBox_former);

        groupBox_res = new QGroupBox(centralWidget);
        groupBox_res->setObjectName(QStringLiteral("groupBox_res"));
        verticalLayout_3 = new QVBoxLayout(groupBox_res);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        resultView = new QGraphicsView(groupBox_res);
        resultView->setObjectName(QStringLiteral("resultView"));

        verticalLayout_3->addWidget(resultView);

        clearResult = new QPushButton(groupBox_res);
        clearResult->setObjectName(QStringLiteral("clearResult"));
        clearResult->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_3->addWidget(clearResult);


        horizontalLayout_3->addWidget(groupBox_res);


        verticalLayout->addLayout(horizontalLayout_3);

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
        menu_image->addAction(action_Filter);
        menu_image->addAction(action_Dct);
        menu_image->addAction(action_Sobel);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\350\247\206\351\242\221\345\244\204\347\220\206", Q_NULLPTR));
        actionopen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        actionopen->setIconText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        actionsave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\347\224\237\346\210\220\346\226\207\344\273\266", Q_NULLPTR));
        action_Gray->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\345\214\226", Q_NULLPTR));
        action_Binary->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226", Q_NULLPTR));
        action_Hist->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\345\217\212\345\235\207\350\241\241\345\214\226", Q_NULLPTR));
        action_Filter->setText(QApplication::translate("MainWindow", "\346\273\244\346\263\242", Q_NULLPTR));
        action_Dct->setText(QApplication::translate("MainWindow", "\347\246\273\346\225\243\344\275\231\345\274\246\345\217\230\346\215\242", Q_NULLPTR));
        actionsaveas->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        action_Sobel->setText(QApplication::translate("MainWindow", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        groupBox_former->setTitle(QApplication::translate("MainWindow", "\345\216\237\345\233\276", Q_NULLPTR));
        clearFormer->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\216\237\345\233\276", Q_NULLPTR));
        groupBox_res->setTitle(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\233\276", Q_NULLPTR));
        clearResult->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\347\224\237\346\210\220\345\233\276", Q_NULLPTR));
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
