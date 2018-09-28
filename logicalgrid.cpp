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
    cells[width+width*height/2].setValue(1);
    cells[width+1+width*height/2].setValue(1);
    cells[width+width+1+width*height/2].setValue(1);
    cells[width+width+2+width*height/2].setValue(1);
    cells[width+width*2+width*height/2].setValue(1);
}

void LogicalGrid::update(){
    for(int i = 0; i < cells.size(); i++){
        if(cells[i].getValue() > 0){
            std::vector<int> surrounding{mod(i-width-1, width*height), mod(i-width, width*height), mod(i-width+1, width*height), mod(i-1, width*height), mod(i+1, width*height), mod(i+width-1, width*height), mod(i+width, width*height), mod(i+width+1, width*height)};
            
            for(const auto ind: surrounding){
                newSums[ind] += 1;
            }

            changedCells.insert(changedCells.end(), surrounding.begin(), surrounding.end());
            changedCells.push_back(i);
        }
    }

    for(int i = 0; i < cells.size(); i++){
        if(cells[i].getValue() > 0){
            if(newSums[i] != 2 && newSums[i] != 3)
                cells[i].setValue(0);
        } else{
            if(newSums[i] == 3)
                cells[i].setValue(newSums[i]);
        }
        
        cells[i].setColor((cells[i].getValue()>0)*255, (cells[i].getValue())*255, (cells[i].getValue())*255); 
    }

    std::fill(newSums.begin(), newSums.end(), 0);
}

