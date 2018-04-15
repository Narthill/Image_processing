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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
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
    QAction *actionGray;
    QAction *actionCutColor;
    QAction *actionSpaceFilter;
    QAction *actionSobel;
    QAction *actionHistogram;
    QAction *actionBinary;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *videoLabel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *timeLabel;
    QFrame *line;
    QSlider *videoSlider;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *playBtn;
    QPushButton *pauseBtn;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_video;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *videoProcessing)
    {
        if (videoProcessing->objectName().isEmpty())
            videoProcessing->setObjectName(QStringLiteral("videoProcessing"));
        videoProcessing->resize(717, 607);
        actionopen = new QAction(videoProcessing);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionsave = new QAction(videoProcessing);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionsaveAs = new QAction(videoProcessing);
        actionsaveAs->setObjectName(QStringLiteral("actionsaveAs"));
        actionGray = new QAction(videoProcessing);
        actionGray->setObjectName(QStringLiteral("actionGray"));
        actionCutColor = new QAction(videoProcessing);
        actionCutColor->setObjectName(QStringLiteral("actionCutColor"));
        actionSpaceFilter = new QAction(videoProcessing);
        actionSpaceFilter->setObjectName(QStringLiteral("actionSpaceFilter"));
        actionSobel = new QAction(videoProcessing);
        actionSobel->setObjectName(QStringLiteral("actionSobel"));
        actionHistogram = new QAction(videoProcessing);
        actionHistogram->setObjectName(QStringLiteral("actionHistogram"));
        actionBinary = new QAction(videoProcessing);
        actionBinary->setObjectName(QStringLiteral("actionBinary"));
        centralWidget = new QWidget(videoProcessing);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        videoLabel = new QLabel(frame);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));
        videoLabel->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout_2->addWidget(videoLabel);


        verticalLayout->addWidget(frame);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        timeLabel = new QLabel(groupBox);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy);
        timeLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(timeLabel);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        videoSlider = new QSlider(groupBox);
        videoSlider->setObjectName(QStringLiteral("videoSlider"));
        videoSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(videoSlider);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(2, 6);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer = new QSpacerItem(98, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        playBtn = new QPushButton(groupBox_2);
        playBtn->setObjectName(QStringLiteral("playBtn"));

        horizontalLayout->addWidget(playBtn);

        pauseBtn = new QPushButton(groupBox_2);
        pauseBtn->setObjectName(QStringLiteral("pauseBtn"));

        horizontalLayout->addWidget(pauseBtn);

        horizontalSpacer_2 = new QSpacerItem(217, 35, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);

        verticalLayout->addWidget(groupBox_2);

        verticalLayout->setStretch(0, 7);
        verticalLayout->setStretch(1, 1);
        videoProcessing->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(videoProcessing);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_video = new QMenu(menuBar);
        menu_video->setObjectName(QStringLiteral("menu_video"));
        videoProcessing->setMenuBar(menuBar);
        mainToolBar = new QToolBar(videoProcessing);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        videoProcessing->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(videoProcessing);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        videoProcessing->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_video->menuAction());
        menu->addAction(actionopen);
        menu->addSeparator();
        menu->addAction(actionsave);
        menu->addAction(actionsaveAs);
        menu_video->addAction(actionGray);
        menu_video->addAction(actionCutColor);
        menu_video->addAction(actionSpaceFilter);
        menu_video->addAction(actionSobel);
        menu_video->addAction(actionHistogram);
        menu_video->addAction(actionBinary);

        retranslateUi(videoProcessing);

        QMetaObject::connectSlotsByName(videoProcessing);
    } // setupUi

    void retranslateUi(QMainWindow *videoProcessing)
    {
        videoProcessing->setWindowTitle(QApplication::translate("videoProcessing", "videoProcessing", Q_NULLPTR));
        actionopen->setText(QApplication::translate("videoProcessing", "\346\211\223\345\274\200\350\247\206\351\242\221", Q_NULLPTR));
        actionsave->setText(QApplication::translate("videoProcessing", "\344\277\235\345\255\230", Q_NULLPTR));
        actionsaveAs->setText(QApplication::translate("videoProcessing", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        actionGray->setText(QApplication::translate("videoProcessing", "\347\201\260\345\272\246\345\214\226", Q_NULLPTR));
        actionGray->setIconText(QApplication::translate("videoProcessing", "\347\201\260\345\272\246\345\214\226", Q_NULLPTR));
        actionCutColor->setText(QApplication::translate("videoProcessing", "\351\242\234\350\211\262\347\251\272\351\227\264\347\274\251\345\207\217", Q_NULLPTR));
        actionSpaceFilter->setText(QApplication::translate("videoProcessing", "\347\251\272\351\227\264\346\273\244\346\263\242", Q_NULLPTR));
        actionSobel->setText(QApplication::translate("videoProcessing", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        actionHistogram->setText(QApplication::translate("videoProcessing", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", Q_NULLPTR));
        actionBinary->setText(QApplication::translate("videoProcessing", "\344\272\214\345\200\274\345\214\226", Q_NULLPTR));
        videoLabel->setText(QString());
        groupBox->setTitle(QApplication::translate("videoProcessing", "\345\211\251\344\275\231\346\227\266\351\225\277", Q_NULLPTR));
        timeLabel->setText(QString());
        groupBox_2->setTitle(QString());
        playBtn->setText(QApplication::translate("videoProcessing", "\346\222\255\346\224\276", Q_NULLPTR));
        pauseBtn->setText(QApplication::translate("videoProcessing", "\346\232\202\345\201\234", Q_NULLPTR));
        menu->setTitle(QApplication::translate("videoProcessing", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_video->setTitle(QApplication::translate("videoProcessing", "\350\247\206\351\242\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class videoProcessing: public Ui_videoProcessing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPROCESSING_H
