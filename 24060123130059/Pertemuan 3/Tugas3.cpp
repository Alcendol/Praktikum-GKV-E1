#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

void circle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void roda(float cx, float cy, float r) {
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    glRotatef(0, 0, 0, 1);
    glTranslatef(-cx, -cy, 0);
    
    glColor3f(0, 0, 0);
    circle(cx, cy, r, 30);
    
    glColor3f(1, 1, 1); 
    circle(cx, cy, r * 0.5f, 30);
    
    glPopMatrix();
}

void mobil() {
    glColor3f(0.95f, 0.95f, 0.95f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, -0.1f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.6f, 0.2f);
    glVertex2f(-0.6f, 0.2f);
    glEnd();

    glLineWidth(0.2f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, -0.1f);
    glVertex2f(0.0f, 0.2f);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(-0.3f, 0.4f);
    glEnd();
    
    roda(-0.4f, -0.1f, 0.1f);
    roda(0.4f, -0.1f, 0.1f);

    glColor3f(1, 1, 0); 
    glBegin(GL_POLYGON);
    glVertex2f(0.55f, 0.05f);
    glVertex2f(0.6f, 0.05f);
    glVertex2f(0.6f, 0.15f);
    glVertex2f(0.55f, 0.15f);
    glEnd();
    
    glColor3f(1, 0, 0); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, 0.05f);
    glVertex2f(-0.55f, 0.05f);
    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.6f, 0.15f);
    glEnd();
}

void gunung() {
    glColor3f(0.0f, 0.6f, 0.0f); 
    glBegin(GL_POLYGON); 
    glVertex2f(-1.0f, 0.0f);  
    glVertex2f(-0.6f, 0.7f);  
    glVertex2f(-0.4f, 0.4f);  
    glVertex2f(-0.1f, 0.65f); 
    glVertex2f(0.2f, 0.35f);  
    glVertex2f(0.5f, 0.5f);   
    glVertex2f(0.7f, 0.3f);   
    glVertex2f(1.0f, 0.0f); 
    glEnd();
}

void jalan() {
    glColor3f(0.3f, 0.3f, 0.3f); 
    glBegin(GL_QUADS);
    glVertex2f(-1, 0.0f);
    glVertex2f(1, 0.f);
    glVertex2f(1, -0.6f);
    glVertex2f(-1, -0.6f);
    glEnd();
}

void markaJalan() {
    glColor3f(1,1,1); 
    for (float x = -0.9f; x <= 0.8f; x += 0.4f) { 
        glBegin(GL_QUADS);
        glVertex2f(x, -0.2f);
        glVertex2f(x + 0.2f, -0.2f);
        glVertex2f(x + 0.2f, -0.3f);
        glVertex2f(x, -0.3f);
        glEnd();
    }
}

void rumput(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(2.5f, 2.5f, 2.0f); 
    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.02f, 0.0f);
    glVertex2f(0.02f, 0.0f);
    glVertex2f(0.0f, 0.05f);
    glEnd();
    glPopMatrix();
}

void batu(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(2.5f, 2.5f, 2.0f); 
    glColor3f(0.5f, 0.5f, 0.5f);
    circle(0.0f, 0.0f, 0.03f, 20);
    glPopMatrix();
}

void tanah() {
    glColor3f(0.55f, 0.27f, 0.07f); 
    glBegin(GL_QUADS);
    glVertex2f(-1, -0.6f);
    glVertex2f(1, -0.6f);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glEnd();

    for (float x = -0.9f; x < 1.0f; x += 0.15f) {
        rumput(x, -0.7f);
    }

    for (float x = -0.9f; x < 1.0f; x += 0.2f) {
        batu(x, -0.85f);
    }
}

void awan(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);      
    glScalef(scale, scale, 1.0f); 
    glColor3f(1.0f, 1.0f, 1.0f); 

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); 
    for (int i = 0; i <= 360; i += 10) {
        float theta = i * 3.14159f / 180.0f; 
        glVertex2f(0.2f * cos(theta), 0.2f * sin(theta));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.15f, 0.1f); 
    for (int i = 0; i <= 360; i += 10) {
        float theta = i * 3.14159f / 180.0f; 
        glVertex2f(-0.15f + 0.15f * cos(theta), 0.1f + 0.15f * sin(theta));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.15f, 0.1f); 
    for (int i = 0; i <= 360; i += 10) {
        float theta = i * 3.14159f / 180.0f; 
        glVertex2f(0.15f + 0.15f * cos(theta), 0.1f + 0.15f * sin(theta));
    }
    glEnd();

    glPopMatrix();
}

void background() {
    glColor3f(0.53f, 0.81f, 0.98f); 
    glBegin(GL_QUADS);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, -0.3f);
    glVertex2f(-1, -0.3f);
    glEnd();
    
    glColor3f(1, 1, 0); 
    circle(0.7f, 0.7f, 0.1f, 30);

    awan(-0.6f, 0.8f, 1.5f);  
    awan(0.4f, 0.85f, 1.2f);  
    
    gunung();
    jalan();
    markaJalan();
    tanah();
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    background();
    mobil();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Mobil", NULL,NULL);
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
        display();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}