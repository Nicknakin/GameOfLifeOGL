#ifndef manipulatorIncluded
#define manipulatorIncluded

#include <vector>
#include "cell.h"

namespace GCA{
    class Manipulator{
        public:
            //Two constructors, one assumes 2d position
            Manipulator(int xPosition, int yPosition);
            Manipulator(std::vector<int> position);

            //Functions needed by every manipulator
            virtual void manipulateCell(Cell* cell) = 0;
            virtual void update(Cell* cell) = 0;

            //Get and Set Methods
            std::vector<int> getPosition();

            int getID();
            static int getNumManipulators();

        protected:
            std::vector<int> position;
            int id;
            static int ID;
    };

    int Manipulator::ID = 0;
}
#endif
