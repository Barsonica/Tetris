#ifndef LSHAPE_H
#define LSHAPE_H

#include "longshape.h"

class LShape : public TetrisShape
{
public:
	LShape() : TetrisShape(Qt::blue)
	{
		bool types[4][4][4] =
		{
			{
				{1,0,0,0},
				{1,0,0,0},
				{1,1,0,0},
				{0,0,0,0}
			},
			{
				{1,1,1,0},
				{1,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				{0,0,1,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
		};

		memcpy(this->blockRotations, types, sizeof(types));
		rotate(0);
	}
};

#endif // LSHAPE_H
