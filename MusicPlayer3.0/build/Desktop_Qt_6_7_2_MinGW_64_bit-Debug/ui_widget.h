/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "label_scroll.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_8;
    QLabel *GIFlabel;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTableWidget *tableWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QPushButton *search;
    QSpacerItem *horizontalSpacer_3;
    QLabel *wavelabel;
    QLabel *searchstate;
    QWidget *page_2;
    QListWidget *listWidget;
    QWidget *page_3;
    QLabel *textlabel1;
    QLabel *textlabel2;
    QLabel *textlabel3;
    QWidget *page_4;
    QLabel *Soaring_cover;
    label_scroll *Soaring_song_name;
    QPushButton *fresh;
    QLabel *Soaring_cover_2;
    QLabel *Soaring_cover_1;
    QPushButton *star;
    QLabel *Floading;
    QWidget *page_5;
    QTableWidget *tableWidget_2;
    QPushButton *LikeUpDate;
    QLabel *LikeState;
    QWidget *page_6;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label_3;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_12;
    QSlider *volumeSlider;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_11;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *List_of_lyrics;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *currenttime;
    QSpacerItem *horizontalSpacer;
    QLabel *totaltime;
    QSlider *currentSlider;
    QPushButton *pushButton_10;
    QLabel *backGround;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Song_Search_2;
    QPushButton *Song_Search;
    QPushButton *likeBtn;
    QPushButton *pushButton_4;
    QPushButton *lyrics_view;
    label_scroll *songname;
    QPushButton *reLogin;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1100, 700);
        Widget->setMinimumSize(QSize(1100, 700));
        Widget->setMaximumSize(QSize(1100, 700));
        Widget->setStyleSheet(QString::fromUtf8(""));
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(1050, 0, 50, 50));
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setMaximumSize(QSize(50, 50));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	\n"
"	\n"
"	image: url(:/close1);\n"
"}\n"
"*{\n"
"boder::none;\n"
"	image: url(:/close);\n"
"}\n"
"\n"
""));
        pushButton_8->setFlat(true);
        GIFlabel = new QLabel(Widget);
        GIFlabel->setObjectName("GIFlabel");
        GIFlabel->setGeometry(QRect(30, 340, 201, 201));
        GIFlabel->setMaximumSize(QSize(300, 300));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(140, 30, 941, 521));
        page = new QWidget();
        page->setObjectName("page");
        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QFont font;
        font.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        __qtablewidgetitem2->setBackground(QColor(104, 104, 104));
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        __qtablewidgetitem3->setBackground(QColor(117, 117, 117));
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 60, 901, 461));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableView{\n"
"	background:transparent;\n"
"	border:1px solid A7 A7 A7;\n"
"	border-radius:10px;\n"
"	font-size:20px;\n"
"	font-family:'\351\273\221\344\275\223';\n"
"}\n"
" QTableWidget QTableCornerButton::section{\n"
"	background:transparent;\n"
"}\n"
" QHeaderView{\n"
"background:transparent;\n"
"	border-radius:10px;\n"
"	height:35;\n"
"	font-size:20px;\n"
"	font-family:'\351\273\221\344\275\223'\n"
"}\n"
"QHeaderView::section{\n"
"background:transparent;\n"
"	padding:5px 10px 5px 10px;\n"
"	border-radius:10px\n"
"}\n"
"\n"
""));
        horizontalLayoutWidget = new QWidget(page);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(19, 0, 541, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-width:1px;\n"
"border-radius:4px;\n"
"font-size:12px;\n"
"color:black;\n"
"border:1px solid gray;\n"
"padding-right: 100px;\n"
"}\n"
"\n"
" QLineEdit:hover{\n"
"border-width:1px;\n"
"border-radius:4px;\n"
"font-size:12px;\n"
"color:black;\n"
"border:1px solid rgb(70,200,50);\n"
"\n"
"}\n"
"\n"
""));

        horizontalLayout_3->addWidget(lineEdit);

        search = new QPushButton(horizontalLayoutWidget);
        search->setObjectName("search");
        search->setMinimumSize(QSize(40, 40));
        search->setMaximumSize(QSize(40, 40));
        search->setStyleSheet(QString::fromUtf8("\n"
"/**\346\255\243\345\270\270\346\203\205\345\206\265\344\270\213\346\240\267\345\274\217**/\n"
"QPushButton{\n"
"	font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"    color: #2f3640;\n"
"    border-color: #2f3640;\n"
"    border-radius: 15px;\n"
"\n"
"    padding: 5px;\n"
"	image: url(:/image_/search.png);\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\345\201\234\347\225\231\345\234\250\346\214\211\351\222\256\344\270\212\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::hover{	\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\346\214\211\345\216\213\344\270\213\345\216\273\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"}\n"
"\n"
"/**\346\214\211\351\222\256\345\244\261\350\203\275\346\203\205\345\206\265\344\270\213\346\240\267"
                        "\345\274\217**/\n"
"QPushButton::disabled{\n"
"    color: #FFFFFF;\n"
"    background-color: #dcdde1;\n"
"    border-color: #dcdde1;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(search);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        wavelabel = new QLabel(page);
        wavelabel->setObjectName("wavelabel");
        wavelabel->setGeometry(QRect(80, 260, 551, 231));
        searchstate = new QLabel(page);
        searchstate->setObjectName("searchstate");
        searchstate->setGeometry(QRect(260, 200, 341, 91));
        searchstate->setScaledContents(true);
        stackedWidget->addWidget(page);
        wavelabel->raise();
        tableWidget->raise();
        horizontalLayoutWidget->raise();
        searchstate->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        listWidget = new QListWidget(page_2);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(160, 40, 681, 371));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"	background:transparent;border:1px\n"
