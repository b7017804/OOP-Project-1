#include "Constants.h"
#include "Mouse.h"
#include "Snake.h"
#include "RandomNumberGenerator.h"

//class Snake
//{
//	public:
//	Snake();
//	~Snake();
//	bool is_at_position(int x, int y);
//	bool has_caught_mouse();
//	void spot_mouse(Mouse* p_mouse);
//	void chase_mouse();
//	void set_direction(int& dx, int& dy);
//	void position_at_random();
//	void update_position(int dx, int dy);
//	char symbol_;
//	int x_, y_;
//	Mouse* p_mouse_;
//	RandomNumberGenerator rng_;
//};

Snake::Snake()
{
	symbol_ = SNAKEHEAD;
	position_at_random();

	// make the pointer safe before the snake spots the mouse
	p_mouse_ = nullptr;
}

Snake::~Snake()
{
}

//bool Snake::is_at_position(int x, int y)
//{
//	return (x_ == x) && (y_ == y);
//}

bool Snake::has_caught_mouse()
{
	return (x_ == p_mouse_->x_) && (y_ == p_mouse_->y_);
}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: The mouse needs to exist 
	assert(p_mouse != nullptr);

	p_mouse_ = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	//go in that direction
	update_position(snake_dx, snake_dy);
}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse_ != nullptr);

	// assume snake only move when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (x_ < p_mouse_->get_x())          // if snake on left of mouse
		dx = 1;                          // snake should move right
	else if (x_ > p_mouse_->get_x())     // if snake on left of mouse
		dx = -1;						 // snake should move left

	if (y_ < p_mouse_->get_y())          // if snake is above mouse
		dy = 1;                          // snake should move down
	else if (y_ > p_mouse_->get_y())     // if snake is below mouse
		dy = -1;						 // snake should move up
}

void Snake::update_position(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
}

void Snake::position_at_random()
{
	// WARNING: this may place on top of other things

	x_ = rng_.get_random_value(SIZE);
	y_ = rng_.get_random_value(SIZE);
}