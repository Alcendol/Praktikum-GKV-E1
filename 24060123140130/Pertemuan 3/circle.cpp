#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

const int NUM_SEGMENTS = 100; // Kembali ke bentuk lingkaran
const float RADIUS = 0.5f; // Radius lingkaran

void drawCreativeShape() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru untuk seluruh lingkaran
    glVertex2f(0.0f, 0.0f); // Pusat lingkaran
    for (int i = 0; i <= NUM_SEGMENTS; i++) {
        float angle = 2.0f * M_PI * i / NUM_SEGMENTS;
        float x = RADIUS * cos(angle);
        float y = RADIUS * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Lingkaran OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        drawCreativeShape();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
