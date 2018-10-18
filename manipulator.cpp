#include "manipulator.h"

namespace GCA{
    Manipulator::Manipulator(int xPosition, int yPosition){
        id = ID++;
        position.push_back(yPosition);
        position.push_back(xPosition);
    }

    Manipulator::Manipulator(std::vector<int> position): position{position}, id{ID++}{
    
    };

    std::vector<int> Manipulator::getPosition(){
        return position;
    }

    int Manipulator::getID(){
        return id;
    }

    int Manipulator::getNumManipulators(){
        return ID;
    }
}
