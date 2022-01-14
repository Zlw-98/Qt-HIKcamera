
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
#include <fstream> // c++文件操作

using namespace std;
//using namespace cv;

//当前label的标记
enum CurrentCaptureState {
    initCapture = 0,
    beginCaptureImage,
    finishCaptureImage,
    beginMoveCaptureArea,
    finishMoveCaptureArea,

};
//元素和测量
enum Mode {
    ELEMENT = 0,  //单个框就可完成的操作
    MEASURE = 1,  //需要两个框完成的操作
    CUSTOMARC = 2,//自定义圆弧检测
    SCALE = 3,    //图像缩放
};
//圆的信息
struct CircleData
{
    QPointF center;
    double radius;
    double diameter = 2 * radius;
};
//鼠标点击事件
enum clickedBtn {
    on_lineBtn_clicked = 0,     //直线
    on_peakLinBtn_clicked = 1,  //峰值线
    on_ctrLinBtn_clicked = 2,   //中心线
    on_circleBtn_clicked = 3,   //圆
    on_arcBtn_clicked = 4,      //圆弧
    on_ptptdisBtn_clicked = 5,  //点-点距离
    on_ptlindisBtn_clicked = 6, //点-线距离
    on_arcmidBtn_clicked = 7,   //圆弧中点
    on_cirlintanBtn_clicked = 8,   //圆-线切点
    on_intersectionBtn_clicked = 9,//线-线交点
    on_linmidBtn_clicked = 10,   //线段中点
    on_circirtanBtn_clicked = 11,//圆圆切点
    on_circirdisBtn_clicked = 12,//圆圆距离
    on_linlindisBtn_clicked = 13,//线线距离
    on_radiusBtn_clicked = 14,   //半径
    on_diameterBtn_clicked = 15, //直径
    on_arcAngleBtn_clicked = 16, //圆弧角度
    on_linlinAngleBtn_clicked = 17,//线线角度
    on_chamferBtn_clicked = 18,  //倒角
    on_perpendicularityBtn_clicked = 19,//垂直度
    on_roundnessBtn_clicked = 20,//圆度
    on_parallelismBtn_clicked = 21,//平行度
    on_axialityBtn_clicked = 22,//同轴度
    on_taperBtn_clicked = 23,//锥度
    on_customArcBtn_clicked = 24,//自定义圆弧
    on_SCALED = 25,//缩放

};

class myLabel : public QLabel
{
    Q_OBJECT

public:
    cv::Mat cv_src;

    myLabel(QWidget* parent);
    //重写绘制事件
    virtual void paintEvent(QPaintEvent* event) override;
    //鼠标按下
    void mousePressEvent(QMouseEvent* e);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* e);
    //鼠标抬起
    void mouseReleaseEvent(QMouseEvent* e);
    void clearRect();//清除矩形框数据
    void clearPoint();//清除交点数据
    QRectF getRect(QPointF& StartPoint, QPointF& EndPoint);
    QRectF getMoveRect();
    QPointF getMovePoint();
    QRectF getSelectRect();
    bool isPressPointInSelectRect(QPointF mousePressPoint);   
    void getDistrict();                  //opencv获取选中区域
    void getPt();                     //画出直线
    QPixmap getPix(QPixmap);           //获取当前label下的pixmap
    void getSrc(cv::Mat,double);            //获取原始图像
    double scaled_ratio;             //原始图像与label图像比例
    cv::Rect cv_rect;
    vector<cv::Rect> cv_rect1;      //将第一个矩形框设置为vector储存是因为cv_rect在绘制时会变
    cv::Rect cv_rect2;
    cv::Mat cv_dst;                    //外部获取ROI
    cv::Mat cv_dst1, cv_dst2;
    clickedBtn m_clickedBtn;          //外部定义检测对象（直线/圆/圆弧...）   
    int getClickedBtn(int);
    Mode m_Mode;                      //外部定义画图模式
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
    double ratio = 0.0196;      //一个像素点对应0.0196mm
    QPointF StartPoint;          //画线起点
    QPointF EndPoint;            //画线终点
    QPointF PtPoint;            //当前的交点
    QPointF lastPtPoint;         //测量点距离时的第一个交点
    QLineF lastLine;             //测量线距离时的第一条线段
    QLineF curLine;              //测量线距离时的当前线段
    QLineF chamfer;              //倒角
    QPointF intersectionPt;      //直线交点
    double LineLineAngle;        //线线角度
    double taper;                //锥度
    double perpendicularity;     //垂直度
    double parrallelism;         //平行度
    double VerAxiality,HorAxiality; //同轴度
    int Parallel;                //是否平行
    QPointF lineStartPoint;     //检测直线的起点
    QPointF lineEndPoint;       //检测直线的终点
    QPointF footPoint;          //垂足
    double roundness;           //圆度            
    QPointF ArcMid;            //圆弧中点
    double ArcAngle;           //圆弧角度
    QPointF ArcCenter;          //圆弧圆心
    double ArcRadius;          //圆弧半径
    QPointF ArcPt0, ArcPt1, ArcPt2,temp = QPoint(0,0);//自定义圆弧的三个点及移动时的临时点
    double clockwise;          //判断顺时针和逆时针
    CircleData Arc;                //自定义圆弧的参数
    double StartAngle;           //圆弧起始角度
    int dr = 15,dx0,dy0,dx1,dy1;                  //画出圆弧的范围
    QPointF ArcLinTan0, ArcLinTan1;//圆-线切点
    QPointF lastCirCenter;         //检测圆圆切点的第一个圆心
    QPointF curCirCenter;          //检测圆圆切点的第二个圆心
    QPointF CirTanPt;              //圆圆切点
    double lastCirRadius, curCirRadius;//检测圆圆切点的两个圆半径
    double CenterDis;              //检测圆圆切点，两圆心的距离
    QPointF leftPeakLineStartPt, leftPeakLineEndPt;     //左峰值线
    QPointF rightPeakLineStartPt, rightPeakLineEndPt;   //右峰值线
    QPointF verCtrLineStartPt, verCtrLineEndPt;    //当前竖直中心线
    QPointF horCtrLineStartPt, horCtrLineEndPt;    //当前水平中心线
    QPointF lastVerCtrLineStartPt, lastVerCtrLineEndPt;//上一个竖直中心线
    QPointF lastHorCtrLineStartPt, lastHorCtrLineEndPt;//上一个水平中心线
    QColor lineColor;               //线条颜色
    int lineSize;                  //5种线型
    bool isPressed;

private:
    vector<cv::Vec4f> lineData;
    QPixmap m_Pixmap;              //从主函数加载fitpixmap
    QPixmap m_capturePixmap;       //截取Rect框选区域


    CurrentCaptureState m_currentCaptureState;  //当前鼠标模式
    QRectF m_currentSelectRect;         //当前的矩形框

    QPointF m_startMovePoint;
    QPointF m_endMovePoint;
    QPointF movePoint;                 //鼠标移动的点
    QPointF newStartPoint;             //根据鼠标移动的点生产的新左上角点
    QPointF newEndPoint;               //根据鼠标移动的点生产的新右下角点


signals:
    void StartPointSignal(QPointF p);  //开始坐标的信号
    void StopPointSignal(QPointF p);  //结束坐标的信号
    void StartMoveRectSignal(QRectF Rect);   //开始移动矩形的信号，移动式宽和高不变，故不需要stop
    
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
    //缩放和平移
    void onZoomInImage(void);
    void onZoomOutImage(void);

    //滚轮事件
    void wheelEvent(QWheelEvent* event) override;
    


};

#endif // MYLABEL_H
