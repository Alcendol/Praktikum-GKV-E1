#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

GLfloat xRotated = 0.0f, yRotated = 0.0f, zRotated = 0.0f;
static float handOffset = -2.0f; // Posisi awal lengan ke kiri

static int shoulder = 0;    // Rotasi bahu
static int elbow = 0;       // Rotasi siku
static int wrist = 0;       // Rotasi telapak tangan
static int fingerBase[4] = {0, 0, 0, 0};  // Rotasi dasar 4 jari utama
static int fingerTip[4] = {0, 0, 0, 0};   // Rotasi ujung 4 jari utama
static int thumbBase = 0;   // Rotasi dasar jempol
static int thumbTip = 0;    // Rotasi ujung jempol

void DrawWireCube()
{
    glBegin(GL_LINES);
    glVertex3f(-0.5, -0.5, 0.5); glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5); glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5); glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5); glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, -0.5); glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5); glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5); glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5); glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5); glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5); glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5); glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5); glVertex3f(-0.5, 0.5, -0.5);
    glEnd();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -7.0);

    glTranslatef(handOffset, 0.0, 0.0);

    // Bahu
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    // Siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.4, 0.0, 0.0);  // Panjang telapak tangan
    glPushMatrix();
    glScalef(1.2, 0.4, 0.6);  // Tinggi sama dengan bahu/lengan
    DrawWireCube();
    glPopMatrix();

    // Jari-jari
    // Panjang, lebar, dan tinggi setiap jari disesuaikan
    const float fingerLengths[4] = {0.5f, 0.6f, 0.5f, 0.45f}; // Panjang jari
    const float fingerWidths[4] = {0.18f, 0.18f, 0.15f, 0.14f}; // Lebar jari lebih kecil
    const float fingerHeights[4] = {0.08f, 0.08f, 0.07f, 0.06f}; // Tinggi lebih pendek

    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(0.45, 0.15 - i * 0.12, 0.3); // Semua jari menempel pada telapak
        glRotatef((GLfloat)fingerBase[i], 0.0, 0.0, 1.0);
        glTranslatef(fingerLengths[i] / 2, 0.0, 0.0); // Penyesuaian panjang jari
        glPushMatrix();
        glScalef(fingerLengths[i], fingerHeights[i], fingerWidths[i]); // Dasar jari lebih kecil
        DrawWireCube();
        glPopMatrix();

        glTranslatef(fingerLengths[i] / 2, 0.0, 0.0);
        glRotatef((GLfloat)fingerTip[i], 0.0, 0.0, 1.0);
        glTranslatef(fingerLengths[i] / 4, 0.0, 0.0);
        glPushMatrix();
        glScalef(fingerLengths[i] / 2, fingerHeights[i], fingerWidths[i]); // Ujung jari lebih kecil lagi
        DrawWireCube();
        glPopMatrix();
        glPopMatrix();
    }

    // Jempol
    glPushMatrix();
    glTranslatef(0.35, 0.25, 0.0); // Menempel pada telapak tangan
    glRotatef((GLfloat)thumbBase, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);  // Translasi dasar diperkecil
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1); // Dasar jempol lebih pendek
    DrawWireCube();
    glPopMatrix();

    glTranslatef(0.2, 0.0, 0.0);  // Translasi ujung diperkecil
    glRotatef((GLfloat)thumbTip, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);  // Translasi terakhir ujung
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1); // Ujung jempol lebih pendek
    DrawWireCube();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}




void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_S:
            if (shoulder < 180) shoulder += 5;
            break;
        case GLFW_KEY_W:
            if (shoulder > 0) shoulder -= 5;
            break;
        case GLFW_KEY_E:
            if (elbow < 135) elbow += 5;
            break;
        case GLFW_KEY_Q:
            if (elbow > 0) elbow -= 5;
            break;
        case GLFW_KEY_R:
            if (wrist < 90) wrist += 5;
            break;
        case GLFW_KEY_F:
            if (wrist > -90) wrist -= 5;
            break;
        // Pergerakan dasar dan ujung jari utama
        case GLFW_KEY_T:
            for (int i = 0; i < 4; i++)
            {
                if (fingerBase[i] < 90) fingerBase[i] += 5;
            }
            break;
        case GLFW_KEY_G:
            for (int i = 0; i < 4; i++)
            {
                if (fingerBase[i] > 0) fingerBase[i] -= 5;
            }
            break;
        case GLFW_KEY_Y:
            for (int i = 0; i < 4; i++)
            {
                if (fingerTip[i] < 45) fingerTip[i] += 5;
            }
            break;
        case GLFW_KEY_H:
            for (int i = 0; i < 4; i++)
            {
                if (fingerTip[i] > 0) fingerTip[i] -= 5;
            }
            break;
        // Pergerakan dasar dan ujung jempol
        case GLFW_KEY_U:
            if (thumbBase < 90) thumbBase += 5;
            break;
        case GLFW_KEY_J:
            if (thumbBase > 0) thumbBase -= 5;
            break;
        case GLFW_KEY_I:
            if (thumbTip < 45) thumbTip += 5;
            break;
        case GLFW_KEY_K:
            if (thumbTip > 0) thumbTip -= 5;
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

    GLFWwindow* window = glfwCreateWindow(640, 480, "Hand Movement", NULL, NULL);
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
