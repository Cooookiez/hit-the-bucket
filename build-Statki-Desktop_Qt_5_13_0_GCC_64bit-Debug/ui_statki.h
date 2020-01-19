/********************************************************************************
** Form generated from reading UI file 'statki.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATKI_H
#define UI_STATKI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ocean.h"

QT_BEGIN_NAMESPACE

class Ui_Statki
{
public:
    QWidget *centralwidget;
    Ocean *gv_ocean_local;
    Ocean *gv_ocean_remote;
    QGraphicsView *gv_local_ships;
    QGraphicsView *gv_remote_ships;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btn_Connect;
    QTextEdit *textEdit_Status;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextEdit *textEdit_IP;
    QLabel *label;
    QTextEdit *textEdit_Port;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Statki)
    {
        if (Statki->objectName().isEmpty())
            Statki->setObjectName(QString::fromUtf8("Statki"));
        Statki->resize(1180, 720);
        Statki->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: white;\n"
"}"));
        centralwidget = new QWidget(Statki);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gv_ocean_local = new Ocean(centralwidget);
        gv_ocean_local->setObjectName(QString::fromUtf8("gv_ocean_local"));
        gv_ocean_local->setGeometry(QRect(40, 170, 301, 301));
        gv_ocean_local->setStyleSheet(QString::fromUtf8(""));
        gv_ocean_remote = new Ocean(centralwidget);
        gv_ocean_remote->setObjectName(QString::fromUtf8("gv_ocean_remote"));
        gv_ocean_remote->setGeometry(QRect(840, 170, 301, 301));
        gv_local_ships = new QGraphicsView(centralwidget);
        gv_local_ships->setObjectName(QString::fromUtf8("gv_local_ships"));
        gv_local_ships->setGeometry(QRect(20, 480, 341, 141));
        gv_local_ships->setStyleSheet(QString::fromUtf8(""));
        gv_remote_ships = new QGraphicsView(centralwidget);
        gv_remote_ships->setObjectName(QString::fromUtf8("gv_remote_ships"));
        gv_remote_ships->setGeometry(QRect(820, 480, 341, 141));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(440, 436, 301, 181));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        btn_Connect = new QPushButton(verticalLayoutWidget_3);
        btn_Connect->setObjectName(QString::fromUtf8("btn_Connect"));
        btn_Connect->setStyleSheet(QString::fromUtf8("QPushButton:hover\n"
"{\n"
"	background-color:#ffffff;\n"
"	color:#006699;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:#006699;\n"
"	color:white;\n"
"	font-weight: bold;\n"
"	border-radius: 10px;\n"
"	height: 30px;\n"
"}"));

        verticalLayout_4->addWidget(btn_Connect);

        textEdit_Status = new QTextEdit(verticalLayoutWidget_3);
        textEdit_Status->setObjectName(QString::fromUtf8("textEdit_Status"));
        textEdit_Status->setEnabled(false);

        verticalLayout_4->addWidget(textEdit_Status);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1080, 10, 81, 25));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:#ffffff;\n"
"	color:#006699;\n"
"	border-radius: 10px;\n"
"	height: 30px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:#006699;\n"
"	color:white;\n"
"	font-weight: bold;\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 1181, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Gothic L"));
        font.setPointSize(60);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel \n"
"{\n"
"	color: white;\n"
"	background-color: #006699;\n"
"\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(46, 110, 291, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("URW Gothic L"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("QLabel \n"
"{\n"
"	color:#006699;\n"
"}\n"
""));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(846, 110, 291, 41));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:#006699;\n"
"}\n"
""));
        label_5->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(439, 193, 301, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("URW Gothic L"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("QLabel \n"
"{\n"
"	color:white;\n"
"	background-color:#006699\n"
"}\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        textEdit_IP = new QTextEdit(verticalLayoutWidget);
        textEdit_IP->setObjectName(QString::fromUtf8("textEdit_IP"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("URW Gothic L"));
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        textEdit_IP->setFont(font3);
        textEdit_IP->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"	color:#006699;\n"
"	text-align: center\n"
"}\n"
""));

        verticalLayout->addWidget(textEdit_IP);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("URW Gothic L"));
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("QLabel \n"
"{\n"
"	color:white;\n"
"	background-color:#006699\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        textEdit_Port = new QTextEdit(verticalLayoutWidget);
        textEdit_Port->setObjectName(QString::fromUtf8("textEdit_Port"));
        textEdit_Port->setFont(font4);
        textEdit_Port->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"	color:#006699;\n"
"}\n"
""));

        verticalLayout->addWidget(textEdit_Port);

        Statki->setCentralWidget(centralwidget);
        gv_ocean_local->raise();
        gv_ocean_remote->raise();
        gv_local_ships->raise();
        gv_remote_ships->raise();
        verticalLayoutWidget_3->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        verticalLayoutWidget->raise();
        pushButton->raise();
        menubar = new QMenuBar(Statki);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1180, 22));
        Statki->setMenuBar(menubar);
        statusbar = new QStatusBar(Statki);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Statki->setStatusBar(statusbar);

        retranslateUi(Statki);

        QMetaObject::connectSlotsByName(Statki);
    } // setupUi

    void retranslateUi(QMainWindow *Statki)
    {
        Statki->setWindowTitle(QCoreApplication::translate("Statki", "Statki", nullptr));
        btn_Connect->setText(QCoreApplication::translate("Statki", "CONNECT", nullptr));
        textEdit_Status->setHtml(QCoreApplication::translate("Statki", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont'; font-size:13pt;\">Status...</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Statki", "MENU", nullptr));
        label_3->setText(QCoreApplication::translate("Statki", "STATKI", nullptr));
        label_4->setText(QCoreApplication::translate("Statki", "GRACZ 1", nullptr));
        label_5->setText(QCoreApplication::translate("Statki", "GRACZ 2", nullptr));
        label_2->setText(QCoreApplication::translate("Statki", "IP", nullptr));
        textEdit_IP->setHtml(QCoreApplication::translate("Statki", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'URW Gothic L'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400;\">127.0.0.1</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Statki", "PORT", nullptr));
        textEdit_Port->setHtml(QCoreApplication::translate("Statki", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'URW Gothic L'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400;\">710</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statki: public Ui_Statki {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATKI_H
