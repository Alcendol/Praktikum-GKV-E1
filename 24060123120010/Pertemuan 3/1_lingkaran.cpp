/* Nama File : 1_lingkaran.cpp
 * Deskripsi : program sederhana untuk membuat objek lingkaran
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

void drawCircle(float radius, int circlePoints){
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= circlePoints; i++) {
        float angle = 2.0f * M_PI * i / circlePoints;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glScalef(1.0f, 1.0f, 1.0f);
    drawCircle(0.5f, 360);
    glPopMatrix();

    glFlush();
}

int main(){
    if(!glfwInit()){
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(800, 800, "Lingkaran", NULL, NULL);
    if(!window){
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    
    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        renderScene();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
