#ifndef FANTASMA_H
#define FANTASMA_H

#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

class Fantasma {
public:
    Fantasma(float speed, float startX, float startY, int colorR, int colorG, int colorB);
    void draw();
    void update(int MC[][21], int filas, int columnas, float cellSize);

private:
    float posX;
    float posY;
    float speed;
    float directionX;
    float directionY;
    bool isMoving;
    int colorR;
    int colorG;
    int colorB;

    void cambiarDireccion(int MC[][21], int filas, int columnas, float cellSize);
};

#endif
