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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
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
    QAction *action_Dct;
    QAction *actionsaveas;
    QAction *action_Sobel;
    QAction *action_LinearGray;
    QAction *action_PieceWiselinearGray;
    QAction *action_LoglinearGray;
    QAction *action_PowerLawlinearGray;
    QAction *action_CutColor;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action1_2;
    QAction *action2_2;
    QAction *action3_2;
    QAction *action4_2;
    QAction *action_SpaceFilter;
    QAction *action_FreqFilter;
    QAction *actionvideo;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *resultView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *revokeBtn;
    QPushButton *clearResult;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_image;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(828, 580);
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
        action_Dct = new QAction(MainWindow);
        action_Dct->setObjectName(QStringLiteral("action_Dct"));
        actionsaveas = new QAction(MainWindow);
        actionsaveas->setObjectName(QStringLiteral("actionsaveas"));
        action_Sobel = new QAction(MainWindow);
        action_Sobel->setObjectName(QStringLiteral("action_Sobel"));
        action_LinearGray = new QAction(MainWindow);
        action_LinearGray->setObjectName(QStringLiteral("action_LinearGray"));
        action_PieceWiselinearGray = new QAction(MainWindow);
        action_PieceWiselinearGray->setObjectName(QStringLiteral("action_PieceWiselinearGray"));
        action_LoglinearGray = new QAction(MainWindow);
        action_LoglinearGray->setObjectName(QStringLiteral("action_LoglinearGray"));
        action_PowerLawlinearGray = new QAction(MainWindow);
        action_PowerLawlinearGray->setObjectName(QStringLiteral("action_PowerLawlinearGray"));
        action_CutColor = new QAction(MainWindow);
        action_CutColor->setObjectName(QStringLiteral("action_CutColor"));
        action1 = new QAction(MainWindow);
        action1->setObjectName(QStringLiteral("action1"));
        action2 = new QAction(MainWindow);
        action2->setObjectName(QStringLiteral("action2"));
        action3 = new QAction(MainWindow);
        action3->setObjectName(QStringLiteral("action3"));
        action4 = new QAction(MainWindow);
        action4->setObjectName(QStringLiteral("action4"));
        action1_2 = new QAction(MainWindow);
        action1_2->setObjectName(QStringLiteral("action1_2"));
        action2_2 = new QAction(MainWindow);
        action2_2->setObjectName(QStringLiteral("action2_2"));
        action3_2 = new QAction(MainWindow);
        action3_2->setObjectName(QStringLiteral("action3_2"));
        action4_2 = new QAction(MainWindow);
        action4_2->setObjectName(QStringLiteral("action4_2"));
        action_SpaceFilter = new QAction(MainWindow);
        action_SpaceFilter->setObjectName(QStringLiteral("action_SpaceFilter"));
        action_FreqFilter = new QAction(MainWindow);
        action_FreqFilter->setObjectName(QStringLiteral("action_FreqFilter"));
        actionvideo = new QAction(MainWindow);
        actionvideo->setObjectName(QStringLiteral("actionvideo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        resultView = new QGraphicsView(layoutWidget);
        resultView->setObjectName(QStringLiteral("resultView"));

        verticalLayout_3->addWidget(resultView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        revokeBtn = new QPushButton(layoutWidget);
        revokeBtn->setObjectName(QStringLiteral("revokeBtn"));

        horizontalLayout_2->addWidget(revokeBtn);

        clearResult = new QPushButton(layoutWidget);
        clearResult->setObjectName(QStringLiteral("clearResult"));
        clearResult->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(clearResult);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        splitter->addWidget(layoutWidget);

        horizontalLayout_3->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 828, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_image = new QMenu(menuBar);
        menu_image->setObjectName(QStringLiteral("menu_image"));
        menu_2 = new QMenu(menu_image);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menu_image);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_image->menuAction());
        menu->addAction(actionopen);
        menu->addSeparator();
        menu->addAction(actionsave);
        menu->addAction(actionsaveas);
        menu_image->addAction(action_Gray);
        menu_image->addAction(menu_2->menuAction());
        menu_image->addAction(action_Binary);
        menu_image->addAction(action_CutColor);
        menu_image->addAction(action_Hist);
        menu_image->addAction(menu_3->menuAction());
        menu_image->addAction(action_Dct);
        menu_image->addAction(action_Sobel);
        menu_2->addAction(action_LinearGray);
        menu_2->addAction(action_PieceWiselinearGray);
        menu_2->addAction(action_LoglinearGray);
        menu_2->addAction(action_PowerLawlinearGray);
        menu_3->addAction(action_SpaceFilter);
        menu_3->addAction(action_FreqFilter);

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
        action_Dct->setText(QApplication::translate("MainWindow", "\347\246\273\346\225\243\344\275\231\345\274\246\345\217\230\346\215\242", Q_NULLPTR));
        actionsaveas->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        action_Sobel->setText(QApplication::translate("MainWindow", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        action_LinearGray->setText(QApplication::translate("MainWindow", "\347\272\277\346\200\247\345\217\230\346\215\242", Q_NULLPTR));
        action_PieceWiselinearGray->setText(QApplication::translate("MainWindow", "\347\272\277\346\200\247\345\210\206\346\256\265\345\217\230\346\215\242", Q_NULLPTR));
        action_LoglinearGray->setText(QApplication::translate("MainWindow", "\345\257\271\346\225\260\345\217\230\346\215\242", Q_NULLPTR));
        action_PowerLawlinearGray->setText(QApplication::translate("MainWindow", "\345\271\202\347\216\207\345\217\230\346\215\242", Q_NULLPTR));
        action_CutColor->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262\347\251\272\351\227\264\347\274\251\345\207\217", Q_NULLPTR));
        action1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        action2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        action3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        action4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        action1_2->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        action2_2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        action3_2->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        action4_2->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        action_SpaceFilter->setText(QApplication::translate("MainWindow", "\347\251\272\351\227\264\346\273\244\346\263\242", Q_NULLPTR));
        action_SpaceFilter->setIconText(QApplication::translate("MainWindow", "\347\251\272\351\227\264\346\273\244\346\263\242", Q_NULLPTR));
        action_FreqFilter->setText(QApplication::translate("MainWindow", "\351\242\221\345\237\237\346\273\244\346\263\242", Q_NULLPTR));
        action_FreqFilter->setIconText(QApplication::translate("MainWindow", "\351\242\221\345\237\237\346\273\244\346\263\242", Q_NULLPTR));
        actionvideo->setText(QApplication::translate("MainWindow", "\350\247\206\351\242\221\345\244\204\347\220\206", Q_NULLPTR));
        revokeBtn->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", Q_NULLPTR));
        clearResult->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_image->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\201\260\345\272\246\345\217\230\346\215\242", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\273\244\346\263\242", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
