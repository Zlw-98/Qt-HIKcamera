#include "Detect.h"

Detect::Detect(QWidget* parent) :myLabel(parent)
{
}

///ע�ⲻ��дwaitkey�������޷���qt�����м�ʱ����

//�ø���ͨ�����о���Ա�
color_type Judge_color(cv::Mat img)
{
    color_type color_flag;
    if (!img.data)
        return color_flag = unknown_error;

    if (img.channels() == 3)//3ͨ��
    {
        std::vector<cv::Mat> rgbChannels(3);
        split(img, rgbChannels);
        if (!countNonZero(rgbChannels[0] != rgbChannels[1]) && !countNonZero(rgbChannels[1] != rgbChannels[2]))//3ͨ����ȫ��ͬ
        {
            //��0.255����=����-0����-255����(�����)
            int num = countNonZero(rgbChannels[0]) + countNonZero(~rgbChannels[0]) - rgbChannels[0].rows * rgbChannels[0].cols;
            if (num)//�Ҷ�
            {
                color_flag = channel_3_gray;
            }
            else//�ڰ�
            {
                color_flag = channel_3_binary;
            }
        }
        else//��ͨ������ȫͬ����ɫͼ
        {
            color_flag = channel_3_color;
        }
    }
    else if (img.channels() == 1)//1ͨ��
    {
        int num = countNonZero(img) + countNonZero(~img) - img.rows * img.cols;
        if (num)//�Ҷ�
        {
            color_flag = channel_1_gray;
        }
        else//�ڰ�
        {
            color_flag = channel_1_binary;
        }
    }
    return color_flag;
}

//�Զ���Բ�����
void Detect::CustomArc(cv::Mat cv_dst) {
    cv::Mat srcImage = cv_dst;
    cv::Mat srcGray;
    //cv::imshow("srcImage", srcImage);
    color_type flag = Judge_color(srcImage);
    //�������ͨ������תΪһͨ���Ҷ�ͼ�����򱣳�ԭͼ
    if (flag == channel_3_gray || flag == channel_3_binary || flag == channel_3_color) {
        cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    }
    else {
        srcGray = srcImage;
    }
    //��ֵ��
    threshold(srcGray, srcGray, 150,255, cv::THRESH_BINARY);
    //��˹ƽ���˲�
    //GaussianBlur(srcGray, srcGray, cv::Size(9, 9), 2, 2);
    Canny(srcGray, srcGray, 100, 250, 3, true); //��Ե���
    cv::imshow("Canny", srcGray);
    cv::Mat src = srcGray;
    int w = src.cols;

    vector<cv::Point> points;
    cv::Vec4f lines;
    cv::Vec4f ls;
    
    for (int col = 0; col < src.cols; col++)
    {
        for (int row = 0; row < src.rows; row++)
        {
            uchar* data = src.ptr<uchar>(row);//�õ�ͼ��row�е�ָ��
            if (data[col] == 255)  // ����row��col�е�����
            {
                points.push_back(cv::Point(col, row));
            }
        }
    }
    circleLeastFit(points, center_x, center_y, radius);//��С�������Բ
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
    //����ͼ
    cv::Mat src = cv_dst;
    //cv::Mat src_gray;
    //cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
    //��ֵ����
    cv::Mat threshold_output;
    cv::threshold(src, threshold_output, 150, 255, cv::THRESH_OTSU | cv::THRESH_BINARY_INV);
    imshow("threshold", threshold_output);
    //����ʼ���������ڣ����������յ�λ��
    if (threshold_output.ptr<cv::Vec3b>(StartPoint.y)[StartPoint.x][0] == 255) {
        cv::Point temp;
        temp = StartPoint;
        StartPoint = EndPoint;
        EndPoint = temp;
    }
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
        if (abs(pointPolygonTest(biggestContour, pt, 1)) < 0.0001 && pt != StartPoint && pt != EndPoint) {
            circle(src, pt, 5, cv::Scalar(0, 0, 255), -1);
            break;
        }
    }
    
    imshow("Point",src);
    //waitKey();
}

