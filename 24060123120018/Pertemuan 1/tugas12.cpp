#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    // GL_LINE_STRIP (Garis berurutan tanpa loop)
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.8, 0.8);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.4, 0.8);
    glEnd();
    
    // GL_LINE_LOOP (Garis berurutan membentuk loop)
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.3, 0.8);
    glVertex2f(-0.1, 0.6);
    glVertex2f(0.1, 0.8);
    glVertex2f(-0.1, 1.0);
    glEnd();
    
    // GL_TRIANGLE_FAN (Kipas segitiga)
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.3, 0.8);  // Titik pusat
    glVertex2f(0.2, 0.6);
    glVertex2f(0.4, 0.6);
    glVertex2f(0.5, 0.7);
    glVertex2f(0.4, 0.9);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.1, 0.7);
    glEnd();
    
    // GL_TRIANGLE_STRIP (Strip segitiga)
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.8, 0.3);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.4, 0.3);
    glVertex2f(-0.2, 0.1);
    glEnd();
    
    // GL_QUADS (Empat sisi)
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.2);
    glVertex2f(-0.6, -0.4);
    glVertex2f(-0.4, -0.2);
    glVertex2f(-0.6, 0.0);
    glEnd();
    
    // GL_QUAD_STRIP (Strip empat sisi)
    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.0, -0.4);
    glVertex2f(0.2, -0.6);
    glVertex2f(0.4, -0.4);
    glVertex2f(0.6, -0.6);
    glEnd();
    
    glFlush();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(500, 500, "OpenGL Primitives", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glewInit();
    
    glClearColor(1, 1, 1, 1);  // Latar belakang putih
    glColor3f(0, 0, 0);  // Warna hitam
    
    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
