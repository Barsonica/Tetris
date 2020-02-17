#ifndef TSHAPE_H
#define TSHAPE_H

#include "../tetrisshape.h"

class LightningShape : public TetrisShape
{
public:
	LightningShape();
	void rotate(uint8_t state = 5) override;
};

#endif // TSHAPE_H
