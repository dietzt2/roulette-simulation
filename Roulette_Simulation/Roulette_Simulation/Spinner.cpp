

#include <iostream>
#include <cstdlib>
#include <random>
#include <cassert>
#include "Spinner.h"
using namespace std;

Spinner::Spinner() {

	innersections = 0;
	outersections = 0;
	last_spin_degrees = 0;

}

Spinner::Spinner(unsigned int new_innersections, unsigned int new_outersections) {

	assert(new_innersections > 0 && new_outersections > 0);

	innersections = new_innersections;
	outersections = new_outersections;

	innersection_cutoffs = new double[innersections];
	outersection_cutoffs = new double[outersections];

	innersection_multipliers = new double[innersections];
	outersection_multipliers = new double[outersections];

	last_spin_degrees = 0;
}

void Spinner::set_cutoff(Section section, unsigned int cutoff_position, double cutoff) {

	//cout << "outersections: " << outersections << endl;
	//cout << "cutoff position: " << cutoff_position << endl;
	assert(innersections > 0 && outersections > 0);

	if (section == INNERSECTION) {
		assert(cutoff_position > 0);
		assert(cutoff_position <= innersections);
	}
	else {
		assert(cutoff_position > 0);
		assert(cutoff_position <= outersections);
	}
	assert(cutoff >= 0);

	if (section == Section::INNERSECTION)
		innersection_cutoffs[cutoff_position - 1] = cutoff;
	else
		outersection_cutoffs[cutoff_position - 1] = cutoff;
}

void Spinner::set_multiplier(Section section, unsigned int multiplier_position, double multiplier) {

	assert(innersections > 0 && outersections > 0);

	if (section == INNERSECTION) {
		assert(multiplier_position > 0);
		assert(multiplier_position <= innersections);
	}
	else {
		assert(multiplier_position > 0);
		assert(multiplier_position <= outersections);
	}
	assert(multiplier >= 0);

	//cout << "multiplier position: " << multiplier_position << endl;
	//cout << "multiplier: " << multiplier << endl;

	if (section == Section::INNERSECTION)
		innersection_multipliers[multiplier_position-1] = multiplier;
	else 
		outersection_multipliers[multiplier_position - 1] = multiplier;
}

void Spinner::spin() {

	last_spin_degrees += ((rand() / static_cast<double>(RAND_MAX + 1)) * 360);
	if (last_spin_degrees > 360)
		last_spin_degrees -= 360;

	last_spin_inner_index = find_spin_index(Section::INNERSECTION);
	last_spin_outer_index = find_spin_index(Section::OUTERSECTION);
}

unsigned int Spinner::find_spin_index(Section s) {

	int i = 0;

	if (s == Section::INNERSECTION) {
		//cout << "Inner" << endl;
		while (last_spin_degrees > innersection_cutoffs[i]) {
			//cout << "last_spin_degrees: " << last_spin_degrees << endl;
			//cout << "innersection cuttof[i]: " << innersection_cutoffs[i] << endl;
			++i;
		}
	}
	else {
		//cout << "outer" << endl;
		while (last_spin_degrees > outersection_cutoffs[i]) {
			++i;
		}
	}
	//cout << "index: " << i << endl;
	return i;
}

double Spinner::get_spin_degrees() {

	return last_spin_degrees;
}

double Spinner::get_spin_multiplier() {

	//cout << "innersection multiplier" << innersection_multipliers[last_spin_inner_index] << endl;
	//cout << "outersection multiplier" << outersection_multipliers[last_spin_outer_index] << endl;

	return (innersection_multipliers[last_spin_inner_index] * outersection_multipliers[last_spin_outer_index]);
}

void Spinner::change_num_sections(Section section, unsigned int num_sections) {

	assert(section == INNERSECTION || section == OUTERSECTION);
	assert(num_sections > 0);

	if (section == INNERSECTION) {

		innersections = num_sections;

		delete innersection_cutoffs;
		innersection_cutoffs = new double[innersections];

		delete innersection_multipliers;
		innersection_multipliers = new double[innersections];
	}
	else {

		outersections = num_sections;

		delete outersection_cutoffs;
		outersection_cutoffs = new double[outersections];

		delete outersection_multipliers;
		outersection_multipliers = new double[outersections];
	}
}

void Spinner::set_cutoff_and_multiplier(Section section, unsigned int position, double cutoff, double multiplier) {

	assert(innersections > 0 && outersections > 0);

	if (section == INNERSECTION) {
		assert(position > 0);
		assert(position <= innersections);
	}
	else {
		assert(position > 0);
		assert(position <= outersections);
	}
	assert(cutoff >= 0);

	if (section == Section::INNERSECTION) {
		innersection_cutoffs[position - 1] = cutoff;
		innersection_multipliers[position - 1] = multiplier;
	}
	else {
		outersection_cutoffs[position - 1] = cutoff;
		outersection_multipliers[position - 1] = multiplier;
	}

}