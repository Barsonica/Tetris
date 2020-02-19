#include "tetrisshape.h"

TetrisShape::TetrisShape()
{
	this->setX(0);
	this->setY(0);
	this->position.setX(3);
}

TetrisShape::TetrisShape(QColor color)
{
	this->color = color;
	TetrisShape();
}

void TetrisShape::rotate(uint8_t state)
{
	if(state < 4)
	{
		rotation = state;
	}
	else
	{
		rotation++;
		if(rotation == 4)
			rotation = 0;
	}

	memcpy(this->blocks, blockRotations[rotation], sizeof(blockRotations[rotation]));
}

bool TetrisShape::move(Block *blockArray[20][10], MoveDirection direction)
{
	int newX = this->position.x();
	int newY = this->position.y();

	switch (direction)
	{
		case moveLeft:
			newX = this->position.x()-1;
			break;
		case moveRight:
			newX = this->position.x()+1;
			break;
		case moveDown:
			newY = this->position.y()+1;
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
					return false;

				if(blockX == 10 | blockX < 0)
					return false;

				for(int y = 0; y < 20; y++)
				{
					for(int x = 0; x < 10; x++)
					{
						if(blockArray[y][x] != nullptr)
						{
							//collision
							if(blockArray[y][x]->getPosition() == QPoint(blockX,blockY))
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	// no collision detected

	this->position.setX(newX);
	this->position.setY(newY);
	return true;
}

void TetrisShape::disperse(Block *blockList[20][10], QGraphicsScene *scene)
{

	for(int i = 0; i < 4; i++)
	{
		for(int a = 0; a < 4; a++)
		{
			if(this->blocks[i][a])
			{
				int blockX = this->position.x() + a;
				int blockY = this->position.y() + i;

				Block *b = new Block(blockX, blockY);
				b->setColor(this->color);

				blockList[blockY][blockX] = b;
				scene->addItem(b);

			}
		}
	}
}

QRectF TetrisShape::boundingRect() const
{
	return QRectF(this->position.x(),this->position.y(),Block::blockSize,Block::blockSize);
}

void TetrisShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->resetTransform();

	QBrush b = painter->brush();
	b.setColor(this->color);
	b.setStyle(Qt::SolidPattern);
	painter->setBrush(b);

	for(int i = 0; i < 4; i++)
	{
		for(int a = 0; a < 4; a++)
		{
			if(this->blocks[i][a])
			{
				painter->drawRect(this->position.x() * Block::blockSize + a * Block::blockSize,
								  this->position.y() * Block::blockSize + i * Block::blockSize,
								  Block::blockSize,
								  Block::blockSize
								  );
			}
		}
	}
}
