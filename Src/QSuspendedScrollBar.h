#ifndef QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_H
#define QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_H

#include <QScrollBar>

class QSuspendedScrollBar : public QScrollBar {
	Q_OBJECT
public:
	explicit QSuspendedScrollBar(Qt::Orientation t, QWidget* parent = 0);
	~QSuspendedScrollBar() {}

public slots:
	void slotValueChanged(int);

	void slotRangeChanged(int min, int max);
};


#endif//QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_H
