/* Nama : Sophie Venecia May M
   Nim  : 24060123120043
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

// Fungsi untuk menggambar persegi panjang
void drawRectangle(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b); // Menentukan warna persegi panjang
    glBegin(GL_QUADS); // Memulai gambar quadrilateral
    glVertex2f(x, y); // Titik kiri bawah
    glVertex2f(x + width, y); // Titik kanan bawah
    glVertex2f(x + width, y + height); // Titik kanan atas
    glVertex2f(x, y + height); // Titik kiri atas
    glEnd(); // Menyelesaikan gambar
}

// Fungsi untuk menggambar lingkaran
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON); // Memulai gambar lingkaran sebagai poligon
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Menghitung sudut
        float x = r * cosf(theta); // Menghitung koordinat x
        float y = r * sinf(theta); // Menghitung koordinat y
        glVertex2f(x + cx, y + cy); // Menambahkan titik ke lingkaran
    }
    glEnd(); // Menyelesaikan gambar
}

// Fungsi untuk menggambar roda
void drawWheel(float cx, float cy, float r) {
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam untuk ban luar
    drawCircle(cx, cy, r, 30); // Gambar ban luar
    glColor3f(0.7f, 0.7f, 0.7f); // Warna abu-abu untuk ban dalam
    drawCircle(cx, cy, r * 0.4f, 20); // Gambar ban dalam
}

// Fungsi untuk menggambar mobil
void drawCar(float x, float y) {
    glPushMatrix(); // Menyimpan status transformasi

    glTranslatef(x, y, 0.0f); // Translasi mobil

    drawRectangle(-0.2f, 0.0f, 0.4f, 0.1f, 0.8f, 0.0f, 0.0f); // Badan mobil
    drawRectangle(-0.12f, 0.07f, 0.24f, 0.06f, 0.9f, 0.0f, 0.0f); // Atap mobil
    drawRectangle(-0.08f, 0.08f, 0.06f, 0.04f, 1.0f, 1.0f, 1.0f); // Kaca depan
    drawRectangle(0.02f, 0.08f, 0.06f, 0.04f, 1.0f, 1.0f, 1.0f); // Kaca belakang
    drawWheel(-0.12f, -0.05f, 0.05f); // Roda kiri
    drawWheel(0.12f, -0.05f, 0.05f); // Roda kanan

    glPopMatrix(); // Mengembalikan status transformasi
}

// Fungsi untuk menggambar pohon
void drawTree(float x, float y) {
    glPushMatrix(); // Menyimpan status transformasi
    glTranslatef(x, y, 0.0f); // Translasi pohon

    drawRectangle(-0.02f, 0.0f, 0.04f, 0.15f, 0.5f, 0.3f, 0.1f); // Batang pohon
    glColor3f(0.0f, 0.5f, 0.0f); // Warna hijau untuk daun
    drawCircle(0.0f, 0.15f, 0.07f, 20); // Daun utama
    drawCircle(-0.04f, 0.12f, 0.05f, 15); // Daun kiri
    drawCircle(0.04f, 0.12f, 0.05f, 15); // Daun kanan

    glPopMatrix(); // Mengembalikan status transformasi
}

// Fungsi untuk menggambar matahari
void drawSun(float x, float y, float r) {
    glPushMatrix(); // Menyimpan status transformasi
    glTranslatef(x, y, 0.0f); // Translasi matahari

    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk matahari
    drawCircle(0.0f, 0.0f, r, 30); // Gambar lingkaran matahari

    // Gambar sinar matahari
    for (int i = 0; i < 12; i++) {
        float angle = i * (M_PI / 6); // Menentukan sudut untuk setiap sinar
        float x1 = cos(angle) * (r + 0.05f); // Titik awal sinar
        float y1 = sin(angle) * (r + 0.05f);
        float x2 = cos(angle) * (r + 0.12f); // Titik akhir sinar
        float y2 = sin(angle) * (r + 0.12f);
        
        glBegin(GL_LINES); // Memulai gambar garis sinar
        glVertex2f(x1, y1); // Titik awal sinar
        glVertex2f(x2, y2); // Titik akhir sinar
        glEnd(); // Menyelesaikan gambar garis
    }

    glPopMatrix(); // Mengembalikan status transformasi
}

// Fungsi untuk menggambar rambu lalu lintas
void drawTrafficSign(float x, float y) {
    drawRectangle(x - 0.01f, y, 0.02f, 0.3f, 0.5f, 0.5f, 0.5f); // Tiang rambu
    drawRectangle(x - 0.04f, y + 0.3f, 0.08f, 0.18f, 0.0f, 0.0f, 0.0f); // Lengan rambu

    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk bagian atas rambu
    drawCircle(x, y + 0.42f, 0.02f, 20); // Bagian merah
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk bagian tengah rambu
    drawCircle(x, y + 0.36f, 0.02f, 20); // Bagian kuning
    glColor3f(0.0f, 1.0f, 0.0f); // Warna hijau untuk bagian bawah rambu
    drawCircle(x, y + 0.30f, 0.02f, 20); // Bagian hijau
}

// Fungsi untuk menggambar rumput
void drawGrass(float x, float y, float width, float height) {
    drawRectangle(x, y, width, height, 0.0f, 0.7f, 0.0f); // Warna hijau untuk rumput
}

// Fungsi untuk menggambar seluruh adegan
void drawScene() {
    glPushMatrix(); // Menyimpan status transformasi

    // Langit
    drawRectangle(-1.0f, 0.2f, 2.0f, 0.8f, 0.5f, 0.8f, 1.0f); 
    drawGrass(-1.0f, -0.7f, 2.0f, 0.5f); // Rumput
    drawRectangle(-1.0f, -0.4f, 2.0f, 0.4f, 0.2f, 0.2f, 0.2f); // Jalan
    drawGrass(-1.0f, 0.0f, 2.0f, 0.2f); // Rumput lagi

    // Membuat garis putih di jalan
    for (float i = -0.9f; i < 1.0f; i += 0.2f) {
        drawRectangle(i, -0.15f, 0.1f, 0.02f, 1.0f, 1.0f, 1.0f);
    }

    drawCar(0.0f, -0.25f); // Gambar mobil

    // Gambar pohon di beberapa tempat
    for (float i = -0.8f; i <= 0.8f; i += 0.3f) {
        drawTree(i, 0.1f);
    }

    drawSun(0.7f, 0.7f, 0.1f); // Gambar matahari
    drawTrafficSign(-0.95f, -0.45f); // Gambar rambu lalu lintas

    glPopMatrix(); // Mengembalikan status transformasi
}

int main() {
    if (!glfwInit()) return -1; // Inisialisasi GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Improved Car Scene", NULL, NULL); // Membuat jendela
    if (!window) {
        glfwTerminate();
        return -1; // Jika gagal membuat jendela
    }
    glfwMakeContextCurrent(window);
    glewInit(); // Inisialisasi GLEW
    glViewport(0, 0, 800, 600); // Mengatur ukuran tampilan

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Menetapkan warna latar belakang (abu-abu)

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT); // Membersihkan layar
        drawScene(); // Menggambar seluruh adegan
        glfwSwapBuffers(window); // Menukar buffer
        glfwPollEvents(); // Memproses event
    }

    glfwDestroyWindow(window); // Menghancurkan jendela
    glfwTerminate(); // Menghentikan GLFW
    return 0;
}
