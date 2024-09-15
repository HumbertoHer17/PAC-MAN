#include "Pacman.h"

Pacman::Pacman(float initialX, float initialY, float speed)
    : posX(initialX), posY(initialY), speed(speed), directionX(1.0f), directionY(0.0f) {}

void Pacman::draw() {
    glPushMatrix();
    float size = 4.0f;
    glTranslatef(posX, posY, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);
    glVertex2f(-size/2, -size/2);
    glVertex2f(size/2, -size/2);
    glVertex2f(size/2, size/2);
    glVertex2f(-size/2, size/2);
    glEnd();
    glPopMatrix();
}


void Pacman::update(int MC[][21], int filas, int columnas, float cellSize) {
    float oldX = posX;
    float oldY = posY;

    posX += directionX * speed;
    posY += directionY * speed;

    int centerCellX = static_cast<int>((posX) / cellSize);
    int centerCellY = filas - static_cast<int>((posY) / cellSize) - 1;

    int cellX = static_cast<int>(posX / cellSize);
    int cellY = filas - static_cast<int>(posY / cellSize) - 1;

    if (directionX < 0) {
        int leftCellX = static_cast<int>((posX - 2.0f) / cellSize);
        if (leftCellX >= 0 && leftCellX < columnas && cellY >= 0 && cellY < filas && MC[cellY][leftCellX] == 1) {
            posX = oldX;
            directionX = 0.0f;
        }
    } else if (directionX > 0) {
        int rightCellX = static_cast<int>((posX + 2.0f) / cellSize);
        if (rightCellX >= 0 && rightCellX < columnas && cellY >= 0 && cellY < filas && MC[cellY][rightCellX] == 1) {
            posX = oldX;
            directionX = 0.0f;
        }
    }

    if (directionY < 0) {
        int bottomCellY = filas - static_cast<int>((posY - 2.0f) / cellSize) - 1;
        if (cellX >= 0 && cellX < columnas && bottomCellY >= 0 && bottomCellY < filas && MC[bottomCellY][cellX] == 1) {
            posY = oldY;
            directionY = 0.0f;
        }
    } else if (directionY > 0) {
        int topCellY = filas - static_cast<int>((posY + 2.0f) / cellSize) - 1;
        if (cellX >= 0 && cellX < columnas && topCellY >= 0 && topCellY < filas && MC[topCellY][cellX] == 1) {
            posY = oldY;
            directionY = 0.0f;
        }
    }
}
void Pacman::setDirection(float dx, float dy) {
    directionX = dx;
    directionY = dy;
}
