/* Nama File : cameraTeaPot.cpp
 * Deskripsi : program sederhana untuk membuat teko dan menggerakkan kamera dalam openGL
 * Pembuat   : Shopia Mudjahidah
 * NIM       : 24060123120010
 * Tanggal   : 5 April 2025 
 * Lab       : GKV E1
 */

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>
#include <cmath>

double rotY = 0.0;
double rotX = 0.0;

void drawCylinder(GLUquadric* quad, float base, float top, float height){
    gluCylinder(quad, base, top, height, 32, 32);
}

void drawDisk(GLUquadric* quad, float inner, float outer){
    gluDisk(quad, inner, outer, 32, 1);
}

void drawSphere(GLUquadric* quad, float radius){
    gluSphere(quad, radius, 32, 32);
}

void drawTeapot(){
    GLUquadric* quad = gluNewQuadric();

    // badan teko 
    glPushMatrix();
    glColor3f(0.8f, 0.4f, 0.2f);
    glScalef(1.2f, 0.8f, 1.2f);
    drawSphere(quad, 1.0f);
    glPopMatrix();

    // bagian bawah yang datar
    glPushMatrix();
    glTranslatef(0.0f, -0.8f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    glColor3f(0.5f, 0.3f, 0.1f);
    drawDisk(quad, 0.0f, 1.0f);
    glPopMatrix();

    // tutup teko kecil
    glPushMatrix();
    glColor3f(0.5f, 0.3f, 0.1f);
    glTranslatef(0.0f, 0.85f, 0.0f);
    drawSphere(quad, 0.2f);
    glPopMatrix();

    // gagang teko
    glPushMatrix();
    glColor3f(0.5f, 0.3f, 0.1f);
    glTranslatef(-1.25f, 0.0f, 0.0f);
    glRotatef(180, 0, 1, 0);
    for(int i = 0; i < 360; i += 5){
        glPushMatrix();
        glRotatef(i, 0, 0, 1);
        glTranslatef(0.35f, 0.0f, 0.0f);
        glRotatef(90, 1, 0, 0);
        drawCylinder(quad, 0.075f, 0.075f, 0.1f);
        glPopMatrix();
    }
    glPopMatrix();

    // corong untuk menuang
    glPushMatrix();
    glColor3f(0.5f, 0.3f, 0.1f);
    glTranslatef(1.0f, 0.3f, 0.0f);
    glRotatef(35, 0, 0, 1);
    glRotatef(90, 0, 1, 0);
    drawCylinder(quad, 0.15f, 0.06f, 0.6f);
    glPopMatrix();

    gluDeleteQuadric(quad);
}

void init(int width, int height){
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -6.0f);
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);

    drawTeapot();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(action == GLFW_PRESS || action == GLFW_REPEAT){
        switch (key){
            case GLFW_KEY_1: rotX += 5; break;
            case GLFW_KEY_2: rotX -= 5; break;
            case GLFW_KEY_3: rotY -= 5; break;
            case GLFW_KEY_4: rotY += 5; break;
            case GLFW_KEY_5: glfwSetWindowShouldClose(window, GLFW_TRUE); break;
        }
    }
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
    init(width, height);
}

int main(){
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Teapot", NULL, NULL);
    if(!window){
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    glfwSetKeyCallback(window, keyCallback);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    init(width, height);

    while(!glfwWindowShouldClose(window)){
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}