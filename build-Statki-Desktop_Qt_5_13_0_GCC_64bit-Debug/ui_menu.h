/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(663, 603);
        verticalLayoutWidget_2 = new QWidget(menu);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(210, 170, 241, 211));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Gothic L"));
        font.setPointSize(15);
        font.setItalic(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#ffffff;\n"
"	color:#006699;\n"
"	border-radius: 20px;\n"
"	height: 50px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#006699;\n"
"	color:white;\n"
"	font-weight: bold;\n"
"}"));

        verticalLayout_3->addWidget(pushButton);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#ffffff;\n"
"	color:#006699;\n"
"	border-radius: 20px;\n"
"	height: 50px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#006699;\n"
"	color:white;\n"
"	font-weight: bold;\n"
"}"));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#ffffff;\n"
"	color:#006699;\n"
"	border-radius: 20px;\n"
"	height: 50px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#006699;\n"
"	color:white;\n"
"	font-weight: bold;\n"
"}"));

        verticalLayout_3->addWidget(pushButton_2);

        verticalLayoutWidget = new QWidget(menu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 16, 641, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("URW Gothic L"));
        font1.setPointSize(60);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel \n"
"{\n"
"	color: white;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("menu", "Start", nullptr));
        pushButton_3->setText(QCoreApplication::translate("menu", "Autorzy", nullptr));
        pushButton_2->setText(QCoreApplication::translate("menu", "Licencja", nullptr));
        label->setText(QCoreApplication::translate("menu", "S T A T K I", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
