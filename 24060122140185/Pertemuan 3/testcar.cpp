#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#define M_PI 3.14159265358979323846

void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawCar() {
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(-0.3f, -0.1f, 0.3f, 0.1f);
    glColor3f(0.8f, 0.0f, 0.0f);
    glRectf(-0.2f, 0.1f, 0.2f, 0.2f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.2f, -0.12f, 0.05f);
    drawCircle(0.2f, -0.12f, 0.05f);
    
    glPopMatrix();
}

void drawRoad() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glRectf(-1.0f, -0.3f, 1.0f, -0.6f);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (float i = -1.0f; i < 1.0f; i += 0.2f) {
        glRectf(i, -0.45f, i + 0.1f, -0.42f);
    }
}

void drawEnvironment() {
    glColor3f(0.5f, 0.8f, 1.0f);
    glRectf(-1.0f, 0.0f, 1.0f, 1.0f);
    glColor3f(0.0f, 0.8f, 0.0f);
    glRectf(-1.0f, -1.0f, 1.0f, 0.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawEnvironment();
    drawRoad();
    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.0f);
    drawCar();
    glPopMatrix();
    glFlush();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Tugas Mobil", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glewInit();
    init();
    
    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
