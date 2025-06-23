// Nama : Sophie Venecia May M
// Nim  : 24060123120043

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>

GLfloat xRotated = 0.0f, yRotated = 0.0f, zRotated = 0.0f;
static int shoulder = 0;
static int elbow = 0;
static int wrist = 0;
static int fingers[5] = {0, 0, 0, 0, 0};

void DrawWireCube() {
    glBegin(GL_LINES);
    float vertices[8][3] = {
        {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
        {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}
    };
    int edges[12][2] = {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };
    for (auto &edge : edges) {
        glVertex3fv(vertices[edge[0]]);
        glVertex3fv(vertices[edge[1]]);
    }
    glEnd();
}

void DrawFinger(float x, float y, float z, int angle) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef((GLfloat)angle, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    DrawWireCube();
    glPopMatrix();
    glPopMatrix();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0, -0.5, -8.0); 

    glPushMatrix();
    glTranslatef(-1.5, 0.0, 0.0); 
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
    
    glPushMatrix();
    glScalef(1.0, 0.3, 0.6);
    DrawWireCube();
    glPopMatrix();
    
    DrawFinger(0.4, 0.15, 0.2, fingers[0]); 
    DrawFinger(0.5, 0.2, 0.3, fingers[1]); 
    DrawFinger(0.5, 0.1, 0.3, fingers[2]); 
    DrawFinger(0.5, 0.0, 0.3, fingers[3]); 
    DrawFinger(0.5, -0.1, 0.3, fingers[4]); 
    
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
                elbow = std::min(elbow + 5, 135);
                break;
            case GLFW_KEY_Q:
                elbow = std::max(elbow - 5, 0);
                break;
            case GLFW_KEY_R:
                wrist = std::min(wrist + 5, 90);
                break;
            case GLFW_KEY_F:
                wrist = std::max(wrist - 5, -90);
                break;
            case GLFW_KEY_T:
                for (int i = 0; i < 5; i++) fingers[i] = std::min(fingers[i] + 5, 90);
                break;
            case GLFW_KEY_G:
                for (int i = 0; i < 5; i++) fingers[i] = std::max(fingers[i] - 5, 0);
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

    GLFWwindow* window = glfwCreateWindow(640, 480, "Robot Arm with Fingers", NULL, NULL);
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
