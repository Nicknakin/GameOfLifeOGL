#include <stdlib.h>
#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "cell.h"
#include "logicalgrid.h"

struct setting{
    const int width;
    const int height;
    const int sideLength;
    const int speed;
};

struct operators{
    std::vector<sf::Color> colors{sf::Color{255,0,0}, sf::Color{255, 128, 0}, sf::Color{0,255,0}, sf::Color{0, 128, 255}, sf::Color{0, 0, 255}, sf::Color{255, 0 , 128}};
};

int main(int argc, char** argv){
    try{
        //Initialize settings, if there are enough arguments use each one for width height sideLengthand speed respectively.
        setting config = {(argc >= 2)? std::stoi(argv[1]): 1920/2, (argc >= 3)? std::stoi(argv[2]): 1080/2-1, (argc >= 4)? std::stoi(argv[3]): 1, (argc >= 5)? std::stoi(argv[4]): 500};
 
        operators ops;

        //Argument used to know whether the window has been resized.
        bool resized = true;

        //Initialize the Grid of cells based on configs
        LogicalGrid grid{config.width/config.sideLength, config.height/config.sideLength, config.sideLength};

        //Create window with SFML and set framerate
        sf::RenderWindow window(sf::VideoMode(config.width,config.height), "SFML Project");
        window.setFramerateLimit(config.speed);
        
        //Execution loop
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if(event.type == sf::Event::Resized)
                        resized = true;
            }

            grid.update();

            while(!resized && grid.getChangedCellSize() > 0){
                window.draw(grid.getChangedCell(0));
                grid.popChangedCell();
            }
            
            if(resized){
                for(int i = 0; i < grid.size(); i++){
                    window.draw(grid.getCell(i));
                }
            }

            resized = false;
            window.display();
        }
    } catch(const std::exception& e){
        return 1;
    }
    return 0;
}

