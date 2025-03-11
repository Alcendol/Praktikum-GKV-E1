// Nama : Sophie Venecia May M
// Nim  : 24060123120043

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void drawWave() {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Warna biru laut
    for (float x = -0.9f; x <= 0.9f; x += 0.1f) {
        float y1 = 0.1f * sin(10 * x);
        float y2 = y1 - 0.2f;
        glVertex2f(x, y1);
        glVertex2f(x, y2);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "Wave Triangle Strip", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    glClearColor(0.0f, 0.5f, 0.0f, 1.0f); // Background hijau tua
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawWave();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
