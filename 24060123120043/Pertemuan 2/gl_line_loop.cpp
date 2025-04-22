// Nama : Sophie Venecia May M
// Nim  : 24060123120043

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void drawStar() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f); 
    float points[10][2] = {
        {0.0f, 0.5f}, {-0.2f, 0.2f}, {-0.5f, 0.2f},
        {-0.3f, 0.0f}, {-0.4f, -0.3f}, {0.0f, -0.1f},
        {0.4f, -0.3f}, {0.3f, 0.0f}, {0.5f, 0.2f}, {0.2f, 0.2f}
    };
    for (int i = 0; i < 10; i++) {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "Star Line Loop", NULL, NULL);
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
        drawStar();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
