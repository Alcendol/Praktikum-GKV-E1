#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>
#include <cmath>

double rotAngle = 10; // rotation angle around y-axis
double rotAngle1 = 10; // rotation angle around x-axis

// Fungsi untuk menggambar cincin/torus
void drawRing(float outerRadius, float innerRadius, int sides, int rings) {
    // outerRadius: radius luar cincin
    // innerRadius: radius penampang cincin (ketebalan)
    // sides: jumlah segmen dalam penampang cincin
    // rings: jumlah segmen melingkar

    const float PI = 3.14159265358979323846f;
    float ringDelta = 2.0f * PI / float(rings);
    float sideDelta = 2.0f * PI / float(sides);
    
    float theta = 0.0f;
    for (int i = 0; i < rings; i++) {
        float theta1 = theta + ringDelta;
        float cosTheta = cos(theta);
        float sinTheta = sin(theta);
        float cosTheta1 = cos(theta1);
        float sinTheta1 = sin(theta1);
        
        glBegin(GL_QUAD_STRIP);
        float phi = 0.0f;
        for (int j = 0; j <= sides; j++) {
            phi = j * sideDelta;
            float cosPhi = cos(phi);
            float sinPhi = sin(phi);
            float dist = outerRadius + innerRadius * cosPhi;
            
            // Warna berdasarkan posisi untuk efek visual
            float colorR = (sinTheta + 1.0f) / 2.0f;
            float colorG = (cosTheta + 1.0f) / 2.0f;
            float colorB = (sinPhi + 1.0f) / 2.0f;
            
            glColor3f(colorR, colorG, colorB);
            
            // Titik pertama
            float x = cosTheta * dist;
            float y = -sinTheta * dist;
            float z = innerRadius * sinPhi;
            glVertex3f(x, y, z);
            
            // Titik kedua
            x = cosTheta1 * dist;
            y = -sinTheta1 * dist;
            z = innerRadius * sinPhi;
            glVertex3f(x, y, z);
        }
        glEnd();
        
        theta = theta1;
    }
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
    drawRing(0.7f, 0.3f, 16, 32);

    glPopMatrix();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_A:
                rotAngle += 5;
                break;
            case GLFW_KEY_W:
                rotAngle1 += 5;
                break;
            case GLFW_KEY_E:
                rotAngle1 -= 5;
                break;
            case GLFW_KEY_D:
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

    GLFWwindow* window = glfwCreateWindow(800, 800, "GLFW Ring Example", NULL, NULL);
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