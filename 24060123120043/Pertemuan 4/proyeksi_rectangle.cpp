// Nama : Sophie Venecia May M
// Nim  : 24060123120043

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, -3.0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, -0.5, -3.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.5, 0.5, -3.0);
    glColor3f(0.0, 0.1, 0.1);
    glVertex3f(-0.5, 0.5, -3.0);
    glEnd();
}

void Reshape(GLFWwindow* window, int width, int height)
{
    if (height == 0) return;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width / (GLdouble)height, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main()
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Rectangle", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    Reshape(window, width, height);

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* win, int w, int h) {
        Reshape(win, w, h);
    });

    while (!glfwWindowShouldClose(window)) {
        Display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
