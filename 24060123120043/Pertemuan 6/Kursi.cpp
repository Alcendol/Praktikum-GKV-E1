// Nama : Sophie Venecia May M
// Nim  : 24060123120043

#define GLFW_INCLUDE_NONE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

// Variabel posisi box dan kamera
float boxPosX = 0.0f, boxPosY = 0.0f, boxPosZ = 0.0f;
float camAngle = 0.0f;
float camDistance = 5.0f;
float camHeight = 2.0f;

// Variabel pencahayaan
const GLfloat light_ambient[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

// Mengatur perspektif dan posisi kamera
void setupCamera(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / (float)height, 0.1, 100.0);

    float camX = boxPosX + sinf(camAngle) * camDistance;
    float camY = boxPosY + camHeight;
    float camZ = boxPosZ + cosf(camAngle) * camDistance;

    gluLookAt(camX, camY, camZ,
              boxPosX, boxPosY, boxPosZ,
              0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Menampilkan grid lantai
void Grid() {
    const float size = 50.0f;
    const float gap = 1.5f;
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
    for (float i = -size; i <= size; i += gap) {
        glVertex3f(-size, 0.0f, i);
        glVertex3f(size, 0.0f, i);
        glVertex3f(i, 0.0f, -size);
        glVertex3f(i, 0.0f, size);
    }
    glEnd();
}

// Menggambar kotak 3D (digunakan untuk bagian-bagian kursi)
void drawBox(float width, float height, float depth) {
    float x = width / 2.0f;
    float y = height / 2.0f;
    float z = depth / 2.0f;

    glBegin(GL_QUADS);
    // Depan
    glVertex3f(-x, -y,  z); glVertex3f( x, -y,  z);
    glVertex3f( x,  y,  z); glVertex3f(-x,  y,  z);
    // Belakang
    glVertex3f( x, -y, -z); glVertex3f(-x, -y, -z);
    glVertex3f(-x,  y, -z); glVertex3f( x,  y, -z);
    // Kiri
    glVertex3f(-x, -y, -z); glVertex3f(-x, -y,  z);
    glVertex3f(-x,  y,  z); glVertex3f(-x,  y, -z);
    // Kanan
    glVertex3f( x, -y,  z); glVertex3f( x, -y, -z);
    glVertex3f( x,  y, -z); glVertex3f( x,  y,  z);
    // Atas
    glVertex3f(-x,  y,  z); glVertex3f( x,  y,  z);
    glVertex3f( x,  y, -z); glVertex3f(-x,  y, -z);
    // Bawah
    glVertex3f(-x, -y, -z); glVertex3f( x, -y, -z);
    glVertex3f( x, -y,  z); glVertex3f(-x, -y,  z);
    glEnd();
}

// Menggambar kursi 3D
void drawChair() {
    glPushMatrix();

    const float seatWidth = 1.2f;
    const float seatDepth = 1.0f;
    const float seatHeight = 0.1f;
    const float legHeight = 1.0f;
    const float legThickness = 0.1f;
    const float backHeight = 1.2f;
    const float backBarHeight = 0.1f;
    const float backBarSpacing = 0.25f;

    // Dudukan kursi
    glColor3f(0.7f, 0.4f, 0.2f);
    glPushMatrix();
    glTranslatef(0.0f, legHeight, 0.0f);
    drawBox(seatWidth, seatHeight, seatDepth);
    glPopMatrix();

    // Kaki kursi
    float offsetX = seatWidth / 2 - legThickness / 2;
    float offsetZ = seatDepth / 2 - legThickness / 2;
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            glPushMatrix();
            glTranslatef(i * offsetX, legHeight / 2, j * offsetZ);
            glRotatef(i * 5.0f, 0.0f, 0.0f, 1.0f);
            drawBox(legThickness, legHeight, legThickness);
            glPopMatrix();
        }
    }

    // Sisi sandaran kiri dan kanan
    glColor3f(0.4f, 0.2f, 0.1f);
    float backY = legHeight + seatHeight / 2 + backHeight / 2;
    float backZ = -seatDepth / 2 + 0.05f;
    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * (seatWidth / 2 - legThickness / 2), backY, backZ);
        drawBox(legThickness, backHeight, legThickness);
        glPopMatrix();
    }

    // Bilah horizontal sandaran
    glColor3f(0.6f, 0.3f, 0.1f);
    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        float y = legHeight + seatHeight + i * backBarSpacing + backBarHeight / 2;
        glTranslatef(0.0f, y, backZ);
        drawBox(seatWidth - 0.2f, backBarHeight, 0.05f);
        glPopMatrix();
    }

    glPopMatrix();
}

// Mengatur pencahayaan
void lighting() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

// Callback saat ukuran layar berubah
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    setupCamera(width, height);
}

// Mengatur input dari keyboard
void processInput(GLFWwindow* window) {
    float moveSpeed = 0.1f;
    float rotateSpeed = 0.05f;

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        boxPosX -= sinf(camAngle) * moveSpeed;
        boxPosZ -= cosf(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        boxPosX += sinf(camAngle) * moveSpeed;
        boxPosZ += cosf(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        boxPosX -= cosf(camAngle) * moveSpeed;
        boxPosZ += sinf(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        boxPosX += cosf(camAngle) * moveSpeed;
        boxPosZ -= sinf(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        camAngle -= rotateSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        camAngle += rotateSpeed;
    }
}

// Fungsi utama
int main() {
    if (!glfwInit()) {
        fprintf(stderr, "GLFW gagal diinisialisasi\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Chair Scene", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "GLEW gagal diinisialisasi\n");
        return -1;
    }

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        setupCamera(800, 600);
        lighting();
        Grid();
        drawChair();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
