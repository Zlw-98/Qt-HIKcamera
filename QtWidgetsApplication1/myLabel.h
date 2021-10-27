
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
    ELEMENT = 0,
    MEASURE = 1,
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


};

class myLabel : public QLabel
{
    Q_OBJECT

public:

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
    QRectF getRect(const QPointF& StartPoint, const QPointF& EndPoint);
    QRectF getMoveRect();
    QPointF getMovePoint();
    QRectF getSelectRect();
    bool isPressPointInSelectRect(QPointF mousePressPoint);
    QPixmap getPix(QPixmap);           //获取当前label下的pixmap
    void getDistrict();                  //opencv获取选中区域
    void getPt();                     //画出直线
    cv::Rect cv_rect;
    cv::Mat cv_dst;                    //外部获取ROI
    clickedBtn m_clickedBtn;          //外部定义检测对象（直线/圆/圆弧...）   
    int getClickedBtn(int);
    Mode m_Mode;                      //外部定义画图模式
    int getMode(int);


private:
    QPointF StartPoint;          //画线起点
    QPointF EndPoint;            //画线终点
    QPointF PtPoint;            //当前的交点
    QPointF lastPtPoint;         //测量点距离时的第一个交点
    QPointF lastLinStartPoint;   //测量线距离时的第一条线段的起点
    QPointF lastLinEndPoint;     //测量线距离时的第一条线段的终点
    QPointF lineStartPoint;     //检测直线的起点
    QPointF lineEndPoint;       //检测直线的终点
    QPointF footPoint;          //垂足
    QColor lineColor;               //线条颜色
    int lineSize;                  //5种线型
    bool isPressed;

    cv::Mat cv_src;
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





};

#endif // MYLABEL_H
