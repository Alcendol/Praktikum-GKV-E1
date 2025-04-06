//Nama: Retno Eka Triatry
//Nim: 24060123140188
//Tanggal: 16 Maret 2025

//no. 1 lingkaran
#include <GLUT/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.75f, 0.8f); // Pink muda

    float radius = 0.5f;
    int triangleAmount = 100;
    float twicePi = 2.0f * 3.14159f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // center
    for(int i = 0; i <= triangleAmount; i++) {
        glVertex2f(radius * cos(i * twicePi / triangleAmount),
                   radius * sin(i * twicePi / triangleAmount));
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lingkaran Pink Muda");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//no. 2 mobil
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>

// Gambar lingkaran
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

// Awan
void drawCloud(float x, float y) {
    glColor3f(1, 1, 1);
    drawCircle(x, y, 0.07f);
    drawCircle(x + 0.06f, y + 0.03f, 0.06f);
    drawCircle(x + 0.12f, y, 0.07f);
    drawCircle(x + 0.06f, y - 0.03f, 0.05f);
}

// Burung besar
void drawBird(float x, float y) {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x - 0.05f, y + 0.025f);
    glVertex2f(x, y);
    glVertex2f(x, y);
    glVertex2f(x + 0.05f, y + 0.025f);
    glEnd();
}

// Pohon kelapa
void drawTree(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);

    // Batang
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(-0.01f, 0.0f);
    glVertex2f(0.01f, 0.0f);
    glVertex2f(0.01f, 0.2f);
    glVertex2f(-0.01f, 0.2f);
    glEnd();

    // Daun
    glColor3f(0.0f, 0.6f, 0.0f);
    for (int i = 0; i < 5; ++i) {
        float angle = i * 72.0f * 3.14f / 180.0f;
        float dx = 0.1f * cos(angle);
        float dy = 0.1f * sin(angle);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(dx, 0.2f + dy);
        glVertex2f(-dx, 0.2f + dy);
        glEnd();
    }

    glPopMatrix();
}

// Mobil
void drawCar(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);

    // Badan mobil
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(0.6f, 0.1f);
    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.0f, 0.2f);
    glEnd();

    // Atap
    glBegin(GL_QUADS);
    glVertex2f(0.15f, 0.2f);
    glVertex2f(0.45f, 0.2f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.2f, 0.3f);
    glEnd();

    // Jendela
    glColor3f(0.8f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.22f, 0.21f);
    glVertex2f(0.38f, 0.21f);
    glVertex2f(0.35f, 0.28f);
    glVertex2f(0.25f, 0.28f);
    glEnd();

    // Lampu
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.6f, 0.15f, 0.015f);

    // Roda kiri
    glColor3f(0, 0, 0); drawCircle(0.15f, 0.1f, 0.05f);
    glColor3f(1, 1, 1); drawCircle(0.15f, 0.1f, 0.025f);

    // Roda kanan
    glColor3f(0, 0, 0); drawCircle(0.45f, 0.1f, 0.05f);
    glColor3f(1, 1, 1); drawCircle(0.45f, 0.1f, 0.025f);

    glPopMatrix();
}

// Tampilan utama
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Langit
    glColor3f(0.53f, 0.81f, 0.98f);
    glBegin(GL_QUADS);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

    // Matahari (kiri atas)
    glColor3f(1.0f, 0.84f, 0.0f);
    drawCircle(-0.85f, 0.85f, 0.1f);

    // Laut
    glColor3f(0.2f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1, -0.2f);
    glVertex2f(1, -0.2f);
    glVertex2f(1, 0);
    glVertex2f(-1, 0);
    glEnd();

    // Pasir
    glColor3f(0.96f, 0.87f, 0.70f);
    glBegin(GL_QUADS);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.2f);
    glVertex2f(-1, -0.2f);
    glEnd();

    // Pohon kelapa (4 buah)
    drawTree(-0.8f, -0.2f);
    drawTree(-0.4f, -0.2f);
    drawTree(0.3f, -0.2f);
    drawTree(0.7f, -0.2f);

    // Mobil
    drawCar(-0.3f, -0.5f);

    // Awan
    drawCloud(-0.6f, 0.7f);
    drawCloud(0.0f, 0.8f);
    drawCloud(0.5f, 0.65f);

    // Burung besar
    drawBird(-0.2f, 0.6f);
    drawBird(0.2f, 0.65f);
    drawBird(0.6f, 0.75f);

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // background putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil Porsche di Pantai");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
