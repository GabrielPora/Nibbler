ifeq ($(shell uname -s), Darwin)
all:
	g++ *.cpp -framework OpenGL -framework GLUT -Wno-deprecated-declarations
else
all:
	g++ -o snake snake.cc -lglut -lGL -lGLU
endif
