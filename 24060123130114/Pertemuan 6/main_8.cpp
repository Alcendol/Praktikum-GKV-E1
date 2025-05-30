#include <math.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

double rx = 0.0;
double ry = 0.0;
float l[] = { 0.0, 80.0, 0.0 };
float n[] = { 0.0, -40.0, 0.0 };
float e[] = { 0.0, -60.0, 0.0 };

void help() {
    printf("Shadow projection example using a cone object\n");
    printf("Controls:\n");
    printf("W/S - Move light up/down\n");
    printf("A/D - Move light left/right\n");
    printf("Q/E - Move light forward/backward\n");
    printf("ESC - Exit\n");
}

void draw() {
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluCylinder(quadric, 20.0, 0.0, 50.0, 40, 50);
    gluDeleteQuadric(quadric);
}

void glShadowProjection(float *l, float *e, float *n) {
    float d, c;
    float mat[16];
    d = n[0]*l[0] + n[1]*l[1] + n[2]*l[2];
    c = e[0]*n[0] + e[1]*n[1] + e[2]*n[2] - d;

    mat[0] = l[0]*n[0]+c;
    mat[4] = n[1]*l[0];
    mat[8] = n[2]*l[0];
    mat[12] = -l[0]*c-l[0]*d;
    mat[1] = n[0]*l[1];
    mat[5] = l[1]*n[1]+c;
    mat[9] = n[2]*l[1];
    mat[13] = -l[1]*c-l[1]*d;
    mat[2] = n[0]*l[2];
    mat[6] = n[1]*l[2];
    mat[10] = l[2]*n[2]+c;
    mat[14] = -l[2]*c-l[2]*d;
    mat[3] = n[0];
    mat[7] = n[1];
    mat[11] = n[2];
    mat[15] = -d;
    glMultMatrixf(mat);
}

void render() {
    glClearColor(0.0, 0.6, 0.9, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLightfv(GL_LIGHT0, GL_POSITION, l);
    
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex3f(l[0], l[1], l[2]);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-1300.0, e[1]-0.1, 1300.0);
    glVertex3f(1300.0, e[1]-0.1, 1300.0);
    glVertex3f(1300.0, e[1]-0.1, -1300.0);
    glVertex3f(-1300.0, e[1]-0.1, -1300.0);
    glEnd();

    glPushMatrix();
    glRotatef(ry, 0, 1, 0);
    glRotatef(rx, 1, 0, 0);
    glEnable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 0.8);
    draw();
    glPopMatrix();

    glPushMatrix();
    glShadowProjection(l, e, n);
    glRotatef(ry, 0, 1, 0);
    glRotatef(rx, 1, 0, 0);
    glDisable(GL_LIGHTING);
    glColor3f(0.4, 0.4, 0.4);
    draw();
    glPopMatrix();
}

void keypress(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
            case GLFW_KEY_S:
                l[1] -= 5.0;
                break;
            case GLFW_KEY_W:
                l[1] += 5.0;
                break;
            case GLFW_KEY_A:
                l[0] -= 5.0;
                break;
            case GLFW_KEY_D:
                l[0] += 5.0;
                break;
            case GLFW_KEY_Q:
                l[2] -= 5.0;
                break;
            case GLFW_KEY_E:
                l[2] += 5.0;
                break;
            case GLFW_KEY_H:
                help();
                break;
        }
    }
}

void idle(GLFWwindow* window) {
    rx += 0.1;
    ry += 0.1;
    render();
    glfwSwapBuffers(window);
}
    
void resize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, (float)width/(float)height, 1.0f, 400.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_SAMPLES, 4);
    GLFWwindow* window = glfwCreateWindow(400, 400, "Shadow Projection", NULL, NULL);
    
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keypress);
    glfwSetFramebufferSizeCallback(window, resize);
    
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    
    float lightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float lightDiffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, 1.0f, 1.0f, 400.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -150.0);

    help();
    
    while (!glfwWindowShouldClose(window)) {
        idle(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

