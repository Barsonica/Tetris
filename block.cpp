#include "block.h"

int Block::blockSize = 30;

Block::Block()
{}

Block::Block(int x, int y)
{
	this->position.setX(x);
	this->position.setY(y);
}

void Block::setColor(QColor color)
{
	this->color = color;
}

QPoint Block::getPosition()
{
	return this->position;
}

void Block::setXPos(int x)
{
	this->position.setX(x);
}

void Block::setYPos(int y)
{
	this->position.setY(y);
}

QRectF Block::boundingRect() const
{
	return QRect(this->position.x() * blockSize, this->position.y() * blockSize, blockSize, blockSize);
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->resetTransform();

	QBrush b = painter->brush();
	b.setColor(this->color);
	b.setStyle(Qt::SolidPattern);
	painter->setBrush(b);

	painter->drawRect(boundingRect());

	//qDebug() << "blocks";
	//qDebug() << QString::number(getPosition().x()) + " : " + QString::number(getPosition().y());
	//qDebug() << "blocks";
}
