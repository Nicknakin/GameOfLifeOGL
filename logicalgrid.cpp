#include "logicalgrid.h"

#include <stdlib.h>

//Utility method only being used because % acts as a remainder operator instead of a modulo operator.
int mod(int a, int b){
    if(a >= 0)
        return a%b;
    else
        return ((a%b)+b)%b;
}

LogicalGrid::LogicalGrid(int width, int height, int side, sf::Color defaultColor): Grid{width, height, side, defaultColor} {
    srand(std::time(nullptr));
    newSums.resize(width*height);
    for(auto& cell: cells)
        cell.setValue(rand()%2);
}

void LogicalGrid::update(){
    for(int i = 0; i < cells.size(); i++){
        std::vector<int> surrounding{mod(i-width-1, width*height), mod(i-width, width*height), mod(i-width+1, width*height), mod(i-1, width*height), mod(i+1, width*height), mod(i+width-1, width*height), mod(i+width, width*height), mod(i+width+1, width*height)};
        newSums[i] = 0;
        for(const auto ind: surrounding){
            newSums[i] += cells[ind].getValue() > 0;
        }
        changedCells.push_back(i);
    }
    for(int i = 0; i < cells.size(); i++){
        cells[i].setValue(newSums[i]);
        cells[i].setColor(cells[i].getValue()*255/8, cells[i].getValue()*255/8, cells[i].getValue()*255/8);
    }
}

