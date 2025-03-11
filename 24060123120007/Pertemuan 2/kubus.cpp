/*  
Nama      : Shofi Rasyida Nata  
NIM       : 24060123120007  
Lab       : GKV E1  
Deskripsi : Membuat tumpukan kubus berwarna dengan primitif.
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Menggambar kubus
void gambarKubus(float x, float y, float ukuran, float merah, float hijau, float biru) {
    glBegin(GL_QUADS);
    glColor3f(merah,hijau,biru);
    glVertex2f(x, y);
    glVertex2f(x + ukuran, y);
    glVertex2f(x + ukuran, y + ukuran);
    glVertex2f(x, y + ukuran);
    glColor3f(merah*0.8f, hijau*0.8f, biru*0.8f);
    glVertex2f(x, y);
    glVertex2f(x + ukuran, y);
    glVertex2f(x + ukuran, y - ukuran*0.2f);
    glVertex2f(x, y - ukuran*0.2f);
    glEnd();
}

//Tumpukan kubus
void gambarTumpukanKubus() {
    float ukuran = 0.12f; 
    float jarak = 0.03f;  
    int barisMaks = 4;    
    for (int tingkat = -barisMaks; tingkat <= barisMaks; tingkat++) {
        int jumlahBaris;
        if (tingkat < 0) {
            jumlahBaris = barisMaks+tingkat; 
        } else {
            jumlahBaris = barisMaks-tingkat; 
        }
        float offsetX = (ukuran+jarak) * jumlahBaris/-2.0f; 
        float merah = 1.0f;
        float hijau = 0.5f + 0.1f * (barisMaks-tingkat);
        float biru = 0.7f + 0.05f * (barisMaks-tingkat);
        for (int i = 0; i < jumlahBaris; i++) {
            float x = offsetX + i * (ukuran+jarak);
            float y = tingkat * (ukuran+jarak);
            gambarKubus(x, y, ukuran, merah, hijau, biru);
        }
    }
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "Tumpukan Kubus", NULL, NULL);
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
        glClear(GL_COLOR_BUFFER_BIT);
        gambarTumpukanKubus();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
