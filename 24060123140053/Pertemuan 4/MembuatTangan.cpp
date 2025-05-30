// Nama: Syahreza Abror Alvarizqi
// NIM: 24060123140053
// Lab: GKV E1

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

GLfloat xRotated = 0.0f, yRotated = 0.0f, zRotated = 0.0f;
static int shoulder = 0;
static int elbow = 0;
static int wrist = 0;        
static int thumbBase = 0;     
static int thumbMiddle = 0; 
static int indexBase = 0;     
static int indexMiddle = 0; 
static int middleBase = 0;  
static int middleMiddle = 0; 
static int ringBase = 0;    
static int ringMiddle = 0;   
static int pinkyBase = 0;     
static int pinkyMiddle = 0;   

const int MAX_ELBOW_ANGLE = 140;
const int MIN_ELBOW_ANGLE = 0;
const int MAX_WRIST_ANGLE = 90;
const int MIN_WRIST_ANGLE = -90;
const int MAX_FINGER_BASE_ANGLE = 90;
const int MIN_FINGER_BASE_ANGLE = 0;
const int MAX_FINGER_MIDDLE_ANGLE = 90;
const int MIN_FINGER_MIDDLE_ANGLE = 0;

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

// Fungsi untuk menggambar jari
void DrawFinger(float length, float width) {
    glPushMatrix();
    glScalef(length, width, width);
    DrawWireCube();
    glPopMatrix();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);

    glPushMatrix();

    glTranslatef(-2.0, 0.0, 0.0);

    // Rotasi bahu
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);

    // Lengan atas (upper arm)
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    // Siku dan rotasinya
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);

    // Lengan bawah (forearm)
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    // Pergelangan tangan dan rotasinya
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 1.0, 0.0, 0.0);  // Rotasi pada sumbu X untuk gerakan atas-bawah

    // Telapak tangan
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.5, 1.2);
    DrawWireCube();
    glPopMatrix();

    // Posisi pangkal ibu jari (sedikit ke belakang dan bawah)
    glPushMatrix();
    glTranslatef(-0.3, -0.3, 0.5);
    glRotatef(45, 0.0, 1.0, 0.0);  // Orientasi dasar ibu jari
    glRotatef((GLfloat)thumbBase, 0.0, 0.0, 1.0);

    // Ruas dasar ibu jari
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    DrawFinger(0.3, 0.1);
    glPopMatrix();

    // Ruas tengah ibu jari
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)thumbMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    DrawFinger(0.3, 0.1);

    glPopMatrix(); // Kembali ke telapak tangan

    // Jari telunjuk
    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.3);
    glRotatef((GLfloat)indexBase, 0.0, 0.0, 1.0);
    
    // Ruas dasar telunjuk
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    DrawFinger(0.4, 0.1);
    glPopMatrix();
    
    // Ruas tengah telunjuk
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)indexMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    DrawFinger(0.4, 0.1);
    
    glPopMatrix(); 
    
    // Jari tengah
    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.0);
    glRotatef((GLfloat)middleBase, 0.0, 0.0, 1.0);
    
    // Ruas dasar jari tengah
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    DrawFinger(0.4, 0.1);
    glPopMatrix();
    
    // Ruas tengah jari tengah
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)middleMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    DrawFinger(0.4, 0.1);
    
    glPopMatrix(); 
    
    // Jari manis
    glPushMatrix();
    glTranslatef(0.5, 0.2, -0.3);
    glRotatef((GLfloat)ringBase, 0.0, 0.0, 1.0);
    
    // Ruas dasar jari manis
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    DrawFinger(0.4, 0.1);
    glPopMatrix();
    
    // Ruas tengah jari manis
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)ringMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    DrawFinger(0.4, 0.1);
    
    glPopMatrix();
    
    // Jari kelingking
    glPushMatrix();
    glTranslatef(0.5, 0.2, -0.6);
    glRotatef((GLfloat)pinkyBase, 0.0, 0.0, 1.0);
    
    // Ruas dasar kelingking
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    DrawFinger(0.3, 0.08);
    glPopMatrix();
    
    // Ruas tengah kelingking
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)pinkyMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    DrawFinger(0.3, 0.08);
    
    glPopMatrix();
    
    glPopMatrix();  // Kembali ke koordinat dunia
}

