#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

void drawCircle(){
    const int circlePoints = 100;
    const float radius = 0.5f;
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f(0.0f, 0.0f); 
    
    for (int i = 0; i <= circlePoints; i++){
        float angle = 2.0f * M_PI * i / circlePoints;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}


int main(){
    if (!glfwInit()){
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 800, "Lingkaran", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    glewInit();

    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        drawCircle(); 

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
