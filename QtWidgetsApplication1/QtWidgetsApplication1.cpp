//#define z QString::fromLocal8Bit    //用于显示中文的宏

#include "QtWidgetsApplication1.h"
#include "ui_QtWidgetsApplication1.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPen>
#include <QPainter>


bool QtWidgetsApplication1::optEnable = false;

//using namespace cv;


QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
	, m_pcMyCamera(NULL)
	, m_nDeviceCombo(0)
	, m_bOpenDevice(FALSE)
	, m_bStartGrabbing(FALSE)
	, m_hGrabThread(NULL)
	, m_bThreadState(FALSE)
	, m_pSaveImageBuf(NULL)
	, m_nTriggerMode(MV_TRIGGER_MODE_OFF)
{

    ui.setupUi(this);                  //Qt自动生成
    setWindowTitle("Machine Vision");  //定义对话框窗口标题
    setFixedSize(this->width(), this->height());

	ui.gridLayoutWidget_2->setGeometry(QRect(10, 10, 640, 470));//设置Show_Label和label_img的范围大小，通过layout所在的widget设置
	
	ui.Rect_info_widget->setGeometry(QRect(-60, 660,470, 80));//设置矩形框信息栏的位置
	label_img = new myLabel(this);

	label_img->setGeometry(0, 0, 0, 0);      //设置初始label_img不显示

    ////MVS相机相关按钮////
	ui.m_ctrlDeviceCombo->setGeometry(QRect(880, 20, 360, 25));//设备列表
	ui.OpenDevice_Btn->setDisabled(TRUE);//将按钮设置为不可点击状态
	ui.CloseDevice_Btn->setDisabled(TRUE);
	ui.StartGrabbing_Btn->setDisabled(TRUE);
	ui.StopGrabbing_Btn->setDisabled(TRUE);
	ui.InitializeWidget->setGeometry(QRect(660, 10, 200, 180));
	ui.parameter_widget->setGeometry(QRect(660, 180, 200,200));
	ui.SaveImageWidget->setGeometry(QRect(880, 60, 220, 100));
	//ui.SaveBMP_Btn->setGeometry(QRect(880, 60, 100, 50));

	connect(ui.FindDevice_Btn, SIGNAL(clicked()), this, SLOT(on_FindDeviceBtn_clicked()));
	connect(ui.OpenDevice_Btn, SIGNAL(clicked()), this, SLOT(on_OpenDeviceBtn_clicked())); 
	connect(ui.CloseDevice_Btn, SIGNAL(clicked()), this, SLOT(on_CloseDeviceBtn_clicked()));
	connect(ui.StartGrabbing_Btn, SIGNAL(clicked()), this, SLOT(on_StartGrabbingBtn_clicked()));
	connect(ui.StopGrabbing_Btn, SIGNAL(clicked()), this, SLOT(on_StopGrabbingBtn_clicked()));
	connect(ui.SoftTrigger_Btn, SIGNAL(clicked()), this, SLOT(on_SoftTriggerBtn_clicked()));
	connect(ui.SetParameter_Btn, SIGNAL(clicked()), this, SLOT(on_SetParameterBtn_clicked()));
	connect(ui.GetParameter_Btn, SIGNAL(clicked()), this, SLOT(on_GetParameterBtn_clicked()));
	connect(ui.CtnMode_Btn, SIGNAL(clicked()), this, SLOT(on_CtnModeBtn_clicked()));
	connect(ui.TriggerMode_Btn, SIGNAL(clicked()), this, SLOT(on_TriggerModeBtn_clicked()));
	connect(ui.SaveBMP_Btn, SIGNAL(clicked()), this, SLOT(on_SaveBMPBtn_clicked()));
	connect(ui.SaveJPG_Btn, SIGNAL(clicked()), this, SLOT(on_SaveJPGBtn_clicked()));
	connect(ui.SaveTIFF_Btn, SIGNAL(clicked()), this, SLOT(on_SaveTIFFBtn_clicked()));
	connect(ui.SavePNG_Btn, SIGNAL(clicked()), this, SLOT(on_SavePNGBtn_clicked()));



    //ui.element_widget->hide();
    ui.assist_widget->hide();
    ui.measure_widget->hide();

    ui.element_Button->setGeometry(700, 320, 120, 60);
    ui.measure_Button->setGeometry(900, 320, 120, 60);
    ui.assist_Button->setGeometry(1100, 320, 120, 60);


    ui.gridLayoutWidget->setGeometry(690, 360, 550, 420);
    //ui.option_Layout->setContentsMargins(20, 30, 60, 20);

    ui.option_Layout->addWidget(ui.element_widget, 0, 0, 1, 1);
    ui.option_Layout->addWidget(ui.measure_widget, 0, 0, 1, 1);
    ui.option_Layout->addWidget(ui.assist_widget, 0, 0, 1, 1);

	ui.Show_label->setGeometry(10, 10, 640, 640);
	ui.Show_label->setStyleSheet("QLabel{border:2px solid rgb(180, 180, 180);}");
	ui.photo_layout->addWidget(ui.Show_label, 0, 0, 1, 1);

	StartCamera = new QPushButton(tr("Start/Stop"), this);
	StartCamera->setGeometry(QRect(400, 700, 100, 50));
	StartCamera->setFont(QFont("Times", 8, QFont::Bold));
	connect(StartCamera, SIGNAL(clicked()), this, SLOT(on_StartCamera_clicked()));
	StartCamera->hide();

	CloseCamera = new QPushButton(tr("Close"), this);
	CloseCamera->setGeometry(QRect(550, 700, 100, 50));
	CloseCamera->setFont(QFont("Times", 8, QFont::Bold));
	connect(CloseCamera, SIGNAL(clicked()), this, SLOT(bnclose()));
	CloseCamera->hide();

    //ui.chamfer_Btn->setGeometry(890, 570, 130, 60);

    //total_Layout->addWidget(widget_1, 0, 0, 1, 1);

    QMenu* file_menu= new QMenu(QString("File"));
    this->menuBar()->addMenu(file_menu);
    file_menu->addAction("Open");
	file_menu->addAction("Camera");
    QAction& addAction(const QString & text);
    connect(menuBar(), SIGNAL(triggered(QAction*)), this, SLOT(trigerMenu(QAction*)));

	//按钮点击事件
	connect(ui.line_Btn, SIGNAL(clicked()), this, SLOT(on_lineBtn_clicked()));
	connect(ui.peaklin_Btn, SIGNAL(clicked()), this, SLOT(on_peaklinBtn_clicked()));
	connect(ui.ctrlin_Btn, SIGNAL(clicked()), this, SLOT(on_ctrlinBtn_clicked()));
	connect(ui.ptptdis_Btn, SIGNAL(clicked()), this, SLOT(on_ptptdisBtn_clicked()));
	connect(ui.ptlindis_Btn, SIGNAL(clicked()), this, SLOT(on_ptlindisBtn_clicked()));
	connect(ui.circle_Btn, SIGNAL(clicked()), this, SLOT(on_circleBtn_clicked()));
	connect(ui.arc_Btn, SIGNAL(clicked()), this, SLOT(on_arcBtn_clicked()));


}

