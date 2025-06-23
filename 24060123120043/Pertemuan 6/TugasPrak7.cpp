/*
Nama : Sophie Venecia May M
Nim  : 24060123120043
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>  
#include <iostream>
#include <cstdlib>
#include "imageloader.h"

const float BOX_SIZE = 7.0f;
float angle = 0.0f;
GLuint textureId[6];

void handleKeypress(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLuint loadTexture(Image* image) {
    GLuint texId;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return texId;
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    const char* textureFiles[6] = {
        "front.bmp",
        "back.bmp",
        "top.bmp",
        "bottom.bmp",
        "left.bmp",
        "right.bmp"
    };

    for (int i = 0; i < 6; i++) {
        Image* image = loadBMP(textureFiles[i]);
        if (!image) {
            std::cerr << "Gagal memuat: " << textureFiles[i] << std::endl;
            exit(1); 
        }
        textureId[i] = loadTexture(image);
        delete image;
    }
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -20.0f);

    GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glRotatef(-angle, 1.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);
        // Atas
        glColor3f(1.0f, 1.0f, 0.0f); // Kuning
        glNormal3f(0.0, 1.0f, 0.0f);
        glVertex3f(-BOX_SIZE/2, BOX_SIZE/2, -BOX_SIZE/2);
        glVertex3f(-BOX_SIZE/2, BOX_SIZE/2,  BOX_SIZE/2);
        glVertex3f( BOX_SIZE/2, BOX_SIZE/2,  BOX_SIZE/2);
        glVertex3f( BOX_SIZE/2, BOX_SIZE/2, -BOX_SIZE/2);

        // Bawah
        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
        glNormal3f(0.0, -1.0f, 0.0f);
        glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
        glVertex3f( BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
        glVertex3f( BOX_SIZE/2, -BOX_SIZE/2,  BOX_SIZE/2);
        glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2,  BOX_SIZE/2);

        // Kiri
        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glNormal3f(-1.0, 0.0f, 0.0f);
        glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
        glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2,  BOX_SIZE/2);
        glVertex3f(-BOX_SIZE/2,  BOX_SIZE/2,  BOX_SIZE/2);
        glVertex3f(-BOX_SIZE/2,  BOX_SIZE/2, -BOX_SIZE/2);

        // Kanan
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glNormal3f(1.0, 0.0f, 0.0f);
        glVertex3f( BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
        glVertex3f( BOX_SIZE/2,  BOX_SIZE/2, -BOX_SIZE/2);
        glVertex3f( BOX_SIZE/2,  BOX_SIZE/2,  BOX_SIZE/2);
        glVertex3f( BOX_SIZE/2, -BOX_SIZE/2,  BOX_SIZE/2);
    glEnd();

    // Sisi depan & belakang dengan tekstur
    glEnable(GL_TEXTURE_2D);
    // Fix: Use a specific texture instead of the entire array
    glBindTexture(GL_TEXTURE_2D, textureId[0]); // Using the first texture
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
        // Depan
        glNormal3f(0.0, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2,  BOX_SIZE/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( BOX_SIZE/2, -BOX_SIZE/2,  BOX_SIZE/2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( BOX_SIZE/2,  BOX_SIZE/2,  BOX_SIZE/2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-BOX_SIZE/2,  BOX_SIZE/2,  BOX_SIZE/2);

        // Belakang
        glNormal3f(0.0, 0.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-BOX_SIZE/2,  BOX_SIZE/2, -BOX_SIZE/2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( BOX_SIZE/2,  BOX_SIZE/2, -BOX_SIZE/2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void drawTexturedCube() {
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); 

    // FRONT (+Z)
    glBindTexture(GL_TEXTURE_2D, textureId[0]);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0f, 1.0f);
    glTexCoord2f(0, 0); glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(1, 0); glVertex3f(BOX_SIZE/2, -BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(1, 1); glVertex3f(BOX_SIZE/2, BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(0, 1); glVertex3f(-BOX_SIZE/2, BOX_SIZE/2, BOX_SIZE/2);
    glEnd();

    // BACK (-Z)
    glBindTexture(GL_TEXTURE_2D, textureId[1]);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0f, -1.0f);
    glTexCoord2f(0, 0); glVertex3f(BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
    glTexCoord2f(1, 0); glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
    glTexCoord2f(1, 1); glVertex3f(-BOX_SIZE/2, BOX_SIZE/2, -BOX_SIZE/2);
    glTexCoord2f(0, 1); glVertex3f(BOX_SIZE/2, BOX_SIZE/2, -BOX_SIZE/2);
    glEnd();

    // TOP (+Y)
    glBindTexture(GL_TEXTURE_2D, textureId[2]);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0f, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(-BOX_SIZE/2, BOX_SIZE/2, -BOX_SIZE/2);
    glTexCoord2f(1, 0); glVertex3f(-BOX_SIZE/2, BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(1, 1); glVertex3f(BOX_SIZE/2, BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(0, 1); glVertex3f(BOX_SIZE/2, BOX_SIZE/2, -BOX_SIZE/2);
    glEnd();

    // BOTTOM (-Y)
    glBindTexture(GL_TEXTURE_2D, textureId[3]);
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0f, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
    glTexCoord2f(1, 0); glVertex3f(BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
    glTexCoord2f(1, 1); glVertex3f(BOX_SIZE/2, -BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(0, 1); glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, BOX_SIZE/2);
    glEnd();

    // LEFT (-X)
    glBindTexture(GL_TEXTURE_2D, textureId[4]);
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0f, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
    glTexCoord2f(1, 0); glVertex3f(-BOX_SIZE/2, -BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(1, 1); glVertex3f(-BOX_SIZE/2, BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(0, 1); glVertex3f(-BOX_SIZE/2, BOX_SIZE/2, -BOX_SIZE/2);
    glEnd();

    // RIGHT (+X)
    glBindTexture(GL_TEXTURE_2D, textureId[5]);
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0f, 0.0f);
    glTexCoord2f(0, 0); glVertex3f(BOX_SIZE/2, -BOX_SIZE/2, -BOX_SIZE/2);
    glTexCoord2f(1, 0); glVertex3f(BOX_SIZE/2, -BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(1, 1); glVertex3f(BOX_SIZE/2, BOX_SIZE/2, BOX_SIZE/2);
    glTexCoord2f(0, 1); glVertex3f(BOX_SIZE/2, BOX_SIZE/2, -BOX_SIZE/2);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return EXIT_FAILURE;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Texture Box", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return EXIT_FAILURE;
    }

    glfwSetKeyCallback(window, handleKeypress);

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 1.0, 200.0);

    initRendering();

    while (!glfwWindowShouldClose(window)) {
        angle += 0.2f;
        if (angle > 360) angle -= 360;
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -20.0f);
        
        // Pencahayaan
        GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

        GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
        GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        // Rotasi objek
        glRotatef(-angle, 1.0f, 1.0f, 0.0f);

        drawTexturedCube();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    for (int i = 0; i < 6; i++) {
        glDeleteTextures(1, &textureId[i]);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}