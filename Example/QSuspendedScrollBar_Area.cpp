#include "QSuspendedScrollBar_Area.h"
QSuspendedScrollBar_Area::QSuspendedScrollBar_Area(QWidget *parent) : QScrollArea(parent) {
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	m_verSuspendedScrollBar = new QSuspendedScrollBar(Qt::Vertical, this);
	connect(this->verticalScrollBar(), SIGNAL(valueChanged(int)),
			m_verSuspendedScrollBar, SLOT(slotValueChanged(int)));
	connect(m_verSuspendedScrollBar, SIGNAL(valueChanged(int)),
			this, SLOT(slotVerValueChanged(int)));
	connect(this->verticalScrollBar(), SIGNAL(rangeChanged(int, int)),
			m_verSuspendedScrollBar, SLOT(slotRangeChanged(int, int)));

	m_horSuspendedScrollBar = new QSuspendedScrollBar(Qt::Horizontal, this);
	connect(this->horizontalScrollBar(), SIGNAL(valueChanged(int)),
			m_horSuspendedScrollBar, SLOT(slotValueChanged(int)));
	connect(m_horSuspendedScrollBar, SIGNAL(valueChanged(int)),
			this, SLOT(slotHorValueChanged(int)));
	connect(this->horizontalScrollBar(), SIGNAL(rangeChanged(int, int)),
			m_horSuspendedScrollBar, SLOT(slotRangeChanged(int, int)));
}

void QSuspendedScrollBar_Area::slotVerValueChanged(int value) {
	this->verticalScrollBar()->setValue(value);
}

void QSuspendedScrollBar_Area::slotHorValueChanged(int value) {
	this->horizontalScrollBar()->setValue(value);
}

void QSuspendedScrollBar_Area::resizeEvent(QResizeEvent *e) {
	int iX = this->width() - 8;
	m_verSuspendedScrollBar->setGeometry(iX, 1, 8, this->height() - 2);

	int iY = this->height() - 8;
	m_horSuspendedScrollBar->setGeometry(1, iY, this->width() - 2, 8);

	return QScrollArea::resizeEvent(e);
}

void QSuspendedScrollBar_Area::enterEvent(QEvent *e) {
	if (m_verSuspendedScrollBar->maximum() > 0)
		m_verSuspendedScrollBar->show();
	if (m_horSuspendedScrollBar->maximum() > 0)
		m_horSuspendedScrollBar->show();
	return QScrollArea::enterEvent(e);
}

void QSuspendedScrollBar_Area::leaveEvent(QEvent *e) {
	m_verSuspendedScrollBar->hide();
	m_horSuspendedScrollBar->hide();
	return QScrollArea::leaveEvent(e);
}
