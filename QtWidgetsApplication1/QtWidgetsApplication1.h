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

//using namespace cv;
namespace Ui { class QtWidgetsApplication1; }


class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
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
    float scaled_ratio;
    void paintEvent(QPaintEvent*);

/*ch: MVS控件对应变量 | en:Control corresponding variable*/
public:
    int SetTriggerSource();//设置软触发
    cv::Mat srcImage;
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
   void readframe();
   void on_StartCamera_clicked();//Opencv打开电脑摄像头
   void bnclose();//Opencv关闭电脑摄像头
   void on_lineBtn_clicked();//点击直线按钮
   void on_peaklinBtn_clicked();//点击峰值线按钮
   void on_ctrlinBtn_clicked();//点击中心线按钮
   void on_circleBtn_clicked();//点击圆按钮
   void on_arcBtn_clicked();//点击圆弧按钮
   //void on_circtrBtn_clicked();//点击圆心按钮
   //void on_intersectionBtn_clicked();//点击直线交点按钮
   //void on_cirlintanBtn_clicked();//点击圆线切点按钮
   //void on_circirtanBtn_clicked();//点击圆圆切点按钮
   //void on_arcmidBtn_clicked();//点击圆弧中点按钮
   //void on_linmidBtn_clicked();//点击线段中点按钮
   void on_ptptdisBtn_clicked();
   void on_ptlindisBtn_clicked();
   
   



   //绘制矩形
   void StartPointSlot(QPointF p);
   void StopPointSlot(QPointF p);
   //void PointTextChangeSlot(QString);
   //移动矩形
   void StartMoveRectSlot(QRectF);//移动时宽和高不变，故不需要stopslot


};

