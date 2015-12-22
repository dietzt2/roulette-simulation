

#include <iostream>
#include <cstdlib>
#include <random>
#include <cassert>
#include "Spinner.h"
using namespace std;

Spinner::Spinner() {

	innersections = 1;
	outersections = 1;
	last_spin_degrees = 0;

}

Spinner::Spinner(unsigned int new_innersections, unsigned int new_outersections) {

	assert(new_innersections > 0);
	assert(new_outersections > 0);

	innersections = new_innersections;
	outersections = new_innersections;

	innersection_cutoffs = new double[innersections];
	outersection_cutoffs = new double[outersections];

	innersection_multipliers = new double[innersections];
	outersection_multipliers = new double[outersections];

	last_spin_degrees = 0;
}

void Spinner::set_cutoff(Section section, unsigned int cutoff_position, double cutoff) {

	if (section == INNERSECTION) {
		assert(cutoff_position > 0);
		assert(cutoff_position <= innersections);
	}
	else {
		assert(cutoff_position > 0);
		assert(cutoff_position <= outersections);
	}
	assert(cutoff >= 0);

	innersection_cutoffs[cutoff_position-1] = cutoff;
}

void Spinner::set_multiplier(Section section, unsigned int multiplier_position, double multiplier) {

	if (section == INNERSECTION) {
		assert(multiplier_position > 0);
		assert(multiplier_position <= innersections);
	}
	else {
		assert(multiplier_position > 0);
		assert(multiplier_position <= outersections);
	}
	assert(multiplier >= 0);

	innersection_multipliers[multiplier_position-1] = multiplier;
}

void Spinner::spin() {

	last_spin_degrees += (rand() * 360);
	last_spin_inner_index = find_spin_index(Section::INNERSECTION);
	last_spin_outer_index = find_spin_index(Section::OUTERSECTION);
}

unsigned int Spinner::find_spin_index(Section s) {

	int i = 0;

	if (s == Section::INNERSECTION) {
		while (last_spin_degrees < innersection_cutoffs[i]) {
			++i;
		}
	}
	else {
		while (last_spin_degrees < outersection_cutoffs[i]) {
			++i;
		}
	}
	return i;
}

double Spinner::get_spin_degrees() {

	return last_spin_degrees;
}

double Spinner::get_spin_multiplier() {

	return (innersection_multipliers[last_spin_inner_index] * outersection_multipliers[last_spin_outer_index]);
}