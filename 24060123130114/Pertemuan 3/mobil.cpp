#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void drawCircle(float x, float y, float radius) {
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * M_PI * i / numSegments;
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
    glColor3f(0.0f, 0.0f, 1.0f);
    drawRectangle(-0.3f, -0.1f, 0.6f, 0.2f);
    
    glColor3f(0.0f, 0.5f, 1.0f);
    drawRectangle(-0.2f, 0.1f, 0.4f, 0.15f);
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-0.2f, -0.15f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.08f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.2f, -0.15f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.08f);
    glPopMatrix();
    
    glPopMatrix();
}

void drawRoad() {
    glColor3f(0.3f, 0.3f, 0.3f);
    drawRectangle(-1.0f, -0.4f, 2.0f, 0.4f);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    for (float i = -0.9f; i < 1.0f; i += 0.3f) {
        drawRectangle(i, -0.2f, 0.1f, 0.05f);
    }
}

void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.7f, 0.7f, 0.15f);
}

void drawTree() {
    glColor3f(0.5f, 0.25f, 0.0f);
    drawRectangle(-0.85f, 0.0f, 0.1f, 0.6f);
    glColor3f(0.0f, 0.8f, 0.0f);
    drawCircle(-0.8f, 0.6f, 0.2f);

    glColor3f(0.5f, 0.25f, 0.0f);
    drawRectangle(-0.25f, 0.0f, 0.1f, 0.6f);
    glColor3f(0.0f, 0.8f, 0.0f);
    drawCircle(-0.2f, 0.6f, 0.2f);
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Mobil 2D", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    glewInit();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        drawRoad();
        drawSun();
        drawTree();
        drawCar();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}