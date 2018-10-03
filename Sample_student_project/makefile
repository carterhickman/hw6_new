output: main.o game.o othello.o 
	g++ main.o game.o othello.o -o output 
	
main.o: main.cc othello.h game.h colors.h piece.h
	g++ -c main.cc 

game.o: game.cc game.h 
	g++ -c game.cc 

othello.o: othello.cc othello.h 
	g++ -c othello.cc

clean: 
	rm *.o output 