//��Բ�����һ���֣�����a���ڵ�b,����a�ڵ�b˳ʱ�뷽��,����false,���򷵻�true
bool PointCmp(cv::Point a, cv::Point b, cv::Point center)
{
    if (a.x >= 0 && b.x < 0)
        return false;
    if (a.x == 0 && b.x == 0)
        return a.y < b.y;
    int det = ((a.x - center.x) * (b.y - center.y) - (b.x - center.x) * (a.y - center.y));
    if (det < 0)
        return false;
    if (det > 0)
        return true;
    double d1 = (a.x - center.x) * (a.x - center.x) + (a.y - center.y) * (a.y - center.y);
    double d2 = (b.x - center.x) * (b.x - center.y) + (b.y - center.y) * (b.y - center.y);
    return d1 < d2;
}
//Բ�����һ���֣����㼯��˳ʱ������
void ClockwiseSortPoints(vector<cv::Point>& vPoints)
{
    //��������
    cv::Point center;
    double X = 0, Y = 0;
    for (int i = 0; i < vPoints.size(); i++)
    {
        X += vPoints[i].x;
        Y += vPoints[i].y;
    }
    center.x = (int)X / vPoints.size();
    center.y = (int)Y / vPoints.size();
    //ð������
    for (int i = 0; i < vPoints.size() - 1; i++)
    {
        for (int j = 0; j < vPoints.size() - i - 1; j++)
        {
            if (PointCmp(vPoints[j], vPoints[j + 1], center))
            {
                cv::Point tmp = vPoints[j];
                vPoints[j] = vPoints[j + 1];
                vPoints[j + 1] = tmp;
            }
        }
    }
}
//Բ�����һ���֣���С�������Բ
bool Detect::circleLeastFit(const std::vector<cv::Point>& points, double& center_x, double& center_y, double& radius)
{
    center_x = 0.0f;
    center_y = 0.0f;
    radius = 0.0f;
    if (points.size() < 3)
    {
        return false;
    }

    double sum_x = 0.0f, sum_y = 0.0f;
    double sum_x2 = 0.0f, sum_y2 = 0.0f;
    double sum_x3 = 0.0f, sum_y3 = 0.0f;
    double sum_xy = 0.0f, sum_x1y2 = 0.0f, sum_x2y1 = 0.0f;

    int N = points.size();
    for (int i = 0; i < N; i++)
    {
        double x = points[i].x;
        double y = points[i].y;
        double x2 = x * x;
        double y2 = y * y;
        sum_x += x;
        sum_y += y;
        sum_x2 += x2;
        sum_y2 += y2;
        sum_x3 += x2 * x;
        sum_y3 += y2 * y;
        sum_xy += x * y;
        sum_x1y2 += x * y2;
        sum_x2y1 += x2 * y;
    }

    double C, D, E, G, H;
    double a, b, c;

    C = N * sum_x2 - sum_x * sum_x;
    D = N * sum_xy - sum_x * sum_y;
    E = N * sum_x3 + N * sum_x1y2 - (sum_x2 + sum_y2) * sum_x;
    G = N * sum_y2 - sum_y * sum_y;
    H = N * sum_x2y1 + N * sum_y3 - (sum_x2 + sum_y2) * sum_y;
    a = (H * D - E * G) / (C * G - D * D);
    b = (H * C - E * D) / (D * D - G * C);
    c = -(a * sum_x + b * sum_y + sum_x2 + sum_y2) / N;

    center_x = a / (-2);
    center_y = b / (-2);
    radius = sqrt(a * a + b * b - 4 * c) / 2;
    return true;
}
//����������Ƕ�
double Detect::cal_angle(cv::Point a, cv::Point b, cv::Point c) {
    double x1 = a.x - b.x;
    double y1 = a.y - b.y;
    double x2 = c.x - b.x;
    double y2 = c.y - b.y;
    double cos_b = (x1 * x2 + y1 * y2) / (sqrt(pow(x1, 2) + pow(y1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2)));
    double B = acos(cos_b)*180/CV_PI;
    return B;
}


