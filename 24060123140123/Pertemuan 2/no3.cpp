#include <GL/glew.h>
#include <GLFW/glfw3.h>

void gambarKubus(float x, float y, float ukuran, float r, float g, float b) {
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(x, y);
    glVertex2f(x + ukuran, y);
    glVertex2f(x + ukuran, y + ukuran);
    glVertex2f(x, y + ukuran);
    glEnd();
    glFlush();
}

void tingkatan() {
    gambarKubus(-0.3f, -0.4f, 0.2f, 1.0f, 0.0f, 0.0f);
    gambarKubus(-0.1f, -0.4f, 0.2f, 0.0f, 1.0f, 0.0f);
    gambarKubus(0.1f, -0.4f, 0.2f, 0.0f, 0.0f, 1.0f);
    
    gambarKubus(-0.2f, -0.2f, 0.2f, 1.0f, 1.0f, 0.0f);
    gambarKubus(0.0f, -0.2f, 0.2f, 0.0f, 1.0f, 1.0f);
    
    gambarKubus(-0.1f, 0.0f, 0.2f, 1.0f, 0.0f, 1.0f);
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "Kubus Bertingkat", NULL, NULL);
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
        
        tingkatan();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}