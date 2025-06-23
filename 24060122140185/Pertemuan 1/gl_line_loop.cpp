#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void drawLineLoop() {
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(0.5f, 0.5f); 
    glVertex2f(1.0f, -0.5f);    
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "Titik", NULL,
    NULL);
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
        drawLineLoop();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}