//����
void Detect::detectChamfer(cv::Mat cv_dst) {
    cv::Mat srcImage = cv_dst;
    //cv::imshow("srcImage", srcImage);
    //cv::Mat srcGray;
    //cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    Canny(srcImage, srcImage, 100, 250, 3, true); //��Ե���
    cv::imshow("Canny", srcImage);
    cv::Mat src = srcImage;
    int w = src.cols;

    vector<cv::Point> points;
    cv::Vec4f chamfer;
    cv::Vec4f ls;

    HoughLinesP(srcImage, line_data, 1.2, CV_PI / 360.0, 10, 10, 40);
    if (line_data.size() > 1) {
        //�ѵõ���ֱ����ʾ��ͼ��
        cv::Scalar color = cv::Scalar(0, 255, 255);
        for (size_t i = 0; i < line_data.size(); i++) {
            cv::Vec4f temp = line_data[i];
            line(srcImage, cv::Point(temp[0], temp[1]), cv::Point(temp[2], temp[3]), color, 4);
        }
       
        if (abs((line_data[0][0] - line_data[0][2]) * (line_data[1][0] - line_data[1][2]) - (line_data[0][1] - line_data[0][3]) * (line_data[1][1] - line_data[1][3])) < 10) {
            chamfer = line_data[2];
        }
        else if (abs((line_data[0][0] - line_data[0][2]) * (line_data[2][0] - line_data[2][2]) - (line_data[0][1] - line_data[0][3]) * (line_data[2][1] - line_data[2][3])) < 10) {
            chamfer = line_data[1];
        }
        else if (abs((line_data[1][0] - line_data[1][2]) * (line_data[2][0] - line_data[2][2]) - (line_data[1][1] - line_data[1][3]) * (line_data[2][1] - line_data[2][3])) < 10) {
            chamfer = line_data[0];
        }
        line(srcImage, cv::Point(chamfer[0], chamfer[1]), cv::Point(chamfer[2], chamfer[3]), cv::Scalar(0, 0, 255), 4);
    }
    chamfer_x0 = chamfer[0]; chamfer_y0 = chamfer[1];
    chamfer_x1 = chamfer[2]; chamfer_y1 = chamfer[3];
    cv::imshow("src", srcImage);
    

}

