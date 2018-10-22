CXX = g++
oglflags = -lsfml-graphics -lsfml-window -lsfml-system -lpthread

default: cell.o grid.o lifecell.o lifegrid.o main.o
	$(CXX) -o GameOfLife main.o cell.o grid.o lifecell.o lifegrid.o $(oglflags)

debug: main.o cell.o
	$(CXX) -g -Wall -o DebugGameOfLife main.cpp cell.cpp grid.cpp lifegrid.cpp lifecell.cpp $(oglflags)

%.o: %.cpp %.h
	$(CXX) -c $< $(oglflags)

run: default
	./GameOfLife

clean:
	rm -rf *.o ./GameOfLife ./DebugGameOfLife *.gch
