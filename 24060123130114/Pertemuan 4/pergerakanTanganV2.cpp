#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

static int shoulder = 0, elbow = 0, wrist = 0;
static int fingerBase1 = 0, fingerUp1 = 0, fingerTip1 = 0;
static int fingerBase2 = 0, fingerUp2 = 0, fingerTip2 = 0;
static int fingerBase3 = 0, fingerUp3 = 0, fingerTip3 = 0;
static int fingerBase4 = 0, fingerUp4 = 0, fingerTip4 = 0;
static int thumbBase = 0, thumbUp = 0, thumbTip = 0;

void DrawWireCube() {
    glBegin(GL_LINES);
    glVertex3f(-0.5, -0.5, 0.5); 
    glVertex3f(0.5, -0.5, 0.5);

    glVertex3f(0.5, -0.5, 0.5); 
    glVertex3f(0.5, 0.5, 0.5);

    glVertex3f(0.5, 0.5, 0.5); 
    glVertex3f(-0.5, 0.5, 0.5);

    glVertex3f(-0.5, 0.5, 0.5); 
    glVertex3f(-0.5, -0.5, 0.5);
    
    glVertex3f(-0.5, -0.5, -0.5); 
    glVertex3f(0.5, -0.5, -0.5);

    glVertex3f(0.5, -0.5, -0.5); 
    glVertex3f(0.5, 0.5, -0.5);

    glVertex3f(0.5, 0.5, -0.5); 
    glVertex3f(-0.5, 0.5, -0.5);

    glVertex3f(-0.5, 0.5, -0.5); 
    glVertex3f(-0.5, -0.5, -0.5);
    
    glVertex3f(-0.5, -0.5, 0.5); 
    glVertex3f(-0.5, -0.5, -0.5);

    glVertex3f(0.5, -0.5, 0.5); 
    glVertex3f(0.5, -0.5, -0.5);

    glVertex3f(0.5, 0.5, 0.5); 
    glVertex3f(0.5, 0.5, -0.5);

    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    glEnd();
}

void DrawFinger(float xOffset, float yOffset, float zOffset, int baseAngle, int upAngle, int tipAngle, float length1, float length2, float length3) {
    glPushMatrix();
    
    glTranslatef(xOffset, yOffset, zOffset);
    glRotatef((GLfloat)baseAngle, 0.0, 0.0, 1.0);
    glTranslatef(length1/2, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(length1, 0.1, 0.1);
    DrawWireCube();
    glPopMatrix();
    
    glTranslatef(length1/2, 0.0, 0.0);
    glRotatef((GLfloat)upAngle, 0.0, 0.0, 1.0);
    glTranslatef(length2/2, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(length2, 0.1, 0.1);
    DrawWireCube();
    glPopMatrix();
    
    glTranslatef(length2/2, 0.0, 0.0);
    glRotatef((GLfloat)tipAngle, 0.0, 0.0, 1.0);
    glTranslatef(length3/2, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(length3, 0.1, 0.1);
    DrawWireCube();
    glPopMatrix();
    
    glPopMatrix();
}

void DrawThumb(float xOffset, float yOffset, float zOffset, int baseAngle, int upAngle, int tipAngle) {
    glPushMatrix();
    
    glTranslatef(xOffset, yOffset, zOffset);
    glRotatef((GLfloat)baseAngle, 0.0, 1.0, 1.0);
    glTranslatef(0.1, -0.05, 0.1);
    
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    DrawWireCube();
    glPopMatrix();
    
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)upAngle, 0.0, 1.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    DrawWireCube();
    glPopMatrix();
    
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)tipAngle, 0.0, 1.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    DrawWireCube();
    glPopMatrix();
    
    glPopMatrix();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -7.0);

    glPushMatrix();

    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 0.4);
    DrawWireCube();
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 0.4);
    DrawWireCube();
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.4, 0.6, 0.8);
    DrawWireCube();
    glPopMatrix();

    DrawFinger(0.2, 0.3, 0.3, fingerBase1, fingerUp1, fingerTip1, 0.4, 0.3, 0.2);  
    DrawFinger(0.2, 0.3, 0.1, fingerBase2, fingerUp2, fingerTip2, 0.5, 0.35, 0.25); 
    DrawFinger(0.2, 0.3, -0.1, fingerBase3, fingerUp3, fingerTip3, 0.45, 0.3, 0.2); 
    DrawFinger(0.2, 0.3, -0.3, fingerBase4, fingerUp4, fingerTip4, 0.35, 0.25, 0.15); 
    DrawThumb(0.0, 0.2, 0.4, thumbBase, thumbUp, thumbTip);

    glPopMatrix();
}

