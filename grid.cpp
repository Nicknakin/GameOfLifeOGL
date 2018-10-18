#include "grid.h"

namespace GCA{
    Grid::Grid(int width, int height): width{width}, height{height}, size{width*height} {

    }

    Cell* Grid::operator[](int ind){
        return cells[ind];
    }

    std::vector<Cell*> Grid::getCells(){
        return cells;
    }

    std::vector<Manipulator*> Grid::getManipulators(){
        return manipulators;
    }

    Cell* Grid::getCell(int index){
        return cells[index];
    }

    Cell* Grid::getCell(int y, int x){
        return cells[y*width+x];
    }

    Manipulator* Grid::getManipulator(int index){
        return manipulators[index];
    }

    int Grid::getWidth(){
        return width;
    }

    int Grid::getHeight(){
        return height;
    }

    int Grid::getSize(){
        return size;
    }
}
