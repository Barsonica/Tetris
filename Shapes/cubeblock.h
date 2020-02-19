#ifndef CUBEBLOCK_H
#define CUBEBLOCK_H

#include "tshape.h"

class CubeBlock : public TetrisShape
{
public:
	CubeBlock() : TetrisShape(Qt::yellow)
	{
		bool types[4][4][4] =
		{
			{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,0,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
		};

		memcpy(this->blockRotations, types, sizeof(types));
		rotate(0);
	}
};

#endif // CUBEBLOCK_H