"}\n"
"\n"
"QListWidget::item{\n"
"	padding-top:24px;\n"
"	color:rgba(121,112,52,1);\n"
"   	margin-left:40px;\n"
"}\n"
"QListWidget::item:hover{\n"
"	background-color:transparent;\n"
"	border-bottom:1px solid rgb(121,112,52);\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    border-bottom:1px solid rgb(121,112,52);\n"
"    padding:0px;\n"
"    margin:0px;\n"
"    color:red;\n"
"}\n"
"QListWidget::item:selected:!active\n"
"{\n"
"    border-width:0px;\n"
"}\n"
"*{\n"
"	\n"
"	font: 700 12pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #F0F0F0;\n"
"    width: 15px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #C0C0C0;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"}\n"
"\n"
"\n"
""));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        textlabel1 = new QLabel(page_3);
        textlabel1->setObjectName("textlabel1");
        textlabel1->setGeometry(QRect(90, 70, 851, 61));
        textlabel1->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        textlabel2 = new QLabel(page_3);
        textlabel2->setObjectName("textlabel2");
        textlabel2->setGeometry(QRect(10, 190, 901, 61));
        textlabel2->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 0);\n"
""));
        textlabel3 = new QLabel(page_3);
        textlabel3->setObjectName("textlabel3");
        textlabel3->setGeometry(QRect(100, 280, 651, 61));
        textlabel3->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        stackedWidget->addWidget(page_3);
        textlabel2->raise();
        textlabel1->raise();
        textlabel3->raise();
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        Soaring_cover = new QLabel(page_4);
        Soaring_cover->setObjectName("Soaring_cover");
        Soaring_cover->setGeometry(QRect(340, 40, 250, 250));
        Soaring_cover->setMinimumSize(QSize(250, 250));
        Soaring_cover->setMaximumSize(QSize(250, 250));
        Soaring_song_name = new label_scroll(page_4);
        Soaring_song_name->setObjectName("Soaring_song_name");
        Soaring_song_name->setGeometry(QRect(370, 370, 241, 51));
        Soaring_song_name->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Microsoft YaHei UI\";"));
        fresh = new QPushButton(page_4);
        fresh->setObjectName("fresh");
        fresh->setGeometry(QRect(60, 20, 61, 41));
        fresh->setStyleSheet(QString::fromUtf8("image: url(:/image_/redo.png);"));
        fresh->setFlat(true);
        Soaring_cover_2 = new QLabel(page_4);
        Soaring_cover_2->setObjectName("Soaring_cover_2");
        Soaring_cover_2->setGeometry(QRect(540, 90, 250, 250));
        Soaring_cover_2->setMinimumSize(QSize(250, 250));
        Soaring_cover_2->setMaximumSize(QSize(250, 250));
        Soaring_cover_1 = new QLabel(page_4);
        Soaring_cover_1->setObjectName("Soaring_cover_1");
        Soaring_cover_1->setGeometry(QRect(120, 90, 250, 250));
        Soaring_cover_1->setMinimumSize(QSize(250, 250));
        Soaring_cover_1->setMaximumSize(QSize(250, 250));
        star = new QPushButton(page_4);
        star->setObjectName("star");
        star->setGeometry(QRect(350, 227, 41, 41));
        star->setStyleSheet(QString::fromUtf8("image: url(:/pause);"));
        star->setFlat(true);
        Floading = new QLabel(page_4);
        Floading->setObjectName("Floading");
        Floading->setGeometry(QRect(290, 70, 311, 101));
        Floading->setScaledContents(true);
        stackedWidget->addWidget(page_4);
        Soaring_song_name->raise();
        fresh->raise();
        Soaring_cover_2->raise();
        Soaring_cover_1->raise();
        Soaring_cover->raise();
        star->raise();
        Floading->raise();
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        tableWidget_2 = new QTableWidget(page_5);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        __qtablewidgetitem7->setBackground(QColor(104, 104, 104));
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        __qtablewidgetitem8->setBackground(QColor(117, 117, 117));
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(10, 50, 901, 461));
        tableWidget_2->setStyleSheet(QString::fromUtf8("QTableView{\n"
"	background:transparent;\n"
"	border:1px solid A7 A7 A7;\n"
"	border-radius:10px;\n"
"	font-size:20px;\n"
"	font-family:'\351\273\221\344\275\223';\n"
"}\n"
" QTableWidget QTableCornerButton::section{\n"
"	background:transparent;\n"
"}\n"
" QHeaderView{\n"
"background:transparent;\n"
"	border-radius:10px;\n"
"	height:35;\n"
"	font-size:20px;\n"
"	font-family:'\351\273\221\344\275\223'\n"
"}\n"
"QHeaderView::section{\n"
"background:transparent;\n"
"	padding:5px 10px 5px 10px;\n"
"	border-radius:10px\n"
"}\n"
"\n"
""));
        LikeUpDate = new QPushButton(page_5);
        LikeUpDate->setObjectName("LikeUpDate");
        LikeUpDate->setGeometry(QRect(60, 10, 31, 31));
        LikeUpDate->setStyleSheet(QString::fromUtf8("image: url(:/image_/reLike.png);"));
        LikeUpDate->setFlat(true);
        LikeState = new QLabel(page_5);
        LikeState->setObjectName("LikeState");
        LikeState->setGeometry(QRect(200, 210, 301, 91));
        LikeState->setScaledContents(true);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        label_2 = new QLabel(page_6);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 40, 151, 41));
        label_2->setStyleSheet(QString::fromUtf8("*{\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"\n"
"\n"
"}"));
        textEdit = new QTextEdit(page_6);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(60, 90, 821, 91));
        textEdit->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(page_6);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 220, 141, 31));
        label_3->setStyleSheet(QString::fromUtf8("*{\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"\n"
"\n"
"}"));
        textBrowser_2 = new QTextBrowser(page_6);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(60, 260, 821, 191));
        textBrowser_2->setStyleSheet(QString::fromUtf8(""));
        pushButton_12 = new QPushButton(page_6);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(770, 200, 113, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("*{\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"\n"
"\n"
"}\n"
"/**\351\274\240\346\240\207\345\201\234\347\225\231\345\234\250\346\214\211\351\222\256\344\270\212\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::hover{	\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"border: 2px solid #555;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\346\214\211\345\216\213\344\270\213\345\216\273\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"border: 2px solid #555;\n"
"}"));
        pushButton_12->setFlat(true);
        stackedWidget->addWidget(page_6);
        volumeSlider = new QSlider(Widget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setEnabled(true);
        volumeSlider->setGeometry(QRect(1040, 550, 11, 100));
        volumeSlider->setMinimumSize(QSize(0, 100));
        volumeSlider->setMaximumSize(QSize(16777215, 100));
        volumeSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:vertiacl {\n"
"    border: 1px solid #bbb;\n"
"    background: white;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertiacl {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #66e, stop: 1 #bbf);\n"
"    \n"
"    border: 1px solid #777;\n"
"    height: 10px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:vertiacl {\n"
"    background: #fff;\n"
"    border: 1px solid #777;\n"
"    height: 15px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:vertiacl {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eee, stop:1 #ccc);\n"
"    border: 1px solid #777;\n"
"    height: 15px;\n"
"    margin-top: -2px;\n"
"    margin-bottom: -2px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:vertiacl:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fff, stop:1 #ddd);\n"
"    border: 1px solid #444;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:vertiacl:disabled {\n"
"    backgroun"
                        "d: #bbb;\n"
"}\n"
"\n"
"QSlider::add-page:vertiacl:disabled {\n"
"    background: #eee;\n"
"    border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:vertiacl:disabled {\n"
"    background: #eee;\n"
"    border: 1px solid #aaa;\n"
"    border-radius: 4px;\n"
"}\n"
""));
        volumeSlider->setOrientation(Qt::Vertical);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(190, 550, 787, 62));
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setMinimumSize(QSize(50, 50));
        pushButton_9->setMaximumSize(QSize(50, 50));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"		\n"
