/*  
Nama      : Shofi Rasyida Nata  
NIM       : 24060123120007  
Lab       : GKV E1  
Deskripsi : Membuat mobil sport dengan lingkungan gunung bersalju.
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float sudutRoda = 0.0f;

//Menggambar lingkaran
void gambarLingkaran(float pusatX, float pusatY, float radius, float r, float g, float b) {
    const int circlePoints = 100;
    
    glBegin(GL_POLYGON);
    glColor3f(r,g,b);
    
    for (int i=0; i<circlePoints; i++) {
        float angle =2.0f* M_PI*i/circlePoints;
        glVertex2f(pusatX+radius*cos(angle),pusatY + radius * sin(angle));
    }
    glEnd();
}

//Menggambar roda
void gambarRoda() {
    gambarLingkaran(0.0f, 0.0f, 0.1f, 0.2f, 0.2f, 0.2f);
    gambarLingkaran(0.0f, 0.0f, 0.1f * 0.7f, 0.7f, 0.7f, 0.7f);
    gambarLingkaran(0.0f, 0.0f, 0.1f * 0.2f, 0.4f, 0.4f, 0.4f);
    glColor3f(0.4f, 0.4f, 0.4f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++) {
        float sudut = 2.0f * M_PI * i / 8 + sudutRoda;
        float x = 0.0f + 0.1f * 0.7f * cos(sudut);
        float y = 0.0f + 0.1f * 0.7f * sin(sudut);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(x, y);
    }
    glEnd();
}

//Menggambar badan mobil
void gambarBadanMobil() {
    glColor3f(0.8f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.1f);  
    glVertex2f(0.5f, -0.1f);   
    glVertex2f(0.45f, 0.1f);   
    glVertex2f(-0.45f, 0.1f);  
    glEnd();
    
    //Kaca belakang dibuat miring soalnya mobil sport
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.2f, 0.1f);   
    glVertex2f(0.4f, 0.1f);   
    glVertex2f(0.2f, 0.2f);   
    glVertex2f(0.1f, 0.3f);  
    glEnd();
    
    //Garis tepi kaca belakang
    glColor3f(0.7f, 0.2f, 0.2f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.1f, 0.3f);
    glEnd();
    
    //Kaca depan
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, 0.1f); 
    glVertex2f(0.2f, 0.1f);    
    glVertex2f(0.1f, 0.3f); 
    glVertex2f(-0.1f, 0.3f);  
    glEnd();
    
    //Garis tepi kaca depan
    glColor3f(0.7f, 0.2f, 0.2f);
    glLineWidth(5.0f);  
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.1f, 0.3f);
    glVertex2f(-0.1f, 0.3f);
    glEnd();
    
    //Garis tepi lampu belakang
    glColor3f(0.7f, 0.2f, 0.2f); 
    glLineWidth(4.0f); 
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.44f, -0.07f);
    glVertex2f(0.49f, -0.07f);
    glVertex2f(0.49f, -0.02f);
    glVertex2f(0.44f, -0.02f);
    glEnd();
    
    //Lampu depan
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.49f, -0.07f); 
    glVertex2f(-0.44f, -0.07f); 
    glVertex2f(-0.44f, -0.02f); 
    glVertex2f(-0.49f, -0.02f); 
    glEnd();
    
    //Garis tepi lampu depan
    glColor3f(0.7f, 0.2f, 0.2f); 
    glLineWidth(4.0f); 
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.49f, -0.07f);
    glVertex2f(-0.44f, -0.07f);
    glVertex2f(-0.44f, -0.02f);
    glVertex2f(-0.49f, -0.02f);
    glEnd();
    
    //Gagang pintu dibuat hanya 1 (dilihat dri samping) karena mobil sport
    glColor3f(0.3f, 0.3f, 0.3f); 
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.03f);
    glVertex2f(0.2f, 0.03f);
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.1f, 0.05f);
    glEnd();
    
    //Garis tepi badan mobil
    glColor3f(0.6f, 0.1f, 0.1f); 
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(0.5f, -0.1f);
    glVertex2f(0.45f, 0.1f);
    glVertex2f(-0.45f, 0.1f);
    glEnd();
}

//Keseluruhan mobil
void gambarMobil() {
    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 0.0f);
    gambarBadanMobil();
    
    glPushMatrix();
    glTranslatef(-0.3f, -0.1f, 0.0f);
    gambarRoda();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.3f, -0.1f, 0.0f);
    gambarRoda();
    glPopMatrix();
    
    glPopMatrix();
}

//Menggambar awan
void gambarAwan() {
    //Awan 1
    glPushMatrix();
    glTranslatef(-0.6f, 0.6f, 0.0f);
    float ukuran1 = 0.1f;
    gambarLingkaran(0.0f, 0.0f, ukuran1, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f + ukuran1 * 0.7f, 0.0f, ukuran1 * 0.8f, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f - ukuran1 * 0.7f, 0.0f, ukuran1 * 0.8f, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f, 0.0f + ukuran1 * 0.5f, ukuran1 * 0.7f, 1.0f, 1.0f, 1.0f);
    glPopMatrix();
    
    //Awan 2
    glPushMatrix();
    glTranslatef(0.2f, 0.5f, 0.0f);
    float ukuran2 = 0.08f;
    gambarLingkaran(0.0f, 0.0f, ukuran2, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f + ukuran2 * 0.7f, 0.0f, ukuran2 * 0.8f, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f - ukuran2 * 0.7f, 0.0f, ukuran2 * 0.8f, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f, 0.0f + ukuran2 * 0.5f, ukuran2 * 0.7f, 1.0f, 1.0f, 1.0f);
    glPopMatrix();
    
    //Awan 3
    glPushMatrix();
    glTranslatef(-0.2f, 0.7f, 0.0f);
    float ukuran3 = 0.12f;
    gambarLingkaran(0.0f, 0.0f, ukuran3, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f + ukuran3 * 0.7f, 0.0f, ukuran3 * 0.8f, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f - ukuran3 * 0.7f, 0.0f, ukuran3 * 0.8f, 1.0f, 1.0f, 1.0f);
    gambarLingkaran(0.0f, 0.0f + ukuran3 * 0.5f, ukuran3 * 0.7f, 1.0f, 1.0f, 1.0f);
    glPopMatrix();
}

//Menggambar pohon
void gambarPohon() {
    //Pohon 1
    glPushMatrix();
    glTranslatef(-0.8f, -0.2f, 0.0f);
    float ukuran1 = 0.3f;
    
    //Batang pohon
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-ukuran1 * 0.05f, 0.0f);
    glVertex2f(ukuran1 * 0.05f, 0.0f);
    glVertex2f(ukuran1 * 0.05f, ukuran1 * 0.3f);
    glVertex2f(-ukuran1 * 0.05f, ukuran1 * 0.3f);
    glEnd();
    
    //Daun pohon
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    //bagian bawah
    glVertex2f(-ukuran1 * 0.2f, ukuran1 * 0.2f);
    glVertex2f(ukuran1 * 0.2f, ukuran1 * 0.2f);
    glVertex2f(0.0f, ukuran1 * 0.5f);
    //tengah
    glVertex2f(-ukuran1 * 0.15f, ukuran1 * 0.35f);
    glVertex2f(ukuran1 * 0.15f, ukuran1 * 0.35f);
    glVertex2f(0.0f, ukuran1 * 0.6f);
    //atas
    glVertex2f(-ukuran1 * 0.1f, ukuran1 * 0.5f);
    glVertex2f(ukuran1 * 0.1f, ukuran1 * 0.5f);
    glVertex2f(0.0f, ukuran1 * 0.7f);
    glEnd();
    glPopMatrix();
    
    // Pohon 2
    glPushMatrix();
    glTranslatef(0.8f, -0.2f, 0.0f);
    float ukuran2 = 0.25f;
    
    //Batang pohon
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-ukuran2 * 0.05f, 0.0f);
    glVertex2f(ukuran2 * 0.05f, 0.0f);
    glVertex2f(ukuran2 * 0.05f, ukuran2 * 0.3f);
    glVertex2f(-ukuran2 * 0.05f, ukuran2 * 0.3f);
    glEnd();
    
    //Daun pohon
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    //bagian bawah
    glVertex2f(-ukuran2 * 0.2f, ukuran2 * 0.2f);
    glVertex2f(ukuran2 * 0.2f, ukuran2 * 0.2f);
    glVertex2f(0.0f, ukuran2 * 0.5f);
    //tengah
    glVertex2f(-ukuran2 * 0.15f, ukuran2 * 0.35f);
    glVertex2f(ukuran2 * 0.15f, ukuran2 * 0.35f);
    glVertex2f(0.0f, ukuran2 * 0.6f);
    //atas
    glVertex2f(-ukuran2 * 0.1f, ukuran2 * 0.5f);
    glVertex2f(ukuran2 * 0.1f, ukuran2 * 0.5f);
    glVertex2f(0.0f, ukuran2 * 0.7f);
    glEnd();
    glPopMatrix();
    
    // Pohon 3
    glPushMatrix();
    glTranslatef(0.4f, -0.2f, 0.0f);
    float ukuran3 = 0.2f;
    
    //Batang pohon
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-ukuran3 * 0.05f, 0.0f);
    glVertex2f(ukuran3 * 0.05f, 0.0f);
    glVertex2f(ukuran3 * 0.05f, ukuran3 * 0.3f);
    glVertex2f(-ukuran3 * 0.05f, ukuran3 * 0.3f);
    glEnd();
    
    //Daun pohon
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    //bagian bawah
    glVertex2f(-ukuran3 * 0.2f, ukuran3 * 0.2f);
    glVertex2f(ukuran3 * 0.2f, ukuran3 * 0.2f);
    glVertex2f(0.0f, ukuran3 * 0.5f);
    //tengah
    glVertex2f(-ukuran3 * 0.15f, ukuran3 * 0.35f);
    glVertex2f(ukuran3 * 0.15f, ukuran3 * 0.35f);
    glVertex2f(0.0f, ukuran3 * 0.6f);
    //atas
    glVertex2f(-ukuran3 * 0.1f, ukuran3 * 0.5f);
    glVertex2f(ukuran3 * 0.1f, ukuran3 * 0.5f);
    glVertex2f(0.0f, ukuran3 * 0.7f);
    glEnd();
    glPopMatrix();
}

//Menggambar gunung
void gambarGunung() {
    //Gunung 1
    glPushMatrix();
    glTranslatef(-0.6f, -0.2f, 0.0f);
    float ukuran1 = 0.3f;
    
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-ukuran1, 0.0f);
    glVertex2f(ukuran1, 0.0f);
    glVertex2f(0.0f, ukuran1 * 1.5f);
    glEnd();
    
    //Salju di puncak gunung
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-ukuran1 * 0.2f, ukuran1 * 1.2f);
    glVertex2f(ukuran1 * 0.2f, ukuran1 * 1.2f);
    glVertex2f(0.0f, ukuran1 * 1.5f);
    glEnd();
    glPopMatrix();
    
    //Gunung 2
    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.0f);
    float ukuran2 = 0.4f;
    
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-ukuran2, 0.0f);
    glVertex2f(ukuran2, 0.0f);
    glVertex2f(0.0f, ukuran2 * 1.5f);
    glEnd();
    
    //Salju di puncak gunung
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-ukuran2 * 0.2f, ukuran2 * 1.2f);
    glVertex2f(ukuran2 * 0.2f, ukuran2 * 1.2f);
    glVertex2f(0.0f, ukuran2 * 1.5f);
    glEnd();
    glPopMatrix();
    
    //Gunung 3
    glPushMatrix();
    glTranslatef(0.6f, -0.2f, 0.0f);
    float ukuran3 = 0.25f;
    
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-ukuran3, 0.0f);
    glVertex2f(ukuran3, 0.0f);
    glVertex2f(0.0f, ukuran3 * 1.5f);
    glEnd();
    
    //Salju di puncak gunung
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-ukuran3 * 0.2f, ukuran3 * 1.2f);
    glVertex2f(ukuran3 * 0.2f, ukuran3 * 1.2f);
    glVertex2f(0.0f, ukuran3 * 1.5f);
    glEnd();
    glPopMatrix();
}

//Menggambar matahari
void gambarMatahari() {
    glPushMatrix();
    glTranslatef(0.7f, 0.7f, 0.0f);
    gambarLingkaran(0.0f, 0.0f, 0.1f, 1.0f, 0.8f, 0.0f);
    glPopMatrix();
}

//Menggambar jalanan
void gambarJalanan() {
    //Jalan
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(-1.0f, -0.2f);
    glEnd();
    
    //Garis jalan
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    for (float x = -1.0f; x < 1.0f; x += 0.2f) {
        glVertex2f(x, -0.35f);
        glVertex2f(x + 0.1f, -0.35f);
    }
    glEnd();
}

//Menggambar pemandangan
void gambarPemandangan() {
    //Langit
    glColor3f(0.4f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    
    //Rumput
    glColor3f(0.2f, 0.8f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();
    
    //Tanah
    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
    
    //Gunung
    gambarGunung();
    //Matahari
    gambarMatahari();
    //Awan
    gambarAwan();
    //Pohon
    gambarPohon();
    //Gambar jalanan
    gambarJalanan();
}

//Viewport untuk menyesuaikan dengan ukuran window
void sesuaikanViewport(GLFWwindow* window) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT); 
    //Gambar pemandangan
    gambarPemandangan();
    //Gambar mobil
    gambarMobil();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Mobil dan Environment", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    
    while (!glfwWindowShouldClose(window)) {
        sesuaikanViewport(window);
        renderScene();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}