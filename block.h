#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include <QVector>
#include <QPainter>
#include <QDebug>

class Block : public QGraphicsItem
{
public:
	Block();
	Block(int x, int y);

	void setColor(QColor color);
	bool collides(QVector<Block*> *blockList);
	QPoint getPos();

	QRectF boundingRect() const override;
	void paint(QPainter *painter,
			   const QStyleOptionGraphicsItem *option,
			   QWidget *widget
			   )override;

	static int blockSize;

private:
	QPoint pos;
	QColor color;
};

#endif // BLOCK_H
