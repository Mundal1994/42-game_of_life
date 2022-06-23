## GAME-OF-LIFE

## How to run

1. make all
2. three executables have been created life (newest and fastests algorithm), first_life (first algorithm) and infinite_life (changed algorithm to become an infinite map)
	./life maps/initial_state iterations


## How to run visualizer

1. run the following command
	make vis
2. visualizer should then compile (can take a few minutes)
3. when compilation is finished run the following script
	you can choose to run 'life' or 'infinite_life' (make sure the executables exist or else run 'make all' or 'make re')

	./run-vis.sh life maps/initial_state iterations
