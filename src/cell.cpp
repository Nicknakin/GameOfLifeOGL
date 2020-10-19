#include "cell.h"

namespace GCA{
    Cell::Cell(int xPosition, int yPosition, int value): value{value} {
        position.push_back(yPosition);
        position.push_back(xPosition);
    }

    Cell::Cell(std::vector<int> position, int value): position{position}, value{value} {
    
    }
    
    int Cell::getValue(){
        return value;
    }

    std::vector<int> Cell::getPosition(){
        return position;
    }

    void Cell::setValue(int val){
        value = val;
    }

    void Cell::setActive(bool act){
        active = act;
    }

    void Cell::setPosition(int x, int y){
        position[0] = y;
        position[1] = x;
    }

    void Cell::setPosition(std::vector<int> pos){
        position = pos;
    }
}
