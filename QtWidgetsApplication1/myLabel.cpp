
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

//清除矩形框数据
void myLabel::clearRect()
{
	StartPoint = QPoint(0, 0);
	EndPoint = QPoint(1, 1);
	update();
}

void myLabel::clearPoint() 
{
    PtPoint = QPoint(0, 0);
	lastPtPoint = QPoint(0, 0);
	update();
}

//获取当前label下的图片;
QPixmap myLabel::getPix(QPixmap map)
{
	return m_Pixmap = map;
}


//绘制事件
void myLabel::paintEvent(QPaintEvent* event)
{
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
				pen.setColor(QColor(Qt::yellow));
				pen.setWidth(10);
				painter.setPen(pen);
				painter.drawPoint(PtPoint);
				lastPtPoint = PtPoint;
			}
			else if (!lastPtPoint.isNull()) {
				pen.setColor(QColor(Qt::yellow));
				pen.setWidth(10);
				painter.setPen(pen);
				painter.drawPoint(lastPtPoint);
				painter.drawPoint(PtPoint);
				pen.setWidth(1);
				painter.setPen(pen);
				painter.drawLine(PtPoint, lastPtPoint);
				float num = sqrtf(powf((PtPoint.x() - lastPtPoint.x()), 2) + powf((PtPoint.y() - lastPtPoint.y()), 2));
				QString data = QString("%1").arg(num);
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
				pen.setColor(QColor(Qt::yellow));
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
					float num = sqrtf(powf((PtPoint.x() - footPoint.x()), 2) + powf((PtPoint.y() - footPoint.y()), 2));
					QString data = QString("%1").arg(num);    //显示距离num
					painter.drawText((PtPoint.x() + footPoint.x()) / 2, (PtPoint.y() + footPoint.y()) / 2, data);

					// 画延长虚线
					QPointF p1 = lineStartPoint.x() > lineEndPoint.x() ? lineEndPoint : lineStartPoint;
					QPointF p2 = lineStartPoint.x() > lineEndPoint.x() ? lineStartPoint : lineEndPoint;
					if (footPoint.x() < p1.x())
					{
						QVector<qreal> dashes;
						qreal space = 3;
						dashes << 5 << space << 5 << space;
						pen.setDashPattern(dashes);
						pen.setWidth(1);
						painter.setPen(pen);
						painter.drawLine(footPoint, p1);
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
						}
					}
				}


			}

		}
		
	}
	else {
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
		if (!lineStartPoint.isNull()) {
			pen.setColor(QColor(Qt::yellow));
			pen.setWidth(6);
			painter.setPen(pen);
			painter.drawLine(lineStartPoint, lineEndPoint);
		}
	}
}

