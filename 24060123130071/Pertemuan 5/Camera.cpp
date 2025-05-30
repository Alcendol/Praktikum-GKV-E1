#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

double rotAngle = 10; // rotation angle around y-axis
double rotAngle1 = 10; // rotation angle around x-axis

void drawCube(float size) {
    float half = size / 2.0f;

    glBegin(GL_QUADS);
        glColor3f(1.0, 0.1, 0.1);
        glVertex3f(-half, -half, half);
        glVertex3f(half, -half, half);
        glVertex3f(half, half, half);
        glVertex3f(-half, half, half);
        glColor3f(0.1, 1.0, 0.1);
        glVertex3f(-half, -half, -half);
        glVertex3f(-half, half, -half);
        glVertex3f(half, half, -half);
        glVertex3f(half, -half, -half);
        glColor3f(0.1, 0.1, 1.0);
        glVertex3f(-half, half, -half);
        glVertex3f(-half, half, half);
        glVertex3f(half, half, half);
        glVertex3f(half, half, -half);
        glColor3f(1.0, 1.0, 0.1);
        glVertex3f(-half, -half, -half);
        glVertex3f(half, -half, -half);
        glVertex3f(half, -half, half);
        glVertex3f(-half, -half, half);
        glColor3f(1.0, 0.1, 1.0);
        glVertex3f(half, -half, -half);
        glVertex3f(half, half, -half);
        glVertex3f(half, half, half);
        glVertex3f(half, -half, half);

        glColor3f(0.1, 1.0, 1.0);
        glVertex3f(-half, -half, -half);
        glVertex3f(-half, -half, half);
        glVertex3f(-half, half, half);
        glVertex3f(-half, half, -half);
    glEnd();
}

void init(int width, int height) {
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)width / (float)height;
    glFrustum(-aspect, aspect, -1.0, 1.0, 1.0, 1000.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
    glPushMatrix();
    glRotated(rotAngle, 0, 1, 0);
    glRotated(rotAngle1, 1, 0, 0);
    
    glEnable(GL_COLOR_MATERIAL);
    drawCube(1.0f);
    
    glPopMatrix();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_A:
                rotAngle += 5;
                break;
            case GLFW_KEY_Y:
                rotAngle1 += 5;
                break;
            case GLFW_KEY_B:
                rotAngle1 -= 5;
                break;
            case GLFW_KEY_L:
                rotAngle -= 5;
                break;
            case GLFW_KEY_Q:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
        }
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    init(width, height);
}

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "GLFWExample", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    init(width, height);
    
    while (!glfwWindowShouldClose(window)) {
        display();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}