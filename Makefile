ifeq ($(shell uname -s), Darwin)
all:
	g++ -o snake snake.cc -framework OpenGL -framework GLUT -Wno-deprecated-declarations
else
all:
	g++ -o snake snake.cc -lglut -lGL -lGLU
endif
