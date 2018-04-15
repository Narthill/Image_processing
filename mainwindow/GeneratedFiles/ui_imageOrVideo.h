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

class Ui_imageOrVideo
{
public:
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *imageBtn;
    QPushButton *videoBtn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *imageOrVideo)
    {
        if (imageOrVideo->objectName().isEmpty())
            imageOrVideo->setObjectName(QStringLiteral("imageOrVideo"));
        imageOrVideo->setWindowModality(Qt::NonModal);
        imageOrVideo->resize(514, 411);
        actionAbout = new QAction(imageOrVideo);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(imageOrVideo);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(30);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imageBtn = new QPushButton(centralWidget);
        imageBtn->setObjectName(QStringLiteral("imageBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageBtn->sizePolicy().hasHeightForWidth());
        imageBtn->setSizePolicy(sizePolicy);
        imageBtn->setAutoDefault(false);
        imageBtn->setFlat(false);

        horizontalLayout->addWidget(imageBtn);

        videoBtn = new QPushButton(centralWidget);
        videoBtn->setObjectName(QStringLiteral("videoBtn"));
        sizePolicy.setHeightForWidth(videoBtn->sizePolicy().hasHeightForWidth());
        videoBtn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(videoBtn);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 1);
        imageOrVideo->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(imageOrVideo);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        imageOrVideo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(imageOrVideo);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        imageOrVideo->setStatusBar(statusBar);
        menuBar = new QMenuBar(imageOrVideo);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 514, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        imageOrVideo->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionAbout);

        retranslateUi(imageOrVideo);

        imageBtn->setDefault(false);


        QMetaObject::connectSlotsByName(imageOrVideo);
    } // setupUi

    void retranslateUi(QMainWindow *imageOrVideo)
    {
        imageOrVideo->setWindowTitle(QApplication::translate("imageOrVideo", "imageOrVideo", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("imageOrVideo", "\345\205\263\344\272\216", Q_NULLPTR));
        actionAbout->setIconText(QApplication::translate("imageOrVideo", "\345\205\263\344\272\216", Q_NULLPTR));
        label->setText(QApplication::translate("imageOrVideo", "\345\233\276\345\203\217\350\247\206\351\242\221\345\244\204\347\220\206", Q_NULLPTR));
        imageBtn->setText(QApplication::translate("imageOrVideo", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR));
        videoBtn->setText(QApplication::translate("imageOrVideo", "\350\247\206\351\242\221\345\244\204\347\220\206", Q_NULLPTR));
        menu->setTitle(QApplication::translate("imageOrVideo", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class imageOrVideo: public Ui_imageOrVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEORVIDEO_H
