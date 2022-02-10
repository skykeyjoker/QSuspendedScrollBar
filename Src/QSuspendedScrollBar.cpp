#include "QSuspendedScrollBar.h"

#include <QFile>

QSuspendedScrollBar::QSuspendedScrollBar(Qt::Orientation t, QWidget *parent) : QScrollBar(t, parent) {
	// Load Style
	QFile styleFile(":/scrollbar.qss");
	if (styleFile.open(QFile::ReadOnly)) {
		QString style = styleFile.readAll();
		this->setStyleSheet(style);
		styleFile.close();
	}
	this->setRange(0, 0);
	this->hide();
}
void QSuspendedScrollBar::slotValueChanged(int value) {
	this->setValue(value);
}
void QSuspendedScrollBar::slotRangeChanged(int min, int max) {
	this->setMinimum(min);
	this->setRange(0, max);
	this->setPageStep(0.75 * (this->height() + max));
	if (max <= 0)
		this->hide();
}
