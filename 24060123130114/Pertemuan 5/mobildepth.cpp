#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Box and camera variables
float boxPosX = 0.0f, boxPosY = 0.8f, boxPosZ = 0.0f;
float camAngle = 0.0f; // Camera rotation around the box
float camDistance = 5.0f; // Distance from camera to box
float camHeight = 2.0f; // Height of camera relative to box

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
    // Calculate camera position based on box position and angle
    float camX = boxPosX - sin(camAngle) * camDistance;
    float camZ = boxPosZ - cos(camAngle) * camDistance;
    float camY = boxPosY + camHeight;
    // Look at the box
    gluLookAt(camX, camY, camZ,
        boxPosX, boxPosY, boxPosZ,
        0.0f, 1.0f, 0.0f);
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

void drawCube() {
    float s = 0.5f;

    glBegin(GL_QUADS);

    glNormal3f(0, 0, 1);
    glVertex3f(-s, -s, s);
    glVertex3f(s, -s, s);
    glVertex3f(s, s, s);
    glVertex3f(-s, s, s);

    glNormal3f(0, 0, -1);
    glVertex3f(-s, -s, -s);
    glVertex3f(-s, s, -s);
    glVertex3f(s, s, -s);
    glVertex3f(s, -s, -s);

    glNormal3f(0, 1, 0);
    glVertex3f(-s, s, -s);
    glVertex3f(-s, s, s);
    glVertex3f(s, s, s);
    glVertex3f(s, s, -s);

    glNormal3f(0, -1, 0);
    glVertex3f(-s, -s, -s);
    glVertex3f(s, -s, -s);
    glVertex3f(s, -s, s);
    glVertex3f(-s, -s, s);

    glNormal3f(1, 0, 0);
    glVertex3f(s, -s, -s);
    glVertex3f(s, s, -s);
    glVertex3f(s, s, s);
    glVertex3f(s, -s, s);

    glNormal3f(-1, 0, 0);
    glVertex3f(-s, -s, -s);
    glVertex3f(-s, -s, s);
    glVertex3f(-s, s, s);
    glVertex3f(-s, s, -s);

    glEnd();
}

void drawWheel(float radius, float width, int slices) {
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, 0, 1);
    glVertex3f(0.0f, 0.0f, width / 2.0f); 
    for (int i = 0; i <= slices; ++i) {
        float angle = 2.0f * M_PI * i / slices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex3f(x, y, width / 2.0f);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, 0, -1);
    glVertex3f(0.0f, 0.0f, -width / 2.0f);
    for (int i = 0; i <= slices; ++i) {
        float angle = 2.0f * M_PI * i / slices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex3f(x, y, -width / 2.0f);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; ++i) {
        float angle = 2.0f * M_PI * i / slices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glNormal3f(x, y, 0); 
        glVertex3f(x, y, width / 2.0f);
        glVertex3f(x, y, -width / 2.0f);
    }
    glEnd();
}

