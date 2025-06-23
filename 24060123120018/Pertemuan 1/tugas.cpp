#include <GL/glew.h> 
#include <GLFW/glfw3.h> 
 
void segiempat1(float x, float y) { 
    glBegin(GL_QUADS); 
    glColor4f(1.0f, 1.0f, 1.0f, 0.3f); 
    glVertex2f(-0.15f + x, 0.15f + y); 
    glVertex2f(0.15f + x, 0.15f + y); 
    glVertex2f(0.15f + x, -0.15f + y); 
    glVertex2f(-0.15f + x, -0.15f + y); 
    glEnd(); 
    glFlush(); 
} 
void segiempat2(float x, float y) { 
    glBegin(GL_QUADS); 
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f); 
    glVertex2f(-0.15f + x, 0.15f + y); 
    glVertex2f(0.15f + x, 0.15f + y); 
    glVertex2f(0.15f + x, -0.15f + y); 
    glVertex2f(-0.15f + x, -0.15f + y); 
    glEnd(); 
    glFlush(); 
} 
 
int main() { 
    if (!glfwInit()) { 
        return -1; 
    } 
 
    GLFWwindow* window = glfwCreateWindow(670, 480, "Tugas Persegi", NULL, 
NULL); 
    if (!window) { 
        glfwTerminate(); 
        return -1; 
    } 
 
    glfwMakeContextCurrent(window); 
    glewExperimental = GL_TRUE; 
    if (glewInit() != GLEW_OK) { 
        return -1; 
    } 

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

 
    while (!glfwWindowShouldClose(window)) { 
        glClear(GL_COLOR_BUFFER_BIT); 
        // layer 1
        segiempat1(-0.80f, 0.80f); 
        segiempat1(-0.40f, 0.80f); 
        segiempat1(0.00f, 0.80f); 
        segiempat1(0.40f, 0.80f); 
        segiempat1(0.80f, 0.80f); 

        segiempat1(-0.80f, 0.40f); 
        segiempat1(-0.40f, 0.40f); 
        segiempat1(0.00f, 0.40f); 
        segiempat1(0.40f, 0.40f); 
        segiempat1(0.80f, 0.40f); 

        segiempat1(-0.80f, -0.00f); 
        segiempat1(-0.40f, -0.00f); 
        segiempat1(0.00f, -0.00f); 
        segiempat1(0.40f, -0.00f); 
        segiempat1(0.80f, -0.00f);

        segiempat1(-0.80f, -0.40f); 
        segiempat1(-0.40f, -0.40f); 
        segiempat1(0.00f, -0.40f); 
        segiempat1(0.40f, -0.40f); 
        segiempat1(0.80f, -0.40f); 

        segiempat1(-0.80f, -0.80f); 
        segiempat1(-0.40f, -0.80f); 
        segiempat1(0.00f, -0.80f); 
        segiempat1(0.40f, -0.80f); 
        segiempat1(0.80f, -0.80f); 

        // layer 2
        segiempat2(-0.60f, 0.60f); 
        segiempat2(-0.20f, 0.60f); 
        segiempat2(0.20f, 0.60f); 
        segiempat2(0.60f, 0.60f); 

        segiempat2(-0.60f, 0.20f); 
        segiempat2(-0.20f, 0.20f); 
        segiempat2(0.20f, 0.20f); 
        segiempat2(0.60f, 0.20f); 

        segiempat2(-0.60f, -0.20f); 
        segiempat2(-0.20f, -0.20f); 
        segiempat2(0.20f, -0.20f); 
        segiempat2(0.60f, -0.20f);

        segiempat2(-0.60f, -0.60f); 
        segiempat2(-0.20f, -0.60f); 
        segiempat2(0.20f, -0.60f); 
        segiempat2(0.60f, -0.60f); 

        // layer 3
        segiempat2(-0.40f, 0.40f); 
        segiempat2(-0.00f, 0.40f); 
        segiempat2(0.40f, 0.40f); 

        segiempat2(-0.40f, 0.00f); 
        segiempat2(-0.00f, 0.00f); 
        segiempat2(0.40f, 0.00f); 

        segiempat2(-0.40f, -0.40f); 
        segiempat2(-0.00f, -0.40f); 
        segiempat2(0.40f, -0.40f); 

        // layer 3
        segiempat2(-0.20f, 0.20f); 
        segiempat2(0.20f, 0.20f); 
       
        segiempat2(-0.20f, -0.20f); 
        segiempat2(0.20f, -0.20f); 

        // layer 4 
        segiempat2(-0.00f, 0.00f); 
         
 
        glfwSwapBuffers(window); 
        glfwPollEvents(); 
    } 
 
    glfwDestroyWindow(window); 
    glfwTerminate(); 
    return 0; 
}