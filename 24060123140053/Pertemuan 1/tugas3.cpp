#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <GL/glew.h>


void segiempat() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.18f, 0.18f);
    glVertex2f(0.18f, 0.18f);
    glVertex2f(0.18f, -0.18f);
    glVertex2f(-0.18f, -0.18f);
    glEnd();
    glFlush();
}

void segiempat2() {
    glBegin(GL_QUADS);
    glColor3f(15.0f, 3.0f, 2.0f);
    glVertex2f(-0.16f, 0.16f);
    glVertex2f(0.16f, 0.16f);
    glVertex2f(0.16f, -0.16f);
    glVertex2f(-0.16f, -0.16f);
    glEnd();
    glFlush();
}

void segiempat3() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.14f, 0.14f);
    glVertex2f(0.14f, 0.14f);
    glVertex2f(0.14f, -0.14f);
    glVertex2f(-0.14f, -0.14f);
    glEnd();
    glFlush();
}

void segiempat4() {
    glBegin(GL_QUADS);
    glColor3f(15.0f, 3.0f, 2.0f);
    glVertex2f(-0.12f, 0.12f);
    glVertex2f(0.12f, 0.12f);
    glVertex2f(0.12f, -0.12f);
    glVertex2f(-0.12f, -0.12f);
    glEnd();
    glFlush();
}

void segiempat4() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.10f, 0.10f);
    glVertex2f(0.10f, 0.10f);
    glVertex2f(0.10f, -0.10f);
    glVertex2f(-0.10f, -0.10f);
    glEnd();
    glFlush();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "SEGI EMPAT 2", NULL,
NULL);
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
        segiempat();
        segiempat2();
        segiempat3();
        segiempat4();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
