#ifndef lifecellInc
#define lifecellInc

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>

#include "cell.h"

class LifeCell: public sf::RectangleShape, public GCA::Cell {
public:
    LifeCell(int x, int y, int width, int height, float r = 255, float g = 255, float b = 255, int value = 0);
    std::string toString() const;
    sf::Color getColor();
    int getR();
    int getG();
    int getB();
    void setColor(sf::Color color);
    void setColor(int r, int g, int b);


private:
    int x, y, width, height;
    int value;
    float r,g,b;
};

#endif
