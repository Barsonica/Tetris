#ifndef LSHAPETWO_H
#define LSHAPETWO_H

#include "lshape.h"

class LShapeTwo : public TetrisShape
{
public:
	LShapeTwo() : TetrisShape(QColor::fromRgb(240,160,1))
	{
		bool types[4][4][4] =
		{
			{
				{0,1,0,0},
				{0,1,0,0},
				{1,1,0,0},
				{0,0,0,0}
			},
			{
				{1,0,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,1,0},
				{0,0,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
		};

		memcpy(this->blockRotations, types, sizeof(types));
		rotate(0);
	}
};

#endif // LSHAPETWO_H
