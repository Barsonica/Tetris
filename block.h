#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVector>
#include <QPainter>
#include <QDebug>

class Block : public QGraphicsItem
{
public:
	Block();
	Block(int x, int y);

	void setColor(QColor color);
	QPoint getPosition();
	void setXPos(int x);
	void setYPos(int y);

	QRectF boundingRect() const override;
	void paint(QPainter *painter,
			   const QStyleOptionGraphicsItem *option,
			   QWidget *widget
			   )override;

	static int blockSize;

private:
	QPoint position;
	QColor color;
};

#endif // BLOCK_H
