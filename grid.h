#ifndef gridIncluded
#define gridIncluded

#include <iterator>
#include <vector>
#include "cell.h"
#include "manipulator.h"

namespace GCA{
    class Grid {
        public:
            //Constructor
            Grid(int width, int height);
            
            //Operator overload to allow for requesting individual cells
            Cell* operator[](int ind);

            //Get and Set methods
            std::vector<Cell*> getCells();
            std::vector<Manipulator*> getManipulators();
            
            Cell* getCell(int index);
            Cell* getCell(int y, int x);

            Manipulator* getManipulator(int index);
            
            int getWidth();
            int getHeight();
            int getSize();

        protected:
            std::vector<Cell*> cells;
            std::vector<Manipulator*> manipulators;
            int width, height, size;

    };
}
#endif
