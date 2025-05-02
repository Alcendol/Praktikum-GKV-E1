#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double rotAngle = 10;  // Rotasi sumbu Y
double rotAngle1 = 10; // Rotasi sumbu X

void drawCylinder(float radius, float height, int slices) {
    float angleStep = 2.0f * M_PI / slices;

    // Sisi silinder
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        glVertex3f(x, 0, z);
        glVertex3f(x, height, z);
    }
    glEnd();

    // Bagian bawah
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);
    for (int i = 0; i <= slices; ++i) {
        float angle = i * angleStep;
        glVertex3f(radius * cos(angle), 0, radius * sin(angle));
    }
    glEnd();

    // Bagian atas
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0);
    for (int i = 0; i <= slices; ++i) {
        float angle = i * angleStep;
        glVertex3f(radius * cos(angle), height, radius * sin(angle));
    }
    glEnd();
}

void drawCone(float radius, float height, int slices) {
    float angleStep = 2.0f * M_PI / slices;

    // Ujung bawah
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0); // Ujung kerucut (bawah)
    for (int i = 0; i <= slices; ++i) {
        float angle = i * angleStep;
        glVertex3f(radius * cos(angle), height, radius * sin(angle));
    }
    glEnd();

    // Tutup atas (lingkaran besar)
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0);
    for (int i = 0; i <= slices; ++i) {
        float angle = i * angleStep;
        glVertex3f(radius * cos(angle), height, radius * sin(angle));
    }
    glEnd();
}


void drawPartialSphere(float radius, int stacks, int slices, float startPhi, float endPhi) {
    for (int i = 0; i < stacks; ++i) {
        float phi1 = startPhi + (i * (endPhi - startPhi)) / stacks;
        float phi2 = startPhi + ((i + 1) * (endPhi - startPhi)) / stacks;
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float theta = (j * 2 * M_PI) / slices;

            float x1 = radius * sin(phi1) * cos(theta);
            float y1 = radius * cos(phi1);
            float z1 = radius * sin(phi1) * sin(theta);

            float x2 = radius * sin(phi2) * cos(theta);
            float y2 = radius * cos(phi2);
            float z2 = radius * sin(phi2) * sin(theta);

            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }
}

void drawHandle() {
    const int segments = 20;
    const float radius = 0.05f;
    for (int i = 0; i < segments; ++i) {
        float t1 = -M_PI / 2 + i * M_PI / segments;
        float t2 = -M_PI / 2 + (i + 1) * M_PI / segments;

        float x1 = cos(t1) * 0.5f + 0.45f;
        float y1 = sin(t1) * 0.5f + 0.5f;

        float x2 = cos(t2) * 0.5f + 0.45f;
        float y2 = sin(t2) * 0.5f + 0.5f;

        glPushMatrix();
        glTranslatef(x1, y1, 0.0f);

        // Arah vektor ke segmen berikutnya
        float dx = x2 - x1;
        float dy = y2 - y1;
        float angle = atan2(dy, dx) * 180.0 / M_PI;

        glRotatef(angle, 0, 0, 1);
        drawCylinder(radius, sqrt(dx*dx + dy*dy), 8);
        glPopMatrix();
    }
}


void drawTeko() {
    glColor3f(1.0f, 0.5f, 0.0f);
    drawCylinder(0.5f, 1.0f, 32); // Badan teko

    glPushMatrix(); // Tutup (turunkan sedikit untuk hilangkan gap)
    glTranslatef(0.0f, 0.65f, 0.0f); // Lebih menempel ke badan teko
    glColor3f(0.8f, 0.4f, 0.0f);
    drawPartialSphere(0.5f, 16, 32, 0.0f, M_PI / 4);
    glPopMatrix();

    glPushMatrix(); // Gagang
    glColor3f(0.9f, 0.6f, 0.0f);
    drawHandle();
    glPopMatrix();

    glPushMatrix(); // Corong
    glTranslatef(-0.53f, 0.8f, 0.0f); // Y dinaikkan agar menyatu ke badan
    glRotatef(-5.0f, 0, 0, 1);
    glColor3f(0.9f, 0.5f, 0.2f);
    drawCone(0.2f, 0.25f, 32);
    glPopMatrix();
}

void init(int width, int height) {
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)width / (float)height;
    glFrustum(-aspect, aspect, -1.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -4.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotated(rotAngle, 0, 1, 0);
    glRotated(rotAngle1, 1, 0, 0);

    drawTeko();

    glPopMatrix();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_A: rotAngle += 5; break;
            case GLFW_KEY_L: rotAngle -= 5; break;
            case GLFW_KEY_Y: rotAngle1 += 5; break;
            case GLFW_KEY_B: rotAngle1 -= 5; break;
            case GLFW_KEY_Q: glfwSetWindowShouldClose(window, GLFW_TRUE); break;
        }
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    init(width, height);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Teko 3D", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

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
