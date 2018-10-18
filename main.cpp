#include <stdlib.h>
#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "lifecell.h"
#include "lifegrid.h"

struct setting{
    const int width;
    const int height;
    const int sideLength;
    const int speed;
};

struct operators{
    std::vector<sf::Color> colors{sf::Color{0,0,0}, sf::Color{0x33, 0x33, 0x33}, sf::Color{0x66,0x66,0x66}, sf::Color{0x99, 0x00, 0x99}, sf::Color{0xcc, 0x00, 0xcc}, sf::Color{0xff, 0x00, 0xff}};
};

int main(int argc, char** argv){
    try{
        //Initialize settings, if there are enough arguments use each one for width height sideLengthand speed respectively.
        setting config = {(argc >= 2)? std::stoi(argv[1]): 1920/2, (argc >= 3)? std::stoi(argv[2]): 1080/2-1, (argc >= 4)? std::stoi(argv[3]): 10, (argc >= 5)? std::stoi(argv[4]): 60};
 
        operators ops;

        //Argument used to know whether the window has been resized.
        bool resized = true;

        //Initialize the Grid of cells based on configs
        LifeGrid grid{config.width/config.sideLength, config.height/config.sideLength, config.sideLength, ops.colors, sf::Color{0,0,0}};

        //Create window with SFML and set framerate
        sf::RenderWindow window(sf::VideoMode(config.width,config.height), "SFML Project");
        window.setFramerateLimit(config.speed);
        
        //Execution loop
        while (window.isOpen()) {
            window.clear();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if(event.type == sf::Event::Resized)
                        resized = true;
            }

            for(int i = 0; i < grid.getSize(); i++){
                auto cell = grid.getCell(i);
                dynamic_cast<LifeCell*> (cell);

                window.draw(cell);
            }

            grid.update();
            window.display();
        }
    } catch(const std::exception& e){
        return 1;
    }
    return 0;
}

