#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtBackTracking.h"
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>


class QtBackTracking : public QMainWindow
{
	Q_OBJECT

public:
	QtBackTracking(QWidget* parent = Q_NULLPTR);

	void init();
	void showData();
	bool isValid(int x, int y);
	bool isRunXY(int x, int y);
	void randomRun(int x, int y);
	int numberRun(int x, int y);
	void minimumRun(int x, int y);
	void backTrackRun(int x, int y);

public slots:
	void functionOne();
	void functionTwo();
	void functionThree();
	void clearData();

private:
	Ui::QtBackTrackingClass ui;
	QLabel* lables[8][8];
	QTextEdit* editTextX;
	QTextEdit* editTextY;
	QPushButton* btnOne;
	QPushButton* btnTwo;
	QPushButton* btnThree;

	const int MAX = 8;
	int arr[8][8];
	//int numbercount = 0;
	int bCount = 1;
	bool bEnd = false;
	int X[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int Y[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
};
