/* Nama File : KubusBertingkat.cpp
 * Deskripsi : program sederhana menggunakan GL_QUADS untuk membuat kubus bertingkat
 * Pembuat   : Shopia Mudjahidah
 * NIM       : 24060123120010
 * Tanggal   : 10 Maret 2025 
 * Lab       : GKV E1
 */

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;
const float CUBE_SIZE = 0.15f;
const float SPACING = 0.03f;

void kubus(float x, float y, float r, float g, float b){
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(x, y);
    glVertex2f(x + CUBE_SIZE, y);
    glVertex2f(x + CUBE_SIZE, y - CUBE_SIZE);
    glVertex2f(x, y - CUBE_SIZE);
    glEnd();
}

void kubusBertingkat(){
    float startY = 0.6f;
    int rows[] = {1, 2, 3, 4, 3, 2, 1};
    int totalRows = sizeof(rows) / sizeof(rows[0]);

    for(int row = 0; row < totalRows; row++){
        int cubesInRow = rows[row];
        float startX = - (cubesInRow * (CUBE_SIZE + SPACING)) / 2 + SPACING / 2;

        for(int col = 0; col < cubesInRow; col++){
            float x = startX + col * (CUBE_SIZE + SPACING);
            float y = startY - row * (CUBE_SIZE + SPACING);
            
            float r = 0.8f + 0.05f * row; 
            float g = 0.6f + 0.02f * col; 
            float b = 1.0f - 0.05f * row;

            kubus(x, y, r, g, b);
        }
    }
}

int main(){
    if(!glfwInit()){
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Kubus Bertingkat", NULL, NULL);
    if(!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        return -1;
    }

    glOrtho(-1, 1, -1, 1, -1, 1);

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        kubusBertingkat();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}