void QtWidgetsApplication1::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawPixmap(10,50,fitpixmap);  //这里的起始点是一个个输入来测试得到的固定值，有待优化
}


//获取移动矩形框时的坐标
void QtWidgetsApplication1::StartMoveRectSlot(QRectF Rect) {

	double point_x = Rect.topLeft().x();
	double point_y = Rect.topLeft().y();

	label_img->getRect(curRect.topLeft(), curRect.bottomRight());

	ui.lineEdit_start_x->setText(QString::number(point_x));
	ui.lineEdit_start_y->setText(QString::number(point_y));

}
//获取开始坐标槽函数
void QtWidgetsApplication1::StartPointSlot(QPointF p) {
	StartPoint = p;
	//qDebug()<<p;
	if (!fitpixmap.isNull())
	{
		double point_x = p.x();
		double point_y = p.y();

		ui.lineEdit_start_x->setText(QString::number(point_x));
		ui.lineEdit_start_y->setText(QString::number(point_y));
	}
	/*
	if (capture != NULL ) {

		double label_size_w = label_img->size().width();
		double label_size_h = label_img->size().height();
		double img_w = capture->get(3);
		double img_h = capture->get(4);
		double point_x = p.x();
		double point_y = p.y();
		//计算比例 得出原图的坐标  (因为图片显示在label上大小变化了)
		int ROI_x = (point_x / label_size_w) * img_w;
		int ROI_y = (point_y / label_size_h) * img_h;

		ui.lineEdit_start_x->setText(QString::number(ROI_x));
		ui.lineEdit_start_y->setText(QString::number(ROI_y));
	}
	*/
	else {
		ui.lineEdit_start_x->setText(QString::number(0));
		ui.lineEdit_start_y->setText(QString::number(0));
	}

}
//获取结束坐标槽函数
void QtWidgetsApplication1::StopPointSlot(QPointF p) {
	if (!fitpixmap.isNull())
	{
		double label_size_w = label_img->size().width();
		double label_size_h = label_img->size().height();
		double point_End_x = p.x();
		double point_End_y = p.y();
		double point_Start_x = StartPoint.x();
		double point_Start_y = StartPoint.y();
		//计算比例得出原图ROI的宽高
		int ROI_w = point_End_x - point_Start_x;
		int ROI_h = point_End_y - point_Start_y;

		ui.lineEdit_size_w->setText(QString::number(ROI_w));
		ui.lineEdit_size_h->setText(QString::number(ROI_h));
	}
	/*
	if (capture != NULL) {
		double label_size_w = label_img->size().width();
		double label_size_h = label_img->size().height();
		double img_w = capture->get(3);
		double img_h = capture->get(4);
		double point_End_x = p.x();
		double point_End_y = p.y();
		double point_Start_x = StartPoint.x();
		double point_Start_y = StartPoint.y();
		//计算比例 得出原图ROI的宽高 (因为图片显示在label上大小变化了)
		int ROI_w = ((point_End_x - point_Start_x) / label_size_w) * img_w;
		int ROI_h = ((point_End_y - point_Start_y) / label_size_h) * img_h;

		ui.lineEdit_size_w->setText(QString::number(ROI_w));
		ui.lineEdit_size_h->setText(QString::number(ROI_h));
	}
	*/
	else {
		ui.lineEdit_size_w->setText(QString::number(0));
		ui.lineEdit_size_h->setText(QString::number(0));
	}

}


//点击点-线距离按钮
void QtWidgetsApplication1::on_ptlindisBtn_clicked()
{
	label_img->clearRect();//清除当前矩形框数据
	label_img->clearPoint();//清除当前交点数据
	if (fitpixmap.isNull() && capture == NULL)
	{
		NoPhoto_Dialog();
	}
	else
	{
		label_img->getMode(1);      //测量模式
		label_img->getClickedBtn(6); //on_ptlindisBtn_clicked = 5
		cv::destroyAllWindows();
		//设置边框颜色
		label_img->setStyleSheet("border:1px solid rgb(0, 0, 0)");
		//设置位置大小和Show_label一样
		//label_img->setGeometry(10, 10, 640, 640);
		//自定义label添加到布局,并在其中添加widget存放label_img
		ui.photo_layout->addWidget(label_img, 0, 0, 1, 1);
		//关联开始坐标的信号
		connect(label_img, SIGNAL(StartPointSignal(QPointF)), this, SLOT(StartPointSlot(QPointF)));

		//关联结束坐标的信号
		connect(label_img, SIGNAL(StopPointSignal(QPointF)), this, SLOT(StopPointSlot(QPointF)));

		//关联开始移动矩形的信号
		connect(label_img, SIGNAL(StartMoveRectSignal(QRectF)), this, SLOT(StartMoveRectSlot(QRectF)));

		//关联结束移动矩形的信号
		connect(label_img, SIGNAL(StopMoveRectSignal(QRectF)), this, SLOT(StopMoveRectSlot(QRectF)));
	}
}