"	border-image: url(:/image_/music-rhythm (1).png);\n"
"}\n"
"*{border-image: url(:/image_/music-rhythm.png);}"));

        horizontalLayout->addWidget(pushButton_9);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background: transparent;\n"
"\n"
"	image: url(:/image_/audio-file (1).png);\n"
"}\n"
"*{\n"
"background: transparent;\n"
"	image: url(:/image_/audio-file.png);\n"
"}\n"
""));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setMaximumSize(QSize(50, 50));
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
"image: url(:/image_/play-order.png);"));
        pushButton_7->setFlat(true);

        horizontalLayout->addWidget(pushButton_7);

        horizontalSpacer_5 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setMinimumSize(QSize(50, 50));
        pushButton_11->setMaximumSize(QSize(50, 50));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	\n"
"	\n"
"	\n"
"	image: url(:/image_/left (1).png);\n"
"}\n"
"*{\n"
"	image: url(:/image_/left (2).png);\n"
"}"));
        pushButton_11->setFlat(true);

        horizontalLayout->addWidget(pushButton_11);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setMaximumSize(QSize(50, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton:hover{\n"
"	\n"
"	image: url(:/image_/pause1.png);\n"
"}\n"
"*{\n"
"	image: url(:/pause);\n"
"background: transparent\n"
"}\n"
""));
        pushButton_2->setFlat(true);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(50, 50));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	\n"
