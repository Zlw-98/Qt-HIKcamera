/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION1_H
#define UI_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication1Class
{
public:
    QAction *actionopen;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *photo_layout;
    QLabel *Show_label;
    QWidget *Rect_info_widget;
    QWidget *layoutWidget;
    QGridLayout *Rect_info;
    QLabel *Rect_x;
    QLineEdit *lineEdit_start_x;
    QLabel *Rect_w;
    QLineEdit *lineEdit_size_w;
    QLabel *Rect_y;
    QLineEdit *lineEdit_start_y;
    QLabel *Rect_h;
    QLineEdit *lineEdit_size_h;
    QPushButton *Preset_Btn;
    QPushButton *clear_Btn;
    QPushButton *log_Btn;
    QPushButton *LoadPara_Btn;
    QWidget *measure_widget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *linlindis_Btn;
    QPushButton *ptlindis_Btn;
    QPushButton *ptptdis_Btn;
    QPushButton *circirdis_Btn;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *radius_Btn;
    QPushButton *diameter_Btn;
    QPushButton *arcAngle_Btn;
    QPushButton *linlinAngle_Btn;
    QGridLayout *DeviceInitialize;
    QComboBox *m_ctrlDeviceCombo;
    QPushButton *SetParameter_Btn;
    QPushButton *SavePNG_Btn;
    QPushButton *SaveBMP_Btn;
    QPushButton *GetParameter_Btn;
    QPushButton *CloseDevice_Btn;
    QPushButton *SaveJPG_Btn;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *CtnMode_Btn;
    QPushButton *OpenDevice_Btn;
    QPushButton *StopGrabbing_Btn;
    QGridLayout *gridLayout;
    QPushButton *measure_Button;
    QPushButton *element_Button;
    QPushButton *assist_Button;
    QGridLayout *option_Layout;
    QPushButton *FindDevice_Btn;
    QLabel *label_3;
    QPushButton *StartGrabbing_Btn;
    QRadioButton *TriggerMode_Btn;
    QLineEdit *FrameEdit;
    QLineEdit *GainEdit;
    QLineEdit *ExposureEdit;
    QPushButton *SaveTIFF_Btn;
    QComboBox *TriggerSrc_Btn;
    QPushButton *SoftTrigger_Btn;
    QWidget *element_widget;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *line_Btn;
    QPushButton *peaklin_Btn;
    QPushButton *ctrlin_Btn;
    QPushButton *circle_Btn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *arc_Btn;
    QPushButton *intersection_Btn;
    QPushButton *cirlintan_Btn;
    QPushButton *circirtan_Btn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *arcmid_Btn;
    QPushButton *linmid_Btn;
    QPushButton *customArc_Btn;
    QWidget *assist_widget;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *chamfer_Btn;
    QPushButton *perpendicularity_Btn;
    QPushButton *roundness_Btn;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *parallelism_Btn;
    QPushButton *axiality_Btn;
    QPushButton *taper_Btn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName(QString::fromUtf8("QtWidgetsApplication1Class"));
        QtWidgetsApplication1Class->resize(1750, 900);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QtWidgetsApplication1/res/8114/r9.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QtWidgetsApplication1Class->setWindowIcon(icon);
        actionopen = new QAction(QtWidgetsApplication1Class);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        centralWidget = new QWidget(QtWidgetsApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        photo_layout = new QGridLayout();
        photo_layout->setSpacing(6);
        photo_layout->setObjectName(QString::fromUtf8("photo_layout"));
        Show_label = new QLabel(centralWidget);
        Show_label->setObjectName(QString::fromUtf8("Show_label"));
        Show_label->setEnabled(true);
        Show_label->setMinimumSize(QSize(1024, 750));
        Show_label->setMaximumSize(QSize(1024, 750));

        photo_layout->addWidget(Show_label, 0, 0, 1, 1);


        gridLayout_2->addLayout(photo_layout, 1, 0, 1, 1);

        Rect_info_widget = new QWidget(centralWidget);
        Rect_info_widget->setObjectName(QString::fromUtf8("Rect_info_widget"));
        layoutWidget = new QWidget(Rect_info_widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 311, 57));
        Rect_info = new QGridLayout(layoutWidget);
        Rect_info->setSpacing(6);
        Rect_info->setContentsMargins(11, 11, 11, 11);
        Rect_info->setObjectName(QString::fromUtf8("Rect_info"));
        Rect_info->setContentsMargins(0, 0, 0, 0);
        Rect_x = new QLabel(layoutWidget);
        Rect_x->setObjectName(QString::fromUtf8("Rect_x"));

        Rect_info->addWidget(Rect_x, 0, 0, 1, 1);

        lineEdit_start_x = new QLineEdit(layoutWidget);
        lineEdit_start_x->setObjectName(QString::fromUtf8("lineEdit_start_x"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_start_x->sizePolicy().hasHeightForWidth());
        lineEdit_start_x->setSizePolicy(sizePolicy);

        Rect_info->addWidget(lineEdit_start_x, 0, 1, 1, 1);

        Rect_w = new QLabel(layoutWidget);
        Rect_w->setObjectName(QString::fromUtf8("Rect_w"));

        Rect_info->addWidget(Rect_w, 0, 2, 1, 1);

        lineEdit_size_w = new QLineEdit(layoutWidget);
        lineEdit_size_w->setObjectName(QString::fromUtf8("lineEdit_size_w"));

        Rect_info->addWidget(lineEdit_size_w, 0, 3, 1, 1);

        Rect_y = new QLabel(layoutWidget);
        Rect_y->setObjectName(QString::fromUtf8("Rect_y"));

        Rect_info->addWidget(Rect_y, 1, 0, 1, 1);

        lineEdit_start_y = new QLineEdit(layoutWidget);
        lineEdit_start_y->setObjectName(QString::fromUtf8("lineEdit_start_y"));

        Rect_info->addWidget(lineEdit_start_y, 1, 1, 1, 1);

        Rect_h = new QLabel(layoutWidget);
        Rect_h->setObjectName(QString::fromUtf8("Rect_h"));

        Rect_info->addWidget(Rect_h, 1, 2, 1, 1);

        lineEdit_size_h = new QLineEdit(layoutWidget);
        lineEdit_size_h->setObjectName(QString::fromUtf8("lineEdit_size_h"));

        Rect_info->addWidget(lineEdit_size_h, 1, 3, 1, 1);

        Preset_Btn = new QPushButton(Rect_info_widget);
        Preset_Btn->setObjectName(QString::fromUtf8("Preset_Btn"));
        Preset_Btn->setGeometry(QRect(420, 0, 93, 28));
        clear_Btn = new QPushButton(Rect_info_widget);
        clear_Btn->setObjectName(QString::fromUtf8("clear_Btn"));
        clear_Btn->setGeometry(QRect(520, 0, 93, 28));
        log_Btn = new QPushButton(Rect_info_widget);
        log_Btn->setObjectName(QString::fromUtf8("log_Btn"));
        log_Btn->setGeometry(QRect(620, 0, 93, 28));
        LoadPara_Btn = new QPushButton(Rect_info_widget);
        LoadPara_Btn->setObjectName(QString::fromUtf8("LoadPara_Btn"));
        LoadPara_Btn->setGeometry(QRect(730, 0, 121, 28));

        gridLayout_2->addWidget(Rect_info_widget, 2, 0, 1, 1);

        measure_widget = new QWidget(centralWidget);
        measure_widget->setObjectName(QString::fromUtf8("measure_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(measure_widget->sizePolicy().hasHeightForWidth());
        measure_widget->setSizePolicy(sizePolicy1);
        layoutWidget1 = new QWidget(measure_widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 701, 331));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 80, -1, -1);
        linlindis_Btn = new QPushButton(layoutWidget1);
        linlindis_Btn->setObjectName(QString::fromUtf8("linlindis_Btn"));

        horizontalLayout_10->addWidget(linlindis_Btn);

        ptlindis_Btn = new QPushButton(layoutWidget1);
        ptlindis_Btn->setObjectName(QString::fromUtf8("ptlindis_Btn"));

        horizontalLayout_10->addWidget(ptlindis_Btn);

        ptptdis_Btn = new QPushButton(layoutWidget1);
        ptptdis_Btn->setObjectName(QString::fromUtf8("ptptdis_Btn"));

        horizontalLayout_10->addWidget(ptptdis_Btn);

        circirdis_Btn = new QPushButton(layoutWidget1);
        circirdis_Btn->setObjectName(QString::fromUtf8("circirdis_Btn"));

        horizontalLayout_10->addWidget(circirdis_Btn);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, 80, -1, -1);
        radius_Btn = new QPushButton(layoutWidget1);
        radius_Btn->setObjectName(QString::fromUtf8("radius_Btn"));

        horizontalLayout_11->addWidget(radius_Btn);

        diameter_Btn = new QPushButton(layoutWidget1);
        diameter_Btn->setObjectName(QString::fromUtf8("diameter_Btn"));

        horizontalLayout_11->addWidget(diameter_Btn);

        arcAngle_Btn = new QPushButton(layoutWidget1);
        arcAngle_Btn->setObjectName(QString::fromUtf8("arcAngle_Btn"));

        horizontalLayout_11->addWidget(arcAngle_Btn);

        linlinAngle_Btn = new QPushButton(layoutWidget1);
        linlinAngle_Btn->setObjectName(QString::fromUtf8("linlinAngle_Btn"));

        horizontalLayout_11->addWidget(linlinAngle_Btn);


        verticalLayout_2->addLayout(horizontalLayout_11);


        gridLayout_2->addWidget(measure_widget, 3, 1, 1, 1);

        DeviceInitialize = new QGridLayout();
        DeviceInitialize->setSpacing(6);
        DeviceInitialize->setObjectName(QString::fromUtf8("DeviceInitialize"));
        m_ctrlDeviceCombo = new QComboBox(centralWidget);
        m_ctrlDeviceCombo->setObjectName(QString::fromUtf8("m_ctrlDeviceCombo"));

        DeviceInitialize->addWidget(m_ctrlDeviceCombo, 1, 0, 1, 3);

        SetParameter_Btn = new QPushButton(centralWidget);
        SetParameter_Btn->setObjectName(QString::fromUtf8("SetParameter_Btn"));

        DeviceInitialize->addWidget(SetParameter_Btn, 14, 0, 1, 1);

        SavePNG_Btn = new QPushButton(centralWidget);
        SavePNG_Btn->setObjectName(QString::fromUtf8("SavePNG_Btn"));

        DeviceInitialize->addWidget(SavePNG_Btn, 9, 2, 1, 1);

        SaveBMP_Btn = new QPushButton(centralWidget);
        SaveBMP_Btn->setObjectName(QString::fromUtf8("SaveBMP_Btn"));

        DeviceInitialize->addWidget(SaveBMP_Btn, 8, 0, 1, 1);

        GetParameter_Btn = new QPushButton(centralWidget);
        GetParameter_Btn->setObjectName(QString::fromUtf8("GetParameter_Btn"));

        DeviceInitialize->addWidget(GetParameter_Btn, 14, 2, 1, 1);

        CloseDevice_Btn = new QPushButton(centralWidget);
        CloseDevice_Btn->setObjectName(QString::fromUtf8("CloseDevice_Btn"));

        DeviceInitialize->addWidget(CloseDevice_Btn, 2, 2, 1, 1);

        SaveJPG_Btn = new QPushButton(centralWidget);
        SaveJPG_Btn->setObjectName(QString::fromUtf8("SaveJPG_Btn"));

        DeviceInitialize->addWidget(SaveJPG_Btn, 8, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setContextMenuPolicy(Qt::NoContextMenu);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        DeviceInitialize->addWidget(label, 11, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setAlignment(Qt::AlignCenter);

        DeviceInitialize->addWidget(label_2, 12, 0, 1, 1);

        CtnMode_Btn = new QRadioButton(centralWidget);
        CtnMode_Btn->setObjectName(QString::fromUtf8("CtnMode_Btn"));

        DeviceInitialize->addWidget(CtnMode_Btn, 3, 0, 1, 1);

        OpenDevice_Btn = new QPushButton(centralWidget);
        OpenDevice_Btn->setObjectName(QString::fromUtf8("OpenDevice_Btn"));

        DeviceInitialize->addWidget(OpenDevice_Btn, 2, 0, 1, 1);

        StopGrabbing_Btn = new QPushButton(centralWidget);
        StopGrabbing_Btn->setObjectName(QString::fromUtf8("StopGrabbing_Btn"));

        DeviceInitialize->addWidget(StopGrabbing_Btn, 5, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        measure_Button = new QPushButton(centralWidget);
        measure_Button->setObjectName(QString::fromUtf8("measure_Button"));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(14);
        measure_Button->setFont(font);

        gridLayout->addWidget(measure_Button, 0, 1, 1, 1);

        element_Button = new QPushButton(centralWidget);
        element_Button->setObjectName(QString::fromUtf8("element_Button"));
        element_Button->setFont(font);

        gridLayout->addWidget(element_Button, 0, 0, 1, 1);

        assist_Button = new QPushButton(centralWidget);
        assist_Button->setObjectName(QString::fromUtf8("assist_Button"));
        assist_Button->setFont(font);

        gridLayout->addWidget(assist_Button, 0, 2, 1, 1);

        option_Layout = new QGridLayout();
        option_Layout->setSpacing(6);
        option_Layout->setObjectName(QString::fromUtf8("option_Layout"));

        gridLayout->addLayout(option_Layout, 1, 0, 1, 3);


        DeviceInitialize->addLayout(gridLayout, 15, 0, 1, 3);

        FindDevice_Btn = new QPushButton(centralWidget);
        FindDevice_Btn->setObjectName(QString::fromUtf8("FindDevice_Btn"));

        DeviceInitialize->addWidget(FindDevice_Btn, 0, 0, 1, 3);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);

        DeviceInitialize->addWidget(label_3, 13, 0, 1, 1);

        StartGrabbing_Btn = new QPushButton(centralWidget);
        StartGrabbing_Btn->setObjectName(QString::fromUtf8("StartGrabbing_Btn"));

        DeviceInitialize->addWidget(StartGrabbing_Btn, 5, 0, 1, 1);

        TriggerMode_Btn = new QRadioButton(centralWidget);
        TriggerMode_Btn->setObjectName(QString::fromUtf8("TriggerMode_Btn"));

        DeviceInitialize->addWidget(TriggerMode_Btn, 3, 2, 1, 1);

        FrameEdit = new QLineEdit(centralWidget);
        FrameEdit->setObjectName(QString::fromUtf8("FrameEdit"));

        DeviceInitialize->addWidget(FrameEdit, 13, 2, 1, 1);

        GainEdit = new QLineEdit(centralWidget);
        GainEdit->setObjectName(QString::fromUtf8("GainEdit"));

        DeviceInitialize->addWidget(GainEdit, 12, 2, 1, 1);

        ExposureEdit = new QLineEdit(centralWidget);
        ExposureEdit->setObjectName(QString::fromUtf8("ExposureEdit"));

        DeviceInitialize->addWidget(ExposureEdit, 11, 2, 1, 1);

        SaveTIFF_Btn = new QPushButton(centralWidget);
        SaveTIFF_Btn->setObjectName(QString::fromUtf8("SaveTIFF_Btn"));

        DeviceInitialize->addWidget(SaveTIFF_Btn, 9, 0, 1, 1);

        TriggerSrc_Btn = new QComboBox(centralWidget);
        TriggerSrc_Btn->setObjectName(QString::fromUtf8("TriggerSrc_Btn"));

        DeviceInitialize->addWidget(TriggerSrc_Btn, 4, 0, 1, 3);

        SoftTrigger_Btn = new QPushButton(centralWidget);
        SoftTrigger_Btn->setObjectName(QString::fromUtf8("SoftTrigger_Btn"));

        DeviceInitialize->addWidget(SoftTrigger_Btn, 7, 0, 1, 3);


        gridLayout_2->addLayout(DeviceInitialize, 1, 1, 2, 5);

        element_widget = new QWidget(centralWidget);
        element_widget->setObjectName(QString::fromUtf8("element_widget"));
        element_widget->setEnabled(true);
        sizePolicy1.setHeightForWidth(element_widget->sizePolicy().hasHeightForWidth());
        element_widget->setSizePolicy(sizePolicy1);
        layoutWidget2 = new QWidget(element_widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 691, 361));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 40, -1, -1);
        line_Btn = new QPushButton(layoutWidget2);
        line_Btn->setObjectName(QString::fromUtf8("line_Btn"));

        horizontalLayout->addWidget(line_Btn);

        peaklin_Btn = new QPushButton(layoutWidget2);
        peaklin_Btn->setObjectName(QString::fromUtf8("peaklin_Btn"));

        horizontalLayout->addWidget(peaklin_Btn);

        ctrlin_Btn = new QPushButton(layoutWidget2);
        ctrlin_Btn->setObjectName(QString::fromUtf8("ctrlin_Btn"));

        horizontalLayout->addWidget(ctrlin_Btn);

        circle_Btn = new QPushButton(layoutWidget2);
        circle_Btn->setObjectName(QString::fromUtf8("circle_Btn"));

        horizontalLayout->addWidget(circle_Btn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 40, -1, -1);
        arc_Btn = new QPushButton(layoutWidget2);
        arc_Btn->setObjectName(QString::fromUtf8("arc_Btn"));

        horizontalLayout_2->addWidget(arc_Btn);

        intersection_Btn = new QPushButton(layoutWidget2);
        intersection_Btn->setObjectName(QString::fromUtf8("intersection_Btn"));

        horizontalLayout_2->addWidget(intersection_Btn);

        cirlintan_Btn = new QPushButton(layoutWidget2);
        cirlintan_Btn->setObjectName(QString::fromUtf8("cirlintan_Btn"));

        horizontalLayout_2->addWidget(cirlintan_Btn);

        circirtan_Btn = new QPushButton(layoutWidget2);
        circirtan_Btn->setObjectName(QString::fromUtf8("circirtan_Btn"));

        horizontalLayout_2->addWidget(circirtan_Btn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 40, -1, -1);
        arcmid_Btn = new QPushButton(layoutWidget2);
        arcmid_Btn->setObjectName(QString::fromUtf8("arcmid_Btn"));

        horizontalLayout_3->addWidget(arcmid_Btn);

        linmid_Btn = new QPushButton(layoutWidget2);
        linmid_Btn->setObjectName(QString::fromUtf8("linmid_Btn"));

        horizontalLayout_3->addWidget(linmid_Btn);

        customArc_Btn = new QPushButton(layoutWidget2);
        customArc_Btn->setObjectName(QString::fromUtf8("customArc_Btn"));

        horizontalLayout_3->addWidget(customArc_Btn);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addWidget(element_widget, 3, 5, 1, 1);

        assist_widget = new QWidget(centralWidget);
        assist_widget->setObjectName(QString::fromUtf8("assist_widget"));
        assist_widget->setEnabled(true);
        sizePolicy1.setHeightForWidth(assist_widget->sizePolicy().hasHeightForWidth());
        assist_widget->setSizePolicy(sizePolicy1);
        layoutWidget3 = new QWidget(assist_widget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 20, 691, 181));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        chamfer_Btn = new QPushButton(layoutWidget3);
        chamfer_Btn->setObjectName(QString::fromUtf8("chamfer_Btn"));

        horizontalLayout_12->addWidget(chamfer_Btn);

        perpendicularity_Btn = new QPushButton(layoutWidget3);
        perpendicularity_Btn->setObjectName(QString::fromUtf8("perpendicularity_Btn"));

        horizontalLayout_12->addWidget(perpendicularity_Btn);

        roundness_Btn = new QPushButton(layoutWidget3);
        roundness_Btn->setObjectName(QString::fromUtf8("roundness_Btn"));

        horizontalLayout_12->addWidget(roundness_Btn);

        layoutWidget_2 = new QWidget(assist_widget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 210, 691, 181));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        parallelism_Btn = new QPushButton(layoutWidget_2);
        parallelism_Btn->setObjectName(QString::fromUtf8("parallelism_Btn"));

        horizontalLayout_13->addWidget(parallelism_Btn);

        axiality_Btn = new QPushButton(layoutWidget_2);
        axiality_Btn->setObjectName(QString::fromUtf8("axiality_Btn"));

        horizontalLayout_13->addWidget(axiality_Btn);

        taper_Btn = new QPushButton(layoutWidget_2);
        taper_Btn->setObjectName(QString::fromUtf8("taper_Btn"));

        horizontalLayout_13->addWidget(taper_Btn);


        gridLayout_2->addWidget(assist_widget, 3, 0, 1, 1);

        QtWidgetsApplication1Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtWidgetsApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsApplication1Class->setStatusBar(statusBar);
        menuBar = new QMenuBar(QtWidgetsApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1750, 26));
        QtWidgetsApplication1Class->setMenuBar(menuBar);

        retranslateUi(QtWidgetsApplication1Class);
        QObject::connect(element_Button, SIGNAL(clicked()), assist_widget, SLOT(hide()));
        QObject::connect(assist_Button, SIGNAL(clicked()), element_widget, SLOT(hide()));
        QObject::connect(measure_Button, SIGNAL(clicked()), element_widget, SLOT(hide()));
        QObject::connect(measure_Button, SIGNAL(clicked()), assist_widget, SLOT(hide()));
        QObject::connect(element_Button, SIGNAL(clicked()), measure_widget, SLOT(hide()));
        QObject::connect(assist_Button, SIGNAL(clicked()), measure_widget, SLOT(hide()));
        QObject::connect(element_Button, SIGNAL(clicked()), element_widget, SLOT(show()));
        QObject::connect(assist_Button, SIGNAL(clicked()), assist_widget, SLOT(show()));
        QObject::connect(measure_Button, SIGNAL(clicked()), measure_widget, SLOT(show()));

        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QApplication::translate("QtWidgetsApplication1Class", "Machine Vision", nullptr));
        actionopen->setText(QApplication::translate("QtWidgetsApplication1Class", "Open", nullptr));
        Show_label->setText(QString());
        Rect_x->setText(QApplication::translate("QtWidgetsApplication1Class", "x", nullptr));
        Rect_w->setText(QApplication::translate("QtWidgetsApplication1Class", "w", nullptr));
        Rect_y->setText(QApplication::translate("QtWidgetsApplication1Class", "y", nullptr));
        Rect_h->setText(QApplication::translate("QtWidgetsApplication1Class", "h", nullptr));
        Preset_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\351\207\215\347\275\256\345\233\276\345\203\217", nullptr));
        clear_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\270\205\347\251\272", nullptr));
        log_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\257\274\345\207\272", nullptr));
        LoadPara_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\212\240\350\275\275\346\265\213\351\207\217\345\217\202\346\225\260", nullptr));
        linlindis_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\272\277-\347\272\277\350\267\235\347\246\273", nullptr));
        ptlindis_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\272\277-\347\202\271\350\267\235\347\246\273", nullptr));
        ptptdis_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\202\271-\347\202\271\350\267\235\347\246\273", nullptr));
        circirdis_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206-\345\234\206\350\267\235\347\246\273", nullptr));
        radius_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\215\212\345\276\204", nullptr));
        diameter_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\233\264\345\276\204", nullptr));
        arcAngle_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206\345\274\247\350\247\222\345\272\246", nullptr));
        linlinAngle_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\272\277\347\272\277\350\247\222\345\272\246", nullptr));
        SetParameter_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        SavePNG_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230PNG", nullptr));
        SaveBMP_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230BMP", nullptr));
        GetParameter_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\217\202\346\225\260\350\216\267\345\217\226", nullptr));
        CloseDevice_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\205\263\351\227\255\350\256\276\345\244\207", nullptr));
        SaveJPG_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230JPG", nullptr));
        label->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\233\235\345\205\211", nullptr));
        label_2->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\242\236\347\233\212", nullptr));
        CtnMode_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\277\236\347\273\255\346\250\241\345\274\217", nullptr));
        OpenDevice_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
        StopGrabbing_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        measure_Button->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\265\213\351\207\217\345\267\245\345\205\267", nullptr));
        element_Button->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\205\203\347\264\240\345\267\245\345\205\267", nullptr));
        assist_Button->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\276\205\345\212\251\345\267\245\345\205\267", nullptr));
        FindDevice_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\237\245\346\211\276\350\256\276\345\244\207", nullptr));
        label_3->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\270\247\347\216\207(1~9)", nullptr));
        StartGrabbing_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        TriggerMode_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\247\246\345\217\221\346\250\241\345\274\217", nullptr));
        SaveTIFF_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230tiff", nullptr));
        SoftTrigger_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\275\257\350\247\246\345\217\221\344\270\200\346\254\241", nullptr));
        line_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\233\264\347\272\277", nullptr));
        peaklin_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\263\260\345\200\274\347\272\277", nullptr));
        ctrlin_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\270\255\345\277\203\347\272\277", nullptr));
        circle_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206", nullptr));
        arc_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206\345\274\247", nullptr));
        intersection_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\233\264\347\272\277\344\272\244\347\202\271", nullptr));
        cirlintan_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206-\347\272\277\345\210\207\347\202\271", nullptr));
        circirtan_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206-\345\234\206\345\210\207\347\202\271", nullptr));
        arcmid_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206\345\274\247\344\270\255\347\202\271", nullptr));
        linmid_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\272\277\346\256\265\344\270\255\347\202\271", nullptr));
        customArc_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\207\252\345\256\232\344\271\211\345\234\206\345\274\247", nullptr));
        chamfer_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\200\222\350\247\222", nullptr));
        perpendicularity_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\236\202\347\233\264\345\272\246", nullptr));
        roundness_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206\345\272\246", nullptr));
        parallelism_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\271\263\350\241\214\345\272\246", nullptr));
        axiality_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\220\214\350\275\264\345\272\246", nullptr));
        taper_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\351\224\245\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