//点击点-点距离按钮
void QtWidgetsApplication1::on_ptptdisBtn_clicked()
{
	label_img->clearRect();//清除当前矩形框数据
	label_img->clearPoint();//清除当前交点数据
	if (fitpixmap.isNull() && capture == NULL)
	{
		NoPhoto_Dialog();
	}
	else
	{
		label_img->getMode(1);      //测量模式
		label_img->getClickedBtn(5); //on_ptptdisBtn_clicked = 5
		cv::destroyAllWindows();
		//设置边框颜色
		label_img->setStyleSheet("border:1px solid rgb(0, 0, 0)");
		//设置位置大小和Show_label一样
		//label_img->setGeometry(10, 10, 640, 640);
		//自定义label添加到布局,并在其中添加widget存放label_img
		ui.photo_layout->addWidget(label_img, 0, 0, 1, 1);
		//关联开始坐标的信号
		connect(label_img, SIGNAL(StartPointSignal(QPointF)), this, SLOT(StartPointSlot(QPointF)));

		//关联结束坐标的信号
		connect(label_img, SIGNAL(StopPointSignal(QPointF)), this, SLOT(StopPointSlot(QPointF)));
	}
}

//点击圆按钮
void QtWidgetsApplication1::on_circleBtn_clicked()
{
	label_img->clearRect();//清除当前矩形框数据
	label_img->clearPoint();//清除当前交点数据
	if (fitpixmap.isNull() && capture == NULL)
	{
		NoPhoto_Dialog();
	}
	else
	{
		label_img->getMode(0);      //元素模式
		label_img->getClickedBtn(3); //on_circleBtn_clicked = 3
		cv::destroyAllWindows();
		//设置边框颜色
		label_img->setStyleSheet("border:1px solid rgb(0, 0, 0)");
		//设置位置大小和Show_label一样
		//label_img->setGeometry(10, 10, 640, 640);
		//自定义label添加到布局,并在其中添加widget存放label_img
		ui.photo_layout->addWidget(label_img, 0, 0, 1, 1);
		//关联开始坐标的信号
		connect(label_img, SIGNAL(StartPointSignal(QPointF)), this, SLOT(StartPointSlot(QPointF)));

		//关联结束坐标的信号
		connect(label_img, SIGNAL(StopPointSignal(QPointF)), this, SLOT(StopPointSlot(QPointF)));

		//关联开始移动矩形的信号
		connect(label_img, SIGNAL(StartMoveRectSignal(QRectF)), this, SLOT(StartMoveRectSlot(QRectF)));

		//关联结束移动矩形的信号
		connect(label_img, SIGNAL(StopMoveRectSignal(QRectF)), this, SLOT(StopMoveRectSlot(QRectF)));
	}
}

//点击圆弧按钮
void QtWidgetsApplication1::on_arcBtn_clicked() {
	label_img->clearRect();//清除当前矩形框数据
	label_img->clearPoint();//清除当前交点数据
	if (fitpixmap.isNull() && capture == NULL)
	{
		NoPhoto_Dialog();
	}
	else
	{
		label_img->getMode(0);      //元素模式
		label_img->getClickedBtn(4); //on_arcBtn_clicked = 4
		cv::destroyAllWindows();
		//设置边框颜色
		label_img->setStyleSheet("border:1px solid rgb(0, 0, 0)");
		//设置位置大小和Show_label一样
		//label_img->setGeometry(10, 10, 640, 640);
		//自定义label添加到布局,并在其中添加widget存放label_img
		ui.photo_layout->addWidget(label_img, 0, 0, 1, 1);
		//关联开始坐标的信号
		connect(label_img, SIGNAL(StartPointSignal(QPointF)), this, SLOT(StartPointSlot(QPointF)));

		//关联结束坐标的信号
		connect(label_img, SIGNAL(StopPointSignal(QPointF)), this, SLOT(StopPointSlot(QPointF)));

		//关联开始移动矩形的信号
		connect(label_img, SIGNAL(StartMoveRectSignal(QRectF)), this, SLOT(StartMoveRectSlot(QRectF)));

		//关联结束移动矩形的信号
		connect(label_img, SIGNAL(StopMoveRectSignal(QRectF)), this, SLOT(StopMoveRectSlot(QRectF)));
	}
}

//点击中心线按钮
void QtWidgetsApplication1::on_ctrlinBtn_clicked()
{
	label_img->clearRect();//清除当前矩形框数据
	label_img->clearPoint();//清除当前交点数据
	if (fitpixmap.isNull() && capture == NULL)
	{
		NoPhoto_Dialog();
	}
	else
	{
		label_img->getMode(0);      //元素模式
		label_img->getClickedBtn(2); //on_ctrlinBtn_clicked = 2
		cv::destroyAllWindows();
		//设置边框颜色
		label_img->setStyleSheet("border:1px solid rgb(0, 0, 0)");
		//设置位置大小和Show_label一样
		//label_img->setGeometry(10, 10, 640, 640);
		//自定义label添加到布局,并在其中添加widget存放label_img
		ui.photo_layout->addWidget(label_img, 0, 0, 1, 1);
		//关联开始坐标的信号
		connect(label_img, SIGNAL(StartPointSignal(QPointF)), this, SLOT(StartPointSlot(QPointF)));

		//关联结束坐标的信号
		connect(label_img, SIGNAL(StopPointSignal(QPointF)), this, SLOT(StopPointSlot(QPointF)));

		//关联开始移动矩形的信号
		connect(label_img, SIGNAL(StartMoveRectSignal(QRectF)), this, SLOT(StartMoveRectSlot(QRectF)));

		//关联结束移动矩形的信号
		connect(label_img, SIGNAL(StopMoveRectSignal(QRectF)), this, SLOT(StopMoveRectSlot(QRectF)));
	}
}

//点击 峰值线 按钮
void QtWidgetsApplication1::on_peaklinBtn_clicked() {
	label_img->clearRect();//清除当前矩形框数据
	label_img->clearPoint();//清除当前交点数据
	if (fitpixmap.isNull() && capture == NULL)
	{
		NoPhoto_Dialog();
	}
	else
	{
		label_img->getMode(0);      //元素模式
		label_img->getClickedBtn(1);  //on_peakLinBtn_clicked = 1
		cv::destroyAllWindows();
		//设置边框颜色
		label_img->setStyleSheet("border:1px solid rgb(0, 0, 0)");
		//设置位置大小和Show_label一样
		//label_img->setGeometry(10, 10, 640, 640);
		//自定义label添加到布局,并在其中添加widget存放label_img
		ui.photo_layout->addWidget(label_img, 0, 0, 1, 1);
		//关联开始坐标的信号
		connect(label_img, SIGNAL(StartPointSignal(QPointF)), this, SLOT(StartPointSlot(QPointF)));

		//关联结束坐标的信号
		connect(label_img, SIGNAL(StopPointSignal(QPointF)), this, SLOT(StopPointSlot(QPointF)));

		//关联开始移动矩形的信号
		connect(label_img, SIGNAL(StartMoveRectSignal(QRectF)), this, SLOT(StartMoveRectSlot(QRectF)));

		//关联结束移动矩形的信号
		connect(label_img, SIGNAL(StopMoveRectSignal(QRectF)), this, SLOT(StopMoveRectSlot(QRectF)));
	}
}

