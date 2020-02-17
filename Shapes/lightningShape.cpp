#include "Shapes/lightningShape.h"

LightningShape::LightningShape()
{
	TetrisShape();
	rotate(0);
}

void LightningShape::rotate(uint8_t state)
{
	TetrisShape::rotate(state);

	bool types[3][4][4] =
	{
		{
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
	};

	memcpy(this->blocks, types[rotation], sizeof(types[rotation]));
}
