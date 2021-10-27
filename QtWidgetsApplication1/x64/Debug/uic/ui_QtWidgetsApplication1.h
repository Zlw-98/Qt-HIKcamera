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
    QPushButton *element_Button;
    QPushButton *measure_Button;
    QPushButton *assist_Button;
    QWidget *measure_widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *linlindis_Btn;
    QPushButton *ptlindis_Btn;
    QPushButton *ptptdis_Btn;
    QPushButton *circirdis_Btn;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *radius_Btn;
    QPushButton *diameter_Btn;
    QPushButton *angle_Btn;
    QWidget *element_widget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *line_Btn;
    QPushButton *peaklin_Btn;
    QPushButton *ctrlin_Btn;
    QPushButton *circle_Btn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *arc_Btn;
    QPushButton *circtr_Btn;
    QPushButton *intersection_Btn;
    QPushButton *cirlintan_Btn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *circirtan_Btn;
    QPushButton *arcmid_Btn;
    QPushButton *linmid_Btn;
    QWidget *assist_widget;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *chamfer_Btn;
    QWidget *gridLayoutWidget;
    QGridLayout *option_Layout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *photo_layout;
    QLabel *Show_label;
    QWidget *Rect_info_widget;
    QWidget *layoutWidget3;
    QGridLayout *Rect_info;
    QLabel *Rect_x;
    QLineEdit *lineEdit_start_x;
    QLabel *Rect_w;
    QLineEdit *lineEdit_size_w;
    QLabel *Rect_y;
    QLineEdit *lineEdit_start_y;
    QLabel *Rect_h;
    QLineEdit *lineEdit_size_h;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *InitializeWidget;
    QWidget *gridLayoutWidget_3;
    QGridLayout *DeviceInitialize;
    QPushButton *FindDevice_Btn;
    QPushButton *StopGrabbing_Btn;
    QPushButton *StartGrabbing_Btn;
    QPushButton *SoftTrigger_Btn;
    QPushButton *OpenDevice_Btn;
    QPushButton *CloseDevice_Btn;
    QRadioButton *CtnMode_Btn;
    QRadioButton *TriggerMode_Btn;
    QComboBox *m_ctrlDeviceCombo;
    QWidget *parameter_widget;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *GainEdit;
    QLabel *label_2;
    QLineEdit *ExposureEdit;
    QPushButton *SetParameter_Btn;
    QPushButton *GetParameter_Btn;
    QWidget *SaveImageWidget;
    QPushButton *SaveBMP_Btn;
    QPushButton *SaveJPG_Btn;
    QPushButton *SaveTIFF_Btn;
    QPushButton *SavePNG_Btn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName(QString::fromUtf8("QtWidgetsApplication1Class"));
        QtWidgetsApplication1Class->resize(1280, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QtWidgetsApplication1/res/8114/r9.ico"), QSize(), QIcon::Normal, QIcon::Off);
        QtWidgetsApplication1Class->setWindowIcon(icon);
        actionopen = new QAction(QtWidgetsApplication1Class);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        centralWidget = new QWidget(QtWidgetsApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        element_Button = new QPushButton(centralWidget);
        element_Button->setObjectName(QString::fromUtf8("element_Button"));
        element_Button->setGeometry(QRect(700, 430, 121, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(14);
        element_Button->setFont(font);
        measure_Button = new QPushButton(centralWidget);
        measure_Button->setObjectName(QString::fromUtf8("measure_Button"));
        measure_Button->setGeometry(QRect(850, 430, 121, 61));
        measure_Button->setFont(font);
        assist_Button = new QPushButton(centralWidget);
        assist_Button->setObjectName(QString::fromUtf8("assist_Button"));
        assist_Button->setGeometry(QRect(1000, 430, 121, 61));
        assist_Button->setFont(font);
        measure_widget = new QWidget(centralWidget);
        measure_widget->setObjectName(QString::fromUtf8("measure_widget"));
        measure_widget->setGeometry(QRect(970, 20, 551, 331));
        layoutWidget = new QWidget(measure_widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 551, 331));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 80, -1, -1);
        linlindis_Btn = new QPushButton(layoutWidget);
        linlindis_Btn->setObjectName(QString::fromUtf8("linlindis_Btn"));

        horizontalLayout_10->addWidget(linlindis_Btn);

        ptlindis_Btn = new QPushButton(layoutWidget);
        ptlindis_Btn->setObjectName(QString::fromUtf8("ptlindis_Btn"));

        horizontalLayout_10->addWidget(ptlindis_Btn);

        ptptdis_Btn = new QPushButton(layoutWidget);
        ptptdis_Btn->setObjectName(QString::fromUtf8("ptptdis_Btn"));

        horizontalLayout_10->addWidget(ptptdis_Btn);

        circirdis_Btn = new QPushButton(layoutWidget);
        circirdis_Btn->setObjectName(QString::fromUtf8("circirdis_Btn"));

        horizontalLayout_10->addWidget(circirdis_Btn);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, 80, -1, -1);
        radius_Btn = new QPushButton(layoutWidget);
        radius_Btn->setObjectName(QString::fromUtf8("radius_Btn"));

        horizontalLayout_11->addWidget(radius_Btn);

        diameter_Btn = new QPushButton(layoutWidget);
        diameter_Btn->setObjectName(QString::fromUtf8("diameter_Btn"));

        horizontalLayout_11->addWidget(diameter_Btn);

        angle_Btn = new QPushButton(layoutWidget);
        angle_Btn->setObjectName(QString::fromUtf8("angle_Btn"));

        horizontalLayout_11->addWidget(angle_Btn);


        verticalLayout_2->addLayout(horizontalLayout_11);

        element_widget = new QWidget(centralWidget);
        element_widget->setObjectName(QString::fromUtf8("element_widget"));
        element_widget->setEnabled(true);
        element_widget->setGeometry(QRect(-420, 380, 541, 361));
        layoutWidget1 = new QWidget(element_widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 541, 361));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 80, -1, -1);
        line_Btn = new QPushButton(layoutWidget1);
        line_Btn->setObjectName(QString::fromUtf8("line_Btn"));

        horizontalLayout->addWidget(line_Btn);

        peaklin_Btn = new QPushButton(layoutWidget1);
        peaklin_Btn->setObjectName(QString::fromUtf8("peaklin_Btn"));

        horizontalLayout->addWidget(peaklin_Btn);

        ctrlin_Btn = new QPushButton(layoutWidget1);
        ctrlin_Btn->setObjectName(QString::fromUtf8("ctrlin_Btn"));

        horizontalLayout->addWidget(ctrlin_Btn);

        circle_Btn = new QPushButton(layoutWidget1);
        circle_Btn->setObjectName(QString::fromUtf8("circle_Btn"));

        horizontalLayout->addWidget(circle_Btn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 80, -1, -1);
        arc_Btn = new QPushButton(layoutWidget1);
        arc_Btn->setObjectName(QString::fromUtf8("arc_Btn"));

        horizontalLayout_2->addWidget(arc_Btn);

        circtr_Btn = new QPushButton(layoutWidget1);
        circtr_Btn->setObjectName(QString::fromUtf8("circtr_Btn"));

        horizontalLayout_2->addWidget(circtr_Btn);

        intersection_Btn = new QPushButton(layoutWidget1);
        intersection_Btn->setObjectName(QString::fromUtf8("intersection_Btn"));

        horizontalLayout_2->addWidget(intersection_Btn);

        cirlintan_Btn = new QPushButton(layoutWidget1);
        cirlintan_Btn->setObjectName(QString::fromUtf8("cirlintan_Btn"));

        horizontalLayout_2->addWidget(cirlintan_Btn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 80, -1, -1);
        circirtan_Btn = new QPushButton(layoutWidget1);
        circirtan_Btn->setObjectName(QString::fromUtf8("circirtan_Btn"));

        horizontalLayout_3->addWidget(circirtan_Btn);

        arcmid_Btn = new QPushButton(layoutWidget1);
        arcmid_Btn->setObjectName(QString::fromUtf8("arcmid_Btn"));

        horizontalLayout_3->addWidget(arcmid_Btn);

        linmid_Btn = new QPushButton(layoutWidget1);
        linmid_Btn->setObjectName(QString::fromUtf8("linmid_Btn"));

        horizontalLayout_3->addWidget(linmid_Btn);


        verticalLayout->addLayout(horizontalLayout_3);

        assist_widget = new QWidget(centralWidget);
        assist_widget->setObjectName(QString::fromUtf8("assist_widget"));
        assist_widget->setEnabled(true);
        assist_widget->setGeometry(QRect(-460, 10, 539, 419));
        layoutWidget2 = new QWidget(assist_widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 20, 539, 361));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        chamfer_Btn = new QPushButton(layoutWidget2);
        chamfer_Btn->setObjectName(QString::fromUtf8("chamfer_Btn"));

        horizontalLayout_12->addWidget(chamfer_Btn);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(710, 500, 160, 80));
        option_Layout = new QGridLayout(gridLayoutWidget);
        option_Layout->setSpacing(6);
        option_Layout->setContentsMargins(11, 11, 11, 11);
        option_Layout->setObjectName(QString::fromUtf8("option_Layout"));
        option_Layout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(120, -30, 561, 321));
        photo_layout = new QGridLayout(gridLayoutWidget_2);
        photo_layout->setSpacing(6);
        photo_layout->setContentsMargins(11, 11, 11, 11);
        photo_layout->setObjectName(QString::fromUtf8("photo_layout"));
        photo_layout->setContentsMargins(0, 0, 0, 0);
        Show_label = new QLabel(centralWidget);
        Show_label->setObjectName(QString::fromUtf8("Show_label"));
        Show_label->setGeometry(QRect(470, 0, 121, 81));
        Rect_info_widget = new QWidget(centralWidget);
        Rect_info_widget->setObjectName(QString::fromUtf8("Rect_info_widget"));
        Rect_info_widget->setGeometry(QRect(-60, 650, 441, 80));
        layoutWidget3 = new QWidget(Rect_info_widget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(70, 10, 311, 57));
        Rect_info = new QGridLayout(layoutWidget3);
        Rect_info->setSpacing(6);
        Rect_info->setContentsMargins(11, 11, 11, 11);
        Rect_info->setObjectName(QString::fromUtf8("Rect_info"));
        Rect_info->setContentsMargins(0, 0, 0, 0);
        Rect_x = new QLabel(layoutWidget3);
        Rect_x->setObjectName(QString::fromUtf8("Rect_x"));

        Rect_info->addWidget(Rect_x, 0, 0, 1, 1);

        lineEdit_start_x = new QLineEdit(layoutWidget3);
        lineEdit_start_x->setObjectName(QString::fromUtf8("lineEdit_start_x"));

        Rect_info->addWidget(lineEdit_start_x, 0, 1, 1, 1);

        Rect_w = new QLabel(layoutWidget3);
        Rect_w->setObjectName(QString::fromUtf8("Rect_w"));

        Rect_info->addWidget(Rect_w, 0, 2, 1, 1);

        lineEdit_size_w = new QLineEdit(layoutWidget3);
        lineEdit_size_w->setObjectName(QString::fromUtf8("lineEdit_size_w"));

        Rect_info->addWidget(lineEdit_size_w, 0, 3, 1, 1);

        Rect_y = new QLabel(layoutWidget3);
        Rect_y->setObjectName(QString::fromUtf8("Rect_y"));

        Rect_info->addWidget(Rect_y, 1, 0, 1, 1);

        lineEdit_start_y = new QLineEdit(layoutWidget3);
        lineEdit_start_y->setObjectName(QString::fromUtf8("lineEdit_start_y"));

        Rect_info->addWidget(lineEdit_start_y, 1, 1, 1, 1);

        Rect_h = new QLabel(layoutWidget3);
        Rect_h->setObjectName(QString::fromUtf8("Rect_h"));

        Rect_info->addWidget(Rect_h, 1, 2, 1, 1);

        lineEdit_size_h = new QLineEdit(layoutWidget3);
        lineEdit_size_h->setObjectName(QString::fromUtf8("lineEdit_size_h"));

        Rect_info->addWidget(lineEdit_size_h, 1, 3, 1, 1);

        layoutWidget_4 = new QWidget(centralWidget);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(420, 680, 541, 361));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        InitializeWidget = new QWidget(centralWidget);
        InitializeWidget->setObjectName(QString::fromUtf8("InitializeWidget"));
        InitializeWidget->setGeometry(QRect(740, 30, 201, 171));
        gridLayoutWidget_3 = new QWidget(InitializeWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 201, 171));
        DeviceInitialize = new QGridLayout(gridLayoutWidget_3);
        DeviceInitialize->setSpacing(6);
        DeviceInitialize->setContentsMargins(11, 11, 11, 11);
        DeviceInitialize->setObjectName(QString::fromUtf8("DeviceInitialize"));
        DeviceInitialize->setContentsMargins(0, 0, 0, 0);
        FindDevice_Btn = new QPushButton(gridLayoutWidget_3);
        FindDevice_Btn->setObjectName(QString::fromUtf8("FindDevice_Btn"));

        DeviceInitialize->addWidget(FindDevice_Btn, 0, 0, 1, 2);

        StopGrabbing_Btn = new QPushButton(gridLayoutWidget_3);
        StopGrabbing_Btn->setObjectName(QString::fromUtf8("StopGrabbing_Btn"));

        DeviceInitialize->addWidget(StopGrabbing_Btn, 3, 1, 1, 1);

        StartGrabbing_Btn = new QPushButton(gridLayoutWidget_3);
        StartGrabbing_Btn->setObjectName(QString::fromUtf8("StartGrabbing_Btn"));

        DeviceInitialize->addWidget(StartGrabbing_Btn, 3, 0, 1, 1);

        SoftTrigger_Btn = new QPushButton(gridLayoutWidget_3);
        SoftTrigger_Btn->setObjectName(QString::fromUtf8("SoftTrigger_Btn"));

        DeviceInitialize->addWidget(SoftTrigger_Btn, 5, 0, 1, 2);

        OpenDevice_Btn = new QPushButton(gridLayoutWidget_3);
        OpenDevice_Btn->setObjectName(QString::fromUtf8("OpenDevice_Btn"));

        DeviceInitialize->addWidget(OpenDevice_Btn, 1, 0, 1, 1);

        CloseDevice_Btn = new QPushButton(gridLayoutWidget_3);
        CloseDevice_Btn->setObjectName(QString::fromUtf8("CloseDevice_Btn"));

        DeviceInitialize->addWidget(CloseDevice_Btn, 1, 1, 1, 1);

        CtnMode_Btn = new QRadioButton(gridLayoutWidget_3);
        CtnMode_Btn->setObjectName(QString::fromUtf8("CtnMode_Btn"));

        DeviceInitialize->addWidget(CtnMode_Btn, 2, 0, 1, 1);

        TriggerMode_Btn = new QRadioButton(gridLayoutWidget_3);
        TriggerMode_Btn->setObjectName(QString::fromUtf8("TriggerMode_Btn"));

        DeviceInitialize->addWidget(TriggerMode_Btn, 2, 1, 1, 1);

        m_ctrlDeviceCombo = new QComboBox(centralWidget);
        m_ctrlDeviceCombo->setObjectName(QString::fromUtf8("m_ctrlDeviceCombo"));
        m_ctrlDeviceCombo->setGeometry(QRect(530, 360, 511, 22));
        parameter_widget = new QWidget(centralWidget);
        parameter_widget->setObjectName(QString::fromUtf8("parameter_widget"));
        parameter_widget->setGeometry(QRect(740, 210, 201, 121));
        gridLayoutWidget_4 = new QWidget(parameter_widget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(0, 0, 195, 71));
        gridLayout = new QGridLayout(gridLayoutWidget_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        GainEdit = new QLineEdit(gridLayoutWidget_4);
        GainEdit->setObjectName(QString::fromUtf8("GainEdit"));

        gridLayout->addWidget(GainEdit, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        ExposureEdit = new QLineEdit(gridLayoutWidget_4);
        ExposureEdit->setObjectName(QString::fromUtf8("ExposureEdit"));

        gridLayout->addWidget(ExposureEdit, 0, 1, 1, 1);

        SetParameter_Btn = new QPushButton(parameter_widget);
        SetParameter_Btn->setObjectName(QString::fromUtf8("SetParameter_Btn"));
        SetParameter_Btn->setGeometry(QRect(0, 80, 93, 28));
        GetParameter_Btn = new QPushButton(parameter_widget);
        GetParameter_Btn->setObjectName(QString::fromUtf8("GetParameter_Btn"));
        GetParameter_Btn->setGeometry(QRect(100, 80, 93, 28));
        SaveImageWidget = new QWidget(centralWidget);
        SaveImageWidget->setObjectName(QString::fromUtf8("SaveImageWidget"));
        SaveImageWidget->setGeometry(QRect(260, 360, 221, 61));
        SaveBMP_Btn = new QPushButton(SaveImageWidget);
        SaveBMP_Btn->setObjectName(QString::fromUtf8("SaveBMP_Btn"));
        SaveBMP_Btn->setGeometry(QRect(10, 0, 93, 28));
        SaveJPG_Btn = new QPushButton(SaveImageWidget);
        SaveJPG_Btn->setObjectName(QString::fromUtf8("SaveJPG_Btn"));
        SaveJPG_Btn->setGeometry(QRect(110, 0, 93, 28));
        SaveTIFF_Btn = new QPushButton(SaveImageWidget);
        SaveTIFF_Btn->setObjectName(QString::fromUtf8("SaveTIFF_Btn"));
        SaveTIFF_Btn->setGeometry(QRect(10, 30, 93, 28));
        SavePNG_Btn = new QPushButton(SaveImageWidget);
        SavePNG_Btn->setObjectName(QString::fromUtf8("SavePNG_Btn"));
        SavePNG_Btn->setGeometry(QRect(110, 30, 93, 28));
        QtWidgetsApplication1Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtWidgetsApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsApplication1Class->setStatusBar(statusBar);
        menuBar = new QMenuBar(QtWidgetsApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        QtWidgetsApplication1Class->setMenuBar(menuBar);

        retranslateUi(QtWidgetsApplication1Class);
        QObject::connect(element_Button, SIGNAL(clicked()), element_widget, SLOT(show()));
        QObject::connect(element_Button, SIGNAL(clicked()), assist_widget, SLOT(hide()));
        QObject::connect(element_Button, SIGNAL(clicked()), measure_widget, SLOT(hide()));
        QObject::connect(assist_Button, SIGNAL(clicked()), assist_widget, SLOT(show()));
        QObject::connect(assist_Button, SIGNAL(clicked()), element_widget, SLOT(hide()));
        QObject::connect(measure_Button, SIGNAL(clicked()), measure_widget, SLOT(show()));
        QObject::connect(measure_Button, SIGNAL(clicked()), element_widget, SLOT(hide()));
        QObject::connect(measure_Button, SIGNAL(clicked()), assist_widget, SLOT(hide()));
        QObject::connect(assist_Button, SIGNAL(clicked()), measure_widget, SLOT(hide()));

        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QApplication::translate("QtWidgetsApplication1Class", "Machine Vision", nullptr));
        actionopen->setText(QApplication::translate("QtWidgetsApplication1Class", "Open", nullptr));
        element_Button->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\205\203\347\264\240\345\267\245\345\205\267", nullptr));
        measure_Button->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\265\213\351\207\217\345\267\245\345\205\267", nullptr));
        assist_Button->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\276\205\345\212\251\345\267\245\345\205\267", nullptr));
        linlindis_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\272\277-\347\272\277\350\267\235\347\246\273", nullptr));
        ptlindis_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\272\277-\347\202\271\350\267\235\347\246\273", nullptr));
        ptptdis_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\202\271-\347\202\271\350\267\235\347\246\273", nullptr));
        circirdis_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206-\345\234\206\350\267\235\347\246\273", nullptr));
        radius_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\215\212\345\276\204", nullptr));
        diameter_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\233\264\345\276\204", nullptr));
        angle_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\247\222\345\272\246", nullptr));
        line_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\233\264\347\272\277", nullptr));
        peaklin_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\263\260\345\200\274\347\272\277", nullptr));
        ctrlin_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\270\255\345\277\203\347\272\277", nullptr));
        circle_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206", nullptr));
        arc_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206\345\274\247", nullptr));
        circtr_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206\345\277\203", nullptr));
        intersection_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\233\264\347\272\277\344\272\244\347\202\271", nullptr));
        cirlintan_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206-\347\272\277\345\210\207\347\202\271", nullptr));
        circirtan_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206-\345\234\206\345\210\207\347\202\271", nullptr));
        arcmid_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\234\206\345\274\247\344\270\255\345\277\203\347\202\271", nullptr));
        linmid_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\347\272\277\346\256\265\344\270\255\347\202\271", nullptr));
        chamfer_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\200\222\350\247\222", nullptr));
        Show_label->setText(QString());
        Rect_x->setText(QApplication::translate("QtWidgetsApplication1Class", "x", nullptr));
        Rect_w->setText(QApplication::translate("QtWidgetsApplication1Class", "w", nullptr));
        Rect_y->setText(QApplication::translate("QtWidgetsApplication1Class", "y", nullptr));
        Rect_h->setText(QApplication::translate("QtWidgetsApplication1Class", "h", nullptr));
        FindDevice_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\237\245\346\211\276\350\256\276\345\244\207", nullptr));
        StopGrabbing_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\201\234\346\255\242\351\207\207\351\233\206", nullptr));
        StartGrabbing_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        SoftTrigger_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\275\257\350\247\246\345\217\221\344\270\200\346\254\241", nullptr));
        OpenDevice_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
        CloseDevice_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\205\263\351\227\255\350\256\276\345\244\207", nullptr));
        CtnMode_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\277\236\347\273\255\346\250\241\345\274\217", nullptr));
        TriggerMode_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\350\247\246\345\217\221\346\250\241\345\274\217", nullptr));
        label->setText(QApplication::translate("QtWidgetsApplication1Class", "\346\233\235\345\205\211", nullptr));
        label_2->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\242\236\347\233\212", nullptr));
        SetParameter_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        GetParameter_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\345\217\202\346\225\260\350\216\267\345\217\226", nullptr));
        SaveBMP_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230BMP", nullptr));
        SaveJPG_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230JPG", nullptr));
        SaveTIFF_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230tiff", nullptr));
        SavePNG_Btn->setText(QApplication::translate("QtWidgetsApplication1Class", "\344\277\235\345\255\230PNG", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
