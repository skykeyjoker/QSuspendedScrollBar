#ifndef QSUSPENDEDSCROLLBAR_QEXAMPLEWIDGET_H
#define QSUSPENDEDSCROLLBAR_QEXAMPLEWIDGET_H

#include <QDebug>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

class QExampleWidget : public QWidget {
	Q_OBJECT
public:
	explicit QExampleWidget(QWidget* parent = 0);
	~QExampleWidget() {}

private:
	QVBoxLayout* mainLay;
	QTabWidget* tabWidget;

	QWidget* listTabWidget;
	QWidget* areaTabWidget;
};


#endif//QSUSPENDEDSCROLLBAR_QEXAMPLEWIDGET_H
