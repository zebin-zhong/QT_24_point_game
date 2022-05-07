#include "mainwindow.h"
#include <QApplication>
#include "windows.h"
#include <QDesktopWidget>
#pragma comment(lib,"User32.lib")

int main(int argc, char *argv[])
{
    //控制图片缩放质量
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

//    qreal  cx = GetSystemMetrics(SM_CXSCREEN);//这个是Windows平台用来获取屏幕宽度的代码，因为在qApplication实例初始化之前，QGuiApplication::screens();无法使用。
//    qreal  cy = GetSystemMetrics(SM_CYSCREEN);
//    qreal scale = cx / cy;
//    qputenv("QT_SCALE_FACTOR", QString::number(scale).toLatin1());
   qputenv("QT_SCALE_FACTOR", "1.5");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
