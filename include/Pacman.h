#ifndef PACMAN_H
#define PACMAN_H

#include <GL/glut.h>
#include <cmath>

class Pacman {
public:
    Pacman(float initialX, float initialY, float speed);
    void draw();
    void update(int MC[][21], int filas, int columnas, float cellSize);
    void setDirection(float dx, float dy);

private:
    float posX;
    float posY;
    float speed;
    float directionX;
    float directionY;
};

#endif
