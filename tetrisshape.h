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
	void rotate(uint8_t state = 5);
	bool move(Block *blockArray[20][10], MoveDirection direction = MoveDirection::moveDown);
	void disperse(Block *blocks[20][10], QGraphicsScene *scene);

	QRectF boundingRect() const override;
	void paint(QPainter *painter,
			   const QStyleOptionGraphicsItem *option,
			   QWidget *widget
			   )override;

private:
	QPoint position;

protected:
	TetrisShape();
	TetrisShape(QColor color);

	bool blocks[4][4];
	bool blockRotations[4][4][4];
	uint8_t rotation;
	QColor color;
};

#endif // SHAPE_H
