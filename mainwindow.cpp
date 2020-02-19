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

	for(int y = 0; y < 20; y++)
		for(int x = 0; x < 10; x++)
			this->blocks[y][x] = nullptr;
	this->scene->update();

	this->setFocus(Qt::FocusReason::NoFocusReason);

	//Block *b = new Block(5,5);
	//b->setColor(Qt::blue);
	//this->scene->addItem(b);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::start()
{
	spawnNewShape();

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

void MainWindow::spawnNewShape()
{
	int shapeType = rand() % 7;
	TetrisShape *shape;

	switch (shapeType)
	{
		case 0:
			shape = new LightningShape();
			break;
		case 1:
			shape = new LightningShapeTwo();
			break;
		case 2:
			shape = new CubeBlock();
			break;
		case 3:
			shape = new TShape();
			break;
		case 4:
			shape = new LongShape();
			break;
		case 5:
			shape = new LShape();
			break;
		case 6:
			shape = new LShapeTwo();
			break;
		default:
			shape = new LightningShape();
			break;
	}

	this->currentShape = shape;
	scene->addItem(shape);
}

void MainWindow::removeRows()
{

	for(int y = 0; y < 20; y++)
	{
		for(int x = 0; x < 10; x++)
			if(this->blocks[y][x] == nullptr)
				goto line_not_full;

		for(int x = 0; x < 10; x++)
		{
			this->scene->removeItem(this->blocks[y][x]);
			delete this->blocks[y][x];
			this->blocks[y][x] = nullptr;
			scene->invalidate();
		}

		/*for(int Y = y-1; Y >= 0; Y--)
		{
			for(int X = 0; X < 10; X++)
			{
				if(this->blocks[Y][X] != nullptr)
				{
					this->blocks[Y][X]->setYPos(Y+1);
				}
			}
		}*/

		line_not_full: scene->update();
	}


/*
	int lines[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	for(int y = 0; y < 20; y++)
	{
		for(int x = 0; x < 10; x++)
		{
			//collision
			if(this->blocks[y][x] != nullptr)
			{
				lines[y]++;
			}
		}
	}

	for(int i = 0; i < 20; i++)
	{
		//if line is full
		if(lines[i] == 10)
		{
			//remove the full row
			for(int x = 0; x < 10; x++)
			{
				//collision
				if(this->blocks[i][x] != nullptr)
				{
					this->scene->removeItem(this->blocks[i][x]);
					delete this->blocks[i][x];
					this->blocks[i][x] = nullptr;
				}
			}

			//move every upper ( < Y) row downwards (y++)
			for(int y = i-1; y >= 0; y--)
			{
				for(int x = 0; x < 10; x++)
				{
					//collision
					if(this->blocks[y][x] != nullptr)
					{
						this->blocks[y][x]->setYPos(y+1);
					}
				}
			}

		}
	}*/
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
				this->currentShape->move(this->blocks, MoveDirection::moveLeft);
				break;
			case Qt::Key_Right:
				this->currentShape->move(this->blocks, MoveDirection::moveRight);
				break;
			case Qt::Key_Down:
				this->currentShape->move(this->blocks, MoveDirection::moveDown);
				break;
		}
		this->scene->update();
	}
}

void MainWindow::update()
{
	if(running)
	{
		this->setFocus(Qt::FocusReason::NoFocusReason);

		if(!this->currentShape->move(this->blocks, MoveDirection::moveDown))
		{
			this->currentShape->disperse(this->blocks, this->scene);

			this->scene->removeItem(this->currentShape);
			delete this->currentShape;

			removeRows();
			spawnNewShape();
		}
		this->scene->update();
	}
}

void MainWindow::on_startButton_clicked()
{
	start();
}
