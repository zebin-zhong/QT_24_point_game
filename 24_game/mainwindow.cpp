#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QString>
#include <QTime>
#include <QtGlobal>
#include <QMessageBox>
#include <QMovie>
#include <QSound>
#include <QCoreApplication>
#include <time.h>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include "handle.h"
#include <QMouseEvent>
#include <QtMultimedia/qmediaplayer.h>
#include <QTimer>
#include <QDir>
#include <QFileDialog>
#include <QFontMetrics>


using namespace std;
QString duration_time;
QString position_time;
int music_amount = 0;//记录歌曲数目
int music_index = 0;//记录当前播放文件标记
int *num_array = new int[4];//声明一个全局数组存储随机数值
int curIndex = 0;//当前文字下标值
static int play_flag = 0;
static QMediaPlayer *player = new QMediaPlayer;  //创建一个音乐播放器, 必须静态声明，否则会每次点击重复创建造成重音
static QMediaPlaylist *musicList = new QMediaPlaylist;  //添加音乐列表


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

/*构造函数，做一些初始化操作*/
ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*一些ui设置*/
    this->ui_init();

}

/*析构函数*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*一些ui初始化设置*/
void MainWindow::ui_init()
{
    /*设置窗体的大小（规定窗体大小)*/
    setFixedSize(860, 458);

    /*设置logo*/
    setWindowIcon(QIcon(":/photo/logo.ico"));

    /*改变鼠标形状*/
    this->mouse_image(":/photo/finger_1.png");

    ui->but1->setText("开始游戏");
    ui->but1->setStyleSheet("border-image: url(:/photo/button.png); color:white");
    ui->but2->setStyleSheet("border-image: url(:/photo/button_box.png); color:white");
    ui->label_music_name->setStyleSheet("color:white");
    ui->label0->setStyleSheet("color:white");
    ui->lineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset; color:white");//设置无边框且透明背景
    ui->label1->setText("0");
    ui->but2->setVisible(false);

    /*鼠标移动到鸡的身上显示文字，使用鼠标移动事件*/
    ui->label_text->setVisible(false);
    ui->centralWidget->setMouseTracking(true);//先把QMainWindow的CentrolWidget使用setMouseTracking(true)开启移动监视
    this->setMouseTracking(true);//这是激活整个窗体的鼠标追踪,不这样做的话就只能一直点击鼠标一个按钮才能触发移动事件
    ui->label_rooster->setMouseTracking(true);//进入某个按钮时，鼠标追踪属性失效，因此也需要激活该按钮的鼠标追踪功能

    ui->label_music_time->setStyleSheet("color: white");
    ui->label1->setStyleSheet("color: white");
    ui->label2->setStyleSheet("color: white");
    ui->label3->setStyleSheet("color: white");

    /*歌曲信息滚动显示*/
    QTimer *pTimer = new QTimer(this);
    connect(pTimer,  SIGNAL(timeout()),  this,  SLOT(scrollCaption()));
    pTimer->start(300);// 定时300毫秒

    /*设置一些gif*/
    this->gif_play();

    /*音乐进度条更新信号连接*/
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(onPositionChanged(qint64)));//进度条
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));//总时长
    connect(player, SIGNAL(metaDataChanged()), this, SLOT(get_music_info()));//歌曲信息
    connect(ui->slider_music,SIGNAL(sliderMoved(int)),this,SLOT(onSliderMoved(int)));//拖动进度条，改变视频的进度

    /*播放背景音乐*/
    this->music_play();
}

/*音乐信息滚动显示*/
void MainWindow::scrollCaption()
{
    QString play_text;
    static int play_text_len;
    static int nPos = 0;
    static bool loop_once = false;//判断是否循环了一次

    play_text = this->get_music_info();
    // 当截取的位置比字符串长时，从头开始
    if (loop_once==true)
    {
        play_text = "                                   " + this->get_music_info();
    }
    if (nPos > play_text.length())
    {
        loop_once = true;
        nPos = 0;
        return;//不加这个return会在这次判断后再打印一遍原来的play_text，多余了。
    }
    ui->label_music_name->setText(play_text.mid(nPos));
    nPos++;
}

