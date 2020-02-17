#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->ui->graphicsView->minimumSize() = QSize(Block::blockSize * 10, Block::blockSize * 20);
	this->ui->graphicsView->update();

	this->scene = new QGraphicsScene(this);
	this->ui->graphicsView->setScene(this->scene);
	this->ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

	this->timer = new QTimer(this);
	this->timer->setInterval(750);
	connect(timer, &QTimer::timeout, this, &MainWindow::update);

	this->scene->update();

	this->setFocus(Qt::FocusReason::NoFocusReason);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::start()
{

	TetrisShape *shape = new LightningShape();
	this->currentShape = shape;
	scene->addItem(shape);
	this->scene->update();

	this->running = true;
	this->timer->start();
	this->setFocus(Qt::FocusReason::NoFocusReason);
}

void MainWindow::pause()
{
	this->running = false;
}

void MainWindow::play()
{
	this->running = true;
	this->timer->start();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Space)
	{
		if(running)
			pause();
		else
			play();
	}

	if(running)
	{
		switch (event->key())
		{
			case Qt::Key_Up:
			case Qt::Key_Enter-1:
			case Qt::Key_Enter:
				this->currentShape->rotate();
				break;
			case Qt::Key_Left:
				this->currentShape->move(&this->blocks, MoveDirection::moveLeft);
				break;
			case Qt::Key_Right:
				this->currentShape->move(&this->blocks, MoveDirection::moveRight);
				break;
			case Qt::Key_Down:
				this->currentShape->move(&this->blocks, MoveDirection::moveDown);
				break;
		}
		this->scene->update();
	}
}

void MainWindow::update()
{
	if(running)
	{
		if(this->currentShape->isOnGround(&this->blocks))
		{
			this->scene->removeItem(this->currentShape);
			QVector<Block*> blc = this->currentShape->disperse();
			this->blocks.append(blc);
			for (int i = 0;i < blc.length();i ++)
			{
				this->scene->addItem(blc.at(i));
			}

			//this always crushes the program for some reason -> cause of delete this in TetrisShape::disperse();
			//delete this->currentShape;

			this->currentShape = new LightningShape();
			scene->addItem(this->currentShape);
			this->scene->update();
		}
		else
		{
			this->currentShape->move(&this->blocks, MoveDirection::moveDown);
		}

		this->scene->update();
	}
}

void MainWindow::on_startButton_clicked()
{
	start();
}