"	image: url(:/image_/right (1).png);\n"
"}\n"
"*{\n"
"	image: url(:/image_/right (2).png);\n"
"}"));
        pushButton_5->setFlat(true);

        horizontalLayout->addWidget(pushButton_5);

        horizontalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(50, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	\n"
"	image: url(:/image_/_volume-notice (1).png);\n"
"}\n"
"*{\n"
"image: url(:/sound);\n"
"\n"
"}"));
        pushButton_3->setFlat(true);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(50, 50));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"		\n"
"	image: url(:/image_/speaker-one (1).png);\n"
"}\n"
"*{\n"
"image: url(:/image_/speaker-one.png);\n"
"}"));
        pushButton_6->setFlat(true);

        horizontalLayout->addWidget(pushButton_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        List_of_lyrics = new QPushButton(widget);
        List_of_lyrics->setObjectName("List_of_lyrics");
        List_of_lyrics->setMinimumSize(QSize(50, 50));
        List_of_lyrics->setMaximumSize(QSize(50, 50));
        List_of_lyrics->setStyleSheet(QString::fromUtf8("\n"
"QPushButton:hover{\n"
"	image: url(:/image_/music-list (1).png);\n"
"}\n"
"*{\n"
"	image: url(:/image_/music-list.png);\n"
"\n"
"}"));
        List_of_lyrics->setFlat(true);

        horizontalLayout->addWidget(List_of_lyrics);

        pushButton->raise();
        pushButton_2->raise();
        pushButton_5->raise();
        pushButton_3->raise();
        pushButton_11->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_9->raise();
        List_of_lyrics->raise();
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(360, 610, 440, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        currenttime = new QLabel(layoutWidget);
        currenttime->setObjectName("currenttime");
        currenttime->setMinimumSize(QSize(35, 0));
        currenttime->setMaximumSize(QSize(35, 16777215));
        currenttime->setStyleSheet(QString::fromUtf8("color: rgb(95, 95, 95);"));

        horizontalLayout_2->addWidget(currenttime);

        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        totaltime = new QLabel(layoutWidget);
        totaltime->setObjectName("totaltime");
        totaltime->setMinimumSize(QSize(35, 0));
        totaltime->setMaximumSize(QSize(35, 16777215));
        totaltime->setStyleSheet(QString::fromUtf8("color: rgb(95, 95, 95);"));

        horizontalLayout_2->addWidget(totaltime);

        currentSlider = new QSlider(Widget);
        currentSlider->setObjectName("currentSlider");
        currentSlider->setGeometry(QRect(350, 640, 450, 16));
        currentSlider->setMinimumSize(QSize(450, 0));
        currentSlider->setMaximumSize(QSize(450, 16777215));
        currentSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #bbb;\n"
"    background: white;\n"
"    height: 10px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #66e, stop: 1 #bbf);\n"
"    border: 1px solid #777;\n"
"    height: 10px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #fff;\n"
"    border: 1px solid #777;\n"
"    height: 10px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eee, stop:1 #ccc);\n"
"    border: 1px solid #777;\n"
"    width: 12px;\n"
"    margin-top: -2px;\n"
"    margin-bottom: -2px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fff, stop:1 #ddd);\n"
"    border: 1px solid #444;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disa"
                        "bled {\n"
"    background: #bbb;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"    background: #eee;\n"
"    border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"    background: #eee;\n"
"    border: 1px solid #aaa;\n"
"    border-radius: 4px;\n"
"}\n"
""));
        currentSlider->setOrientation(Qt::Horizontal);
        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(1000, 0, 50, 50));
        pushButton_10->setMinimumSize(QSize(50, 50));
        pushButton_10->setMaximumSize(QSize(50, 50));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	image: url(:/image_/min1.png);\n"
