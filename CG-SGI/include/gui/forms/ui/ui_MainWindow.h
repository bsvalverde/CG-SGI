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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
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
    QGroupBox *groupZoom;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnZoomOut;
    QSlider *zoomControl;
    QPushButton *btnZoomIn;
    QGroupBox *groupNavigation;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *btnCenter;
    QPushButton *btnUp;
    QPushButton *btnRight;
    QPushButton *btnLeft;
    QPushButton *btnDown;
    QSpacerItem *horizontalSpacer2;
    QWidget *pageObjects;
    QPushButton *btnRemoveObject;
    QPushButton *btnInsertObject;
    QTableWidget *tableObjects;
    QPushButton *btnTransformObject;
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
        groupZoom = new QGroupBox(pageWindow);
        groupZoom->setObjectName(QStringLiteral("groupZoom"));
        groupZoom->setGeometry(QRect(9, 0, 241, 61));
        groupZoom->setStyleSheet(QLatin1String("QGroupBox  {\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"}\n"
" \n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"}"));
        horizontalLayoutWidget_2 = new QWidget(groupZoom);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(9, 20, 221, 35));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnZoomOut = new QPushButton(horizontalLayoutWidget_2);
        btnZoomOut->setObjectName(QStringLiteral("btnZoomOut"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(35);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnZoomOut->sizePolicy().hasHeightForWidth());
        btnZoomOut->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        font1.setItalic(false);
        btnZoomOut->setFont(font1);

        horizontalLayout_2->addWidget(btnZoomOut);

        zoomControl = new QSlider(horizontalLayoutWidget_2);
        zoomControl->setObjectName(QStringLiteral("zoomControl"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(90);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(zoomControl->sizePolicy().hasHeightForWidth());
        zoomControl->setSizePolicy(sizePolicy3);
        zoomControl->setMaximum(100);
        zoomControl->setValue(50);
        zoomControl->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(zoomControl);

        btnZoomIn = new QPushButton(horizontalLayoutWidget_2);
        btnZoomIn->setObjectName(QStringLiteral("btnZoomIn"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(35);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnZoomIn->sizePolicy().hasHeightForWidth());
        btnZoomIn->setSizePolicy(sizePolicy4);
        btnZoomIn->setFont(font1);

        horizontalLayout_2->addWidget(btnZoomIn);

        groupNavigation = new QGroupBox(pageWindow);
        groupNavigation->setObjectName(QStringLiteral("groupNavigation"));
        groupNavigation->setGeometry(QRect(9, 70, 241, 161));
        groupNavigation->setStyleSheet(QLatin1String("QGroupBox  {\n"
"    border: 1px solid gray;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"}\n"
" \n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 8px;\n"
"}"));
        horizontalLayoutWidget_3 = new QWidget(groupNavigation);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(9, 19, 221, 131));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btnCenter = new QPushButton(horizontalLayoutWidget_3);
        btnCenter->setObjectName(QStringLiteral("btnCenter"));
        btnCenter->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(35);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnCenter->sizePolicy().hasHeightForWidth());
        btnCenter->setSizePolicy(sizePolicy5);
        QFont font2;
        font2.setPointSize(14);
        font2.setItalic(true);
        btnCenter->setFont(font2);

        gridLayout->addWidget(btnCenter, 1, 1, 1, 1);

        btnUp = new QPushButton(horizontalLayoutWidget_3);
        btnUp->setObjectName(QStringLiteral("btnUp"));
        sizePolicy5.setHeightForWidth(btnUp->sizePolicy().hasHeightForWidth());
        btnUp->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(btnUp, 0, 1, 1, 1);

        btnRight = new QPushButton(horizontalLayoutWidget_3);
        btnRight->setObjectName(QStringLiteral("btnRight"));
        sizePolicy5.setHeightForWidth(btnRight->sizePolicy().hasHeightForWidth());
        btnRight->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(btnRight, 1, 2, 1, 1);

        btnLeft = new QPushButton(horizontalLayoutWidget_3);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));
        sizePolicy5.setHeightForWidth(btnLeft->sizePolicy().hasHeightForWidth());
        btnLeft->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(btnLeft, 1, 0, 1, 1);

        btnDown = new QPushButton(horizontalLayoutWidget_3);
        btnDown->setObjectName(QStringLiteral("btnDown"));
        sizePolicy5.setHeightForWidth(btnDown->sizePolicy().hasHeightForWidth());
        btnDown->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(btnDown, 2, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        horizontalSpacer2 = new QSpacerItem(30, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer2);

        toolBox->addItem(pageWindow, QString::fromUtf8("Controle de Visualiza\303\247\303\243o"));
        pageObjects = new QWidget();
        pageObjects->setObjectName(QStringLiteral("pageObjects"));
        pageObjects->setGeometry(QRect(0, 0, 100, 30));
        btnRemoveObject = new QPushButton(pageObjects);
        btnRemoveObject->setObjectName(QStringLiteral("btnRemoveObject"));
        btnRemoveObject->setGeometry(QRect(110, 380, 71, 31));
        QFont font3;
        font3.setPointSize(10);
        btnRemoveObject->setFont(font3);
        btnInsertObject = new QPushButton(pageObjects);
        btnInsertObject->setObjectName(QStringLiteral("btnInsertObject"));
        btnInsertObject->setGeometry(QRect(190, 380, 61, 31));
        btnInsertObject->setFont(font3);
        tableObjects = new QTableWidget(pageObjects);
        if (tableObjects->columnCount() < 2)
            tableObjects->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableObjects->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableObjects->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableObjects->setObjectName(QStringLiteral("tableObjects"));
        tableObjects->setGeometry(QRect(10, 1, 241, 371));
        QFont font4;
        font4.setPointSize(10);
        font4.setItalic(false);
        tableObjects->setFont(font4);
        tableObjects->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableObjects->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableObjects->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableObjects->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableObjects->setTabKeyNavigation(false);
        tableObjects->setSelectionMode(QAbstractItemView::SingleSelection);
        tableObjects->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableObjects->setShowGrid(true);
        tableObjects->setGridStyle(Qt::DotLine);
        tableObjects->setWordWrap(true);
        tableObjects->setCornerButtonEnabled(false);
        tableObjects->horizontalHeader()->setVisible(false);
        tableObjects->horizontalHeader()->setCascadingSectionResizes(false);
        tableObjects->horizontalHeader()->setDefaultSectionSize(80);
        tableObjects->horizontalHeader()->setHighlightSections(false);
        tableObjects->horizontalHeader()->setMinimumSectionSize(50);
        tableObjects->horizontalHeader()->setStretchLastSection(true);
        tableObjects->verticalHeader()->setVisible(false);
        tableObjects->verticalHeader()->setDefaultSectionSize(17);
        tableObjects->verticalHeader()->setMinimumSectionSize(15);
        tableObjects->verticalHeader()->setStretchLastSection(false);
        btnTransformObject = new QPushButton(pageObjects);
        btnTransformObject->setObjectName(QStringLiteral("btnTransformObject"));
        btnTransformObject->setGeometry(QRect(10, 380, 91, 31));
        btnTransformObject->setFont(font3);
        toolBox->addItem(pageObjects, QStringLiteral("Objetos"));

        horizontalLayout->addWidget(toolBox);

        graphicsView = new QGraphicsView(horizontalLayoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(200);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy6);

        horizontalLayout->addWidget(graphicsView);

        QWidget::setTabOrder(graphicsView, btnZoomOut);
        QWidget::setTabOrder(btnZoomOut, zoomControl);
        QWidget::setTabOrder(zoomControl, btnZoomIn);
        QWidget::setTabOrder(btnZoomIn, btnLeft);
        QWidget::setTabOrder(btnLeft, btnCenter);
        QWidget::setTabOrder(btnCenter, btnRight);
        QWidget::setTabOrder(btnRight, btnDown);
        QWidget::setTabOrder(btnDown, btnRemoveObject);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sistema Gr\303\241fico Interativo", 0));
        groupZoom->setTitle(QApplication::translate("MainWindow", "Zoom", 0));
        btnZoomOut->setText(QApplication::translate("MainWindow", "-", 0));
        btnZoomOut->setShortcut(QApplication::translate("MainWindow", "Alt+O", 0));
        btnZoomIn->setText(QApplication::translate("MainWindow", "+", 0));
        btnZoomIn->setShortcut(QApplication::translate("MainWindow", "Alt+I", 0));
        groupNavigation->setTitle(QApplication::translate("MainWindow", "Navega\303\247\303\243o", 0));
        btnCenter->setText(QApplication::translate("MainWindow", "\342\227\211", 0));
        btnCenter->setShortcut(QApplication::translate("MainWindow", "Home", 0));
        btnUp->setText(QApplication::translate("MainWindow", "\342\226\262", 0));
        btnUp->setShortcut(QApplication::translate("MainWindow", "Up", 0));
        btnRight->setText(QApplication::translate("MainWindow", "\342\226\266", 0));
        btnRight->setShortcut(QApplication::translate("MainWindow", "Right", 0));
        btnLeft->setText(QApplication::translate("MainWindow", "\342\227\200", 0));
        btnLeft->setShortcut(QApplication::translate("MainWindow", "Left", 0));
        btnDown->setText(QApplication::translate("MainWindow", "\342\226\274", 0));
        btnDown->setShortcut(QApplication::translate("MainWindow", "Down", 0));
        toolBox->setItemText(toolBox->indexOf(pageWindow), QApplication::translate("MainWindow", "Controle de Visualiza\303\247\303\243o", 0));
        btnRemoveObject->setText(QApplication::translate("MainWindow", "Remover", 0));
        btnRemoveObject->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        btnInsertObject->setText(QApplication::translate("MainWindow", "Inserir", 0));
        btnInsertObject->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0));
        QTableWidgetItem *___qtablewidgetitem = tableObjects->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Tipo", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableObjects->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Nome", 0));
        btnTransformObject->setText(QApplication::translate("MainWindow", "Transformar", 0));
        btnTransformObject->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0));
        toolBox->setItemText(toolBox->indexOf(pageObjects), QApplication::translate("MainWindow", "Objetos", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
