#ifndef SHAPE_H
#define SHAPE_H

#include "block.h"

enum MoveDirection
{
	moveLeft,
	moveRight,
	moveDown
};


class TetrisShape : public QGraphicsItem
{
public:
	TetrisShape();

	virtual void rotate(uint8_t state = 5);
	void move(QVector<Block*> *blockList, MoveDirection direction = MoveDirection::moveDown);
	bool isOnGround(QVector<Block*> *blockList);

	QVector<Block*> disperse();

	QRectF boundingRect() const override;
	void paint(QPainter *painter,
			   const QStyleOptionGraphicsItem *option,
			   QWidget *widget
			   )override;

private:
	QPoint pos;
	QColor color;

protected:
	bool blocks[4][4];
	uint8_t rotation;
};

#endif // SHAPE_H
