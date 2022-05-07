#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>


using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_but1_clicked();

    void on_but2_clicked();

    void on_but_music_clicked();

    void on_but_help_clicked();

    void on_but_set_clicked();

    void onDurationChanged(qint64 duration);

    void onPositionChanged(qint64 position);

    void on_but_play_clicked();

    void on_but_next_clicked();

    void on_but_last_clicked();

    void on_but_file_clicked();

    QString get_music_info();

    void onSliderMoved(int value);

    void scrollCaption();


private:
    Ui::MainWindow *ui;
    void ui_init();
    void mouse_image(QString image);  
    void rand_num();
    QString poke(int num);
    bool judge(string res);
    void rand_num_display();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void music_play();
    void gif_play();
};

#endif // MAINWINDOW_H
