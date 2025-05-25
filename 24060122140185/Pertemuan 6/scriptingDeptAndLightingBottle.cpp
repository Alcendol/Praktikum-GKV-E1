/* Nama File : scriptingDeptAndLightingBottle.cpp
 * Pembuat   : Naufal Shafi Anwar
 * NIM       : 24060122140185
 * Tanggal   : 30 April 2025 
 * Lab       : GKV E1
 */

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Bottle and camera variables
float bottlePosX = 0.0f, bottlePosY = 0.0f, bottlePosZ = -2.0f;
float camAngle = 0.0f; 
float camDistance = 7.0f; 
float camHeight = 3.0f; 

// Texture IDs
GLuint bottleTextureID;

// Lighting variables
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void createBottleTexture() {
    const int width = 512;
    const int height = 512;
    unsigned char* data = (unsigned char*)malloc(width * height * 3);
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            
            // Bottle label in the middle
            if(y > height * 0.3 && y < height * 0.7) {
                if(x > width * 0.1 && x < width * 0.9) {
                    data[index] = 220;   // R
                    data[index+1] = 240; // G
                    data[index+2] = 255; // B
                    
                    if((y % 30) == 10 && x > width * 0.15 && x < width * 0.85) {
                        data[index] = 100;   // R
                        data[index+1] = 100; // G
                        data[index+2] = 150; // B
                    }
                    
                    if(x < width * 0.15 || x > width * 0.85) {
                        data[index] = 180;   // R
                        data[index+1] = 200; // G
                        data[index+2] = 220; // B
                    }
                    
                    int centerX = width/2;
                    int centerY = height/2;
                    int dx = x - centerX;
                    int dy = y - centerY;
                    float distance = sqrt(dx*dx + dy*dy);
                    if(distance < 50) {
                        data[index] = 30;    // R
                        data[index+1] = 100; // G
                        data[index+2] = 200; // B
                    }
                } else {
                    // Bottle edge transparency
                    data[index] = 240;   // R
                    data[index+1] = 240; // G
                    data[index+2] = 250; // B
                }
            } else {
                data[index] = 240;   // R
                data[index+1] = 240; // G
                data[index+2] = 250; // B
                
                if((x + y) % 7 == 0) {
                    data[index] = 230;   // R
                    data[index+1] = 230; // G
                    data[index+2] = 240; // B
                }
            }
        }
    }
    
    glGenTextures(1, &bottleTextureID);
    glBindTexture(GL_TEXTURE_2D, bottleTextureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    free(data);
}

// Cylinder drawing helper function with texture coordinates
void drawCylinder(float radius, float height, int segments, bool useTexture) {
    float x, y, z;
    float angle, texX, texY;
    
    if(useTexture) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, bottleTextureID);
    }
    
    // Draw the cylinder walls (sides)
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        angle = i * 2.0f * M_PI / segments;
        x = radius * cos(angle);
        z = radius * sin(angle);
        texX = (float)i / segments;
        
        // Bottom vertex
        glTexCoord2f(texX, 0.0f);
        glVertex3f(x, 0.0f, z);
        
        // Top vertex
        glTexCoord2f(texX, 1.0f);
        glVertex3f(x, height, z);
    }
    glEnd();
    
    // Draw the top circle
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, height, 0.0f);
    for (int i = 0; i <= segments; i++) {
        angle = i * 2.0f * M_PI / segments;
        x = radius * cos(angle);
        z = radius * sin(angle);
        texX = 0.5f + 0.5f * cos(angle);
        texY = 0.5f + 0.5f * sin(angle);
        glTexCoord2f(texX, texY);
        glVertex3f(x, height, z);
    }
    glEnd();
    
    // Draw the bottom circle
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    for (int i = segments; i >= 0; i--) {
        angle = i * 2.0f * M_PI / segments;
        x = radius * cos(angle);
        z = radius * sin(angle);
        texX = 0.5f + 0.5f * cos(angle);
        texY = 0.5f + 0.5f * sin(angle);
        glTexCoord2f(texX, texY);
        glVertex3f(x, 0.0f, z);
    }
    glEnd();
    
    if(useTexture) {
        glDisable(GL_TEXTURE_2D);
    }
}

