CXX=g++
CXXFLAGS=-std=c++17 -Wall -I include/
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system -lpthread
SRC_DIR=./src
OBJ_DIR=./obj
BUILD_DIR=./build

BRACKET_STYLE=java

OUTPUT=GameOfLife

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

default: ${OBJ_FILES} 
	${CXX} ${CXXFLAGS} $^ -o ${BUILD_DIR}/${OUTPUT} ${LDLIBS}

preprocess: CXXFLAGS+=-E
preprocess: default

debug: CXXFLAGS+=-g 
debug: clean default 

docgen:
	@doxygen
	@firefox ./docs/html/index.html

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	$(CXX) ${CXXFLAGS} -c -o $@ $< $(LDLIBS) 

prettify:
	find -type f \( -iname \*.h -o -iname \*.hpp -o -iname \*.cpp \) -exec astyle -n --style=${BRACKET_STYLE} {} \; | grep ^Formatted*

clean:
	-rm -rf ${BUILD_DIR}/*
	-rm -rf ${OBJ_DIR}/*.o