//点击 直线 按钮
void QtWidgetsApplication1::on_lineBtn_clicked()
{
	label_img->clearRect();//清除当前矩形框数据
	label_img->clearPoint();//清除当前交点数据
	if (fitpixmap.isNull() && capture == NULL)
	{
		NoPhoto_Dialog();
	}
	else
	{
		label_img->getMode(0);      //元素模式
		label_img->getClickedBtn(0);
		cv::destroyAllWindows();
		//设置边框颜色
		label_img->setStyleSheet("border:1px solid rgb(0, 0, 0)"); 
		//设置位置大小和Show_label一样
		//label_img->setGeometry(10, 10, 640, 640);
		//自定义label添加到布局,并在其中添加widget存放label_img
		ui.photo_layout->addWidget(label_img, 0, 0, 1, 1);
		//关联开始坐标的信号
		connect(label_img, SIGNAL(StartPointSignal(QPointF)),this, SLOT(StartPointSlot(QPointF)));

		//关联结束坐标的信号
		connect(label_img, SIGNAL(StopPointSignal(QPointF)),this, SLOT(StopPointSlot(QPointF)));

		//关联开始移动矩形的信号
		connect(label_img, SIGNAL(StartMoveRectSignal(QRectF)), this, SLOT(StartMoveRectSlot(QRectF)));

		//关联结束移动矩形的信号
		connect(label_img, SIGNAL(StopMoveRectSignal(QRectF)), this, SLOT(StopMoveRectSlot(QRectF)));
	}	
}

//弹出警告框
void QtWidgetsApplication1::PopDialog(QString str) {
	QMessageBox dlg(this);//弹出消息框
	dlg.question(this, "Warning", str);
}

//菜单
void QtWidgetsApplication1::trigerMenu(QAction* act)
{
	if (act->text() == ("Open"))//如果点击了File子菜单项
	{
		QString fileName = QFileDialog::getOpenFileName(this,
			tr("choose file directory"),
			"C:",
			tr("file(*png *jpg *bmp *tiff)"));
		cv::Mat img = cv::imread(fileName.toLocal8Bit().toStdString());//加载图像（路径可包含中文字符）


		pixmap = QPixmap::fromImage(cvMatToQImage(img));

		int width = ui.Show_label->width();
		int height = ui.Show_label->height();
		//QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
		fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
		int cur_width = fitpixmap.size().width();
		int origin_width = pixmap.size().width();
		scaled_ratio = origin_width/ cur_width;

		label_img->getPix(fitpixmap);

		//ui.Show_label->setPixmap(fitpixmap);
		update();

	}
	else if (act->text() == ("Camera"))//如果点击了Camera子菜单项
	{

		timer = new QTimer(this);
		timer->start(30);
		connect(timer, SIGNAL(timeout()), this, SLOT(readframe()));  // 时间到，读取当前摄像头信息
		reading_frame = true;

		StartCamera->show();
		CloseCamera->show();
		
		//打开摄像头，从摄像头中获取视频
		capture = new cv::VideoCapture(0);
	}
}

//弹出没有加载图片
void QtWidgetsApplication1::NoPhoto_Dialog()
{
	QMessageBox dlg(this);//弹出消息框
	dlg.question(this, "Warning", "No photo!");

}

//打开摄像头
void QtWidgetsApplication1::on_StartCamera_clicked()
{
	// 开始计时，超时则发出timeout()信号
	if (reading_frame)timer->stop();
	else timer->start(33);
	reading_frame = !reading_frame;
}

//读取Frame图像 when timeout()
void QtWidgetsApplication1::readframe()
{
	capture->read(matFrame);

	ui.Show_label->setPixmap(QPixmap::fromImage(cvMatToQImage(matFrame)));//将图片显示到label
	//ui.cameraView->setPixmap(QPixmap::fromImage(imag));

}

//close camera
void QtWidgetsApplication1::bnclose()
{
	timer->stop();         // 停止读取数据。
	capture->release();
	ui.Show_label->clear();
	//exit
	//QApplication* app;
	//app->exit(0);
	StartCamera->hide();
	CloseCamera->hide();
}

//将QPixmap转化为Mat
cv::Mat QtWidgetsApplication1::QPixmapToCvMat(const QPixmap& inPixmap, bool inCloneImageData)
{
	return QImageToCvMat(inPixmap.toImage(), inCloneImageData);
}

//将QImage转化为Mat
cv::Mat QtWidgetsApplication1::QImageToCvMat(const QImage& inImage, bool inCloneImageData)
{
	switch (inImage.format())
	{
		// 8-bit, 4 channel
	case QImage::Format_ARGB32:
	case QImage::Format_ARGB32_Premultiplied:
	{
		cv::Mat  mat(inImage.height(), inImage.width(),
			CV_8UC4,
			const_cast<uchar*>(inImage.bits()),
			static_cast<size_t>(inImage.bytesPerLine())
		);

		return (inCloneImageData ? mat.clone() : mat);
	}

	// 8-bit, 3 channel
	case QImage::Format_RGB32:
	case QImage::Format_RGB888:
	{
		if (!inCloneImageData)
		{
			qWarning() << "CVS::QImageToCvMat() - Conversion requires cloning because we use a temporary QImage";
		}

		QImage   swapped = inImage;

		if (inImage.format() == QImage::Format_RGB32)
		{
			swapped = swapped.convertToFormat(QImage::Format_RGB888);
		}

		swapped = swapped.rgbSwapped();

		return cv::Mat(swapped.height(), swapped.width(),
			CV_8UC3,
			const_cast<uchar*>(swapped.bits()),
			static_cast<size_t>(swapped.bytesPerLine())
		).clone();
	}

	// 8-bit, 1 channel
	case QImage::Format_Indexed8:
	{
		cv::Mat  mat(inImage.height(), inImage.width(),
			CV_8UC1,
			const_cast<uchar*>(inImage.bits()),
			static_cast<size_t>(inImage.bytesPerLine())
		);

		return (inCloneImageData ? mat.clone() : mat);
	}

	default:
		qWarning() << "CVS::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
		break;
	}

	return cv::Mat();
}

