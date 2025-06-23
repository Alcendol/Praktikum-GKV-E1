/* Nama File : 2_mobil.cpp
 * Deskripsi : program sederhana untuk membuat mobil dan objek lainnya
 * Pembuat   : Shopia Mudjahidah
 * NIM       : 24060123120010
 * Tanggal   : 12 Maret 2025 
 * Lab       : GKV E1
 */

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void drawBackground(){
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f); // warna biru muda
    glClear(GL_COLOR_BUFFER_BIT);
    
    // gambar latar hijau
    glColor3f(0.5f, 0.8f, 0.3f); // warna hijau tua
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, 0.2f);
        glVertex2f(-1.0f, 0.2f);
    glEnd();
    
    // gambar jalan raya
    glColor3f(0.3f, 0.3f, 0.3f); // warna hitam agak abu
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.6f);
        glVertex2f(1.0f, -0.6f);
        glVertex2f(1.0f, -0.2f);
        glVertex2f(-1.0f, -0.2f);
    glEnd();
    
    // garis tengah jalan berbentuk strip persegi panjang
    glColor3f(1.0f, 1.0f, 1.0f); // warna putih
    glBegin(GL_QUADS);
    for(float i = -1.0f; i < 1.0f; i += 0.25f){
        glVertex2f(i, -0.38f);
        glVertex2f(i + 0.10f, -0.38f);
        glVertex2f(i + 0.10f, -0.42f);
        glVertex2f(i, -0.42f);
    }
    glEnd();
}

void drawRainbow(){
    float colors[8][3] = {
        {1.0f, 0.0f, 0.0f}, // merah
        {1.0f, 0.5f, 0.0f}, // oranye
        {1.0f, 1.0f, 0.0f}, // kuning
        {0.0f, 1.0f, 0.0f}, // hijau
        {0.0f, 0.0f, 1.0f}, // biru
        {0.3f, 0.0f, 0.5f}, // indigo
        {0.6f, 0.0f, 0.8f}, // ungu
        {0.53f, 0.81f, 0.98f} // biru langit
    };
    
    float radius = 0.75f;
    float centerX = -1.0f; // sebelah kiri bawah
    float centerY = 0.2f;
    float bandWidth = 0.09f; // ukuran setiap warna sama
    
    for(int i = 0; i < 8; i++){
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(centerX, centerY);
        for(int j = 0; j <= 180; j++){
            float angle = j * M_PI / 180;
            glVertex2f(centerX + radius * cos(angle), centerY + radius * sin(angle));
        }
        glEnd();
        radius -= bandWidth;
    }
}

