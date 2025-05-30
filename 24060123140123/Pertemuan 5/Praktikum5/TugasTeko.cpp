#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double rotAngle = 90;  // Arahkan cerat ke kanan
double rotAngle1 = 0;

void drawTeapotBody(float size) {
    float radius = size * 0.7f;  // Radius diperbesar agar bentuk lebih bulat
    int slices = 64;
    int stacks = 32;

    glColor3f(1.0f, 0.0f, 0.0f);

    for (int i = 0; i < slices; i++) {
        float theta1 = i * 2.0f * M_PI / slices;
        float theta2 = (i + 1) * 2.0f * M_PI / slices;

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= stacks; j++) {
            float phi = j * M_PI / stacks;
            float scaleY = 0.6f;  // Skala Y dikurangi agar bentuk lebih pendek
            float x1 = radius * sin(phi) * cos(theta1);
            float y1 = (radius * cos(phi) - size * 0.3f) * scaleY;  // Offset disesuaikan
            float z1 = radius * sin(phi) * sin(theta1);

            float x2 = radius * sin(phi) * cos(theta2);
            float y2 = (radius * cos(phi) - size * 0.3f) * scaleY;
            float z2 = radius * sin(phi) * sin(theta2);

            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }
}

void drawTeapotHandle(float size) {
    int segments = 32;
    float tubeRadius = size * 0.08f;  // Ketebalan ditambah agar sesuai gambar
    float curveRadius = size * 0.4f;  // Jari-jari lengkungan disesuaikan

    glColor3f(1.0f, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(-size * 0.6f, 0.0f, 0.0f);  // Posisikan pegangan di sebelah kiri

    for (int i = 0; i <= segments; i++) {
        float t = (float)i / segments;
        float theta1 = M_PI * t;  // Lengkungan dari 0 sampai 180 derajat
        float theta2 = M_PI * (t + 1.0f / segments);

        float cx1 = curveRadius * (1.0f + 0.5f * sin(theta1));  // Tonjolan keluar
        float cy1 = curveRadius * cos(theta1);
        float cx2 = curveRadius * (1.0f + 0.5f * sin(theta2));
        float cy2 = curveRadius * cos(theta2);

        // Sesuaikan titik sambungan
        if (i == 0) {
            cy1 = size * 0.15f;  // Titik sambungan atas
            cx1 = curveRadius * 0.2f;
        }
        if (i == segments) {
            cy2 = -size * 0.35f;  // Titik sambungan bawah
            cx2 = curveRadius * 0.2f;
        }

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= segments; ++j) {
            float angle = 2.0f * M_PI * j / segments;
            float x1 = tubeRadius * cos(angle);
            float z1 = tubeRadius * sin(angle);
            glVertex3f(cx1 + x1, cy1, z1);
            glVertex3f(cx2 + x1, cy2, z1);
        }
        glEnd();
    }
    glPopMatrix();
}

void drawTeapotSpout(float size) {
    int segments = 32;
    float tubeRadius = size * 0.08f;  // Ketebalan ditambah agar sesuai gambar
    float length = size * 0.9f;       // Panjang cerat

    glColor3f(1.0f, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(size * 0.5f, size * 0.05f, 0.0f);  // Posisikan cerat di sebelah kanan

    for (int i = 0; i < segments; ++i) {
        float t1 = (float)i / segments;
        float t2 = (float)(i + 1) / segments;

        float x1 = length * t1;
        float y1 = size * 0.5f * pow(t1, 0.8f);  // Lengkungan ke atas yang halus
        float x2 = length * t2;
        float y2 = size * 0.5f * pow(t2, 0.8f);

        // Ujung sedikit mengecil
        float radius1 = tubeRadius * (1.0f - 0.3f * t1);
        float radius2 = tubeRadius * (1.0f - 0.3f * t2);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= segments; ++j) {
            float angle = 2.0f * M_PI * j / segments;
            float dx1 = radius1 * cos(angle);
            float dz1 = radius1 * sin(angle);
            float dx2 = radius2 * cos(angle);
            float dz2 = radius2 * sin(angle);
            glVertex3f(x1, y1 + dx1, dz1);
            glVertex3f(x2, y2 + dx2, dz2);
        }
        glEnd();
    }

    glPopMatrix();
}

void drawTeapotLid(float size) {
    float lidRadius = size * 0.1f;   // Tutup yang lebih kecil
    float lidHeight = size * 0.02f;  // Tutup yang lebih datar
    int slices = 32;
    int stacks = 16;

    glColor3f(1.0f, 0.0f, 0.0f);

    // Gambar tutup sebagai cakram agak cembung
    for (int i = 0; i < slices; i++) {
        float theta1 = i * 2.0f * M_PI / slices;
        float theta2 = (i + 1) * 2.0f * M_PI / slices;

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= stacks; j++) {
            float phi = j * M_PI / (2 * stacks);
            float dome = 0.5f * (1.0f - cos(phi));  // Efek kubah sedikit
            float x1 = lidRadius * sin(phi) * cos(theta1);
            float y1 = lidHeight * dome;
            float z1 = lidRadius * sin(phi) * sin(theta1);

            float x2 = lidRadius * sin(phi) * cos(theta2);
            float y2 = lidHeight * dome;
            float z2 = lidRadius * sin(phi) * sin(theta2);

            glVertex3f(x1, y1 + size * 0.2f, z1);  // Posisi tutup disesuaikan
            glVertex3f(x2, y2 + size * 0.2f, z2);
        }
        glEnd();
    }

    // Gagang kecil pada tutup (lebih kecil sesuai gambar)
    float knobRadius = lidRadius * 0.2f;  // Gagang lebih kecil
    float knobHeight = size * 0.03f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, size * 0.26f, 0);  // Titik atas gagang
    for (int i = 0; i <= slices; ++i) {
        float angle = i * 2.0f * M_PI / slices;
        float x = knobRadius * cos(angle);
        float z = knobRadius * sin(angle);
        glVertex3f(x, size * 0.22f + knobHeight * sin(angle), z);
    }
    glEnd();
}

void drawTeapot(float size) {
    drawTeapotBody(size);
    drawTeapotHandle(size);
    drawTeapotSpout(size);
    drawTeapotLid(size);
}

void init(int width, int height) {
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)width / (float)height;
    glFrustum(-aspect, aspect, -1.0, 1.0, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotated(rotAngle, 0, 1, 0);
    glRotated(rotAngle1, 1, 0, 0);
    drawTeapot(1.0f);
    glPopMatrix();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
        case GLFW_KEY_A: rotAngle += 5; break;
        case GLFW_KEY_L: rotAngle -= 5; break;
        case GLFW_KEY_Y: rotAngle1 += 5; break;
        case GLFW_KEY_B: rotAngle1 -= 5; break;
        case GLFW_KEY_Q: glfwSetWindowShouldClose(window, GLFW_TRUE); break;
        }
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    init(width, height);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Gagal menginisialisasi GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Teapot", NULL, NULL);
    if (!window) {
        std::cerr << "Gagal membuat jendela GLFW\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Gagal inisialisasi GLEW\n";
        return -1;
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    init(width, height);

    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
