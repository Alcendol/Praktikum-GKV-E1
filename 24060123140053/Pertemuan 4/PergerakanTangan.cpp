// Nama: Syahreza Abror Alvarizqi
// NIM: 24060123140053
// Lab: GKV E1
// penjelasan kode ini ada baris paling bawah

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

GLfloat xRotated = 0.0f, yRotated = 0.0f, zRotated = 0.0f;
static int shoulder = 0;
static int elbow = 0;

void DrawWireCube()
{
    glBegin(GL_LINES);

    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f( 0.5, -0.5, 0.5);

    glVertex3f( 0.5, -0.5, 0.5);
    glVertex3f( 0.5, 0.5, 0.5);

    glVertex3f( 0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);

    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, 0.5, -0.5);

    glVertex3f( 0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);

    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5);

    glVertex3f( 0.5, -0.5, 0.5);
    glVertex3f( 0.5, -0.5, -0.5);

    glVertex3f( 0.5, 0.5, 0.5);
    glVertex3f( 0.5, 0.5, -0.5);

    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glEnd();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -7.0);

    glPushMatrix();

    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    glPopMatrix();
}

void Reshape(GLFWwindow* window, int width, int height)
{
    if (height == 0 || width == 0) return;

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)width / (GLfloat)height, 0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
        case GLFW_KEY_S:
            shoulder = (shoulder + 5) % 360;
            break;
        case GLFW_KEY_W:
            shoulder = (shoulder - 5) % 360;
            break;
        case GLFW_KEY_E:
            elbow = (elbow + 5) % 360;
            break;
        case GLFW_KEY_Q:
            elbow = (elbow - 5) % 360;
            break;
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, true);
            break;
        }
    }
}

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Wireframe Cube", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(window, KeyCallback);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    Reshape(window, width, height);

    while (!glfwWindowShouldClose(window))
    {
    Display();
    glfwSwapBuffers(window);
    glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

// penjelasan kode:
// Pergerakan tangan pada kode tersebut bekerja dengan prinsip-prinsip berikut:
// 1. Inisialisasi Variabel Rotasi:
// Variabel shoulder dan elbow dideklarasikan sebagai variabel statis dengan nilai awal 0
// Variabel ini mengontrol sudut rotasi untuk bahu dan siku

// 2. Pembentukan Struktur Tangan:
// Bagian lengan dibentuk menggunakan fungsi DrawWireCube() yang menggambar kubus wire
// Dua kubus wireframe digunakan pada satu untuk lengan atas (dari bahu ke siku) dan satu untuk lengan bawah (dari siku ke pergelangan)

// 3. Transformasi dan Hierarki:
// Implementasi menggunakan konsep push dan pop matrix untuk membuat hierarki transformasi
// glPushMatrix() menyimpan state transformasi saat ini
// glPopMatrix() mengembalikan ke state transformasi yang disimpan sebelumnya

// 4. Mekanisme Pergerakan:
// Fungsi Display() mengatur posisi dan orientasi lengan:
// Pertama translasi ke titik (-1.0, 0.0, 0.0) untuk posisi awal bahu
// Rotasi sebesar nilai shoulder pada sumbu Z (menggambarkan gerakan bahu)
// Translasi (1.0, 0.0, 0.0) untuk menempatkan lengan atas
// Penskalaan lengan atas dengan glScalef(2.0, 0.4, 1.0) untuk memberikan bentuk persegi panjang
// Translasi ke posisi siku
// Rotasi sebesar nilai elbow pada sumbu Z (menggambarkan gerakan siku)
// Translasi dan penskalaan untuk lengan bawah

// 5. Kontrol melalui Keyboard:
// Implementasi callback keyboard (KeyCallback) untuk mengontrol pergerakan:
// Tombol 'S': Menambah sudut rotasi bahu sebesar 5 derajat (berputar searah jarum jam)
// Tombol 'W': Mengurangi sudut rotasi bahu sebesar 5 derajat (berputar berlawanan jarum jam)
// Tombol 'E': Menambah sudut rotasi siku sebesar 5 derajat
// Tombol 'Q': Mengurangi sudut rotasi siku sebesar 5 derajat
// Operasi modulo 360 digunakan untuk membatasi nilai rotasi dalam rentang 0-359 derajat

// 6. Rendering dan Update:
// Fungsi Display() dipanggil pada setiap frame untuk merender ulang lengan dengan sudut rotasi terkini
// glfwSwapBuffers() dan glfwPollEvents() digunakan untuk update tampilan dan menangkap input