/*下一组*/
void MainWindow::on_but1_clicked()
{

    ui->but2->setText("确认");//点击下一组的 时候将“已答”按钮变为“确认”
    ui->lineEdit->setPlaceholderText("请输入数学表达式...");
    ui->lineEdit->setText("");//清空输入框

    if (ui->but1->text() == "下一组")
    {
        this->rand_num();
        this->rand_num_display();
        /*QMessageBox MBox;
        MBox.setWindowTitle("来自bin的温馨提示");
        MBox.setText("确定要更换一组吗？");
        QPushButton *agreeBut = MBox.addButton("是的客官(^∀^) ", QMessageBox::AcceptRole);
        QPushButton *disagreeBut = MBox.addButton("算了，继续肝(ง'-̀'́)ง", QMessageBox::RejectRole);
        MBox.exec();
        if (MBox.clickedButton() == (QAbstractButton*)agreeBut)
        {
            this->rand_num();
            this->rand_num_display();

        }
        else if (MBox.clickedButton() == (QAbstractButton*)disagreeBut)
        {

        }*/

    }
    else
    {
        ui->but1->setText("下一组");
        this->rand_num();
        this->rand_num_display();
        ui->but2->setVisible(true);

    }
}

/*表达式运算结果判断*/
void MainWindow::on_but2_clicked()
{
    /*初始化以及答案文本字符串的获取*/
    static int score = 0;
    string res;
    string label1_score;
    QString str;
    bool is_pass;
    res = ui->lineEdit->text().toStdString();//文本获取内容为QString，转成string
    label1_score = ui->label1->text().toStdString();

    is_pass = this->judge(res);//表达式规范判断函数
    if (is_pass == true)
    {
        /*判断结果*/
        if (handle(res) == true)
        {
            str = QString::fromStdString(label1_score);
            score = str.toInt(); //数字字符串转整数
            score += 100;
            str = QString("%1").arg(score); //整数转数字字符串
            ui->label1->setText(str);

            QMessageBox mBox;
            mBox.setWindowTitle(" ");
            mBox.setText("恭喜你，答案正确！");
            mBox.exec();
            this->on_but1_clicked();
        }
        else
        {
            QMessageBox mBox;
            mBox.setWindowTitle(" ");
            mBox.setText("很遗憾，答案错误哦，继续努力！");
            mBox.exec();
        }
    }
    else
    {
        QMessageBox sBox;
        sBox.setWindowTitle(" ");
        sBox.setText("算式格式有误，请检查操作符或数字、数字个数是否有误！");
        sBox.exec();
    }
}

/*更改鼠标图标*/
void MainWindow::mouse_image(QString image)
{
    QCursor cCursor;
    QPixmap cMap(image);
    QSize cSize(30, 30);
    QPixmap cScaleMap = cMap.scaled(cSize, Qt::KeepAspectRatio);
    cCursor = QCursor(cScaleMap);
    ui->centralWidget->setCursor(cCursor);
}

/*音乐开关图片切换,并控制音量*/
void MainWindow::on_but_music_clicked()
{
    if (play_flag == 0)
    {
        ui->but_music->setStyleSheet("border-image: url(:/photo/music_open.png)");
        player->setVolume(80);
        play_flag = 1;
    }
    else
    {
        ui->but_music->setStyleSheet("border-image: url(:/photo/music_close.png)");
        player->setVolume(0);
        //player->pause();
        play_flag = 0;
    }
}

