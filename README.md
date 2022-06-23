## GAME-OF-LIFE

## How to run

1. make all
2. three executables have been created 'first_life' (first algorithm), 'life' (fastest algorithm with boundary condition) and 'infinite_life' (fastest algorithm with infinite map)
	./life maps/initial_state iterations


## How to run visualizer

1. run the following command
	make vis
2. visualizer should then compile (can take a few minutes)
3. when compilation is finished run the following script
	you can choose to run 'life' or 'infinite_life' (make sure the executables exist or else run 'make all' or 'make re')

	./run-vis.sh life maps/initial_state iterations
