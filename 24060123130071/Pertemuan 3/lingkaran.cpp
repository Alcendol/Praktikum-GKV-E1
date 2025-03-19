#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void drawCircle() {
    const float radius = 0.5f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 360; i += 10) {
        float angle = M_PI * i / 180.0f;
        glColor3f(1.0f - i / 360.0f, 0.0f, i / 360.0f);
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 640, "Lingkaran", NULL, NULL);
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
        drawCircle();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}