#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

float carPosX = 0.0f; // Posisi X mobil

void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i += 10) {
        float theta = i * M_PI / 180.0f;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}

void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawHalfCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Titik pusat

    for (int i = 0; i <= 180; i += 10) {
        float theta = i * M_PI / 180.0f;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }

    glEnd();
}

void drawTraffic(){
    // Tiang
    drawRectangle(-0.86f, 0.0f, -0.84f, 0.5f, 0.0f, 0.0f, 0.0f);
    drawRectangle(-0.9f, 0.35f, -0.8f, 0.7f, 0.0f, 0.0f, 0.0f);

    // Lampu
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(-0.85f, 0.64f, 0.04f);
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(-0.85f, 0.53f, 0.04f);
    glColor3f(0.6235f, 0.8745f, 0.3059f);
    drawCircle(-0.85f, 0.42f, 0.04f);
}


void drawTree(float x, float y) {
    // Batang pohon
    glColor3f(0.5f, 0.3f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.07f, y - 0.3f);
    glVertex2f(x + 0.07f, y - 0.3f);
    glVertex2f(x + 0.07f, y + 0.3f);
    glVertex2f(x - 0.07f, y + 0.3f);
    glEnd();

    // Daun pohon
    glColor3f(0.0f, 0.7f, 0.0f);
    drawCircle(x, y + 0.4f, 0.15f);
    drawCircle(x - 0.08f, y + 0.3f, 0.15f);
    drawCircle(x + 0.1f, y + 0.25f, 0.15f);
}

void drawRainbow(){
    // Pelangi
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah
    drawHalfCircle(0.27f, 0.5f, 0.45f);
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning
    drawHalfCircle(0.27f, 0.5f, 0.35f);
    glColor3f(0.6235f, 0.8745f, 0.3059f); // Warna hijau
    drawHalfCircle(0.27f, 0.5f, 0.25f);
    glColor3f(0.5f, 0.8f, 1.0f);
    drawHalfCircle(0.27f, 0.5f, 0.15f);

    // Awan
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.0f, 0.5f, 0.12f);
    drawCircle(-0.16f, 0.49f, 0.1f);
    drawCircle(0.53f, 0.5f, 0.12f);
    drawCircle(0.68f, 0.49f, 0.1f);
}

void drawCar() {
    glPushMatrix(); 
    glTranslatef(carPosX, -0.2f, 0.0f);

    // Body mobil
    drawRectangle(-0.45f, -0.1f, 0.45f, 0.2f, 0.85f, 0.85f, 0.45f);

    // Bagian atas mobil
    glColor3f(0.3f, 0.5f, 0.15f);
    drawHalfCircle(0.03f, 0.2f, 0.3f);

    // Kaca mobil
    glColor3f(0.85f, 0.85f, 0.85f);
    drawHalfCircle(0.03f, 0.23f, 0.2f);

    // Lampu depan
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(-0.37f, 0.1f, 0.05f);

    // Ban mobil
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.28f, -0.15f, 0.1f);
    drawCircle(0.28f, -0.15f, 0.1f);

    glPopMatrix(); // Kembalikan transformasi awal
}

void drawTriangle(float x1, float y1, 
    float x2, float y2, 
    float x3, float y3) {
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}


void drawGrass(float x, float y){
    drawTriangle(x - 0.03f, y, x + 0.03f, y, x, y + 0.1f);
    drawTriangle(x - 0.08f, y, x, y, x - 0.06f, y + 0.1f);
    drawTriangle(x, y, x + 0.08f, y, x + 0.06f, y + 0.1f);
}

void display(){
    // Rangit
    drawRectangle(-1.0f, 0.0f, 1.0f, 1.0f, 0.5f, 0.8f, 1.0f);

    // Jalan
    drawRectangle(-1.0f, -0.5f, 1.0f, 0.0f, 0.5f, 0.5f, 0.5f);
    drawRectangle(-0.95f, -0.15f, -0.6f, -0.05f, 1.0f, 1.0f, 1.0f);
    drawRectangle(-0.95f, -0.3f, -0.6f, -0.2f, 1.0f, 1.0f, 1.0f);
    drawRectangle(-0.95f, -0.45f, -0.6f, -0.35f, 1.0f, 1.0f, 1.0f);    

    // Rumput
    drawRectangle(-1.0f, -1.0f, 1.0f, -0.5f, 0.6235f, 0.8745f, 0.3059f);

    // Traffic Light
    drawTraffic();

    // Pelangi
    drawRainbow();

    // Mobil
    drawCar();

    // Pohon
    drawTree(0.75f, -0.5f);   
    
    // Rumput-rumput
    drawGrass(-0.75f, -0.75f);
    drawGrass(-0.25f, -0.85f);
    drawGrass(0.25f, -0.75f);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        carPosX += 0.001f;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        carPosX -= 0.001f;
    }
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Mobil", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT);
        display();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}