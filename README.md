## GAME-OF-LIFE

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