/*表达式格式判断*/
bool MainWindow::judge(string res)//可能还存在“10”这个数字拆成1和0来用却无法判断的bug
{
    int num_i = 0;
    QString num_curr = "0";
    QString ops_curr = " ";
    QString ops_next = " ";
    string ops = "+-*/()";
    string ops_count = "+-*/";
    int num_array_len = 4;
    /*复制一个数组变量*/
    int new_array[4];
    for(int i=0; i<4; i++)
         new_array[i] = num_array[i] ;

    /*将生成的四个随机数组合成字符串用于判断*/
    string rand_str;
    QString num_1 = QString::number(num_array[0]);
    QString num_2 = QString::number(num_array[1]);
    QString num_3 = QString::number(num_array[2]);
    QString num_4 = QString::number(num_array[3]);
    for (int i = 0; i < 4; i++)
    {
        rand_str += to_string(num_array[i]);
    }
    rand_str += "\0";

    /*判断写入的表达式的数字是否在这些随机数内*/
    for(int j = 0; j < res.length(); j++)
    {
        /*如果是数字*/
        if (ops.find(res[j]) == ops.npos)
        {
            num_curr = res[j];//记录当前数字(QString类型）
            /*解决“10”这个数字的问题,因为10在字符串中是“1”和“0”*/
            if (num_curr==QString::number(1) && j<res.length()-1)// 如果字符“1”不是索引的最后一个（也就是1不是式子最末尾的数）
            {
                if(res[j+1]==QString::number(0))//如果1的后面是0，就是10
                {
                    j++;
                    num_curr = "10";
                }
                else if (ops.find(res[j+1]) == ops.npos)
                {
                    return false;
                }
            }
            /*解决除10以外两位以上数字不合法的问题*/
            if (num_curr!=QString::number(1) && j<res.length()-1)//如果是非1数字
            {
                if(ops.find(res[j+1]) == ops.npos)//如果非1数字后面还是数字，报错
                {
                    return false;
                }
            }

            num_i++;//记录数字个数
            //如果不在四个随机数中
            if(num_curr!=num_1 && num_curr!=num_2 && num_curr!=num_3 && num_curr!=num_4)
            {
                return false;
            }
            //如果在四个数内，判断是否被重复使用
            else
            {
                int temp_cont = num_array_len;
                for (int k = 0; k < num_array_len; k++)
                {
                    qDebug() << "j:"<<j<< "k:"<<k<<"len:"<<num_array_len<<"num_array"<<new_array[k]<<"num_curr"<<num_curr<<endl;
                    if (QString::number(new_array[k]) == num_curr && k != num_array_len - 1)//如果找到相等的数
                    {
                        for (int r = k; r < num_array_len; r++)
                        {
                            new_array[r] = new_array[r + 1];
                        }
                        --num_array_len;
                        break;
                    }
                    else  if (QString::number(new_array[k]) == num_curr && k == num_array_len - 1)//如果找到相等的数在最后一个，原地删除
                    {
                         --num_array_len;
                        break;
                    }
                }
                if (num_array_len == temp_cont)//如果找不到
                    return false;
            }

        }
        /*如果是操作符*/
        else
        {
            ops_curr = res[j];  //当前扫描到的操作符
            ops_next = res[j+1];  //下一个操作符

            /*如果操作符位于第一个且第一个字符不是 "("，报错*/
            if (j == 0 && ops_curr != "(")
            {
                return false;
            }
            /*如果操作符位于最后一个且不是 ")"， 报错*/
            if (j == res.size() && ops_curr != ")")
            {
                return false;
            }

        }
    }
    if (num_i != 4)
    {
        return false;
    }
    return true;
}

/*产生随机数并显示*/
void MainWindow::rand_num()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));          //设置随机数种子
    int rand1 = qrand() % 10 + 1;
    int rand2 = qrand() % 10 + 1;
    int rand3 = qrand() % 10 + 1;
    int rand4 = qrand() % 10 + 1;

    /*前面已经声明一个全局变量存储随机数数组*/
    num_array[0] = rand1;
    num_array[1] = rand2;
    num_array[2] = rand3;
    num_array[3] = rand4;
}