//Բ�����
void Detect::detectArc(cv::Mat cv_dst)
{
    cv::Mat srcImage = cv_dst;
    //cv::imshow("srcImage", srcImage);
    //cv::Mat srcGray;
    //cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    //��˹ƽ���˲�
    //GaussianBlur(srcGray, srcGray, cv::Size(9, 9), 2, 2);
    //��ֵ��
    threshold(srcImage, srcImage, 150, 255, cv::THRESH_BINARY);
    Canny(srcImage, srcImage, 100, 250, 3, true); //��Ե���
    cv::imshow("Canny", srcImage);
    cv::Mat src = srcImage;
    int w = src.cols;

    vector<cv::Point> points;
    cv::Vec4f lines;
    cv::Vec4f ls;
    /*
    for (int row = 0; row < src.rows; row++)
    {
        uchar* data = src.ptr<uchar>(row);
        for (int col = 0; col < src.cols; col++)
        {
            if (data[col] == 255)
            {
                points.push_back(cv::Point(col, row));
            }
        }
    }*/
    for (int col = 0; col < src.cols; col++)
    {
        for (int row = 0; row < src.rows; row++)
        {
            uchar* data = src.ptr<uchar>(row);//�õ�ͼ��row�е�ָ��
            if (data[col] == 255)  // ����row��col�е�����
            {
                points.push_back(cv::Point(col, row));
            }
        }
    }
    if (points.size()) {
        //ð������ʹ������˳������
        ClockwiseSortPoints(points);

        //����ֱ�߼��
        //HoughLinesP( InputArray image, OutputArray lines,
          //double rho,  // rho �Ĳ���
          //double theta,  // �ǶȵĲ�������λ�Ƕ�
          //int threshold, // ��ֵ,��һ�����ϵĵ㳬�������ֵ���ж�Ϊֱ��
          //double minLineLength = 0,  // �߶ε���С��ȣ����������С�����������
          //double maxLineGap = 0 );  // �߶�֮�����С���룬�������С��maxLineGap�ͻ���кϲ�

        HoughLinesP(srcImage, line_data, 0.5, CV_PI / 360.0, 20, 1, 20);
        if (line_data.size() > 1) {
            //�ѵõ���ֱ����ʾ��ͼ��
            cv::Scalar color = cv::Scalar(0, 255, 255);
            for (size_t i = 0; i < line_data.size(); i++) {
                cv::Vec4f temp = line_data[i];
                line(srcImage, cv::Point(temp[0], temp[1]), cv::Point(temp[2], temp[3]), color, 4);
            }

            int ArcStart, ArcEnd;

            ////Բ������յ�ȷ��
            double d0 = pow((line_data[0][0] - line_data[1][0]), 2) + pow((line_data[0][1] - line_data[1][1]), 2);//һ��һ�������һ�����
            double d1 = pow((line_data[0][0] - line_data[1][2]), 2) + pow((line_data[0][1] - line_data[1][3]), 2);//һ��һ������߶������
            double d2 = pow((line_data[0][2] - line_data[1][0]), 2) + pow((line_data[0][3] - line_data[1][1]), 2);//һ�߶��������һ�����
            double d3 = pow((line_data[0][2] - line_data[1][2]), 2) + pow((line_data[0][3] - line_data[1][3]), 2);//һ�߶�������߶������
            for (int i = 0; i < points.size(); i++) {
                if (d0 < d1 && d0 < d2 && d0 < d3) {
                    if (points[i] == cv::Point(line_data[0][0], line_data[0][1])) {
                        ArcStart = i;
                    }
                    if (points[i] == cv::Point(line_data[1][0], line_data[1][1])) {
                        ArcEnd = i;
                    }
                }
                if (d1 < d0 && d1 < d2 && d1 < d3) {
                    if (points[i] == cv::Point(line_data[0][0], line_data[0][1])) {
                        ArcStart = i;
                    }
                    if (points[i] == cv::Point(line_data[1][2], line_data[1][3])) {
                        ArcEnd = i;
                    }
                }
                if (d2 < d0 && d2 < d1 && d2 < d3) {
                    if (points[i] == cv::Point(line_data[0][2], line_data[0][3])) {
                        ArcStart = i;
                    }
                    if (points[i] == cv::Point(line_data[1][0], line_data[1][1])) {
                        ArcEnd = i;
                    }
                }
                if (d3 < d0 && d3 < d1 && d3 < d2) {
                    if (points[i] == cv::Point(line_data[0][2], line_data[0][3])) {
                        ArcStart = i;
                    }
                    if (points[i] == cv::Point(line_data[1][2], line_data[1][3])) {
                        ArcEnd = i;
                    }
                }
            }
            //��Բ���ĵ����ArcPoints��
            vector<cv::Point> ArcPoints;
            for (int i = ArcStart < ArcEnd ? ArcStart : ArcEnd; i < abs(ArcEnd - ArcStart) + (ArcStart < ArcEnd ? ArcStart : ArcEnd); i++) {
                cv::circle(srcImage, points[i], 1, cv::Scalar(0, 0, 255), 2, 8, 0);
                ArcPoints.push_back(points[i]);
            }
            //Բ���е�
            arcMid_x = points[abs(ArcEnd - ArcStart) / 2 + (ArcStart < ArcEnd ? ArcStart : ArcEnd)].x;
            arcMid_y = points[abs(ArcEnd - ArcStart) / 2 + (ArcStart < ArcEnd ? ArcStart : ArcEnd)].y;
            //Բ-���е�
            arclintan_x0 = points[ArcStart].x;
            arclintan_y0 = points[ArcStart].y;
            arclintan_x1 = points[ArcEnd].x;
            arclintan_y1 = points[ArcEnd].y;
            //Բ��
            cv::Point ArcCenter;
            circleLeastFit(ArcPoints, center_x, center_y, radius);//��С�������Բ
            ArcCenter.x = center_x;
            ArcCenter.y = center_y;
            //Բ���Ƕ�
            arcAngle = cal_angle(points[ArcStart], ArcCenter, points[ArcEnd]);
            //Բ��
            double dis;
            vector<double> distance;
            for (int i = 0; i < ArcPoints.size(); i++) {
                dis = abs(sqrt(pow(ArcPoints[i].x - ArcCenter.x, 2) + pow(ArcPoints[i].y - ArcCenter.y, 2))- radius);
                distance.push_back(dis);
            }
            auto maxPosition = max_element(distance.begin(), distance.end());
            roundness = *maxPosition;

            //cv::circle(srcImage, ArcCenter, radius, cv::Scalar(0, 255, 0), 1, 8, 0);
            cv::imshow("src", srcImage);
        }
    }
}

