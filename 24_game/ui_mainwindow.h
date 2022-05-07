/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label_coin;
    QLabel *num1;
    QLabel *num2;
    QLabel *num3;
    QLabel *num4;
    QLabel *label_flower;
    QLabel *label_pea;
    QPushButton *but_set;
    QPushButton *but_music;
    QPushButton *but2;
    QLineEdit *lineEdit;
    QLabel *label4;
    QLabel *label0;
    QPushButton *but1;
    QPushButton *but_help;
    QLabel *label_woniu;
    QSlider *slider_music;
    QLabel *label_music_name;
    QLabel *label_music_time;
    QPushButton *but_last;
    QPushButton *but_play;
    QPushButton *but_next;
    QPushButton *but_file;
    QFrame *frame;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(859, 480);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setInputMethodHints(Qt::ImhLowercaseOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setMouseTracking(true);
        centralWidget->setAutoFillBackground(true);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(130, 310, 131, 19));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        label1->setFont(font1);
        label1->setFrameShape(QFrame::NoFrame);
        label1->setFrameShadow(QFrame::Raised);
        label1->setTextFormat(Qt::RichText);
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(104, 310, 51, 16));
        label2->setOpenExternalLinks(false);
        label3 = new QLabel(centralWidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(76, 370, 45, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        label3->setFont(font2);
        label_coin = new QLabel(centralWidget);
        label_coin->setObjectName(QString::fromUtf8("label_coin"));
        label_coin->setGeometry(QRect(76, 300, 31, 31));
        num1 = new QLabel(centralWidget);
        num1->setObjectName(QString::fromUtf8("num1"));
        num1->setGeometry(QRect(200, 130, 81, 111));
        num1->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/poke_backgrand.png);"));
        num2 = new QLabel(centralWidget);
        num2->setObjectName(QString::fromUtf8("num2"));
        num2->setGeometry(QRect(327, 130, 81, 111));
        num2->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/poke_backgrand.png);"));
        num3 = new QLabel(centralWidget);
        num3->setObjectName(QString::fromUtf8("num3"));
        num3->setGeometry(QRect(455, 130, 81, 111));
        num3->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/poke_backgrand.png);"));
        num4 = new QLabel(centralWidget);
        num4->setObjectName(QString::fromUtf8("num4"));
        num4->setGeometry(QRect(582, 130, 81, 111));
        num4->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/poke_backgrand.png);"));
        label_flower = new QLabel(centralWidget);
        label_flower->setObjectName(QString::fromUtf8("label_flower"));
        label_flower->setGeometry(QRect(728, 28, 72, 72));
        label_pea = new QLabel(centralWidget);
        label_pea->setObjectName(QString::fromUtf8("label_pea"));
        label_pea->setGeometry(QRect(80, 20, 72, 72));
        but_set = new QPushButton(centralWidget);
        but_set->setObjectName(QString::fromUtf8("but_set"));
        but_set->setGeometry(QRect(818, 12, 28, 28));
        but_set->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/setting.png);"));
        but_music = new QPushButton(centralWidget);
        but_music->setObjectName(QString::fromUtf8("but_music"));
        but_music->setGeometry(QRect(14, 10, 28, 28));
        but_music->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/music_close.png);"));
        but2 = new QPushButton(centralWidget);
        but2->setObjectName(QString::fromUtf8("but2"));
        but2->setGeometry(QRect(410, 370, 80, 27));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        but2->setFont(font3);
        but2->setMouseTracking(false);
        but2->setFocusPolicy(Qt::StrongFocus);
        but2->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/button_box.png);"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 370, 242, 26));
        lineEdit->setFrame(true);
        label4 = new QLabel(centralWidget);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(125, 363, 271, 41));
        label4->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/input_box.png);"));
        label0 = new QLabel(centralWidget);
        label0->setObjectName(QString::fromUtf8("label0"));
        label0->setGeometry(QRect(104, 370, 51, 16));
        label0->setOpenExternalLinks(false);
        but1 = new QPushButton(centralWidget);
        but1->setObjectName(QString::fromUtf8("but1"));
        but1->setGeometry(QRect(600, 356, 161, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\215\216\346\226\207\351\232\266\344\271\246"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        but1->setFont(font4);
        but1->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/button.png);"));
        but_help = new QPushButton(centralWidget);
        but_help->setObjectName(QString::fromUtf8("but_help"));
        but_help->setGeometry(QRect(816, 45, 32, 31));
        but_help->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/photo/help.png);"));
        label_woniu = new QLabel(centralWidget);
        label_woniu->setObjectName(QString::fromUtf8("label_woniu"));
        label_woniu->setGeometry(QRect(70, 44, 72, 51));
        slider_music = new QSlider(centralWidget);
        slider_music->setObjectName(QString::fromUtf8("slider_music"));
        slider_music->setGeometry(QRect(50, 32, 151, 16));
        slider_music->setCursor(QCursor(Qt::PointingHandCursor));
        slider_music->setContextMenuPolicy(Qt::DefaultContextMenu);
        slider_music->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"  border: 0px solid #bbb;\n"
