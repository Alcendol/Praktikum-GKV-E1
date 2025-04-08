/* Nama : Sophie Venecia May M
   Nim  : 24060123120043
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>
#include <math.h>

// Variabel rotasi
float rotX = 0.0f; // Pitch
float rotY = 0.0f; // Yaw
float rotZ = 0.0f; // Roll

// Fungsi bantu untuk gambar lingkaran
void drawCircle(float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, 0.0f, 0.0f); // Titik tengah
        for (int i = 0; i <= 32; i++) {
            float angle = 2.0f * 3.14159f * i / 32;
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glVertex3f(x, y, 0.0f);
        }
    glEnd();
}

// Fungsi menggambar roket
void drawRocket() {
    GLUquadric* quad = gluNewQuadric();

    // Badan Roket
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0); // Merah
        gluCylinder(quad, 0.3, 0.3, 1.5, 32, 32);
    glPopMatrix();

    // Kepala Roket
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 1.5f);
        glColor3f(1.0, 0.0, 0.0); // Merah
        gluCylinder(quad, 0.3, 0.0, 0.6, 32, 32);
    glPopMatrix();

    // Jendela 1 (bawah)
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, 0.8f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        // Outline kuning
        drawCircle(0.14f, 1.0f, 1.0f, 0.0f);
        // Isi putih
        drawCircle(0.12f, 1.0f, 1.0f, 1.0f);
    glPopMatrix();

    // Jendela 2 (atas, dinaikin biar ga nabrak cincin)
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, 1.3f); // <- sebelumnya 1.1, dinaikin jadi 1.3
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        // Outline kuning
        drawCircle(0.14f, 1.0f, 1.0f, 0.0f);
        // Isi putih
        drawCircle(0.12f, 1.0f, 1.0f, 1.0f);
    glPopMatrix();

    // Sayap Roket
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
            glRotatef(i * 120.0, 0, 0, 1);
            glTranslatef(0.28, 0.0f, 0.2);
            glColor3f(1.0, 0.0, 0.0); // Merah
            glBegin(GL_POLYGON);
                glVertex3f(0.0f, 0.0f, 0.0f);
                glVertex3f(0.0f, 0.0f, -0.6f);
                glVertex3f(0.2f, 0.0f, -0.5f);
                glVertex3f(0.2f, 0.0f, -0.1f);
            glEnd();
        glPopMatrix();
    }

    // Api Roket
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, -0.3f);
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(-0.15f, 0.0f, -0.5f);
            glVertex3f(0.15f, 0.0f, -0.5f);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, -0.1f);
            glVertex3f(-0.1f, 0.0f, -0.6f);
            glVertex3f(0.1f, 0.0f, -0.6f);
        glEnd();
    glPopMatrix();

    // Asap Roket
    glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f); // Abu-abu
        for (int i = 0; i < 3; i++) {
            glPushMatrix();
                glTranslatef((i - 1) * 0.25f, 0.0f, -0.9f);
                gluDisk(quad, 0.0, 0.15 + (i * 0.05f), 32, 1);
            glPopMatrix();
        }
    glPopMatrix();

    // Cincin Horizontal
    float ringZ[] = {0.5f, 1.0f, 1.48f};
    for (int i = 0; i < 3; ++i) {
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, ringZ[i]);
            glColor3f(1.0f, 1.0f, 1.0f); // Putih
            gluCylinder(quad, 0.31, 0.31, 0.02, 32, 1);
        glPopMatrix();
    }

    gluDeleteQuadric(quad);
}


// Inisialisasi tampilan
void init(int width, int height) {
    glClearColor(1, 1, 1, 1);
    glClearDepth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)width / (float)height;
    glFrustum(-aspect, aspect, -1.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -6.0f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

// Tampilan frame
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(rotX, 1.0f, 0.0f, 0.0f); // Pitch
        glRotatef(rotY, 0.0f, 1.0f, 0.0f); // Yaw
        glRotatef(rotZ, 0.0f, 0.0f, 1.0f); // Roll
        drawRocket();
    glPopMatrix();
}

// Callback ukuran layar
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    init(width, height);
}

// Kontrol input keyboard
void processInput(GLFWwindow* window) {
    float rotationSpeed = 1.0f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) rotX -= rotationSpeed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) rotX += rotationSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) rotY -= rotationSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) rotY += rotationSpeed;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) rotZ -= rotationSpeed;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) rotZ += rotationSpeed;
}

// Fungsi utama
int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Roket Merah dengan Asap", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewInit();

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    init(width, height);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
