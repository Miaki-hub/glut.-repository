#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <conio.h>
int xc, yc, radius;

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white.
    glMatrixMode(GL_PROJECTION);      // Set projection parameters.
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void setPixel(GLint x, GLint y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawCircle(int xc, int yc, int radius) {
    int x = radius;
    int y = 0;
    int decision = 1 - radius;
    while (y <= x) {
        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        setPixel(xc + y, yc + x);
        setPixel(xc - y, yc + x);
        setPixel(xc + y, yc - x);
        setPixel(xc - y, yc - x);
        if (decision <= 0)
            decision += 2 * y + 3;
        else {
            decision += 2 * (y - x) + 5;
            x--;
        }
        y++;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(xc, yc, radius);
    glFlush();
}

int main(int argc, char** argv) {
    // Prompt user for circle parameters
    std::cout << "Enter the center coordinates (xc yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the radius: ";
    std::cin >> radius;

    glutInit(&argc, argv);                  // Initialize GLUT.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
    glutInitWindowPosition(50, 100);            // Set top-left display-window position.
    glutInitWindowSize(400, 300);               // Set display-window width and height.
    glutCreateWindow("Circle Drawing");         // Create display window.
    init();                                    // Execute initialization procedure.
    glutDisplayFunc(display);                   // Send graphics to display window.
    glutMainLoop();                            // Display everything and wait.
    return 0;
}