// Fungsi untuk menerapkan batas-batas pergerakan
int ClampAngle(int angle, int min, int max) {
    if (angle > max) return max;
    if (angle < min) return min;
    return angle;
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
            elbow = ClampAngle(elbow + 5, MIN_ELBOW_ANGLE, MAX_ELBOW_ANGLE);
            break;
        case GLFW_KEY_Q:
            elbow = ClampAngle(elbow - 5, MIN_ELBOW_ANGLE, MAX_ELBOW_ANGLE);
            break;

        case GLFW_KEY_D:
            wrist = ClampAngle(wrist + 5, MIN_WRIST_ANGLE, MAX_WRIST_ANGLE);
            break;
        case GLFW_KEY_A:
            wrist = ClampAngle(wrist - 5, MIN_WRIST_ANGLE, MAX_WRIST_ANGLE);
            break;

        case GLFW_KEY_T:
            thumbBase = ClampAngle(thumbBase + 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_G:
            thumbBase = ClampAngle(thumbBase - 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_Y:
            thumbMiddle = ClampAngle(thumbMiddle + 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;
        case GLFW_KEY_H:
            thumbMiddle = ClampAngle(thumbMiddle - 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;

        case GLFW_KEY_U:
            indexBase = ClampAngle(indexBase + 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_J:
            indexBase = ClampAngle(indexBase - 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_I:
            indexMiddle = ClampAngle(indexMiddle + 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;
        case GLFW_KEY_K:
            indexMiddle = ClampAngle(indexMiddle - 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;

        case GLFW_KEY_O:
            middleBase = ClampAngle(middleBase + 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_L:
            middleBase = ClampAngle(middleBase - 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_P:
            middleMiddle = ClampAngle(middleMiddle + 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;
        case GLFW_KEY_SEMICOLON:  // ;
            middleMiddle = ClampAngle(middleMiddle - 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;

        case GLFW_KEY_Z:
            ringBase = ClampAngle(ringBase + 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_X:
            ringBase = ClampAngle(ringBase - 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_C:
            ringMiddle = ClampAngle(ringMiddle + 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;
        case GLFW_KEY_V:
            ringMiddle = ClampAngle(ringMiddle - 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;

        case GLFW_KEY_B:
            pinkyBase = ClampAngle(pinkyBase + 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_N:
            pinkyBase = ClampAngle(pinkyBase - 5, MIN_FINGER_BASE_ANGLE, MAX_FINGER_BASE_ANGLE);
            break;
        case GLFW_KEY_M:
            pinkyMiddle = ClampAngle(pinkyMiddle + 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;
        case GLFW_KEY_COMMA:  // ,
            pinkyMiddle = ClampAngle(pinkyMiddle - 5, MIN_FINGER_MIDDLE_ANGLE, MAX_FINGER_MIDDLE_ANGLE);
            break;

        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, true);
            break;
        }
    }
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

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Animasi Tangan", NULL, NULL);
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

// simulasi operasi yang dilakukan ketika keyboard ditekan, direpresentasikan dalam konteks sumbu x, y, z:

// 1. Rotasi Bahu (Tombol W/S):
// Operasi rotasi pada sumbu Z
// Pada saat tombol S ditekan: Rotasi +5 derajat pada sumbu Z (searah jarum jam)
// Pada saat tombol W ditekan: Rotasi -5 derajat pada sumbu Z (berlawanan jarum jam)
// Representasi matriks: Rotasi Z(θ) = [cos(θ) -sin(θ) 0; sin(θ) cos(θ) 0; 0 0 1]

// 2. Rotasi Siku (Tombol Q/E):
// Operasi rotasi pada sumbu Z
// Pada saat tombol E ditekan: Rotasi +5 derajat pada sumbu Z (terbatas 0-140°)
// Pada saat tombol Q ditekan: Rotasi -5 derajat pada sumbu Z (terbatas 0-140°)
// Representasi matriks: Rotasi Z(θ) = [cos(θ) -sin(θ) 0; sin(θ) cos(θ) 0; 0 0 1]

// 3. Rotasi Pergelangan (Tombol A/D):
// Operasi rotasi pada sumbu X (untuk gerakan atas-bawah)
// Pada saat tombol D ditekan: Rotasi +5 derajat pada sumbu X (terbatas -90° sampai 90°)
// Pada saat tombol A ditekan: Rotasi -5 derajat pada sumbu X (terbatas -90° sampai 90°)
// Representasi matriks: Rotasi X(θ) = [1 0 0; 0 cos(θ) -sin(θ); 0 sin(θ) cos(θ)]

// 4. Rotasi Jari (Berbagai Tombol):
// Semua rotasi jari beroperasi pada sumbu Z
// Batasan: 0° sampai 90° untuk semua gerakan jari
// Representasi matriks sama dengan rotasi pada sumbu Z

// Diagram milimeter blok untuk representasi rotasi saat keyboard ditekan (untuk bahu):

// ^ Y
//      |
//      |   Z (keluar dari bidang)
//      |  /
//      | /
//      |/
// -----+-----> X
//      |
//      |

// Rotasi W (rotasi bahu -5°)     Rotasi S (rotasi bahu +5°)
//      ^ Y                             ^ Y
//      |                               |
//    ,'|                             ,'|
//   /  |                            /  |
//  /   |                           /   |
// /    |                          /    |
// -----+-----> X                 -----+-----> X
//      |   \                           |    /
//      |    \                          |   /
//      |     \                         |  /
//      |      \                        | /
//      |       v                       |/
//                                      v