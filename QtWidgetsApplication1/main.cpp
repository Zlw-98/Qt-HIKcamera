#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   //����Ӧ�ó������
    QtWidgetsApplication1 w;      //����һ�������ڶ���
    w.show();                     //��ʾ������
    return a.exec();              //�����¼�ѭ��

}
