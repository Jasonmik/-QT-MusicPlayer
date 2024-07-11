/********************************************************************************
** Form generated from reading UI file 'create.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_H
#define UI_CREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Create
{
public:
    QFrame *frame;
    QLabel *label_3;
    QPushButton *Create_2;
    QCheckBox *checkBox;
    QLabel *label_4;
    QLineEdit *userName_2;
    QLabel *label;
    QLineEdit *userID;
    QLabel *label_2;
    QLineEdit *userName;
    QPushButton *pushButton;

    void setupUi(QWidget *Create)
    {
        if (Create->objectName().isEmpty())
            Create->setObjectName("Create");
        Create->resize(500, 400);
        Create->setMinimumSize(QSize(500, 400));
        Create->setMaximumSize(QSize(500, 400));
        frame = new QFrame(Create);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 500, 400));
        frame->setMinimumSize(QSize(500, 400));
        frame->setMaximumSize(QSize(500, 400));
        frame->setStyleSheet(QString::fromUtf8("\n"
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
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 50, 251, 31));
        Create_2 = new QPushButton(frame);
        Create_2->setObjectName("Create_2");
        Create_2->setGeometry(QRect(130, 320, 81, 51));
        Create_2->setStyleSheet(QString::fromUtf8("image: url(:/image_/zhuce.png);"));
        Create_2->setFlat(true);
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(400, 200, 81, 31));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 260, 81, 41));
        userName_2 = new QLineEdit(frame);
        userName_2->setObjectName("userName_2");
        userName_2->setGeometry(QRect(200, 260, 181, 41));
        userName_2->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 227);"));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 120, 71, 49));
        userID = new QLineEdit(frame);
        userID->setObjectName("userID");
        userID->setGeometry(QRect(200, 120, 181, 41));
        userID->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 227);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 190, 51, 49));
        userName = new QLineEdit(frame);
        userName->setObjectName("userName");
        userName->setGeometry(QRect(200, 190, 181, 41));
        userName->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 227, 227);"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 330, 41, 31));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/image_/creat_back.png);"));
        pushButton->setFlat(true);

        retranslateUi(Create);

        QMetaObject::connectSlotsByName(Create);
    } // setupUi

    void retranslateUi(QWidget *Create)
    {
        Create->setWindowTitle(QCoreApplication::translate("Create", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; font-style:italic; color:#000000;\">\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250\347\224\250\346\210\267\346\263\250\345\206\214</span></p></body></html>", nullptr));
        Create_2->setText(QString());
        checkBox->setText(QCoreApplication::translate("Create", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#000000;\">\351\207\215\345\244\215\345\257\206\347\240\201:</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#000000;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700; color:#000000;\">\345\257\206\347\240\201\357\274\232 </span></p></body></html>", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Create: public Ui_Create {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_H
