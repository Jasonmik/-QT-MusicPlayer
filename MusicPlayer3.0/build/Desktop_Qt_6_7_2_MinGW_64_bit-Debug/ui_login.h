/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *frame;
    QLineEdit *userName;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userID;
    QLabel *label_3;
    QPushButton *Login_2;
    QPushButton *Create;
    QCheckBox *checkBox;
    QPushButton *pushButton;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(500, 400);
        Login->setMinimumSize(QSize(500, 400));
        Login->setMaximumSize(QSize(500, 400));
        Login->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(Login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 500, 400));
        frame->setMinimumSize(QSize(500, 400));
        frame->setMaximumSize(QSize(500, 400));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("/*QFrame{\n"
"	background-color: #138A93;\n"
"	border-radius:12px;\n"
"}*/\n"
"QLabel{\n"
"color:white;\n"
"}\n"
"QLineEdit{\n"
"	border-radius:6px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgb(248, 255, 110);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        userName = new QLineEdit(frame);
        userName->setObjectName("userName");
        userName->setGeometry(QRect(180, 130, 161, 51));
        userName->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 227);"));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 130, 91, 51));
        label->setStyleSheet(QString::fromUtf8("*{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 210, 81, 51));
        label_2->setStyleSheet(QString::fromUtf8("*{\n"
"	\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        userID = new QLineEdit(frame);
        userID->setObjectName("userID");
        userID->setGeometry(QRect(180, 210, 161, 51));
        userID->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 227);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 40, 271, 51));
        Login_2 = new QPushButton(frame);
        Login_2->setObjectName("Login_2");
        Login_2->setGeometry(QRect(80, 310, 50, 50));
        Login_2->setMinimumSize(QSize(50, 50));
        Login_2->setMaximumSize(QSize(50, 50));
        Login_2->setAutoFillBackground(false);
        Login_2->setStyleSheet(QString::fromUtf8("image: url(:/image_/denglu.png);"));
        Login_2->setFlat(true);
        Create = new QPushButton(frame);
        Create->setObjectName("Create");
        Create->setGeometry(QRect(230, 310, 50, 50));
        Create->setMinimumSize(QSize(50, 50));
        Create->setMaximumSize(QSize(50, 50));
        Create->setStyleSheet(QString::fromUtf8("image: url(:/image_/zhuce.png);"));
        Create->setFlat(true);
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(380, 220, 91, 41));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(370, 320, 31, 31));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/image_/back.png);"));
        pushButton->setAutoDefault(true);
        pushButton->setFlat(true);

        retranslateUi(Login);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; font-style:italic; color:#000000;\">\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250\347\224\250\346\210\267\347\231\273\345\275\225</span></p></body></html>", nullptr));
        Login_2->setText(QString());
        Create->setText(QString());
        checkBox->setText(QCoreApplication::translate("Login", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
