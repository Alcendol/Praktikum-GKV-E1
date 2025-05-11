#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

#define PI 3.14f

float angle = 0.0f, deltaAngle = 0.0f, ratio;
float x = 5.0f, y = 10.0f, z = 40.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, w, h;
static int rotAngleX = 0, rotAngleY = 0, rotAngleZ = 0;
float posXBadan = 10, posXKotak = 0, posYBadan = 7, posYKotak = 6;
float rotTangan1 = 0.0f, rotTangan2 = 0.0f, rotTangan3 = 0.0f,
rotTangan4 = 0.0f;
int kick = 0, roll = 0, hit = 0, gerakTangan = 0, drop = 0, bring = 0,
grab = 0, tabrak = 0;
float jarak = 1;
GLUquadricObj *IDquadric;

const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void init(void) {
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    IDquadric = gluNewQuadric();
    gluQuadricNormals(IDquadric, GLU_SMOOTH);
    gluQuadricTexture(IDquadric, GL_TRUE);
}

void reshape(GLFWwindow* window, int w1, int h1) {
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void orientMe(float ang) {
    lx = sin(ang/10);
    lz = -cos(ang/10);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i) {
    x = x + i*(lx)*0.1f;
    z = z + i*(lz)*0.1f;
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_W: rotAngleX += 2; break;
            case GLFW_KEY_S: rotAngleX -= 2; break;
            case GLFW_KEY_A: rotAngleY += 2; break;
            case GLFW_KEY_D: rotAngleY -= 2; break;
            case GLFW_KEY_Q: rotAngleZ += 2; break;
            case GLFW_KEY_E: rotAngleZ -= 2; break;
            case GLFW_KEY_O:
                if (drop == 0) {
                    if (posXBadan > 4) {
                        posXBadan -= 1;
                        if (bring == 1) posXKotak -= 1;
                    }
                } 
                else {
                    if (posXBadan > posXKotak + 3) {
                        posXBadan -= 1;
                    }
                }
                break;
            case GLFW_KEY_P:
                posXBadan += 1;
                if (bring == 1) posXKotak += 1;
                break;
            case GLFW_KEY_G: gerakTangan = 1; break;
            case GLFW_KEY_T:
                if (posXBadan >= 8) {
                    drop = 1;
                    gerakTangan = 3;
                }
                break;
            case GLFW_KEY_SPACE:
                rotAngleX = rotAngleY = rotAngleZ = 0;
                posXBadan = 10; posXKotak = 0; posYBadan = 7; posYKotak = 6;
                rotTangan1 = rotTangan2 = rotTangan3 = rotTangan4 = kick = roll = gerakTangan = drop = hit = bring = grab = 0;
                break;
            case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GLFW_TRUE); break;
        }
    }
}

void specialKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_UP: deltaMove = 1; break;
            case GLFW_KEY_DOWN: deltaMove = -1; break;
            case GLFW_KEY_LEFT: deltaAngle = -0.01f; break;
            case GLFW_KEY_RIGHT: deltaAngle = 0.01f; break;
        }
    } 
    else if (action == GLFW_RELEASE) {
        switch (key) {
            case GLFW_KEY_UP: if (deltaMove > 0) deltaMove = 0; break;
            case GLFW_KEY_DOWN: if (deltaMove < 0) deltaMove = 0; break;
            case GLFW_KEY_LEFT: if (deltaAngle < 0.0f) deltaAngle = 0.0f; break;
            case GLFW_KEY_RIGHT: if (deltaAngle > 0.0f) deltaAngle = 0.0f; break;
        }
    }
}

void lighting() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void Grid() {
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 2;

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
    for (i = Z_MIN; i < Z_MAX; i += gap) {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for (i = X_MIN; i < X_MAX; i += gap) {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

void Grid2() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-50, 0, 50);
    glVertex3f(-50, 0, -50);
    glVertex3f(50, 0, -50);
    glVertex3f(50, 0, 50);
    glEnd();
}

void Balok(float panjang, float lebar, float tinggi) {
    glPushMatrix();
    float p = panjang/2;
    float l = lebar/2;
    float t = tinggi/2;

    glBegin(GL_QUADS);
    glVertex3f(-p, 0, l);
    glVertex3f(p, 0, l);
    glVertex3f(p, -t*2, l);
    glVertex3f(-p, -t*2, l);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-p, 0, -l);
    glVertex3f(p, 0, -l);
    glVertex3f(p, -t*2, -l);
    glVertex3f(-p, -t*2, -l);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-p, 0, -l);
    glVertex3f(p, 0, -l);
    glVertex3f(p, 0, l);
    glVertex3f(-p, 0, l);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-p, -t*2, -l);
    glVertex3f(p, -t*2, -l);
    glVertex3f(p, -t*2, l);
    glVertex3f(-p, -t*2, l);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-p, -t*2, -l);
    glVertex3f(-p, -t*2, l);
    glVertex3f(-p, 0, l);
    glVertex3f(-p, 0, -l);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(p, -t*2, -l);
    glVertex3f(p, -t*2, l);
    glVertex3f(p, 0, l);
    glVertex3f(p, 0, -l);
    glEnd();

    glPopMatrix();
}