void drawHouse(){
    // tembok rumah
    glColor3f(1.0f, 0.9f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(0.20f, -0.1f);
        glVertex2f(0.85f, -0.1f);
        glVertex2f(0.85f, 0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();
    
    // atap rumah
    glColor3f(0.6f, 0.3f, 0.2f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.15f, 0.3f);
        glVertex2f(0.90f, 0.3f);
        glVertex2f(0.525f, 0.55f);
    glEnd();
    
    // pintu rumah
    glColor3f(0.5f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.48f, -0.1f);
        glVertex2f(0.62f, -0.1f);
        glVertex2f(0.62f, 0.15f);
        glVertex2f(0.48f, 0.15f);
    glEnd();
    
    // jendela rumah
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.25f, 0.05f);
        glVertex2f(0.39f, 0.05f);
        glVertex2f(0.39f, 0.15f);
        glVertex2f(0.25f, 0.15f);
    glEnd();
}

void drawCar(){
    float carX = -0.3f; // posisi mobil di sumbu X
    float carY = -0.3f; // posisi mobil di jalan
    float scale = 1.2f; // ukuran mobil

    // badan mobil
    glColor3f(1.0f, 0.75f, 0.8f);
    glBegin(GL_QUADS);
        glVertex2f(carX - 0.4f * scale, carY);
        glVertex2f(carX + 0.3f * scale, carY);
        glVertex2f(carX + 0.3f * scale, carY + 0.15f * scale);
        glVertex2f(carX - 0.4f * scale, carY + 0.15f * scale);
    glEnd();

    // badan mobil atas 
    glColor3f(1.0f, 0.6f, 0.7f);
    glBegin(GL_QUADS);
        glVertex2f(carX - 0.3f * scale, carY + 0.15f * scale);
        glVertex2f(carX + 0.2f * scale, carY + 0.15f * scale);
        glVertex2f(carX + 0.15f * scale, carY + 0.3f * scale);
        glVertex2f(carX - 0.25f * scale, carY + 0.3f * scale);
    glEnd();
    
    // kaca mobil
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(carX - 0.25f * scale, carY + 0.16f * scale);
    glVertex2f(carX + 0.15f * scale, carY + 0.16f * scale);
    glVertex2f(carX + 0.1f * scale, carY + 0.28f * scale);
    glVertex2f(carX - 0.2f * scale, carY + 0.28f * scale);
    glEnd();

    // garis pembatas kaca
    glColor3f(1.0f, 0.6f, 0.7f);
    glBegin(GL_QUADS);
        glVertex2f(carX - 0.02f * scale, carY + 0.16f * scale);
        glVertex2f(carX + 0.02f * scale, carY + 0.16f * scale);
        glVertex2f(carX + 0.02f * scale, carY + 0.28f * scale);
        glVertex2f(carX - 0.02f * scale, carY + 0.28f * scale);
    glEnd();

    // gagang pintu
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(carX + 0.04f * scale, carY + 0.06f * scale);
        glVertex2f(carX + 0.07f * scale, carY + 0.06f * scale);
        glVertex2f(carX + 0.07f * scale, carY + 0.08f * scale);
        glVertex2f(carX + 0.04f * scale, carY + 0.08f * scale);
    glEnd();

    // lampu belakang
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < 360; i++){
        float angle = i * M_PI / 180;
        glVertex2f(carX - 0.38f * scale + 0.02f * scale * cos(angle), carY + 0.08f * scale + 0.02f * scale * sin(angle));
    }
    glEnd();

    // roda kiri depan
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < 360; i++){
        float angle = i * M_PI / 180;
        glVertex2f(carX - 0.25f * scale + 0.06f * scale * cos(angle), carY - 0.04f * scale + 0.06f * scale * sin(angle));
    }
    glEnd();

    // velg kiri depan
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < 360; i++){
        float angle = i * M_PI / 180;
        glVertex2f(carX - 0.25f * scale + 0.02f * scale * cos(angle), carY - 0.04f * scale + 0.02f * scale * sin(angle));
    }
    glEnd();

    // roda kanan belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < 360; i++){
        float angle = i * M_PI / 180;
        glVertex2f(carX + 0.15f * scale + 0.06f * scale * cos(angle), carY - 0.04f * scale + 0.06f * scale * sin(angle));
    }
    glEnd();

    // velg kanan belakang
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i < 360; i++){
        float angle = i * M_PI / 180;
        glVertex2f(carX + 0.15f * scale + 0.02f * scale * cos(angle), carY - 0.04f * scale + 0.02f * scale * sin(angle));
    }
    glEnd();
}

void drawTree(float x, float y, float scale){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.25f, 0.0f);
    glVertex2f(-0.05f, -0.3f);
    glVertex2f(0.05f, -0.3f);
    glVertex2f(0.05f, 0.0f);
    glVertex2f(-0.05f, 0.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.1f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.15f, 0.0f);
    glVertex2f(0.15f, 0.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.2f);
    glVertex2f(-0.15f, -0.1f);
    glVertex2f(0.15f, -0.1f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(-0.15f, -0.2f);
    glVertex2f(0.15f, -0.2f);
    glEnd();
    
    glPopMatrix();
}

void renderScene(){
    drawBackground();
    drawRainbow();
    drawHouse();
    drawCar();
    drawTree(0.35f, -0.55f, 1.3f);
    drawTree(0.75f, -0.55f, 1.3f);
    glFlush();
}

int main(){
    if(!glfwInit()){
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Mobil", NULL, NULL);
    if(!window){ 
        glfwTerminate(); return -1; 
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        return -1;
    }

    while(!glfwWindowShouldClose(window)){
        renderScene();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}