#include "Underground.h"
#include <cassert>

// number of holes in underground  ASK PASCALE
const int MAXHOLES(3);

Underground::Underground() : holes_(MAXHOLES)
{
}

Hole Underground::get_hole_no(int no) const
{
	// pre-condition: valid hole number
	//assert(is_valid_hole_number(no));
	assert(true);
	return holes_.at(no);
}

void Underground::set_hole_no_at_position(int no, int x, int y)
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	Hole h(x, y);

	switch (no)
	{
		case 0: holes_.at(0) = h; break;
		case 1: holes_.at(1) = h; break;
		case 2: holes_.at(2) = h; break;
	}
}

bool Underground::is_valid_hole_number(int no) const
{
	return (no >= 0) && (no < holes_.size());
}