//Բ��Բ�ȼ��
void Detect::detectRoundness(cv::Mat cv_dst) {
    cv::Mat srcImage = cv_dst;
    //cv::imshow("srcImage", srcImage);
    //cv::Mat srcGray;
    //cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    //��˹ƽ���˲�
    GaussianBlur(srcImage, srcImage, cv::Size(9, 9), 2, 2);
    Canny(srcImage, srcImage, 100, 250, 3, true); //��Ե���
    cv::imshow("Canny", srcImage);
    cv::Mat src = srcImage;
    int w = src.cols;

    vector<cv::Point> points;
    cv::Vec4f lines;
    cv::Vec4f ls;
    for (int col = 0; col < src.cols; col++)
    {
        for (int row = 0; row < src.rows; row++)
        {
            uchar* data = src.ptr<uchar>(row);//�õ�ͼ��row�е�ָ��
            if (data[col] == 255)  // ����row��col�е�����
            {
                points.push_back(cv::Point(col, row));
            }
        }
    }
    if (points.size()) {
        //ð������ʹ������˳������
        ClockwiseSortPoints(points);
        //Բ��
        cv::Point ArcCenter;
        circleLeastFit(points, center_x, center_y, radius);//��С�������Բ
        ArcCenter.x = center_x;
        ArcCenter.y = center_y;
        //Բ��
        double dis;
        vector<double> distance;
        for (int i = 0; i < points.size(); i++) {
            dis = abs(sqrt(pow(points[i].x - ArcCenter.x, 2) + pow(points[i].y - ArcCenter.y, 2)) - radius);
            distance.push_back(dis);
        }
        auto maxPosition = max_element(distance.begin(), distance.end());
        roundness = *maxPosition;

        cv::circle(srcImage, ArcCenter, radius, cv::Scalar(0, 255, 0), 1, 8, 0);
        cv::imshow("src", srcImage);
    }
}

//Բ���
void Detect::detectCircle(cv::Mat cv_dst)
{
    cv::Mat srcImage = cv_dst;
    cv::imshow("srcImage", srcImage);
    //cv::Mat srcGray;
    //cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    //��˹ƽ���˲�
    GaussianBlur(srcImage, srcImage, cv::Size(9, 9), 2, 2);
    //HoughԲ���
    HoughCircles(srcImage, circles, cv::HOUGH_GRADIENT, 1, srcImage.rows / 8, 200, 100, 0, 0);
    /*
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
    //imshow("HoughResult", srcImage);*/
}

//���������
void Detect::detectCtrLin(cv::Mat cv_dst)
{
    //cv::Mat src_gray;
    //cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    cv::Mat src_binary;
    cv::threshold(cv_dst, src_binary, 140, 255, cv::THRESH_OTSU);
    /*
    cv::Mat src_canny;
    Canny(src_gray, src_canny, 100, 200, 3, true); //Canny��Ե���
    cv::imshow("edge img", src_canny);*/
    vector<int> count;
    vector<cv::Point2d> ver_CtrPt, hor_CtrPt;
    cv::Point ctrPt;
    //����ֱ����������
    for (int row = 0; row < src_binary.rows; row++)
    {
        uchar* data = src_binary.ptr<uchar>(row);//�õ�ͼ��row�е�ָ��
        for (int col = 0; col < src_binary.cols; col++)
        {
            if (data[col] == 0)  // ����row��col�е����أ�y��x��
            {
                count.push_back(col);
            }
        }
        if (count.size()) {
            double X = 0;
            for (int k = 0; k < count.size(); k++) {
                X += count[k];
            }
            ctrPt.x = X / count.size();
            ctrPt.y = row;
            ver_CtrPt.push_back(ctrPt);
            count.clear();
        }
    }
    cv::Vec4f ver_CtrLin;
    cv::fitLine(ver_CtrPt, ver_CtrLin, cv::DIST_L2, 0, 0.01, 0.01);
    double ver_cos_theta = ver_CtrLin[0];
    double ver_sin_theta = ver_CtrLin[1];
    double ver_x0 = ver_CtrLin[2], ver_y0 = ver_CtrLin[3];

    double ver_k = ver_cos_theta/ ver_sin_theta;
    double ver_b = ver_x0 - ver_k * ver_y0;
    ver_y = 0;
    ver_x = ver_k * ver_y + ver_b;
    ver_y1 = cv_dst.rows;
    ver_x1 = ver_k * ver_y1 + ver_b;
    cv::line(cv_dst, cv::Point(ver_x1, ver_y1), cv::Point(ver_x, ver_y), cv::Scalar(0,255,0), 2);
    //��ˮƽ����������
    for (int col = 0; col < src_binary.cols; col++)
    {
        for (int row = 0; row < src_binary.rows; row++)
        {
            uchar* data = src_binary.ptr<uchar>(row);//�õ�ͼ��row�е�ָ��
            if (data[col] == 0)  // ����row��col�е����أ�y��x��
            {
                count.push_back(row);
            }
        }
        if (count.size()) {
            double Y = 0;
            for (int k = 0; k < count.size(); k++) {
                Y += count[k];
            }
            ctrPt.y = Y / count.size();
            ctrPt.x = col;
            hor_CtrPt.push_back(ctrPt);
            count.clear();
        }
    }
    cv::Vec4f hor_CtrLin;
    cv::fitLine(hor_CtrPt, hor_CtrLin, cv::DIST_L2, 0, 0.01, 0.01);
    double hor_cos_theta = hor_CtrLin[0];
    double hor_sin_theta = hor_CtrLin[1];
    double hor_x0 = hor_CtrLin[2], hor_y0 = hor_CtrLin[3];

    double hor_k = hor_sin_theta / hor_cos_theta;
    double hor_b = hor_y0 - hor_k * hor_x0;
    hor_x = 0;
    hor_y = hor_k * hor_x + hor_b;
    hor_x1 = cv_dst.cols;
    hor_y1 = hor_k * hor_x1 + hor_b;
    cv::line(cv_dst, cv::Point(hor_x1, hor_y1), cv::Point(hor_x, hor_y), cv::Scalar(0, 255, 0), 2);   
    //for (int i = 0; i < ver_CtrPt.size(); i++) {
    //   cv::circle(cv_dst, ver_CtrPt[i], 1, cv::Scalar(0, 0, 255), 1, 8, 0);
    //}
    cv::imshow("CtrLine", cv_dst);
    
}