//将Mat转化为QPixmap
QPixmap QtWidgetsApplication1::cvMatToQPixmap(const cv::Mat& inMat)
{
	return QPixmap::fromImage(cvMatToQImage(inMat));
}

//将Mat转化为QImage
QImage QtWidgetsApplication1::cvMatToQImage(const cv::Mat& inMat)
{
	switch (inMat.type())
	{
	case CV_8UC4:		// 8-bit, 4 channel
	{
		QImage image(inMat.data,
			inMat.cols, inMat.rows,
			static_cast<int>(inMat.step),
			QImage::Format_ARGB32);

		return image;
	}

	case CV_8UC3:		// 8-bit, 3 channel
	{
		QImage image(inMat.data,
			inMat.cols, inMat.rows,
			static_cast<int>(inMat.step),
			QImage::Format_RGB888);

		return image.rgbSwapped();
	}


	case CV_8UC1:// 8-bit, 1 channel
	{
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
		QImage image(inMat.data,
			inMat.cols, inMat.rows,
			static_cast<int>(inMat.step),
			QImage::Format_Grayscale8); //Format_Alpha8 and Format_Grayscale8 were added in Qt 5.5
#else
		static QVector<QRgb>  sColorTable;

		// only create our color table the first time
		if (sColorTable.isEmpty())
		{
			sColorTable.resize(256);

			for (int i = 0; i < 256; ++i)
			{
				sColorTable[i] = qRgb(i, i, i);
			}
		}

		QImage image(inMat.data,
			inMat.cols, inMat.rows,
			static_cast<int>(inMat.step),
			QImage::Format_Indexed8);

		image.setColorTable(sColorTable);
#endif
		return image;
	}

	default:
		//			qWarning() << "CVS::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
		break;
	}

	return QImage();
}


////////////MVS Demo//////////////
//查找设备
void QtWidgetsApplication1::on_FindDeviceBtn_clicked() {
	QString strMsg;
	ui.m_ctrlDeviceCombo->clear();
	//m_ctrlDeviceCombo.ResetContent();
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));

	// ch:枚举子网内所有设备 | en:Enumerate all devices within subnet
	int nRet = CMvCamera::EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_stDevList);
	if (MV_OK != nRet)
	{
		return;
	}

	// ch:将值加入到信息列表框中并显示出来 | en:Add value to the information list box and display
	for (unsigned int i = 0; i < m_stDevList.nDeviceNum; i++)
	{
		MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
		if (NULL == pDeviceInfo)
		{
			continue;
		}

		wchar_t* pUserName = NULL;
		if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
		{
			int nIp1 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
			int nIp2 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
			int nIp3 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
			int nIp4 = (m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

			if (strcmp("", (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName)) != 0)
			{
				DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName), -1, NULL, 0);
				pUserName = new wchar_t[dwLenUserName];
				MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName), -1, pUserName, dwLenUserName);
			}
			else
			{
				char strUserName[256] = { 0 };
				sprintf_s(strUserName, 256, "%s %s (%s)", pDeviceInfo->SpecialInfo.stGigEInfo.chManufacturerName,
					pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
					pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);
				DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, NULL, 0);
				pUserName = new wchar_t[dwLenUserName];
				MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, pUserName, dwLenUserName);
			}
			strMsg.sprintf(("[%d]GigE:    %s  (%d.%d.%d.%d)"), i, pUserName, nIp1, nIp2, nIp3, nIp4);
		}
		else if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
		{
			if (strcmp("", (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName) != 0)
			{
				DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName), -1, NULL, 0);
				pUserName = new wchar_t[dwLenUserName];
				MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName), -1, pUserName, dwLenUserName);
			}
			else
			{
				char strUserName[256] = { 0 };
				sprintf_s(strUserName, 256, "%s %s (%s)", pDeviceInfo->SpecialInfo.stUsb3VInfo.chManufacturerName,
					pDeviceInfo->SpecialInfo.stUsb3VInfo.chModelName,
					pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber);
				DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, NULL, 0);
				pUserName = new wchar_t[dwLenUserName];
				MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, pUserName, dwLenUserName);
			}
			strMsg.sprintf(("[%d]UsbV3:  %s"), i, pUserName);
		}
		else
		{
			PopDialog("Unknown device enumerated");
			//ShowErrorMsg(TEXT("Unknown device enumerated"), 0);
		}
		ui.m_ctrlDeviceCombo->addItem(strMsg);
		//m_ctrlDeviceCombo.AddString(reinterpret_cast<LPCWSTR>(strMsg.data()));

		if (pUserName)
		{
			delete[] pUserName;
			pUserName = NULL;
		}
	}

	if (0 == m_stDevList.nDeviceNum)
	{
		PopDialog("No device");
		//ShowErrorMsg(TEXT("No device"), 0);
		return;
	}
	//m_ctrlDeviceCombo.SetCurSel(0);

	EnableControls(TRUE);
}

// ch:打开设备 | en:Open Device
int QtWidgetsApplication1::OpenDevice() {
	
	int nIndex = m_nDeviceCombo;
	m_pcMyCamera = new CMvCamera;    //创建m_pcMyCamera对象
	if (NULL == m_pcMyCamera)
	{
		return -1;
	}

	int nRet = m_pcMyCamera->Open(m_stDevList.pDeviceInfo[nIndex]);
	if (MV_OK != nRet)
	{
		delete m_pcMyCamera;
		m_pcMyCamera = NULL;
		PopDialog("Open Fail");
		//ShowErrorMsg(TEXT("Open Fail"), nRet);
		return -1;
	}


	m_bOpenDevice = TRUE;
	EnableControls(TRUE);
	on_GetParameterBtn_clicked(); // ch:获取参数 | en:Get Parameter
	return MV_OK;
}

