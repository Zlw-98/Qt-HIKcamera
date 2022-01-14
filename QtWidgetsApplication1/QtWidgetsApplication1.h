#pragma once

#define _AFXDLL

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include "QString"
#include <QFileDialog>
#include <Qtimer>
#include <QMessageBox>
#include <opencv2/opencv.hpp>  //引入openCV
#include "myLabel.h"
#include "Detect.h"
#include "MvCamera.h"
#include "afxwin.h"
#include "Mmsystem.h"
#pragma comment(lib, "winmm.lib")

//using namespace cv;
namespace Ui { class QtWidgetsApplication1; }


//鼠标点击事件
enum ClickedBtn {
    lineBtn_clicked = 0,     //直线
    peakLinBtn_clicked = 1,  //峰值线
    ctrLinBtn_clicked = 2,   //中心线
    circleBtn_clicked = 3,   //圆
    arcBtn_clicked = 4,      //圆弧
    ptptdisBtn_clicked = 5,  //点-点距离
    ptlindisBtn_clicked = 6, //点-线距离
    arcmidBtn_clicked = 7,   //圆弧中点
    cirlintanBtn_clicked = 8,   //圆-线切点
    intersectionBtn_clicked = 9,//线-线交点
    linmidBtn_clicked = 10,   //线段中点
    circirtanBtn_clicked = 11,//圆圆切点
    circirdisBtn_clicked = 12,//圆圆距离
    linlindisBtn_clicked = 13,//线线距离
    radiusBtn_clicked = 14,   //半径
    diameterBtn_clicked = 15, //直径
    arcAngleBtn_clicked = 16, //圆弧角度
    linlinAngleBtn_clicked = 17,//线线角度
    chamferBtn_clicked = 18,  //倒角
    perpendicularityBtn_clicked = 19,//垂直度
    roundnessBtn_clicked = 20,//圆度
    parallelismBtn_clicked = 21,//平行度
    axialityBtn_clicked = 22,//同轴度
    taperBtn_clicked = 23,//锥度
    customArcBtn_clicked = 24,//自定义圆弧
    SCALED = 25,//缩放

};

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:

    DWORD delayTimeBegin;
    DWORD delayTimeEnd;
    DWORD processTime;

    static bool optEnable;

    Ui::QtWidgetsApplication1Class ui;
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);
    cv::Mat QImageToCvMat(const QImage& inImage, bool inCloneImageData);//QImage转Mat函数
    cv::Mat QPixmapToCvMat(const QPixmap& inPixmap, bool inCloneImageData);//QPixmap转Mat函数
    QImage cvMatToQImage(const cv::Mat& inMat);//Mat转Qimage函数
    QPixmap cvMatToQPixmap(const cv::Mat& inMat);//Mat转QPixmap函数
    void NoPhoto_Dialog();//弹出没有图片的警告弹窗
    void PopDialog(QString str);//弹出警告框
    QPixmap pixmap;
    QPixmap fitpixmap;
    cv::Mat srcImage;
    ClickedBtn clickedBtn;
    float scaled_ratio;
    void paintEvent(QPaintEvent*);
    int GetClicked(int);

/*ch: MVS控件对应变量 | en:Control corresponding variable*/
public:
    int SetTriggerSource();//设置软触发
private:
    BOOL                    m_bSoftWareTriggerCheck;
    CComboBox               m_ctrlDeviceCombo;                // ch:枚举到的设备 | en:Enumerated device
    
    BOOL                    m_bOpenDevice;                        // ch:是否打开设备 | en:Whether to open device
    BOOL                    m_bStartGrabbing;                     // ch:是否开始抓图 | en:Whether to start grabbing
    void*                   m_hGrabThread;              // ch:取流线程句柄 | en:Grab thread handle
    unsigned int            m_nSaveImageBufSize;
    unsigned int            g_nPayloadSize = 0;

    unsigned char*          m_pBufForDriver; // 用于从驱动获取图像的缓存
     
    unsigned char*          m_pSaveImageBuf;// 用于保存图像的缓存

    BOOL                    m_bThreadState;
    int                     m_nTriggerMode;                       // ch:触发模式 | en:Trigger Mode
    int                     m_nTriggerSource;                     // ch:触发源 | en:Trigger Source
    CMvCamera*              m_pcMyCamera;               // ch:CMyCamera封装了常用接口 | en:CMyCamera packed commonly used interface
    int                     m_nDeviceCombo;
    HWND                    m_hwndDisplay;                        // ch:显示句柄 | en:Display Handle
    MV_CC_DEVICE_INFO_LIST  m_stDevList;
    CRITICAL_SECTION        m_hSaveImageMux;
    MV_FRAME_OUT_INFO_EX    m_stImageInfo;

    int CloseDevice();                   // ch:关闭设备 | en:Close Device
    int OpenDevice();
    int GetExposureTime();              // ch:获取曝光
    int GetGain();                      // ch:获取增益
    int SetExposureTime();              // ch:设置曝光时间 | en:Set Exposure Time
    int SetGain();                      // ch:设置增益 | en:Set Gain
    int GetFrameRate();                  // ch:设置帧率 | en:Set Frame Rate
    int SetFrameRate();
    void EnableControls(BOOL bIsCameraReady);
    bool Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char* pData);

