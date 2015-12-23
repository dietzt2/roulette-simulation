
#include "spinner_section.h"

class Spinner {

public: 

	//Creates a Spinner shell with 1 inner and outer section
	//Default inner and outer multiplier are 0
	Spinner();
	//Creates a Spinner class with the indicated number of sections. 
	//Must be at least one section for each
	Spinner(unsigned int new_innersections, unsigned int new_outersections);

	//Going in a clockwise direction from the 12:00 position, the number (in degrees) from 0 to 360 is the cutoff. 
	//The cutoff_position begins at 1
	//This is the cutoff for the end of the section. The left cutoff is the end for the previous section.
	//For example, if the cutoff position is 1, and the cutoff is 45, the section goes from 0 to 45 degrees.
	//If the cutoff of 2 was then set to be 50, the second section is from 45 to 50
	//The cutoff for the last position must be 360
	void set_cutoff(Section section, unsigned int cutoff_position, double cutoff);

	//Going in a clockwise direction, the first position is 1. 
	//The multiplier must be at least 0.
	void set_multiplier(Section section, unsigned int multiplier_position, double multiplier);

	//Provides the angle of the last spin in degrees
	double get_spin_degrees();

	//Provides the total multiplier of the last spin
	double get_spin_multiplier();

	//Simulate one spin of the spinner
	void spin();

private:
	unsigned int innersections;
	unsigned int outersections;

	double * innersection_cutoffs;
	double * outersection_cutoffs;

	double * innersection_multipliers;
	double * outersection_multipliers;

	double last_spin_degrees;
	unsigned int last_spin_inner_index;
	unsigned int last_spin_outer_index;

	unsigned int find_spin_index(Section);
};
