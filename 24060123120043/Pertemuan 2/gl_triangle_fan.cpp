#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void drawSun() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk matahari
    glVertex2f(0.0f, 0.0f); // Titik pusat
    
    int numTriangles = 20;
    float radius = 0.4f;
    for (int i = 0; i <= numTriangles; i++) {
        float angle = 2.0f * M_PI * i / numTriangles;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "Sun Triangle Fan", NULL, NULL);
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
        drawSun();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