"}\n"
"*{\n"
"boder::none;\n"
"	\n"
"	image: url(:/image_/min.png);\n"
"}\n"
"\n"
""));
        pushButton_10->setFlat(true);
        backGround = new QLabel(Widget);
        backGround->setObjectName("backGround");
        backGround->setGeometry(QRect(0, 0, 1100, 700));
        backGround->setMinimumSize(QSize(1100, 700));
        backGround->setMaximumSize(QSize(1100, 700));
        backGround->setStyleSheet(QString::fromUtf8("QLable{\n"
"\n"
"border:2px groove gray;\n"
" border-radius:15px;\n"
" padding:2px 4px;\n"
"}\n"
""));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 60, 131, 254));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Song_Search_2 = new QPushButton(verticalLayoutWidget);
        Song_Search_2->setObjectName("Song_Search_2");
        Song_Search_2->setMinimumSize(QSize(120, 60));
        Song_Search_2->setMaximumSize(QSize(120, 60));
        Song_Search_2->setStyleSheet(QString::fromUtf8("*{\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"\n"
"\n"
"}\n"
"/**\351\274\240\346\240\207\345\201\234\347\225\231\345\234\250\346\214\211\351\222\256\344\270\212\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::hover{	\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"border: 2px solid #555;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\346\214\211\345\216\213\344\270\213\345\216\273\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"border: 2px solid #555;\n"
"}"));
        Song_Search_2->setFlat(true);

        verticalLayout->addWidget(Song_Search_2);

        Song_Search = new QPushButton(verticalLayoutWidget);
        Song_Search->setObjectName("Song_Search");
        Song_Search->setMinimumSize(QSize(120, 60));
        Song_Search->setMaximumSize(QSize(120, 60));
        Song_Search->setStyleSheet(QString::fromUtf8("*{\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"\n"
"\n"
"}\n"
"/**\351\274\240\346\240\207\345\201\234\347\225\231\345\234\250\346\214\211\351\222\256\344\270\212\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::hover{	\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"border: 2px solid #555;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\346\214\211\345\216\213\344\270\213\345\216\273\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"border: 2px solid #555;\n"
"}"));
        Song_Search->setFlat(true);

        verticalLayout->addWidget(Song_Search);

        likeBtn = new QPushButton(verticalLayoutWidget);
        likeBtn->setObjectName("likeBtn");
        likeBtn->setMinimumSize(QSize(120, 60));
        likeBtn->setMaximumSize(QSize(120, 60));
        likeBtn->setStyleSheet(QString::fromUtf8("*{\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"\n"
"\n"
"}\n"
"/**\351\274\240\346\240\207\345\201\234\347\225\231\345\234\250\346\214\211\351\222\256\344\270\212\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::hover{	\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"border: 2px solid #555;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\346\214\211\345\216\213\344\270\213\345\216\273\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"border: 2px solid #555;\n"
"}"));
        likeBtn->setFlat(true);

        verticalLayout->addWidget(likeBtn);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(120, 60));
        pushButton_4->setMaximumSize(QSize(120, 60));
        pushButton_4->setStyleSheet(QString::fromUtf8("*{\n"
"font: 16pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"\n"
"\n"
"}\n"
"/**\351\274\240\346\240\207\345\201\234\347\225\231\345\234\250\346\214\211\351\222\256\344\270\212\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::hover{	\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"border: 2px solid #555;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\346\214\211\345\216\213\344\270\213\345\216\273\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"border: 2px solid #555;\n"
"}"));
        pushButton_4->setFlat(true);

        verticalLayout->addWidget(pushButton_4);

        lyrics_view = new QPushButton(Widget);
        lyrics_view->setObjectName("lyrics_view");
        lyrics_view->setGeometry(QRect(50, 560, 80, 80));
        lyrics_view->setMinimumSize(QSize(80, 80));
        lyrics_view->setMaximumSize(QSize(80, 80));
        lyrics_view->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    image: url(:/image_/picture.png);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"}\n"