void drawCar() {
    glPushMatrix();
    glTranslatef(boxPosX, boxPosY, boxPosZ);

    //body
    glPushMatrix();
    glScalef(2.5f, 0.75f, 1.2f); 
    glColor3f(0.2f, 0.6f, 0.9f); 
    drawCube();
    glPopMatrix();

    //kap
    glPushMatrix();
    glTranslatef(1.0f, 0.3f, 0.0f);
    glScalef(0.8f, 0.4f, 1.1f);
    glColor3f(0.2f, 0.5f, 0.8f); 
    drawCube();
    glPopMatrix();

    //bagasi
    glPushMatrix();
    glTranslatef(-1.0f, 0.3f, 0.0f);
    glScalef(0.6f, 0.4f, 1.1f);
    glColor3f(0.2f, 0.5f, 0.8f);
    drawCube();
    glPopMatrix();

    //atap
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, 0.0f);
    glScalef(1.4f, 0.3f, 1.0f);
    glColor3f(0.2f, 0.5f, 0.8f); 
    drawCube();
    glPopMatrix();

    //kaca depan
    glPushMatrix();
    glTranslatef(0.7f, 0.65f, 0.0f);
    glScalef(0.01f, 0.25f, 0.9f);
    glColor3f(0.7f, 0.8f, 0.9f); 
    drawCube();
    glPopMatrix();

    //kaca belakang
    glPushMatrix();
    glTranslatef(-0.7f, 0.65f, 0.0f);
    glScalef(0.01f, 0.25f, 0.9f);
    glColor3f(0.7f, 0.8f, 0.9f);
    drawCube();
    glPopMatrix();

    //kaca kanan
    glPushMatrix();
    glTranslatef(0.0f, 0.65f, 0.5f);
    glScalef(1.3f, 0.25f, 0.01f);
    glColor3f(0.7f, 0.8f, 0.9f);
    drawCube();
    glPopMatrix();

    //kaca kiri
    glPushMatrix();
    glTranslatef(0.0f, 0.65f, -0.5f);
    glScalef(1.3f, 0.25f, 0.01f);
    glColor3f(0.7f, 0.8f, 0.9f);
    drawCube();
    glPopMatrix();

    //roda
    float wheelOffsetX = 0.9f, wheelOffsetZ = 0.6f;
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            glPushMatrix();
            glTranslatef(i * wheelOffsetX, -0.35f, j * wheelOffsetZ);
            glRotatef(0, 0, 1, 0);
            
            glColor3f(0.3f, 0.3f, 0.3f);
            drawWheel(0.25f, 0.15f, 24);
            
            glColor3f(0.1f, 0.1f, 0.1f);
            drawWheel(0.3f, 0.2f, 24);
            
            glColor3f(0.7f, 0.7f, 0.7f);
            drawWheel(0.1f, 0.16f, 12);
            
            glPopMatrix();
        }
    }

    //lampu depan
    glPushMatrix();
    glTranslatef(1.4f, 0.3f, 0.3f);
    glScalef(0.1f, 0.1f, 0.1f);
    glColor3f(0.9f, 0.9f, 0.7f);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4f, 0.3f, -0.3f);
    glScalef(0.1f, 0.1f, 0.1f);
    glColor3f(0.9f, 0.9f, 0.7f);
    drawCube();
    glPopMatrix();

    //lampu belakang
    glPushMatrix();
    glTranslatef(-1.3f, 0.3f, 0.3f);
    glScalef(0.1f, 0.1f, 0.1f);
    glColor3f(0.8f, 0.2f, 0.2f); 
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.3f, 0.3f, -0.3f);
    glScalef(0.1f, 0.1f, 0.1f);
    glColor3f(0.8f, 0.2f, 0.2f);
    drawCube();
    glPopMatrix();

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
    static float moveSpeed = 0.1f;
    static float rotateSpeed = 0.05f;

    // Box movement (relative to camera view)
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        boxPosX -= sin(camAngle) * moveSpeed;
        boxPosZ -= cos(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        boxPosX += sin(camAngle) * moveSpeed;
        boxPosZ += cos(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        boxPosX -= cos(camAngle) * moveSpeed;
        boxPosZ += sin(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        boxPosX += cos(camAngle) * moveSpeed;
        boxPosZ -= sin(camAngle) * moveSpeed;
    }

    // Camera rotation around the box
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        camAngle -= rotateSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        camAngle += rotateSpeed;
    }

    // Camera distance adjustment
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        camDistance += 0.1f;
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        camDistance = fmax(1.0f, camDistance - 0.1f);
    }

    // Camera height adjustment
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
        camHeight += 0.1f;
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
        camHeight -= 0.1f;
    }

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
    GLFWwindow* window = glfwCreateWindow(800, 600, "Car with Following Camera", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
        
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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
        // Update camera (automatically follows the box)
        setupCamera(width, height);
        // Draw scene
        Grid();
        drawCar();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
        
    glfwTerminate();
    return 0;
}