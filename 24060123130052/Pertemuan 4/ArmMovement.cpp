#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

GLfloat xRotated = 0.0f, yRotated = 0.0f, zRotated = 0.0f;
static int shoulder = 0;
static int elbow = 0;
static int wrist = 0;
static int pinky = 0, ring_finger = 0, middle_finger = 0, index_finger = 0, thumb = 0;
static int armRotation = 0;

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

void drawFinger(float x, float y, float z, int angle, float scaleX, float rotX, float rotY)
{
    glPushMatrix();
    glTranslatef(x - 0.125 * scaleX, y, z); // Menggeser sumbu rotasi ke pangkal jari
    glRotatef((GLfloat)-angle, 0.0, 0.0, 1.0); // Membalik arah rotasi
    glTranslatef(0.125 * scaleX, 0, 0); // Mengembalikan posisi jari agar tidak bertabrakan
    glRotatef((GLfloat)rotX, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)rotY, 0.0, 1.0, 0.0);
    glScalef(0.2 * scaleX, 0.1, 0.1); // Mengurangi skala jari agar tidak bertabrakan dengan telapak
    DrawWireCube();
    glPopMatrix();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -7.0);
    glRotatef((GLfloat)armRotation, 0.0, 1.0, 0.0);
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
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.3, 0.8);
    DrawWireCube();
    glPopMatrix();
    drawFinger(0.35, 0.15, -0.25, pinky, 2.5, 0, 0);
    drawFinger(0.35, 0.15, -0.1, ring_finger, 2.5, 0, 0);
    drawFinger(0.35, 0.15, 0.05, middle_finger, 2.5, 0, 0);
    drawFinger(0.35, 0.15, 0.2, index_finger, 2.5, 0, 0);
    drawFinger(0.25, -0.1, 0.45, thumb, 2.5, -30, -20);
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
        case GLFW_KEY_S: shoulder = (shoulder + 5) % 360; break;
        case GLFW_KEY_W: shoulder = (shoulder - 5) % 360; break;
        case GLFW_KEY_E: if (elbow < 135) elbow += 5; break;
        case GLFW_KEY_Q: if (elbow > 0) elbow -= 5; break;
        case GLFW_KEY_R: if (wrist < 90) wrist += 5; break;
        case GLFW_KEY_F: if (wrist > -90) wrist -= 5; break;
        case '1': pinky = (pinky + 5) % 90; break;
        case '2': pinky = (pinky - 5) % 90; break;
        case '3': ring_finger = (ring_finger + 5) % 90; break;
        case '4': ring_finger = (ring_finger - 5) % 90; break;
        case '5': middle_finger = (middle_finger + 5) % 90; break;
        case '6': middle_finger = (middle_finger - 5) % 90; break;
        case '7': index_finger = (index_finger + 5) % 90; break;
        case '8': index_finger = (index_finger - 5) % 90; break;
        case '9': thumb = (thumb + 5) % 90; break;
        case '0': thumb = (thumb - 5) % 90; break;
        case GLFW_KEY_A: armRotation = (armRotation + 5) % 360; break;
        case GLFW_KEY_D: armRotation = (armRotation - 5) % 360; break;
        case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, true); break;
        }
    }
}

int main()
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "Wireframe Arm", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
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