//��ֵ�߼��
void  Detect::detectPeakLin(cv::Mat cv_dst)
{
    cv::Mat srcImage = cv_dst;
    //cv::imshow("srcImage", srcImage);
    //cv::Mat srcGray;
    //cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
    //���ýǵ������
    std::vector<cv::Point2f> corners;
    int max_corners = 200;
    double quality_level = 0.08;
    double min_distance = 10.0;
    int block_size = 3;
    bool use_harris = false;
    double k = 0.04;
    
    //�ǵ���
    cv::goodFeaturesToTrack(srcImage,
        corners,
        max_corners,
        quality_level,
        min_distance,
        cv::Mat(),
        block_size,
        use_harris,
        k);
    //ָ�������ؼ��������ע
    cv::TermCriteria criteria = cv::TermCriteria(
        cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS,
        40,
        0.001);
    //�����ؼ�⣬��ԭ���Ľǵ���߾���
    cv::cornerSubPix(srcImage, corners, cv::Size(5, 5), cv::Size(-1, -1), criteria);
    
    //�����е�
    double X = 0;
    for (int i = 0; i < corners.size(); i++)
    {
        X += corners[i].x;
    }
    double center_x = (int)X / corners.size();
    double max_x = corners[0].x, min_x = corners[0].x;
    for (int i = 0; i < corners.size(); i++) {
        max_x = max_x > corners[i].x ? max_x : corners[i].x;
    }
    for (int i = 0; i < corners.size(); i++) {
        min_x = max_x < corners[i].x ? min_x : corners[i].x;
    }
    auto it = corners.begin();
    for (int i = 0; i < corners.size(); ++i) {
        if (abs(corners[i].x - center_x) <= (max_x - min_x) / 3) {
            corners.erase(it);
        }
        else {
            it++;
        }
    }
    //����⵽�Ľǵ���Ƶ�ԭͼ��
    for (int i = 0; i < corners.size(); i++)
    {
        cv::circle(srcImage, corners[i], 1, cv::Scalar(0, 0, 255), 2, 8, 0);
    }
    //�����е㣬��Ϊ����������ֵ��
    std::vector<cv::Point2f> LEFT_corners;
    std::vector<cv::Point2f> RIGHT_corners;
    for (int i = 0; i < corners.size(); i++) {
        if (corners[i].x > center_x + 4) {
            RIGHT_corners.push_back(corners[i]);
        }
        if (corners[i].x < center_x - 4) {
            LEFT_corners.push_back(corners[i]);
        }
    }
    cv::Vec4f LeftPeakLine, RightPeakLine;
    //����ֵ��
    cv::fitLine(LEFT_corners, LeftPeakLine, cv::DIST_L2, 0, 0.01, 0.01);
    double left_cos_theta = LeftPeakLine[0];
    double left_sin_theta = LeftPeakLine[1];
    double left_x0 = LeftPeakLine[2], left_y0 = LeftPeakLine[3];

    double left_k = left_cos_theta / left_sin_theta;
    double left_b = left_x0 - left_k * left_y0;

    leftPeakLine_y0 = 0;
    leftPeakLine_x0 = left_k * leftPeakLine_y0 + left_b;
    leftPeakLine_y1 = srcImage.rows;
    leftPeakLine_x1 = left_k * leftPeakLine_y1 + left_b;
    cv::line(srcImage, cv::Point(leftPeakLine_x1, leftPeakLine_y1), cv::Point(leftPeakLine_x0, leftPeakLine_y0), cv::Scalar(0, 255, 0), 2);
    //�Ҳ��ֵ��
    cv::fitLine(RIGHT_corners, RightPeakLine, cv::DIST_L2, 0, 0.01, 0.01);
    double right_cos_theta = RightPeakLine[0];
    double right_sin_theta = RightPeakLine[1];
    double right_x0 = RightPeakLine[2], right_y0 = RightPeakLine[3];

    double right_k = right_cos_theta / right_sin_theta;
    double right_b = right_x0 - right_k * right_y0;

    rightPeakLine_y0 = 0;
    rightPeakLine_x0 = right_k * rightPeakLine_y0 + right_b;
    rightPeakLine_y1 = srcImage.rows;
    rightPeakLine_x1 = right_k * rightPeakLine_y1 + right_b;
    cv::line(srcImage, cv::Point(rightPeakLine_x1, rightPeakLine_y1), cv::Point(rightPeakLine_x0, rightPeakLine_y0), cv::Scalar(0,255,0), 2);

    cv::imshow("corner", srcImage);


}

