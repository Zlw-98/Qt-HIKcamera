
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
#include <QDateTime>
#include <iostream>
#include <fstream> // c++�ļ�����

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
    ELEMENT = 0,  //������Ϳ���ɵĲ���
    MEASURE = 1,  //��Ҫ��������ɵĲ���
    CUSTOMARC = 2,//�Զ���Բ�����
    SCALE = 3,    //ͼ������
};
//Բ����Ϣ
struct CircleData
{
    QPointF center;
    double radius;
    double diameter = 2 * radius;
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
    on_arcmidBtn_clicked = 7,   //Բ���е�
    on_cirlintanBtn_clicked = 8,   //Բ-���е�
    on_intersectionBtn_clicked = 9,//��-�߽���
    on_linmidBtn_clicked = 10,   //�߶��е�
    on_circirtanBtn_clicked = 11,//ԲԲ�е�
    on_circirdisBtn_clicked = 12,//ԲԲ����
    on_linlindisBtn_clicked = 13,//���߾���
    on_radiusBtn_clicked = 14,   //�뾶
    on_diameterBtn_clicked = 15, //ֱ��
    on_arcAngleBtn_clicked = 16, //Բ���Ƕ�
    on_linlinAngleBtn_clicked = 17,//���߽Ƕ�
    on_chamferBtn_clicked = 18,  //����
    on_perpendicularityBtn_clicked = 19,//��ֱ��
    on_roundnessBtn_clicked = 20,//Բ��
    on_parallelismBtn_clicked = 21,//ƽ�ж�
    on_axialityBtn_clicked = 22,//ͬ���
    on_taperBtn_clicked = 23,//׶��
    on_customArcBtn_clicked = 24,//�Զ���Բ��
    on_SCALED = 25,//����

};

class myLabel : public QLabel
{
    Q_OBJECT

public:
    cv::Mat cv_src;

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
    QRectF getRect(QPointF& StartPoint, QPointF& EndPoint);
    QRectF getMoveRect();
    QPointF getMovePoint();
    QRectF getSelectRect();
    bool isPressPointInSelectRect(QPointF mousePressPoint);   
    void getDistrict();                  //opencv��ȡѡ������
    void getPt();                     //����ֱ��
    QPixmap getPix(QPixmap);           //��ȡ��ǰlabel�µ�pixmap
    void getSrc(cv::Mat,double);            //��ȡԭʼͼ��
    double scaled_ratio;             //ԭʼͼ����labelͼ�����
    cv::Rect cv_rect;
    vector<cv::Rect> cv_rect1;      //����һ�����ο�����Ϊvector��������Ϊcv_rect�ڻ���ʱ���
    cv::Rect cv_rect2;
    cv::Mat cv_dst;                    //�ⲿ��ȡROI
    cv::Mat cv_dst1, cv_dst2;
    clickedBtn m_clickedBtn;          //�ⲿ���������ֱ��/Բ/Բ��...��   
    int getClickedBtn(int);
    Mode m_Mode;                      //�ⲿ���廭ͼģʽ
    int getMode(int);
    void SaveParameter(int, string);
    int LoadParameter(string);

    int deviceOpened = 0;
    int triggerMode = 0;
    

