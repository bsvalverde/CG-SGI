/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolBox *toolBox;
    QWidget *pageWindow;
    QSlider *zoomControl;
    QLabel *labelZoom;
    QPushButton *btnZoomIn;
    QPushButton *btnZoomOut;
    QLabel *labelNavigation;
    QPushButton *btnUp;
    QPushButton *btnRight;
    QPushButton *btnDown;
    QPushButton *btnLeft;
    QPushButton *btnCenter;
    QWidget *pageObjects;
    QListView *displayFIle;
    QPushButton *btnInsertObject;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 500));
        MainWindow->setMaximumSize(QSize(800, 500));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        horizontalLayoutWidget = new QWidget(MainWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 481));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(horizontalLayoutWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy1);
        pageWindow = new QWidget();
        pageWindow->setObjectName(QStringLiteral("pageWindow"));
        pageWindow->setGeometry(QRect(0, 0, 256, 415));
        zoomControl = new QSlider(pageWindow);
        zoomControl->setObjectName(QStringLiteral("zoomControl"));
        zoomControl->setGeometry(QRect(60, 40, 141, 31));
        zoomControl->setMaximum(100);
        zoomControl->setOrientation(Qt::Horizontal);
        labelZoom = new QLabel(pageWindow);
        labelZoom->setObjectName(QStringLiteral("labelZoom"));
        labelZoom->setGeometry(QRect(16, 6, 231, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        labelZoom->setFont(font1);
        btnZoomIn = new QPushButton(pageWindow);
        btnZoomIn->setObjectName(QStringLiteral("btnZoomIn"));
        btnZoomIn->setGeometry(QRect(210, 40, 41, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setItalic(true);
        btnZoomIn->setFont(font2);
        btnZoomOut = new QPushButton(pageWindow);
        btnZoomOut->setObjectName(QStringLiteral("btnZoomOut"));
        btnZoomOut->setGeometry(QRect(10, 40, 41, 31));
        btnZoomOut->setFont(font2);
        labelNavigation = new QLabel(pageWindow);
        labelNavigation->setObjectName(QStringLiteral("labelNavigation"));
        labelNavigation->setGeometry(QRect(10, 80, 241, 31));
        labelNavigation->setFont(font1);
        btnUp = new QPushButton(pageWindow);
        btnUp->setObjectName(QStringLiteral("btnUp"));
        btnUp->setGeometry(QRect(100, 110, 41, 41));
        btnRight = new QPushButton(pageWindow);
        btnRight->setObjectName(QStringLiteral("btnRight"));
        btnRight->setGeometry(QRect(150, 160, 41, 41));
        btnDown = new QPushButton(pageWindow);
        btnDown->setObjectName(QStringLiteral("btnDown"));
        btnDown->setGeometry(QRect(100, 210, 41, 41));
        btnLeft = new QPushButton(pageWindow);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));
        btnLeft->setGeometry(QRect(50, 160, 41, 41));
        btnCenter = new QPushButton(pageWindow);
        btnCenter->setObjectName(QStringLiteral("btnCenter"));
        btnCenter->setGeometry(QRect(100, 160, 41, 41));
        btnCenter->setFont(font2);
        toolBox->addItem(pageWindow, QStringLiteral("Controle da Window"));
        pageObjects = new QWidget();
        pageObjects->setObjectName(QStringLiteral("pageObjects"));
        pageObjects->setGeometry(QRect(0, 0, 256, 415));
        displayFIle = new QListView(pageObjects);
        displayFIle->setObjectName(QStringLiteral("displayFIle"));
        displayFIle->setGeometry(QRect(10, 1, 241, 371));
        btnInsertObject = new QPushButton(pageObjects);
        btnInsertObject->setObjectName(QStringLiteral("btnInsertObject"));
        btnInsertObject->setGeometry(QRect(8, 380, 241, 27));
        toolBox->addItem(pageObjects, QStringLiteral("Objetos"));

        horizontalLayout->addWidget(toolBox);

        graphicsView = new QGraphicsView(horizontalLayoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(200);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(graphicsView);

        QWidget::setTabOrder(graphicsView, btnZoomOut);
        QWidget::setTabOrder(btnZoomOut, zoomControl);
        QWidget::setTabOrder(zoomControl, btnZoomIn);
        QWidget::setTabOrder(btnZoomIn, btnUp);
        QWidget::setTabOrder(btnUp, btnLeft);
        QWidget::setTabOrder(btnLeft, btnCenter);
        QWidget::setTabOrder(btnCenter, btnRight);
        QWidget::setTabOrder(btnRight, btnDown);
        QWidget::setTabOrder(btnDown, displayFIle);
        QWidget::setTabOrder(displayFIle, btnInsertObject);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sistema Gr\303\241fico Interativo", 0));
        labelZoom->setText(QApplication::translate("MainWindow", "Zoom", 0));
        btnZoomIn->setText(QApplication::translate("MainWindow", "+", 0));
        btnZoomOut->setText(QApplication::translate("MainWindow", "-", 0));
        labelNavigation->setText(QApplication::translate("MainWindow", "Navega\303\247\303\243o", 0));
        btnUp->setText(QApplication::translate("MainWindow", "\342\226\262", 0));
        btnRight->setText(QApplication::translate("MainWindow", "\342\226\266", 0));
        btnDown->setText(QApplication::translate("MainWindow", "\342\226\274", 0));
        btnLeft->setText(QApplication::translate("MainWindow", "\342\227\200", 0));
        btnCenter->setText(QApplication::translate("MainWindow", "\342\227\211", 0));
        toolBox->setItemText(toolBox->indexOf(pageWindow), QApplication::translate("MainWindow", "Controle da Window", 0));
        btnInsertObject->setText(QApplication::translate("MainWindow", "Inserir Objeto", 0));
        toolBox->setItemText(toolBox->indexOf(pageObjects), QApplication::translate("MainWindow", "Objetos", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
