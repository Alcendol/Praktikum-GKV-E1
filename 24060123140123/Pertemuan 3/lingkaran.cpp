#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void lingkaran() {
    const int circlePoints = 100;
    const float radius = 0.3f;
    
    glColor3f(1.0f, 0.0f, 0.0f);
    
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circlePoints; i++) {
        float angle = 2.0f * M_PI * i / circlePoints;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    lingkaran();
    glPopMatrix();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "Lingkaran Merah", NULL, NULL);
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
        renderScene();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}