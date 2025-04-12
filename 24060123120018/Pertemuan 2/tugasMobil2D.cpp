#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void langit() {
    glBegin(GL_QUADS);
    glColor3f(0.529f, 0.808f, 0.922f); 
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.678f, 0.847f, 0.902f); 
    glVertex2f(1.0f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glEnd();
}

void matahari() {
    glColor3f(1.0f, 0.843f, 0.0f);
    const int circlePoints = 100;
    const float radius = 0.15f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Titik tengah
    for (int i = 0; i <= circlePoints; i++) {
        float angle = 2.0f * M_PI * i / circlePoints;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void sinarMatahari() {
    const float radius = 0.15f;
    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) {
        float angle = 2.0f * M_PI * i / 12;
        glVertex2f(0.0f, 0.0f);
        glVertex2f(radius * 1.5f * cos(angle), radius * 1.5f * sin(angle));
    }
    glEnd();
}

void laut() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.8f); 
    glVertex2f(-1.2f, -0.2f); 
    glVertex2f(1.2f, -0.2f);  
    glColor3f(0.0f, 0.4f, 0.7f); 
    glVertex2f(1.2f, -0.4f);  
    glVertex2f(-1.2f, -0.4f); 
    glEnd();
}

void jalan() {
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f); 
    glVertex2f(-1.2f, -0.4f);
    glVertex2f(1.2f, -0.4f);
    glVertex2f(1.2f, -0.7f);
    glVertex2f(-1.2f, -0.7f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); 
    
    for (float x = -0.9f; x < 1.0f; x += 0.3f) {
        glVertex2f(x, -0.54f);
        glVertex2f(x + 0.15f, -0.54f);
        glVertex2f(x + 0.15f, -0.56f);
        glVertex2f(x, -0.56f);
    }
    glEnd();
}

void rumput() {
    glBegin(GL_QUADS);
    glColor3f(0.133f, 0.545f, 0.133f); // Warna hijau
    glVertex2f(-1.2f, -0.7f);
    glVertex2f(1.2f, -0.7f);
    glVertex2f(1.2f, -1.0f);
    glVertex2f(-1.2f, -1.0f);
    glEnd();
    
    // Detil rumput
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.4f, 0.0f); // Warna hijau lebih gelap
    for (float x = -1.2f; x < 1.2f; x += 0.1f) {
        glVertex2f(x, -0.7f);
        glVertex2f(x + 0.05f, -0.75f);
        
        glVertex2f(x + 0.05f, -0.7f);
        glVertex2f(x, -0.75f);
    }
    glEnd();
}

void pohonKelapa(float x, float scale) {
    glPushMatrix();
    glTranslatef(x, -0.7f, 0.0f);
    glScalef(scale, scale, 1.0f);
    
    // Batang pohon
    glBegin(GL_QUADS);
    glColor3f(0.545f, 0.271f, 0.075f); // Warna coklat
    glVertex2f(-0.03f, 0.0f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.04f, 0.3f);
    glVertex2f(-0.04f, 0.3f);
    glEnd();
    
    // Daun pohon
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.0f); // Warna hijau
    
    // Daun kiri
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(-0.1f, 0.25f);
    
    // Daun kanan
    glVertex2f(0.0f, 0.3f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.1f, 0.25f);
    
    // Daun atas
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(0.1f, 0.5f);
    glEnd();
    
    glPopMatrix();
}

void mobil(float x, float y, float r, float g, float b, bool isRacing) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    
    // Badan mobil
    glBegin(GL_QUADS);
    glColor3f(r, g, b); // Warna mobil
    glVertex2f(-0.12f, -0.02f);
    glVertex2f(0.12f, -0.02f);
    glVertex2f(0.12f, 0.06f);
    glVertex2f(-0.12f, 0.06f);
    glEnd();
    
    // Atap mobil
    glBegin(GL_QUADS);
    glColor3f(r * 0.8f, g * 0.8f, b * 0.8f); // Warna sedikit lebih gelap
    glVertex2f(-0.08f, 0.06f);
    glVertex2f(0.08f, 0.06f);
    glVertex2f(0.06f, 0.12f);
    glVertex2f(-0.06f, 0.12f);
    glEnd();
    
    // Kaca depan
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 0.7f); // Warna abu-abu
    glVertex2f(-0.055f, 0.06f);
    glVertex2f(0.055f, 0.06f);
    glVertex2f(0.04f, 0.11f);
    glVertex2f(-0.04f, 0.11f);
    glEnd();
    
    // Roda depan
    glPushMatrix();
    glTranslatef(-0.08f, -0.02f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f); // Warna hitam
    const int wheelPoints = 20;
    const float wheelRadius = 0.03f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Titik tengah
    for (int i = 0; i <= wheelPoints; i++) {
        float angle = 2.0f * M_PI * i / wheelPoints;
        glVertex2f(wheelRadius * cos(angle), wheelRadius * sin(angle));
    }
    glEnd();
    glPopMatrix();
    
    // Roda belakang
    glPushMatrix();
    glTranslatef(0.08f, -0.02f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f); // Warna hitam
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Titik tengah
    for (int i = 0; i <= wheelPoints; i++) {
        float angle = 2.0f * M_PI * i / wheelPoints;
        glVertex2f(wheelRadius * cos(angle), wheelRadius * sin(angle));
    }
    glEnd();
    glPopMatrix();
    
    
    // Api dari knalpot jika mobil sedang racing
    if (isRacing) {
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Merah
        glVertex2f(-0.12f, 0.0f);
        glColor3f(1.0f, 0.5f, 0.0f); // Oranye
        glVertex2f(-0.2f, 0.02f);
        glColor3f(1.0f, 1.0f, 0.0f); // Kuning
        glVertex2f(-0.2f, -0.02f);
        glEnd();
    }
    
    glPopMatrix();
}



void gabungan() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    langit();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f, 0.7f, 0.0f);
    matahari();
    sinarMatahari();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.1f, -0.00f, 0.0f);
    laut();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1f, -0.00f, 0.0f);
    jalan();
    rumput();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1f, -0.1f, 0.0f);
    pohonKelapa(-0.9, 1.0);
    pohonKelapa(1.1, 1.0);
    glPopMatrix();

    glPushMatrix();
  mobil(0.0f, -0.5f, 1.0f, 0.0f, 0.0f, true); // Mobil merah dengan api
  mobil(0.3f, -0.5f, 0.0f, 0.0f, 1.0f, false); // Mobil biru tanpa api
    glPopMatrix();
}



int main() {
    if (!glfwInit()) {
    return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Rectangle", NULL, NULL);
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
        glClear(GL_COLOR_BUFFER_BIT);
        gabungan();

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

