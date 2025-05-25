/* Nama File : quadStrip.cpp
 * Deskripsi : program sederhana menggunakan GL_TRIANGLE_FAN untuk membuat daun teratai dari kumpulan segitiga yang salah satu titik sudutnya berada pada titik yang sama
 * Pembuat   : Shopia Mudjahidah
 * NIM       : 24060123120010
 * Tanggal   : 10 Maret 2025 
 * Lab       : GKV E1
 */

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void triangleFan() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f, 0.7f, 0.5f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.6f);
    glVertex2f(0.8f, 0.4f);
    glVertex2f(0.8f, -0.1f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, -0.7f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.8f, -0.1f);
    glVertex2f(-0.8f, 0.4f);
    glVertex2f(-0.5f, 0.6f);
    glEnd();
}

int main(){
    if(!glfwInit()){
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Triangle Fan", NULL, NULL);
    if(!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        return -1;
    } 

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        triangleFan();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
