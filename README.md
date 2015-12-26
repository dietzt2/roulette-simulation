# spinner-simulation
Built to test two roulette-style spinners. There are an inner and outer ring on the spinners. The spinner will point to both an inner and outer section. The inner ring is the initial amount, and the outer ring is multiplied by the inner ring to give the total. 
The two spinners are uploaded as images in issues under "Images for README". The spinner on top is referenced as 'spinner1' and the bottom as 'spinner2'.

The files 'spinner.h', 'spinner.cpp', and 'spinner_section.h' are required to use the spinner. The file 'simulation.cpp' is built to test and use the spinners. Currently, it tests the 'Spinner' class by comparing the simulated expected value of each spinner to the known expected value (4.0 and 4.875, respectively). 

To use the 'Spinner' class, include the 'spinner.h', 'spinner.cpp', and 'spinner_section.h' files to a project. Create a new 'Spinner' object, using the 2-argument constructor (the class is currently not set up to be usable with the default constructor). The first argument is the number of number of sections on the inside of the spinner, and the second is the number of sections on the outside. 

The next task is to set each of the 'cutoffs' for the spinner. The right-cutoff is, going in a clockwise direction from the 12:00 position, the angle (in degrees) of the endpoint of the section. The left-cutoff is implicitly the end of the previous section. For example, if the first section begins at the 12:00 position and ends at the 3:00 position, the left-cutoff would implicitly be 0 and the right would be set as 90. 

After this, the program must set the multiplier for each section, in a similar manner. The multiplier is simply the number that the user would win if the spinner lands in that section.

The cutoff and multipliers must be set for both the inner and outer sections.

Use the 'spin()' member function to spin the spinner. Use the 'get_spin_degrees()' member function to get the angle of the last spin, and the 'get_spin_multiplier()' member function to get the multiplier (inside multiplier * outside multiplier) of the last spin.
