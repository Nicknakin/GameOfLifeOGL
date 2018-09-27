#ifndef logicalgridinc
#define logicalgridinc

#include <vector>
#include <SFML/Graphics.hpp>

#include "grid.h"
#include "cell.h"

class LogicalGrid: public Grid{
    public:
        LogicalGrid(int width, int height, int side = 1, sf::Color defaultColor = sf::Color(0,0,0));
        void update();

    private:
        std::vector<int> newSums{};
};

#endif
