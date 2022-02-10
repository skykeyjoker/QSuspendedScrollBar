#ifndef QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_LISTWIDGET_H
#define QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_LISTWIDGET_H

#include <QDebug>
#include <QListWidget>

#include "../Src/QSuspendedScrollBar.h"

class QSuspendedScrollBar_ListWidget : public QListWidget {
	Q_OBJECT
public:
	explicit QSuspendedScrollBar_ListWidget(QWidget *parent = 0);
	~QSuspendedScrollBar_ListWidget() {}

public slots:
	void slotValueChanged(int value);

protected:
	void resizeEvent(QResizeEvent *e);
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);

private:
	QSuspendedScrollBar *m_suspendedScrollBar;
};


#endif//QSUSPENDEDSCROLLBAR_QSUSPENDEDSCROLLBAR_LISTWIDGET_H
