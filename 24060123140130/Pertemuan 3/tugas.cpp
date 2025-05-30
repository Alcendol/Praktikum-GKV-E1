#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * M_PI * i / 100;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawCar() {
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Merah untuk badan mobil
    drawRectangle(-0.35f, -0.1f, 0.7f, 0.2f);
    
    glColor3f(0.0f, 0.0f, 1.0f); // Biru untuk kaca depan
    drawRectangle(-0.2f, 0.05f, 0.4f, 0.15f);
    
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam untuk roda
    drawCircle(-0.25f, -0.15f, 0.07f);
    drawCircle(0.25f, -0.15f, 0.07f);
    glPopMatrix();
}

void drawRoad() {
    glColor3f(0.2f, 0.2f, 0.2f);
    drawRectangle(-1.0f, -0.3f, 2.0f, 0.2f);
}

void drawBackground() {
    glColor3f(1.0f, 0.5f, 0.0f); // Orange untuk langit
    drawRectangle(-1.0f, 0.0f, 2.0f, 1.0f);
    
    glColor3f(0.0f, 0.6f, 0.0f); // Hijau untuk rumput
    drawRectangle(-1.0f, -0.3f, 2.0f, 0.3f);
    
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning untuk matahari
    drawCircle(0.7f, 0.7f, 0.2f);
    
    glColor3f(0.5f, 0.5f, 0.5f); // Abu-abu untuk batu
    drawCircle(-0.7f, -0.2f, 0.1f);
}

void drawFlower(float x, float y) {
    glColor3f(1.0f, 0.0f, 0.0f); // Merah untuk kelopak
    drawCircle(x, y + 0.02f, 0.02f);
    drawCircle(x - 0.02f, y, 0.02f);
    drawCircle(x + 0.02f, y, 0.02f);
    drawCircle(x, y - 0.02f, 0.02f);
    
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning untuk tengah bunga
    drawCircle(x, y, 0.015f);
    
    glColor3f(0.0f, 0.6f, 0.0f); // Hijau untuk batang
    drawRectangle(x - 0.005f, y - 0.05f, 0.01f, 0.05f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    drawBackground();
    drawRoad();
    drawCar();
    
    drawFlower(-0.5f, -0.2f);
    drawFlower(0.5f, -0.2f);
    
    glFlush();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Mobil 2D OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
