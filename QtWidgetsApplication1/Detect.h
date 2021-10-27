#pragma once
#include "myLabel.h"


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
    cv::Point pt;
    float footPointDistance;
    vector<cv::Vec4f> line_data;
    myLabel* mylabel;

};

