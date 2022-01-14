
#include "myLabel.h"
#include "QtWidgetsApplication1.h"

myLabel::myLabel(QWidget* parent) :QLabel(parent)
           ,m_currentCaptureState(initCapture)
{
	//QList<QRect> Rects[2];    //绘制两个框时可能会用到
	//clear();

}

int myLabel::getMode(int x)
{
	return m_Mode = (Mode)x;
}

int myLabel::getClickedBtn(int x)
{
	return m_clickedBtn = (clickedBtn)x;  //把数值赋予枚举变量，必须用强制类型转换。
}

//导出数据
void myLabel::onLogData(QString fileName) {
	/*
	QFileInfo l_info("./QtWidgetsApplication1.exe");
	QString l_str = l_info.absolutePath();//绝对路径

	QString dir_str;
	QString str = QString("SaveData");//文件夹名
	dir_str = l_str + "/" + str;
	QDir dir;
	dir.mkpath(dir_str); //新建文件夹：（文件夹名：SaveData）

	QDateTime datetime;
	// QString timestr=datetime.currentDateTime().toString("yyyy.MM.dd_HH.mm.ss");
	QString timestr = datetime.currentDateTime().toString("yyyy.MM.dd");
	QString fileName = dir_str + "/" + timestr + ".txt";*/
	QFile file(fileName);

	/*******写数据到文本文件*******/
	if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		if (linlindis.size()) {
			for (int i = 0; i < linlindis.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i+1);
				file.write(Number);

				char cBuf[64] =  " 线线距离：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%fmm\n", linlindis[i]);
				file.write(data);			
			}
		}
		if (ptlindis.size()) {
			for (int i = 0; i < ptlindis.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char cBuf[64] = " 点线距离：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%fmm\n", ptlindis[i]);
				file.write(data);
			}
		}
		if (ptptdis.size()) {
			for (int i = 0; i < ptptdis.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char cBuf[64] = " 点点距离：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%fmm\n", ptptdis[i]);
				file.write(data);
			}
		}
		if (circirdis.size()) {
			for (int i = 0; i < circirdis.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char cBuf[64] = " 圆圆距离：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%fmm\n", circirdis[i]);
				file.write(data);
			}
		}
		if (Circle.size()) {
			for (int i = 0; i < Circle.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char rBuf[64] = " 圆	半径：";
				file.write(rBuf);

				char Rdata[64] = "";
				sprintf(Rdata, "%fmm", ratio * scaled_ratio * Circle[i].radius);
				file.write(Rdata);

				char dBuf[64] = "	直径：";
				file.write(dBuf);

				char Ddata[64] = "";
				sprintf(Ddata, "%fmm\n ", ratio * 2 * scaled_ratio * Circle[i].radius);
				file.write(Ddata);
			}
		}
		if (linlinangle.size()) {
			for (int i = 0; i < linlinangle.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char cBuf[64] = " 线线角度：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%f度\n", linlinangle[i]);
				file.write(data);
			}
		}
		if (Parallelism.size()) {
			for (int i = 0; i < linlinangle.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char cBuf[64] = " 平行度：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%fmm\n", Parallelism[i]);
				file.write(data);
			}
		}
		if (Perpendicularity.size()) {
			for (int i = 0; i < linlinangle.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char cBuf[64] = " 垂直度：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%fmm\n", Perpendicularity[i]);
				file.write(data);
			}
		}
		if (arcangle.size()) {
			for (int i = 0; i < linlinangle.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char cBuf[64] = " 圆弧角度：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%f度\n", arcangle[i]);
				file.write(data);
			}
		}
		if (Taper.size()) {
			for (int i = 0; i < Taper.size(); i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char cBuf[64] = " 锥度：";
				file.write(cBuf);

				char data[64] = "";
				sprintf(data, "%f\n", Taper[i]);
				file.write(data);
			}
		}
		if (axiality.size()) {
			for (int i = 0; i < axiality.size()/2; i++) {
				char Number[64] = "";
				sprintf(Number, "No.%i", i + 1);
				file.write(Number);

				char verBuf[64] = " 竖直同轴度：";
				file.write(verBuf);

				char vdata[64] = "";
				sprintf(vdata, "%f度\n", axiality[2*i]);
				file.write(vdata);

				char horBuf[64] = " 水平同轴度：";
				file.write(horBuf);

				char hdata[64] = "";
				sprintf(hdata, "%f度\n", axiality[2 * i+1]);
				file.write(hdata);
			}
		}
	}
	file.close();

}

//清除所有数据
void myLabel::onClearImage()
{
	Line.clear();
	Circle.clear();
	Point.clear();
	linlindis_Line.clear();
	linlindis.clear();
	ptlindis_Line.clear();
	ptlindis.clear();
	ptptdis_Line.clear();
	ptptdis.clear();
	circirdis_Line.clear();
	circirdis.clear();
	linlinangle_Line.clear();
	linlinangle.clear();
	arcangle.clear();
	Taper.clear();
	Parallelism.clear();
	parallelism_Line.clear();
	Perpendicularity.clear();
	perpendicularity_Line.clear();
	Roundness.clear();
	cv_rect1.clear();
	update();
}

//清除矩形框数据
void myLabel::clearRect()
{
	StartPoint = QPoint(0, 0);
	EndPoint = QPoint(1, 1);
	m_currentSelectRect = QRectF(0, 0, 5, 5);
	update();
}

void myLabel::clearPoint() 
{
    PtPoint = QPoint(0, 0);
	lineStartPoint = QPoint(0, 0);lineEndPoint = QPoint(0, 0);
	lastPtPoint = QPoint(0, 0);
	lastCirCenter = QPoint(0, 0);
	curCirCenter = QPoint(0, 0);
	lastLine = QLine(0, 0, 0, 0);
	curLine = QLine(0, 0, 0, 0);
	ArcCenter = QPoint(0, 0); ArcLinTan0 = QPoint(0, 0); ArcLinTan1 = QPoint(0, 0); ArcRadius = 0;
	verCtrLineStartPt = QPoint(0, 0); verCtrLineEndPt = QPoint(0, 0);
	horCtrLineStartPt = QPoint(0, 0); horCtrLineEndPt = QPoint(0, 0);
	lastVerCtrLineStartPt = QPoint(0, 0); lastVerCtrLineEndPt = QPoint(0, 0);
	lastHorCtrLineStartPt = QPoint(0, 0); lastHorCtrLineEndPt = QPoint(0, 0);
	ArcPt0 = QPoint(0, 0); ArcPt1 = QPoint(0, 0); ArcPt2 = QPoint(0, 0); temp = QPoint(0, 0);
	pp = QPoint(0, 0); p1 = QPoint(0, 0);p2 = QPoint(0, 0);
	leftPeakLineStartPt = QPoint(0, 0); leftPeakLineEndPt = QPoint(0, 0); 
	rightPeakLineStartPt = QPoint(0, 0); rightPeakLineEndPt = QPoint(0, 0);
	intersectionPt = QPoint(0, 0);
	footPoint = QPoint(0, 0);
	update();
}

//获取当前label下的图片;
QPixmap myLabel::getPix(QPixmap map)
{
	m_Pixmap = map;
	update();
	return m_Pixmap;
}
void myLabel::getSrc(cv::Mat src, double ratio) {
	cv_src = src;
	scaled_ratio = ratio;
}

//滚轮事件
void myLabel::wheelEvent(QWheelEvent* event)
{
	if (this->width() - m_Pixmap.size().width() == 0 && this->height() - m_Pixmap.size().height() == 0) {
		getMode(3);      //缩放
		clearRect();//清除当前矩形框数据
		clearPoint();//清除当前交点数据
		getClickedBtn(25);
		cv::destroyAllWindows();
		int value = event->delta();
		if (value > 0)
			onZoomInImage();
		else
			onZoomOutImage();

		this->update();
	}
}
//放大
void myLabel::onZoomInImage(void)
{
	m_ZoomValue += 0.1;
	this->update();
}
//缩小
void myLabel::onZoomOutImage(void)
{
	m_ZoomValue -= 0.1;
	if (m_ZoomValue < 1.0)
	{
		m_ZoomValue = 1.0;
		return;
	}

	this->update();
}
void myLabel::onPresetImage(void)
{
	m_ZoomValue = 1.0;
	m_XPtInterval = 0;
	m_YPtInterval = 0;
	this->update();
}