//鼠标按下
void myLabel::mousePressEvent(QMouseEvent* e)
{
	if (m_Mode == MEASURE) {
		if (m_Pixmap.isNull()) {
			QtWidgetsApplication1 Qt;
			Qt.NoPhoto_Dialog();
		}
		else {
			if (m_clickedBtn == on_ptptdisBtn_clicked) {
				StartPoint = e->pos();
				EndPoint = e->pos();
				//setCursor(Qt::ArrowCursor);   //改变光标形状
				//发送开始位置坐标信号给主窗体
				emit StartPointSignal(StartPoint);
				m_currentCaptureState = beginCaptureImage;
			}
			else {
				StartPoint = e->pos();
				EndPoint = e->pos();
				//setCursor(Qt::ArrowCursor);   //改变光标形状
				//发送开始位置坐标信号给主窗体
				emit StartPointSignal(StartPoint);
				m_currentCaptureState = beginCaptureImage;
			}
			
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
			else if (isPressPointInSelectRect(e->pos()))//在矩形内框区域时按下鼠标，则可拖动图片
			{
				m_startMovePoint = e->pos();
				setCursor(Qt::SizeAllCursor);   //改变光标形状,手的形状
				emit StartMoveRectSignal(getSelectRect());
				m_currentCaptureState = beginMoveCaptureArea;
				//m_endMovePoint = e->pos();
				//emit MoveRectSignal(m_endMovePoint);
				//update();
			}

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
	if (m_Mode == MEASURE) {
		if (m_clickedBtn == on_ptptdisBtn_clicked) {
			EndPoint = e->pos();
			//发送结束位置坐标信号给主窗体
			emit StopPointSignal(EndPoint);
			update();//更新label显示 调用paintEvent事件
		}
		else {
			EndPoint = e->pos();
			//发送结束位置坐标信号给主窗体
			emit StopPointSignal(EndPoint);
			update();//更新label显示 调用paintEvent事件
		}
		
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
	if (m_Mode == MEASURE) {
		
		if (m_clickedBtn == on_ptptdisBtn_clicked) {
			EndPoint = e->pos();
			update();
			getPt();    //画出点
		}
		else {
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
		
	}
	else {
		if (m_currentCaptureState == beginCaptureImage)
		{
			m_currentCaptureState = finishCaptureImage;
			EndPoint = e->pos();
			update();
			getDistrict();                //获取ROI
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
QRectF myLabel::getRect(const QPointF& startPoint, const QPointF& endPoint)
{
	int x, y, width, height;
	width = qAbs(startPoint.x() - endPoint.x());
	height = qAbs(startPoint.y() - endPoint.y());
	x = startPoint.x() < endPoint.x() ? startPoint.x() : endPoint.x();
	y = startPoint.y() < endPoint.y() ? startPoint.y() : endPoint.y();

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
	cv_rect.x = x;
	cv_rect.y = y;
	//防止鼠标只点击了一下宽高都为0会报错
	if (width == 0 || height == 0) {
		cv_rect.width = 5;
		cv_rect.height = 5;
		width = 5;
		height = 5;
	}
	else {
		cv_rect.width = width;
		cv_rect.height = height;
	}
	//QRect selectedRect = QRect(x, y, width, height);
	cv_src = myQt.QPixmapToCvMat(m_Pixmap, 0);
	//显示roi截图
	cv_dst = cv_src(cv_rect).clone();
	Detect detect(this);
	if (StartPoint.x() < EndPoint.x()) {
		if (StartPoint.y() < EndPoint.y()) {
			detect.detectPoint(cv_dst, cv::Point(0,0), cv::Point(width, height));
			PtPoint.setX(detect.pt.x+ StartPoint.x());
			PtPoint.setY(detect.pt.y+ StartPoint.y());
			update();
		}
		else {
			detect.detectPoint(cv_dst, cv::Point(0, height), cv::Point(width, 0));
			PtPoint.setX(detect.pt.x + StartPoint.x());
			PtPoint.setY(detect.pt.y + StartPoint.y()-height);
			update();
		}
	}
	else {
		if (StartPoint.y() < EndPoint.y()) {
			detect.detectPoint(cv_dst, cv::Point(width,0), cv::Point(0, height));
			PtPoint.setX(detect.pt.x + StartPoint.x()-width);
			PtPoint.setY(detect.pt.y + StartPoint.y());
			update();
		}
		else {
			detect.detectPoint(cv_dst, cv::Point(width, height), cv::Point(0, 0));
			PtPoint.setX(detect.pt.x + EndPoint.x());
			PtPoint.setY(detect.pt.y + EndPoint.y());
			update();
		}
	}
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
// 计算点到直线的距离
float calculate_distance(QPoint ps0, QPoint ps1, QPoint ps2)
{
	float d = 0;                    // 距离
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
		int a1 = -(ps2.y() - ps1.y());
		int b1 = ps2.x() - ps1.x();
		int c1 = (ps2.y() - ps1.y()) * ps1.x() - (ps2.x() - ps1.x()) * ps1.y();
		d = abs(a1 * ps0.x() + b1 * ps0.y() + c1) / sqrt(a1 * a1 + b1 * b1);
	}
	return d;
}



//opencv获取ROI
void myLabel::getDistrict()
{
	cv::destroyAllWindows();//清空所有窗口
	//QPixmap* capturePixmap = new QPixmap(m_Pixmap);
	//m_capturePixmap = capturePixmap->copy(m_currentSelectRect);
	QtWidgetsApplication1 myQt;
	if (m_currentCaptureState == finishCaptureImage) {
		int x, y, width, height;
		width = qAbs(StartPoint.x() - EndPoint.x());
		height = qAbs(StartPoint.y() - EndPoint.y());
		x = StartPoint.x() < EndPoint.x() ? StartPoint.x() : EndPoint.x();
		y = StartPoint.y() < EndPoint.y() ? StartPoint.y() : EndPoint.y();
		cv_rect.x = x;
		cv_rect.y = y;
		cv_rect.width = width;
		cv_rect.height = height;
		QRect selectedRect = QRect(x, y, width, height);
		cv_src = myQt.QPixmapToCvMat(m_Pixmap, 0);
		//显示roi截图
		cv_dst = cv_src(cv_rect).clone();

		// 避免宽或高为零时拷贝截图有误;
		// 可以看QQ截图，当选取截图宽或高为零时默认为20;
		if (selectedRect.width() == 0|| selectedRect.height()==0)
		{
			return;
		}
		else {
			if (m_clickedBtn == on_lineBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//从opencv转换坐标到Qt
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(detect.line_data[0][0] + cv_rect.x);
					lineStartPoint.setY(detect.line_data[0][1] + cv_rect.y);
					lineEndPoint.setX(detect.line_data[0][2] + cv_rect.x);
					lineEndPoint.setY(detect.line_data[0][3] + cv_rect.y);
					update();
				}
			}
			else if (m_clickedBtn == on_peakLinBtn_clicked) {
				Detect detect(this);
				detect.detectPeakLin(cv_dst); 
				//lineStartPoint.setX(detect.line_data[0][0] + StartPoint.x());
				//lineStartPoint.setY(detect.line_data[0][1] + StartPoint.y());
				//lineEndPoint.setX(detect.line_data[0][2] + StartPoint.x());
				//lineEndPoint.setY(detect.line_data[0][3] + StartPoint.y());
			}
			else if (m_clickedBtn == on_ctrLinBtn_clicked) {
				Detect detect(this);
				detect.detectCtrLin(cv_dst);
				lineStartPoint.setX(detect.line_data[0][0] + StartPoint.x());
				lineStartPoint.setY(detect.line_data[0][1] + StartPoint.y());
				lineEndPoint.setX(detect.line_data[0][2] + StartPoint.x());
				lineEndPoint.setY(detect.line_data[0][3] + StartPoint.y());
			}
			else if (m_clickedBtn == on_circleBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
			}
			else if (m_clickedBtn == on_arcBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
			}
			else if (m_clickedBtn == on_ptlindisBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//从opencv转换坐标到Qt
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(detect.line_data[0][0] + cv_rect.x);
					lineStartPoint.setY(detect.line_data[0][1] + cv_rect.y);
					lineEndPoint.setX(detect.line_data[0][2] + cv_rect.x);
					lineEndPoint.setY(detect.line_data[0][3] + cv_rect.y);
					footPoint = calculate_foot_point(PtPoint, lineStartPoint, lineEndPoint);
					//detect.drawVertical(cv_src, Point(PtPoint.x(), PtPoint.y()), Point(lineStartPoint.x(), lineStartPoint.y()), Point(lineEndPoint.x(), lineEndPoint.y()));
					update();
				}
			}
			
		}
	}
	else if (m_currentCaptureState == finishMoveCaptureArea) {

		int width, height;
		width = qAbs(newStartPoint.x() - newEndPoint.x());
		height = qAbs(newStartPoint.y() - newEndPoint.y());
		cv_rect.x = newStartPoint.x() < newEndPoint.x() ? newStartPoint.x() : newEndPoint.x();
		cv_rect.y = newStartPoint.y() < newEndPoint.y() ? newStartPoint.y() : newEndPoint.y();
		cv_rect.width = width;
		cv_rect.height = height;
		cv_src = myQt.QPixmapToCvMat(m_Pixmap, 0);
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
					lineStartPoint.setX(detect.line_data[0][0] + cv_rect.x);
					lineStartPoint.setY(detect.line_data[0][1] + cv_rect.y);
					lineEndPoint.setX(detect.line_data[0][2] + cv_rect.x);
					lineEndPoint.setY(detect.line_data[0][3] + cv_rect.y);
					update();
				}
			}
			else if (m_clickedBtn == on_peakLinBtn_clicked) {
				Detect detect(this);
				detect.detectPeakLin(cv_dst);
				//lineStartPoint.setX(detect.line_data[0][0] + StartPoint.x());
				//lineStartPoint.setY(detect.line_data[0][1] + StartPoint.y());
				//lineEndPoint.setX(detect.line_data[0][2] + StartPoint.x());
				//lineEndPoint.setY(detect.line_data[0][3] + StartPoint.y());
			}
			else if (m_clickedBtn == on_ctrLinBtn_clicked) {
				Detect detect(this);
				detect.detectCtrLin(cv_dst);
				lineStartPoint.setX(detect.line_data[0][0] + StartPoint.x());
				lineStartPoint.setY(detect.line_data[0][1] + StartPoint.y());
				lineEndPoint.setX(detect.line_data[0][2] + StartPoint.x());
				lineEndPoint.setY(detect.line_data[0][3] + StartPoint.y());
			}
			else if (m_clickedBtn == on_circleBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
			}
			else if (m_clickedBtn == on_arcBtn_clicked) {
				Detect detect(this);
				detect.detectCircle(cv_dst);
			}
			else if (m_clickedBtn == on_ptlindisBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//从opencv转换坐标到Qt
				if (detect.line_data.size() != 0) {
					lineStartPoint.setX(detect.line_data[0][0] + cv_rect.x);
					lineStartPoint.setY(detect.line_data[0][1] + cv_rect.y);
					lineEndPoint.setX(detect.line_data[0][2] + cv_rect.x);
					lineEndPoint.setY(detect.line_data[0][3] + cv_rect.y);
					footPoint = calculate_foot_point(PtPoint, lineStartPoint, lineEndPoint);
					//detect.drawVertical(cv_src, Point(PtPoint.x(), PtPoint.y()), Point(lineStartPoint.x(), lineStartPoint.y()), Point(lineEndPoint.x(), lineEndPoint.y()));
					update();
				}
			}
			
		}
	}
}











