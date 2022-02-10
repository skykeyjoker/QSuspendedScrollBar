#include "QSuspendedScrollBar_ListWidget.h"

#include <QEnterEvent>
#include <QResizeEvent>

QSuspendedScrollBar_ListWidget::QSuspendedScrollBar_ListWidget(QWidget *parent) : QListWidget(parent) {
	this->setVerticalScrollMode(ScrollPerPixel);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	// Load Style
	QFile styleFile(":/listwidget.qss");
	if (styleFile.open(QFile::ReadOnly)) {
		QString style = styleFile.readAll();
		this->setStyleSheet(style);
		styleFile.close();
	}

	m_suspendedScrollBar = new QSuspendedScrollBar(Qt::Vertical, this);
	connect(this->verticalScrollBar(), SIGNAL(valueChanged(int)),
			m_suspendedScrollBar, SLOT(slotValueChanged(int)));
	connect(m_suspendedScrollBar, SIGNAL(valueChanged(int)),
			this, SLOT(slotValueChanged(int)));
	connect(this->verticalScrollBar(), SIGNAL(rangeChanged(int, int)),
			m_suspendedScrollBar, SLOT(slotRangeChanged(int, int)));
}

void QSuspendedScrollBar_ListWidget::slotValueChanged(int value) {
	this->verticalScrollBar()->setValue(value);
}

void QSuspendedScrollBar_ListWidget::resizeEvent(QResizeEvent *e) {
	int iX = this->width() - 8;
	m_suspendedScrollBar->setGeometry(iX, 1, 8, this->height() - 2);
	return QListWidget::resizeEvent(e);
}

void QSuspendedScrollBar_ListWidget::enterEvent(QEvent *e) {
	if (m_suspendedScrollBar->maximum() > 0)
		m_suspendedScrollBar->show();
	return QListWidget::enterEvent(e);
}

void QSuspendedScrollBar_ListWidget::leaveEvent(QEvent *e) {
	m_suspendedScrollBar->hide();
	return QListWidget::leaveEvent(e);
}
