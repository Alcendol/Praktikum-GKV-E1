#include <GL/glew.h>
#include <GLFW/glfw3.h>

void BadanRumah() {
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f); 
    glVertex2f(0.5f, -0.5f);  
    glVertex2f(0.5f, 0.1f);   
    glVertex2f(-0.5f, 0.1f);  
    glEnd();
}

void Atap() {
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.7f);
    glVertex2f(-0.6f, 0.1f);   
    glVertex2f(0.6f, 0.1f);   
    glEnd();
}

void Pintu() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.1f, -0.5f);  
    glVertex2f(-0.1f, -0.1f);  
    glVertex2f(0.1f, -0.5f);   
    glVertex2f(0.1f, -0.1f);  
    glEnd();
}

void Jendela() {
    glColor3f(0.4f, 0.7f, 1.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-0.4f, -0.1f);   
    glVertex2f(-0.4f, 0.0f);   
    glVertex2f(-0.2f, -0.1f);   
    glVertex2f(-0.2f, 0.0f);   
    glEnd();
}

void KacaJendela() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.4f, -0.05f);
    glVertex2f(-0.2f, -0.05f);
    glVertex2f(-0.3f, -0.05f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, -0.1f);
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(640, 480, "Rumah Sederhana", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    
    glClearColor(0.0f, 0.8f, 0.0f, 1.0f);
    
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        BadanRumah();   
        Atap();   
        Pintu();   
        Jendela();
        KacaJendela();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}