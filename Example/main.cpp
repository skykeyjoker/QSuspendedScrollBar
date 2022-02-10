#include <QApplication>

#include "QExampleWidget.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	QExampleWidget widget;
	widget.show();

	return app.exec();
}
