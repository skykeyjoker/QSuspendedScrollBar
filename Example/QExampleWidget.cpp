#include "QExampleWidget.h"

#include <QLabel>

#include "QSuspendedScrollBar_Area.h"
#include "QSuspendedScrollBar_ListWidget.h"

QExampleWidget::QExampleWidget(QWidget *parent) : QWidget(parent) {
	this->setMinimumSize(800, 600);

	mainLay = new QVBoxLayout(this);
	tabWidget = new QTabWidget;
	mainLay->addWidget(tabWidget);

	listTabWidget = new QWidget;
	QVBoxLayout *listTabLay = new QVBoxLayout(listTabWidget);
	QSuspendedScrollBar_ListWidget *suspendedScrollBarListWidget = new QSuspendedScrollBar_ListWidget();
	listTabLay->addWidget(suspendedScrollBarListWidget);
	tabWidget->addTab(listTabWidget, "QListWidget");
	for (int i = 0; i < 100; ++i) {
		suspendedScrollBarListWidget->insertItem(suspendedScrollBarListWidget->count(), "List " + QString::number(i));
	}

	areaTabWidget = new QWidget;
	QVBoxLayout *areaTabLay = new QVBoxLayout(areaTabWidget);
	QSuspendedScrollBar_Area *suspendedScrollBarArea = new QSuspendedScrollBar_Area();
	areaTabLay->addWidget(suspendedScrollBarArea);
	tabWidget->addTab(areaTabWidget, "QScrolledArea");
	QLabel *picLabel = new QLabel;
	picLabel->setPixmap(QPixmap("pic.jpg"));
	suspendedScrollBarArea->setWidget(picLabel);
}