//绘制事件
void myLabel::paintEvent(QPaintEvent* event)
{
	QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
	QPainter painter(this);
	// 根据窗口计算应该显示的图片的大小
	int width = qMin(m_Pixmap.width(), this->width());
	int height = width * 1.0 / (m_Pixmap.width() * 1.0 / m_Pixmap.height());
	height = qMin(height, this->height());
	// 缩放
	painter.scale(m_ZoomValue, m_ZoomValue);
	// 平移
	painter.translate(this->width() / 2 + m_XPtInterval, this->height() / 2 + m_YPtInterval);//坐标系在中心位置
	// 绘制图像
	QRect picRect(-width / 2, -height / 2, width, height);//左上角为-w/2,-h/2

	painter.drawPixmap(picRect, m_Pixmap);
	if (Line.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		pen.setColor(QColor(Qt::blue));pen.setWidth(4);painter.setPen(pen);
		for (auto i = 0; i < Line.size(); i++) {
			painter.drawLine(Line[i]);
		}
	}
	if (Circle.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		if (triggerMode == 1 && deviceOpened == 1) {
			pen.setColor(QColor(Qt::blue)); pen.setWidth(3); painter.setPen(pen);
			painter.drawEllipse(Circle.back().center.x() - Circle.back().radius,
				Circle.back().center.y() - Circle.back().radius,
				2 * Circle.back().radius,
				2 * Circle.back().radius);

			pen.setWidth(1); pen.setColor(QColor(Qt::red)); painter.setPen(pen);
			QPoint tempPt; tempPt.setX(Circle.back().center.x() + Circle.back().radius); tempPt.setY(Circle.back().center.y());
			painter.drawLine(Circle.back().center, tempPt);
			QString data = QString("%1mm").arg(ratio * scaled_ratio * Circle.back().radius);    //显示半径
			painter.drawText((Circle.back().center.x() + tempPt.x()) / 2, (Circle.back().center.y() + tempPt.y()) / 2, data);
		}
		else {
			for (auto i = 0; i < Circle.size(); i++) {
				pen.setColor(QColor(Qt::blue)); pen.setWidth(3); painter.setPen(pen);
				painter.drawEllipse(Circle[i].center.x() - Circle[i].radius,
					Circle[i].center.y() - Circle[i].radius,
					2 * Circle[i].radius,
					2 * Circle[i].radius);

				pen.setWidth(1); pen.setColor(QColor(Qt::red)); painter.setPen(pen);
				QPoint tempPt; tempPt.setX(Circle[i].center.x() + Circle[i].radius); tempPt.setY(Circle[i].center.y());
				painter.drawLine(Circle[i].center, tempPt);
				QString data = QString("%1mm").arg(ratio * scaled_ratio * Circle[i].radius);    //显示半径
				painter.drawText((Circle[i].center.x() + tempPt.x()) / 2, (Circle[i].center.y() + tempPt.y()) / 2, data);
			}
		}
	}
	if (Point.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		pen.setColor(QColor(Qt::red)); pen.setWidth(5); painter.setPen(pen);
		for (auto i = 0; i < Point.size(); i++) {
			painter.drawPoint(Point[i]);
		}
	}
	if (ptptdis_Line.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::red)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < ptptdis_Line.size(); i++) {
			painter.drawLine(ptptdis_Line[i]);
		}
		for (auto i = 0; i < ptptdis.size(); i++) {
			QString data = QString("%1mm").arg(ptptdis[i]);    //显示距离
			painter.drawText(ptptdis_Line[i].x1() + 5, ptptdis_Line[i].y1() - 5, data);
		}
	}
	if (ptlindis_Line.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::red)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < ptlindis_Line.size(); i++) {
			painter.drawLine(ptlindis_Line[i]);
		}
		for (auto i = 0; i < ptlindis.size(); i++) {
			QString data = QString("%1mm").arg(ptlindis[i]);    //显示距离
			painter.drawText(Point[i].x()+5,Point[i].y()-5, data);
		}
	}
	if (linlindis_Line.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::red)); pen.setWidth(1); painter.setPen(pen);
		if (deviceOpened == 1 && triggerMode == 1) {
			painter.drawLine(linlindis_Line.back());
		}
		else {
			for (auto i = 0; i < linlindis_Line.size(); i++) {
				painter.drawLine(linlindis_Line[i]);
			}
			for (auto i = 0; i < linlindis.size(); i++) {
				QString data = QString("%1mm").arg(linlindis[i]);    //显示距离
				painter.drawText(linlindis_Line[i].x1() + 5, linlindis_Line[i].y1() - 5, data);
			}
		}
	}
	if (circirdis.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::green)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < circirdis_Line.size(); i++) {
			painter.drawLine(circirdis_Line[i]);
		}
		for (auto i = 0; i < circirdis.size(); i++) {
			QString data = QString("%1mm").arg(circirdis[i]);    //显示距离
			painter.drawText(circirdis_Line[i].x1() + 5, circirdis_Line[i].y1() - 5, data);
		}
	}
	if (linlinangle.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::green)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < linlinangle_Line.size(); i++) {
			painter.drawLine(linlinangle_Line[i]);
		}
		for (auto i = 0; i < linlinangle.size(); i++) {
			QString data = QString("%1°").arg(linlinangle[i]);    //显示角度
			painter.drawText(linlinangle_Line[2 * i].x1() + 5, linlinangle_Line[2 * i].y1() - 5, data);
		}
	}
	if (Taper.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::green)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < taper_Line.size(); i++) {
			painter.drawLine(taper_Line[i]);
		}
		for (auto i = 0; i < Taper.size(); i++) {
			QString data = QString("%1").arg(Taper[i]);    //显示
			painter.drawText(taper_Line[2 * i].x1() + 5, taper_Line[2 * i].y1() - 5, data);
		}
	}
	if (Parallelism.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::green)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < Parallelism.size(); i++) {
			QString data = QString("%1mm").arg(Parallelism[i]);    //显示
			painter.drawText(parallelism_Line[2*i].x1() + 5, parallelism_Line[2*i].y1() - 5, data);
		}
	}
	if (Perpendicularity.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::green)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < Perpendicularity.size(); i++) {
			QString data = QString("%1mm").arg(Perpendicularity[i]);    //显示
			painter.drawText(perpendicularity_Line[2 * i].x1() + 5, perpendicularity_Line[2 * i].y1() - 5, data);
		}
	}
	if (arcangle.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::green)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < arcangle_Line.size(); i++) {
			painter.drawLine(arcangle_Line[i]);
		}
		for (auto i = 0; i < arcangle.size(); i++) {
			QString data = QString("%1°").arg(arcangle[i]);    //显示角度
			painter.drawText(arcangle_Line[2*i].x2() + 5, arcangle_Line[2*i].y2() - 5, data);
		}
	}
	if (Roundness.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::red)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < Roundness.size(); i++) {
			QString data = QString("%1mm").arg(Roundness[i]);    //显示距离
			painter.drawText(Roundness_Point[i].x() - 10, Roundness_Point[i].y() + 10, data);
		}
	}
	if (axiality.size()) {
		QPainter painter(this);
		painter.scale(m_ZoomValue, m_ZoomValue);
		painter.translate(m_XPtInterval, m_YPtInterval);
		QPen pen;
		QVector<qreal>dashes;
		qreal space = 4;
		dashes << 3 << space;
		pen.setDashPattern(dashes);
		pen.setColor(QColor(Qt::green)); pen.setWidth(1); painter.setPen(pen);
		for (auto i = 0; i < axiality.size(); i++) {
			QString data = QString("%1mm").arg(axiality[i]);    //显示距离
			painter.drawText(axiality_Point[i].x() + 5, axiality_Point[i].y() - 5, data);
		}
	}
	/*
	if (m_Mode == SCALE) {
		QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
		QPainter painter(this);
		// 缩放
		painter.scale(m_ZoomValue, m_ZoomValue);

		// 绘制图像
		//QRect picRect(-width / 2, -height / 2, width, height);

		painter.drawPixmap(0,0, m_Pixmap);
	}*/
	if (m_Mode == CUSTOMARC) {
		QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
		QPainter painter(this);
		QPen pen;
		pen.setColor(QColor(Qt::red));
		pen.setWidth(2);
		painter.setPen(pen);
		if (!ArcPt0.isNull()) {
			painter.drawPoint(ArcPt0);
		}
		if (!ArcPt1.isNull()) {
			painter.drawPoint(ArcPt0);
			painter.drawPoint(ArcPt1);
		}
		if (!temp.isNull()) {
			painter.drawPoint(ArcPt0);
			painter.drawPoint(ArcPt1);
			painter.drawPoint(temp);
			painter.drawPoint(Arc.center);
			painter.drawArc(Arc.center.x() - Arc.radius, Arc.center.y() - Arc.radius, 2 * Arc.radius, 2 * Arc.radius, 16 * StartAngle, 16 * ArcAngle);
			painter.drawArc(Arc.center.x() - Arc.radius + dr, Arc.center.y() - Arc.radius + dr, 2 * (Arc.radius - dr), 2 * (Arc.radius - dr), 16 * StartAngle, 16 * ArcAngle);
			painter.drawArc(Arc.center.x() - Arc.radius - dr, Arc.center.y() - Arc.radius - dr, 2 * (Arc.radius + dr), 2 * (Arc.radius + dr), 16 * StartAngle, 16 * ArcAngle);
		}
		if (!ArcPt2.isNull()) {
			/*
			painter.drawPoint(ArcPt0);
			painter.drawPoint(ArcPt1);
			painter.drawPoint(ArcPt2);
			painter.drawPoint(Arc.center);
			painter.drawArc(Arc.center.x() - Arc.radius, Arc.center.y() - Arc.radius, 2*Arc.radius, 2*Arc.radius, 16*StartAngle, 16*ArcAngle);
			painter.drawArc(Arc.center.x() - Arc.radius+dr, Arc.center.y() - Arc.radius+dr, 2 * (Arc.radius-dr), 2 * (Arc.radius-dr), 16 * StartAngle, 16 * ArcAngle);
			painter.drawArc(Arc.center.x() - Arc.radius - dr, Arc.center.y() - Arc.radius - dr, 2 * (Arc.radius + dr), 2 * (Arc.radius + dr), 16 * StartAngle, 16 * ArcAngle);
			*/
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x() - ArcRadius*m_ZoomValue, 
				ArcCenter.y() - ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue);
			pen.setWidth(6);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
			pen.setWidth(1); painter.setPen(pen);
			QPoint tempPt; tempPt.setX(ArcCenter.x() + ArcRadius * m_ZoomValue); tempPt.setY(ArcCenter.y());
			painter.drawLine(ArcCenter, tempPt);
			QString data = QString("%1mm").arg(ratio * scaled_ratio * ArcRadius);    //显示半径
			painter.drawText((ArcCenter.x() + tempPt.x()) / 2, (ArcCenter.y() + tempPt.y()) / 2, data);
		}
		
	}
	if (m_Mode == MEASURE) {
		//点-点距离
		if (m_clickedBtn == on_ptptdisBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			//painter.drawRect(QRect(StartPoint.x(), StartPoint.y(), EndPoint.x() - StartPoint.x(), EndPoint.y() - StartPoint.y()));
			m_currentSelectRect = getSelectRect();
			painter.drawLine(StartPoint, EndPoint);
			if (!PtPoint.isNull() && lastPtPoint.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(10);
				painter.setPen(pen);
				painter.drawPoint(PtPoint);
				lastPtPoint = PtPoint;
			}
			else if (!lastPtPoint.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(10);
				painter.setPen(pen);
				painter.drawPoint(lastPtPoint);
				painter.drawPoint(PtPoint);
				pen.setWidth(1); pen.setColor(QColor(Qt::red));
				painter.setPen(pen);
				painter.drawLine(PtPoint, lastPtPoint);
				num = ratio*sqrtf(powf((PtPoint.x() - lastPtPoint.x()), 2) + powf((PtPoint.y() - lastPtPoint.y()), 2));
				QString data = QString("%1mm").arg(num/m_ZoomValue);
				painter.drawText((PtPoint.x() + lastPtPoint.x()) / 2, (PtPoint.y() + lastPtPoint.y()) / 2, data);
			}
		}
		//点-线距离
		else if (m_clickedBtn == on_ptlindisBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			//painter.drawRect(QRect(StartPoint.x(), StartPoint.y(), EndPoint.x() - StartPoint.x(), EndPoint.y() - StartPoint.y()));
			m_currentSelectRect = getSelectRect();
			painter.drawLine(StartPoint, EndPoint);
			painter.drawRect(m_currentSelectRect);
			if (!PtPoint.isNull() && lastPtPoint.isNull()) {
				pen.setColor(QColor(Qt::yellow));
				pen.setWidth(10);
				painter.setPen(pen);
				painter.drawPoint(PtPoint);
				lastPtPoint = PtPoint;
			}
			else if (!lastPtPoint.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(10);
				painter.setPen(pen);
				painter.drawPoint(lastPtPoint);
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(lineStartPoint, lineEndPoint);
				if (!footPoint.isNull()) {
					pen.setColor(QColor(Qt::red));
					pen.setWidth(1);
					painter.setPen(pen);
					painter.drawLine(PtPoint, footPoint);
					num = ratio*sqrtf(powf((PtPoint.x() - footPoint.x()), 2) + powf((PtPoint.y() - footPoint.y()), 2));
					QString data = QString("%1mm").arg(num/m_ZoomValue);    //显示距离num
					painter.drawText((PtPoint.x() + footPoint.x()) / 2, (PtPoint.y() + footPoint.y()) / 2, data);

					// 画延长虚线
					p1 = lineStartPoint.x() > lineEndPoint.x() ? lineEndPoint : lineStartPoint;
					p2 = lineStartPoint.x() > lineEndPoint.x() ? lineStartPoint : lineEndPoint;
					if (footPoint.x() < p1.x())
					{
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						pen.setWidth(1);
						painter.setPen(pen);
						painter.drawLine(footPoint, p1);
						pp = p1;
					}
					else if (footPoint.x() > p2.x())
					{
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						pen.setWidth(1);
						painter.setPen(pen);
						painter.drawLine(footPoint, p2);
						pp = p2;
					}
					else
					{
						p1 = lineStartPoint.y() > lineEndPoint.y() ? lineEndPoint : lineStartPoint;
						p2 = lineStartPoint.y() > lineEndPoint.y() ? lineStartPoint : lineEndPoint;
						if (footPoint.y() < p1.y())
						{
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							pen.setWidth(1);
							painter.setPen(pen);
							painter.drawLine(footPoint, p1);
							pp = p1;
						}
						else if (footPoint.y() > p2.y())
						{
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							pen.setWidth(1);
							painter.setPen(pen);
							painter.drawLine(footPoint, p2);
							pp = p2;
						}
					}
				}
			}
		}
		//直线交点
		else if (m_clickedBtn == on_intersectionBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!curLine.isNull() && lastLine.isNull()) {
				pen.setColor(QColor(Qt::yellow));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				lastLine = curLine;
			}
			else if (!lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				painter.drawLine(lastLine);
				pen.setColor(QColor(Qt::red));
				painter.setPen(pen);
				painter.drawPoint(intersectionPt);
				//延长虚线
				pen.setWidth(2);
				painter.setPen(pen);
				if (Parallel == -1) { //判断是否平行
					if (intersectionPt.x() > (lastLine.x1() > lastLine.x2() ? lastLine.x1() : lastLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (lastLine.x1() > lastLine.x2() ? lastLine.p1() : lastLine.p2()));
					}
					else if (intersectionPt.x() < (lastLine.x1() < lastLine.x2() ? lastLine.x1() : lastLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (lastLine.x1() < lastLine.x2() ? lastLine.p1() : lastLine.p2()));
					}
					else {
						if (intersectionPt.y() > (lastLine.y1() > lastLine.y2() ? lastLine.y1() : lastLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (lastLine.y1() > lastLine.y2() ? lastLine.p1() : lastLine.p2()));
						}
						else if (intersectionPt.y() < (lastLine.y1() < lastLine.y2() ? lastLine.y1() : lastLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (lastLine.y1() < lastLine.y2() ? lastLine.p1() : lastLine.p2()));
						}
					}

					if (intersectionPt.x() > (curLine.x1() > curLine.x2() ? curLine.x1() : curLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (curLine.x1() > curLine.x2() ? curLine.p1() : curLine.p2()));
					}
					else if (intersectionPt.x() < (curLine.x1() < curLine.x2() ? curLine.x1() : curLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (curLine.x1() < curLine.x2() ? curLine.p1() : curLine.p2()));
					}
					else {
						if (intersectionPt.y() > (curLine.y1() > curLine.y2() ? curLine.y1() : curLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (curLine.y1() > curLine.y2() ? curLine.p1() : curLine.p2()));
						}
						else if (intersectionPt.y() < (curLine.y1() < curLine.y2() ? curLine.y1() : curLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (curLine.y1() < curLine.y2() ? curLine.p1() : curLine.p2()));
						}
					}
				}
			}
		}
		//锥度
		else if (m_clickedBtn == on_taperBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!curLine.isNull() && lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				lastLine = curLine;
			}
			else if (!lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				painter.drawLine(lastLine);
				//延长虚线
				if (Parallel == -1) { //判断是否平行
					pen.setColor(QColor(Qt::red));
					pen.setWidth(6);
					painter.setPen(pen);
					painter.drawPoint(intersectionPt);
					taper = 2*tan(LineLineAngle*CV_PI / 360);//   锥度为2*tan(a/2),a为顶角
					QString data = QString("%1").arg(taper);    //显示锥度
					pen.setWidth(1);
					painter.drawText((lastLine.x1()+curLine.x1())/2 + 5, (lastLine.y1()+curLine.y1())/2 - 5, data);
					
				}
				else {
					QString data = QString("0");    //显示角度
					pen.setWidth(1);
					painter.drawText(lastLine.x1() + 5, lastLine.y1() - 5, data);
				}
			}
		}
		//线线角度
		else if (m_clickedBtn == on_linlinAngleBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!curLine.isNull() && lastLine.isNull()) {
				pen.setColor(QColor(Qt::yellow));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				lastLine = curLine;
			}
			else if (!lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				painter.drawLine(lastLine);
				//延长虚线
				if (Parallel == -1) { //判断是否平行
					pen.setColor(QColor(Qt::red));
					pen.setWidth(6);
					painter.setPen(pen);
					painter.drawPoint(intersectionPt);
					QString data = QString("%1").arg(LineLineAngle);    //显示角度
					pen.setWidth(1);
					painter.drawText(lastLine.x1() + 5, lastLine.y1() - 5, data);
					pen.setWidth(2);
					painter.setPen(pen);
					if (intersectionPt.x() > (lastLine.x1() > lastLine.x2() ? lastLine.x1() : lastLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (lastLine.x1() > lastLine.x2() ? lastLine.p1() : lastLine.p2()));
					}
					else if (intersectionPt.x() < (lastLine.x1() < lastLine.x2() ? lastLine.x1() : lastLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (lastLine.x1() < lastLine.x2() ? lastLine.p1() : lastLine.p2()));
					}
					else {
						if (intersectionPt.y() > (lastLine.y1() > lastLine.y2() ? lastLine.y1() : lastLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (lastLine.y1() > lastLine.y2() ? lastLine.p1() : lastLine.p2()));
						}
						else if (intersectionPt.y() < (lastLine.y1() < lastLine.y2() ? lastLine.y1() : lastLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (lastLine.y1() < lastLine.y2() ? lastLine.p1() : lastLine.p2()));
						}
					}

					if (intersectionPt.x() > (curLine.x1() > curLine.x2() ? curLine.x1() : curLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (curLine.x1() > curLine.x2() ? curLine.p1() : curLine.p2()));
					}
					else if (intersectionPt.x() < (curLine.x1() < curLine.x2() ? curLine.x1() : curLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (curLine.x1() < curLine.x2() ? curLine.p1() : curLine.p2()));
					}
					else {
						if (intersectionPt.y() > (curLine.y1() > curLine.y2() ? curLine.y1() : curLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (curLine.y1() > curLine.y2() ? curLine.p1() : curLine.p2()));
						}
						else if (intersectionPt.y() < (curLine.y1() < curLine.y2() ? curLine.y1() : curLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (curLine.y1() < curLine.y2() ? curLine.p1() : curLine.p2()));
						}
					}
				}
				else {
					QString data = QString("0");    //显示角度
					pen.setWidth(1);
					painter.drawText(lastLine.x1() + 5, lastLine.y1() - 5, data);
				}
			}
		}
		//平行度
		else if (m_clickedBtn == on_parallelismBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!curLine.isNull() && lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				lastLine = curLine;
			}
			else if (!lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				painter.drawLine(lastLine);
				QString data = QString("%1mm").arg(parrallelism/m_ZoomValue);    //显示平行度
				pen.setWidth(1);
				pen.setColor(QColor(Qt::red));
				painter.setPen(pen);
				painter.drawText(lastLine.x1() + 5, lastLine.y1() - 5, data);

			}
		}
		//同轴度
		else if (m_clickedBtn == on_axialityBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!verCtrLineStartPt.isNull() && lastVerCtrLineStartPt.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(verCtrLineStartPt, verCtrLineEndPt);
				painter.drawLine(horCtrLineStartPt, horCtrLineEndPt);
				lastVerCtrLineStartPt = verCtrLineStartPt;
				lastVerCtrLineEndPt = verCtrLineEndPt;
				lastHorCtrLineStartPt = horCtrLineStartPt;
				lastHorCtrLineEndPt = horCtrLineEndPt;
			}
			else if (!lastVerCtrLineStartPt.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(verCtrLineStartPt, verCtrLineEndPt);
				painter.drawLine(horCtrLineStartPt, horCtrLineEndPt);
				painter.drawLine(lastVerCtrLineStartPt, lastVerCtrLineEndPt);
				painter.drawLine(lastHorCtrLineStartPt, lastHorCtrLineEndPt);
				vector<double> verDis, horDis;
				if (verCtrLineStartPt.x() == lastVerCtrLineStartPt.x() && verCtrLineStartPt.x() == lastVerCtrLineEndPt.x()) {
					if (verCtrLineEndPt.x() == lastVerCtrLineStartPt.x() && verCtrLineEndPt.x() == lastVerCtrLineEndPt.x()) {
						VerAxiality = 0;
					}
					else {
						VerAxiality = ratio*(abs(verCtrLineEndPt.x()- lastVerCtrLineStartPt.x()));
					}
				}
				else if (verCtrLineEndPt.x() == lastVerCtrLineStartPt.x() && verCtrLineEndPt.x() == lastVerCtrLineEndPt.x()) {
					if (verCtrLineStartPt.x() == lastVerCtrLineStartPt.x() && verCtrLineStartPt.x() == lastVerCtrLineEndPt.x()) {
						VerAxiality = 0;
					}
					else {
						VerAxiality = ratio * (abs(verCtrLineStartPt.x())- lastVerCtrLineStartPt.x());
					}
				}
				else {
					verDis.push_back(abs(verCtrLineEndPt.x() - lastVerCtrLineStartPt.x()));
					verDis.push_back(abs(verCtrLineStartPt.x()) - lastVerCtrLineStartPt.x());
					auto maxVer = max_element(verDis.begin(), verDis.end());
					VerAxiality = ratio * (*maxVer);
				}

				if (horCtrLineStartPt.y() == lastHorCtrLineStartPt.y() && horCtrLineStartPt.y() == lastHorCtrLineEndPt.y()) {
					if (horCtrLineEndPt.y() == lastHorCtrLineStartPt.y() && horCtrLineEndPt.y() == lastHorCtrLineEndPt.y()) {
						HorAxiality = 0;
					}
					else {
						HorAxiality = ratio * (abs(horCtrLineEndPt.y()- lastHorCtrLineStartPt.y()));
					}
				}
				else if (horCtrLineEndPt.y() == lastHorCtrLineStartPt.y() && horCtrLineEndPt.y() == lastHorCtrLineEndPt.y()) {
					if (horCtrLineStartPt.y() == lastHorCtrLineStartPt.y() && horCtrLineStartPt.y() == lastHorCtrLineEndPt.y()) {
						HorAxiality = 0;
					}
					else {
						HorAxiality = ratio * (abs(horCtrLineStartPt.y()- lastHorCtrLineStartPt.y()));
					}
				}
				else {
					horDis.push_back(abs(horCtrLineEndPt.y() - lastHorCtrLineStartPt.y()));
					horDis.push_back(abs(horCtrLineStartPt.y() - lastHorCtrLineStartPt.y()));
					auto maxHor = max_element(horDis.begin(), horDis.end());
					HorAxiality = ratio * (*maxHor);
				}

				QString verdata = QString("%1mm").arg(VerAxiality/m_ZoomValue);    //显示同轴度
				QString hordata = QString("%1mm").arg(HorAxiality/m_ZoomValue);    //显示同轴度
				pen.setWidth(1);
				pen.setColor(QColor(Qt::red));
				painter.setPen(pen);
				painter.drawText(verCtrLineStartPt.x() + 5, verCtrLineStartPt.y() - 5, verdata);
				painter.drawText(horCtrLineStartPt.x() + 5, horCtrLineStartPt.y() - 5, hordata);

			}
		}
		//垂直度
		else if (m_clickedBtn == on_perpendicularityBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!curLine.isNull() && lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				lastLine = curLine;
			}
			else if (!lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				painter.drawLine(lastLine);
				pen.setColor(QColor(Qt::red));
				painter.setPen(pen);
				painter.drawPoint(intersectionPt);
				QString data = QString("%1mm").arg(perpendicularity/m_ZoomValue);    //显示垂直度
				pen.setWidth(1);
				painter.drawText(lastLine.x1() + 5, lastLine.y1() - 5, data);
				//延长虚线
				pen.setWidth(2);
				painter.setPen(pen);
				if (Parallel == -1) { //判断是否平行
					if (intersectionPt.x() > (lastLine.x1() > lastLine.x2() ? lastLine.x1() : lastLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (lastLine.x1() > lastLine.x2() ? lastLine.p1() : lastLine.p2()));
					}
					else if (intersectionPt.x() < (lastLine.x1() < lastLine.x2() ? lastLine.x1() : lastLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (lastLine.x1() < lastLine.x2() ? lastLine.p1() : lastLine.p2()));
					}
					else {
						if (intersectionPt.y() > (lastLine.y1() > lastLine.y2() ? lastLine.y1() : lastLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (lastLine.y1() > lastLine.y2() ? lastLine.p1() : lastLine.p2()));
						}
						else if (intersectionPt.y() < (lastLine.y1() < lastLine.y2() ? lastLine.y1() : lastLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (lastLine.y1() < lastLine.y2() ? lastLine.p1() : lastLine.p2()));
						}
					}

					if (intersectionPt.x() > (curLine.x1() > curLine.x2() ? curLine.x1() : curLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (curLine.x1() > curLine.x2() ? curLine.p1() : curLine.p2()));
					}
					else if (intersectionPt.x() < (curLine.x1() < curLine.x2() ? curLine.x1() : curLine.x2())) {
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						painter.drawLine(intersectionPt, (curLine.x1() < curLine.x2() ? curLine.p1() : curLine.p2()));
					}
					else {
						if (intersectionPt.y() > (curLine.y1() > curLine.y2() ? curLine.y1() : curLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (curLine.y1() > curLine.y2() ? curLine.p1() : curLine.p2()));
						}
						else if (intersectionPt.y() < (curLine.y1() < curLine.y2() ? curLine.y1() : curLine.y2())) {
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							painter.drawLine(intersectionPt, (curLine.y1() < curLine.y2() ? curLine.p1() : curLine.p2()));
						}
					}
				}
			}
		}
		//线线距离
		else if (m_clickedBtn == on_linlindisBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!curLine.isNull() && lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				lastLine = curLine;
			}
			else if (!lastLine.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(curLine);
				painter.drawLine(lastLine);
				//footPoint = calculate_foot_point(lastLine.center(), curLine.p1(), curLine.p2());
				pen.setColor(QColor(Qt::red));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawPoint(lastLine.center());
				if (!footPoint.isNull()) {
					pen.setColor(QColor(Qt::red));
					pen.setWidth(1);
					painter.setPen(pen);
					painter.drawLine(lastLine.center(), footPoint);
					//num = ratio * sqrtf(powf((lastLine.center().x() - footPoint.x()), 2) + powf((lastLine.center().y() - footPoint.y()), 2));
					num = ratio * calculate_distance(lastLine.center(), curLine.p1(), curLine.p2());
					QString data = QString("%1mm").arg(num/m_ZoomValue);    //显示距离num
					painter.drawText((lastLine.center().x() + footPoint.x()) / 2, (lastLine.center().y() + footPoint.y()) / 2, data);

					// 画延长虚线
					p1 = curLine.p1().x() > curLine.p2().x() ? curLine.p2() : curLine.p1();
					p2 = curLine.p1().x() > curLine.p2().x() ? curLine.p1() : curLine.p2();
					if (footPoint.x() < p1.x())
					{
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						pen.setWidth(1);
						painter.setPen(pen);
						painter.drawLine(footPoint, p1);
						pp = p1;
					}
					else if (footPoint.x() > p2.x())
					{
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						pen.setWidth(1);
						painter.setPen(pen);
						painter.drawLine(footPoint, p2);
						pp = p2;
					}
					else
					{
						p1 = curLine.p1().y() > curLine.p2().y() ? curLine.p2() : curLine.p1();
						p2 = curLine.p1().y() > curLine.p2().y() ? curLine.p1() : curLine.p2();
						if (footPoint.y() < p1.y())
						{
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							pen.setWidth(1);
							painter.setPen(pen);
							painter.drawLine(footPoint, p1);
							pp = p1;
						}
						else if (footPoint.y() > p2.y())
						{
							QVector<qreal> dashes;
							qreal space = 3;
							dashes << 5 << space << 5 << space;
							pen.setDashPattern(dashes);
							pen.setWidth(1);
							painter.setPen(pen);
							painter.drawLine(footPoint, p2);
							pp = p2;
						}
					}
				}
			}
		}
		//圆圆切点
		else if (m_clickedBtn == on_circirtanBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!curCirCenter.isNull() && lastCirCenter.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(3);
				painter.setPen(pen);
				painter.drawEllipse(curCirCenter.x() - curCirRadius, curCirCenter.y() - curCirRadius, 2 * curCirRadius, 2 * curCirRadius);
				pen.setWidth(6);
				pen.setColor(Qt::red); // 设置画笔为红色
				painter.setPen(pen); // 设置画笔
				painter.drawPoint(curCirCenter.x(), curCirCenter.y());
				lastCirCenter = curCirCenter;
				lastCirRadius = curCirRadius;
			}
			else if (!lastCirCenter.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(3);
				painter.setPen(pen);
				painter.drawEllipse(curCirCenter.x() - curCirRadius, curCirCenter.y() - curCirRadius, 2 * curCirRadius, 2 * curCirRadius);
				painter.drawEllipse(lastCirCenter.x() - lastCirRadius, lastCirCenter.y() - lastCirRadius, 2 * lastCirRadius, 2 * lastCirRadius);
				pen.setWidth(6);
				pen.setColor(Qt::red); // 设置画笔为红色
				painter.setPen(pen); // 设置画笔
				painter.drawPoint(curCirCenter.x(), curCirCenter.y());
				painter.drawPoint(lastCirCenter.x(), lastCirCenter.y());
				CenterDis = sqrt(pow(curCirCenter.x() - lastCirCenter.x(), 2) + pow(curCirCenter.y() - lastCirCenter.y(), 2));
				
				//判断是否两圆相切
				if (abs(CenterDis - abs(curCirRadius - lastCirRadius)) <= 5 || abs(CenterDis - curCirRadius - lastCirRadius) <= 5) {
					//内切    //利用几何知识进行切点坐标的定位（比值）
					if (abs(CenterDis - abs(curCirRadius - lastCirRadius)) <= 5) {
						if (curCirRadius > lastCirRadius) {
							CirTanPt.setX((curCirRadius / abs(curCirRadius - lastCirRadius)) * (lastCirCenter.x() - curCirCenter.x()) + curCirCenter.x());
							CirTanPt.setY((curCirRadius / abs(curCirRadius - lastCirRadius)) * (lastCirCenter.y() - curCirCenter.y()) + curCirCenter.y());

						}
						else if (curCirRadius < lastCirRadius) {
							CirTanPt.setX((lastCirRadius / abs(curCirRadius - lastCirRadius)) * (curCirCenter.x() - lastCirCenter.x()) + lastCirCenter.x());
							CirTanPt.setY((lastCirRadius / abs(curCirRadius - lastCirRadius)) * (curCirCenter.y() - lastCirCenter.y()) + lastCirCenter.y());
						}
					}
					//外切
					else if (abs(CenterDis - curCirRadius - lastCirRadius) <= 5) {
						CirTanPt.setX((curCirRadius / (curCirRadius + lastCirRadius))* (lastCirCenter.x() - curCirCenter.x()) + curCirCenter.x());
						CirTanPt.setY((curCirRadius / (curCirRadius + lastCirRadius))* (lastCirCenter.y() - curCirCenter.y()) + curCirCenter.y());
					}
				}
				
				pen.setWidth(10);
				pen.setColor(Qt::yellow); // 设置画笔为红色
				painter.setPen(pen); // 设置画笔
				painter.drawPoint(CirTanPt);
			}
		}
		//圆圆距离
		else if (m_clickedBtn == on_circirdisBtn_clicked) {
			QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
			QPainter painter(this);
			QPen pen;
			pen.setColor(QColor(Qt::red));
			pen.setWidth(1);
			painter.setPen(pen);
			m_currentSelectRect = getSelectRect();
			painter.drawRect(m_currentSelectRect);
			if (!curCirCenter.isNull() && lastCirCenter.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(3);
				painter.setPen(pen);
				painter.drawEllipse(curCirCenter.x() - curCirRadius, curCirCenter.y() - curCirRadius, 2 * curCirRadius, 2 * curCirRadius);
				pen.setWidth(6);
				pen.setColor(Qt::red); // 设置画笔为红色
				painter.setPen(pen); // 设置画笔
				painter.drawPoint(curCirCenter.x(), curCirCenter.y());
				lastCirCenter = curCirCenter;
				lastCirRadius = curCirRadius;
			}
			else if (!lastCirCenter.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(3);
				painter.setPen(pen);
				painter.drawEllipse(curCirCenter.x() - curCirRadius, curCirCenter.y() - curCirRadius, 2 * curCirRadius, 2 * curCirRadius);
				painter.drawEllipse(lastCirCenter.x() - lastCirRadius, lastCirCenter.y() - lastCirRadius, 2 * lastCirRadius, 2 * lastCirRadius);
				pen.setWidth(6);
				pen.setColor(Qt::red); // 设置画笔为红色
				painter.setPen(pen); // 设置画笔
				painter.drawPoint(curCirCenter.x(), curCirCenter.y());
				painter.drawPoint(lastCirCenter.x(), lastCirCenter.y());
				CenterDis = ratio * sqrt(pow(curCirCenter.x() - lastCirCenter.x(), 2) + pow(curCirCenter.y() - lastCirCenter.y(), 2));
				pen.setWidth(1);
				pen.setColor(Qt::red); // 设置画笔为红色
				painter.setPen(pen); // 设置画笔
				painter.drawLine(curCirCenter, lastCirCenter);
				QString data = QString("%1mm").arg(CenterDis/m_ZoomValue);    //显示距离num
				painter.drawText((curCirCenter.x() + lastCirCenter.x()) / 2, (curCirCenter.y() + lastCirCenter.y()) / 2, data);
			}
		}
		
		






	}
	else if(m_Mode == ELEMENT) {
		QLabel::paintEvent(event);//必须有，才能让背景图片显示出来
		QPainter painter(this);
		QPen pen;
		pen.setColor(QColor(Qt::red));
		pen.setWidth(1);
		painter.setPen(pen);
		//painter.drawRect(QRect(StartPoint.x(), StartPoint.y(), EndPoint.x() - StartPoint.x(), EndPoint.y() - StartPoint.y()));


		m_currentSelectRect = getSelectRect();

		switch (m_currentCaptureState)
		{
		case initCapture:
			break;
		case beginCaptureImage:
			painter.drawRect(m_currentSelectRect);
		case finishCaptureImage:
			painter.drawRect(m_currentSelectRect);
		case beginMoveCaptureArea:
			painter.drawRect(m_currentSelectRect);
		case finishMoveCaptureArea:
			painter.drawRect(m_currentSelectRect);
		default:
			break;
		}
		if (m_clickedBtn == on_lineBtn_clicked) {
			if (!lineStartPoint.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawLine(lineStartPoint, lineEndPoint);
			}
		}
		else if (m_clickedBtn == on_linmidBtn_clicked) {
			if (!lineStartPoint.isNull()) {
				pen.setColor(QColor(Qt::blue));
				pen.setWidth(5);
				painter.setPen(pen);
				painter.drawLine(lineStartPoint, lineEndPoint);
				pen.setColor(QColor(Qt::red));
				pen.setWidth(6);
				painter.setPen(pen);
				painter.drawPoint((lineStartPoint.x() + lineEndPoint.x()) / 2, (lineStartPoint.y() + lineEndPoint.y()) / 2);
			}
		}
		else if (m_clickedBtn == on_circleBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x() - ArcRadius*m_ZoomValue, 
				ArcCenter.y() - ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue,
				2 * ArcRadius * m_ZoomValue);
			pen.setWidth(6);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
		}
		else if (m_clickedBtn == on_radiusBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x() - ArcRadius * m_ZoomValue, 
				ArcCenter.y() - ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue);
			pen.setWidth(6);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
			pen.setWidth(1); painter.setPen(pen);
			QPoint tempPt; tempPt.setX(ArcCenter.x() + ArcRadius); tempPt.setY(ArcCenter.y());
			painter.drawLine(ArcCenter, tempPt);
			QString data = QString("%1mm").arg(ratio * scaled_ratio *ArcRadius);    //显示半径
			painter.drawText((ArcCenter.x() + tempPt.x()) / 2, (ArcCenter.y() + tempPt.y()) / 2, data);
		}
		else if (m_clickedBtn == on_diameterBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x() - ArcRadius * m_ZoomValue, 
				ArcCenter.y() - ArcRadius * m_ZoomValue,
				2 * ArcRadius * m_ZoomValue,
				2 * ArcRadius * m_ZoomValue);
			pen.setWidth(6);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
			pen.setWidth(1); painter.setPen(pen);
			QPoint Pt1,Pt2; 
			Pt1.setX(ArcCenter.x() + ArcRadius); Pt1.setY(ArcCenter.y());
			Pt2.setX(ArcCenter.x() - ArcRadius); Pt2.setY(ArcCenter.y());
			painter.drawLine(Pt1, Pt2);
			QString data = QString("%1mm").arg(ratio * 2* scaled_ratio * ArcRadius);    //显示直径
			painter.drawText((Pt1.x() + Pt2.x()) / 2, (Pt1.y() + Pt2.y()) / 2 - 2, data);
		}
		else if (m_clickedBtn == on_arcBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x()- ArcRadius * m_ZoomValue, 
				ArcCenter.y()- ArcRadius * m_ZoomValue, 
				2*ArcRadius * m_ZoomValue, 
				2*ArcRadius * m_ZoomValue);
			pen.setWidth(4);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
		}
		else if (m_clickedBtn == on_chamferBtn_clicked) {
			pen.setWidth(4);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawLine(chamfer);
		}
		else if (m_clickedBtn == on_roundnessBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x() - ArcRadius * m_ZoomValue, 
				ArcCenter.y() - ArcRadius * m_ZoomValue,
				2 * ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue);
			pen.setWidth(4);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
			QString data = QString("%1mm").arg(roundness/m_ZoomValue);    //显示圆度
			painter.drawText(ArcCenter.x()+5, ArcCenter.y()-5, data);
		}
		else if (m_clickedBtn == on_arcAngleBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x() - ArcRadius * m_ZoomValue,
				ArcCenter.y() - ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue);
			pen.setWidth(4);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
			pen.setWidth(1); 
			painter.setPen(pen);
			painter.drawLine(ArcCenter, ArcLinTan0);
			painter.drawLine(ArcCenter, ArcLinTan1);
			QString data = QString("%1").arg(ArcAngle);    //显示角度
			painter.drawText(ArcCenter.x() + 3, ArcCenter.y() - 3, data);
		}
		else if (m_clickedBtn == on_arcmidBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x() - ArcRadius * m_ZoomValue,
				ArcCenter.y() - ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue);
			pen.setWidth(4);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
			painter.drawPoint(ArcMid.x(), ArcMid.y());
		}
		else if (m_clickedBtn == on_cirlintanBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(2);
			painter.setPen(pen);
			painter.drawEllipse(ArcCenter.x() - ArcRadius * m_ZoomValue, 
				ArcCenter.y() - ArcRadius * m_ZoomValue, 
				2 * ArcRadius * m_ZoomValue,
				2 * ArcRadius * m_ZoomValue);
			pen.setWidth(4);
			pen.setColor(Qt::red); // 设置画笔为红色
			painter.setPen(pen); // 设置画笔
			painter.drawPoint(ArcCenter.x(), ArcCenter.y());
			painter.drawPoint(ArcLinTan0.x(), ArcLinTan0.y());
			painter.drawPoint(ArcLinTan1.x(), ArcLinTan1.y());
		}
		else if (m_clickedBtn == on_peakLinBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(4);
			painter.setPen(pen);
			painter.drawLine(leftPeakLineStartPt, leftPeakLineEndPt);
			painter.drawLine(rightPeakLineStartPt, rightPeakLineEndPt);
		}
		else if (m_clickedBtn == on_ctrLinBtn_clicked) {
			pen.setColor(QColor(Qt::blue));
			pen.setWidth(4);
			painter.setPen(pen);
			painter.drawLine(verCtrLineStartPt, verCtrLineEndPt);
			painter.drawLine(horCtrLineStartPt, horCtrLineEndPt);
		}
	}
}



