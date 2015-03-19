/********************************************************************************
** Form generated from reading UI file 'ObjectTransformationWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTTRANSFORMATIONWINDOW_H
#define UI_OBJECTTRANSFORMATIONWINDOW_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectTransformationWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout2;
    QPushButton *btnCancel;
    QPushButton *btnTransform;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabTransformations;
    QWidget *tabScale;
    QGroupBox *groupScaleFactors;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout_2;
    QLabel *labelScaleFactorX;
    QLineEdit *fieldScaleFactorX;
    QFormLayout *formLayout_3;
    QLabel *labelScaleFactorY;
    QLineEdit *fieldScaleFactorY;
    QFormLayout *formLayout_4;
    QLabel *labelScaleFactorZ;
    QLineEdit *fieldScaleFactorZ;
    QWidget *tabRotate;
    QGroupBox *groupRotateDegree;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_5;
    QLabel *labelRotateDegree;
    QLineEdit *fieldRotateDegree;
    QGroupBox *groupRotatePoint;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout_8;
    QLabel *labelRotatePointX;
    QLineEdit *fieldRotatePointX;
    QFormLayout *formLayout_9;
    QLabel *labelRotatePointY;
    QLineEdit *fieldRotatePointY;
    QFormLayout *formLayout_10;
    QLabel *labelRotatePointZ;
    QLineEdit *fieldRotatePointZ;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radBtnGeometricCenter;
    QRadioButton *radBtnSpecificPoint;
    QWidget *tabTranslate;
    QGroupBox *groupTranslateFactors;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout_11;
    QLabel *labelTranslateFactorX;
    QLineEdit *fieldTranslateFactorX;
    QFormLayout *formLayout_12;
    QLabel *labelTranslateFactorY;
    QLineEdit *fieldTranslateFactorY;
    QFormLayout *formLayout_13;
    QLabel *labelTranslateFactorZ;
    QLineEdit *fieldTranslateFactorZ;

    void setupUi(QWidget *ObjectTransformationWindow)
    {
        if (ObjectTransformationWindow->objectName().isEmpty())
            ObjectTransformationWindow->setObjectName(QStringLiteral("ObjectTransformationWindow"));
        ObjectTransformationWindow->setWindowModality(Qt::NonModal);
        ObjectTransformationWindow->resize(400, 321);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ObjectTransformationWindow->sizePolicy().hasHeightForWidth());
        ObjectTransformationWindow->setSizePolicy(sizePolicy);
        ObjectTransformationWindow->setMinimumSize(QSize(400, 0));
        ObjectTransformationWindow->setMaximumSize(QSize(400, 400));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        ObjectTransformationWindow->setFont(font);
        ObjectTransformationWindow->setAutoFillBackground(false);
        gridLayoutWidget = new QWidget(ObjectTransformationWindow);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 381, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout2 = new QGridLayout();
        gridLayout2->setObjectName(QStringLiteral("gridLayout2"));
        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        gridLayout2->addWidget(btnCancel, 0, 0, 1, 1);

        btnTransform = new QPushButton(gridLayoutWidget);
        btnTransform->setObjectName(QStringLiteral("btnTransform"));

        gridLayout2->addWidget(btnTransform, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout2->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout2, 5, 0, 1, 1);

        tabTransformations = new QTabWidget(gridLayoutWidget);
        tabTransformations->setObjectName(QStringLiteral("tabTransformations"));
        tabScale = new QWidget();
        tabScale->setObjectName(QStringLiteral("tabScale"));
        groupScaleFactors = new QGroupBox(tabScale);
        groupScaleFactors->setObjectName(QStringLiteral("groupScaleFactors"));
        groupScaleFactors->setGeometry(QRect(10, 10, 351, 71));
        groupScaleFactors->setStyleSheet(QLatin1String("QGroupBox  {\n"
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
        layoutWidget = new QWidget(groupScaleFactors);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 331, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(-1, 5, -1, 5);
        labelScaleFactorX = new QLabel(layoutWidget);
        labelScaleFactorX->setObjectName(QStringLiteral("labelScaleFactorX"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelScaleFactorX);

        fieldScaleFactorX = new QLineEdit(layoutWidget);
        fieldScaleFactorX->setObjectName(QStringLiteral("fieldScaleFactorX"));
        fieldScaleFactorX->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fieldScaleFactorX->sizePolicy().hasHeightForWidth());
        fieldScaleFactorX->setSizePolicy(sizePolicy1);
        fieldScaleFactorX->setMaximumSize(QSize(16777214, 30));
        fieldScaleFactorX->setMaxLength(50);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, fieldScaleFactorX);


        horizontalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(-1, 5, -1, 5);
        labelScaleFactorY = new QLabel(layoutWidget);
        labelScaleFactorY->setObjectName(QStringLiteral("labelScaleFactorY"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelScaleFactorY);

        fieldScaleFactorY = new QLineEdit(layoutWidget);
        fieldScaleFactorY->setObjectName(QStringLiteral("fieldScaleFactorY"));
        sizePolicy1.setHeightForWidth(fieldScaleFactorY->sizePolicy().hasHeightForWidth());
        fieldScaleFactorY->setSizePolicy(sizePolicy1);
        fieldScaleFactorY->setMaximumSize(QSize(16777215, 30));
        fieldScaleFactorY->setMaxLength(50);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, fieldScaleFactorY);


        horizontalLayout->addLayout(formLayout_3);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(-1, 5, -1, 5);
        labelScaleFactorZ = new QLabel(layoutWidget);
        labelScaleFactorZ->setObjectName(QStringLiteral("labelScaleFactorZ"));
        labelScaleFactorZ->setEnabled(false);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, labelScaleFactorZ);

        fieldScaleFactorZ = new QLineEdit(layoutWidget);
        fieldScaleFactorZ->setObjectName(QStringLiteral("fieldScaleFactorZ"));
        fieldScaleFactorZ->setEnabled(false);
        sizePolicy1.setHeightForWidth(fieldScaleFactorZ->sizePolicy().hasHeightForWidth());
        fieldScaleFactorZ->setSizePolicy(sizePolicy1);
        fieldScaleFactorZ->setMaximumSize(QSize(16777215, 30));
        fieldScaleFactorZ->setMaxLength(50);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, fieldScaleFactorZ);


        horizontalLayout->addLayout(formLayout_4);

        tabTransformations->addTab(tabScale, QString());
        tabRotate = new QWidget();
        tabRotate->setObjectName(QStringLiteral("tabRotate"));
        groupRotateDegree = new QGroupBox(tabRotate);
        groupRotateDegree->setObjectName(QStringLiteral("groupRotateDegree"));
        groupRotateDegree->setGeometry(QRect(10, 10, 351, 71));
        groupRotateDegree->setStyleSheet(QLatin1String("QGroupBox  {\n"
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
        layoutWidget1 = new QWidget(groupRotateDegree);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(91, 21, 171, 37));
        formLayout_5 = new QFormLayout(layoutWidget1);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_5->setContentsMargins(0, 5, 0, 5);
        labelRotateDegree = new QLabel(layoutWidget1);
        labelRotateDegree->setObjectName(QStringLiteral("labelRotateDegree"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelRotateDegree);

        fieldRotateDegree = new QLineEdit(layoutWidget1);
        fieldRotateDegree->setObjectName(QStringLiteral("fieldRotateDegree"));
        sizePolicy1.setHeightForWidth(fieldRotateDegree->sizePolicy().hasHeightForWidth());
        fieldRotateDegree->setSizePolicy(sizePolicy1);
        fieldRotateDegree->setMaximumSize(QSize(16777214, 30));
        fieldRotateDegree->setMaxLength(50);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, fieldRotateDegree);

        groupRotatePoint = new QGroupBox(tabRotate);
        groupRotatePoint->setObjectName(QStringLiteral("groupRotatePoint"));
        groupRotatePoint->setGeometry(QRect(10, 90, 351, 131));
        groupRotatePoint->setStyleSheet(QLatin1String("QGroupBox  {\n"
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
        layoutWidget_4 = new QWidget(groupRotatePoint);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 80, 331, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        formLayout_8->setContentsMargins(-1, 5, -1, 5);
        labelRotatePointX = new QLabel(layoutWidget_4);
        labelRotatePointX->setObjectName(QStringLiteral("labelRotatePointX"));
        labelRotatePointX->setEnabled(false);

        formLayout_8->setWidget(0, QFormLayout::LabelRole, labelRotatePointX);

        fieldRotatePointX = new QLineEdit(layoutWidget_4);
        fieldRotatePointX->setObjectName(QStringLiteral("fieldRotatePointX"));
        fieldRotatePointX->setEnabled(false);
        sizePolicy1.setHeightForWidth(fieldRotatePointX->sizePolicy().hasHeightForWidth());
        fieldRotatePointX->setSizePolicy(sizePolicy1);
        fieldRotatePointX->setMaximumSize(QSize(16777214, 30));
        fieldRotatePointX->setMaxLength(50);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, fieldRotatePointX);


        horizontalLayout_3->addLayout(formLayout_8);

        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QStringLiteral("formLayout_9"));
        formLayout_9->setContentsMargins(-1, 5, -1, 5);
        labelRotatePointY = new QLabel(layoutWidget_4);
        labelRotatePointY->setObjectName(QStringLiteral("labelRotatePointY"));
        labelRotatePointY->setEnabled(false);

        formLayout_9->setWidget(0, QFormLayout::LabelRole, labelRotatePointY);

        fieldRotatePointY = new QLineEdit(layoutWidget_4);
        fieldRotatePointY->setObjectName(QStringLiteral("fieldRotatePointY"));
        fieldRotatePointY->setEnabled(false);
        sizePolicy1.setHeightForWidth(fieldRotatePointY->sizePolicy().hasHeightForWidth());
        fieldRotatePointY->setSizePolicy(sizePolicy1);
        fieldRotatePointY->setMaximumSize(QSize(16777215, 30));
        fieldRotatePointY->setMaxLength(50);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, fieldRotatePointY);


        horizontalLayout_3->addLayout(formLayout_9);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QStringLiteral("formLayout_10"));
        formLayout_10->setContentsMargins(-1, 5, -1, 5);
        labelRotatePointZ = new QLabel(layoutWidget_4);
        labelRotatePointZ->setObjectName(QStringLiteral("labelRotatePointZ"));
        labelRotatePointZ->setEnabled(false);

        formLayout_10->setWidget(0, QFormLayout::LabelRole, labelRotatePointZ);

        fieldRotatePointZ = new QLineEdit(layoutWidget_4);
        fieldRotatePointZ->setObjectName(QStringLiteral("fieldRotatePointZ"));
        fieldRotatePointZ->setEnabled(false);
        sizePolicy1.setHeightForWidth(fieldRotatePointZ->sizePolicy().hasHeightForWidth());
        fieldRotatePointZ->setSizePolicy(sizePolicy1);
        fieldRotatePointZ->setMaximumSize(QSize(16777215, 30));
        fieldRotatePointZ->setMaxLength(50);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, fieldRotatePointZ);


        horizontalLayout_3->addLayout(formLayout_10);

        layoutWidget2 = new QWidget(groupRotatePoint);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(16, 21, 321, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radBtnGeometricCenter = new QRadioButton(layoutWidget2);
        radBtnGeometricCenter->setObjectName(QStringLiteral("radBtnGeometricCenter"));
        radBtnGeometricCenter->setChecked(true);

        verticalLayout_2->addWidget(radBtnGeometricCenter);

        radBtnSpecificPoint = new QRadioButton(layoutWidget2);
        radBtnSpecificPoint->setObjectName(QStringLiteral("radBtnSpecificPoint"));
        radBtnSpecificPoint->setChecked(false);

        verticalLayout_2->addWidget(radBtnSpecificPoint);

        tabTransformations->addTab(tabRotate, QString());
        tabTranslate = new QWidget();
        tabTranslate->setObjectName(QStringLiteral("tabTranslate"));
        groupTranslateFactors = new QGroupBox(tabTranslate);
        groupTranslateFactors->setObjectName(QStringLiteral("groupTranslateFactors"));
        groupTranslateFactors->setGeometry(QRect(10, 10, 351, 71));
        groupTranslateFactors->setStyleSheet(QLatin1String("QGroupBox  {\n"
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
        layoutWidget_2 = new QWidget(groupTranslateFactors);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 331, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QStringLiteral("formLayout_11"));
        formLayout_11->setContentsMargins(-1, 5, -1, 5);
        labelTranslateFactorX = new QLabel(layoutWidget_2);
        labelTranslateFactorX->setObjectName(QStringLiteral("labelTranslateFactorX"));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, labelTranslateFactorX);

        fieldTranslateFactorX = new QLineEdit(layoutWidget_2);
        fieldTranslateFactorX->setObjectName(QStringLiteral("fieldTranslateFactorX"));
        fieldTranslateFactorX->setEnabled(true);
        sizePolicy1.setHeightForWidth(fieldTranslateFactorX->sizePolicy().hasHeightForWidth());
        fieldTranslateFactorX->setSizePolicy(sizePolicy1);
        fieldTranslateFactorX->setMaximumSize(QSize(16777214, 30));
        fieldTranslateFactorX->setMaxLength(50);

        formLayout_11->setWidget(0, QFormLayout::FieldRole, fieldTranslateFactorX);


        horizontalLayout_4->addLayout(formLayout_11);

        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QStringLiteral("formLayout_12"));
        formLayout_12->setContentsMargins(-1, 5, -1, 5);
        labelTranslateFactorY = new QLabel(layoutWidget_2);
        labelTranslateFactorY->setObjectName(QStringLiteral("labelTranslateFactorY"));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, labelTranslateFactorY);

        fieldTranslateFactorY = new QLineEdit(layoutWidget_2);
        fieldTranslateFactorY->setObjectName(QStringLiteral("fieldTranslateFactorY"));
        sizePolicy1.setHeightForWidth(fieldTranslateFactorY->sizePolicy().hasHeightForWidth());
        fieldTranslateFactorY->setSizePolicy(sizePolicy1);
        fieldTranslateFactorY->setMaximumSize(QSize(16777215, 30));
        fieldTranslateFactorY->setMaxLength(50);

        formLayout_12->setWidget(0, QFormLayout::FieldRole, fieldTranslateFactorY);


        horizontalLayout_4->addLayout(formLayout_12);

        formLayout_13 = new QFormLayout();
        formLayout_13->setObjectName(QStringLiteral("formLayout_13"));
        formLayout_13->setContentsMargins(-1, 5, -1, 5);
        labelTranslateFactorZ = new QLabel(layoutWidget_2);
        labelTranslateFactorZ->setObjectName(QStringLiteral("labelTranslateFactorZ"));
        labelTranslateFactorZ->setEnabled(false);

        formLayout_13->setWidget(0, QFormLayout::LabelRole, labelTranslateFactorZ);

        fieldTranslateFactorZ = new QLineEdit(layoutWidget_2);
        fieldTranslateFactorZ->setObjectName(QStringLiteral("fieldTranslateFactorZ"));
        fieldTranslateFactorZ->setEnabled(false);
        sizePolicy1.setHeightForWidth(fieldTranslateFactorZ->sizePolicy().hasHeightForWidth());
        fieldTranslateFactorZ->setSizePolicy(sizePolicy1);
        fieldTranslateFactorZ->setMaximumSize(QSize(16777215, 30));
        fieldTranslateFactorZ->setMaxLength(50);

        formLayout_13->setWidget(0, QFormLayout::FieldRole, fieldTranslateFactorZ);


        horizontalLayout_4->addLayout(formLayout_13);

        tabTransformations->addTab(tabTranslate, QString());

        gridLayout->addWidget(tabTransformations, 4, 0, 1, 1);

        QWidget::setTabOrder(tabTransformations, fieldScaleFactorX);
        QWidget::setTabOrder(fieldScaleFactorX, fieldScaleFactorY);
        QWidget::setTabOrder(fieldScaleFactorY, fieldScaleFactorZ);
        QWidget::setTabOrder(fieldScaleFactorZ, fieldRotateDegree);
        QWidget::setTabOrder(fieldRotateDegree, fieldRotatePointX);
        QWidget::setTabOrder(fieldRotatePointX, fieldRotatePointY);
        QWidget::setTabOrder(fieldRotatePointY, fieldRotatePointZ);
        QWidget::setTabOrder(fieldRotatePointZ, btnCancel);
        QWidget::setTabOrder(btnCancel, btnTransform);

        retranslateUi(ObjectTransformationWindow);

        tabTransformations->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ObjectTransformationWindow);
    } // setupUi

    void retranslateUi(QWidget *ObjectTransformationWindow)
    {
        ObjectTransformationWindow->setWindowTitle(QApplication::translate("ObjectTransformationWindow", "Transformar Objeto", 0));
        btnCancel->setText(QApplication::translate("ObjectTransformationWindow", "Cancelar", 0));
        btnTransform->setText(QApplication::translate("ObjectTransformationWindow", "Ok", 0));
        groupScaleFactors->setTitle(QApplication::translate("ObjectTransformationWindow", "Fatores de Escalonamento", 0));
        labelScaleFactorX->setText(QApplication::translate("ObjectTransformationWindow", "Sx", 0));
        fieldScaleFactorX->setText(QString());
        labelScaleFactorY->setText(QApplication::translate("ObjectTransformationWindow", "Sy", 0));
        labelScaleFactorZ->setText(QApplication::translate("ObjectTransformationWindow", "Sz", 0));
        fieldScaleFactorZ->setText(QApplication::translate("ObjectTransformationWindow", "1", 0));
        tabTransformations->setTabText(tabTransformations->indexOf(tabScale), QApplication::translate("ObjectTransformationWindow", "Escalonar", 0));
        groupRotateDegree->setTitle(QApplication::translate("ObjectTransformationWindow", "Grau de Rota\303\247\303\243o", 0));
        labelRotateDegree->setText(QApplication::translate("ObjectTransformationWindow", "Grau (\302\272)", 0));
        groupRotatePoint->setTitle(QApplication::translate("ObjectTransformationWindow", "Ponto de Rota\303\247\303\243o", 0));
        labelRotatePointX->setText(QApplication::translate("ObjectTransformationWindow", "X", 0));
        labelRotatePointY->setText(QApplication::translate("ObjectTransformationWindow", "Y", 0));
        labelRotatePointZ->setText(QApplication::translate("ObjectTransformationWindow", "Z", 0));
        fieldRotatePointZ->setText(QApplication::translate("ObjectTransformationWindow", "1", 0));
        radBtnGeometricCenter->setText(QApplication::translate("ObjectTransformationWindow", "Centro Geom\303\251trico", 0));
        radBtnSpecificPoint->setText(QApplication::translate("ObjectTransformationWindow", "Ponto Espec\303\255fico", 0));
        tabTransformations->setTabText(tabTransformations->indexOf(tabRotate), QApplication::translate("ObjectTransformationWindow", "Rotacionar", 0));
        groupTranslateFactors->setTitle(QApplication::translate("ObjectTransformationWindow", "Fatores de Transla\303\247\303\243o", 0));
        labelTranslateFactorX->setText(QApplication::translate("ObjectTransformationWindow", "Sx", 0));
        fieldTranslateFactorX->setText(QString());
        labelTranslateFactorY->setText(QApplication::translate("ObjectTransformationWindow", "Sy", 0));
        labelTranslateFactorZ->setText(QApplication::translate("ObjectTransformationWindow", "Sz", 0));
        fieldTranslateFactorZ->setText(QApplication::translate("ObjectTransformationWindow", "1", 0));
        tabTransformations->setTabText(tabTransformations->indexOf(tabTranslate), QApplication::translate("ObjectTransformationWindow", "Transladar", 0));
    } // retranslateUi

};

namespace Ui {
    class ObjectTransformationWindow: public Ui_ObjectTransformationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTTRANSFORMATIONWINDOW_H
