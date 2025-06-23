#include <GL/glew.h>
#include <GLFW/glfw3.h>

void triangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.10f, -0.10f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.10f, -0.10f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.00f, 0.10f, 0.0f);
    glEnd();
}

   int main() {
        if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "Titik", NULL,
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

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        triangle();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
        
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
       