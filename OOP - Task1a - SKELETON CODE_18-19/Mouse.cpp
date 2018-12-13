#include "Mouse.h"

Mouse::Mouse() : symbol_(MOUSE), x_(0), y_(0), alive_(true), escaped_(false), mouse_dx_(0), mouse_dy_(0)
{
	position_in_middle_of_grid();
}

const int Mouse::get_x()
{
	return x_;
}

const int Mouse::get_y()
{
	return y_;
}

const char Mouse::get_symbol() const
{
	return symbol_;
}

bool Mouse::is_at_position(int x, int y)
{
	return (x_ == x) && (y_ == y);
}

const bool Mouse::is_alive() const
{
	return alive_;
}

const bool Mouse::has_escaped() const
{
	return escaped_;
}

bool Mouse::has_reached_a_hole(Underground ug)  //Move?
{
	for (int h_no(0); h_no < ug.holes_.size(); ++h_no) //Move?
	{
		Hole h = ug.get_hole_no(h_no); //Move?

		if (is_at_position(h.get_x(), h.get_y()))
		{
			return true;
		}
	}

	return false;
}

void Mouse::die()
{
	alive_ = false;
}

void Mouse::escape_into_hole() //Move?
{
	escaped_ = true;
}

void Mouse::scamper(char k)
{
	// move mouse in required direction
	// pre: k is an arrow representing the direction in which the mouse moves

	// find direction indicated by k
	switch (k)
	{
		case LEFT:
			mouse_dx_ = -1;
			mouse_dy_ = 0;
			break;
		case RIGHT:
			mouse_dx_ = +1;
			mouse_dy_ = 0;
			break;
		case UP:
			mouse_dx_ = 0;
			mouse_dy_ = -1;
			break;
		case DOWN:
			mouse_dx_ = 0;
			mouse_dy_ = +1;
			break;
	}

	// update mouse coordinates if move is possible
	if (((x_ + mouse_dx_) >= 1) && ((x_ + mouse_dx_) <= SIZE) && ((y_ + mouse_dy_) >= 1) && ((y_ + mouse_dy_) <= SIZE))
	{
		update_position(mouse_dx_, mouse_dy_);
	}
}

void Mouse::update_position(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
}

void Mouse::position_in_middle_of_grid()
{
	x_ = SIZE / 2;
	y_ = SIZE / 2;
}