// Nama : Sophie Venecia May M
// Nim  : 24060123120043


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>  

void drawWavyLine() {
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f); // Garis putih
    for (float x = -0.9f; x <= 0.9f; x += 0.1f) {
        float y = 0.2f * sin(10 * x);  
        glVertex2f(x, y);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "Wavy Line Strip", NULL, NULL);
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
        drawWavyLine();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
