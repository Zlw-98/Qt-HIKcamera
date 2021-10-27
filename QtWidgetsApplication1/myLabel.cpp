
#include "myLabel.h"
#include "QtWidgetsApplication1.h"

myLabel::myLabel(QWidget* parent) :QLabel(parent)
           ,m_currentCaptureState(initCapture)
{
	//QList<QRect> Rects[2];    //����������ʱ���ܻ��õ�
	//clear();

}

int myLabel::getMode(int x)
{
	return m_Mode = (Mode)x;
}

int myLabel::getClickedBtn(int x)
{
	return m_clickedBtn = (clickedBtn)x;  //����ֵ����ö�ٱ�����������ǿ������ת����
}

//������ο�����
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

//��ȡ��ǰlabel�µ�ͼƬ;
QPixmap myLabel::getPix(QPixmap map)
{
	return m_Pixmap = map;
}


//�����¼�
void myLabel::paintEvent(QPaintEvent* event)
{
	if (m_Mode == MEASURE) {
		//��-�����
		if (m_clickedBtn == on_ptptdisBtn_clicked) {
			QLabel::paintEvent(event);//�����У������ñ���ͼƬ��ʾ����
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
		//��-�߾���
		else if (m_clickedBtn == on_ptlindisBtn_clicked) {
			QLabel::paintEvent(event);//�����У������ñ���ͼƬ��ʾ����
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
					QString data = QString("%1").arg(num);    //��ʾ����num
					painter.drawText((PtPoint.x() + footPoint.x()) / 2, (PtPoint.y() + footPoint.y()) / 2, data);

					// ���ӳ�����
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
		QLabel::paintEvent(event);//�����У������ñ���ͼƬ��ʾ����
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

//��갴��
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
				//setCursor(Qt::ArrowCursor);   //�ı�����״
				//���Ϳ�ʼλ�������źŸ�������
				emit StartPointSignal(StartPoint);
				m_currentCaptureState = beginCaptureImage;
			}
			else {
				StartPoint = e->pos();
				EndPoint = e->pos();
				//setCursor(Qt::ArrowCursor);   //�ı�����״
				//���Ϳ�ʼλ�������źŸ�������
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
			//���ð���flagΪtrue
			isPressed = true;
			if (m_currentCaptureState == initCapture)
			{
				StartPoint = e->pos();
				//EndPoint = e->pos();
				setCursor(Qt::ArrowCursor);   //�ı�����״
				//���Ϳ�ʼλ�������źŸ�������
				emit StartPointSignal(StartPoint);
				//    qDebug()<<"��ʼ"<<StartPoint;
				m_currentCaptureState = beginCaptureImage;
			}
			else if (isPressPointInSelectRect(e->pos()))//�ھ����ڿ�����ʱ������꣬����϶�ͼƬ
			{
				m_startMovePoint = e->pos();
				setCursor(Qt::SizeAllCursor);   //�ı�����״,�ֵ���״
				emit StartMoveRectSignal(getSelectRect());
				m_currentCaptureState = beginMoveCaptureArea;
				//m_endMovePoint = e->pos();
				//emit MoveRectSignal(m_endMovePoint);
				//update();
			}

			else {
				StartPoint = e->pos();
				EndPoint = e->pos();
				setCursor(Qt::ArrowCursor);   //�ı�����״
				//���Ϳ�ʼλ�������źŸ�������
				emit StartPointSignal(StartPoint);
				m_currentCaptureState = beginCaptureImage;
				//    qDebug()<<"��ʼ"<<StartPoint;
			}

		}
	}
}

//����ƶ�
void myLabel::mouseMoveEvent(QMouseEvent* e)
{
	if (m_Mode == MEASURE) {
		if (m_clickedBtn == on_ptptdisBtn_clicked) {
			EndPoint = e->pos();
			//���ͽ���λ�������źŸ�������
			emit StopPointSignal(EndPoint);
			update();//����label��ʾ ����paintEvent�¼�
		}
		else {
			EndPoint = e->pos();
			//���ͽ���λ�������źŸ�������
			emit StopPointSignal(EndPoint);
			update();//����label��ʾ ����paintEvent�¼�
		}
		
	}
	else {
		// ��������Ƿ���ѡ�����������������ʽ;
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
			//��ý����������
			EndPoint = e->pos();
			//���ͽ���λ�������źŸ�������
			emit StopPointSignal(EndPoint);
			update();//����label��ʾ ����paintEvent�¼�
			//      qDebug()<<"�����ƶ�"<<EndPoint;
		}
		else if (m_currentCaptureState == beginMoveCaptureArea)
		{
			m_endMovePoint = e->pos();
			emit StartMoveRectSignal(getSelectRect());
			update();
		}
	}
}

