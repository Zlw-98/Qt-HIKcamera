#pragma once

#define _AFXDLL

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include "QString"
#include <QFileDialog>
#include <Qtimer>
#include <QMessageBox>
#include <opencv2/opencv.hpp>  //����openCV
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
    cv::Mat QImageToCvMat(const QImage& inImage, bool inCloneImageData);//QImageתMat����
    cv::Mat QPixmapToCvMat(const QPixmap& inPixmap, bool inCloneImageData);//QPixmapתMat����
    QImage cvMatToQImage(const cv::Mat& inMat);//MatתQimage����
    QPixmap cvMatToQPixmap(const cv::Mat& inMat);//MatתQPixmap����
    void NoPhoto_Dialog();//����û��ͼƬ�ľ��浯��
    void PopDialog(QString str);//���������
    QPixmap pixmap;
    QPixmap fitpixmap;
    float scaled_ratio;
    void paintEvent(QPaintEvent*);

/*ch: MVS�ؼ���Ӧ���� | en:Control corresponding variable*/
public:
    int SetTriggerSource();//��������
    cv::Mat srcImage;
private:
    BOOL                    m_bSoftWareTriggerCheck;
    CComboBox               m_ctrlDeviceCombo;                // ch:ö�ٵ����豸 | en:Enumerated device
    
    BOOL                    m_bOpenDevice;                        // ch:�Ƿ���豸 | en:Whether to open device
    BOOL                    m_bStartGrabbing;                     // ch:�Ƿ�ʼץͼ | en:Whether to start grabbing
    void*                   m_hGrabThread;              // ch:ȡ���߳̾�� | en:Grab thread handle
    unsigned int            m_nSaveImageBufSize;
    unsigned int            g_nPayloadSize = 0;

    unsigned char*          m_pBufForDriver; // ���ڴ�������ȡͼ��Ļ���
     
    unsigned char*          m_pSaveImageBuf;// ���ڱ���ͼ��Ļ���

    BOOL                    m_bThreadState;
    int                     m_nTriggerMode;                       // ch:����ģʽ | en:Trigger Mode
    int                     m_nTriggerSource;                     // ch:����Դ | en:Trigger Source
    CMvCamera*              m_pcMyCamera;               // ch:CMyCamera��װ�˳��ýӿ� | en:CMyCamera packed commonly used interface
    int                     m_nDeviceCombo;
    HWND                    m_hwndDisplay;                        // ch:��ʾ��� | en:Display Handle
    MV_CC_DEVICE_INFO_LIST  m_stDevList;
    CRITICAL_SECTION        m_hSaveImageMux;
    MV_FRAME_OUT_INFO_EX    m_stImageInfo;

    int CloseDevice();                   // ch:�ر��豸 | en:Close Device
    int OpenDevice();
    int GetExposureTime();              // ch:��ȡ�ع�
    int GetGain();                      // ch:��ȡ����
    int SetExposureTime();              // ch:�����ع�ʱ�� | en:Set Exposure Time
    int SetGain();                      // ch:�������� | en:Set Gain
    void EnableControls(BOOL bIsCameraReady);
    bool Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char* pData);

private slots:
    void on_FindDeviceBtn_clicked();//��������豸��ť
    void on_OpenDeviceBtn_clicked();//������豸��ť
    void on_CloseDeviceBtn_clicked();//����ر��豸��ť
    void on_StartGrabbingBtn_clicked();//�����ʼ�ɼ���ť
    void on_StopGrabbingBtn_clicked();//���ֹͣ�ɼ���ť
    void on_SoftTriggerBtn_clicked();//�������һ�ΰ�ť
    void on_SetParameterBtn_clicked();//����������ð�ť
    void on_GetParameterBtn_clicked();//���������ȡ��ť
    void on_CtnModeBtn_clicked();//�������ģʽ��ť
    void on_TriggerModeBtn_clicked();//�������ģʽ��ť
    void on_SaveBMPBtn_clicked();//�������BMP��ť
    void on_SaveJPGBtn_clicked();//�������JPG��ť
    void on_SaveTIFFBtn_clicked();//�������tiff��ť
    void on_SavePNGBtn_clicked();//�������PNG��ť

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
   void triggered();//�ź�
   void sendPix(QPixmap);

private slots:
   void trigerMenu(QAction* act);//�˵�������
   void readframe();
   void on_StartCamera_clicked();//Opencv�򿪵�������ͷ
   void bnclose();//Opencv�رյ�������ͷ
   void on_lineBtn_clicked();//���ֱ�߰�ť
   void on_peaklinBtn_clicked();//�����ֵ�߰�ť
   void on_ctrlinBtn_clicked();//��������߰�ť
   void on_circleBtn_clicked();//���Բ��ť
   void on_arcBtn_clicked();//���Բ����ť
   //void on_circtrBtn_clicked();//���Բ�İ�ť
   //void on_intersectionBtn_clicked();//���ֱ�߽��㰴ť
   //void on_cirlintanBtn_clicked();//���Բ���е㰴ť
   //void on_circirtanBtn_clicked();//���ԲԲ�е㰴ť
   //void on_arcmidBtn_clicked();//���Բ���е㰴ť
   //void on_linmidBtn_clicked();//����߶��е㰴ť
   void on_ptptdisBtn_clicked();
   void on_ptlindisBtn_clicked();
   
   



   //���ƾ���
   void StartPointSlot(QPointF p);
   void StopPointSlot(QPointF p);
   //void PointTextChangeSlot(QString);
   //�ƶ�����
   void StartMoveRectSlot(QRectF);//�ƶ�ʱ��͸߲��䣬�ʲ���Ҫstopslot


};

