#include "Hole.h"

const int Hole::get_x()
{
	return x_;
}

const int Hole::get_y()
{
	return y_;
}

const char Hole::get_symbol() const
{
	return symbol_;
}

bool Hole::is_at_position(int x, int y)
{
	return (x_ == x) && (y_ == y);
}