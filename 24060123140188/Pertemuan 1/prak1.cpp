//Nama: Retno Eka Triatry
//Nim: 24060123140188
//Tanggal: 11 Maret 2025

//no. 1 Titik dan Garis
#include <GLUT/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Titik
    glPointSize(10);
    glBegin(GL_POINTS);
        glColor3f(1, 0, 0);
        glVertex2f(-0.5f, 0.5f);
    glEnd();

    // Garis
    glLineWidth(3);
    glBegin(GL_LINES);
        glColor3f(0, 1, 0);
        glVertex2f(-0.7f, -0.2f);
        glVertex2f(0.7f, -0.2f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Titik dan Garis");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//no. 2 Memanfaatkan Fungsi Primitif
#include <GLUT/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // GL_LINE_STRIP
    glBegin(GL_LINE_STRIP);
        glColor3f(1, 0, 0); glVertex2f(-0.9f, 0.9f);
        glColor3f(0, 1, 0); glVertex2f(-0.7f, 0.7f);
        glColor3f(0, 0, 1); glVertex2f(-0.5f, 0.9f);
    glEnd();

    // GL_LINE_LOOP
    glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2f(-0.4f, 0.7f);
        glVertex2f(-0.2f, 0.9f);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(-0.3f, 0.6f);
    glEnd();

    // GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1, 1, 0);
        glVertex2f(0.3f, 0.8f); // Titik pusat
        glVertex2f(0.2f, 0.9f);
        glVertex2f(0.4f, 0.9f);
        glVertex2f(0.5f, 0.7f);
        glVertex2f(0.3f, 0.6f);
        glVertex2f(0.2f, 0.7f);
        glVertex2f(0.2f, 0.9f); // Tutup
    glEnd();

    // GL_TRIANGLE_STRIP
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1, 0, 1);
        glVertex2f(-0.9f, 0.4f);
        glVertex2f(-0.8f, 0.3f);
        glVertex2f(-0.7f, 0.4f);
        glVertex2f(-0.6f, 0.3f);
        glVertex2f(-0.5f, 0.4f);
    glEnd();

     GL_QUADS
    glBegin(GL_QUADS);
        glColor3f(0, 1, 1);
        glVertex2f(-0.4f, 0.4f);
        glVertex2f(-0.2f, 0.4f);
        glVertex2f(-0.2f, 0.2f);
        glVertex2f(-0.4f, 0.2f);
    glEnd();

    // GL_QUAD_STRIP
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.5f, 0.2f, 0.8f);
        glVertex2f(0.2f, 0.4f); glVertex2f(0.2f, 0.2f);
        glVertex2f(0.4f, 0.4f); glVertex2f(0.4f, 0.2f);
        glVertex2f(0.6f, 0.4f); glVertex2f(0.6f, 0.2f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Primitive Shapes");
    glClearColor(1, 1, 1, 1); // White background
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//no. 3
#include <GLUT/glut.h>

void drawCube(float x, float y, float size) {
    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.6f, 1.0f);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float size = 0.2f;
    // Baris bawah (3 kubus)
    drawCube(-0.6f, -0.6f, size);
    drawCube(-0.3f, -0.6f, size);
    drawCube(0.0f, -0.6f, size);

    // Baris tengah (2 kubus)
    drawCube(-0.45f, -0.35f, size);
    drawCube(-0.15f, -0.35f, size);

    // Atas (1 kubus)
    drawCube(-0.3f, -0.1f, size);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Kubus Bertingkat");
    glClearColor(1, 1, 1, 1); // putih
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
