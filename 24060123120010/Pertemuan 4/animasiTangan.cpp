/* Nama File : animasiTangan.cpp
 * Pembuat   : Shopia Mudjahidah
 * NIM       : 24060123120010
 * Tanggal   : 24 Maret 2025 
 * Lab       : GKV E1
 */

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

GLfloat xRotated = 0.0f, yRotated = 0.0f, zRotated = 0.0f;

static int shoulder = 0;
static int elbow = 0;
static int wrist = 0;
static int thumbBase = 0, thumbMid = 0, thumbTip = 0;
static int indexBase = 0, indexMid = 0, indexTip = 0;
static int middleBase = 0, middleMid = 0, middleTip = 0;
static int ringBase = 0, ringMid = 0, ringTip = 0;
static int pinkyBase = 0, pinkyMid = 0, pinkyTip = 0;

void DrawWireCube(float scaleX = 1.0f, float scaleY = 1.0f, float scaleZ = 1.0f){
    glBegin(GL_LINES);

    // front face lines
    glVertex3f(-0.5 * scaleX, -0.5 * scaleY,  0.5 * scaleZ);
    glVertex3f( 0.5 * scaleX, -0.5 * scaleY,  0.5 * scaleZ);
    
    glVertex3f( 0.5 * scaleX, -0.5 * scaleY,  0.5 * scaleZ);
    glVertex3f( 0.5 * scaleX,  0.5 * scaleY,  0.5 * scaleZ);

    glVertex3f( 0.5 * scaleX,  0.5 * scaleY,  0.5 * scaleZ);
    glVertex3f(-0.5 * scaleX,  0.5 * scaleY,  0.5 * scaleZ);

    glVertex3f(-0.5 * scaleX,  0.5 * scaleY,  0.5 * scaleZ);
    glVertex3f(-0.5 * scaleX, -0.5 * scaleY,  0.5 * scaleZ);

    // back face lines
    glVertex3f(-0.5 * scaleX, -0.5 * scaleY, -0.5 * scaleZ);
    glVertex3f( 0.5 * scaleX, -0.5 * scaleY, -0.5 * scaleZ);

    glVertex3f( 0.5 * scaleX, -0.5 * scaleY, -0.5 * scaleZ);
    glVertex3f( 0.5 * scaleX,  0.5 * scaleY, -0.5 * scaleZ);

    glVertex3f( 0.5 * scaleX,  0.5 * scaleY, -0.5 * scaleZ);
    glVertex3f(-0.5 * scaleX,  0.5 * scaleY, -0.5 * scaleZ);

    glVertex3f(-0.5 * scaleX,  0.5 * scaleY, -0.5 * scaleZ);
    glVertex3f(-0.5 * scaleX, -0.5 * scaleY, -0.5 * scaleZ);

    // connecting lines
    glVertex3f(-0.5 * scaleX, -0.5 * scaleY,  0.5 * scaleZ);
    glVertex3f(-0.5 * scaleX, -0.5 * scaleY, -0.5 * scaleZ);

    glVertex3f( 0.5 * scaleX, -0.5 * scaleY,  0.5 * scaleZ);
    glVertex3f( 0.5 * scaleX, -0.5 * scaleY, -0.5 * scaleZ);

    glVertex3f( 0.5 * scaleX,  0.5 * scaleY,  0.5 * scaleZ);
    glVertex3f( 0.5 * scaleX,  0.5 * scaleY, -0.5 * scaleZ);

    glVertex3f(-0.5 * scaleX,  0.5 * scaleY,  0.5 * scaleZ);
    glVertex3f(-0.5 * scaleX,  0.5 * scaleY, -0.5 * scaleZ);

    glEnd();
}

void DrawFingerSegment(float length, float width = 0.2f, float depth = 0.15f){
    glPushMatrix();
    glScalef(length, width, depth);
    DrawWireCube();
    glPopMatrix();
}

void Display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -7.0);

    glPushMatrix();

    // shoulder movement (gerakan bahu)
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    // upper arm (lengan atas)
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    // elbow movement (gerakan siku)
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    // rorearm (lengan bawah)
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    DrawWireCube();
    glPopMatrix();

    // wrist movement (gerakan pergelangan tangan)
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 1.0, 0.0, 0.0);

    // hand/palm (tangan/telapak)
    glPushMatrix();
    glTranslatef(0.6, 0.0, 0.0);
    glScalef(1.2, 0.2, 0.8);
    DrawWireCube();
    glPopMatrix();

    // thumb (jempol) - 3 segments
    glPushMatrix();
    glTranslatef(1.1, 0.0, 0.4);
    glRotatef((GLfloat)thumbBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.4);
    
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)thumbMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.3);
    
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)thumbTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.2);
    glPopMatrix();

    // index finger (telunjuk) - 3 segments
    glPushMatrix();
    glTranslatef(1.1, 0.0, 0.2);
    glRotatef((GLfloat)indexBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.5);
    
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)indexMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.4);
    
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)indexTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.3);
    glPopMatrix();

    // middle finger (jari tengah) - 3 segments
    glPushMatrix();
    glTranslatef(1.1, 0.0, 0.0);
    glRotatef((GLfloat)middleBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.6);
    
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef((GLfloat)middleMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.5);
    
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)middleTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.4);
    glPopMatrix();

    // ring finger (jari manis) - 3 segments
    glPushMatrix();
    glTranslatef(1.1, 0.0, -0.2);
    glRotatef((GLfloat)ringBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.5);
    
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)ringMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.4);
    
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)ringTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.3);
    glPopMatrix();

    // pinky (kelingking) - 3 segments
    glPushMatrix();
    glTranslatef(1.1, 0.0, -0.4);
    glRotatef((GLfloat)pinkyBase, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.4);
    
    glTranslatef(0.4, 0.0, 0.0);
    glRotatef((GLfloat)pinkyMid, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.3);
    
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)pinkyTip, 0.0, 0.0, 1.0);
    DrawFingerSegment(0.2);
    glPopMatrix();

    glPopMatrix();
}

