
#include <cstdlib>
#include <iostream>
#include "Spinner.h"
using namespace std;


int main() {

	int dummy_v;
	const unsigned int inner_sections = 5;
	const unsigned int outer_sections = 16;

	Spinner spinner1(inner_sections, outer_sections);

	//Set the cutoffs for the inner section
	spinner1.set_cutoff(Section::INNERSECTION, 1, 90);
	spinner1.set_cutoff(Section::INNERSECTION, 2, 135);
	spinner1.set_cutoff(Section::INNERSECTION, 3, 180);
	spinner1.set_cutoff(Section::INNERSECTION, 4, 270);
	spinner1.set_cutoff(Section::INNERSECTION, 5, 360);

	//Set the multipliers for the inner section
	spinner1.set_multiplier(Section::INNERSECTION, 1, 1.0);
	spinner1.set_multiplier(Section::INNERSECTION, 2, 7.80);
	spinner1.set_multiplier(Section::INNERSECTION, 3, 2.0);
	spinner1.set_multiplier(Section::INNERSECTION, 4, .50);
	spinner1.set_multiplier(Section::INNERSECTION, 5, 0);


	//Set the cutoffs for the outer section
	spinner1.set_cutoff(Section::OUTERSECTION, 1, 22.5);
	spinner1.set_cutoff(Section::OUTERSECTION, 2, 45);
	spinner1.set_cutoff(Section::OUTERSECTION, 3, 67.5);
	spinner1.set_cutoff(Section::OUTERSECTION, 4, 90);
	spinner1.set_cutoff(Section::OUTERSECTION, 5, 112.5);
	spinner1.set_cutoff(Section::OUTERSECTION, 6, 135);
	spinner1.set_cutoff(Section::OUTERSECTION, 7, 157.5);
	spinner1.set_cutoff(Section::OUTERSECTION, 8, 180);
	spinner1.set_cutoff(Section::OUTERSECTION, 9, 202.5);
	spinner1.set_cutoff(Section::OUTERSECTION, 10, 225);
	spinner1.set_cutoff(Section::OUTERSECTION, 11, 247.5);
	spinner1.set_cutoff(Section::OUTERSECTION, 12, 270);
	spinner1.set_cutoff(Section::OUTERSECTION, 13, 292.5);
	spinner1.set_cutoff(Section::OUTERSECTION, 14, 315);
	spinner1.set_cutoff(Section::OUTERSECTION, 15, 337.5);
	spinner1.set_cutoff(Section::OUTERSECTION, 16, 360);


	//Set the multipliers for the outer section
	spinner1.set_multiplier(Section::OUTERSECTION, 1, 1);
	spinner1.set_multiplier(Section::OUTERSECTION, 2, 4);
	spinner1.set_multiplier(Section::OUTERSECTION, 3, 1);
	spinner1.set_multiplier(Section::OUTERSECTION, 4, 4);
	spinner1.set_multiplier(Section::OUTERSECTION, 5, 1);
	spinner1.set_multiplier(Section::OUTERSECTION, 6, 4);
	spinner1.set_multiplier(Section::OUTERSECTION, 7, 1);
	spinner1.set_multiplier(Section::OUTERSECTION, 8, 4);
	spinner1.set_multiplier(Section::OUTERSECTION, 9, 1);
	spinner1.set_multiplier(Section::OUTERSECTION, 10, 4);
	spinner1.set_multiplier(Section::OUTERSECTION, 11, 1);
	spinner1.set_multiplier(Section::OUTERSECTION, 12, 4);
	spinner1.set_multiplier(Section::OUTERSECTION, 13, 1);
	spinner1.set_multiplier(Section::OUTERSECTION, 14, 4);
	spinner1.set_multiplier(Section::OUTERSECTION, 15, 1);
	spinner1.set_multiplier(Section::OUTERSECTION, 16, 4);

	for (int i = 1; i < 11; ++i) {

		spinner1.spin();
		cout << "Spin " << i << " degrees: " << spinner1.get_spin_degrees() << endl;
		//cout << "Spin " << i << " multiplier: " << spinner1.get_spin_multiplier() << endl;
	}

	do {
		cout << "Type 1 and press enter to exit: ";
		cin >> dummy_v;
	} while (dummy_v != 1);

	return EXIT_SUCCESS;
}