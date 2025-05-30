#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

GLfloat xRotated = 0.0f, yRotated = 0.0f, zRotated = 0.0f;
static int shoulder = 0;
static int elbow = 0;
static int wrist = 0;
static int wrist_y = 0;
static int thumbBase = 0, thumbTip = 0;
static int indexBase = 0, indexMid = 0, indexTip = 0;
static int middleBase = 0, middleMid = 0, middleTip = 0;
static int ringBase = 0, ringMid = 0, ringTip = 0;
static int pinkyBase = 0, pinkyMid = 0, pinkyTip = 0;

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

void DrawFingerSegment(float length, float width = 0.1f, float depth = 0.1f){
    glPushMatrix();
    glScalef(length, width, depth);
    DrawWireCube();
    glPopMatrix();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.0, 0.0, -7.0);

    glPushMatrix();

    // Lengan atas
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    //Lengan Bawah
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    // Telapak Tangan
    glTranslatef(1.2, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist_y, 0.0, 0.0, 0.1);

    glPushMatrix();
    glScalef(0.5, 0.1, 0.4);  // Scale to make a palm
    DrawWireCube();
    glPopMatrix();

    float fingerLength = 0.2;
    // Kelingking
    glPushMatrix();
    glTranslatef(0.4, 0.0, 0.15);
    glRotatef((GLfloat)pinkyBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength);
    
    glTranslatef(fingerLength, 0.0, 0.0);
    glRotatef((GLfloat)pinkyMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.6);
    
    glTranslatef(fingerLength * 0.75, 0.0, 0.0);
    glRotatef((GLfloat)pinkyTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.4);
    glPopMatrix();

    // Jari Manis
    glPushMatrix();
    glTranslatef(0.4, 0.0, 0.05);
    glRotatef((GLfloat)ringBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength);
    
    glTranslatef(fingerLength, 0.0, 0.0);
    glRotatef((GLfloat)ringMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.6);
    
    glTranslatef(fingerLength * 0.75, 0.0, 0.0);
    glRotatef((GLfloat)ringTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.4);
    glPopMatrix();

    // Jari Tengah
    glPushMatrix();
    glTranslatef(0.4, 0.0, -0.05);
    glRotatef((GLfloat)middleBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength);
    
    glTranslatef(fingerLength, 0.0, 0.0);
    glRotatef((GLfloat)middleMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.6);
    
    glTranslatef(fingerLength * 0.75, 0.0, 0.0);
    glRotatef((GLfloat)middleTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.4);
    glPopMatrix();

    // Jari Telunjuk
    glPushMatrix();
    glTranslatef(0.4, 0.0, -0.15);
    glRotatef((GLfloat)indexBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength);
    
    glTranslatef(fingerLength, 0.0, 0.0);
    glRotatef((GLfloat)indexMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.6);
    
    glTranslatef(fingerLength * 0.75, 0.0, 0.0);
    glRotatef((GLfloat)indexTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.4);
    glPopMatrix();

    // Ibu Jari
    glPushMatrix();
    glTranslatef(0.2, 0.0, -0.25);
    glRotatef((GLfloat)thumbBase, 0.0, 1.0, 0.0);
    DrawFingerSegment(fingerLength);
    
    glTranslatef(fingerLength , 0.0, 0.0);
    glRotatef((GLfloat)thumbTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(fingerLength * 0.6);
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
            // Rotasi bahu (shoulder)
            case GLFW_KEY_S:
                shoulder = (shoulder + 5) % 360;
                break;
            case GLFW_KEY_W:
                shoulder = (shoulder - 5) % 360;
                break;

            // Rotasi siku (elbow) dengan batasan 0° - 180°
            case GLFW_KEY_E:
                if (elbow < 180) elbow += 5;
                break;
            case GLFW_KEY_Q:
                if (elbow > 0) elbow -= 5;
                break;

            // Putar pergelangan tangan (wrist) 180° pada sumbu X
            case GLFW_KEY_D:
                if (wrist < 180) wrist += 5;
                break;
            case GLFW_KEY_A:
                if (wrist > 0) wrist -= 5;
                break;

            // Putar pergelangan tangan (wrist_y) max ±90° pada sumbu Y
            case GLFW_KEY_Z:
                if (wrist_y < 90) wrist_y += 5;
                break;
            case GLFW_KEY_X:
                if (wrist_y > -90) wrist_y -= 5;
                break;

            // Pergerakan Jari kelingking
            case GLFW_KEY_1: pinkyBase = std::min(pinkyBase + 5, 90); break;
            case GLFW_KEY_2: pinkyBase = std::max(pinkyBase - 5, 0); break;
            case GLFW_KEY_3: pinkyMid = std::min(pinkyMid + 5, 90); break;
            case GLFW_KEY_4: pinkyMid = std::max(pinkyMid - 5, 0); break;
            case GLFW_KEY_5: pinkyTip = std::min(pinkyTip + 5, 90); break;
            case GLFW_KEY_6: pinkyTip = std::max(pinkyTip - 5, 0); break;

            // Pergerakan Jari Manis
            case GLFW_KEY_7: ringBase = std::min(ringBase + 5, 90); break;
            case GLFW_KEY_8: ringBase = std::max(ringBase - 5, 0); break;
            case GLFW_KEY_9: ringMid = std::min(ringMid + 5, 90); break;
            case GLFW_KEY_0: ringMid = std::max(ringMid - 5, 0); break;
            case GLFW_KEY_P: ringTip = std::min(ringTip + 5, 90); break;
            case GLFW_KEY_SEMICOLON: ringTip = std::max(ringTip - 5, 0); break;
            
            // Pergerakan Jari Tengah
            case GLFW_KEY_T: middleBase = std::min(middleBase + 5, 90); break;
            case GLFW_KEY_Y: middleBase = std::max(middleBase - 5, 0); break;
            case GLFW_KEY_G: middleMid = std::min(middleMid + 5, 90); break;
            case GLFW_KEY_H: middleMid = std::max(middleMid - 5, 0); break;
            case GLFW_KEY_B: middleTip = std::min(middleTip + 5, 90); break;
            case GLFW_KEY_N: middleTip = std::max(middleTip - 5, 0); break;

            // Pergerakan Jari Telunjuk
            case GLFW_KEY_U: indexBase = std::min(indexBase + 5, 90); break;
            case GLFW_KEY_I: indexBase = std::max(indexBase - 5, 0); break;
            case GLFW_KEY_J: indexMid = std::min(indexMid + 5, 90); break;
            case GLFW_KEY_K: indexMid = std::max(indexMid - 5, 0); break;
            case GLFW_KEY_M: indexTip = std::min(indexTip + 5, 90); break;
            case GLFW_KEY_L: indexTip = std::max(indexTip - 5, 0); break;

            // Pergerakan Ibu Jari
            case GLFW_KEY_R: thumbBase = std::min(thumbBase + 5, 90); break;
            case GLFW_KEY_F: thumbBase = std::max(thumbBase - 5, -90); break;
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
    GLFWwindow* window = glfwCreateWindow(640, 480, "Wireframe Cube",
    NULL, NULL);
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