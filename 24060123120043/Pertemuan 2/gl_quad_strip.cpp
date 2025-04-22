// Nama : Sophie Venecia May M
// Nim  : 24060123120043
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawTrack() {
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    for (float x = -0.8f; x <= 0.8f; x += 0.2f) {
        glVertex2f(x, -0.5f);
        glVertex2f(x + 0.1f, 0.5f);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "Simple Track", NULL, NULL);
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
        drawTrack();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}