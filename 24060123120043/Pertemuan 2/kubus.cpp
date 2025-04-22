// Nama : Sophie Venecia May M
// Nim  : 24060123120043

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void drawCube(float x, float y, float size) {
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.5f, 0.8f); 

    // Persegi depan
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);

    glEnd();
}

void drawStackedCubes() {
    float size = 0.2f;


    drawCube(-0.35f, -0.3f, size);
    drawCube(-0.10f, -0.3f, size);
    drawCube(0.15f, -0.3f, size);


    drawCube(-0.225f, -0.1f, size);
    drawCube(0.025f, -0.1f, size);


    drawCube(-0.10f, 0.1f, size);
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Stacked Cubes", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);
    glewInit();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawStackedCubes();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
