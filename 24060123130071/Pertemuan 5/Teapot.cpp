#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

double rotAngle = 10; // rotation angle around y-axis
double rotAngle1 = 10; // rotation angle around x-axis
const float PI = 3.14159265f;

void drawCylinder(float radius, float height, int slices) {
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= slices; ++i) {
        float theta = (2.0f * PI * i) / slices;
        float x = radius * cos(theta);
        float z = radius * sin(theta);

        glVertex3f(x, 0, z);
        glVertex3f(x, height, z);
    }
    glEnd();
}

void drawHalfSphere(float radius, int stacks, int slices) {
    for (int i = 0; i < stacks / 2; ++i) {
        float theta1 = (PI * i) / stacks;
        float theta2 = (PI * (i + 1)) / stacks;

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float phi = (2 * PI * j) / slices;

            float x1 = radius * sin(theta1) * cos(phi);
            float y1 = radius * cos(theta1);
            float z1 = radius * sin(theta1) * sin(phi);

            float x2 = radius * sin(theta2) * cos(phi);
            float y2 = radius * cos(theta2);
            float z2 = radius * sin(theta2) * sin(phi);

            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }
}

void drawSphere(float radius, int stacks, int slices) {
    for (int i = 0; i < stacks; ++i) {
        float theta1 = (PI * i) / stacks;
        float theta2 = (PI * (i + 1)) / stacks;

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float phi = (2 * PI * j) / slices;

            float x1 = radius * sin(theta1) * cos(phi);
            float y1 = radius * cos(theta1);
            float z1 = radius * sin(theta1) * sin(phi);

            float x2 = radius * sin(theta2) * cos(phi);
            float y2 = radius * cos(theta2);
            float z2 = radius * sin(theta2) * sin(phi);

            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }
}

void drawTeapot() {
    // Badan
    glColor3f(0.8f, 0.4f, 0.2f);
    drawSphere(0.5f, 20, 20);

    // Tutup
    glPushMatrix();
        glTranslatef(0.0f, 0.5f, 0.0f);
        drawHalfSphere(0.2f, 10, 20);
    glPopMatrix();

    // Cerat (Spout)
    glPushMatrix();
        glColor3f(1.0, 0.1, 0.1);
        glTranslatef(0.4f, 0.0f, 0.2f);
        glRotatef(-45, 0, 0, 1);
        drawCylinder(0.07f, 0.3f, 20);
    glPopMatrix();

    // Pegangan
    glPushMatrix();
    glColor3f(1.0, 0.1, 0.1);
    glTranslatef(-0.4f, 0.0f, 0.0f); // pos awal pegangan
    glRotatef(90, 0, 0, 1);
    int segments = 30;
    float radius = 0.3f;
    float tubeRadius = 0.05f;
    for (int i = 0; i < segments; ++i) {
        float theta1 = (PI * i) / segments;
        float theta2 = (PI * (i + 1)) / segments;

        // titik awal dan akhir segmen
        float x1 = radius * cos(theta1);
        float y1 = radius * sin(theta1);
        float x2 = radius * cos(theta2);
        float y2 = radius * sin(theta2);

        // hitung arah segmen
        float dx = x2 - x1;
        float dy = y2 - y1;
        float angle = atan2(dy, dx) * 180.0f / PI;

        glPushMatrix();
            glTranslatef(x1, y1, 0);
            glRotatef(angle, 0, 0, 1); // putar mengikuti arah kurva
            drawCylinder(tubeRadius, sqrt(dx*dx + dy*dy), 8);
        glPopMatrix();
    }
glPopMatrix();

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
    glTranslatef(0.0f, 0.0f, -2.0f);
    
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
    glPushMatrix();
    glRotated(rotAngle, 0, 1, 0);
    glRotated(rotAngle1, 1, 0, 0);
    
    glEnable(GL_COLOR_MATERIAL);
    drawTeapot();
    
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

    GLFWwindow* window = glfwCreateWindow(800, 800, "Teapot", NULL, NULL);
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
