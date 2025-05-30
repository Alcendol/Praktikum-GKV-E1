#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void gambarLingkaran(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void roda() {
    glColor3f(0.0f, 0.0f, 0.0f);
    gambarLingkaran(0.07f, 20);
    
    glColor3f(0.5f, 0.5f, 0.5f);
    gambarLingkaran(0.04f, 20);
}

void badanMobil() {
    glColor3f(0.0f, 0.6f, 0.0f);  // Warna hijau seperti mobil Mr. Bean
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, 0.1f);
    glVertex2f(-0.3f, 0.1f);
    glEnd();
    
    glColor3f(0.0f, 0.5f, 0.0f);  // Warna hijau tua untuk atap
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.1f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();
    
    // Kaca jendela biru
    glColor3f(0.1f, 0.3f, 0.8f);  // Warna biru untuk kaca
    glBegin(GL_QUADS);
    glVertex2f(-0.18f, 0.12f);
    glVertex2f(0.08f, 0.12f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(-0.18f, 0.18f);
    glEnd();
    
    // Kaca depan biru
    glColor3f(0.1f, 0.3f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.1f, 0.18f);
    glVertex2f(0.05f, 0.18f);
    glVertex2f(0.05f, 0.1f);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.28f, 0.02f);
    glVertex2f(0.3f, 0.02f);
    glVertex2f(0.3f, 0.08f);
    glVertex2f(0.28f, 0.08f);
    glEnd();
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.28f, 0.02f);
    glVertex2f(-0.3f, 0.02f);
    glVertex2f(-0.3f, 0.08f);
    glVertex2f(-0.28f, 0.08f);
    glEnd();
}

void jalan() {
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.11f);
    glVertex2f(-0.6f, -0.11f);
    glVertex2f(-0.6f, -0.09f);
    glVertex2f(-0.8f, -0.09f);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.11f);
    glVertex2f(-0.2f, -0.11f);
    glVertex2f(-0.2f, -0.09f);
    glVertex2f(-0.4f, -0.09f);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(0.0f, -0.11f);
    glVertex2f(0.2f, -0.11f);
    glVertex2f(0.2f, -0.09f);
    glVertex2f(0.0f, -0.09f);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.11f);
    glVertex2f(0.6f, -0.11f);
    glVertex2f(0.6f, -0.09f);
    glVertex2f(0.4f, -0.09f);
    glEnd();
}

void rumput() {
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glEnd();
}

void langit() {
    glColor3f(0.5f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void matahari() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= 36; i++) {
        float angle = 2.0f * M_PI * i / 36;
        glVertex2f(0.1f * cos(angle), 0.1f * sin(angle));
    }
    glEnd();
}

void awan() {
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_QUADS);
    glVertex2f(-0.15f, -0.05f);
    glVertex2f(0.15f, -0.05f);
    glVertex2f(0.15f, 0.05f);
    glVertex2f(-0.15f, 0.05f);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, 0.05f);
    glVertex2f(0.1f, 0.05f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
}

void pohon() {
    glColor3f(0.5f, 0.25f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.2f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.05f, 0.1f);
    glVertex2f(-0.05f, 0.1f);
    glEnd();
    
    glColor3f(0.0f, 0.4f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.15f, 0.1f);
    glVertex2f(0.15f, 0.1f);
    glVertex2f(0.15f, 0.3f);
    glVertex2f(-0.15f, 0.3f);
    glEnd();
}

void renderAdegan() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    langit();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.7f, 0.7f, 0.0f);
    matahari();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.4f, 0.6f, 0.0f);
    awan();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.5f, 0.5f, 0.0f);
    awan();
    glPopMatrix();
    
    glPushMatrix();
    rumput();
    glPopMatrix();
    
    glPushMatrix();
    jalan();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.6f, 0.0f, 0.0f);
    pohon();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.6f, 0.0f, 0.0f);
    pohon();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, -0.1f, 0.0f);
    badanMobil();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.2f, -0.1f, 0.0f);
    roda();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.2f, -0.1f, 0.0f);
    roda();
    glPopMatrix();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Mobil 2D Mr. Bean", NULL, NULL);
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
        renderAdegan();
        
        glfwSwapBuffers(window);
        
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}