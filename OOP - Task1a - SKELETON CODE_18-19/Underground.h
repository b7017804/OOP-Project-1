#ifndef UndergroundH
#define UndergroundH 


#include <cassert>
#include <vector>

#include "constants.h"
#include "RandomNumberGenerator.h"
#include "Hole.h"

using namespace std;

class Underground
{
	private:
		bool is_valid_hole_number(int n) const;
	public:
		Underground();
		Hole get_hole_no(int no) const;
		void set_hole_no_at_position(int no, int x, int y);
		vector<Hole> holes_;
};

#endif