    CircleData findCircle(QPointF pt1, QPointF pt2, QPointF pt3);
    double cal_angle(QPointF a, QPointF b, QPointF c);
    double calculate_distance(QPointF ps0, QPointF ps1, QPointF ps2);

private:
    QPointF pp,p1,p2,p3,p4;
    double num;
    int totalXMove = 0, totalYMove = 0;
    vector<QLineF> Line;
    vector<CircleData> Circle;
    vector<QPointF> Point;
    vector<QLineF> linlindis_Line;
    vector<double> linlindis;
    vector<QLineF> ptlindis_Line;
    vector<double> ptlindis;
    vector<QLineF> ptptdis_Line;
    vector<double> ptptdis;
    vector<QLineF> circirdis_Line;
    vector<double> circirdis;
    vector<QLineF> linlinangle_Line;
    vector<double> linlinangle;
    vector<QLineF> taper_Line;
    vector<double> Taper;
    vector<QLineF> parallelism_Line;
    vector<double> Parallelism;
    vector<QLineF> perpendicularity_Line;
    vector<double> Perpendicularity;
    vector<QLineF> arcangle_Line;
    vector<double> arcangle;
    vector<QPointF> Roundness_Point;
    vector<double> Roundness;
    vector<QPointF> axiality_Point;
    vector<double> axiality;
    

private:
    double ratio = 0.0196;      //һ�����ص��Ӧ0.0196mm
    QPointF StartPoint;          //�������
    QPointF EndPoint;            //�����յ�
    QPointF PtPoint;            //��ǰ�Ľ���
    QPointF lastPtPoint;         //���������ʱ�ĵ�һ������
    QLineF lastLine;             //�����߾���ʱ�ĵ�һ���߶�
    QLineF curLine;              //�����߾���ʱ�ĵ�ǰ�߶�
    QLineF chamfer;              //����
    QPointF intersectionPt;      //ֱ�߽���
    double LineLineAngle;        //���߽Ƕ�
    double taper;                //׶��
    double perpendicularity;     //��ֱ��
    double parrallelism;         //ƽ�ж�
    double VerAxiality,HorAxiality; //ͬ���
    int Parallel;                //�Ƿ�ƽ��
    QPointF lineStartPoint;     //���ֱ�ߵ����
    QPointF lineEndPoint;       //���ֱ�ߵ��յ�
    QPointF footPoint;          //����
    double roundness;           //Բ��            
    QPointF ArcMid;            //Բ���е�
    double ArcAngle;           //Բ���Ƕ�
    QPointF ArcCenter;          //Բ��Բ��
    double ArcRadius;          //Բ���뾶
    QPointF ArcPt0, ArcPt1, ArcPt2,temp = QPoint(0,0);//�Զ���Բ���������㼰�ƶ�ʱ����ʱ��
    double clockwise;          //�ж�˳ʱ�����ʱ��
    CircleData Arc;                //�Զ���Բ���Ĳ���
    double StartAngle;           //Բ����ʼ�Ƕ�
    int dr = 15,dx0,dy0,dx1,dy1;                  //����Բ���ķ�Χ
    QPointF ArcLinTan0, ArcLinTan1;//Բ-���е�
    QPointF lastCirCenter;         //���ԲԲ�е�ĵ�һ��Բ��
    QPointF curCirCenter;          //���ԲԲ�е�ĵڶ���Բ��
    QPointF CirTanPt;              //ԲԲ�е�
    double lastCirRadius, curCirRadius;//���ԲԲ�е������Բ�뾶
    double CenterDis;              //���ԲԲ�е㣬��Բ�ĵľ���
    QPointF leftPeakLineStartPt, leftPeakLineEndPt;     //���ֵ��
    QPointF rightPeakLineStartPt, rightPeakLineEndPt;   //�ҷ�ֵ��
    QPointF verCtrLineStartPt, verCtrLineEndPt;    //��ǰ��ֱ������
    QPointF horCtrLineStartPt, horCtrLineEndPt;    //��ǰˮƽ������
    QPointF lastVerCtrLineStartPt, lastVerCtrLineEndPt;//��һ����ֱ������
    QPointF lastHorCtrLineStartPt, lastHorCtrLineEndPt;//��һ��ˮƽ������
    QColor lineColor;               //������ɫ
    int lineSize;                  //5������
    bool isPressed;

private:
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
    
public:
    void onPresetImage(void);
    void onClearImage();
    void onLogData(QString);
private:
    qreal m_ZoomValue = 1.0;
    int m_XPtInterval = 0;
    int m_YPtInterval = 0;
    QPoint m_OldPos;
private:
    bool m_Pressed;
    //���ź�ƽ��
    void onZoomInImage(void);
    void onZoomOutImage(void);

    //�����¼�
    void wheelEvent(QWheelEvent* event) override;
    


};

#endif // MYLABEL_H
