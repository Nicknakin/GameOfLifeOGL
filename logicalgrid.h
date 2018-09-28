#ifndef logicalgridinc
#define logicalgridinc

#include <vector>
#include <SFML/Graphics.hpp>

#include "grid.h"
#include "cell.h"

class LogicalGrid: public Grid{
    public:
        LogicalGrid(int width, int height, int side, std::vector<sf::Color> colors, sf::Color defaultColor = sf::Color(0,0,0));
        void update();

    private:
        void calcSums();
        std::vector<int> newSums{};
        std::vector<sf::Color> colors;
};

#endif