//ch:按下打开设备按钮：打开设备 | en:Click Open button: Open Device
void QtWidgetsApplication1::on_OpenDeviceBtn_clicked() {
	OpenDevice();
	EnableControls(TRUE);
	
	
}

// ch:按下关闭设备按钮：关闭设备 | en:Click Close button: Close Device
void QtWidgetsApplication1::on_CloseDeviceBtn_clicked()
{
	CloseDevice();
	EnableControls(TRUE);
}

// ch:关闭设备 | en:Close Device
int QtWidgetsApplication1::CloseDevice()
{
	m_bThreadState = FALSE;
	if (m_hGrabThread)
	{
		WaitForSingleObject(m_hGrabThread, INFINITE);
		CloseHandle(m_hGrabThread);
		m_hGrabThread = NULL;
	}

	if (m_pcMyCamera)
	{
		m_pcMyCamera->Close();
		delete m_pcMyCamera;
		m_pcMyCamera = NULL;
	}

	m_bStartGrabbing = FALSE;
	m_bOpenDevice = FALSE;

	if (m_pSaveImageBuf)
	{
		free(m_pSaveImageBuf);
		m_pSaveImageBuf = NULL;
	}
	m_nSaveImageBufSize = 0;

	return MV_OK;


}



int RGB2BGR(unsigned char* pRgbData, unsigned int nWidth, unsigned int nHeight)
{
	if (NULL == pRgbData)
	{
		return MV_E_PARAMETER;
	}

	for (unsigned int j = 0; j < nHeight; j++)
	{
		for (unsigned int i = 0; i < nWidth; i++)
		{
			unsigned char red = pRgbData[j * (nWidth * 3) + i * 3];
			pRgbData[j * (nWidth * 3) + i * 3] = pRgbData[j * (nWidth * 3) + i * 3 + 2];
			pRgbData[j * (nWidth * 3) + i * 3 + 2] = red;
		}
	}

	return MV_OK;
}

// convert data stream in Mat format
bool QtWidgetsApplication1::Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char* pData)
{

	if (pstImageInfo->enPixelType == PixelType_Gvsp_Mono8)
	{
		srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC1, pData);
		//cv::imshow("srcimg", srcImage);
	}
	else if (pstImageInfo->enPixelType == PixelType_Gvsp_RGB8_Packed)
	{
		RGB2BGR(pData, pstImageInfo->nWidth, pstImageInfo->nHeight);
		srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC3, pData);
		//cv::imshow("srcimg", srcImage);
	}
	else
	{
		printf("unsupported pixel format\n");
		return false;
	}

	if (NULL == srcImage.data)
	{
		return false;
	}
	

	pixmap = QPixmap::fromImage(cvMatToQImage(srcImage));
	int width = ui.Show_label->width();
	int height = ui.Show_label->height();
	//QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
	fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
	int cur_width = fitpixmap.size().width();
	int origin_width = pixmap.size().width();
	scaled_ratio = origin_width / cur_width;

	label_img->getPix(fitpixmap);

	//ui.Show_label->setPixmap(fitpixmap);
	update();
	//save converted image in a local file
	try {
#if defined (VC9_COMPILE)
		cvSaveImage("MatImage.bmp", &(IplImage(srcImage)));
#else
		cv::imwrite("MatImage.bmp", srcImage);
#endif
	}
	catch (cv::Exception& ex) {
		fprintf(stderr, "Exception saving image to bmp format: %s\n", ex.what());
	}
	srcImage.release();

	return true;
}

