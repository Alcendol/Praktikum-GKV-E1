/* Nama File : quads.cpp
 * Deskripsi : program sederhana menggunakan GL_QUADS untuk membuat tiga buah persegi sembarang
 * Pembuat   : Shopia Mudjahidah
 * NIM       : 24060123120010
 * Tanggal   : 10 Maret 2025 
 * Lab       : GKV E1
 */

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void quads(){
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.3f, 0.5f);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.5f, 0.3f);

    glColor3f(0.3f, 0.7f, 0.2f);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.5f, -0.6f);
    glVertex2f(0.6f, -0.1f);
    glVertex2f(0.3f, 0.1f);

    glColor3f(0.2f, 0.5f, 0.8f);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.4f, 0.9f);
    glVertex2f(-0.1f, 0.8f);

    glEnd();
}

int main(){
    if(!glfwInit()){
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Quads", NULL, NULL);
    if(!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        return -1;
    } 

    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        quads();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