/*显示随机数*/
void MainWindow::rand_num_display()
{
    ui->num1->setStyleSheet(this->poke(num_array[0]));
    ui->num2->setStyleSheet(this->poke(num_array[1]));
    ui->num3->setStyleSheet(this->poke(num_array[2]));
    ui->num4->setStyleSheet(this->poke(num_array[3]));
}

/*鼠标点击切换手势*/
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //int x = event->x();
    //int y = event->y();
    // 如果是鼠标左键按下
    if(event->button() == Qt::LeftButton)
    {
        this->mouse_image(":/photo/finger_2.png");
        ui->label_text->setVisible (false);
    }

}

/*鼠标松开切换手势*/
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
   this->mouse_image(":/photo/finger_1.png");
}

/*帮助信息*/
void MainWindow::on_but_help_clicked()
{
    QString tips = "  给出4个数字,所给数字均为有整数(1至10之间, 10, J, Q, K均代表10),用加、减、乘、除(可加括号)把给出的数算成24,每个数必须用一次且只能用一次。";
    QMessageBox sBox;
    sBox.setWindowTitle("游戏规则");
    sBox.setText(tips);
    sBox.exec();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(ui->label_rooster->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        ui->label_text->setVisible (true);
    else
    {
         ui->label_text->setVisible (false);
         event->ignore();
    }

}

/*默认播放背景音乐*/
void MainWindow::music_play()
{
    musicList->addMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath())+"\\music\\Taylor Swift - Love Story.mp3"));  //添加音乐列表
    musicList->addMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath())+"\\music\\yinghuacao.mp3"));
    musicList->addMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath())+"\\music\\background_music.mp3"));
    musicList->addMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath())+"\\music\\Danny Avila - End Of The Night (Explicit).mp3"));
    //musicList->addMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath())+"\\music\\background_music.mp3"));
    musicList->setPlaybackMode(QMediaPlaylist::Loop);


    player->setPlaylist(musicList);
    player->setVolume(80);  //音量
    ui->but_music->setStyleSheet("border-image: url(:/photo/music_open.png)");
    //QString author = player->metaData("Title").toString();
    //ui->label_music->setText(author);
    player->play();
    play_flag = 1;
}

/*播放gif*/
void MainWindow::gif_play()
{
    QMovie *gif1 = new QMovie(":/photo/coin.gif");
    ui->label_coin->setMovie(gif1);
    gif1->setScaledSize(QSize(35,35));
    gif1->start();

    QMovie *gif2 = new QMovie(":/photo/jige.gif");
    ui->label_rooster->setMovie(gif2);
    gif2->setScaledSize(QSize(40,40));
    gif2->start();

    QMovie *gif3 = new QMovie(":/photo/flower.gif");
    ui->label_flower->setMovie(gif3);
    gif3->setScaledSize(QSize(35,35));
    gif3->start();
}

/*设置按钮*/
void MainWindow::on_but_set_clicked()
{
    // do something
}

/*设置进度条当前音乐的总时长*/
void MainWindow::onDurationChanged(qint64 duration)
{
    ui->slider_music->setMaximum(duration);
    //设置进度条最大值 也就是歌曲时长 ms
    int secs = duration/1000; //全部秒数
    int mins = secs/60;//分
    secs = secs % 60;//秒
    duration_time = QString::asprintf("%d:%d",mins,secs);
    ui->label_music_time->setText(position_time+"/"+duration_time);
}

/*当前音乐播放时间位置变化，更新进度条显示*/
void MainWindow::onPositionChanged(qint64 position)
{

    ui->slider_music->setValue(position);
    int secs = position/1000;
    int mins = secs/60;
    secs = secs % 60;
    position_time = QString::asprintf("%d:%d",mins,secs);
    ui->label_music_time->setText(position_time+"/"+duration_time);

}

