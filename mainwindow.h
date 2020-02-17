#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>

#include "Shapes/lightningShape.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;

	TetrisShape *currentShape;
	QVector<Block*> blocks;

	QGraphicsScene *scene;
	QTimer *timer;
	bool running = false;

	void start();
	void pause();
	void play();

	void keyPressEvent(QKeyEvent *event);

public slots:
	void update();

private slots:
	void on_startButton_clicked();
};

#endif // MAINWINDOW_H
