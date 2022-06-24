## GAME-OF-LIFE

## ABOUT

The Game of Life (or Life) is a cellular automaton devised by the British mathematician John Horton Conway in 1970. The evolution is determined by its initial state and isn't in need of any input from any player (therefor a zero-player game). One interacts with the Game of Life by creating an initial configuration and observing how it evolves.

## HOW TO RUN GAME OF LIFE

	1. make all
	2. three executables have been created 'first_life' (first algorithm), 'life' (fastest algorithm with boundary condition) and 'infinite_life' (fastest algorithm with infinite map)
		for iterations pick a positive number

		./life maps/initial_state (iterations)


## HOW TO RUN VISUALIZER

	1. run the following command
		make vis
	2. visualizer should then compile (can take a few minutes)
	3. when compilation is finished run the following script
		you can choose to run 'life' or 'infinite_life' (make sure the executables exist or else run 'make all' or 'make re')
		for iterations pick a positive number

		./run_vis.sh life maps/initial_state (iterations)

## HOW TO USE VISUALIZER

CONTROLS

	ESC: quit the program

	SPACE: auto display stages of the map / press again to stop auto display

	R: resets to initial state

	PLUS(+): speeds up auto display

	MINUS(-): slows down auto display

	LEFT ARROW KEY: previous state

	RIGHT ARROW KEY: next state

## COLLABORATION

Project made in collaporation with Daniel Palacio(https://https://github.com/Danielmdc94) who took care of the visualizer for the project while I focused on the algorithm.