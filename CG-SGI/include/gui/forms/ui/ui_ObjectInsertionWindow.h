/********************************************************************************
** Form generated from reading UI file 'ObjectInsertionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTINSERTIONWINDOW_H
#define UI_OBJECTINSERTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectInsertionWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout2;
    QPushButton *btnCancel;
    QPushButton *btnInsert;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabObjects;
    QWidget *tabPoint;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout_2;
    QLabel *labelPointX;
    QLineEdit *fieldPointX;
    QFormLayout *formLayout_3;
    QLabel *labelPointY1;
    QLineEdit *fieldPointY;
    QFormLayout *formLayout_4;
    QLabel *labelPointZ1;
    QLineEdit *fieldPointZ;
    QWidget *tabLine;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout_5;
    QLabel *labelPointX1_2;
    QLineEdit *fieldLineX1;
    QFormLayout *formLayout_6;
    QLabel *labelPointY1_2;
    QLineEdit *fieldLineY1;
    QFormLayout *formLayout_7;
    QLabel *labelPointZ1_2;
    QLineEdit *fieldLineZ1;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout_8;
    QLabel *labelPointX1_3;
    QLineEdit *fieldLineX2;
    QFormLayout *formLayout_9;
    QLabel *labelPointY1_3;
    QLineEdit *fieldLineY2;
    QFormLayout *formLayout_10;
    QLabel *labelPointZ1_3;
    QLineEdit *fieldLineZ2;
    QWidget *tabPoligon;
    QTableWidget *tablePoligonPoints;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout2_2;
    QPushButton *btnRemovePoint;
    QPushButton *btnInsertPoint;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *fieldName;
    QFormLayout *formLayout_11;
    QLabel *labelColor;
    QPushButton *btnColor;

    void setupUi(QWidget *ObjectInsertionWindow)
    {
        if (ObjectInsertionWindow->objectName().isEmpty())
            ObjectInsertionWindow->setObjectName(QStringLiteral("ObjectInsertionWindow"));
        ObjectInsertionWindow->setWindowModality(Qt::NonModal);
        ObjectInsertionWindow->resize(400, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ObjectInsertionWindow->sizePolicy().hasHeightForWidth());
        ObjectInsertionWindow->setSizePolicy(sizePolicy);
        ObjectInsertionWindow->setMinimumSize(QSize(400, 400));
        ObjectInsertionWindow->setMaximumSize(QSize(400, 400));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        ObjectInsertionWindow->setFont(font);
        ObjectInsertionWindow->setAutoFillBackground(false);
        gridLayoutWidget = new QWidget(ObjectInsertionWindow);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 381, 381));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout2 = new QGridLayout();
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        gridLayout2->addWidget(btnCancel, 0, 0, 1, 1);

        btnInsert = new QPushButton(gridLayoutWidget);
        btnInsert->setObjectName(QStringLiteral("btnInsert"));

        gridLayout2->addWidget(btnInsert, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout2, 5, 0, 1, 1);

        tabObjects = new QTabWidget(gridLayoutWidget);
        tabObjects->setObjectName(QStringLiteral("tabObjects"));
        tabPoint = new QWidget();
        tabPoint->setObjectName(QStringLiteral("tabPoint"));
        groupBox = new QGroupBox(tabPoint);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 351, 71));
        groupBox->setStyleSheet(QLatin1String("QGroupBox  {\n"
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
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 331, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(-1, 5, -1, 5);
        labelPointX = new QLabel(layoutWidget);
        labelPointX->setObjectName(QStringLiteral("labelPointX"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelPointX);

        fieldPointX = new QLineEdit(layoutWidget);
        fieldPointX->setObjectName(QStringLiteral("fieldPointX"));
        fieldPointX->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fieldPointX->sizePolicy().hasHeightForWidth());
        fieldPointX->setSizePolicy(sizePolicy1);
        fieldPointX->setMaximumSize(QSize(16777214, 30));
        fieldPointX->setMaxLength(50);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, fieldPointX);


        horizontalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(-1, 5, -1, 5);
        labelPointY1 = new QLabel(layoutWidget);
        labelPointY1->setObjectName(QStringLiteral("labelPointY1"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelPointY1);

        fieldPointY = new QLineEdit(layoutWidget);
        fieldPointY->setObjectName(QStringLiteral("fieldPointY"));
        sizePolicy1.setHeightForWidth(fieldPointY->sizePolicy().hasHeightForWidth());
        fieldPointY->setSizePolicy(sizePolicy1);
        fieldPointY->setMaximumSize(QSize(16777215, 30));
        fieldPointY->setMaxLength(50);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, fieldPointY);


        horizontalLayout->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(-1, 5, -1, 5);
        labelPointZ1 = new QLabel(layoutWidget);
        labelPointZ1->setObjectName(QStringLiteral("labelPointZ1"));
        labelPointZ1->setEnabled(false);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, labelPointZ1);

        fieldPointZ = new QLineEdit(layoutWidget);
        fieldPointZ->setObjectName(QStringLiteral("fieldPointZ"));
        fieldPointZ->setEnabled(false);
        sizePolicy1.setHeightForWidth(fieldPointZ->sizePolicy().hasHeightForWidth());
        fieldPointZ->setSizePolicy(sizePolicy1);
        fieldPointZ->setMaximumSize(QSize(16777215, 30));
        fieldPointZ->setMaxLength(50);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, fieldPointZ);


        horizontalLayout->addLayout(formLayout_4);

        tabObjects->addTab(tabPoint, QString());
        tabLine = new QWidget();
        tabLine->setObjectName(QStringLiteral("tabLine"));
        groupBox_2 = new QGroupBox(tabLine);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 351, 71));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox  {\n"
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
        layoutWidget_3 = new QWidget(groupBox_2);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 20, 331, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setContentsMargins(-1, 5, -1, 5);
        labelPointX1_2 = new QLabel(layoutWidget_3);
        labelPointX1_2->setObjectName(QStringLiteral("labelPointX1_2"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelPointX1_2);

        fieldLineX1 = new QLineEdit(layoutWidget_3);
        fieldLineX1->setObjectName(QStringLiteral("fieldLineX1"));
        sizePolicy1.setHeightForWidth(fieldLineX1->sizePolicy().hasHeightForWidth());
        fieldLineX1->setSizePolicy(sizePolicy1);
        fieldLineX1->setMaximumSize(QSize(16777214, 30));
        fieldLineX1->setMaxLength(50);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, fieldLineX1);


        horizontalLayout_2->addLayout(formLayout_5);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setContentsMargins(-1, 5, -1, 5);
        labelPointY1_2 = new QLabel(layoutWidget_3);
        labelPointY1_2->setObjectName(QStringLiteral("labelPointY1_2"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, labelPointY1_2);

        fieldLineY1 = new QLineEdit(layoutWidget_3);
        fieldLineY1->setObjectName(QStringLiteral("fieldLineY1"));
        sizePolicy1.setHeightForWidth(fieldLineY1->sizePolicy().hasHeightForWidth());
        fieldLineY1->setSizePolicy(sizePolicy1);
        fieldLineY1->setMaximumSize(QSize(16777215, 30));
        fieldLineY1->setMaxLength(50);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, fieldLineY1);


        horizontalLayout_2->addLayout(formLayout_6);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        formLayout_7->setContentsMargins(-1, 5, -1, 5);
        labelPointZ1_2 = new QLabel(layoutWidget_3);
        labelPointZ1_2->setObjectName(QStringLiteral("labelPointZ1_2"));
        labelPointZ1_2->setEnabled(false);

        formLayout_7->setWidget(0, QFormLayout::LabelRole, labelPointZ1_2);

        fieldLineZ1 = new QLineEdit(layoutWidget_3);
        fieldLineZ1->setObjectName(QStringLiteral("fieldLineZ1"));
        fieldLineZ1->setEnabled(false);
        sizePolicy1.setHeightForWidth(fieldLineZ1->sizePolicy().hasHeightForWidth());
        fieldLineZ1->setSizePolicy(sizePolicy1);
        fieldLineZ1->setMaximumSize(QSize(16777215, 30));
        fieldLineZ1->setMaxLength(50);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, fieldLineZ1);


        horizontalLayout_2->addLayout(formLayout_7);

        groupBox_3 = new QGroupBox(tabLine);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 90, 351, 71));
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox  {\n"
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
        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 20, 331, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        formLayout_8->setContentsMargins(-1, 5, -1, 5);
        labelPointX1_3 = new QLabel(layoutWidget_4);
        labelPointX1_3->setObjectName(QStringLiteral("labelPointX1_3"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, labelPointX1_3);

        fieldLineX2 = new QLineEdit(layoutWidget_4);
        fieldLineX2->setObjectName(QStringLiteral("fieldLineX2"));
        sizePolicy1.setHeightForWidth(fieldLineX2->sizePolicy().hasHeightForWidth());
        fieldLineX2->setSizePolicy(sizePolicy1);
        fieldLineX2->setMaximumSize(QSize(16777214, 30));
        fieldLineX2->setMaxLength(50);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, fieldLineX2);


        horizontalLayout_3->addLayout(formLayout_8);

        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QStringLiteral("formLayout_9"));
        formLayout_9->setContentsMargins(-1, 5, -1, 5);
        labelPointY1_3 = new QLabel(layoutWidget_4);
        labelPointY1_3->setObjectName(QStringLiteral("labelPointY1_3"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, labelPointY1_3);

        fieldLineY2 = new QLineEdit(layoutWidget_4);
        fieldLineY2->setObjectName(QStringLiteral("fieldLineY2"));
        sizePolicy1.setHeightForWidth(fieldLineY2->sizePolicy().hasHeightForWidth());
        fieldLineY2->setSizePolicy(sizePolicy1);
        fieldLineY2->setMaximumSize(QSize(16777215, 30));
        fieldLineY2->setMaxLength(50);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, fieldLineY2);


        horizontalLayout_3->addLayout(formLayout_9);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QStringLiteral("formLayout_10"));
        formLayout_10->setContentsMargins(-1, 5, -1, 5);
        labelPointZ1_3 = new QLabel(layoutWidget_4);
        labelPointZ1_3->setObjectName(QStringLiteral("labelPointZ1_3"));
        labelPointZ1_3->setEnabled(false);

        formLayout_10->setWidget(0, QFormLayout::LabelRole, labelPointZ1_3);

        fieldLineZ2 = new QLineEdit(layoutWidget_4);
        fieldLineZ2->setObjectName(QStringLiteral("fieldLineZ2"));
        fieldLineZ2->setEnabled(false);
        sizePolicy1.setHeightForWidth(fieldLineZ2->sizePolicy().hasHeightForWidth());
        fieldLineZ2->setSizePolicy(sizePolicy1);
        fieldLineZ2->setMaximumSize(QSize(16777215, 30));
        fieldLineZ2->setMaxLength(50);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, fieldLineZ2);


        horizontalLayout_3->addLayout(formLayout_10);

        tabObjects->addTab(tabLine, QString());
        tabPoligon = new QWidget();
        tabPoligon->setObjectName(QStringLiteral("tabPoligon"));
        tablePoligonPoints = new QTableWidget(tabPoligon);
        if (tablePoligonPoints->columnCount() < 2)
            tablePoligonPoints->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablePoligonPoints->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablePoligonPoints->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tablePoligonPoints->setObjectName(QStringLiteral("tablePoligonPoints"));
        tablePoligonPoints->setGeometry(QRect(10, 11, 351, 201));
        tablePoligonPoints->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tablePoligonPoints->setSelectionMode(QAbstractItemView::SingleSelection);
        tablePoligonPoints->setSelectionBehavior(QAbstractItemView::SelectRows);
        tablePoligonPoints->setGridStyle(Qt::SolidLine);
        tablePoligonPoints->setCornerButtonEnabled(true);
        tablePoligonPoints->horizontalHeader()->setDefaultSectionSize(100);
        layoutWidget_2 = new QWidget(tabPoligon);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 220, 351, 31));
        gridLayout2_2 = new QGridLayout(layoutWidget_2);
        gridLayout2_2->setObjectName(QStringLiteral("gridLayout2_2"));
        gridLayout2_2->setContentsMargins(0, 0, 0, 0);
        btnRemovePoint = new QPushButton(layoutWidget_2);
        btnRemovePoint->setObjectName(QStringLiteral("btnRemovePoint"));

        gridLayout2_2->addWidget(btnRemovePoint, 0, 0, 1, 1);

        btnInsertPoint = new QPushButton(layoutWidget_2);
        btnInsertPoint->setObjectName(QStringLiteral("btnInsertPoint"));

        gridLayout2_2->addWidget(btnInsertPoint, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        tabObjects->addTab(tabPoligon, QString());

        gridLayout->addWidget(tabObjects, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(10, 5, 0, 10);
        labelName = new QLabel(gridLayoutWidget);
        labelName->setObjectName(QStringLiteral("labelName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelName);

        fieldName = new QLineEdit(gridLayoutWidget);
        fieldName->setObjectName(QStringLiteral("fieldName"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(30);
        sizePolicy2.setHeightForWidth(fieldName->sizePolicy().hasHeightForWidth());
        fieldName->setSizePolicy(sizePolicy2);
        fieldName->setMaxLength(25);

        formLayout->setWidget(0, QFormLayout::FieldRole, fieldName);


        horizontalLayout_4->addLayout(formLayout);

        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QStringLiteral("formLayout_11"));
        formLayout_11->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_11->setContentsMargins(10, 5, 10, 10);
        labelColor = new QLabel(gridLayoutWidget);
        labelColor->setObjectName(QStringLiteral("labelColor"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelColor->sizePolicy().hasHeightForWidth());
        labelColor->setSizePolicy(sizePolicy3);

        formLayout_11->setWidget(0, QFormLayout::LabelRole, labelColor);

        btnColor = new QPushButton(gridLayoutWidget);
        btnColor->setObjectName(QStringLiteral("btnColor"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(30);
        sizePolicy4.setHeightForWidth(btnColor->sizePolicy().hasHeightForWidth());
        btnColor->setSizePolicy(sizePolicy4);
        btnColor->setStyleSheet(QLatin1String("QPushButton  {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(0, 0, 0);\n"
"}"));

        formLayout_11->setWidget(0, QFormLayout::FieldRole, btnColor);


        horizontalLayout_4->addLayout(formLayout_11);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        QWidget::setTabOrder(fieldName, tabObjects);
        QWidget::setTabOrder(tabObjects, fieldPointX);
        QWidget::setTabOrder(fieldPointX, fieldPointY);
        QWidget::setTabOrder(fieldPointY, fieldPointZ);
        QWidget::setTabOrder(fieldPointZ, fieldLineX1);
        QWidget::setTabOrder(fieldLineX1, fieldLineY1);
        QWidget::setTabOrder(fieldLineY1, fieldLineZ1);
        QWidget::setTabOrder(fieldLineZ1, fieldLineX2);
        QWidget::setTabOrder(fieldLineX2, fieldLineY2);
        QWidget::setTabOrder(fieldLineY2, fieldLineZ2);
        QWidget::setTabOrder(fieldLineZ2, tablePoligonPoints);
        QWidget::setTabOrder(tablePoligonPoints, btnRemovePoint);
        QWidget::setTabOrder(btnRemovePoint, btnInsertPoint);
        QWidget::setTabOrder(btnInsertPoint, btnCancel);
        QWidget::setTabOrder(btnCancel, btnInsert);

        retranslateUi(ObjectInsertionWindow);

        tabObjects->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ObjectInsertionWindow);
    } // setupUi

    void retranslateUi(QWidget *ObjectInsertionWindow)
    {
        ObjectInsertionWindow->setWindowTitle(QApplication::translate("ObjectInsertionWindow", "Inserir Objeto", 0));
        btnCancel->setText(QApplication::translate("ObjectInsertionWindow", "Cancelar", 0));
        btnInsert->setText(QApplication::translate("ObjectInsertionWindow", "Ok", 0));
        groupBox->setTitle(QApplication::translate("ObjectInsertionWindow", "Coordenadas", 0));
        labelPointX->setText(QApplication::translate("ObjectInsertionWindow", "X", 0));
        fieldPointX->setText(QString());
        labelPointY1->setText(QApplication::translate("ObjectInsertionWindow", "Y", 0));
        labelPointZ1->setText(QApplication::translate("ObjectInsertionWindow", "Z", 0));
        fieldPointZ->setText(QApplication::translate("ObjectInsertionWindow", "1", 0));
        tabObjects->setTabText(tabObjects->indexOf(tabPoint), QApplication::translate("ObjectInsertionWindow", "Ponto", 0));
        groupBox_2->setTitle(QApplication::translate("ObjectInsertionWindow", "Ponto Inicial", 0));
        labelPointX1_2->setText(QApplication::translate("ObjectInsertionWindow", "x1", 0));
        labelPointY1_2->setText(QApplication::translate("ObjectInsertionWindow", "y1", 0));
        labelPointZ1_2->setText(QApplication::translate("ObjectInsertionWindow", "z1", 0));
        fieldLineZ1->setText(QApplication::translate("ObjectInsertionWindow", "1", 0));
        groupBox_3->setTitle(QApplication::translate("ObjectInsertionWindow", "Ponto Final", 0));
        labelPointX1_3->setText(QApplication::translate("ObjectInsertionWindow", "x2", 0));
        labelPointY1_3->setText(QApplication::translate("ObjectInsertionWindow", "y2", 0));
        labelPointZ1_3->setText(QApplication::translate("ObjectInsertionWindow", "z2", 0));
        fieldLineZ2->setText(QApplication::translate("ObjectInsertionWindow", "1", 0));
        tabObjects->setTabText(tabObjects->indexOf(tabLine), QApplication::translate("ObjectInsertionWindow", "Reta", 0));
        QTableWidgetItem *___qtablewidgetitem = tablePoligonPoints->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ObjectInsertionWindow", "X", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tablePoligonPoints->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ObjectInsertionWindow", "Y", 0));
        btnRemovePoint->setText(QApplication::translate("ObjectInsertionWindow", "Remover Ponto", 0));
        btnInsertPoint->setText(QApplication::translate("ObjectInsertionWindow", "Inserir Ponto", 0));
        tabObjects->setTabText(tabObjects->indexOf(tabPoligon), QApplication::translate("ObjectInsertionWindow", "Pol\303\255gono", 0));
        labelName->setText(QApplication::translate("ObjectInsertionWindow", "Nome", 0));
        fieldName->setInputMask(QString());
        fieldName->setText(QString());
        labelColor->setText(QApplication::translate("ObjectInsertionWindow", "Cor", 0));
        btnColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ObjectInsertionWindow: public Ui_ObjectInsertionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTINSERTIONWINDOW_H
