/*Nama: Radityantari Kusuma Wardani
  NIM : 24060123130059*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void init() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void background() {
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.6f, 1.0f);  // Biru langit
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.6f);  // Biru laut
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void kotak() {
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.8f); // Oranye transparan
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

void segitiga() {
    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 0.0f, 0.8f); // Kuning transparan
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glEnd();
}

void lingkaran() {
    glBegin(GL_TRIANGLE_FAN);
    glColor4f(0.0f, 1.0f, 1.0f, 0.7f); // Cyan transparan
    glVertex2f(0.7f, 0.7f);
    for (int i = 0; i <= 50; i++) {
        float angle = i * 2.0f * 3.14159f / 50;
        glVertex2f(0.7f + 0.1f * cos(angle), 0.7f + 0.1f * sin(angle));
    }
    glEnd();
}

void garisStrip() {
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(-0.4f, -0.8f);
    glEnd();
}

void garisLoop() {
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.4f, -0.8f);
    glVertex2f(0.6f, -0.6f);
    glVertex2f(0.8f, -0.8f);
    glEnd();
}

void triangleStrip() {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.6f, 0.2f);
    glVertex2f(-0.4f, 0.5f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

void quadStrip() {
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.4f, 0.5f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    background();
    kotak();
    segitiga();
    lingkaran();
    garisStrip();
    garisLoop();
    triangleStrip();
    quadStrip();
    glFlush();
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "Gambar", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) return -1;

    init();

    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
