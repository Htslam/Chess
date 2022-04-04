install:
	sudo apt-get install libsfml-dev
	g++ Engine.cpp main.cpp Moves.cpp Engine.h Menu.cpp Menu.h -o game -lsfml-graphics -lsfml-audio  -lsfml-window -lsfml-system
	@./game
test:
	@./game
