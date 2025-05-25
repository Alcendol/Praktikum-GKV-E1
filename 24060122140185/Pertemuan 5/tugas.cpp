// Dept dan Lighting
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

// Box and camera variables
float boxPosX = 0.0f, boxPosY = 0.0f, boxPosZ = 0.0f;
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

    glColor3f(0.5f, 0.5f, 0.0f);
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

void drawRing(float outerRadius, float innerRadius, int sides, int rings) {
    // outerRadius: radius luar cincin
    // innerRadius: radius penampang cincin (ketebalan)
    // sides: jumlah segmen dalam penampang cincin
    // rings: jumlah segmen melingkar

    const float PI = 3.14159265358979323846f;
    float ringDelta = 2.0f * PI / float(rings);
    float sideDelta = 2.0f * PI / float(sides);
    
    float theta = 0.0f;
    for (int i = 0; i < rings; i++) {
        float theta1 = theta + ringDelta;
        float cosTheta = cos(theta);
        float sinTheta = sin(theta);
        float cosTheta1 = cos(theta1);
        float sinTheta1 = sin(theta1);
        
        glBegin(GL_QUAD_STRIP);
        float phi = 0.0f;
        for (int j = 0; j <= sides; j++) {
            phi = j * sideDelta;
            float cosPhi = cos(phi);
            float sinPhi = sin(phi);
            float dist = outerRadius + innerRadius * cosPhi;
            
            // Warna berdasarkan posisi untuk efek visual
            float colorR = (sinTheta + 1.0f) / 2.0f;
            float colorG = (cosTheta + 1.0f) / 2.0f;
            float colorB = (sinPhi + 1.0f) / 2.0f;
            
            glColor3f(colorR, colorG, colorB);
            
            // Titik pertama
            float x = cosTheta * dist;
            float y = -sinTheta * dist;
            float z = innerRadius * sinPhi;
            glVertex3f(x, y, z);
            
            // Titik kedua
            x = cosTheta1 * dist;
            y = -sinTheta1 * dist;
            z = innerRadius * sinPhi;
            glVertex3f(x, y, z);
        }
        glEnd();
        
        theta = theta1;
    }
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

void framebuffer_size_callback(GLFWwindow* window, int width, int
height) {
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
    GLFWwindow* window = glfwCreateWindow(800, 600, "Box with Following Camera", NULL, NULL);
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
        glPushMatrix();
        glTranslatef(0.0f, 0.7f, 0.7f); 
        drawRing(0.7f, 0.4f, 15, 10);
        glPopMatrix();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