void perubahKotak() {
    if (drop == 1 && grab == 1) {
        if (posYKotak >= 3) {
            posYKotak -= 0.01f;
        }
        if (posYKotak < 3) {
            bring = 0;
            hit = 0;
            grab = 0;
        }
    }
}

void pengubahTangan() {
    if (posXBadan != 4) {
        hit = 0;
    } 
    else {
        hit = 1;
    }
    
    if (hit == 1 && grab == 1) {
        bring = 1;
    }
    
    if (gerakTangan == 1) {
        if (rotTangan1 >= -90) {
            rotTangan1 -= 0.1f;
        }
        if (rotTangan1 < -90) {
            gerakTangan = 2;
        }
    }
        
    if (gerakTangan == 2) {
        if (rotTangan2 >= -90) {
            rotTangan2 -= 0.1f;
        }
        if (rotTangan2 < -90 && hit == 1) {
            grab = 1;
        }
    }
    
    if (gerakTangan == 3) {
        if (rotTangan2 <= 0) {
            rotTangan2 += 0.1f;
        }
        if (rotTangan2 > 0) {
            gerakTangan = 4;
        }
    }
    
    if (gerakTangan == 4) {
        if (rotTangan1 <= 0) {
            rotTangan1 += 0.1f;
        }
        if (rotTangan1 > 0) {
            gerakTangan = 0;
        }
    }
}

void Object() {
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.2f);
    glTranslatef(0, 3, 0);
    Balok(5, 5, 3);
    glPopMatrix();
    
    glPushMatrix();
    perubahKotak();
    glColor3f(0.8f, 0.3f, 0.3f);
    glTranslatef(posXKotak, posYKotak, 0);
    Balok(3, 3, 3);
    glPopMatrix();

    glPushMatrix();
    pengubahTangan();
    glColor3f(0.3f, 0.3f, 0.8f);
    glTranslatef(posXBadan, posYBadan, 0);
    Balok(3, 3, 7);

    glPushMatrix();
    glColor3f(0.2f, 0.5f, 0.2f);
    glTranslatef(0, -2, 2.5f);
    glRotatef(rotTangan1, 1, 0, 0);
    glRotatef(rotTangan2, 0, 0, 1);
    Balok(2, 2, 4);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2f, 0.5f, 0.2f);
    glTranslatef(0, -2, -2.5f);
    glRotatef(-rotTangan1, 1, 0, 0);
    glRotatef(rotTangan2, 0, 0, 1);
    Balok(2, 2, 4);
    glPopMatrix();

    glPopMatrix();
}

void display(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (deltaMove) moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }

    glPushMatrix();
    glRotated(rotAngleX + 10, 1, 0, 0);
    glRotated(rotAngleY, 0, 1, 0);
    glRotated(rotAngleZ, 0, 0, 1);

    Grid();
    Grid2();
    Object();

    glPopMatrix();

    glfwSwapBuffers(window);
}

int main(int argc, char **argv) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Grab", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetWindowSizeCallback(window, reshape);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    lighting();
    init();
    reshape(window, 640, 480);

    while (!glfwWindowShouldClose(window)) {
        display(window);
        glfwPollEvents();
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) deltaMove = 1;
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) deltaMove = -1;
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) deltaAngle = -0.01f;
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) deltaAngle = 0.01f;
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_RELEASE && deltaMove > 0) deltaMove = 0;
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_RELEASE && deltaMove < 0) deltaMove = 0;
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_RELEASE && deltaAngle < 0.0f) deltaAngle = 0.0f;
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_RELEASE && deltaAngle > 0.0f) deltaAngle = 0.0f;
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}