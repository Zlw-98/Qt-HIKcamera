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
#include "Mmsystem.h"
#pragma comment(lib, "winmm.lib")

//using namespace cv;
namespace Ui { class QtWidgetsApplication1; }


//������¼�
enum ClickedBtn {
    lineBtn_clicked = 0,     //ֱ��
    peakLinBtn_clicked = 1,  //��ֵ��
    ctrLinBtn_clicked = 2,   //������
    circleBtn_clicked = 3,   //Բ
    arcBtn_clicked = 4,      //Բ��
    ptptdisBtn_clicked = 5,  //��-�����
    ptlindisBtn_clicked = 6, //��-�߾���
    arcmidBtn_clicked = 7,   //Բ���е�
    cirlintanBtn_clicked = 8,   //Բ-���е�
    intersectionBtn_clicked = 9,//��-�߽���
    linmidBtn_clicked = 10,   //�߶��е�
    circirtanBtn_clicked = 11,//ԲԲ�е�
    circirdisBtn_clicked = 12,//ԲԲ����
    linlindisBtn_clicked = 13,//���߾���
    radiusBtn_clicked = 14,   //�뾶
    diameterBtn_clicked = 15, //ֱ��
    arcAngleBtn_clicked = 16, //Բ���Ƕ�
    linlinAngleBtn_clicked = 17,//���߽Ƕ�
    chamferBtn_clicked = 18,  //����
    perpendicularityBtn_clicked = 19,//��ֱ��
    roundnessBtn_clicked = 20,//Բ��
    parallelismBtn_clicked = 21,//ƽ�ж�
    axialityBtn_clicked = 22,//ͬ���
    taperBtn_clicked = 23,//׶��
    customArcBtn_clicked = 24,//�Զ���Բ��
    SCALED = 25,//����

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
    cv::Mat QImageToCvMat(const QImage& inImage, bool inCloneImageData);//QImageתMat����
    cv::Mat QPixmapToCvMat(const QPixmap& inPixmap, bool inCloneImageData);//QPixmapתMat����
    QImage cvMatToQImage(const cv::Mat& inMat);//MatתQimage����
    QPixmap cvMatToQPixmap(const cv::Mat& inMat);//MatתQPixmap����
    void NoPhoto_Dialog();//����û��ͼƬ�ľ��浯��
    void PopDialog(QString str);//���������
    QPixmap pixmap;
    QPixmap fitpixmap;
    cv::Mat srcImage;
    ClickedBtn clickedBtn;
    float scaled_ratio;
    void paintEvent(QPaintEvent*);
    int GetClicked(int);

/*ch: MVS�ؼ���Ӧ���� | en:Control corresponding variable*/
public:
    int SetTriggerSource();//��������
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
    int GetFrameRate();                  // ch:����֡�� | en:Set Frame Rate
    int SetFrameRate();
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
   void on_PresetBtn_clicked();//ͼ�����ð�ť
   void on_clearBtn_clicked();//��հ�ť
   void on_logBtn_clicked();//������ť
   void on_loadparaBtn_clicked();//���ز����ļ�

   void readframe();
   void on_StartCamera_clicked();//Opencv�򿪵�������ͷ
   void bnclose();//Opencv�رյ�������ͷ
   void on_lineBtn_clicked();//���ֱ�߰�ť
   void on_peaklinBtn_clicked();//�����ֵ�߰�ť
   void on_ctrlinBtn_clicked();//��������߰�ť
   void on_circleBtn_clicked();//���Բ��ť
   void on_arcBtn_clicked();//���Բ����ť
   void on_intersectionBtn_clicked();//���ֱ�߽��㰴ť
   void on_circirtanBtn_clicked();//���ԲԲ�е㰴ť
   void on_arcmidBtn_clicked();//���Բ���е㰴ť
   void on_cirlintanBtn_clicked();//���Բ-���е㰴ť
   void on_linmidBtn_clicked();//����߶��е㰴ť
   void on_customArcBtn_clicked();//����Զ���Բ����ť

   void on_ptptdisBtn_clicked();//�����-����밴ť
   void on_ptlindisBtn_clicked();//�����-�߾��밴ť
   void on_linlindisBtn_clicked();//�����-�߾��밴ť
   void on_circirdisBtn_clicked();//���Բ-Բ���밴ť
   void on_radiusBtn_clicked();//����뾶��ť
   void on_diameterBtn_clicked();//���ֱ����ť
   void on_arcAngleBtn_clicked();//���Բ���ǶȰ�ť
   void on_linlinAngleBtn_clicked();//������߽ǶȰ�ť
   
   void on_chamferBtn_clicked();    //������ǰ�ť
   void on_perpendicularityBtn_clicked();//�����ֱ�Ȱ�ť
   void on_roundnessBtn_clicked();  //���Բ�Ȱ�ť
   void on_parallelismBtn_clicked();//���ƽ�жȰ�ť
   void on_axialityBtn_clicked();   //���ͬ��Ȱ�ť
   void on_taperBtn_clicked();      //���׶�Ȱ�ť


private slots:
   //���ƾ���
   void StartPointSlot(QPointF p);
   void StopPointSlot(QPointF p);
   //void PointTextChangeSlot(QString);
   //�ƶ�����
   void StartMoveRectSlot(QRectF);//�ƶ�ʱ��͸߲��䣬�ʲ���Ҫstopslot
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
    //���ź�ƽ��
    void onZoomInImage(void);
    void onZoomOutImage(void);
    void onPresetImage(void);

    //�����¼�
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;*/


};