//鼠标按下
void myLabel::mousePressEvent(QMouseEvent* e)
{
	if (m_Mode == SCALE) {
		m_OldPos = e->pos();
		m_Pressed = true;
	}
	if (m_Mode == CUSTOMARC) {
		if (m_Pixmap.isNull()) {
			QtWidgetsApplication1 Qt;
			Qt.NoPhoto_Dialog();
		}
		else if (ArcPt0.isNull() && ArcPt1.isNull() && ArcPt2.isNull()){
			ArcPt0 = e->pos();
			update();
		}
		else if (ArcPt1.isNull() && ArcPt2.isNull()) {
			ArcPt1 = e->pos();
			update();
		}
		
	}
	if (m_Mode == MEASURE) {
		if (m_Pixmap.isNull()) {
			QtWidgetsApplication1 Qt;
			Qt.NoPhoto_Dialog();
		}
		else {
			StartPoint = e->pos();
			EndPoint = e->pos();
			setCursor(Qt::ArrowCursor);   //改变光标形状
			//发送开始位置坐标信号给主窗体
			emit StartPointSignal(StartPoint);
			m_currentCaptureState = beginCaptureImage;
		}
	}
	else {
		if (m_Pixmap.isNull()) {
			QtWidgetsApplication1 Qt;
			Qt.NoPhoto_Dialog();
		}
		else {
			//设置按下flag为true
			isPressed = true;
			if (m_currentCaptureState == initCapture)
			{
				StartPoint = e->pos();
				//EndPoint = e->pos();
				setCursor(Qt::ArrowCursor);   //改变光标形状
				//发送开始位置坐标信号给主窗体
				emit StartPointSignal(StartPoint);
				//    qDebug()<<"开始"<<StartPoint;
				m_currentCaptureState = beginCaptureImage;
			}
			/*
			else if (isPressPointInSelectRect(e->pos()))//在矩形内框区域时按下鼠标，则可拖动图片
			{
				m_startMovePoint = e->pos();
				setCursor(Qt::SizeAllCursor);   //改变光标形状,手的形状
				emit StartMoveRectSignal(getSelectRect());
				m_currentCaptureState = beginMoveCaptureArea;
				//m_endMovePoint = e->pos();
				//emit MoveRectSignal(m_endMovePoint);
				//update();
			}*/

			else {
				StartPoint = e->pos();
				EndPoint = e->pos();
				setCursor(Qt::ArrowCursor);   //改变光标形状
				//发送开始位置坐标信号给主窗体
				emit StartPointSignal(StartPoint);
				m_currentCaptureState = beginCaptureImage;
				//    qDebug()<<"开始"<<StartPoint;
			}

		}
	}
}

//鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent* e)
{
	if (m_Mode == SCALE) {
		if (!m_Pressed)
			return QWidget::mouseMoveEvent(e);

		setCursor(Qt::SizeAllCursor);
		QPoint pos = e->pos();
		int xPtInterval = pos.x() - m_OldPos.x();
		int yPtInterval = pos.y() - m_OldPos.y();

		m_XPtInterval += xPtInterval;
		m_YPtInterval += yPtInterval;

		m_OldPos = pos;
		update();
	}
	if (m_Mode == CUSTOMARC) {
		if (!ArcPt0.isNull() && !ArcPt1.isNull()) {
			temp = e->pos();
			Arc = findCircle(ArcPt0, ArcPt1, temp);
			StartAngle = cal_angle(ArcPt0, Arc.center, QPointF(Arc.center.x() + 10, Arc.center.y()));
			if (ArcPt0.y() > Arc.center.y()) {
				StartAngle = -StartAngle;
			}
			ArcAngle = cal_angle(ArcPt0, Arc.center, temp);
			
			if (int(ArcAngle) != int(cal_angle(ArcPt1, Arc.center, temp)+ cal_angle(ArcPt0, Arc.center, ArcPt1))) {
				ArcAngle = 360 - ArcAngle;
				//ArcAngle = -ArcAngle;
			}
			//矢量叉积判断是逆时针还是顺时针
			clockwise = (ArcPt1.x() - ArcPt0.x()) * (temp.y() - ArcPt0.y())
				- (ArcPt1.y() - ArcPt0.y()) * (temp.x()-ArcPt0.x()); 
			if (clockwise > 0) {
				ArcAngle = -ArcAngle;
			}
			/*
			if (Arc.center.y()> ArcPt1.y()) {
				ArcAngle = -ArcAngle;
			}*/
			update();
		}
	}
	if (m_Mode == MEASURE) {
		EndPoint = e->pos();
		//发送结束位置坐标信号给主窗体
		emit StopPointSignal(EndPoint);
		update();//更新label显示 调用paintEvent事件
		
	}
	else {
		// 根据鼠标是否在选中区域内设置鼠标样式;
		if (isPressPointInSelectRect(e->pos()))
		{
			setCursor(Qt::SizeAllCursor);
		}
		else if (!isPressPointInSelectRect(e->pos()) && m_currentCaptureState != beginMoveCaptureArea)
		{
			setCursor(Qt::ArrowCursor);
		}

		if (m_currentCaptureState == beginCaptureImage)
		{
			//获得结束点的坐标
			EndPoint = e->pos();
			//发送结束位置坐标信号给主窗体
			emit StopPointSignal(EndPoint);
			update();//更新label显示 调用paintEvent事件
			//      qDebug()<<"按下移动"<<EndPoint;
		}
		else if (m_currentCaptureState == beginMoveCaptureArea)
		{
			m_endMovePoint = e->pos();
			emit StartMoveRectSignal(getSelectRect());
			update();
		}
	}
}