//���ֱ���ϵĵ�
void Detect::detectLinePoints(cv::Mat cv_dst) {
    //cv::Mat src_gray;
    //cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    cv::Mat src_canny;
    Canny(cv_dst, src_canny, 100, 250, 3, true); //��Ե���

    for (int col = 0; col < src_canny.cols; col++)
    {
        for (int row = 0; row < src_canny.rows; row++)
        {
            uchar* data = src_canny.ptr<uchar>(row);//�õ�ͼ��row�е�ָ��
            if (data[col] == 255)  // ����row��col�е�����
            {
                LinePoints.push_back(cv::Point(col, row));
            }
        }
    }
    
}

//���ֱ��
void  Detect::detectLine(cv::Mat cv_dst)
{
    //ֱ����Ͽ�����cv::fitLine()����

    //mylabel = new myLabel(this);
    //namedWindow("src", WINDOW_AUTOSIZE);
    //imshow("src", cv_dst);
    //cv::Mat src_gray;
    //cvtColor(cv_dst, src_gray, cv::COLOR_BGR2GRAY);
    cv::Mat src_canny;
    Canny(cv_dst, src_canny, 100, 250,3,true); //��Ե���
    cv::imshow("edge img", src_canny);

    //����ֱ�߼��

    //HoughLinesP( InputArray image, OutputArray lines,
      //double rho,  // rho �Ĳ���
      //double theta,  // �ǶȵĲ�������λ�Ƕ�
      //int threshold, // ��ֵ,��һ�����ϵĵ㳬�������ֵ���ж�Ϊֱ��
      //double minLineLength = 0,  // �߶ε���С��ȣ����������С�����������
      //double maxLineGap = 0 );  // �߶�֮�����С���룬�������С��maxLineGap�ͻ���кϲ�

    HoughLinesP(src_canny, line_data, 1.2, CV_PI / 360.0, 20, 20, 40);
    //�ѵõ���ֱ����ʾ��ͼ��
    cv::Scalar color = cv::Scalar(0, 255, 255);
    for (size_t i = 0; i < line_data.size(); i++) {
        cv::Vec4f temp = line_data[i];
        line(cv_dst, cv::Point(temp[0], temp[1]), cv::Point(temp[2], temp[3]), color, 4);

    }
    imshow("houghLinesP img", cv_dst);
    //waitKey(0);
}
