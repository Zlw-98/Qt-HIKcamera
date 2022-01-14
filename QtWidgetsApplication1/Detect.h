#pragma once
#include "myLabel.h"

enum color_type
{
    unknown_error = 0,
    channel_3_color = 1,//3ͨ����ɫ
    channel_3_gray = 2,//3ͨ���Ҷ�
    channel_3_binary = 3,//3ͨ����ֵ
    channel_1_gray = 4,//1ͨ���Ҷ�
    channel_1_binary = 5,//1ͨ����ֵ
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
    vector<cv::Point> LinePoints;//ֱ���ϵĵ�
    vector<cv::Vec4f> line_data;//ֱ�ߵ�����յ�
    vector<cv::Vec3f> circles;  //Բ��Բ��
    double center_x, center_y, radius;// Բ����Բ��Բ�ĺͰ뾶
    double arcMid_x, arcMid_y;        //Բ���е�
    double arcAngle;                  //Բ���Ƕ�
    double roundness;                 //Բ��
    double chamfer_x0,chamfer_x1,chamfer_y0,chamfer_y1;             //���ǽǶ�
    double arclintan_x0, arclintan_y0, arclintan_x1, arclintan_y1; //Բ-���е�
    double leftPeakLine_x0 ,leftPeakLine_y0, leftPeakLine_x1, leftPeakLine_y1;    //���ֵ������յ�����
    double rightPeakLine_x0, rightPeakLine_y0, rightPeakLine_x1, rightPeakLine_y1;//�ҷ�ֵ������յ�����
    double ver_x, ver_y, ver_x1, ver_y1;   //��ֱ����������յ�����
    double hor_x, hor_y, hor_x1, hor_y1;   //ˮƽ����������յ�����
    myLabel* mylabel;

};

