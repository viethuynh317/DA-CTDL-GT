#include "QtBackTracking.h"
#include <QLabel>
#include <QRectF>
#include <QMessageBox>

QtBackTracking::QtBackTracking(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	int width = 50;
	int height = 50;
	int offset = 50;
	int margin = 20;

	init();

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {

			lables[i][j] = new QLabel(this);
			lables[i][j]->setFrameStyle(QFrame::Panel | QFrame::Sunken);
			lables[i][j]->setAlignment(Qt::AlignCenter);
			lables[i][j]->setGeometry(QRect(offset + i * height, offset + j * width, height, width));
			if ((i + j) % 2 == 0) {
				lables[i][j]->setStyleSheet("QLabel { background-color : red; color : blue; }");
			}
			else {
				lables[i][j]->setStyleSheet("QLabel { background-color : white; color : blue; }");
			}

		}
	}

	// Add button
	btnOne = new QPushButton("Cho ngua nhay tu do", this);
	btnOne->setGeometry(QRect(offset, offset + margin + MAX * height, 200, 40));
	connect(btnOne, &QPushButton::clicked, this, &QtBackTracking::functionOne);

	btnTwo = new QPushButton("Cho ngua nhay vao o thap nhat", this);
	btnTwo->setGeometry(QRect(offset, offset + margin + (MAX + 1) * height, 200, 40));
	connect(btnTwo, &QPushButton::clicked, this, &QtBackTracking::functionTwo);

	btnThree = new QPushButton("Cho ngua nhay theo quay lui", this);
	btnThree->setGeometry(QRect(offset, offset + margin + (MAX + 2) * height, 200, 40));
	connect(btnThree, &QPushButton::clicked, this, &QtBackTracking::functionThree);

	QLabel* lableX = new QLabel("vi tri cot", this);
	lableX->setGeometry(QRect(offset * 2 + 200, offset + margin + (MAX)*height, 80, 40));
	editTextX = new QTextEdit(this);
	editTextX->setGeometry(QRect(offset * 3 + 200, offset + margin + (MAX)*height, 100, 40));

	QLabel* lableY = new QLabel("vi tri dong", this);
	lableY->setGeometry(QRect(offset * 2 + 200, offset + margin + (MAX + 1) * height, 80, 40));
	editTextY = new QTextEdit(this);
	editTextY->setGeometry(QRect(offset * 3 + 200, offset + margin + (MAX + 1) * height, 100, 40));

	QPushButton* btnClear = new QPushButton("Xoa du lieu", this);
	btnClear->setGeometry(QRect(offset * 2 + 200, offset + margin + (MAX + 2) * height, 150, 40));
	connect(btnClear, &QPushButton::clicked, this, &QtBackTracking::clearData);

	this->setFixedSize(QSize(700, 700));
}

void QtBackTracking::functionOne()
{
	int x;
	int y;

	QString textX = editTextX->toPlainText();
	QString textY = editTextY->toPlainText();
	x = textX.toInt();
	y = textY.toInt();

	if (x < 1 || y < 1 || x > 8 || y > 8) {
		QMessageBox::about(this, "Message", "Ban phai nhap hop le");
		return;
	}

	init();
	randomRun(x - 1, y - 1);
	showData();
}

void QtBackTracking::functionTwo()
{
	int x;
	int y;

	QString textX = editTextX->toPlainText();
	QString textY = editTextY->toPlainText();
	x = textX.toInt();
	y = textY.toInt();

	if (x < 1 || y < 1 || x > 8 || y > 8) {
		QMessageBox::about(this, "Message", "Ban phai nhap hop le");
		return;
	}

	init();
	minimumRun(x - 1, y - 1);
	showData();
}

void QtBackTracking::functionThree()
{
	int x;
	int y;

	QString textX = editTextX->toPlainText();
	QString textY = editTextY->toPlainText();
	x = textX.toInt();
	y = textY.toInt();

	if (x < 1 || y < 1 || x > 8 || y > 8) {
		QMessageBox::about(this, "Message", "Ban phai nhap hop le");
		return;
	}

	init();
	bEnd = false;
	bCount = 1;
	backTrackRun(x - 1, y - 1);
	showData();

}

void QtBackTracking::clearData()
{
	init();
	showData();
}

void QtBackTracking::init()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = 0;
		}
	}
}

void QtBackTracking::showData()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {

			lables[i][j]->setText("");
			if (arr[i][j] == 0) {
				continue;
			}
			QString value = QString::number(arr[i][j]);
			lables[i][j]->setText(value);
		}
	}
}

bool QtBackTracking::isValid(int x, int y)
{
	if (x < 0 || x > 7)
		return false;
	else if (y < 0 || y > 7)
		return false;
	else if (arr[x][y] > 0)
		return false;
	return true;
}

bool QtBackTracking::isRunXY(int x, int y)
{
	for (int i = 0; i < MAX; i++) {
		int u = x + X[i];
		int v = y + Y[i];
		if (isValid(u, v))
			return true;
	}

	return false;
}

void QtBackTracking::randomRun(int x, int y)
{
	arr[x][y] = 1;
	int count = 2;
	//srand((int)time(0));
	int u = x;
	int v = y;

	do
	{

		int index = rand() % MAX;
		if (isValid(u + X[index], v + Y[index])) {
			u = u + X[index];
			v = v + Y[index];
			arr[u][v] = count;
			count++;
		}

	} while (isRunXY(u, v));
}

int QtBackTracking::numberRun(int x, int y)
{
	int result = 0;

	for (int i = 0; i < MAX; i++) {
		if (isValid(x + X[i], y + Y[i])) {
			result++;
		}
	}

	return result;
}

void QtBackTracking::minimumRun(int x, int y)
{
	arr[x][y] = 1;
	int count = 2;
	int u = x;
	int v = y;

	do
	{
		int* numbers = new int[MAX];

		for (int i = 0; i < MAX; i++) {
			numbers[i] = numberRun(u + X[i], v + Y[i]);
		}

		int indexMin = 0;
		int min = MAX;
		for (int i = 0; i < MAX; i++) {
			if (numbers[i] < min && isValid(u + X[i], v + Y[i])) {
				min = numbers[i];
				indexMin = i;
			}
		}

		u = u + X[indexMin];
		v = v + Y[indexMin];
		arr[u][v] = count;
		count++;

	} while (isRunXY(u, v));
}

void QtBackTracking::backTrackRun(int x, int y)
{
	arr[x][y] = bCount;

	if (bCount == 64) {
		bEnd = true;
		return;
	}

	int* numbers = new int[MAX];

	for (int i = 0; i < MAX; i++) {
		numbers[i] = numberRun(x + X[i], y + Y[i]);
	}

	int indexMin = 0;
	int min = MAX;
	for (int i = 0; i < MAX; i++) {
		if (numbers[i] < min && isValid(x + X[i], y + Y[i])) {
			min = numbers[i];
			indexMin = i;
		}
	}

	// Tim dc vi tri bang phuong phap duyet uu tien
	int number = 0;
	while (number < 8) {
		int position = indexMin % 8;
		int u = x + X[position];
		int v = y + Y[position];
		if (isValid(u, v)) {
			bCount++;
			backTrackRun(u, v);
		}
		if (bEnd) {
			return;
		}
		indexMin++;
		number++;
	}

	bCount--;
	arr[x][y] = 0;
}


