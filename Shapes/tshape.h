#ifndef TSHAPE_H
#define TSHAPE_H

#include "lightningshapetwo.h"

class TShape : public TetrisShape
{
public:
	TShape() : TetrisShape(QColor::fromRgb(160,0,240))
	{
		bool types[4][4][4] =
		{
			{
				{1,1,1,0},
				{0,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,0,0,0},
				{1,1,0,0},
				{1,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
		};

		memcpy(this->blockRotations, types, sizeof(types));
		rotate(0);
	}
};

#endif // TSHAPE_H
