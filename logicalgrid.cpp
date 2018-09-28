#include "logicalgrid.h"

#include <stdlib.h>

//Utility method only being used because % acts as a remainder operator instead of a modulo operator.
int mod(int a, int b){
    if(a >= 0)
        return a%b;
    else
        return ((a%b)+b)%b;
}

LogicalGrid::LogicalGrid(int width, int height, int side, std::vector<sf::Color> colors, sf::Color defaultColor): Grid{width, height, side, defaultColor}, colors{colors}{
    srand(std::time(nullptr));
    newSums.resize(width*height);
    for(auto& cell: cells){
        cell.setValue(rand()%2);
    }

    calcSums();
}

void LogicalGrid::update(){
    for(int i = 0; i < cells.size(); i++){
        if(cells[i].getValue() > 0){
            if(newSums[i] != 2 && newSums[i] != 3)
                cells[i].setValue(0);
        } else{
            if(newSums[i] == 3)
                cells[i].setValue(newSums[i]);
        }    
    }

    std::fill(newSums.begin(), newSums.end(), 0);
    
    calcSums();
    for(int i = 0; i < cells.size(); i++){
        cells[i].setColor(colors[(cells[i].getValue()? 1: 0)*(newSums[i]-1)]);
    }
}

void LogicalGrid::calcSums(){
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
}

