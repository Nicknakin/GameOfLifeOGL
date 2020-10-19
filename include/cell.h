#ifndef cellIncluded
#define cellIncluded

#include <vector>
namespace GCA{
    class Cell {
        public:
            Cell(int xPosition, int yPosition, int value);
            Cell(std::vector<int> position, int value);
            int getValue();
            bool getActive();
            std::vector<int> getPosition();
            void setValue(int val);
            void setActive(bool act);
            void setPosition(int x, int y);
            void setPosition(std::vector<int> pos);

        protected:
            std::vector<int> position;
            bool active;
            int value;
    };
}
#endif
