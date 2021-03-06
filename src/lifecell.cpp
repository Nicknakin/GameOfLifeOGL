#include "lifecell.h"
#include <sstream>

LifeCell::LifeCell(int x, int y, int width, int height, float r, float g, float b, int value): GCA::Cell(x, y, value), sf::RectangleShape(sf::Vector2<float> {
    (float) width, (float) height
}), width{width}, height{height} {
    this->r = (float) r/255.f;
    this->g = (float) g/255.f;
    this->b = (float) b/255.f;
    RectangleShape::setPosition(x*width, y*height);
    setFillColor(sf::Color{(unsigned char) r, (unsigned char) g, (unsigned char) b});
}

std::string LifeCell::toString() const {
    std::stringstream buffer{};
    buffer << x << " " << y << " " << width << " " << height << " (" << (int) r*255 << "," << (int) g*255 << "," << (int) b*255 << ")";
    return buffer.str();
}

int LifeCell::getR() {
    return getFillColor().r;
}

int LifeCell::getG() {
    return getFillColor().g;
}

int LifeCell::getB() {
    return getFillColor().b;
}

void LifeCell::setColor(sf::Color color) {
    setFillColor(color);
    r = (float) color.r/255.f;
    g = (float) color.g/255.f;
    b = (float) color.b/255.f;
}

void LifeCell::setColor(int r, int g, int b) {
    setFillColor(sf::Color((int) r,(int) g, (int) b));
    this->r = (float) r/255.f;
    this->g = (float) g/255.f;
    this->b = (float) b/255.f;
}