void Reshape(GLFWwindow* window, int width, int height){
    if(height == 0 || width == 0){
        return;
    }

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width / (GLdouble)height, 0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(action == GLFW_PRESS || action == GLFW_REPEAT){
        switch(key){
            // shoulder controls
            case GLFW_KEY_S: shoulder = (shoulder + 5) % 360; break;
            case GLFW_KEY_W: shoulder = (shoulder - 5) % 360; break;

            // elbow controls
            case GLFW_KEY_E: elbow = (elbow + 5) % 180; break;
            case GLFW_KEY_Q: elbow = (elbow - 5) % 180; break;

            // wrist controls (limited to +/- 90 degrees)
            case GLFW_KEY_D: wrist = std::min(wrist + 5, 90); break;
            case GLFW_KEY_A: wrist = std::max(wrist - 5, -90); break;

            // thumb controls
            case GLFW_KEY_T: thumbBase = std::min(thumbBase + 3, 45); break;
            case GLFW_KEY_G: thumbBase = std::max(thumbBase - 3, -15); break;
            case GLFW_KEY_Y: thumbMid = std::min(thumbMid + 3, 45); break;
            case GLFW_KEY_H: thumbMid = std::max(thumbMid - 3, -15); break;
            case GLFW_KEY_U: thumbTip = std::min(thumbTip + 3, 45); break;
            case GLFW_KEY_J: thumbTip = std::max(thumbTip - 3, -15); break;

            // index finger controls
            case GLFW_KEY_I: indexBase = std::min(indexBase + 3, 45); break;
            case GLFW_KEY_K: indexBase = std::max(indexBase - 3, -15); break;
            case GLFW_KEY_O: indexMid = std::min(indexMid + 3, 45); break;
            case GLFW_KEY_L: indexMid = std::max(indexMid - 3, -15); break;
            case GLFW_KEY_P: indexTip = std::min(indexTip + 3, 45); break;
            case GLFW_KEY_SEMICOLON: indexTip = std::max(indexTip - 3, -15); break;

            // middle finger controls
            case GLFW_KEY_1: middleBase = std::min(middleBase + 3, 45); break;
            case GLFW_KEY_2: middleBase = std::max(middleBase - 3, -15); break;
            case GLFW_KEY_3: middleMid = std::min(middleMid + 3, 45); break;
            case GLFW_KEY_4: middleMid = std::max(middleMid - 3, -15); break;
            case GLFW_KEY_5: middleTip = std::min(middleTip + 3, 45); break;
            case GLFW_KEY_6: middleTip = std::max(middleTip - 3, -15); break;

            // ring finger controls
            case GLFW_KEY_7: ringBase = std::min(ringBase + 3, 45); break;
            case GLFW_KEY_8: ringBase = std::max(ringBase - 3, -15); break;
            case GLFW_KEY_9: ringMid = std::min(ringMid + 3, 45); break;
            case GLFW_KEY_0: ringMid = std::max(ringMid - 3, -15); break;
            case GLFW_KEY_MINUS: ringTip = std::min(ringTip + 3, 45); break;
            case GLFW_KEY_EQUAL: ringTip = std::max(ringTip - 3, -15); break;

            // pinky controls
            case GLFW_KEY_Z: pinkyBase = std::min(pinkyBase + 3, 45); break;
            case GLFW_KEY_X: pinkyBase = std::max(pinkyBase - 3, -15); break;
            case GLFW_KEY_C: pinkyMid = std::min(pinkyMid + 3, 45); break;
            case GLFW_KEY_V: pinkyMid = std::max(pinkyMid - 3, -15); break;
            case GLFW_KEY_B: pinkyTip = std::min(pinkyTip + 3, 45); break;
            case GLFW_KEY_N: pinkyTip = std::max(pinkyTip - 3, -15); break;

            case GLFW_KEY_ESCAPE: 
                glfwSetWindowShouldClose(window, true); 
                break;
        }
    }
}

int main(){
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1200, 480, "Animasi Tangan", NULL, NULL);
    if(!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(window, KeyCallback);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    Reshape(window, width, height);

    while(!glfwWindowShouldClose(window)){
        Display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}