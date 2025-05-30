#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <GL/freeglut_std.h>

void initLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightPos[] = { 10.0f, 10.0f, 10.0f, 1.0f };
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void drawCube(float x, float y, float z, float width, float height, float depth) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, depth);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawCar() {
    // Body
    glColor3f(0.8f, 0.1f, 0.1f);  // Red
    drawCube(0, 0.5, 0, 2.0f, 0.5f, 1.0f);

    // Top cabin
    glColor3f(0.6f, 0.1f, 0.1f);  // Dark red
    drawCube(0, 0.9, 0, 1.0f, 0.4f, 0.8f);

    // Wheels
    glColor3f(0.1f, 0.1f, 0.1f);  // Black
    drawCube(-0.9f, 0.2f, 0.5f, 0.4f, 0.4f, 0.4f);
    drawCube( 0.9f, 0.2f, 0.5f, 0.4f, 0.4f, 0.4f);
    drawCube(-0.9f, 0.2f, -0.5f, 0.4f, 0.4f, 0.4f);
    drawCube( 0.9f, 0.2f, -0.5f, 0.4f, 0.4f, 0.4f);
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Mobil 3D", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();
    glEnable(GL_DEPTH_TEST);
    initLighting();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(4, 3, 6, 0, 0.5, 0, 0, 1, 0);

        drawCar();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