private slots:
    void on_FindDeviceBtn_clicked();//点击查找设备按钮
    void on_OpenDeviceBtn_clicked();//点击打开设备按钮
    void on_CloseDeviceBtn_clicked();//点击关闭设备按钮
    void on_StartGrabbingBtn_clicked();//点击开始采集按钮
    void on_StopGrabbingBtn_clicked();//点击停止采集按钮
    void on_SoftTriggerBtn_clicked();//点击软触发一次按钮
    void on_SetParameterBtn_clicked();//点击参数设置按钮
    void on_GetParameterBtn_clicked();//点击参数获取按钮
    void on_CtnModeBtn_clicked();//点击连续模式按钮
    void on_TriggerModeBtn_clicked();//点击触发模式按钮
    void on_SaveBMPBtn_clicked();//点击保存BMP按钮
    void on_SaveJPGBtn_clicked();//点击保存JPG按钮
    void on_SaveTIFFBtn_clicked();//点击保存tiff按钮
    void on_SavePNGBtn_clicked();//点击保存PNG按钮

private:
    QTimer* timer;
    bool reading_frame;
    cv::VideoCapture* capture;
    cv::Mat matFrame;
    QPushButton* StartCamera;
    QPushButton* CloseCamera;
    myLabel* label_img;
    QPointF StartPoint;
    QPointF m_startMovePoint;
    QPointF m_endMovePoint;
    QRectF curRect;




signals:
   void triggered();//信号
   void sendPix(QPixmap);

private slots:
   void trigerMenu(QAction* act);//菜单触发键
   void on_PresetBtn_clicked();//图像重置按钮
   void on_clearBtn_clicked();//清空按钮
   void on_logBtn_clicked();//导出按钮
   void on_loadparaBtn_clicked();//加载参数文件

   void readframe();
   void on_StartCamera_clicked();//Opencv打开电脑摄像头
   void bnclose();//Opencv关闭电脑摄像头
   void on_lineBtn_clicked();//点击直线按钮
   void on_peaklinBtn_clicked();//点击峰值线按钮
   void on_ctrlinBtn_clicked();//点击中心线按钮
   void on_circleBtn_clicked();//点击圆按钮
   void on_arcBtn_clicked();//点击圆弧按钮
   void on_intersectionBtn_clicked();//点击直线交点按钮
   void on_circirtanBtn_clicked();//点击圆圆切点按钮
   void on_arcmidBtn_clicked();//点击圆弧中点按钮
   void on_cirlintanBtn_clicked();//点击圆-线切点按钮
   void on_linmidBtn_clicked();//点击线段中点按钮
   void on_customArcBtn_clicked();//点击自定义圆弧按钮

   void on_ptptdisBtn_clicked();//点击点-点距离按钮
   void on_ptlindisBtn_clicked();//点击点-线距离按钮
   void on_linlindisBtn_clicked();//点击线-线距离按钮
   void on_circirdisBtn_clicked();//点击圆-圆距离按钮
   void on_radiusBtn_clicked();//点击半径按钮
   void on_diameterBtn_clicked();//点击直径按钮
   void on_arcAngleBtn_clicked();//点击圆弧角度按钮
   void on_linlinAngleBtn_clicked();//点击线线角度按钮
   
   void on_chamferBtn_clicked();    //点击倒角按钮
   void on_perpendicularityBtn_clicked();//点击垂直度按钮
   void on_roundnessBtn_clicked();  //点击圆度按钮
   void on_parallelismBtn_clicked();//点击平行度按钮
   void on_axialityBtn_clicked();   //点击同轴度按钮
   void on_taperBtn_clicked();      //点击锥度按钮


private slots:
   //绘制矩形
   void StartPointSlot(QPointF p);
   void StopPointSlot(QPointF p);
   //void PointTextChangeSlot(QString);
   //移动矩形
   void StartMoveRectSlot(QRectF);//移动时宽和高不变，故不需要stopslot
/*
private:
    qreal m_ZoomValue = 1.0;
    int m_XPtInterval = 0;
    int m_YPtInterval = 0;
    QPoint m_OldPos;
    /*
private:
    bool m_Pressed;
    void paint();
    bool eventFilter(QObject* obj, QEvent* event);
    //缩放和平移
    void onZoomInImage(void);
    void onZoomOutImage(void);
    void onPresetImage(void);

    //滚轮事件
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;*/


};

