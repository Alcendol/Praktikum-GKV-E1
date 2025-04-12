/* Nama File : scriptingDeptAndLighting2.cpp
 * Pembuat   : Shopia Mudjahidah
 * NIM       : 24060123120010
 * Tanggal   : 9 April 2025 
 * Lab       : GKV E1
 */

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Camera and object variables
float boxPosX = 0.0f, boxPosY = 0.0f, boxPosZ = 0.0f;
float angle = 0.0f;
float camX = 0.0f, camY = 1.75f, camZ = 15.0f; // camera position
float camLX = 0.0f, camLY = 0.0f, camLZ = -1.0f; // look direction

// Lighting variables
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void setupCamera(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)width / (float)height;
    gluPerspective(45.0f, ratio, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, camX + camLX, camY + camLY, camZ + camLZ, 0.0f, 1.0f, 0.0f);
}

void updateCameraDirection() {
    camLX = sin(angle);
    camLZ = -cos(angle);
}

void moveCamera(float distance) {
    camX += distance * camLX;
    camZ += distance * camLZ;
}

void Grid() {
    const float size = 50.0f;
    const float gap = 1.5f;
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
    for(float i = -size; i <= size; i += gap) {
        // Horizontal lines
        glVertex3f(-size, 0.0f, i);
        glVertex3f(size, 0.0f, i);
        // Vertical lines
        glVertex3f(i, 0.0f, -size);
        glVertex3f(i, 0.0f, size);
    }
    glEnd();
}
void drawBox() {
    glPushMatrix();
    glTranslatef(boxPosX, boxPosY, boxPosZ);

    // Box size
    const float s = 3.0f;

    // Front face
    glBegin(GL_QUADS);
    glVertex3f(-s, -s, s);
    glVertex3f(s, -s, s);
    glVertex3f(s, s, s);
    glVertex3f(-s, s, s);
    glEnd();

    // Back face
    glBegin(GL_QUADS);
    glVertex3f(-s, -s, -s);
    glVertex3f(-s, s, -s);
    glVertex3f(s, s, -s);
    glVertex3f(s, -s, -s);
    glEnd();

    // Top face
    glBegin(GL_QUADS);
    glVertex3f(-s, s, -s);
    glVertex3f(-s, s, s);
    glVertex3f(s, s, s);
    glVertex3f(s, s, -s);
    glEnd();

    // Bottom face
    glBegin(GL_QUADS);
    glVertex3f(-s, -s, -s);
    glVertex3f(s, -s, -s);
    glVertex3f(s, -s, s);
    glVertex3f(-s, -s, s);
    glEnd();

    // Right face
    glBegin(GL_QUADS);
    glVertex3f(s, -s, -s);
    glVertex3f(s, s, -s);

    glVertex3f(s, s, s);
    glVertex3f(s, -s, s);
    glEnd();

    // Left face
    glBegin(GL_QUADS);
    glVertex3f(-s, -s, -s);
    glVertex3f(-s, -s, s);
    glVertex3f(-s, s, s);
    glVertex3f(-s, s, -s);
    glEnd();

    glPopMatrix();
}
void lighting() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    setupCamera(width, height);
}

void processInput(GLFWwindow* window) {
    static float moveSpeed = 0.2f;
    static float rotateSpeed = 0.05f;
    // Camera rotation
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        angle -= rotateSpeed;
        updateCameraDirection();
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        angle += rotateSpeed;
        updateCameraDirection();
    }

    // Camera movement
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        moveCamera(moveSpeed);
    }

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        moveCamera(-moveSpeed);
    }

    // Box movement
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) boxPosZ -= moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) boxPosZ += moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) boxPosX -= moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) boxPosX += moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) boxPosY -= moveSpeed;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) boxPosY += moveSpeed;

    // Exit
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // Configure GLFW window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Box Movement", NULL, NULL);

    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,
    framebuffer_size_callback);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    // Initialize OpenGL
    int width, height;

    glfwGetFramebufferSize(window, &width, &height);
    framebuffer_size_callback(window, width, height);

    lighting();
    init();
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Render
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update camera
        setupCamera(width, height);

        // Draw scene
        Grid();
        drawBox();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}