#include "Detect.h"

Detect::Detect(QWidget* parent) :myLabel(parent)
{
}



//寻找最大外接轮廓
vector<cv::Point> FindBigestContour(cv::Mat src) {
    int max_area_contour_idx = 0;
    double max_area = -1;
    vector<vector<cv::Point> >contours;
    findContours(src, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
    //handle case if no contours are detected
    CV_Assert(0 != contours.size());
    for (uint i = 0; i < contours.size(); i++) {
        double temp_area = contourArea(contours[i]);
        if (max_area < temp_area) {
            max_area_contour_idx = i;
            max_area = temp_area;
        }
    }
    return contours[max_area_contour_idx];
}

void Detect::detectPoint(cv::Mat cv_dst,cv::Point StartPoint,cv::Point EndPoint)
{
    //读入图像，转换为灰度
    cv::Mat src = cv_dst;
    cv::Mat src_gray;
    cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
    //阈值处理
    cv::Mat threshold_output;
    cv::threshold(src_gray, threshold_output, 150, 255, cv::THRESH_OTSU | cv::THRESH_BINARY_INV);
    //轮廓分析
    vector<vector<cv::Point> > contours;
    vector<cv::Vec4i> hierarchy;
    vector<cv::Point> biggestContour = FindBigestContour(threshold_output);//寻找最大轮廓
    line(src, StartPoint,EndPoint, cv::Scalar(255, 255, 0));//绘制线段
    //求出主方向直线和轮廓的交点，
    //遍历两个点之间的线段，得出和轮廓的交点
    cv::LineIterator it(src, StartPoint, EndPoint, 8);
    for (int i = 0; i < it.count; i++, ++it)
    {
        pt = it.pos();//获得线段上的点
        if (abs(pointPolygonTest(biggestContour, pt, 1)) < 0.0001) {
            circle(src, pt, 5, cv::Scalar(0, 0, 255), -1);
            break;
        }
    }
    imshow("Point",src);
    //waitKey();
}

//圆弧检测//待完成
void Detect::detectArc(cv::Mat cv_dst)
{
    cv::Mat srcImage = cv_dst;
    cv::imshow("srcImage", srcImage);
    cv::Mat srcGray;
    cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    //高斯平滑滤波
    GaussianBlur(srcGray, srcGray, cv::Size(9, 9), 2, 2);
    vector<cv::Vec3f> circles;
    
}

//圆检测
void Detect::detectCircle(cv::Mat cv_dst)
{
    cv::Mat srcImage = cv_dst;
    cv::imshow("srcImage", srcImage);
    cv::Mat srcGray;
    cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    //高斯平滑滤波
    GaussianBlur(srcGray, srcGray, cv::Size(9, 9), 2, 2);
    vector<cv::Vec3f> circles;
    //Hough圆检测
    HoughCircles(srcGray, circles, cv::HOUGH_GRADIENT, 1, srcGray.rows / 8, 200, 100, 0, 0);
    //将得到的结果绘图
    for (size_t i = 0; i < circles.size(); i++)
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        //检测圆中心
        circle(srcImage, center, 3, cv::Scalar(0, 255,0), -1, 8, 0);
        //检测圆轮廓
        circle(srcImage, center, radius, cv::Scalar(0, 255, 255), 3, 8, 0);
    }
    imshow("HoughResult", srcImage);
}

//检测中心线，，未完成
void Detect::detectCtrLin(cv::Mat cv_dst)
{
    cv::Mat src_gray;
    cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    cv::Mat src_canny;
    Canny(src_gray, src_canny, 100, 200, 3, true); //Canny边缘检测
    cv::imshow("edge img", src_canny);

    
}

//峰值线检测，，未完成   尝试convexHull
void  Detect::detectPeakLin(cv::Mat cv_dst)
{
    vector<vector<cv::Point>>contours;
    cv::Mat src_gray;
    cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    //使用Threshold检测图像边缘
    cv::Mat threshold_output;
    threshold(src_gray, threshold_output, 100, 255, cv::THRESH_OTSU);

    imshow("peakline img", threshold_output);


}

//检测直线
void  Detect::detectLine(cv::Mat cv_dst)
{
    //mylabel = new myLabel(this);
    //namedWindow("src", WINDOW_AUTOSIZE);
    //imshow("src", cv_dst);
    cv::Mat src_gray;
    cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    cv::Mat src_canny;
    Canny(src_gray, src_canny, 100, 250,3,true); //边缘检测
    cv::imshow("edge img", src_canny);

    //霍夫直线检测

    //HoughLinesP( InputArray image, OutputArray lines,
      //double rho,  // rho 的步长
      //double theta,  // 角度的步长，单位是度
      //int threshold, // 阈值,在一条线上的点超过这个阈值则判定为直线
      //double minLineLength = 0,  // 线段的最小宽度，如果低于最小宽度则舍弃掉
      //double maxLineGap = 0 );  // 线段之间的最小距离，如果距离小于maxLineGap就会进行合并

    HoughLinesP(src_canny, line_data, 0.5, CV_PI / 360.0, 25, 1, 20);
    //把得到的直线显示在图中
    cv::Scalar color = cv::Scalar(0, 255, 255);
    for (size_t i = 0; i < line_data.size(); i++) {
        cv::Vec4f temp = line_data[i];
        line(cv_dst, cv::Point(temp[0], temp[1]), cv::Point(temp[2], temp[3]), color, 4);

    }
    imshow("houghLinesP img", cv_dst);

    //waitKey(0);
}
