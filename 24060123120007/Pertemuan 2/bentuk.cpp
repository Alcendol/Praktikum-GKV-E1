/*Nama      : Shofi Rasyida Nata
NIM         : 24060123120007
Lab         : GKV E1
Deskripsi   : Membuat bentuk dengan primitif GL_LINE_STRIP, GL_LINE_LOOP, 
GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP, GL_QUADS, dan GL_QUAD_STRIP.*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void bentuk() {
    glClear(GL_COLOR_BUFFER_BIT);
    //Bentuk zig-zag (GL_LINE_STRIP)
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 0.6, 0.6);  
    glVertex2f(-0.7f, 0.7f);
    glVertex2f(-0.5f, 0.9f);
    glVertex2f(-0.3f, 0.7f);
    glVertex2f(-0.1f, 0.9f);
    glVertex2f(0.1f, 0.7f);
    glEnd();

    //Bentuk bintang (GL_LINE_LOOP)
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 0.7);  
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.5f, 0.9f);
    glVertex2f(0.7f, 0.7f);
    glVertex2f(0.2f, 0.85f);
    glVertex2f(0.7f, 0.85f);
    glEnd();

    //Bentuk panah ke atas (GL_TRIANGLE_FAN)
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.6, 1.0, 0.6);  
    glVertex2f(-0.6f, 0.2f);
    glVertex2f(-0.9f, -0.1f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(-0.8f, -0.4f);
    glEnd();

    //Bentuk abstrak (GL_TRIANGLE_STRIP)
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.7, 0.7, 1.0); 
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(0.2f, 0.3f);
    glEnd();

    //Kubus (GL_QUADS)
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.8, 0.6);  
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(-0.2f, -0.8f);
    glVertex2f(-0.5f, -0.8f);
    glEnd();

    //Balok (GL_QUAD_STRIP)
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.8, 0.6, 1.0); 
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.1f, -0.7f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.7f, -0.7f);
    glEnd();

    glFlush();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(600, 600, "OpenGL Pastel", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();
    glClearColor(0.2, 0.0, 0.2, 1.0);  

    while (!glfwWindowShouldClose(window)) {
        bentuk();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
