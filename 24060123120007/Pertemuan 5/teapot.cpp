/*
Nama: Shofi Rasyida Nata
NIM: 24060123120007
LAB: GKV E1
Deskripsi: Membuat teko/teapot
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

double rotAngle = 10;    //rotasi sumbu Y
double rotAngle1 = 10;   //rotasi sumbu X

void drawTeapot() {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);

    //badan teapot
    glColor3f(0.7f, 0.2f, 0.2f);
    gluSphere(quad, 0.5, 32, 32);

    //tutup
    glPushMatrix();
    glColor3f(0.9f, 0.5f, 0.2f);
    glTranslatef(0.0f, 0.55f, 0.0f);
    gluSphere(quad, 0.08, 16, 16);
    glPopMatrix();

    //dasar teapot
    glPushMatrix();
    glColor3f(0.3f, 0.2f, 0.1f);
    glTranslatef(0.0f, -0.52f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    gluDisk(quad, 0.0f, 0.52f, 32, 1);
    glPopMatrix();

    //pegangan teapot
    glPushMatrix();
    glColor3f(0.6f, 0.2f, 0.2f); 
    for (float angle = -90.0f; angle <= 90.0f; angle += 15.0f) {
        glPushMatrix();
        glTranslatef(-0.45f, 0.0f, 0.0f);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.0f, 0.22f, 0.0f);
        glRotatef(90, 1, 0, 0);
        gluCylinder(quad, 0.025, 0.025, 0.04, 12, 1);
        glPopMatrix();
    }
    glPopMatrix();

    //corong
    glPushMatrix();
    glColor3f(0.6f, 0.2f, 0.2f);
    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glTranslatef(0.43f + (i * 0.05f), 0.1f + (i * 0.03f), 0.0f);
        glRotatef(-25 + (i * 5), 0, 0, 1);
        glRotatef(90, 0, 1, 0);
        gluCylinder(quad, 0.025f - (i * 0.005f), 0.02f - (i * 0.005f), 0.05f, 12, 1);
        glPopMatrix();
    }
    glPopMatrix();

    gluDeleteQuadric(quad);
}

void init(int width, int height) {
    glClearColor(0, 0, 0, 1);
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
    glRotated(rotAngle, 0, 1, 0);    //rotasi sumbu Y
    glRotated(rotAngle1, 1, 0, 0);   //rotasi sumbu X

    drawTeapot();

    glPopMatrix();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_A:
                rotAngle += 5;
                break;
            case GLFW_KEY_L:
                rotAngle -= 5;
                break;
            case GLFW_KEY_Y:
                rotAngle1 += 5;
                break;
            case GLFW_KEY_B:
                rotAngle1 -= 5;
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
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Teapot", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

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
