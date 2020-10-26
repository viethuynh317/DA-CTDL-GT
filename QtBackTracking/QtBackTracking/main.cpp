#include "QtBackTracking.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtBackTracking w;
	w.show();
	return a.exec();
}
