#include "block.h"

int Block::blockSize = 30;

Block::Block()
{

}

Block::Block(int x, int y)
{
	this->pos.setX(x);
	this->pos.setY(y);
}

void Block::setColor(QColor color)
{
	this->color = color;
}

bool Block::collides(QVector<Block *> *blockList)
{
	if(pos.y() > 20)
		return true;

	if(pos.x() > 10 | pos.x() < 0)
		return true;

	for(int i = 0; i < blockList->length(); i++)
	{
		if(blockList->at(i)->getPos() == pos)
			return true;
	}

	return false;
}

QPoint Block::getPos()
{
	return pos;
}

QRectF Block::boundingRect() const
{
	return QRect(this->pos.x() * blockSize, this->pos.y() * blockSize, blockSize, blockSize);
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawRect(boundingRect());
}