"\n"
"\n"
""));
        lyrics_view->setFlat(true);
        songname = new label_scroll(Widget);
        songname->setObjectName("songname");
        songname->setGeometry(QRect(170, 610, 170, 50));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(songname->sizePolicy().hasHeightForWidth());
        songname->setSizePolicy(sizePolicy);
        songname->setMinimumSize(QSize(170, 50));
        songname->setMaximumSize(QSize(170, 50));
        songname->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Microsoft YaHei UI\";"));
        reLogin = new QPushButton(Widget);
        reLogin->setObjectName("reLogin");
        reLogin->setGeometry(QRect(20, 10, 41, 31));
        reLogin->setStyleSheet(QString::fromUtf8("image: url(:/image_/person.png);"));
        reLogin->setFlat(true);
        backGround->raise();
        GIFlabel->raise();
        stackedWidget->raise();
        volumeSlider->raise();
        widget->raise();
        layoutWidget->raise();
        currentSlider->raise();
        pushButton_10->raise();
        pushButton_8->raise();
        verticalLayoutWidget->raise();
        lyrics_view->raise();
        songname->raise();
        reLogin->raise();

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_8->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>\345\205\263\351\227\255</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_8->setText(QString());
        GIFlabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\346\255\214\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\346\255\214\346\211\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "\346\227\266\351\225\277", nullptr));
        search->setText(QString());
        wavelabel->setText(QString());
        searchstate->setText(QString());
        textlabel1->setText(QString());
        textlabel2->setText(QString());
        textlabel3->setText(QString());
        Soaring_cover->setText(QString());
        Soaring_song_name->setText(QCoreApplication::translate("Widget", "songName", nullptr));
        fresh->setText(QString());
        Soaring_cover_2->setText(QString());
        Soaring_cover_1->setText(QString());
        star->setText(QString());
        Floading->setText(QString());
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "\346\255\214\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "\346\255\214\346\211\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "\346\227\266\351\225\277", nullptr));
        LikeUpDate->setText(QString());
        LikeState->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\351\227\256\351\242\230\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\233\236\347\255\224\357\274\232", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Widget", "\346\217\220\344\272\244", nullptr));
        pushButton_9->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>\346\267\273\345\212\240\346\226\207\344\273\266</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
        pushButton_7->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_11->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>\344\270\212\344\270\200\351\246\226</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_11->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>\346\232\202\345\201\234/\346\222\255\346\224\276</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>\344\270\213\344\270\200\351\246\226</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_5->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_3->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>\351\237\263\351\207\217</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_6->setWhatsThis(QCoreApplication::translate("Widget", "<html><head/><body><p>\351\237\263\351\207\217</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_6->setText(QString());
#if QT_CONFIG(whatsthis)
        List_of_lyrics->setWhatsThis(QCoreApplication::translate("Widget", "<html><head/><body><p>\346\255\214\350\257\215\345\210\227\350\241\250</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        List_of_lyrics->setText(QString());
        currenttime->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        totaltime->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_10->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>\345\205\263\351\227\255</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_10->setWhatsThis(QCoreApplication::translate("Widget", "<html><head/><body><p>\346\234\200\345\260\217\345\214\226</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_10->setText(QString());
        backGround->setText(QString());
        Song_Search_2->setText(QCoreApplication::translate("Widget", "\351\243\231\345\215\207\346\255\214\346\233\262", nullptr));
        Song_Search->setText(QCoreApplication::translate("Widget", "\346\255\214\346\233\262\346\220\234\347\264\242", nullptr));
        likeBtn->setText(QCoreApplication::translate("Widget", "like", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\346\230\237\347\201\253\345\244\247\346\250\241\345\236\213", nullptr));
        lyrics_view->setText(QString());
        songname->setText(QString());
        reLogin->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
