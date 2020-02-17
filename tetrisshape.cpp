#include "tetrisshape.h"

TetrisShape::TetrisShape()
{

}

void TetrisShape::rotate(uint8_t state)
{
	if(state < 3)
	{
		rotation = state;
	}
	else
	{
		rotation++;
		if(rotation > 2)
			rotation = 0;
	}
}

void TetrisShape::move(QVector<Block*> *blockList, MoveDirection direction)
{
	int newX = this->pos.x();
	int newY = this->pos.y();

	switch (direction)
	{
		case moveLeft:
			newX = this->pos.x()-1;
			break;
		case moveRight:
			newX = this->pos.x()+1;
			break;
		case moveDown:
			newY = this->pos.y()+1;
			break;
	}

	for(int i = 0; i < 4; i++)
	{
		for(int a = 0; a < 4; a++)
		{
			if(this->blocks[i][a])
			{
				int blockX = newX + a;
				int blockY = newY + i;

				if(blockY == 20)
					return;

				if(blockX == 10 | blockX < 0)
					return;

				for(int i = 0; i < blockList->length(); i++)
				{
					//collision
					if(blockList->at(i)->getPos() == QPoint(blockX,blockY))
					{
						return;
					}
				}
			}
		}
	}
	// no collision detected

	this->pos.setX(newX);
	this->pos.setY(newY);
}

bool TetrisShape::isOnGround(QVector<Block*> *blockList)
{
	for(int i = 0; i < 4; i++)
	{
		for(int a = 0; a < 4; a++)
		{
			if(this->blocks[i][a])
			{
				if(pos.y() + i == 19)
					return true;
			}

			for(int b = 0; b < blockList->length(); b++)
			{
				if(blockList->at(b) != nullptr)
				{
					if(blockList->at(b)->getPos() == QPoint(pos.x() + a, pos.y() + i + 1))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

QVector<Block*> TetrisShape::disperse()
{
	QVector<Block*> blocks;

	for(int i = 0; i < 4; i++)
	{
		for(int a = 0; a < 4; a++)
		{
			if(this->blocks[i][a])
			{
				Block *b = new Block(pos.x() + a, pos.y() + i);
				blocks.append(b);
			}
		}
	}

	delete this;
	return blocks;
}

QRectF TetrisShape::boundingRect() const
{

}

void TetrisShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	for(int i = 0; i < 4; i++)
	{
		for(int a = 0; a < 4; a++)
		{
			if(this->blocks[i][a])
			{
				painter->drawRect(this->pos.x() * Block::blockSize + a * Block::blockSize,
								  this->pos.y() * Block::blockSize + i * Block::blockSize,
								  Block::blockSize,
								  Block::blockSize
								  );
			}
		}
	}
}