"}\n"
" \n"
"QSlider::sub-page:horizontal {\n"
"  background: rgb(255,255,0);\n"
"  border-radius: 0px;\n"
"  margin-top: 8px;\n"
"  margin-bottom: 9px;\n"
"}\n"
" \n"
"QSlider::add-page:horizontal {\n"
"  background: rgb(0,0,0);\n"
"  border: 0px solid #777; \n"
"  border-radius: 2px; \n"
"  margin-top: 8px; \n"
"  margin-bottom: 9px; \n"
"}\n"
" \n"
"QSlider::handle:horizontal { \n"
"  background: rgb(255,255,255); \n"
"  border: 1px solid rgba(102,102,102,102); \n"
"  width: 8px; \n"
"  height: 8px; \n"
"  border-radius: 5px; \n"
"  margin-top: 2px; \n"
"  margin-bottom: 2px; \n"
"}\n"
" \n"
"QSlider::handle:horizontal:hover { \n"
"  background: rgb(255,255,0); \n"
"  border: 1px solid rgba(102,102,102,102); \n"
"  border-radius: 5px; \n"
"}\n"
" \n"
"QSlider::sub-page:horizontal:disabled { \n"
"  background: #bbb; \n"
"  border-color: #999; \n"
"}\n"
" \n"
"QSlider::add-page:horizontal:disabled { \n"
"  background: #eee; \n"
"  border-color: #99"
                        "9; \n"
"}\n"
" \n"
"QSlider::handle:horizontal:disabled { \n"
"  background: #eee; \n"
"  border: 1px solid #aaa; \n"
"  border-radius: 4px; \n"
"}"));
        slider_music->setValue(0);
        slider_music->setOrientation(Qt::Horizontal);
        label_music_name = new QLabel(centralWidget);
        label_music_name->setObjectName(QString::fromUtf8("label_music_name"));
        label_music_name->setGeometry(QRect(50, 12, 141, 16));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(7);
        font5.setBold(false);
        font5.setItalic(true);
        font5.setWeight(50);
        label_music_name->setFont(font5);
        label_music_time = new QLabel(centralWidget);
        label_music_time->setObjectName(QString::fromUtf8("label_music_time"));
        label_music_time->setGeometry(QRect(214, 26, 101, 22));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(7);
        font6.setBold(true);
        font6.setWeight(75);
        label_music_time->setFont(font6);
        but_last = new QPushButton(centralWidget);
        but_last->setObjectName(QString::fromUtf8("but_last"));
        but_last->setGeometry(QRect(200, 6, 22, 22));
        but_last->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(170,170,255);\n"
"border-image: url(:/photo/music_last.png);\n"
"color:white;\n"
"border-radius:11px;\n"
"border:2px groove gray;\n"
"border-style:outset;\n"
"}"));
        but_play = new QPushButton(centralWidget);
        but_play->setObjectName(QString::fromUtf8("but_play"));
        but_play->setGeometry(QRect(230, 6, 22, 22));
        but_play->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-image: url(:/photo/music_pause_white.png);\n"
"background-color:rgb(170,170,255);\n"
"color:white;\n"
"border-radius:11px;\n"
"border:2px groove gray;\n"
"border-style:outset;\n"
"}"));
        but_next = new QPushButton(centralWidget);
        but_next->setObjectName(QString::fromUtf8("but_next"));
        but_next->setGeometry(QRect(260, 6, 22, 22));
        but_next->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(170,170,255);\n"
"border-image: url(:/photo/music_next.png);\n"
"color:white;\n"
"border-radius:11px;\n"
"border:2px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));
        but_file = new QPushButton(centralWidget);
        but_file->setObjectName(QString::fromUtf8("but_file"));
        but_file->setGeometry(QRect(290, 6, 20, 20));
        but_file->setMouseTracking(true);
        but_file->setTabletTracking(true);
        but_file->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/music_file.png);"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-2, 1, 862, 458));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/456.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        label4->raise();
        label1->raise();
        label2->raise();
        label3->raise();
        label_coin->raise();
        num1->raise();
        num2->raise();
        num3->raise();
        num4->raise();
        label_flower->raise();
        label_pea->raise();
        but_set->raise();
        but_music->raise();
        but2->raise();
        lineEdit->raise();
        label0->raise();
        but1->raise();
        but_help->raise();
        label_woniu->raise();
        slider_music->raise();
        label_music_name->raise();
        label_music_time->raise();
        but_last->raise();
        but_play->raise();
        but_next->raise();
        but_file->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 859, 25));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "24 \347\202\271\346\270\270\346\210\217\357\274\210Designed by bin\357\274\211", nullptr));
        label1->setText(QString());
        label2->setText(QCoreApplication::translate("MainWindow", " \357\274\232", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "\347\255\224\346\241\210", nullptr));
        label_coin->setText(QCoreApplication::translate("MainWindow", "\351\207\221\345\270\201", nullptr));
        num1->setText(QString());
        num2->setText(QString());
        num3->setText(QString());
        num4->setText(QString());
        label_flower->setText(QCoreApplication::translate("MainWindow", "\351\270\241\345\223\245", nullptr));
        label_pea->setText(QString());
        but_set->setText(QString());
        but_music->setText(QString());
        but2->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        label4->setText(QString());
        label0->setText(QCoreApplication::translate("MainWindow", " \357\274\232", nullptr));
        but1->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        but_help->setText(QString());
        label_woniu->setText(QCoreApplication::translate("MainWindow", "woniu", nullptr));
        label_music_name->setText(QCoreApplication::translate("MainWindow", "music info", nullptr));
        label_music_time->setText(QCoreApplication::translate("MainWindow", "00:00/00:00", nullptr));
        but_last->setText(QString());
        but_play->setText(QString());
#if QT_CONFIG(tooltip)
        but_file->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