void Reshape(GLFWwindow* window, int width, int height) {
    if (height == 0 || width == 0) return;

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)width / (GLfloat)height, 0.5, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_S: 
                shoulder = (shoulder + 5) % 360; 
                    break;
            case GLFW_KEY_W: 
                shoulder = (shoulder - 5) % 360; 
                break;
            
            case GLFW_KEY_E: 
                elbow = (elbow + 5);
                if (elbow > 135) elbow = 135;
                break;
            case GLFW_KEY_Q: 
                elbow = (elbow - 5);
                if (elbow < 0) elbow = 0;
                break;
            
            case GLFW_KEY_D: 
                wrist = (wrist + 5);
                if (wrist > 90) wrist = 90;
                break;
            case GLFW_KEY_A: 
                wrist = (wrist - 5);
                if (wrist < -90) wrist = -90;
                break;
            
            case GLFW_KEY_1: 
                fingerBase1 = (fingerBase1 + 5);
                if (fingerBase1 > 90) fingerBase1 = 90;
                break;
            case GLFW_KEY_2: 
                fingerBase1 = (fingerBase1 - 5);
                if (fingerBase1 < 0) fingerBase1 = 0;
                break;
            case GLFW_KEY_3: 
                fingerUp1 = (fingerUp1 + 5);
                if (fingerUp1 > 90) fingerUp1 = 90;
                break;
            case GLFW_KEY_4: 
                fingerUp1 = (fingerUp1 - 5);
                if (fingerUp1 < 0) fingerUp1 = 0;
                break;
            case GLFW_KEY_5: 
                fingerTip1 = (fingerTip1 + 5);
                if (fingerTip1 > 45) fingerTip1 = 45;
                break;
            case GLFW_KEY_6: 
                fingerTip1 = (fingerTip1 - 5);
                if (fingerTip1 < 0) fingerTip1 = 0;
                break;
            
            case GLFW_KEY_7: 
                fingerBase2 = (fingerBase2 + 5);
                if (fingerBase2 > 90) fingerBase2 = 90;
                break;
            case GLFW_KEY_8: 
                fingerBase2 = (fingerBase2 - 5);
                if (fingerBase2 < 0) fingerBase2 = 0;
                break;
            case GLFW_KEY_9: 
                fingerUp2 = (fingerUp2 + 5);
                if (fingerUp2 > 90) fingerUp2 = 90;
                break;
            case GLFW_KEY_0: 
                fingerUp2 = (fingerUp2 - 5);
                if (fingerUp2 < 0) fingerUp2 = 0;
                break;
            case GLFW_KEY_MINUS: 
                fingerTip2 = (fingerTip2 + 5);
                if (fingerTip2 > 45) fingerTip2 = 45;
                break;
            case GLFW_KEY_EQUAL: 
                fingerTip2 = (fingerTip2 - 5);
                if (fingerTip2 < 0) fingerTip2 = 0;
                break;

            case GLFW_KEY_G: 
                fingerBase3 = (fingerBase3 + 5);
                if (fingerBase3 > 90) fingerBase3 = 90;
                break;
            case GLFW_KEY_H: 
                fingerBase3 = (fingerBase3 - 5);
                if (fingerBase3 < 0) fingerBase3 = 0;
                break;
            case GLFW_KEY_J: 
                fingerUp3 = (fingerUp3 + 5);
                if (fingerUp3 > 90) fingerUp3 = 90;
                break;
            case GLFW_KEY_K: 
                fingerUp3 = (fingerUp3 - 5);
                if (fingerUp3 < 0) fingerUp3 = 0;
                break;
            case GLFW_KEY_L: 
                fingerTip3 = (fingerTip3 + 5);
                if (fingerTip3 > 45) fingerTip3 = 45;
                break;
            case GLFW_KEY_SEMICOLON: 
                fingerTip3 = (fingerTip3 - 5);
                if (fingerTip3 < 0) fingerTip3 = 0;
                break;

            case GLFW_KEY_V: 
                fingerBase4 = (fingerBase4 + 5);
                if (fingerBase4 > 90) fingerBase4 = 90;
                break;
            case GLFW_KEY_B: 
                fingerBase4 = (fingerBase4 - 5);
                if (fingerBase4 < 0) fingerBase4 = 0;
                break;
            case GLFW_KEY_N: 
                fingerUp4 = (fingerUp4 + 5);
                if (fingerUp4 > 90) fingerUp4 = 90;
                break;
            case GLFW_KEY_M: 
                fingerUp4 = (fingerUp4 - 5);
                if (fingerUp4 < 0) fingerUp4 = 0;
                break;
            case GLFW_KEY_COMMA: 
                fingerTip4 = (fingerTip4 + 5);
                if (fingerTip4 > 45) fingerTip4 = 45;
                break;
            case GLFW_KEY_PERIOD: 
                fingerTip4 = (fingerTip4 - 5);
                if (fingerTip4 < 0) fingerTip4 = 0;
                break;
            
            case GLFW_KEY_T: 
                thumbBase = (thumbBase + 5);
                if (thumbBase > 70) thumbBase = 70;
                break;
            case GLFW_KEY_Y: 
                thumbBase = (thumbBase - 5);
                if (thumbBase < 0) thumbBase = 0;
                break;
            case GLFW_KEY_U: 
                thumbUp = (thumbUp + 5);
                if (thumbUp > 90) thumbUp = 90;
                break;
            case GLFW_KEY_I: 
                thumbUp = (thumbUp - 5);
                if (thumbUp < 0) thumbUp = 0;
                break;
            
            case GLFW_KEY_ESCAPE: 
                glfwSetWindowShouldClose(window, true); 
                break;
        }
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1000, 1000, "Wireframe Cube", NULL, NULL);
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