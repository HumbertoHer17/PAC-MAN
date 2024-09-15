#include <GL/glut.h>
#include <cmath>
#include "Pacman.h"
#include "Fantasma.h"

const int filas = 21;
const int columnas = 21;
const float cellSize = 5.0f;

int MC[21][21] = {
    //1 2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, /*1*/
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, /*2*/
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1}, /*3*/
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1}, /*4*/
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1}, /*5*/
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, /*6*/
    {1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1}, /*7*/
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1}, /*8*/
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1}, /*9*/
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, /*10*/
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, /*11*/
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1}, /*12*/
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1}, /*13*/
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, /*14*/
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1}, /*15*/
    {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1}, /*16*/
    {1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1}, /*17*/
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, /*18*/
    {1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1}, /*19*/
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, /*20*/
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, /*21*/
}; // Matriz de control

Pacman pacman(7.5f, 7.5f, 1.0f);
Fantasma fantasma1(1.0f, 97.5f, 77.5f, 0, 255, 255); // Fantasma Cian
Fantasma fantasma2(1.0f, 7.5f, 77.5f, 255, 0, 0); // Fantasma Rojo
Fantasma fantasma3(1.0f, 7.5f, 27.5f, 255, 165, 0); // Fantasma Naranja
Fantasma fantasma4(1.0f, 97.5f, 27.5f, 255, 182, 193); // Fantasma Rosa
float posX = 7.5f;
float posY = 7.5f;
float speed = 1.0f;
float directionX = 1.0f;
float directionY = 0.0f;

void drawLaberinto() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (MC[i][j] == 1) {
                glBegin(GL_QUADS);
                glColor3ub(0, 0, 250); // Color Azul
                glVertex2f(j * cellSize, (filas - i - 1) * cellSize);
                glVertex2f((j + 1) * cellSize, (filas - i - 1) * cellSize);
                glVertex2f((j + 1) * cellSize, (filas - i) * cellSize);
                glVertex2f(j * cellSize, (filas - i) * cellSize);
                glEnd();

            } else {
                glBegin(GL_QUADS);
                glColor3ub(255, 255, 0); // Color Amarillo
                glVertex2f(j * cellSize + 2, (filas - i - 1) * cellSize + 2);
                glVertex2f((j + 1) * cellSize - 2, (filas - i - 1) * cellSize + 2);
                glVertex2f((j + 1) * cellSize - 2, (filas - i) * cellSize - 2);
                glVertex2f(j * cellSize + 2, (filas - i) * cellSize - 2);
                glEnd();
            }
        }
    }
}

void drawObjeto() {
    pacman.draw();
    fantasma1.draw();
    fantasma2.draw();
    fantasma3.draw();
    fantasma4.draw();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 105, 0, 105);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawLaberinto();
    drawObjeto();

    glFlush();
}

void update(int value) {
    pacman.update(MC, filas, columnas, cellSize);
    fantasma1.update(MC, filas, columnas, cellSize);
    fantasma2.update(MC, filas, columnas, cellSize);
    fantasma3.update(MC, filas, columnas, cellSize);
    fantasma4.update(MC, filas, columnas, cellSize);
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void movimientoTeclas(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            pacman.setDirection(0.0f, 1.0f);
            break;
        case 's':
            pacman.setDirection(0.0f, -1.0f);
            break;
        case 'a':
            pacman.setDirection(-1.0f, 0.0f);
            break;
        case 'd':
            pacman.setDirection(1.0f, 0.0f);
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Pacman");

    glutDisplayFunc(display);
    glutKeyboardFunc(movimientoTeclas);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutTimerFunc(100, update, 0);

    glutMainLoop();
    return 0;
}
