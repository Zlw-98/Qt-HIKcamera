#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   //定义应用程序对象
    QtWidgetsApplication1 w;      //定义一个主窗口对象
    w.show();                     //显示主窗口
    return a.exec();              //启动事件循环

}