/*根据进度条的value，改变视频的进度*/
void MainWindow::onSliderMoved(int value)
{
    player->setPosition(value);  //视频跟着进度条变
}

/*暂停or播放*/
void MainWindow::on_but_play_clicked()
{
    if (player->state()==player->PlayingState)
    {
        player->pause();
        ui->but_play->setStyleSheet("QPushButton{                                     \
                                    border-image: url(:/photo/music_play_white.png); \
                                    background-color:rgb(170,170,255);                \
                                    color:white;                                      \
                                    border-radius:11px;                               \
                                    border:2px groove gray;                           \
                                    border-style:outset;                              \
                                    }");
    }
    else
    {
        player->play();
        ui->but_play->setStyleSheet("QPushButton{                                     \
                                    border-image: url(:/photo/music_pause_white.png); \
                                    background-color:rgb(170,170,255);                \
                                    color:white;                                      \
                                    border-radius:11px;                               \
                                    border:2px groove gray;                           \
                                    border-style:outset;                              \
                                    }");
    }
}

/*下一曲*/
void MainWindow::on_but_next_clicked()
{
    music_amount = musicList->mediaCount();
    if (music_index==music_amount)//如果已经是最后一个文件了
    {
        music_index = 0;//从第一个文件重新开始播放
        musicList->setCurrentIndex(music_index);
        player->play();
        ui->but_play->setStyleSheet("QPushButton{                                     \
                                    border-image: url(:/photo/music_pause_white.png); \
                                    background-color:rgb(170,170,255);                \
                                    color:white;                                      \
                                    border-radius:11px;                               \
                                    border:2px groove gray;                           \
                                    border-style:outset;                              \
                                    }");
    }
    else
    {
        musicList->setCurrentIndex((++music_index));
        player->play();
        ui->but_play->setStyleSheet("QPushButton{                                     \
                                    border-image: url(:/photo/music_pause_white.png); \
                                    background-color:rgb(170,170,255);                \
                                    color:white;                                      \
                                    border-radius:11px;                               \
                                    border:2px groove gray;                           \
                                    border-style:outset;                              \
                                    }");
    }
}

/*上一曲*/
void MainWindow::on_but_last_clicked()
{
    music_amount = musicList->mediaCount();
    if (music_index==0)//如果已经是第一个文件了
    {
        music_index = music_amount-1;//索引是从0开始的，最后一个文件索引要减1
        musicList->setCurrentIndex(music_index);
        player->play();
        ui->but_play->setStyleSheet("QPushButton{                                     \
                                    border-image: url(:/photo/music_pause_white.png); \
                                    background-color:rgb(170,170,255);                \
                                    color:white;                                      \
                                    border-radius:11px;                               \
                                    border:2px groove gray;                           \
                                    border-style:outset;                              \
                                    }");
    }
    else
    {
        musicList->setCurrentIndex((--music_index));
        player->play();
        ui->but_play->setStyleSheet("QPushButton{                                     \
                                    border-image: url(:/photo/music_pause_white.png); \
                                    background-color:rgb(170,170,255);                \
                                    color:white;                                      \
                                    border-radius:11px;                               \
                                    border:2px groove gray;                           \
                                    border-style:outset;                              \
                                    }");
    }
}

/*从外部添加音乐到播放列表*/
void MainWindow::on_but_file_clicked()
{

   QString curPash =QDir::currentPath();
   QString dlgTitle="选择音频文件";
   QString filter="音频文件(*.mp3 *.wav *.wma)mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)";
   QStringList fileList = QFileDialog::getOpenFileNames(this,dlgTitle,curPash,filter);
   QString file_acount = QString::number(fileList.count());

   if(fileList.count()<1)
       return;
   else
   {
       for(int music_index = 0; music_index<fileList.count(); music_index++)
       {
           //QFileInfo fileinfo = QFileInfo(fileList[music_index]);
           //qDebug() << fileinfo.fileName();//获取文件名
           musicList->addMedia(QUrl::fromLocalFile(fileList[music_index]));
           //ui->plainTextEdit->appendPlainText(fileList.at(i));
           //将选择的文件显示在文本框上
       }
       QMessageBox mBox;
       mBox.setWindowTitle(" ");
       mBox.setText("成功添加"+file_acount+"首歌曲到播放列表！");
       mBox.exec();
   }

}

