// Nama : Sophie Venecia May M
// Nim  : 24060123120043

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawPatternQuads() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(-0.1f, -0.4f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(-0.4f, -0.1f);
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.4f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.1f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.1f, 0.4f);
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "Pattern QUADS", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawPatternQuads();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}