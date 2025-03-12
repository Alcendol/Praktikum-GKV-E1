#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Fungsi untuk menangani input keyboard
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

// Fungsi untuk menggambar berbagai bentuk primitif OpenGL
void render() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. GL_LINE_STRIP (garis bersambung)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.8f, 0.8f);
        glVertex2f(-0.6f, 0.6f);
        glVertex2f(-0.4f, 0.8f);
        glVertex2f(-0.2f, 0.6f);
    glEnd();

    // 2. GL_LINE_LOOP (garis tertutup)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.2f, 0.8f);
        glVertex2f(0.4f, 0.6f);
        glVertex2f(0.6f, 0.8f);
        glVertex2f(0.5f, 0.9f);
    glEnd();

    // 3. GL_TRIANGLE_FAN (bentuk kipas segitiga)
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.5f, 0.0f); // Titik pusat
        glVertex2f(-0.7f, -0.2f);
        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f(-0.3f, -0.2f);
    glEnd();

    // 4. GL_TRIANGLE_STRIP (strip segitiga)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.4f, -0.2f);
        glVertex2f(0.6f, 0.0f);
        glVertex2f(0.8f, -0.2f);
    glEnd();

    // 5. GL_QUADS (kotak individual)
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.8f, -0.8f);
        glVertex2f(-0.6f, -0.8f);
        glVertex2f(-0.6f, -0.6f);
        glVertex2f(-0.8f, -0.6f);
    glEnd();

    // 6. GL_QUAD_STRIP (strip kuadrilateral)
    glColor3f(0.5, 0.0, 0.5);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.2f, -0.8f);
        glVertex2f(0.0f, -0.8f);
        glVertex2f(-0.2f, -0.6f);
        glVertex2f(0.0f, -0.6f);
        glVertex2f(-0.2f, -0.4f);
        glVertex2f(0.0f, -0.4f);
    glEnd();
}

// Fungsi utama untuk inisialisasi OpenGL
int main() {
    // Inisialisasi GLFW
    if (!glfwInit()) {
        std::cerr << "Gagal menginisialisasi GLFW" << std::endl;
        return -1;
    }

    // Buat jendela GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "program", nullptr, nullptr);
    if (!window) {
        std::cerr << "Gagal membuat jendela GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Inisialisasi GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Gagal menginisialisasi GLEW" << std::endl;
        return -1;
    }

    // Atur viewport dan proyeksi tanpa gluOrtho2D
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Mengganti gluOrtho2D dengan glOrtho

    // Loop utama
    while (!glfwWindowShouldClose(window)) {
        processInput(window);  // Cek input keyboard
        render();              // Render objek
        glfwSwapBuffers(window);
        glfwPollEvents();      // Perbarui event
    }

    // Bersihkan sumber daya
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