/*获取歌曲信息*/
QString MainWindow::get_music_info()
{
    QString title = player->metaData(QMediaMetaData::Title).toString();//歌名
    QString auther_list =  player->metaData("Author").toString();//作者
    QString res_text = title+"-"+auther_list;
    return res_text;
}

/*扑克图片处理*/
QString MainWindow::poke(int num)
{
    switch(num)
    {

        case 1  :
        {
            QString candidates[] = {"QLabel{border-image: url(:/photo/poke/14.jpg);}",
                                     "QLabel{border-image: url(:/photo/poke/27.jpg);}",
                                     "QLabel{border-image: url(:/photo/poke/40.jpg);}",
                                     "QLabel{border-image: url(:/photo/poke/53.jpg);}"};
            int r = rand() % 4;
            return candidates[r];
        }
           break;
        case 2  :
        {
            QString candidates[] = {"QLabel{border-image: url(:/photo/poke/15.jpg);}",
                                    "QLabel{border-image: url(:/photo/poke/28.jpg);}",
                                    "QLabel{border-image: url(:/photo/poke/41.jpg);}",
                                    "QLabel{border-image: url(:/photo/poke/54.jpg);}"};
            int r = rand() % 4;
            return candidates[r];
        }
           break;
        case 3  :
        {
           QString candidates[] = {"QLabel{border-image: url(:/photo/poke/3.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/29.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/42.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/16.jpg);}"};
           int r = rand() % 4;
           return candidates[r];
        }
           break;
        case 4  :
        {
           QString candidates[] = {"QLabel{border-image: url(:/photo/poke/4.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/30.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/43.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/17.jpg);}"};
           int r = rand() % 4;
           return candidates[r];
        }
           break;
        case 5  :
        {
           QString candidates[] = {"QLabel{border-image: url(:/photo/poke/5.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/31.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/44.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/18.jpg);}"};
           int r = rand() % 4;
           return candidates[r];
        }
           break;
        case 6  :
        {
           QString candidates[] = {"QLabel{border-image: url(:/photo/poke/6.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/32.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/45.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/19.jpg);}"};
           int r = rand() % 4;
           return candidates[r];
        }
           break;
        case 7  :
        {
           QString candidates[] = {"QLabel{border-image: url(:/photo/poke/7.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/33.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/46.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/20.jpg);}"};
           int r = rand() % 4;
           return candidates[r];
        }
           break;
        case 8  :
        {
           QString candidates[] = {"QLabel{border-image: url(:/photo/poke/8.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/34.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/47.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/21.jpg);}"};
           int r = rand() % 4;
           return candidates[r];
        }
           break;
        case 9  :
        {
           QString candidates[] = {"QLabel{border-image: url(:/photo/poke/9.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/35.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/48.jpg);}",
                                 "QLabel{border-image: url(:/photo/poke/22.jpg);}"};
           int r = rand() % 4;
           return candidates[r];
        }
           break;
        case 10  :
        {
           QString candidates[] = {"QLabel{border-image: url(:/photo/poke/10.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/36.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/49.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/23.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/24.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/25.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/26.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/11.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/12.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/13.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/37.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/38.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/39.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/50.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/51.jpg);}",
                                  "QLabel{border-image: url(:/photo/poke/52.jpg);}"};
           int r = rand() % 16;
           return candidates[r];
         }
           break;
       default:
          return "QLabel{border-image: url(:/photo/叉.png);}";
          break;

    }
}


