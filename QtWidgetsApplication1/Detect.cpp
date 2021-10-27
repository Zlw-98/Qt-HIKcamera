#include "Detect.h"

Detect::Detect(QWidget* parent) :myLabel(parent)
{
}



//Ѱ������������
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
    //����ͼ��ת��Ϊ�Ҷ�
    cv::Mat src = cv_dst;
    cv::Mat src_gray;
    cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
    //��ֵ����
    cv::Mat threshold_output;
    cv::threshold(src_gray, threshold_output, 150, 255, cv::THRESH_OTSU | cv::THRESH_BINARY_INV);
    //��������
    vector<vector<cv::Point> > contours;
    vector<cv::Vec4i> hierarchy;
    vector<cv::Point> biggestContour = FindBigestContour(threshold_output);//Ѱ���������
    line(src, StartPoint,EndPoint, cv::Scalar(255, 255, 0));//�����߶�
    //���������ֱ�ߺ������Ľ��㣬
    //����������֮����߶Σ��ó��������Ľ���
    cv::LineIterator it(src, StartPoint, EndPoint, 8);
    for (int i = 0; i < it.count; i++, ++it)
    {
        pt = it.pos();//����߶��ϵĵ�
        if (abs(pointPolygonTest(biggestContour, pt, 1)) < 0.0001) {
            circle(src, pt, 5, cv::Scalar(0, 0, 255), -1);
            break;
        }
    }
    imshow("Point",src);
    //waitKey();
}

//Բ�����//�����
void Detect::detectArc(cv::Mat cv_dst)
{
    cv::Mat srcImage = cv_dst;
    cv::imshow("srcImage", srcImage);
    cv::Mat srcGray;
    cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    //��˹ƽ���˲�
    GaussianBlur(srcGray, srcGray, cv::Size(9, 9), 2, 2);
    vector<cv::Vec3f> circles;
    
}

//Բ���
void Detect::detectCircle(cv::Mat cv_dst)
{
    cv::Mat srcImage = cv_dst;
    cv::imshow("srcImage", srcImage);
    cv::Mat srcGray;
    cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    //��˹ƽ���˲�
    GaussianBlur(srcGray, srcGray, cv::Size(9, 9), 2, 2);
    vector<cv::Vec3f> circles;
    //HoughԲ���
    HoughCircles(srcGray, circles, cv::HOUGH_GRADIENT, 1, srcGray.rows / 8, 200, 100, 0, 0);
    //���õ��Ľ����ͼ
    for (size_t i = 0; i < circles.size(); i++)
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        //���Բ����
        circle(srcImage, center, 3, cv::Scalar(0, 255,0), -1, 8, 0);
        //���Բ����
        circle(srcImage, center, radius, cv::Scalar(0, 255, 255), 3, 8, 0);
    }
    imshow("HoughResult", srcImage);
}

//��������ߣ���δ���
void Detect::detectCtrLin(cv::Mat cv_dst)
{
    cv::Mat src_gray;
    cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    cv::Mat src_canny;
    Canny(src_gray, src_canny, 100, 200, 3, true); //Canny��Ե���
    cv::imshow("edge img", src_canny);

    
}

//��ֵ�߼�⣬��δ���   ����convexHull
void  Detect::detectPeakLin(cv::Mat cv_dst)
{
    vector<vector<cv::Point>>contours;
    cv::Mat src_gray;
    cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    //ʹ��Threshold���ͼ���Ե
    cv::Mat threshold_output;
    threshold(src_gray, threshold_output, 100, 255, cv::THRESH_OTSU);

    imshow("peakline img", threshold_output);


}

//���ֱ��
void  Detect::detectLine(cv::Mat cv_dst)
{
    //mylabel = new myLabel(this);
    //namedWindow("src", WINDOW_AUTOSIZE);
    //imshow("src", cv_dst);
    cv::Mat src_gray;
    cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    cv::Mat src_canny;
    Canny(src_gray, src_canny, 100, 250,3,true); //��Ե���
    cv::imshow("edge img", src_canny);

    //����ֱ�߼��

    //HoughLinesP( InputArray image, OutputArray lines,
      //double rho,  // rho �Ĳ���
      //double theta,  // �ǶȵĲ�������λ�Ƕ�
      //int threshold, // ��ֵ,��һ�����ϵĵ㳬�������ֵ���ж�Ϊֱ��
      //double minLineLength = 0,  // �߶ε���С��ȣ����������С�����������
      //double maxLineGap = 0 );  // �߶�֮�����С���룬�������С��maxLineGap�ͻ���кϲ�

    HoughLinesP(src_canny, line_data, 0.5, CV_PI / 360.0, 25, 1, 20);
    //�ѵõ���ֱ����ʾ��ͼ��
    cv::Scalar color = cv::Scalar(0, 255, 255);
    for (size_t i = 0; i < line_data.size(); i++) {
        cv::Vec4f temp = line_data[i];
        line(cv_dst, cv::Point(temp[0], temp[1]), cv::Point(temp[2], temp[3]), color, 4);

    }
    imshow("houghLinesP img", cv_dst);

    //waitKey(0);
}
