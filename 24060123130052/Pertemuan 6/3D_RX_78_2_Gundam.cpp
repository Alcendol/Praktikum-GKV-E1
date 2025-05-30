#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void DrawCube() {
    glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5, 0.5); 
    glVertex3f( 0.5, -0.5, 0.5);
    glVertex3f( 0.5,  0.5, 0.5);
    glVertex3f(-0.5,  0.5, 0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f(-0.5,  0.5, -0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5, -0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5,  0.5);
    glVertex3f(0.5,  0.5,  0.5);
    glVertex3f(0.5,  0.5, -0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5,  0.5,  0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f(-0.5,  0.5, -0.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
}


void drawGundamRX78() {
    // Badan atas
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glScalef(1.5f, 1.0f, 0.8f);
    DrawCube();
    glPopMatrix();

    // Badan bawah
    glPushMatrix();
    glTranslatef(0.0f, -0.8f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glScalef(1.3f, 0.8f, 0.5f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Kepala
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    GLUquadric* quad = gluNewQuadric();
    gluSphere(quad, 0.4f, 20, 20);
    gluDeleteQuadric(quad);
    glPopMatrix();

    // Antena Kiri
    glPushMatrix();
    glTranslatef(-0.3f, 1.8f, 0.3f);
    glRotatef(45, 0, 0, 1);
    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix();
    glScalef(0.05f, 0.7f, 0.05f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Antena Kanan
    glPushMatrix();
    glTranslatef(0.3f, 1.8f, 0.3);
    glRotatef(-45, 0, 0, 1);
    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix();
    glScalef(0.05f, 0.7f, 0.05f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Kotak Merah di Antara Antena
    glPushMatrix();
    glTranslatef(0.0f, 1.6f, 0.3f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glScalef(0.2f, 0.2f, 0.2f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Lengan Kiri
    glPushMatrix();
    glTranslatef(-1.0f, 0.3f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glScalef(0.4f, 1.5f, 0.4f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();

    // Lengan Kanan
    glPushMatrix();
    glTranslatef(1.0f, 0.3f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glScalef(0.4f, 1.5f, 0.4f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Tangan Kiri
    glPushMatrix();
    glTranslatef(-1.0f, -0.6f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    GLUquadric* handLeft = gluNewQuadric();
    gluSphere(handLeft, 0.25f, 16, 16);
    gluDeleteQuadric(handLeft);
    glPopMatrix();

    // Tangan Kanan
    glPushMatrix();
    glTranslatef(1.0f, -0.6f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    GLUquadric* handRight = gluNewQuadric();
    gluSphere(handRight, 0.25f, 16, 16);
    gluDeleteQuadric(handRight);
    glPopMatrix();

    // Shield
    glPushMatrix();
    glTranslatef(1.3f, 0.2f, 0.0f);
    glScalef(0.5f, 3.5f, 1.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    const float depth = 0.1f;
    const float radius = 0.5f;

    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++) {
        float angle = i * M_PI / 3.0f + M_PI / 6.0f;
        glVertex3f(depth, radius * cos(angle), radius * sin(angle));
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++) {
        float angle = i * M_PI / 3.0f + M_PI / 6.0f;
        glVertex3f(-depth, radius * cos(angle), radius * sin(angle));
    }
    glEnd();

    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++) {
        float angle1 = i * M_PI / 3.0f + M_PI / 6.0f;
        float angle2 = (i + 1) * M_PI / 3.0f + M_PI / 6.0f;

        float y1 = radius * cos(angle1);
        float z1 = radius * sin(angle1);
        float y2 = radius * cos(angle2);
        float z2 = radius * sin(angle2);

        glVertex3f(depth, y1, z1);
        glVertex3f(depth, y2, z2);
        glVertex3f(-depth, y2, z2);
        glVertex3f(-depth, y1, z1);
    }
    glEnd();
    
    // Ornamen
    glPushMatrix();
    glTranslatef(0.15f, -0.05f, 0.0f); 
    glColor3f(1.0f, 1.0f, 0.0f);
    glScalef(0.1f, 0.6f, 0.1f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();
    ;

    // Beam Saber
    glPushMatrix();
    glTranslatef(-1.0f, -0.6f, 0.0f);
    glRotatef(0, 0, 1, 0);

    //Beam Effect
    glColor3f(3.0f, 0.0f, 1.0f);
    GLUquadric* saber = gluNewQuadric();
    gluCylinder(saber, 0.09, 0.09, 2.5, 16, 16);

    // Handle
    glTranslatef(0.0f, 0.0f, -0.25f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluCylinder(saber, 0.1, 0.1, 0.7, 16, 16);
    gluDeleteQuadric(saber);
    glPopMatrix();

    // Pinggang
    glPushMatrix();
    glTranslatef(0.0f, -0.9f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glScalef(1.5f, 0.4f, 0.6f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Kaki Kiri
    glPushMatrix();
    glTranslatef(-0.5f, -1.8f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glScalef(0.5f, 1.5f, 0.5f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Kaki Kanan
    glPushMatrix();
    glTranslatef(0.5f, -1.8f, 0.0f);
    glPushMatrix();
    glScalef(0.5f, 1.5f, 0.5f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Telapak Kiri
    glPushMatrix();
    glTranslatef(-0.5f, -2.7f, 0.2f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glScalef(0.7f, 0.3f, 1.4f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();

    // Telapak Kanan
    glPushMatrix();
    glTranslatef(0.5f, -2.7f, 0.2f);
    glPushMatrix();
    glScalef(0.7f, 0.3f, 1.4f);
    DrawCube();
    glPopMatrix();
    glPopMatrix();
}

void setProjection(int mode, int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = width / (float)height;
    float scale = 3.0f;

    switch (mode) {
        // ORTHOGRAPHIC
        case 0: // Front
            if (aspect >= 1.0f)
                glOrtho(-scale * aspect, scale * aspect, -scale, scale, -10, 10);
            else
                glOrtho(-scale, scale, -scale / aspect, scale / aspect, -10, 10);
            gluLookAt(0, -1.0f, 5, 0, 0, 0, 0, 1, 0);  
            break;
        case 1: // Left Side
            if (aspect >= 1.0f)
                glOrtho(-scale * aspect, scale * aspect, -scale, scale, -10, 10);
            else
                glOrtho(-scale, scale, -scale / aspect, scale / aspect, -10, 10);
            gluLookAt(5, -1.0f, 0, 0, 0, 0, 0, 1, 0);
            break;
        
        case 2: // Right side
            if (aspect >= 1.0f)
                glOrtho(-scale * aspect, scale * aspect, -scale, scale, -10, 10);
            else
                glOrtho(-scale, scale, -scale / aspect, scale / aspect, -10, 10);
            gluLookAt(-5, -1.0f, 0, 0, 0, 0, 0, 1, 0);
            break;

        case 3: // Top
            if (aspect >= 1.0f)
                glOrtho(-scale * aspect, scale * aspect, -scale, scale, -10, 10);
            else
                glOrtho(-scale, scale, -scale / aspect, scale / aspect, -10, 10);
            gluLookAt(0, 5, 0, 0, 0, 0, 0, 0, -1);
            break;
        case 4: // Isometric
            if (aspect >= 1.0f)
                glOrtho(-scale * aspect, scale * aspect, -scale, scale, -10, 10);
            else
                glOrtho(-scale, scale, -scale / aspect, scale / aspect, -10, 10);
            gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
            break;
        case 5: // Dimetric
            if (aspect >= 1.0f)
                glOrtho(-scale * aspect, scale * aspect, -scale, scale, -10, 10);
            else
                glOrtho(-scale, scale, -scale / aspect, scale / aspect, -10, 10);
            gluLookAt(4, 2, 3, 0, 0, 0, 0, 1, 0);
            break;
        case 6: // Trimetric
            if (aspect >= 1.0f)
                glOrtho(-scale * aspect, scale * aspect, -scale, scale, -10, 10);
            else
                glOrtho(-scale, scale, -scale / aspect, scale / aspect, -10, 10);
            gluLookAt(4, 3, 2, 0, 0, 0, 0, 1, 0);
            break;

        // PERSPECTIVE
        case 7: // 1-point
            gluPerspective(60, aspect, 1, 100);
            gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
            break;
        case 8: // 2-point
            gluPerspective(60, aspect, 1, 100);
            gluLookAt(5, 0, 5, 0, 0, 0, 0, 1, 0);
            break;
        case 9: // 3-point
            gluPerspective(60, aspect, 1, 100);
            gluLookAt(4, 5, 4, 0, 0, 0, 0, 1, 0);
            break;

    }
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Gundam RX-78-2", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();
    glEnable(GL_DEPTH_TEST);

    int mode = 0;

    glEnable(GL_LIGHTING);                // Aktifkan sistem pencahayaan
    glEnable(GL_LIGHT0);                  // Gunakan LIGHT0

    GLfloat light_pos[] = { 2.0f, 5.0f, 5.0f, 1.0f };  // Posisi lampu (x, y, z, w)
    GLfloat light_amb[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // Cahaya ambient
    GLfloat light_dif[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Cahaya diffuse
    GLfloat light_spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // Cahaya specular

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_dif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_spe);

    glEnable(GL_COLOR_MATERIAL);  // Gunakan warna objek sebagai material
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_shininess[] = { 50.0f };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);



    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        setProjection(mode, width, height);

        drawGundamRX78();

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS) mode = 0;
        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) mode = 1;
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) mode = 2;
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) mode = 3;
        if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) mode = 4;
        if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) mode = 5;
        if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) mode = 6;
        if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS) mode = 7;
        if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS) mode = 8;
        if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS) mode = 9;
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}