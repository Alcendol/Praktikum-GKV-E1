#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>
#include <cmath>

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

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); 
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = cos(angle) * radius;
        float z = sin(angle) * radius;
        glVertex3f(x, 0.0f, z);
    }
    glEnd();
}

void drawHalfCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); 
    for (int i = 0; i <= segments; i++) {
        float angle = M_PI * i / segments;
        float x = cos(angle) * radius;
        float y = sin(angle) * radius;
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void drawCylinder(float radius, float height, int segments) {
    float half = height / 2.0f;

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = cos(angle) * radius;
        float z = sin(angle) * radius;
        glVertex3f(x, -half, z);
        glVertex3f(x, half, z);
    }
    glEnd();

    glPushMatrix();
    glTranslatef(0.0f, -half, 0.0f);
    drawCircle(radius, segments);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, half, 0.0f);
    drawCircle(radius, segments);
    glPopMatrix();
}

void drawSphere(float radius, int slices, int stacks) {
    for (int i = 0; i < stacks; ++i) {
        float phi1 = M_PI * (-0.5f + (float)(i) / stacks);
        float phi2 = M_PI * (-0.5f + (float)(i + 1) / stacks);
        
        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float t = 2.0f * M_PI * (float)(j) / slices;
            
            float x1 = cos(t) * cos(phi1);
            float y1 = sin(phi1);
            float z1 = sin(t) * cos(phi1);
            
            float x2 = cos(t) * cos(phi2);
            float y2 = sin(phi2);
            float z2 = sin(t) * cos(phi2);
            
            glVertex3f(x1 * radius, y1 * radius, z1 * radius);
            glVertex3f(x2 * radius, y2 * radius, z2 * radius);
        }
        glEnd();
    }
}

void drawTeapot() {
    //body
    glPushMatrix();
    glColor3f(0.8, 0.4, 0.2);
    glScalef(1.0f, 1.0f, 1.0f); 
    drawSphere(1.0f, 36, 18);
    glPopMatrix();

    //tutup
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glScalef(1.0f, 0.3f, 1.0f); 
    glColor3f(0.8, 0.4, 0.2);
    drawSphere(0.8f, 36, 18); 
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.0f); 
    glColor3f(0.9, 0.5, 0.3);
    drawSphere(0.2f, 24, 12); 
    glPopMatrix();
    glPopMatrix();

    ///corong
    glPushMatrix();
    glTranslatef(1.0f, 0.1f, 0.0f);
    glRotatef(-45, 0, 0, 1);
    glRotatef(90, 0, 1, 0);
    glColor3f(0.7, 0.3, 0.2);
    
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 36; i++) {
        float angle = 2.0f * M_PI * i / 36;
        float r1 = 0.15f;
        float r2 = 0.1f;
        float x1 = cos(angle) * r1;
        float z1 = sin(angle) * r1;
        float x2 = cos(angle) * r2;
        float z2 = sin(angle) * r2;
        glVertex3f(x1, -0.5f, z1);
        glVertex3f(x2, 0.5f, z2);
    }
    glEnd();
    glPopMatrix();

    //handle
    glPushMatrix();
    glTranslatef(-0.9f, 0.1f, 0.0f);
    glRotatef(90, 1, 0, 0);
    glColor3f(0.6, 0.3, 0.2);
    
    for (int i = 0; i < 18; i++) {
        float angle1 = M_PI * i / 18;
        float angle2 = M_PI * (i + 1) / 18;
        
        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= 36; j++) {
            float t = 2.0f * M_PI * j / 36;
            float r = 0.1f;
            float R = 0.5f;
            
            float x1 = (R + r * cos(angle1)) * cos(t);
            float y1 = r * sin(angle1);
            float z1 = (R + r * cos(angle1)) * sin(t);
            
            float x2 = (R + r * cos(angle2)) * cos(t);
            float y2 = r * sin(angle2);
            float z2 = (R + r * cos(angle2)) * sin(t);
            
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
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
    glTranslatef(0.0f, 0.0f, -5.0f);

    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotated(rotAngle1, 1, 0, 0);
    glRotated(rotAngle, 0, 1, 0);
    drawTeapot();
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
            case GLFW_KEY_S:
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

int main(){
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