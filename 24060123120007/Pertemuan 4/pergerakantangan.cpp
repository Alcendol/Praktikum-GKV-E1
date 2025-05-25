#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

//Rotasi tiap bagian
static int bahu = 0;
static int siku = 0;
static int telapak = 0;
static int jari1 = 0, jari2 = 0, jari3 = 0, jari4 = 0, jari5 = 0;

void DrawWireCube()
{
    glBegin(GL_LINES);
    glVertex3f(-0.5, -0.5, 0.5); glVertex3f( 0.5, -0.5, 0.5);
    glVertex3f( 0.5, -0.5, 0.5); glVertex3f( 0.5, 0.5, 0.5);
    glVertex3f( 0.5, 0.5, 0.5); glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5); glVertex3f(-0.5, -0.5, 0.5);

    glVertex3f(-0.5, -0.5, -0.5); glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5); glVertex3f( 0.5, 0.5, -0.5);
    glVertex3f( 0.5, 0.5, -0.5); glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5); glVertex3f(-0.5, -0.5, -0.5);

    glVertex3f(-0.5, -0.5, 0.5); glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, 0.5); glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, 0.5, 0.5); glVertex3f( 0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5); glVertex3f(-0.5, 0.5, -0.5);
    glEnd();
}

//Gambar sumbu XYZ
void DrawAxes()
{
    glLineWidth(3.0f); 
    glBegin(GL_LINES);

    //X (Merah)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(10.0f, 0.0f, 0.0f);

    //Y (Hijau)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 10.0f, 0.0f);

    //Z (Biru)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);

    glEnd();
    glLineWidth(1.0f);
    glColor3f(1.0f, 1.0f, 1.0f); 
}

//Gambar grid/milimeter block
void DrawGrid()
{
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_LINES);
    for (int i = -10; i <= 10; ++i) {
        glVertex3f(i, 0, -10); glVertex3f(i, 0, 10); 
        glVertex3f(-10, 0, i); glVertex3f(10, 0, i); 
    }
    glEnd();
    glColor3f(1, 1, 1);
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(6, 6, 6, 0, 0, 0, 0, 1, 0);

    DrawGrid();
    DrawAxes();

    //Bahu
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)bahu, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    //Siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)siku, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    //Telapak tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)telapak, 0.0, 0.0, 1.0);

    glPushMatrix();
    glScalef(1.0, 0.3, 0.7);
    DrawWireCube();
    glPopMatrix();

    //Jari
    for (int i = 0; i < 5; ++i)
    {
        int* finger = nullptr;
        switch (i) {
            case 0: finger = &jari1; break;
            case 1: finger = &jari2; break;
            case 2: finger = &jari3; break;
            case 3: finger = &jari4; break;
            case 4: finger = &jari5; break;
        }

        float zOffset = -0.3f + i * 0.15f;

        glPushMatrix();
        glTranslatef(0.6f, 0.1f, zOffset);
        glRotatef((GLfloat)(*finger), 0.0, 0.0, 1.0);
        glTranslatef(0.3f, 0.0f, 0.0f);
        glPushMatrix();
        glScalef(0.6, 0.1, 0.1);
        DrawWireCube();
        glPopMatrix();
        glPopMatrix();
    }

    glPopMatrix();
}

void Reshape(GLFWwindow* window, int width, int height)
{
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_S: bahu = (bahu + 5) % 360; break;
            case GLFW_KEY_W: bahu = (bahu - 5) % 360; break;
            case GLFW_KEY_E: if (siku < 150) siku += 5; break;
            case GLFW_KEY_Q: if (siku > 0) siku -= 5; break;
            case GLFW_KEY_R: if (telapak < 90) telapak += 5; break;
            case GLFW_KEY_F: if (telapak > -90) telapak-= 5; break;
            case GLFW_KEY_1: if (jari1 < 90) jari1 += 5; break;
            case GLFW_KEY_2: if (jari2 < 90) jari2 += 5; break;
            case GLFW_KEY_3: if (jari3 < 90) jari3 += 5; break;
            case GLFW_KEY_4: if (jari4 < 90) jari4 += 5; break;
            case GLFW_KEY_5: if (jari5 < 90) jari5 += 5; break;
            case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, true); break;
        }
    }
}

int main()
{
    if (!glfwInit()) {
        std::cerr << "GLFW init failed\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Pergerakan Tangan", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW init failed\n";
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(window, KeyCallback);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    Reshape(window, width, height);

    while (!glfwWindowShouldClose(window)) {
        Display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
