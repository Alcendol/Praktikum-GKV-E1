#include <GL/glew.h>
#include <GLFW/glfw3.h>

void garis(){
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.2f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, -0.2f, 0.0f);
    glEnd();
}

int main(){
    if (!glfwInit()){
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "Garis", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK){
        return -1;
    }

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);        
        
        garis();
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}