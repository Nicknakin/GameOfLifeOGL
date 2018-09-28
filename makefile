CXX = g++
oglflags = -lsfml-graphics -lsfml-window -lsfml-system

default: cell.o grid.o logicalgrid.o main.o
	$(CXX) -o shapes.out main.o cell.o grid.o logicalgrid.o $(oglflags)

debug: main.o cell.o
	$(CXX) -g -Wall -o dbgshapes.out main.cpp cell.cpp grid.cpp logicalgrid.cpp $(oglflags)

%.o: %.cpp %.h
	$(CXX) -c $< $(oglflags)

run: default
	./shapes.out

clean:
	rm -rf *.o *.out
