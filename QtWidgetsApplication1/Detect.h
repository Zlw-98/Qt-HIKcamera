#pragma once
#include "myLabel.h"

enum color_type
{
    unknown_error = 0,
    channel_3_color = 1,//3通道彩色
    channel_3_gray = 2,//3通道灰度
    channel_3_binary = 3,//3通道二值
    channel_1_gray = 4,//1通道灰度
    channel_1_binary = 5,//1通道二值
};


class Detect :
    private myLabel
{
public:
    Detect(QWidget* parent);
    void detectLine(cv::Mat);
    void detectPeakLin(cv::Mat);
    void detectCtrLin(cv::Mat);
    void detectCircle(cv::Mat);
    void detectArc(cv::Mat);
    void detectPoint(cv::Mat,cv::Point,cv::Point);
    void detectChamfer(cv::Mat);
    void detectRoundness(cv::Mat);
    void detectLinePoints(cv::Mat);
    double cal_angle(cv::Point a, cv::Point b, cv::Point c);
    void CustomArc(cv::Mat cv_dst);
    bool circleLeastFit(const std::vector<cv::Point>& points, double& center_x, double& center_y, double& radius);
    cv::Point pt;
    float footPointDistance;
    vector<cv::Point> LinePoints;//直线上的点
    vector<cv::Vec4f> line_data;//直线的起点终点
    vector<cv::Vec3f> circles;  //圆的圆心
    double center_x, center_y, radius;// 圆弧或圆的圆心和半径
    double arcMid_x, arcMid_y;        //圆弧中点
    double arcAngle;                  //圆弧角度
    double roundness;                 //圆度
    double chamfer_x0,chamfer_x1,chamfer_y0,chamfer_y1;             //倒角角度
    double arclintan_x0, arclintan_y0, arclintan_x1, arclintan_y1; //圆-线切点
    double leftPeakLine_x0 ,leftPeakLine_y0, leftPeakLine_x1, leftPeakLine_y1;    //左峰值线起点终点坐标
    double rightPeakLine_x0, rightPeakLine_y0, rightPeakLine_x1, rightPeakLine_y1;//右峰值线起点终点坐标
    double ver_x, ver_y, ver_x1, ver_y1;   //竖直中心线起点终点坐标
    double hor_x, hor_y, hor_x1, hor_y1;   //水平中心线起点终点坐标
    myLabel* mylabel;

};

