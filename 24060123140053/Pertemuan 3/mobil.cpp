#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#define PI 3.14159265358979323846

void drawCircle(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * PI * i / 100;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y - height);
    glVertex2f(x, y - height);
    glEnd();
}


void drawCar() {
    glPushMatrix();
    glTranslatef(-0.2f, -0.3f, 0.0f);

    // Badan dan atap mobil 
    glColor3f(0.6f, 0.0f, 0.0f);
    drawRectangle(-0.3f, 0.1f, 0.6f, 0.2f);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawRectangle(-0.05f, 0.2f, 0.2f, 0.15f);
    
    // Jendela
    glColor3f(0.0f, 0.0f, 1.0f);
    drawRectangle(0.02f, 0.17f, 0.08f, 0.05f);
    
    // Roda 
    glColor3f(0.75f, 0.75f, 0.75f);
    drawCircle(-0.2f, -0.1f, 0.075f);
    drawCircle(0.2f, -0.1f, 0.075f);
    
    glPopMatrix();
}


void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);

    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Jalanan
    glColor3f(0.0f, 0.0f, 0.0f);
    drawRectangle(-1.0f, -0.4f, 2.0f, -0.2f);
    drawRectangle(-1.0f, -0.6f, 2.0f, -0.2f);
    drawRectangle(-1.0f, -0.8f, 2.0f, -0.2f);
    
    // garis jalan
    glColor3f(1.0f, 1.0f, 1.0f);
    drawRectangle(-0.8f, -0.45f, 0.2f, 0.05f);
    drawRectangle(-0.4f, -0.45f, 0.2f, 0.05f);
    drawRectangle(0.0f, -0.45f, 0.2f, 0.05f);
    drawRectangle(0.4f, -0.45f, 0.2f, 0.05f);
    
    // Matahari
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.8f, 0.8f, 0.1f);
    
    drawCar();
    glFlush();
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(640, 480, "mobil", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewInit();
    
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        drawScene();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}