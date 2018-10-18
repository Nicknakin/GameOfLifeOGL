#include "lifegrid.h"

#include <stdlib.h>

//Utility method only being used because % acts as a remainder operator instead of a modulo operator.
int mod(int a, int b){
    if(a >= 0)
        return a%b;
    else
        return ((a%b)+b)%b;
}

LifeGrid::LifeGrid(int width, int height, int side, std::vector<sf::Color> colors, sf::Color defaultColor): Grid{width, height}, colors{colors}{
    srand(std::time(nullptr));
    newSums.resize(width*height);

    for(int i = 0; i < size; i++){
        cells.push_back(new LifeCell(i%width, i/width, side, side, defaultColor.r, defaultColor.g, defaultColor.b, value));
    }

    calcSums();
}

void LifeGrid::update(){
    for(int i = 0; i < cells.size(); i++){
        if(cells[i]->getValue() > 0){
            if(newSums[i] != 2 && newSums[i] != 3)
                cells[i]->setValue(0);
        } else{
            if(newSums[i] == 3)
                cells[i]->setValue(newSums[i]);
        }    
    }

    std::fill(newSums.begin(), newSums.end(), 0);
    
    calcSums();
}

void LifeGrid::calcSums(){
    for(int i = 0; i < cells.size(); i++){
        if(cells[i]->getValue() > 0){
            std::vector<int> surrounding{mod(i-width-1, width*height), mod(i-width, width*height), mod(i-width+1, width*height), mod(i-1, width*height), mod(i+1, width*height), mod(i+width-1, width*height), mod(i+width, width*height), mod(i+width+1, width*height)};
            
            for(const auto ind: surrounding){
                newSums[ind] += 1;
            }
        }
    }

    for(int i = 0; i < cells.size(); i++){
        cells[i]->setColor(colors[(cells[i]->getValue()? 1: 0)*(newSums[i])]);
    }
}

