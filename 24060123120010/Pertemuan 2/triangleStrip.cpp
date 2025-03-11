/* Nama File : quadStrip.cpp
 * Deskripsi : program sederhana menggunakan GL_TRIANGLE_STRIP untuk membuat ikan dari kumpulan segitiga
 * Pembuat   : Shopia Mudjahidah
 * NIM       : 24060123120010
 * Tanggal   : 10 Maret 2025 
 * Lab       : GKV E1
 */

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void triangleStrip() {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.2f, 0.6f, 1.0f);
    glVertex2f(-0.8f, 0.2f);
    glVertex2f(-0.8f, -0.2f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.8f, 0.5f);
    glVertex2f(0.8f, -0.5f);
    glEnd();
}

int main(){
    if(!glfwInit()){
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(600, 600, "Triangle Strip", NULL, NULL);
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
        triangleStrip();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
