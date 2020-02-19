#ifndef LIGHTNINGSHAPETWO_H
#define LIGHTNINGSHAPETWO_H

#include "lightningShape.h"

class LightningShapeTwo : public TetrisShape
{
public:
	LightningShapeTwo() : TetrisShape(Qt::green)
	{
		bool types[4][4][4] =
		{
			{
				{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0}
			},
		};

		memcpy(this->blockRotations, types, sizeof(types));
		rotate(0);
	}
};

#endif // LIGHTNINGSHAPETWO_H
