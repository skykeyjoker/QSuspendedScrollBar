#ifndef QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_AREA_H
#define QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_AREA_H

#include <QScrollArea>

#include "../Src/QSuspendedScrollBar.h"

class QSuspendedScrollBar_Area : public QScrollArea {
	Q_OBJECT
public:
	explicit QSuspendedScrollBar_Area(QWidget *parent = 0);
	~QSuspendedScrollBar_Area() {}

public slots:
	void slotVerValueChanged(int value);
	void slotHorValueChanged(int value);

protected:
	void resizeEvent(QResizeEvent *e);
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);

private:
	QSuspendedScrollBar *m_horSuspendedScrollBar;
	QSuspendedScrollBar *m_verSuspendedScrollBar;
};


#endif//QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_AREA_H
