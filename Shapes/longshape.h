#ifndef LONGSHAPE_H
#define LONGSHAPE_H

#include "cubeblock.h"

class LongShape : public TetrisShape
{
public:
	LongShape() : TetrisShape(QColor::fromRgb(0,240,239))
	{
		bool types[4][4][4] =
		{
			{
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0}
			},
			{
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0},
				{1,0,0,0}
			},
			{
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
		};

		memcpy(this->blockRotations, types, sizeof(types));
		rotate(0);
	}
};

#endif // LONGSHAPE_H
