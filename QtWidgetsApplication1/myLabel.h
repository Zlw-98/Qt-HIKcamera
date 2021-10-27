
#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QPainter>
#include <QPoint>
#include <QColor>
#include <QPen>
#include <QMouseEvent>
#include <qdebug.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <math.h>

using namespace std;
//using namespace cv;

//��ǰlabel�ı��
enum CurrentCaptureState {
    initCapture = 0,
    beginCaptureImage,
    finishCaptureImage,
    beginMoveCaptureArea,
    finishMoveCaptureArea,

};
//Ԫ�غͲ���
enum Mode {
    ELEMENT = 0,
    MEASURE = 1,
};

//������¼�
enum clickedBtn {
    on_lineBtn_clicked = 0,     //ֱ��
    on_peakLinBtn_clicked = 1,  //��ֵ��
    on_ctrLinBtn_clicked = 2,   //������
    on_circleBtn_clicked = 3,   //Բ
    on_arcBtn_clicked = 4,      //Բ��
    on_ptptdisBtn_clicked = 5,  //��-�����
    on_ptlindisBtn_clicked = 6, //��-�߾���


};

class myLabel : public QLabel
{
    Q_OBJECT

public:

    myLabel(QWidget* parent);
    //��д�����¼�
    virtual void paintEvent(QPaintEvent* event) override;
    //��갴��
    void mousePressEvent(QMouseEvent* e);
    //����ƶ�
    void mouseMoveEvent(QMouseEvent* e);
    //���̧��
    void mouseReleaseEvent(QMouseEvent* e);
    void clearRect();//������ο�����
    void clearPoint();//�����������
    QRectF getRect(const QPointF& StartPoint, const QPointF& EndPoint);
    QRectF getMoveRect();
    QPointF getMovePoint();
    QRectF getSelectRect();
    bool isPressPointInSelectRect(QPointF mousePressPoint);
    QPixmap getPix(QPixmap);           //��ȡ��ǰlabel�µ�pixmap
    void getDistrict();                  //opencv��ȡѡ������
    void getPt();                     //����ֱ��
    cv::Rect cv_rect;
    cv::Mat cv_dst;                    //�ⲿ��ȡROI
    clickedBtn m_clickedBtn;          //�ⲿ���������ֱ��/Բ/Բ��...��   
    int getClickedBtn(int);
    Mode m_Mode;                      //�ⲿ���廭ͼģʽ
    int getMode(int);


private:
    QPointF StartPoint;          //�������
    QPointF EndPoint;            //�����յ�
    QPointF PtPoint;            //��ǰ�Ľ���
    QPointF lastPtPoint;         //���������ʱ�ĵ�һ������
    QPointF lastLinStartPoint;   //�����߾���ʱ�ĵ�һ���߶ε����
    QPointF lastLinEndPoint;     //�����߾���ʱ�ĵ�һ���߶ε��յ�
    QPointF lineStartPoint;     //���ֱ�ߵ����
    QPointF lineEndPoint;       //���ֱ�ߵ��յ�
    QPointF footPoint;          //����
    QColor lineColor;               //������ɫ
    int lineSize;                  //5������
    bool isPressed;

    cv::Mat cv_src;
    vector<cv::Vec4f> lineData;
    QPixmap m_Pixmap;              //������������fitpixmap
    QPixmap m_capturePixmap;       //��ȡRect��ѡ����


    CurrentCaptureState m_currentCaptureState;  //��ǰ���ģʽ
    QRectF m_currentSelectRect;         //��ǰ�ľ��ο�

    QPointF m_startMovePoint;
    QPointF m_endMovePoint;
    QPointF movePoint;                 //����ƶ��ĵ�
    QPointF newStartPoint;             //��������ƶ��ĵ������������Ͻǵ�
    QPointF newEndPoint;               //��������ƶ��ĵ������������½ǵ�


signals:
    void StartPointSignal(QPointF p);  //��ʼ������ź�
    void StopPointSignal(QPointF p);  //����������ź�
    void StartMoveRectSignal(QRectF Rect);   //��ʼ�ƶ����ε��źţ��ƶ�ʽ��͸߲��䣬�ʲ���Ҫstop





};

#endif // MYLABEL_H
