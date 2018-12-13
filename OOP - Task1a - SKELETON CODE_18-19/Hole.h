#ifndef HoleH 
#define HoleH 

#include "constants.h"
// None of these are constants because every attribute is being changed
class Hole
{
private:
	int x_;
	int y_;
	char symbol_;
public:
	Hole::Hole()
	{
	}

	Hole::Hole(int x, int y)
	{
		symbol_ = HOLE;
		x_ = x;
		y_ = y;
	}

	const int get_x();
	const int get_y();
	const char get_symbol() const;
	bool is_at_position(int, int);
};

#endif