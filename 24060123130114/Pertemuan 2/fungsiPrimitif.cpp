#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawLineStrip() {
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.8f);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(-0.4f, 0.8f);
    glVertex2f(-0.2f, 0.6f);
    glEnd();
}

void drawLineLoop() {
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.2f, 0.8f);
    glVertex2f(0.4f, 0.6f);
    glVertex2f(0.6f, 0.8f);
    glVertex2f(0.8f, 0.6f);
    glEnd();
}

void drawTriangleFan() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();
}

void drawTriangleStrip() {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.6f, -0.6f);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(0.0f, -0.4f);
    glVertex2f(0.2f, -0.6f);
    glEnd();
}

void drawQuads() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(-0.6f, 0.2f);
    glEnd();
}

void drawQuadStrip() {
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Primitif OpenGL", NULL, NULL);
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
        drawLineStrip();
        drawLineLoop();
        drawTriangleFan();
        drawTriangleStrip();
        drawQuads();
        drawQuadStrip();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
