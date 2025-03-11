#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawCube(float x, float y, float size) {
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.5f, 1.0f);
    
    glVertex2f(x - size, y - size);
    glVertex2f(x + size, y - size);
    glVertex2f(x + size, y + size);
    glVertex2f(x - size, y + size);
    
    glEnd();
}

void drawStackedCubes() {
    float size = 0.1f;
    float spacing = 0.005f; 
    float offsetX = size * 2 + spacing;
    float offsetY = size * 2 + spacing;
    
    for (int i = 0; i < 5; i++) {
        drawCube(-offsetX * 0.5f * i, -0.5f + offsetY * i, size);
    }
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Kubus Bertingkat", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }

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