//鼠标抬起
void myLabel::mouseReleaseEvent(QMouseEvent* e)
{
	isPressed = false;
	if (m_Mode == SCALE) {
		m_Pressed = false;
		setCursor(Qt::ArrowCursor);
	}
	else if (m_Mode == CUSTOMARC) {
		ArcPt2 = temp;
		if (!ArcPt2.isNull()) {
			m_currentCaptureState = finishCaptureImage;
			//update();
			temp = QPoint(0, 0);
			/*
			ArcAngle = cal_angle(ArcPt0, Arc.center, ArcPt2);
			if (Arc.center.y() > ArcPt1.y()) {
				ArcAngle = -ArcAngle;
			}*/
			Detect detect(this);
			dx0 = (abs(ArcPt0.x() - Arc.center.x()) * dr / Arc.radius) * scaled_ratio / m_ZoomValue;
			dy0 = (abs(ArcPt0.y() - Arc.center.y()) * dr / Arc.radius) * scaled_ratio / m_ZoomValue;
			dx1 = (abs(ArcPt2.x() - Arc.center.x()) * dr / Arc.radius) * scaled_ratio / m_ZoomValue;
			dy1 = (abs(ArcPt2.y() - Arc.center.y()) * dr / Arc.radius) * scaled_ratio / m_ZoomValue;
			
			if (abs(ArcAngle) <= 180) {
				if (ArcPt0.y() <= ArcPt2.y() && ArcPt0.x() <= ArcPt2.x()) {
					if (Arc.center.x() - Arc.radius < ArcPt0.x() && Arc.center.x() > ArcPt0.x() && Arc.center.y() > min(ArcPt0.y(),ArcPt2.y()) && Arc.center.y() < max(ArcPt0.y(), ArcPt2.y())) {
						cv_rect.x = scaled_ratio *
							((Arc.center.x() - Arc.radius - dr - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt2.x() - Arc.center.x() + Arc.radius + dr + dx1) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt2.y() - ArcPt0.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.x() + Arc.radius > ArcPt2.x() && Arc.center.x() < ArcPt0.x() && Arc.center.y() > min(ArcPt0.y(), ArcPt2.y()) && Arc.center.y() < max(ArcPt0.y(), ArcPt2.y())) {
						cv_rect.x = scaled_ratio *
							((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (Arc.center.x() + Arc.radius - ArcPt0.x() + dr + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt2.y() - ArcPt0.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.y() - Arc.radius < ArcPt0.y() && Arc.center.y() > ArcPt0.y() && Arc.center.x() > min(ArcPt0.x(), ArcPt2.x()) && Arc.center.x() < max(ArcPt0.x(), ArcPt2.x())) {
						cv_rect.x = scaled_ratio *
							((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((Arc.center.y() - Arc.radius - dr - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt2.x() - ArcPt0.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt2.y() - Arc.center.y() + Arc.radius + dr + dy1) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.y() + Arc.radius > ArcPt2.y() && Arc.center.y() < ArcPt2.y() && Arc.center.x() > min(ArcPt0.x(), ArcPt2.x()) && Arc.center.x() < max(ArcPt0.x(), ArcPt2.x())) {
						cv_rect.x = scaled_ratio *
							((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt2.x() - ArcPt0.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (Arc.center.y() + Arc.radius - ArcPt0.y() + dr + dy0) * scaled_ratio / m_ZoomValue;
					}
					else {
						cv_rect.x = scaled_ratio *
							((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt2.x() - ArcPt0.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt2.y() - ArcPt0.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
				}
				else if (ArcPt0.y() >= ArcPt2.y() && ArcPt0.x() >= ArcPt2.x()) {
					if (Arc.center.x() - Arc.radius < ArcPt2.x() && Arc.center.x() > ArcPt2.x() && Arc.center.y() > min(ArcPt0.y(), ArcPt2.y()) && Arc.center.y() < max(ArcPt0.y(), ArcPt2.y())) {
						cv_rect.x = scaled_ratio *
							((Arc.center.x() - Arc.radius - dr - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt0.x() - Arc.center.x() + Arc.radius + dr + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt0.y() - ArcPt2.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.x() + Arc.radius > ArcPt0.x() && Arc.center.x() < ArcPt0.x() && Arc.center.y() > min(ArcPt0.y(), ArcPt2.y()) && Arc.center.y() < max(ArcPt0.y(), ArcPt2.y())) {
						cv_rect.x = scaled_ratio *
							((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (Arc.center.x() + Arc.radius - ArcPt2.x() + dr + dx1) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt0.y() - ArcPt2.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.y() - Arc.radius < ArcPt2.y() && Arc.center.y() > ArcPt2.y() && Arc.center.x() > min(ArcPt0.x(), ArcPt2.x()) && Arc.center.x() < max(ArcPt0.x(), ArcPt2.x())) {
						cv_rect.x = scaled_ratio *
							((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((Arc.center.y() - Arc.radius - dr - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt0.x() - ArcPt2.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt0.y() - Arc.center.y() + Arc.radius + dr + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.y() + Arc.radius > ArcPt0.y() && Arc.center.y() < ArcPt0.y() && Arc.center.x() > min(ArcPt0.x(), ArcPt2.x()) && Arc.center.x() < max(ArcPt0.x(), ArcPt2.x())) {
						cv_rect.x = scaled_ratio *
							((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt0.x() - ArcPt2.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (Arc.center.y() + Arc.radius - ArcPt2.y() + dr + dy1) * scaled_ratio / m_ZoomValue;
					}
					else {
						cv_rect.x = scaled_ratio *
							((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt0.x() - ArcPt2.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt0.y() - ArcPt2.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
				}
				else if (ArcPt0.y() <= ArcPt2.y() && ArcPt0.x() >= ArcPt2.x()) {
					if (Arc.center.x() - Arc.radius < ArcPt2.x() && Arc.center.x() > ArcPt2.x() && Arc.center.y() > min(ArcPt0.y(), ArcPt2.y()) && Arc.center.y() < max(ArcPt0.y(), ArcPt2.y())) {
						cv_rect.x = scaled_ratio *
							((Arc.center.x() - Arc.radius - dr - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt0.x() - Arc.center.x() + Arc.radius + dr + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt2.y() - ArcPt0.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.x() + Arc.radius > ArcPt0.x() && Arc.center.x() < ArcPt0.x() && Arc.center.y() > min(ArcPt0.y(), ArcPt2.y()) && Arc.center.y() < max(ArcPt0.y(), ArcPt2.y())) {
						cv_rect.x = scaled_ratio *
							((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (Arc.center.x() + Arc.radius - ArcPt2.x() + dr + dx1) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt2.y() - ArcPt0.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.y() - Arc.radius < ArcPt0.y() && Arc.center.y() > ArcPt0.y() && Arc.center.x() > min(ArcPt0.x(), ArcPt2.x()) && Arc.center.x() < max(ArcPt0.x(), ArcPt2.x())) {
						cv_rect.x = scaled_ratio *
							((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((Arc.center.y() - Arc.radius - dr - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt0.x() - ArcPt2.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt2.y() - Arc.center.y() + Arc.radius + dr + dy1) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.y() + Arc.radius > ArcPt2.y() && Arc.center.y() < ArcPt2.y() && Arc.center.x() > min(ArcPt0.x(), ArcPt2.x()) && Arc.center.x() < max(ArcPt0.x(), ArcPt2.x())) {
						cv_rect.x = scaled_ratio *
							((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt0.x() - ArcPt2.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (Arc.center.y() + Arc.radius - ArcPt0.y() + dr + dy0) * scaled_ratio / m_ZoomValue;
					}
					else {
						cv_rect.x = scaled_ratio *
							((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt0.x() - ArcPt2.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt2.y() - ArcPt0.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
				}
				else if (ArcPt0.y() >= ArcPt2.y() && ArcPt0.x() <= ArcPt2.x()) {
				    if (Arc.center.x() - Arc.radius < ArcPt0.x() && Arc.center.x() > ArcPt0.x() && Arc.center.y() > min(ArcPt0.y(), ArcPt2.y()) && Arc.center.y() < max(ArcPt0.y(), ArcPt2.y())) {
						cv_rect.x = scaled_ratio *
							((Arc.center.x() - Arc.radius - dr - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt2.x() - Arc.center.x() + Arc.radius + dr + dx1) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt0.y() - ArcPt2.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.x() + Arc.radius > ArcPt2.x() && Arc.center.x() < ArcPt2.x() && Arc.center.y() > min(ArcPt0.y(), ArcPt2.y()) && Arc.center.y() < max(ArcPt0.y(), ArcPt2.y())) {
						cv_rect.x = scaled_ratio *
							((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (Arc.center.x() + Arc.radius - ArcPt0.x() + dr + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt0.y() - ArcPt2.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.y() - Arc.radius < ArcPt2.y() && Arc.center.y() > ArcPt2.y() && Arc.center.x() > min(ArcPt0.x(), ArcPt2.x()) && Arc.center.x() < max(ArcPt0.x(), ArcPt2.x())) {
						cv_rect.x = scaled_ratio *
							((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((Arc.center.y() - Arc.radius - dr - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt2.x() - ArcPt0.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt0.y() - Arc.center.y() + Arc.radius + dr + dy0) * scaled_ratio / m_ZoomValue;
					}
					else if (Arc.center.y() + Arc.radius > ArcPt0.y() && Arc.center.y() < ArcPt0.y() && Arc.center.x() > min(ArcPt0.x(), ArcPt2.x()) && Arc.center.x() < max(ArcPt0.x(), ArcPt2.x())) {
						cv_rect.x = scaled_ratio *
							((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt2.x() - ArcPt0.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (Arc.center.y() + Arc.radius - ArcPt2.y() + dr + dy1) * scaled_ratio / m_ZoomValue;
					}
					else {
						cv_rect.x = scaled_ratio *
							((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
						cv_rect.y = scaled_ratio *
							((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
						cv_rect.width = (ArcPt2.x() - ArcPt0.x() + dx1 + dx0) * scaled_ratio / m_ZoomValue;
						cv_rect.height = (ArcPt0.y() - ArcPt2.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
					}
				}
			}
			/*
			else if (abs(ArcAngle) >= 90 && abs(ArcAngle) <= 180)  {
				if (ArcPt0.y() <= ArcPt2.y() && ArcPt0.x() <= ArcPt2.x()) {
					cv_rect.x = scaled_ratio *
						((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
					cv_rect.y = scaled_ratio *
						((Arc.center.y() - Arc.radius - dr - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
					cv_rect.width = (Arc.center.x() + Arc.radius - ArcPt0.x() + dr + dx0) * scaled_ratio / m_ZoomValue;
					cv_rect.height = (ArcPt2.y() - Arc.center.y() + Arc.radius + dr + dy1) * scaled_ratio / m_ZoomValue;
				}
				else if (ArcPt0.y() >= ArcPt2.y() && ArcPt0.x() >= ArcPt2.x()) {
					cv_rect.x = scaled_ratio *
						((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
					cv_rect.y = scaled_ratio *
						((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
					cv_rect.width = (Arc.center.x() + Arc.radius - ArcPt2.x() + dx1 + dr) * scaled_ratio / m_ZoomValue;
					cv_rect.height = (ArcPt0.y() - ArcPt2.y() + dy1 + dy0) * scaled_ratio / m_ZoomValue;
				}
				else if (ArcPt0.y() <= ArcPt2.y() && ArcPt0.x() >= ArcPt2.x()) {
					cv_rect.x = scaled_ratio *
						((ArcPt2.x() - dx1 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
					cv_rect.y = scaled_ratio *
						((ArcPt0.y() - dy0 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
					cv_rect.width = (Arc.center.x() + Arc.radius - ArcPt2.x() + dx1 + dr) * scaled_ratio / m_ZoomValue;
					cv_rect.height = (Arc.center.y() + Arc.radius - ArcPt0.y() + dr + dy0) * scaled_ratio / m_ZoomValue;
				}
				else if (ArcPt0.y() >= ArcPt2.y() && ArcPt0.x() <= ArcPt2.x()) {
					cv_rect.x = scaled_ratio *
						((ArcPt0.x() - dx0 - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
					cv_rect.y = scaled_ratio *
						((ArcPt2.y() - dy1 - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
					cv_rect.width = (Arc.center.x() + Arc.radius - ArcPt0.x() + dr + dx0) * scaled_ratio / m_ZoomValue;
					cv_rect.height = (Arc.center.y() + Arc.radius - ArcPt2.y() + dy1 + dr) * scaled_ratio / m_ZoomValue;
				}

			}*/
			else if (abs(ArcAngle) > 180) {
				cv_rect.x = scaled_ratio *
					((Arc.center.x() - Arc.radius - dr - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
				cv_rect.y = scaled_ratio *
					((Arc.center.y() - Arc.radius - dr - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
				cv_rect.width = 2*(Arc.radius + dr) * scaled_ratio / m_ZoomValue;
				cv_rect.height = 2*(Arc.radius + dr) * scaled_ratio / m_ZoomValue;
			}

			if (cv_rect.x <= 0 || cv_rect.y <= 0 || cv_rect.x + cv_rect.width >= cv_src.cols || cv_rect.y + cv_rect.height >= cv_src.rows) {
				return;
			}
			else {
				cv_dst = cv_src(cv_rect).clone();
				detect.CustomArc(cv_dst);
				ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcRadius = detect.radius / scaled_ratio;

				CircleData circle;
				circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval, ArcCenter.y() / m_ZoomValue - m_YPtInterval);
				circle.radius = ArcRadius;
				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Circle.push_back(circle);
					//save parameter(int flag)
					SaveParameter(24, "SaveRect.txt");
					//clearRect();
					clearPoint();
					break;
				case QMessageBox::No:
					//clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
			
			update();
		}
	}
	else if (m_Mode == MEASURE) {
		
		if (m_clickedBtn == on_ptptdisBtn_clicked) {
			EndPoint = e->pos();
			update();
			getPt();    //画出点
			if (!lastPtPoint.isNull()) {
				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					ptptdis_Line.push_back(QLineF(PtPoint.x() / m_ZoomValue - m_XPtInterval,
						PtPoint.y() / m_ZoomValue - m_YPtInterval,
						lastPtPoint.x() / m_ZoomValue - m_XPtInterval,
						lastPtPoint.y() / m_ZoomValue - m_YPtInterval));
					ptptdis.push_back(num / m_ZoomValue);
					Point.push_back(QPointF(PtPoint.x() / m_ZoomValue - m_XPtInterval,
						PtPoint.y() / m_ZoomValue - m_YPtInterval));
					Point.push_back(QPointF(lastPtPoint.x() / m_ZoomValue - m_XPtInterval,
						lastPtPoint.y() / m_ZoomValue - m_YPtInterval));
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
		}
		else if (m_clickedBtn == on_ptlindisBtn_clicked){
			//EndPoint = e->pos();
			//update();
			if (lastPtPoint.isNull()) {
				EndPoint = e->pos();
				getPt();    //画出点
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}

		}
		else if (m_clickedBtn == on_intersectionBtn_clicked) {
			if (lastLine.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出线
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		else if (m_clickedBtn == on_linlinAngleBtn_clicked) {
			if (lastLine.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出线
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		else if (m_clickedBtn == on_taperBtn_clicked) {
			if (lastLine.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出线
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		else if (m_clickedBtn == on_axialityBtn_clicked) {
			if (lastVerCtrLineStartPt.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出线
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		else if (m_clickedBtn == on_parallelismBtn_clicked) {
			if (lastLine.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出线
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		else if (m_clickedBtn == on_perpendicularityBtn_clicked) {
			if (lastLine.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出线
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		else if (m_clickedBtn == on_linlindisBtn_clicked) {
			if (lastLine.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出线
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		else if (m_clickedBtn == on_circirtanBtn_clicked) {
			if (lastCirCenter.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出圆
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		else if (m_clickedBtn == on_circirdisBtn_clicked) {
			if (lastCirCenter.isNull()) {
				EndPoint = e->pos();
				getDistrict();    //画出圆
				update();
			}
			else {
				m_currentCaptureState = finishCaptureImage;
				EndPoint = e->pos();
				getDistrict();
				update();
			}
		}
		
	}
	else {
		if (m_currentCaptureState == beginCaptureImage)
		{
			m_currentCaptureState = finishCaptureImage;
			EndPoint = e->pos();
			//update();
			getDistrict();                //获取ROI
			update();
		}
		else if (m_currentCaptureState == beginMoveCaptureArea)
		{
			m_currentCaptureState = finishMoveCaptureArea;
			m_endMovePoint = e->pos();
			setCursor(Qt::ArrowCursor);   //改变光标形状
			update();
			getDistrict();                //获取ROI
		}
	}
}


void myLabel::SaveParameter(int flag, string strFileName) {
	// 定义/打开输出的txt文件
	ofstream out_txt_file;
	out_txt_file.open(strFileName, ios::out | ios::trunc);
	out_txt_file << fixed;
	if (flag == 24) {
		out_txt_file << setprecision(4) << flag  <<" "<< cv_rect.x << " " << cv_rect.y << " " << cv_rect.width << " "<< cv_rect .height<<endl;
	}
	if (flag == 2) {
		out_txt_file << setprecision(4) << flag  << " "<< cv_rect1[0].x << " " << cv_rect1[0].y << " " << cv_rect1[0].width << " " << cv_rect1[0].height << " " << cv_rect2.x << " " << cv_rect2.y << " " << cv_rect2.width << " " << cv_rect2.height << endl;
	}

	// 关闭文件
	out_txt_file.close();
}

int myLabel::LoadParameter(string strFileName) {
	/*
	// 定义/打开输入的txt文件
	ifstream in_txt_file;
	in_txt_file.open(strFileName, ios::in | ios::trunc);
	char temp[1024] = { 0 };
	//in_txt_file >> temp; //遇到空格输出停止，空格后的内容无法输出，'\0'是截止符
	in_txt_file.getline(temp, 8); //可以输出空格，遇到delim符号才截止。 最后一个参数0表示文本框遇到空字符（ASCLL码为32，文本框不可能有空字符）截止符。不加第三个参数0时，表示'\n'为截止符('\n'也是换行符)。
	*/
	ifstream fin(strFileName);
	string s;
	getline(fin, s);
	
		cout << " Read from file: " << s << endl;
		istringstream ss(s);
		vector<int> v;
		int i;
		while (ss >> i)
		{
			v.push_back(i);
		}
		if (v[0] == 24) {
			//如果是圆弧
			cv_rect.x = v[1];
			cv_rect.y = v[2];
			cv_rect.width = v[3];
			cv_rect.height = v[4];
			m_clickedBtn = on_customArcBtn_clicked;
			m_Mode = CUSTOMARC;
			m_currentCaptureState = finishCaptureImage;
			update();
		}
		cv_dst = cv_src(cv_rect).clone();
		return v[0];

	//in_txt_file.close();
}


// 当前鼠标坐标是否在选取的矩形区域内;
bool myLabel::isPressPointInSelectRect(QPointF mousePressPoint)
{
	QRectF selectRect = m_currentSelectRect;
	if (selectRect.contains(mousePressPoint))
	{
		return true;
	}
	return false;

}

// 根据beginPoint , endPoint 获取当前选中的矩形
QRectF myLabel::getRect(QPointF& startPoint, QPointF& endPoint)
{
	int x, y, width, height;
	width = qAbs(startPoint.x() - endPoint.x());
	height = qAbs(startPoint.y() - endPoint.y());
	x = startPoint.x() < endPoint.x() ? startPoint.x() : endPoint.x();
	y = startPoint.y() < endPoint.y() ? startPoint.y() : endPoint.y();
	

	//画框限制边界
	if (x + width - (this->width() / 2 - m_Pixmap.size().width() / 2) >= m_Pixmap.size().width()) {
		width = m_Pixmap.size().width() + (this->width() / 2 - m_Pixmap.size().width() / 2) - x-2;
	}
	if (y + height - (this->height() / 2 - m_Pixmap.size().height() / 2) >= m_Pixmap.size().height()) {
		height = m_Pixmap.size().height() + (this->height() / 2 - m_Pixmap.size().height() / 2) - y-2;
	}
	if (x - (this->width() / 2 - m_Pixmap.size().width() / 2) <= 0) {
		x = 2 + (this->width() / 2 - m_Pixmap.size().width() / 2); width = StartPoint.x() - (this->width() / 2 - m_Pixmap.size().width() / 2);
	}
	if (y - (this->height() / 2 - m_Pixmap.size().height() / 2) <= 0) {
		y = 2 + (this->height() / 2 - m_Pixmap.size().height() / 2); height = StartPoint.y() - (this->height() / 2 - m_Pixmap.size().height() / 2);
	}

	QRect selectedRect = QRect(x, y, width, height);
	// 避免宽或高为零时拷贝截图有误;
	// 可以看QQ截图，当选取截图宽或高为零时默认为10;
	if (selectedRect.width() == 0)
	{
		selectedRect.setWidth(10);
	}
	if (selectedRect.height() == 0)
	{
		selectedRect.setHeight(10);
	}

	return selectedRect;
}

// 获取移动后选中的矩形;
QRectF myLabel::getMoveRect()
{
	// 通过getMovePoint方法先检查当前是否移动超出屏幕;
	movePoint = getMovePoint();
	newStartPoint = StartPoint + movePoint;
	newEndPoint = EndPoint + movePoint;
	// 结束移动选区时更新当前StartPoint , EndPoint,防止下一次操作时截取的图片有问题;
	if (m_currentCaptureState == finishMoveCaptureArea)
	{
		StartPoint = newStartPoint;
		EndPoint = newEndPoint;
		m_startMovePoint = QPoint(0, 0);
		m_endMovePoint = QPoint(0, 0);
	}
	return getRect(newStartPoint, newEndPoint);
}

// 根据当前截取状态获取当前选中的截图区域;
QRectF myLabel::getSelectRect()
{
	if (m_currentCaptureState == beginMoveCaptureArea || m_currentCaptureState == finishMoveCaptureArea)
	{
		return getMoveRect();
	}
	else if (m_currentCaptureState == beginCaptureImage || m_currentCaptureState == finishCaptureImage)
	{
		return getRect(StartPoint, EndPoint);
	}

	return QRect(0, 0, 0, 0);
}

QPointF myLabel::getMovePoint()
{
	QPointF movePoint = m_endMovePoint - m_startMovePoint;
	QRectF currentRect = getRect(StartPoint,EndPoint);

	//
	//此处会导致移动矩形框时起点在鼠标位置

	//移动选区是否超出屏幕左边界;
	if (currentRect.topLeft().x() + movePoint.x() < 0)
	{
		movePoint.setX(0 - currentRect.topLeft().x());
	}
	//移动选区是否超出屏幕上边界;
	if (currentRect.topLeft().y() + movePoint.y() < 0)
	{
		movePoint.setY(0 - currentRect.topLeft().y());
	}
	//移动选区是否超出屏幕右边界;
	if (currentRect.bottomRight().x() + movePoint.x() > m_Pixmap.size().width())
	{
		movePoint.setX(m_Pixmap.size().width() - currentRect.bottomRight().x());
	}
	//移动选区是否超出屏幕下边界;
	if (currentRect.bottomRight().y() + movePoint.y() > m_Pixmap.size().height())
	{
		movePoint.setY(m_Pixmap.size().height() - currentRect.bottomRight().y());
	}
	

	return movePoint;
}


//得到圆的参数
CircleData myLabel::findCircle(QPointF pt1, QPointF pt2, QPointF pt3)
{
	//令：
	//A1 = 2 * pt2.x - 2 * pt1.x      B1 = 2 * pt1.y - 2 * pt2.y       C1 = pt1.y² + pt2.x² - pt1.x² - pt2.y²
	//A2 = 2 * pt3.x - 2 * pt2.x      B2 = 2 * pt2.y - 2 * pt3.y       C2 = pt2.y² + pt3.x² - pt2.x² - pt3.y²
	float A1, A2, B1, B2, C1, C2, temp;
	A1 = pt1.x() - pt2.x();
	B1 = pt1.y() - pt2.y();
	C1 = (pow(pt1.x(), 2) - pow(pt2.x(), 2) + pow(pt1.y(), 2) - pow(pt2.y(), 2)) / 2;
	A2 = pt3.x() - pt2.x();
	B2 = pt3.y() - pt2.y();
	C2 = (pow(pt3.x(), 2) - pow(pt2.x(), 2) + pow(pt3.y(), 2) - pow(pt2.y(), 2)) / 2;
	//为了方便编写程序，令temp = A1*B2 - A2*B1
	temp = A1 * B2 - A2 * B1;
	//定义一个圆的数据的结构体对象CD
	CircleData CD;
	//判断三点是否共线
	if (temp == 0) {
		//共线则将第一个点pt1作为圆心
		CD.center.setX(pt1.x());
		CD.center.setY(pt1.y());
	}
	else {
		//不共线则求出圆心：
		//center.x = (C1*B2 - C2*B1) / A1*B2 - A2*B1;
		//center.y = (A1*C2 - A2*C1) / A1*B2 - A2*B1;
		CD.center.setX((C1 * B2 - C2 * B1) / temp);
		CD.center.setY((A1 * C2 - A2 * C1) / temp);
	}

	CD.radius = sqrtf((CD.center.x() - pt1.x()) * (CD.center.x() - pt1.x()) + (CD.center.y() - pt1.y()) * (CD.center.y() - pt1.y()));
	return CD;
}


//获取交点
void myLabel::getPt()
{
	QtWidgetsApplication1 myQt;
	cv::destroyAllWindows();
	int x, y, width, height;
	width = qAbs(StartPoint.x() - EndPoint.x());
	height = qAbs(StartPoint.y() - EndPoint.y());
	x = StartPoint.x() < EndPoint.x() ? StartPoint.x() : EndPoint.x();
	y = StartPoint.y() < EndPoint.y() ? StartPoint.y() : EndPoint.y();
	cv_rect.x = scaled_ratio * ((x - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
	cv_rect.y = scaled_ratio * ((y - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
	//防止鼠标只点击了一下宽高都为0会报错
	if (width == 0 || height == 0) {
		cv_rect.width = 5;
		cv_rect.height = 5;
		width = 5;
		height = 5;
	}
	else {
		cv_rect.width = width * scaled_ratio / m_ZoomValue;
		cv_rect.height = height * scaled_ratio / m_ZoomValue;
	}
	//QRect selectedRect = QRect(x, y, width, height);
	//cv_src = myQt.QPixmapToCvMat(m_Pixmap, 0);
	//显示roi截图
	cv_dst = cv_src(cv_rect).clone();
	Detect detect(this);
	if (StartPoint.x() < EndPoint.x()) {
		if (StartPoint.y() < EndPoint.y()) {
			detect.detectPoint(cv_dst, cv::Point(2,2), cv::Point(cv_rect.width-2, cv_rect.height-2));//设为（2,2）为了防止判定为第一个点与边缘相交
			PtPoint.setX(((detect.pt.x+ scaled_ratio * ((StartPoint.x() - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval)) / scaled_ratio + m_XPtInterval)* m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2));
			PtPoint.setY(((detect.pt.y+ scaled_ratio * ((StartPoint.y() - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval)) / scaled_ratio + m_YPtInterval) * m_ZoomValue
				+ (this->height() / 2 - m_Pixmap.size().height() / 2));
			update();
		}
		else {
			detect.detectPoint(cv_dst, cv::Point(2, cv_rect.height-2), cv::Point(cv_rect.width-2, 2));
			PtPoint.setX(((detect.pt.x + scaled_ratio * ((StartPoint.x() - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval)) / scaled_ratio + m_XPtInterval) * m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2));
			PtPoint.setY(((detect.pt.y + scaled_ratio * ((StartPoint.y() - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval)) / scaled_ratio + m_YPtInterval) * m_ZoomValue
				+ (this->height() / 2 - m_Pixmap.size().height() / 2) -height);
			update();
		}
	}
	else {
		if (StartPoint.y() < EndPoint.y()) {
			detect.detectPoint(cv_dst, cv::Point(cv_rect.width-2,2), cv::Point(1, cv_rect.height-2));
			PtPoint.setX(((detect.pt.x + scaled_ratio * ((StartPoint.x() - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval)) / scaled_ratio + m_XPtInterval) * m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2) -width);
			PtPoint.setY(((detect.pt.y + scaled_ratio * ((StartPoint.y() - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval)) / scaled_ratio + m_YPtInterval) * m_ZoomValue
				+ (this->height() / 2 - m_Pixmap.size().height() / 2));
			update();
		}
		else {
			detect.detectPoint(cv_dst, cv::Point(cv_rect.width-2, cv_rect.height-2), cv::Point(2, 2));
			PtPoint.setX(((detect.pt.x + scaled_ratio * ((EndPoint.x() - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval)) / scaled_ratio + m_XPtInterval) * m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2));
			PtPoint.setY(((detect.pt.y + scaled_ratio * ((EndPoint.y() - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval)) / scaled_ratio + m_YPtInterval) * m_ZoomValue
				+ (this->height() / 2 - m_Pixmap.size().height() / 2));
			update();
		}
	}
}


//计算直线交点
int Line_Intersect(QPointF& p1, QPointF& p2, QPointF& p3, QPointF& p4, QPointF& p5) {
	double a0 = p1.y() - p2.y();
	double b0 = p2.x() - p1.x();
	double c0 = p1.x() * p2.y() - p2.x() * p1.y();

	double a1 = p3.y() - p4.y();
	double b1 = p4.x() - p3.x();
	double c1 = p3.x() * p4.y() - p4.x() * p3.y();

	double D = a0 * b1 - a1 * b0;

	//D==0 直线平行
	if (D == 0) {
		return 1;
	}

	p5.setX((b0 * c1 - b1 * c0) / D);
	p5.setY((a1 * c0 - a0 * c1) / D);

	return -1;

}

// 计算垂足的坐标    ps代表线外的点，线段起点，线段终点
QPoint calculate_foot_point(QPointF ps0, QPointF ps1, QPointF ps2)
{
	QPoint p(0, 0);                // 垂足
	if (ps1.x() == ps2.x()) // 线与x轴垂直
	{
		p.setX(ps1.x());
		p.setY(ps0.y());
	}
	else if (ps1.y() == ps2.y()) // 线与y轴垂直
	{
		p.setX(ps0.x());
		p.setY(ps1.y());
	}
	else // 线与x轴，y轴都不垂直
	{
		int a1 = -(ps2.y() - ps1.y());
		int b1 = ps2.x() - ps1.x();
		int c1 = (ps2.y() - ps1.y()) * ps1.x() - (ps2.x() - ps1.x()) * ps1.y();
		p.setX((b1 * b1 * ps0.x() - a1 * b1 * ps0.y() - a1 * c1) / (a1 * a1 + b1 * b1));
		p.setY((a1 * a1 * ps0.y() - a1 * b1 * ps0.x() - b1 * c1) / (a1 * a1 + b1 * b1));
	}

	return p;
}
// 计算点ps0到直线的距离
double myLabel::calculate_distance(QPointF ps0, QPointF ps1, QPointF ps2)
{
	double d = 0;                    // 距离
	if (ps1.x() == ps2.x()) // 线与x轴垂直
	{
		d = abs(ps1.x() - ps0.x());
	}
	else if (ps1.y() == ps2.y()) // 线与y轴垂直
	{
		d = abs(ps1.y() - ps0.y());
	}
	else // 线与x轴，y轴都不垂直
	{
		double a1 = -(ps2.y() - ps1.y());
		double b1 = ps2.x() - ps1.x();
		double c1 = (ps2.y() - ps1.y()) * ps1.x() - (ps2.x() - ps1.x()) * ps1.y();
		d = abs(a1 * ps0.x() + b1 * ps0.y() + c1) / sqrt(a1 * a1 + b1 * b1);
	}
	return d;
}
//向量法计算角度
double myLabel::cal_angle(QPointF a, QPointF b, QPointF c) {
	double x1 = a.x() - b.x();
	double y1 = a.y() - b.y();
	double x2 = c.x() - b.x();
	double y2 = c.y() - b.y();
	double cos_b = (x1 * x2 + y1 * y2) / (sqrt(pow(x1, 2) + pow(y1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2)));
	double B = acos(cos_b) * 180 / CV_PI;
	return B;
}


//opencv获取ROI
void myLabel::getDistrict()
{
	cv::destroyAllWindows();//清空所有窗口
	//QPixmap* capturePixmap = new QPixmap(m_Pixmap);
	//m_capturePixmap = capturePixmap->copy(m_currentSelectRect);
	QtWidgetsApplication1 myQt;
	//////////截取图像位置和大小///////////
	int x, y, width, height;
	width = qAbs(StartPoint.x() - EndPoint.x());
	height = qAbs(StartPoint.y() - EndPoint.y());
	x = StartPoint.x() < EndPoint.x() ? StartPoint.x() : EndPoint.x();
	y = StartPoint.y() < EndPoint.y() ? StartPoint.y() : EndPoint.y();
	//限制边界
	if (x + width - (this->width() / 2 - m_Pixmap.size().width() / 2) >= m_Pixmap.size().width()) {
		width = m_Pixmap.size().width() - x - 2;
	}
	if (y + height - (this->height() / 2 - m_Pixmap.size().height() / 2) >= m_Pixmap.size().height()) {
		height = m_Pixmap.size().height() - y - 2;
	}
	if (x - (this->width() / 2 - m_Pixmap.size().width() / 2) <= 0) {
		x = 2; width = StartPoint.x();
	}
	if (y - (this->height() / 2 - m_Pixmap.size().height() / 2) <= 0) {
		y = 2; height = StartPoint.y();
	}
	if (x - (this->width() / 2 - m_Pixmap.size().width() / 2) >= m_Pixmap.size().width() || y - (this->height() / 2 - m_Pixmap.size().height() / 2) >= m_Pixmap.size().height()) {
		x = 0; y = 0; width = 5; height = 5;
	}
	if (m_Mode == CUSTOMARC) {
		//自定义圆弧在鼠标释放时就画好了rect，不要再次定义
	}
	else {
		//在原始图像中的位置，scaled_ratio指原图像和showlabel的缩放比例，m_ZoomValue指滚轮缩放尺度
		cv_rect.x = scaled_ratio * ((x - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
		cv_rect.y = scaled_ratio * ((y - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
		if (width == 0 || height == 0) {
			cv_rect.width = 10 * scaled_ratio / m_ZoomValue;
			cv_rect.height = 10 * scaled_ratio / m_ZoomValue;
		}
		else {
			cv_rect.width = width * scaled_ratio / m_ZoomValue;
			cv_rect.height = height * scaled_ratio / m_ZoomValue;
		}
	}
	//cv_rect.width = width * scaled_ratio / m_ZoomValue;
	//cv_rect.height = height* scaled_ratio / m_ZoomValue;
	QRect selectedRect = QRect(x, y, width, height);
	//cv_src = myQt.QPixmapToCvMat(m_Pixmap, 0);
	//显示roi截图
	cv_dst = cv_src(cv_rect).clone();
	cv::imshow("dst", cv_dst);
	///////////////////////
	if (m_currentCaptureState == beginCaptureImage) {
		if (m_clickedBtn == on_intersectionBtn_clicked) {
			Detect detect(this);
			detect.detectLine(cv_dst);
			if (detect.line_data.size() != 0) {
				curLine.setLine(qreal(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)*m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2)),
					qreal(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2)));
				update();
			}
		}
		else if (m_clickedBtn == on_linlindisBtn_clicked) {
			Detect detect(this);
			detect.detectLine(cv_dst);
			if (detect.line_data.size() != 0) {
				curLine.setLine(qreal(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)),
					qreal(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)));
				update();
				cv_rect1.push_back(cv_rect);

			}
		}
		else if (m_clickedBtn == on_linlinAngleBtn_clicked) {
			Detect detect(this);
			detect.detectLine(cv_dst);
			if (detect.line_data.size() != 0) {
				curLine.setLine(qreal(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)),
					qreal(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)));
				update();
			}
		}
		else if (m_clickedBtn == on_taperBtn_clicked) {
			Detect detect(this);
			detect.detectLine(cv_dst);
			if (detect.line_data.size() != 0) {
				curLine.setLine(qreal(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)),
					qreal(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)));
				update();
			}
		}
		else if (m_clickedBtn == on_parallelismBtn_clicked) {
			Detect detect(this);
			detect.detectLine(cv_dst);
			if (detect.line_data.size() != 0) {
				curLine.setLine(qreal(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)),
					qreal(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)));
				update();
			}
		}
		else if (m_clickedBtn == on_perpendicularityBtn_clicked) {
			Detect detect(this);
			detect.detectLine(cv_dst);
			if (detect.line_data.size() != 0) {
				curLine.setLine(qreal(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)),
					qreal(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
					qreal(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)));
				update();
			}
		}
		else if (m_clickedBtn == on_circirtanBtn_clicked) {
			Detect detect(this);
			detect.detectCircle(cv_dst);
			if (detect.circles.size() != 0) {
				curCirCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio)* m_ZoomValue 
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				curCirCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio) * m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				curCirRadius = detect.circles[0][2] / scaled_ratio;
				update();
			}
		}
		else if (m_clickedBtn == on_circirdisBtn_clicked) {
			Detect detect(this);
			detect.detectCircle(cv_dst);
			if (detect.circles.size() != 0) {
				curCirCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				curCirCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				curCirRadius = detect.circles[0][2] / scaled_ratio;
				update();
			}
		}
		else if (m_clickedBtn == on_axialityBtn_clicked) {
			Detect detect(this);
			detect.detectCtrLin(cv_dst);
			verCtrLineStartPt.setX(((detect.ver_x + cv_rect.x) / scaled_ratio)* m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2));
			verCtrLineStartPt.setY(((detect.ver_y + cv_rect.y) / scaled_ratio)* m_ZoomValue
				+ (this->height() / 2 - m_Pixmap.size().height() / 2));
			verCtrLineEndPt.setX(((detect.ver_x1 + cv_rect.x) / scaled_ratio)* m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2));
			verCtrLineEndPt.setY(((detect.ver_y1 + cv_rect.y) / scaled_ratio)* m_ZoomValue
				+ (this->height() / 2 - m_Pixmap.size().height() / 2));
			horCtrLineStartPt.setX(((detect.hor_x + cv_rect.x) / scaled_ratio)* m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2));
			horCtrLineStartPt.setY(((detect.hor_y + cv_rect.y) / scaled_ratio)* m_ZoomValue
				+ (this->height() / 2 - m_Pixmap.size().height() / 2));
			horCtrLineEndPt.setX(((detect.hor_x1 + cv_rect.x) / scaled_ratio)* m_ZoomValue
				+ (this->width() / 2 - m_Pixmap.size().width() / 2));
			horCtrLineEndPt.setY(((detect.hor_y1 + cv_rect.y) / scaled_ratio)* m_ZoomValue
				+ (this->height() / 2 - m_Pixmap.size().height() / 2));
			update();
		}
	}
	if (m_currentCaptureState == finishCaptureImage) {

		// 避免宽或高为零时拷贝截图有误;
		// 可以看QQ截图，当选取截图宽或高为零时默认为20;
		if (cv_rect.width == 0|| cv_rect.height==0)
		{
			return;
		}
		else {
			if (m_clickedBtn == on_customArcBtn_clicked) {
				Detect detect(this);
				detect.CustomArc(cv_dst);
				ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcRadius = detect.radius / scaled_ratio;

				CircleData circle;
				circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval, ArcCenter.y() / m_ZoomValue - m_YPtInterval);
				circle.radius = ArcRadius;
				Circle.push_back(circle);
				update();
				clearPoint();
			}
			else if (m_clickedBtn == on_lineBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//从opencv转换坐标到Qt
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(((detect.line_data[0][0]+ cv_rect.x) / scaled_ratio +m_XPtInterval)* m_ZoomValue 
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineStartPoint.setY(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio +m_YPtInterval)* m_ZoomValue 
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					lineEndPoint.setX(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue 
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineEndPoint.setY(((detect.line_data[0][3]+ cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue 
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					update();
					QMessageBox::StandardButton result = QMessageBox::information(NULL, 
						"Save", 
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Line.push_back(QLineF(lineStartPoint.x()/ m_ZoomValue -m_XPtInterval, lineStartPoint.y() / m_ZoomValue - m_YPtInterval, lineEndPoint.x() / m_ZoomValue - m_XPtInterval, lineEndPoint.y() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_linmidBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//从opencv转换坐标到Qt
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineStartPoint.setY(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					lineEndPoint.setX(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineEndPoint.setY(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					update();
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Line.push_back(QLineF(lineStartPoint.x() / m_ZoomValue - m_XPtInterval, lineStartPoint.y() / m_ZoomValue - m_YPtInterval, lineEndPoint.x() / m_ZoomValue - m_XPtInterval, lineEndPoint.y() / m_ZoomValue - m_YPtInterval));
						Point.push_back(QPointF((lineStartPoint.x() + lineEndPoint.x()) / (2* m_ZoomValue) - m_XPtInterval, (lineStartPoint.y() + lineEndPoint.y()) / (2* m_ZoomValue)- m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_peakLinBtn_clicked) {
				Detect detect(this);
				detect.detectPeakLin(cv_dst);
				leftPeakLineStartPt.setX(((detect.leftPeakLine_x0 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				leftPeakLineStartPt.setY(((detect.leftPeakLine_y0 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				leftPeakLineEndPt.setX(((detect.leftPeakLine_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				leftPeakLineEndPt.setY(((detect.leftPeakLine_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				rightPeakLineStartPt.setX(((detect.rightPeakLine_x0 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				rightPeakLineStartPt.setY(((detect.rightPeakLine_y0 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				rightPeakLineEndPt.setX(((detect.rightPeakLine_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				rightPeakLineEndPt.setY(((detect.rightPeakLine_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				update();
				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Line.push_back(QLineF(leftPeakLineStartPt.x() / m_ZoomValue - m_XPtInterval, leftPeakLineStartPt.y() / m_ZoomValue - m_YPtInterval, leftPeakLineEndPt.x() / m_ZoomValue - m_XPtInterval, leftPeakLineEndPt.y() / m_ZoomValue - m_YPtInterval));
					Line.push_back(QLineF(rightPeakLineStartPt.x() / m_ZoomValue - m_XPtInterval, rightPeakLineStartPt.y() / m_ZoomValue - m_YPtInterval, rightPeakLineEndPt.x() / m_ZoomValue - m_XPtInterval, rightPeakLineEndPt.y() / m_ZoomValue - m_YPtInterval));
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
			else if (m_clickedBtn == on_ctrLinBtn_clicked) {
				Detect detect(this);
				detect.detectCtrLin(cv_dst);
				verCtrLineStartPt.setX(((detect.ver_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				verCtrLineStartPt.setY(((detect.ver_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				verCtrLineEndPt.setX(((detect.ver_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				verCtrLineEndPt.setY(((detect.ver_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				horCtrLineStartPt.setX(((detect.hor_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				horCtrLineStartPt.setY(((detect.hor_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				horCtrLineEndPt.setX(((detect.hor_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				horCtrLineEndPt.setY(((detect.hor_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				update();
				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Line.push_back(QLineF(verCtrLineStartPt.x() / m_ZoomValue - m_XPtInterval, verCtrLineStartPt.y() / m_ZoomValue - m_YPtInterval, verCtrLineEndPt.x() / m_ZoomValue - m_XPtInterval, verCtrLineEndPt.y() / m_ZoomValue - m_YPtInterval));
					Line.push_back(QLineF(horCtrLineStartPt.x() / m_ZoomValue - m_XPtInterval, horCtrLineStartPt.y() / m_ZoomValue - m_YPtInterval, horCtrLineEndPt.x() / m_ZoomValue - m_XPtInterval, horCtrLineEndPt.y() / m_ZoomValue - m_YPtInterval));
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
			else if (m_clickedBtn == on_circleBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					ArcCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.circles[0][2] / scaled_ratio;
					update();

					CircleData circle;
					circle.center = QPointF(ArcCenter.x()/m_ZoomValue-m_XPtInterval, 
						ArcCenter.y()/m_ZoomValue-m_YPtInterval); 
					circle.radius = ArcRadius;
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle);
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_radiusBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					ArcCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.circles[0][2] / scaled_ratio;
					update();

					CircleData circle;
					circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
						ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
					circle.radius = ArcRadius;
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle);
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
				else if (detect.circles.size() == 0) {
					detect.detectArc(cv_dst);
					ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.radius / scaled_ratio;

					CircleData circle;
					circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
						ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
					circle.radius = ArcRadius;
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle);
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_diameterBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					ArcCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.circles[0][2] / scaled_ratio;
					update();

					CircleData circle;
					circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
						ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
					circle.radius = ArcRadius;
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle);
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
				else if (detect.circles.size() == 0) {
					detect.detectArc(cv_dst);
					ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.radius / scaled_ratio;

					CircleData circle;
					circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
						ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
					circle.radius = ArcRadius;
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle);
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_arcBtn_clicked) {
				Detect detect(this);
				detect.detectArc(cv_dst);
				ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcRadius = detect.radius / scaled_ratio;

				CircleData circle;
				circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
					ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
				circle.radius = ArcRadius;
				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Circle.push_back(circle);
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
			else if (m_clickedBtn == on_roundnessBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					detect.detectRoundness(cv_dst);
					ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.radius / scaled_ratio;
					roundness = ratio * detect.roundness / scaled_ratio;

					CircleData circle;
					circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
						ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
					circle.radius = ArcRadius;
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle);
						Roundness.push_back(roundness);
						Roundness_Point.push_back(QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval, 
							ArcCenter.y() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
				else if (detect.circles.size() == 0) {
					detect.detectArc(cv_dst);
					ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.radius / scaled_ratio;
					roundness = ratio * detect.roundness / scaled_ratio;

					CircleData circle;
					circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
						ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
					circle.radius = ArcRadius;
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle);
						Roundness.push_back(roundness);
						Roundness_Point.push_back(QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
							ArcCenter.y() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_chamferBtn_clicked) {
				Detect detect(this);
				detect.detectChamfer(cv_dst);
				chamfer.setP1(QPoint(((detect.chamfer_x0  + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2),
					((detect.chamfer_y0  + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2)));
				chamfer.setP2(QPoint(((detect.chamfer_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2),
					((detect.chamfer_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2)));

				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Line.push_back(QLineF(chamfer.x1() / m_ZoomValue - m_XPtInterval, chamfer.y1() / m_ZoomValue - m_YPtInterval, chamfer.x2() / m_ZoomValue - m_XPtInterval, chamfer.y2() / m_ZoomValue - m_YPtInterval));
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
			else if (m_clickedBtn == on_arcAngleBtn_clicked) {
				Detect detect(this);
				detect.detectArc(cv_dst);
				ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcRadius = detect.radius / scaled_ratio;
				ArcLinTan0.setX(((detect.arclintan_x0 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcLinTan0.setY(((detect.arclintan_y0 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcLinTan1.setX(((detect.arclintan_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcLinTan1.setY(((detect.arclintan_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcAngle = detect.arcAngle;

				CircleData circle;
				circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
					ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
				circle.radius = ArcRadius;
				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Circle.push_back(circle);
					arcangle_Line.push_back(QLineF(ArcCenter.x() / m_ZoomValue - m_XPtInterval, ArcCenter.y() / m_ZoomValue - m_YPtInterval, ArcLinTan0.x() / m_ZoomValue - m_XPtInterval, ArcLinTan0.y() / m_ZoomValue - m_YPtInterval));
					arcangle_Line.push_back(QLineF(ArcCenter.x() / m_ZoomValue - m_XPtInterval, ArcCenter.y() / m_ZoomValue - m_YPtInterval, ArcLinTan1.x() / m_ZoomValue - m_XPtInterval, ArcLinTan1.y() / m_ZoomValue - m_YPtInterval));
					arcangle.push_back(ArcAngle);
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
			else if (m_clickedBtn == on_arcmidBtn_clicked) {
				Detect detect(this);
				detect.detectArc(cv_dst);
				ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcRadius = detect.radius / scaled_ratio;
				ArcMid.setX(((detect.arcMid_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcMid.setY(((detect.arcMid_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));

				CircleData circle;
				circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
					ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
				circle.radius = ArcRadius;
				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Circle.push_back(circle);
					Point.push_back(QPointF(ArcMid.x() / m_ZoomValue - m_XPtInterval,
						ArcMid.y() / m_ZoomValue - m_YPtInterval));
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
			else if (m_clickedBtn == on_cirlintanBtn_clicked) {
				Detect detect(this);
				detect.detectArc(cv_dst);
				ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcRadius = detect.radius / scaled_ratio;
				ArcLinTan0.setX(((detect.arclintan_x0 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcLinTan0.setY(((detect.arclintan_y0 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcLinTan1.setX(((detect.arclintan_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcLinTan1.setY(((detect.arclintan_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));

				CircleData circle;
				circle.center = QPointF(ArcCenter.x() / m_ZoomValue - m_XPtInterval,
					ArcCenter.y() / m_ZoomValue - m_YPtInterval); 
				circle.radius = ArcRadius;
				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Circle.push_back(circle);
					Point.push_back(QPointF(ArcLinTan0.x() / m_ZoomValue - m_XPtInterval,
						ArcLinTan0.y() / m_ZoomValue - m_YPtInterval));
					Point.push_back(QPointF(ArcLinTan1.x() / m_ZoomValue - m_XPtInterval,
						ArcLinTan1.y() / m_ZoomValue - m_YPtInterval));
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}
			else if (m_clickedBtn == on_ptlindisBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//从opencv转换坐标到Qt
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineStartPoint.setY(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					lineEndPoint.setX(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineEndPoint.setY(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					footPoint = calculate_foot_point(PtPoint, lineStartPoint, lineEndPoint);
					//detect.drawVertical(cv_src, Point(PtPoint.x(), PtPoint.y()), Point(lineStartPoint.x(), lineStartPoint.y()), Point(lineEndPoint.x(), lineEndPoint.y()));
					update();

					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						ptlindis_Line.push_back(QLineF(pp.x() / m_ZoomValue - m_XPtInterval,
							pp.y() / m_ZoomValue - m_YPtInterval,
							footPoint.x() / m_ZoomValue - m_XPtInterval,
							footPoint.y() / m_ZoomValue - m_YPtInterval));
						ptlindis_Line.push_back(QLineF(PtPoint.x() / m_ZoomValue - m_XPtInterval,
							PtPoint.y() / m_ZoomValue - m_YPtInterval,
							footPoint.x() / m_ZoomValue - m_XPtInterval,
							footPoint.y() / m_ZoomValue - m_YPtInterval));
						ptlindis.push_back(num / m_ZoomValue);
						Line.push_back(QLineF(p1.x() / m_ZoomValue - m_XPtInterval,
							p1.y() / m_ZoomValue - m_YPtInterval,
							p2.x() / m_ZoomValue - m_XPtInterval,
							p2.y() / m_ZoomValue - m_YPtInterval));
						Point.push_back(QPointF(PtPoint.x() / m_ZoomValue - m_XPtInterval,
							PtPoint.y() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_intersectionBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				if (detect.line_data.size() != 0) {
					curLine.setLine(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2),
						((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
							+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					Parallel = Line_Intersect(curLine.p1(), curLine.p2(), lastLine.p1(), lastLine.p2(), intersectionPt);
				    update();

					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							lastLine.x2() / m_ZoomValue - m_XPtInterval,
							lastLine.y2() / m_ZoomValue - m_YPtInterval));
						Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							curLine.x2() / m_ZoomValue - m_XPtInterval,
							curLine.y2() / m_ZoomValue - m_YPtInterval));
						Point.push_back(QPointF(intersectionPt.x() / m_ZoomValue - m_XPtInterval, intersectionPt.y() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_linlindisBtn_clicked) {
			cv_rect2 = cv_rect;
			//save parameter cv_rect1[0], cv_rect2

			if (deviceOpened == 1 && triggerMode == 1) {
				
				cv_dst1 = cv_src(cv_rect1[0]).clone();
				cv_dst2 = cv_src(cv_rect2).clone();
				Detect detect(this);
				detect.detectLine(cv_dst1);
				if (detect.line_data.size() != 0) {
					lastLine.setLine(qreal(((detect.line_data[0][0] + cv_rect1[0].x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
						qreal(((detect.line_data[0][1] + cv_rect1[0].y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
							+ (this->height() / 2 - m_Pixmap.size().height() / 2)),
						qreal(((detect.line_data[0][2] + cv_rect1[0].x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
							+ (this->width() / 2 - m_Pixmap.size().width() / 2)),
						qreal(((detect.line_data[0][3] + cv_rect1[0].y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
							+ (this->height() / 2 - m_Pixmap.size().height() / 2)));
					detect.line_data.clear();
				}
				detect.detectLine(cv_dst2);
				if (detect.line_data.size() != 0) {
					curLine.setLine(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2),
						((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					footPoint = calculate_foot_point(lastLine.center(), curLine.p1(), curLine.p2());
					linlindis_Line.push_back(QLineF(pp.x() / m_ZoomValue - m_XPtInterval,
						pp.y() / m_ZoomValue - m_YPtInterval,
						footPoint.x() / m_ZoomValue - m_XPtInterval,
						footPoint.y() / m_ZoomValue - m_YPtInterval));
					linlindis_Line.push_back(QLineF(lastLine.center().x() / m_ZoomValue - m_XPtInterval,
						lastLine.center().y() / m_ZoomValue - m_YPtInterval,
						footPoint.x() / m_ZoomValue - m_XPtInterval,
						footPoint.y() / m_ZoomValue - m_YPtInterval));
					linlindis.push_back(num / m_ZoomValue);
					Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
						lastLine.y1() / m_ZoomValue - m_YPtInterval,
						lastLine.x2() / m_ZoomValue - m_XPtInterval,
						lastLine.y2() / m_ZoomValue - m_YPtInterval));
					Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
						curLine.y1() / m_ZoomValue - m_YPtInterval,
						curLine.x2() / m_ZoomValue - m_XPtInterval,
						curLine.y2() / m_ZoomValue - m_YPtInterval));
					update();
				}
			}
			else {
				Detect detect(this);
				detect.detectLine(cv_dst);
				if (detect.line_data.size() != 0) {
					curLine.setLine(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2),
						((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					footPoint = calculate_foot_point(lastLine.center(), curLine.p1(), curLine.p2());
					update();

					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						linlindis_Line.push_back(QLineF(pp.x() / m_ZoomValue - m_XPtInterval,
							pp.y() / m_ZoomValue - m_YPtInterval,
							footPoint.x() / m_ZoomValue - m_XPtInterval,
							footPoint.y() / m_ZoomValue - m_YPtInterval));
						linlindis_Line.push_back(QLineF(lastLine.center().x() / m_ZoomValue - m_XPtInterval,
							lastLine.center().y() / m_ZoomValue - m_YPtInterval,
							footPoint.x() / m_ZoomValue - m_XPtInterval,
							footPoint.y() / m_ZoomValue - m_YPtInterval));
						linlindis.push_back(num / m_ZoomValue);
						Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							lastLine.x2() / m_ZoomValue - m_XPtInterval,
							lastLine.y2() / m_ZoomValue - m_YPtInterval));
						Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							curLine.x2() / m_ZoomValue - m_XPtInterval,
							curLine.y2() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			}
			else if (m_clickedBtn == on_linlinAngleBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				if (detect.line_data.size() != 0) {
					curLine.setLine(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2),
						((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					Parallel = Line_Intersect(curLine.p1(), curLine.p2(), lastLine.p1(), lastLine.p2(), intersectionPt);
					LineLineAngle = cal_angle(curLine.p1(), intersectionPt, lastLine.p1());
					update();

					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						linlinangle_Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							intersectionPt.x() / m_ZoomValue - m_XPtInterval,
							intersectionPt.y() / m_ZoomValue - m_YPtInterval));
						linlinangle_Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							intersectionPt.x() / m_ZoomValue - m_XPtInterval,
							intersectionPt.y() / m_ZoomValue - m_YPtInterval));
						linlinangle.push_back(LineLineAngle);
						Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							lastLine.x2() / m_ZoomValue - m_XPtInterval,
							lastLine.y2() / m_ZoomValue - m_YPtInterval));
						Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							curLine.x2() / m_ZoomValue - m_XPtInterval,
							curLine.y2() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_taperBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				if (detect.line_data.size() != 0) {
					curLine.setLine(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2),
						((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					Parallel = Line_Intersect(curLine.p1(), curLine.p2(), lastLine.p1(), lastLine.p2(), intersectionPt);
					LineLineAngle = cal_angle(curLine.p1(), intersectionPt, lastLine.p1());
					update();

					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						taper_Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							intersectionPt.x() / m_ZoomValue - m_XPtInterval,
							intersectionPt.y() / m_ZoomValue - m_YPtInterval));
						taper_Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							intersectionPt.x() / m_ZoomValue - m_XPtInterval,
							intersectionPt.y() / m_ZoomValue - m_YPtInterval));
						Taper.push_back(taper);
						Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							lastLine.x2() / m_ZoomValue - m_XPtInterval,
							lastLine.y2() / m_ZoomValue - m_YPtInterval));
						Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							curLine.x2() / m_ZoomValue - m_XPtInterval,
							curLine.y2() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_parallelismBtn_clicked) {
			    Detect detect(this);
				detect.detectLinePoints(cv_dst);
				vector<double> dis;
				for (int i = 0; i < detect.LinePoints.size(); i++) {
					dis.push_back(calculate_distance(QPointF(((detect.LinePoints[i].x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.LinePoints[i].y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2)), 
						lastLine.p1(), lastLine.p2()));
				}
				auto maxPosition = max_element(dis.begin(), dis.end());
				auto minPosition = min_element(dis.begin(), dis.end());
				parrallelism = ratio*(*maxPosition - *minPosition);
				detect.detectLine(cv_dst);
				if (detect.line_data.size() != 0) {
					curLine.setLine(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2),
						((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					Parallel = Line_Intersect(curLine.p1(), curLine.p2(), lastLine.p1(), lastLine.p2(), intersectionPt);
					LineLineAngle = cal_angle(curLine.p1(), intersectionPt, lastLine.p1());
					update();

					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						parallelism_Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							lastLine.y2() / m_ZoomValue - m_XPtInterval,
							lastLine.y2() / m_ZoomValue - m_YPtInterval));
						parallelism_Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							curLine.x2() / m_ZoomValue - m_XPtInterval,
							curLine.y2() / m_ZoomValue - m_YPtInterval));
						Parallelism.push_back(parrallelism);
						Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							lastLine.x2() / m_ZoomValue - m_XPtInterval,
							lastLine.y2() / m_ZoomValue - m_YPtInterval));
						Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							curLine.x2() / m_ZoomValue - m_XPtInterval,
							curLine.y2() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_perpendicularityBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				if (detect.line_data.size() != 0) {
					curLine.setLine(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2),
						((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2),
						((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					Parallel = Line_Intersect(curLine.p1(), curLine.p2(), lastLine.p1(), lastLine.p2(), intersectionPt);
					LineLineAngle = cal_angle(curLine.p1(), intersectionPt, lastLine.p1());
					perpendicularity = ratio * cos(LineLineAngle*CV_PI/180) * sqrt(pow(lastLine.p1().x() - lastLine.p2().x(), 2) + pow(lastLine.p1().y() - lastLine.p2().y(), 2));
					update();

					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						perpendicularity_Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							lastLine.y2() / m_ZoomValue - m_XPtInterval,
							lastLine.y2() / m_ZoomValue - m_YPtInterval));
						perpendicularity_Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							curLine.x2() / m_ZoomValue - m_XPtInterval,
							curLine.y2() / m_ZoomValue - m_YPtInterval));
						Perpendicularity.push_back(perpendicularity);
						Line.push_back(QLineF(lastLine.x1() / m_ZoomValue - m_XPtInterval,
							lastLine.y1() / m_ZoomValue - m_YPtInterval,
							lastLine.x2() / m_ZoomValue - m_XPtInterval,
							lastLine.y2() / m_ZoomValue - m_YPtInterval));
						Line.push_back(QLineF(curLine.x1() / m_ZoomValue - m_XPtInterval,
							curLine.y1() / m_ZoomValue - m_YPtInterval,
							curLine.x2() / m_ZoomValue - m_XPtInterval,
							curLine.y2() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_circirtanBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					curCirCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					curCirCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					curCirRadius = detect.circles[0][2] / scaled_ratio;
					update();

					CircleData circle1, circle2;
					circle1.center = QPointF(curCirCenter.x() / m_ZoomValue - m_XPtInterval, curCirCenter.y() / m_ZoomValue - m_YPtInterval);
					circle1.radius = curCirRadius;
					circle2.center = QPointF(lastCirCenter.x() / m_ZoomValue - m_XPtInterval, lastCirCenter.y() / m_ZoomValue - m_YPtInterval);
					circle2.radius = lastCirRadius;
					Point.push_back(CirTanPt);
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle1);
						Circle.push_back(circle2);
						circirdis.push_back(CenterDis / m_ZoomValue);
						circirdis_Line.push_back(QLineF(circle1.center.x() / m_ZoomValue - m_XPtInterval,
							circle1.center.y() / m_ZoomValue - m_YPtInterval,
							circle2.center.x() / m_ZoomValue - m_XPtInterval,
							circle2.center.y() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_circirdisBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					curCirCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					curCirCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					curCirRadius = detect.circles[0][2] / scaled_ratio;
					update();

					CircleData circle1,circle2;
					circle1.center = QPointF(curCirCenter.x() / m_ZoomValue - m_XPtInterval, curCirCenter.y() / m_ZoomValue - m_YPtInterval);
					circle1.radius = curCirRadius;
					circle2.center = QPointF(lastCirCenter.x() / m_ZoomValue - m_XPtInterval, lastCirCenter.y() / m_ZoomValue - m_YPtInterval);
					circle2.radius = lastCirRadius;
					QMessageBox::StandardButton result = QMessageBox::information(NULL,
						"Save",
						"Do you want to save?",
						QMessageBox::Yes | QMessageBox::No,
						QMessageBox::Yes);
					switch (result)
					{
					case QMessageBox::Yes:
						Circle.push_back(circle1);
						Circle.push_back(circle2);
						circirdis.push_back(CenterDis/m_ZoomValue);
						circirdis_Line.push_back(QLineF(circle1.center.x() / m_ZoomValue - m_XPtInterval,
							circle1.center.y() / m_ZoomValue - m_YPtInterval,
							circle2.center.x() / m_ZoomValue - m_XPtInterval,
							circle2.center.y() / m_ZoomValue - m_YPtInterval));
						break;
					case QMessageBox::No:
						clearRect();
						clearPoint();
						break;
					default:
						break;
					}
				}
			}
			else if (m_clickedBtn == on_axialityBtn_clicked) {
				Detect detect(this);
				detect.detectCtrLin(cv_dst);
				verCtrLineStartPt.setX(((detect.ver_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				verCtrLineStartPt.setY(((detect.ver_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				verCtrLineEndPt.setX(((detect.ver_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				verCtrLineEndPt.setY(((detect.ver_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				horCtrLineStartPt.setX(((detect.hor_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				horCtrLineStartPt.setY(((detect.hor_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				horCtrLineEndPt.setX(((detect.hor_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				horCtrLineEndPt.setY(((detect.hor_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				//update();

				QMessageBox::StandardButton result = QMessageBox::information(NULL,
					"Save",
					"Do you want to save?",
					QMessageBox::Yes | QMessageBox::No,
					QMessageBox::Yes);
				switch (result)
				{
				case QMessageBox::Yes:
					Line.push_back(QLineF(verCtrLineStartPt.x() / m_ZoomValue - m_XPtInterval,
						verCtrLineStartPt.y() / m_ZoomValue - m_YPtInterval,
						verCtrLineEndPt.x() / m_ZoomValue - m_XPtInterval,
						verCtrLineEndPt.y() / m_ZoomValue - m_YPtInterval));
					Line.push_back(QLineF(horCtrLineStartPt.x() / m_ZoomValue - m_XPtInterval,
						horCtrLineStartPt.y() / m_ZoomValue - m_YPtInterval,
						horCtrLineEndPt.x() / m_ZoomValue - m_XPtInterval,
						horCtrLineEndPt.y() / m_ZoomValue - m_YPtInterval));
					Line.push_back(QLineF(lastVerCtrLineStartPt.x() / m_ZoomValue - m_XPtInterval,
						lastVerCtrLineStartPt.y() / m_ZoomValue - m_YPtInterval,
						lastVerCtrLineEndPt.x() / m_ZoomValue - m_XPtInterval,
						lastVerCtrLineEndPt.y() / m_ZoomValue - m_YPtInterval));
					Line.push_back(QLineF(lastHorCtrLineStartPt.x() / m_ZoomValue - m_XPtInterval,
						lastHorCtrLineStartPt.y() / m_ZoomValue - m_YPtInterval,
						lastHorCtrLineEndPt.x() / m_ZoomValue - m_XPtInterval,
						lastHorCtrLineEndPt.y() / m_ZoomValue - m_YPtInterval));
					axiality_Point.push_back(QPointF(verCtrLineStartPt.x() / m_ZoomValue - m_XPtInterval,
						verCtrLineStartPt.y() / m_ZoomValue - m_YPtInterval));
					axiality_Point.push_back(QPointF(horCtrLineStartPt.x() / m_ZoomValue - m_XPtInterval,
						horCtrLineStartPt.y() / m_ZoomValue - m_YPtInterval));
					axiality.push_back(VerAxiality);
					axiality.push_back(HorAxiality);
					break;
				case QMessageBox::No:
					clearRect();
					clearPoint();
					break;
				default:
					break;
				}
			}

			
		}
	}
	else if (m_currentCaptureState == finishMoveCaptureArea) {

	    int x, y, width, height;
	    x = newStartPoint.x() < newEndPoint.x() ? newStartPoint.x() : newEndPoint.x();
	    y = newStartPoint.y() < newEndPoint.y() ? newStartPoint.y() : newEndPoint.y();
		width = qAbs(newStartPoint.x() - newEndPoint.x());
		height = qAbs(newStartPoint.y() - newEndPoint.y());

		cv_rect.x = scaled_ratio * ((x - (this->width() / 2 - m_Pixmap.size().width() / 2)) / m_ZoomValue - m_XPtInterval);
		cv_rect.y = scaled_ratio * ((y - (this->height() / 2 - m_Pixmap.size().height() / 2)) / m_ZoomValue - m_YPtInterval);
		cv_rect.width = width;
		cv_rect.height = height;
		//cv_src = myQt.QPixmapToCvMat(m_Pixmap, 0);
		//显示roi截图
		cv_dst = cv_src(cv_rect).clone();

		if (width == 0||height==0) {
			return;
		}
		else {
			if (m_clickedBtn == on_lineBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineStartPoint.setY(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					lineEndPoint.setX(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineEndPoint.setY(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					update();
				}
			}
			else if (m_clickedBtn == on_linmidBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//从opencv转换坐标到Qt
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineStartPoint.setY(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					lineEndPoint.setX(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineEndPoint.setY(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					update();
				}
			}
			else if (m_clickedBtn == on_peakLinBtn_clicked) {
				Detect detect(this);
				detect.detectPeakLin(cv_dst);
				leftPeakLineStartPt.setX(((detect.leftPeakLine_x0 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				leftPeakLineStartPt.setY(((detect.leftPeakLine_y0 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				leftPeakLineEndPt.setX(((detect.leftPeakLine_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				leftPeakLineEndPt.setY(((detect.leftPeakLine_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				rightPeakLineStartPt.setX(((detect.rightPeakLine_x0 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				rightPeakLineStartPt.setY(((detect.rightPeakLine_y0 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				rightPeakLineEndPt.setX(((detect.rightPeakLine_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				rightPeakLineEndPt.setY(((detect.rightPeakLine_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				update();
			}
			else if (m_clickedBtn == on_ctrLinBtn_clicked) {
				Detect detect(this);
				detect.detectCtrLin(cv_dst);
				verCtrLineStartPt.setX(((detect.ver_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				verCtrLineStartPt.setY(((detect.ver_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				verCtrLineEndPt.setX(((detect.ver_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				verCtrLineEndPt.setY(((detect.ver_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				horCtrLineStartPt.setX(((detect.hor_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				horCtrLineStartPt.setY(((detect.hor_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				horCtrLineEndPt.setX(((detect.hor_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				horCtrLineEndPt.setY(((detect.hor_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				update();
			}
			else if (m_clickedBtn == on_circleBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					ArcCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.circles[0][2] / scaled_ratio;
					update();
				}
			}
			else if (m_clickedBtn == on_radiusBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					ArcCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval) * m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval) * m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.circles[0][2] / scaled_ratio;
					update();
				}
				else if (detect.circles.size() == 0) {
					detect.detectArc(cv_dst);
					ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.radius / scaled_ratio;
				}
			}
			else if (m_clickedBtn == on_diameterBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					ArcCenter.setX(((detect.circles[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.circles[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.circles[0][2] / scaled_ratio;
					update();
				}
				else if (detect.circles.size() == 0) {
					detect.detectArc(cv_dst);
					ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.radius / scaled_ratio;
				}
			}
			else if (m_clickedBtn == on_arcBtn_clicked) {
				Detect detect(this);
				detect.detectArc(cv_dst);
				ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcRadius = detect.radius / scaled_ratio;
			}
			else if (m_clickedBtn == on_roundnessBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
				if (detect.circles.size() != 0) {
					detect.detectRoundness(cv_dst);
					ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.radius / scaled_ratio;
					roundness = ratio * detect.roundness / scaled_ratio;
				}
				else if (detect.circles.size() == 0) {
					detect.detectArc(cv_dst);
					ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					ArcRadius = detect.radius / scaled_ratio;
					roundness = ratio * detect.roundness / scaled_ratio;
				}
			}
			else if (m_clickedBtn == on_arcAngleBtn_clicked) {
				Detect detect(this);
				detect.detectArc(cv_dst);
				ArcCenter.setX(((detect.center_x + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcCenter.setY(((detect.center_y + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcRadius = detect.radius / scaled_ratio;
				ArcLinTan0.setX(((detect.arclintan_x0 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcLinTan0.setY(((detect.arclintan_y0 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcLinTan1.setX(((detect.arclintan_x1 + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
					+ (this->width() / 2 - m_Pixmap.size().width() / 2));
				ArcLinTan1.setY(((detect.arclintan_y1 + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
					+ (this->height() / 2 - m_Pixmap.size().height() / 2));
				ArcAngle = detect.arcAngle;
			}
			else if (m_clickedBtn == on_ptlindisBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//从opencv转换坐标到Qt
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(((detect.line_data[0][0] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineStartPoint.setY(((detect.line_data[0][1] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					lineEndPoint.setX(((detect.line_data[0][2] + cv_rect.x) / scaled_ratio + m_XPtInterval)* m_ZoomValue
						+ (this->width() / 2 - m_Pixmap.size().width() / 2));
					lineEndPoint.setY(((detect.line_data[0][3] + cv_rect.y) / scaled_ratio + m_YPtInterval)* m_ZoomValue
						+ (this->height() / 2 - m_Pixmap.size().height() / 2));
					footPoint = calculate_foot_point(PtPoint, lineStartPoint, lineEndPoint);
					//detect.drawVertical(cv_src, Point(PtPoint.x(), PtPoint.y()), Point(lineStartPoint.x(), lineStartPoint.y()), Point(lineEndPoint.x(), lineEndPoint.y()));
					update();
				}
			}
			
		}
	}
}











