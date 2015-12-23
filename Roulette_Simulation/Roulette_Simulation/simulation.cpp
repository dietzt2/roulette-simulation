#include <cstdlib>
#include <iostream>
#include "Spinner.h"
using namespace std;

void set_spinner1(Spinner& spinner1);
void set_spinner2(Spinner& spinner2);

int main() {

	//Spinner with 5 inner sections and 16 outer sections
	Spinner spinner1(5, 16);
	set_spinner1(spinner1);

	double total = 0; //The sum of all iterations of the spinner
	const int ITERATIONS = 1000000; //The number of times to 'spin' the spinner

	for (int i = 0; i < ITERATIONS; ++i) {
		spinner1.spin();
		total += spinner1.get_spin_multiplier();
	}

	cout << "Spinner 1 Expected value: " << (total / ITERATIONS) << endl;

	//Spinner with 5 inner sections and 24 outer sections
	Spinner spinner2(5, 24);
	set_spinner2(spinner2);
	total = 0; //The sum of all iterations of the spinner

	for (int i = 0; i < ITERATIONS; ++i) {
		spinner2.spin();
		total += spinner2.get_spin_multiplier();
	}

	cout << "Spinner 2 Expected value: " << (total / ITERATIONS) << endl;

	return EXIT_SUCCESS;
}

void set_spinner1(Spinner& spinner1) {

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
}

void set_spinner2(Spinner& spinner2) {

	//Set the cutoffs for the inner section
	spinner2.set_cutoff(Section::INNERSECTION, 1, 180);
	spinner2.set_cutoff(Section::INNERSECTION, 2, 270);
	spinner2.set_cutoff(Section::INNERSECTION, 3, 315);
	spinner2.set_cutoff(Section::INNERSECTION, 4, 345);
	spinner2.set_cutoff(Section::INNERSECTION, 5, 360);

	//Set the multipliers for the inner section
	spinner2.set_multiplier(Section::INNERSECTION, 1, 0);
	spinner2.set_multiplier(Section::INNERSECTION, 2, 1);
	spinner2.set_multiplier(Section::INNERSECTION, 3, 3);
	spinner2.set_multiplier(Section::INNERSECTION, 4, 5);
	spinner2.set_multiplier(Section::INNERSECTION, 5, 24);

	//Set the cutoffs for the outer section
	spinner2.set_cutoff(Section::OUTERSECTION, 1, 15);
	spinner2.set_cutoff(Section::OUTERSECTION, 2, 30);
	spinner2.set_cutoff(Section::OUTERSECTION, 3, 45);
	spinner2.set_cutoff(Section::OUTERSECTION, 4, 60);
	spinner2.set_cutoff(Section::OUTERSECTION, 5, 75);
	spinner2.set_cutoff(Section::OUTERSECTION, 6, 90);
	spinner2.set_cutoff(Section::OUTERSECTION, 7, 105);
	spinner2.set_cutoff(Section::OUTERSECTION, 8, 120);
	spinner2.set_cutoff(Section::OUTERSECTION, 9, 135);
	spinner2.set_cutoff(Section::OUTERSECTION, 10, 150);
	spinner2.set_cutoff(Section::OUTERSECTION, 11, 165);
	spinner2.set_cutoff(Section::OUTERSECTION, 12, 180);
	spinner2.set_cutoff(Section::OUTERSECTION, 13, 195);
	spinner2.set_cutoff(Section::OUTERSECTION, 14, 210);
	spinner2.set_cutoff(Section::OUTERSECTION, 15, 225);
	spinner2.set_cutoff(Section::OUTERSECTION, 16, 240);
	spinner2.set_cutoff(Section::OUTERSECTION, 17, 255);
	spinner2.set_cutoff(Section::OUTERSECTION, 18, 270);
	spinner2.set_cutoff(Section::OUTERSECTION, 19, 285);
	spinner2.set_cutoff(Section::OUTERSECTION, 20, 300);
	spinner2.set_cutoff(Section::OUTERSECTION, 21, 315);
	spinner2.set_cutoff(Section::OUTERSECTION, 22, 330);
	spinner2.set_cutoff(Section::OUTERSECTION, 23, 345);
	spinner2.set_cutoff(Section::OUTERSECTION, 24, 360);

	//Set the multipliers for the outer section
	spinner2.set_multiplier(Section::OUTERSECTION, 1, 1);
	spinner2.set_multiplier(Section::OUTERSECTION, 2, 2);
	spinner2.set_multiplier(Section::OUTERSECTION, 3, 3);
	spinner2.set_multiplier(Section::OUTERSECTION, 4, 1);
	spinner2.set_multiplier(Section::OUTERSECTION, 5, 2);
	spinner2.set_multiplier(Section::OUTERSECTION, 6, 3);
	spinner2.set_multiplier(Section::OUTERSECTION, 7, 1);
	spinner2.set_multiplier(Section::OUTERSECTION, 8, 2);
	spinner2.set_multiplier(Section::OUTERSECTION, 9, 3);
	spinner2.set_multiplier(Section::OUTERSECTION, 10, 1);
	spinner2.set_multiplier(Section::OUTERSECTION, 11, 2);
	spinner2.set_multiplier(Section::OUTERSECTION, 12, 3);
	spinner2.set_multiplier(Section::OUTERSECTION, 13, 1);
	spinner2.set_multiplier(Section::OUTERSECTION, 14, 2);
	spinner2.set_multiplier(Section::OUTERSECTION, 15, 3);
	spinner2.set_multiplier(Section::OUTERSECTION, 16, 1);
	spinner2.set_multiplier(Section::OUTERSECTION, 17, 2);
	spinner2.set_multiplier(Section::OUTERSECTION, 18, 3);
	spinner2.set_multiplier(Section::OUTERSECTION, 19, 1);
	spinner2.set_multiplier(Section::OUTERSECTION, 20, 2);
	spinner2.set_multiplier(Section::OUTERSECTION, 21, 3);
	spinner2.set_multiplier(Section::OUTERSECTION, 22, 1);
	spinner2.set_multiplier(Section::OUTERSECTION, 23, 2);
	spinner2.set_multiplier(Section::OUTERSECTION, 24, 3);
}