void setupCamera(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)width / (float)height;
    gluPerspective(45.0f, ratio, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Calculate camera position based on bottle position and angle
    float camX = bottlePosX - sin(camAngle) * camDistance;
    float camZ = bottlePosZ - cos(camAngle) * camDistance;
    float camY = bottlePosY + camHeight;
    gluLookAt(camX, camY, camZ, bottlePosX, bottlePosY, bottlePosZ, 0.0f, 1.0f, 0.0f);
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

void drawWaterBottle() {
    glPushMatrix();
    glTranslatef(bottlePosX, bottlePosY, bottlePosZ);
    
    // Bottle dimensions
    const float bottleRadius = 0.4f;
    const float bodyHeight = 2.0f;
    const float neckHeight = 0.3f;
    const float neckRadius = 0.2f;
    const float capHeight = 0.2f;
    const float waterLevel = bodyHeight * 0.75f; // Water fills 3/4 of the bottle
    const int segments = 32;
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // the blue water inside
    glDisable(GL_LIGHTING); 
    glColor4f(0.0f, 0.4f, 0.9f, 0.9f); 
    
    // Water
    glPushMatrix();
    glTranslatef(0.0f, 0.05f, 0.0f);
    drawCylinder(bottleRadius * 0.95f, waterLevel, segments, false);
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    
    // Bottle body
    glColor4f(0.9f, 0.9f, 0.9f, 0.5f);
    drawCylinder(bottleRadius, bodyHeight, segments, true);
    glColor4f(1.0f, 1.0f, 1.0f, 0.15f);
    glBegin(GL_QUADS);
    glVertex3f(-bottleRadius*0.5f, bodyHeight*0.1f, bottleRadius*0.8f);
    glVertex3f(-bottleRadius*0.3f, bodyHeight*0.9f, bottleRadius*0.8f);
    glVertex3f(bottleRadius*0.3f, bodyHeight*0.9f, bottleRadius*0.8f);
    glVertex3f(bottleRadius*0.5f, bodyHeight*0.1f, bottleRadius*0.8f);
    glEnd();
    
    // The neck of the bottle
    glPushMatrix();
    glTranslatef(0.0f, bodyHeight, 0.0f);
    glColor4f(0.9f, 0.9f, 0.9f, 0.6f);
    drawCylinder(neckRadius, neckHeight, segments, true);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, bodyHeight + neckHeight, 0.0f);
    glColor4f(0.0f, 0.2f, 0.8f, 1.0f);
    drawCylinder(neckRadius + 0.02f, capHeight, segments, false);
    glPopMatrix();
    
    glColor4f(0.95f, 0.95f, 0.95f, 0.2f);
    const float indent1 = bodyHeight * 0.2f;
    const float indent2 = bodyHeight * 0.5f;
    const float indent3 = bodyHeight * 0.8f;
    const float indentDepth = bottleRadius * 0.05f;
    
    // Three indentation rings
    glPushMatrix();
    glTranslatef(0.0f, indent1, 0.0f);
    drawCylinder(bottleRadius - indentDepth, 0.05f, segments, false);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, indent2, 0.0f);
    drawCylinder(bottleRadius - indentDepth, 0.05f, segments, false);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, indent3, 0.0f);
    drawCylinder(bottleRadius - indentDepth, 0.05f, segments, false);
    glPopMatrix();
    
    // Water surface
    glDisable(GL_LIGHTING);
    glColor4f(0.0f, 0.5f, 1.0f, 0.9f);
    glPushMatrix();
    glTranslatef(0.0f, waterLevel, 0.0f);
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); // Center
    for (int i = 0; i <= segments; i++) {
        float angle = i * 2.0f * M_PI / segments;
        float x = bottleRadius * 0.95f * cos(angle);
        float z = bottleRadius * 0.95f * sin(angle);
        glVertex3f(x, 0.0f, z);
    }
    glEnd();
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glDisable(GL_BLEND);
    
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
    createBottleTexture();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    setupCamera(width, height);
}

void processInput(GLFWwindow* window) {
    static float moveSpeed = 0.1f;
    static float rotateSpeed = 0.05f;
    
    // Bottle movement (relative to camera view)
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        bottlePosX -= sin(camAngle) * moveSpeed;
        bottlePosZ -= cos(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        bottlePosX += sin(camAngle) * moveSpeed;
        bottlePosZ += cos(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        bottlePosX -= cos(camAngle) * moveSpeed;
        bottlePosZ += sin(camAngle) * moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        bottlePosX += cos(camAngle) * moveSpeed;
        bottlePosZ -= sin(camAngle) * moveSpeed;
    }

    // Camera rotation around the bottle
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
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Textured Water Bottle", NULL, NULL);
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

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        // Render
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update camera (automatically follows the bottle)
        setupCamera(width, height);
        
        // Draw scene
        Grid();
        drawWaterBottle();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