//���̧��
void myLabel::mouseReleaseEvent(QMouseEvent* e)
{
	isPressed = false;
	if (m_Mode == MEASURE) {
		
		if (m_clickedBtn == on_ptptdisBtn_clicked) {
			EndPoint = e->pos();
			update();
			getPt();    //������
		}
		else {
			//EndPoint = e->pos();
			//update();
			if (lastPtPoint.isNull()) {
				EndPoint = e->pos();
				getPt();    //������
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
			getDistrict();                //��ȡROI
		}
		else if (m_currentCaptureState == beginMoveCaptureArea)
		{
			m_currentCaptureState = finishMoveCaptureArea;
			m_endMovePoint = e->pos();
			setCursor(Qt::ArrowCursor);   //�ı�����״
			update();
			getDistrict();                //��ȡROI
		}
	}
}


// ��ǰ��������Ƿ���ѡȡ�ľ���������;
bool myLabel::isPressPointInSelectRect(QPointF mousePressPoint)
{
	QRectF selectRect = m_currentSelectRect;
	if (selectRect.contains(mousePressPoint))
	{
		return true;
	}
	return false;

}

// ����beginPoint , endPoint ��ȡ��ǰѡ�еľ���
QRectF myLabel::getRect(const QPointF& startPoint, const QPointF& endPoint)
{
	int x, y, width, height;
	width = qAbs(startPoint.x() - endPoint.x());
	height = qAbs(startPoint.y() - endPoint.y());
	x = startPoint.x() < endPoint.x() ? startPoint.x() : endPoint.x();
	y = startPoint.y() < endPoint.y() ? startPoint.y() : endPoint.y();

	QRect selectedRect = QRect(x, y, width, height);
	// �������Ϊ��ʱ������ͼ����;
	// ���Կ�QQ��ͼ����ѡȡ��ͼ����Ϊ��ʱĬ��Ϊ10;
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

// ��ȡ�ƶ���ѡ�еľ���;
QRectF myLabel::getMoveRect()
{
	// ͨ��getMovePoint�����ȼ�鵱ǰ�Ƿ��ƶ�������Ļ;
	movePoint = getMovePoint();
	newStartPoint = StartPoint + movePoint;
	newEndPoint = EndPoint + movePoint;
	// �����ƶ�ѡ��ʱ���µ�ǰStartPoint , EndPoint,��ֹ��һ�β���ʱ��ȡ��ͼƬ������;
	if (m_currentCaptureState == finishMoveCaptureArea)
	{
		StartPoint = newStartPoint;
		EndPoint = newEndPoint;
		m_startMovePoint = QPoint(0, 0);
		m_endMovePoint = QPoint(0, 0);
	}
	return getRect(newStartPoint, newEndPoint);
}

// ���ݵ�ǰ��ȡ״̬��ȡ��ǰѡ�еĽ�ͼ����;
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
	//�˴��ᵼ���ƶ����ο�ʱ��������λ��

	//�ƶ�ѡ���Ƿ񳬳���Ļ��߽�;
	if (currentRect.topLeft().x() + movePoint.x() < 0)
	{
		movePoint.setX(0 - currentRect.topLeft().x());
	}
	//�ƶ�ѡ���Ƿ񳬳���Ļ�ϱ߽�;
	if (currentRect.topLeft().y() + movePoint.y() < 0)
	{
		movePoint.setY(0 - currentRect.topLeft().y());
	}
	//�ƶ�ѡ���Ƿ񳬳���Ļ�ұ߽�;
	if (currentRect.bottomRight().x() + movePoint.x() > m_Pixmap.size().width())
	{
		movePoint.setX(m_Pixmap.size().width() - currentRect.bottomRight().x());
	}
	//�ƶ�ѡ���Ƿ񳬳���Ļ�±߽�;
	if (currentRect.bottomRight().y() + movePoint.y() > m_Pixmap.size().height())
	{
		movePoint.setY(m_Pixmap.size().height() - currentRect.bottomRight().y());
	}
	

	return movePoint;
}





//��ȡ����
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
	//��ֹ���ֻ�����һ�¿�߶�Ϊ0�ᱨ��
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
	//��ʾroi��ͼ
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


// ���㴹�������    ps��������ĵ㣬�߶���㣬�߶��յ�
QPoint calculate_foot_point(QPointF ps0, QPointF ps1, QPointF ps2)
{
	QPoint p(0, 0);                // ����
	if (ps1.x() == ps2.x()) // ����x�ᴹֱ
	{
		p.setX(ps1.x());
		p.setY(ps0.y());
	}
	else if (ps1.y() == ps2.y()) // ����y�ᴹֱ
	{
		p.setX(ps0.x());
		p.setY(ps1.y());
	}
	else // ����x�ᣬy�ᶼ����ֱ
	{
		int a1 = -(ps2.y() - ps1.y());
		int b1 = ps2.x() - ps1.x();
		int c1 = (ps2.y() - ps1.y()) * ps1.x() - (ps2.x() - ps1.x()) * ps1.y();
		p.setX((b1 * b1 * ps0.x() - a1 * b1 * ps0.y() - a1 * c1) / (a1 * a1 + b1 * b1));
		p.setY((a1 * a1 * ps0.y() - a1 * b1 * ps0.x() - b1 * c1) / (a1 * a1 + b1 * b1));
	}

	return p;
}
// ����㵽ֱ�ߵľ���
float calculate_distance(QPoint ps0, QPoint ps1, QPoint ps2)
{
	float d = 0;                    // ����
	if (ps1.x() == ps2.x()) // ����x�ᴹֱ
	{
		d = abs(ps1.x() - ps0.x());
	}
	else if (ps1.y() == ps2.y()) // ����y�ᴹֱ
	{
		d = abs(ps1.y() - ps0.y());
	}
	else // ����x�ᣬy�ᶼ����ֱ
	{
		int a1 = -(ps2.y() - ps1.y());
		int b1 = ps2.x() - ps1.x();
		int c1 = (ps2.y() - ps1.y()) * ps1.x() - (ps2.x() - ps1.x()) * ps1.y();
		d = abs(a1 * ps0.x() + b1 * ps0.y() + c1) / sqrt(a1 * a1 + b1 * b1);
	}
	return d;
}



//opencv��ȡROI
void myLabel::getDistrict()
{
	cv::destroyAllWindows();//������д���
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
		//��ʾroi��ͼ
		cv_dst = cv_src(cv_rect).clone();

		// �������Ϊ��ʱ������ͼ����;
		// ���Կ�QQ��ͼ����ѡȡ��ͼ����Ϊ��ʱĬ��Ϊ20;
		if (selectedRect.width() == 0|| selectedRect.height()==0)
		{
			return;
		}
		else {
			if (m_clickedBtn == on_lineBtn_clicked) {
				Detect detect(this);
				detect.detectLine(cv_dst);
				//��opencvת�����굽Qt
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
				//��opencvת�����굽Qt
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
		//��ʾroi��ͼ
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
				//��opencvת�����굽Qt
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