// ch:按下开始采集按钮 | en:Click Start button
void QtWidgetsApplication1::on_StartGrabbingBtn_clicked()
{
	/*
	if (FALSE == m_bOpenDevice || TRUE == m_bStartGrabbing || NULL == m_pcMyCamera)
	{
		return;
	}*/

	m_bThreadState = TRUE;
	int nIndex = m_nDeviceCombo;
	int nRet = MV_OK;
	
	// Set trigger mode as off
	//int nRet = MV_CC_SetEnumValue(m_hGrabThread, "TriggerMode", 0);
	nRet = m_pcMyCamera->SetEnumValue("TriggerMode", 0);
	if (MV_OK != nRet)
	{
		printf("Set Trigger Mode fail! nRet [0x%x]\n", nRet);
		return;
	}
	
	
		// Get payload size
		MVCC_INTVALUE_EX stParam;
		memset(&stParam, 0, sizeof(MVCC_INTVALUE));
		//nRet = MV_CC_GetIntValue(m_hGrabThread, "PayloadSize", &stParam);
		nRet = m_pcMyCamera->GetIntValue("PayloadSize", &stParam);
		if (MV_OK != nRet)
		{
			printf("Get PayloadSize fail! nRet [0x%x]\n", nRet);
			return;
		}
		g_nPayloadSize = stParam.nCurValue;
		// Start grab image
		//nRet = MV_CC_StartGrabbing(m_hGrabThread);
		nRet = m_pcMyCamera->StartGrabbing();
		if (MV_OK != nRet)
		{
			printf("Start Grabbing fail! nRet [0x%x]\n", nRet);
			return;
		}

		MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
		memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
		unsigned char* pData = (unsigned char*)malloc(sizeof(unsigned char) * (g_nPayloadSize));
		if (pData == NULL)
		{
			printf("Allocate memory failed.\n");
			return;
		}

		// get one frame from camera with timeout=1000ms
		//nRet = MV_CC_GetOneFrameTimeout(m_hGrabThread, pData, g_nPayloadSize, &stImageInfo, 1000);
		nRet = m_pcMyCamera->GetOneFrameTimeout(pData, g_nPayloadSize, &stImageInfo, 1000);
		if (nRet == MV_OK)
		{
			printf("Get One Frame: Width[%d], Height[%d], nFrameNum[%d]\n",
				stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
		}
		else
		{
			PopDialog("No data");
			printf("No data[0x%x]\n", nRet);
			free(pData);
			pData = NULL;
			return;
		}

		// 数据去转换
		bool bConvertRet = false;

		bConvertRet = Convert2Mat(&stImageInfo, pData);


		// print result
		if (bConvertRet)
		{
			printf("OpenCV format convert finished.\n");
			free(pData);
			pData = NULL;
		}
		else
		{
			printf("OpenCV format convert failed.\n");
			free(pData);
			pData = NULL;
			return;
		}
	
	m_bStartGrabbing = TRUE;
	EnableControls(TRUE);

	while (m_bThreadState) {
		if (m_nTriggerMode == MV_TRIGGER_MODE_OFF) {
			/*
			nRet = MV_OK;
			// Get payload size
			MVCC_INTVALUE_EX stParam;
			memset(&stParam, 0, sizeof(MVCC_INTVALUE));
			//nRet = MV_CC_GetIntValue(m_hGrabThread, "PayloadSize", &stParam);
			nRet = m_pcMyCamera->GetIntValue("PayloadSize", &stParam);
			if (MV_OK != nRet)
			{
				printf("Get PayloadSize fail! nRet [0x%x]\n", nRet);
				return;
			}
			g_nPayloadSize = stParam.nCurValue;
			*/
			MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
			memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
			unsigned char* pData = (unsigned char*)malloc(sizeof(unsigned char) * (g_nPayloadSize));
			if (pData == NULL)
			{
				printf("Allocate memory failed.\n");
				return;
			}
			
			// get one frame from camera with timeout=1000ms
			//nRet = MV_CC_GetOneFrameTimeout(m_hGrabThread, pData, g_nPayloadSize, &stImageInfo, 1000);
			nRet = m_pcMyCamera->GetOneFrameTimeout(pData, g_nPayloadSize, &stImageInfo, 1000);
			if (nRet == MV_OK)
			{
				printf("Get One Frame: Width[%d], Height[%d], nFrameNum[%d]\n",
					stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
			}
			else
			{
				PopDialog("No data");
				printf("No data[0x%x]\n", nRet);
				free(pData);
				pData = NULL;
				return;
			}


			MV_FRAME_OUT_INFO_EX* pstImageInfo = &stImageInfo;
			if (pstImageInfo->enPixelType == PixelType_Gvsp_Mono8)
			{
				srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC1, pData);
				//cv::imshow("srcimg", srcImage);
				cv::waitKey(5);
			}
			else if (pstImageInfo->enPixelType == PixelType_Gvsp_RGB8_Packed)
			{
				RGB2BGR(pData, pstImageInfo->nWidth, pstImageInfo->nHeight);
				srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC3, pData);
				//cv::imshow("srcimg", srcImage);
				cv::waitKey(5);
			}
			else
			{
				printf("unsupported pixel format\n");
				return;
			}

			if (NULL == srcImage.data)
			{
				return;
			}


			pixmap = QPixmap::fromImage(cvMatToQImage(srcImage));
			int width = ui.Show_label->width();
			int height = ui.Show_label->height();
			//QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
			fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
			int cur_width = fitpixmap.size().width();
			int origin_width = pixmap.size().width();
			scaled_ratio = origin_width / cur_width;

			label_img->getPix(fitpixmap);

			update();

		}
		else if (m_nTriggerMode == MV_TRIGGER_MODE_ON) {
			break;
		}

	}
	
}

// ch:按下停止采集按钮 | en:Click Stop button
void QtWidgetsApplication1::on_StopGrabbingBtn_clicked()
{
	if (FALSE == m_bOpenDevice || FALSE == m_bStartGrabbing || NULL == m_pcMyCamera)
	{
		return;
	}

	m_bThreadState = FALSE;
	if (m_hGrabThread)
	{
		WaitForSingleObject(m_hGrabThread, INFINITE);
		CloseHandle(m_hGrabThread);
		m_hGrabThread = NULL;
	}

	int nRet = m_pcMyCamera->StopGrabbing();
	if (MV_OK != nRet)
	{
		PopDialog("Stop grabbing fail");
		//ShowErrorMsg(TEXT("Stop grabbing fail"), nRet);
		return;
	}
	m_bStartGrabbing = FALSE;
	EnableControls(TRUE);

}

// ch:按下连续模式按钮
void QtWidgetsApplication1::on_CtnModeBtn_clicked() {
	
	m_nTriggerMode = MV_TRIGGER_MODE_OFF;

	/*
	int nRet = m_pcMyCamera->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);
	if (MV_OK != nRet)
	{
		printf("Set Trigger Mode fail! nRet [0x%x]\n", nRet);
		return;
	}*/
}

// ch:按下触发模式按钮
void QtWidgetsApplication1::on_TriggerModeBtn_clicked() {
	
	m_nTriggerMode = MV_TRIGGER_MODE_ON;
	/*
	int nRet = m_pcMyCamera->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
	if (MV_OK != nRet)
	{
		printf("Set Trigger Mode fail! nRet [0x%x]\n", nRet);
		return;
	}*/
}

// ch:按下软触发一次按钮
void QtWidgetsApplication1::on_SoftTriggerBtn_clicked() {
	// Get payload size
	MVCC_INTVALUE_EX stParam;
	memset(&stParam, 0, sizeof(MVCC_INTVALUE));
	//nRet = MV_CC_GetIntValue(m_hGrabThread, "PayloadSize", &stParam);
	int nRet = m_pcMyCamera->GetIntValue("PayloadSize", &stParam);
	if (MV_OK != nRet)
	{
		printf("Get PayloadSize fail! nRet [0x%x]\n", nRet);
		return;
	}
	g_nPayloadSize = stParam.nCurValue;

	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
	memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
	unsigned char* pData = (unsigned char*)malloc(sizeof(unsigned char) * (g_nPayloadSize));
	if (pData == NULL)
	{
		printf("Allocate memory failed.\n");
		return;
	}

	// get one frame from camera with timeout=1000ms
	//nRet = MV_CC_GetOneFrameTimeout(m_hGrabThread, pData, g_nPayloadSize, &stImageInfo, 1000);
	nRet = m_pcMyCamera->GetOneFrameTimeout(pData, g_nPayloadSize, &stImageInfo, 1000);
	if (nRet == MV_OK)
	{
		printf("Get One Frame: Width[%d], Height[%d], nFrameNum[%d]\n",
			stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
	}
	else
	{
		PopDialog("No data");
		printf("No data[0x%x]\n", nRet);
		free(pData);
		pData = NULL;
		return;
	}



	MV_FRAME_OUT_INFO_EX* pstImageInfo = &stImageInfo;
	if (pstImageInfo->enPixelType == PixelType_Gvsp_Mono8)
	{
		srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC1, pData);
		//cv::imshow("srcimg", srcImage);
	}
	else if (pstImageInfo->enPixelType == PixelType_Gvsp_RGB8_Packed)
	{
		RGB2BGR(pData, pstImageInfo->nWidth, pstImageInfo->nHeight);
		srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC3, pData);
		//cv::imshow("srcimg", srcImage);
	}
	else
	{
		printf("unsupported pixel format\n");
		return;
	}

	if (NULL == srcImage.data)
	{
		return;
	}


	pixmap = QPixmap::fromImage(cvMatToQImage(srcImage));
	int width = ui.Show_label->width();
	int height = ui.Show_label->height();
	//QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
	fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
	int cur_width = fitpixmap.size().width();
	int origin_width = pixmap.size().width();
	scaled_ratio = origin_width / cur_width;

	label_img->getPix(fitpixmap);

	update();
}

// ch:按下参数设置按钮
void QtWidgetsApplication1::on_SetParameterBtn_clicked() {
	bool bIsSetSucceed = true;
	int nRet = SetExposureTime();
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		PopDialog("Set Exposure Time Fail");
		//ShowErrorMsg(TEXT("Set Exposure Time Fail"), nRet);
	}
	nRet = SetGain();
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		PopDialog("Set Gain Fail");
		//ShowErrorMsg(TEXT("Set Gain Fail"), nRet);
	}
	if (true == bIsSetSucceed)
	{
		PopDialog("Set Parameter Succeed");
		//ShowErrorMsg(TEXT("Set Parameter Succeed"), nRet);
	}
}

// ch:按下参数获取按钮
void QtWidgetsApplication1::on_GetParameterBtn_clicked() {
	int nRet = GetExposureTime();
	if (nRet != MV_OK)
	{
		PopDialog("Get Exposure Time Fail");
		//ShowErrorMsg(TEXT("Get Exposure Time Fail"), nRet);
	}

	nRet = GetGain();
	if (nRet != MV_OK)
	{
		PopDialog("Get Gain Fail");
		//ShowErrorMsg(TEXT("Get Gain Fail"), nRet);
	}
}

// ch:获取曝光时间 | en:Get Exposure Time
int QtWidgetsApplication1::GetExposureTime()
{
	MVCC_FLOATVALUE stFloatValue = { 0 };

	int nRet = m_pcMyCamera->GetFloatValue("ExposureTime", &stFloatValue);
	if (MV_OK != nRet)
	{
		return nRet;
	}

	ui.ExposureEdit->setText(QString("%1").arg(stFloatValue.fCurValue));

	return MV_OK;
}

// ch:设置曝光时间 | en:Set Exposure Time
int QtWidgetsApplication1::SetExposureTime()
{
	// ch:调节这两个曝光模式，才能让曝光时间生效
	// en:Adjust these two exposure mode to allow exposure time effective
	int nRet = m_pcMyCamera->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);
	if (MV_OK != nRet)
	{
		return nRet;
	}

	m_pcMyCamera->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);

	return m_pcMyCamera->SetFloatValue("ExposureTime", ui.ExposureEdit->text().toFloat());
}

// ch:获取增益 | en:Get Gain
int QtWidgetsApplication1::GetGain()
{
	MVCC_FLOATVALUE stFloatValue = { 0 };

	int nRet = m_pcMyCamera->GetFloatValue("Gain", &stFloatValue);
	if (MV_OK != nRet)
	{
		return nRet;
	}
	ui.GainEdit->setText(QString("%1").arg(stFloatValue.fCurValue));

	return MV_OK;
}

// ch:设置增益 | en:Set Gain
int QtWidgetsApplication1::SetGain()
{
	// ch:设置增益前先把自动增益关闭，失败无需返回
	//en:Set Gain after Auto Gain is turned off, this failure does not need to return
	m_pcMyCamera->SetEnumValue("GainAuto", 0);

	return m_pcMyCamera->SetFloatValue("Gain", ui.GainEdit->text().toFloat());
}

// ch:保存BMP图片
void QtWidgetsApplication1::on_SaveBMPBtn_clicked() {


	//string Img_Name = "D:\\Machine Vision\\SaveImg" + to_string(1) + ".bmp";
	cv::imshow("src",srcImage);
	cv::imwrite("D:\\Machine Vision\\SaveImg\\image.bmp", srcImage);
	
}

// ch:保存JPG图片
void QtWidgetsApplication1::on_SaveJPGBtn_clicked() {

	//string Img_Name = "D:\\Machine Vision\\SaveImg" + to_string(1) + ".bmp";
	cv::imshow("src", srcImage);
	cv::imwrite("D:\\Machine Vision\\SaveImg\\image.jpg", srcImage);

}

// ch:保存tiff图片
void QtWidgetsApplication1::on_SaveTIFFBtn_clicked() {

	//string Img_Name = "D:\\Machine Vision\\SaveImg" + to_string(1) + ".bmp";
	cv::imshow("src", srcImage);
	cv::imwrite("D:\\Machine Vision\\SaveImg\\image.tiff", srcImage);

}

// ch:保存png图片
void QtWidgetsApplication1::on_SavePNGBtn_clicked() {

	//string Img_Name = "D:\\Machine Vision\\SaveImg" + to_string(1) + ".bmp";
	cv::imshow("src", srcImage);
	cv::imwrite("D:\\Machine Vision\\SaveImg\\image.png", srcImage);

}


// ch:按钮使能 | en:Enable control
void QtWidgetsApplication1::EnableControls(BOOL bIsCameraReady)
{
	
	ui.OpenDevice_Btn->setEnabled(m_bOpenDevice ? FALSE : (bIsCameraReady ? TRUE : FALSE));
	ui.CloseDevice_Btn->setEnabled((m_bOpenDevice && bIsCameraReady) ? TRUE : FALSE);
	ui.StartGrabbing_Btn->setEnabled((m_bStartGrabbing && bIsCameraReady) ? FALSE : (m_bOpenDevice ? TRUE : FALSE));
	ui.StopGrabbing_Btn->setEnabled(m_bStartGrabbing ? TRUE : FALSE);
	

}
