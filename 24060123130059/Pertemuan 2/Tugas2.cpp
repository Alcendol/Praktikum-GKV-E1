#include <GL/glew.h>
#include <GLFW/glfw3.h>

void ketupatKuning() {
    float y = 0.2f; 
    float xOffset = 0.3f;

    for (int i = 0; i < 4; i++) {
        // Ketupat tengah
        glPushMatrix();
        glTranslatef(0.0f, y, 0.0f);
        glBegin(GL_QUADS);
            glColor3f(0.9f, 1.0f, 0.4f); 
            glVertex2f(0.0f, 0.15f);
            glVertex2f(0.15f, 0.0f);
            glVertex2f(0.0f, -0.15f);
            glVertex2f(-0.15f, 0.0f);
        glEnd();
        glPopMatrix();

        if (i == 1 || i == 2) {
            // Ketupat kiri
            glPushMatrix();
            glTranslatef(-xOffset, y, 0.0f);
            glBegin(GL_QUADS);
                glColor3f(0.9f, 1.0f, 0.4f);
                glVertex2f(0.0f, 0.15f);
                glVertex2f(0.15f, 0.0f);
                glVertex2f(0.0f, -0.15f);
                glVertex2f(-0.15f, 0.0f);
            glEnd();
            glPopMatrix();

            // Ketupat kanan
            glPushMatrix();
            glTranslatef(xOffset, y, 0.0f);
            glBegin(GL_QUADS);
                glColor3f(0.9f, 1.0f, 0.4f);
                glVertex2f(0.0f, 0.15f);
                glVertex2f(0.15f, 0.0f);
                glVertex2f(0.0f, -0.15f);
                glVertex2f(-0.15f, 0.0f);
            glEnd();
            glPopMatrix();
        }

        y -= 0.3f;  
    }
}

void ketupatHijau() {
    float xOffset = 0.15f; 
    float yHijau[] = {0.05f, -0.25f, -0.55f}; 

    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(-xOffset, yHijau[i], 0.0f);
        glBegin(GL_QUADS);
            glColor3f(0.0f, 0.7f, 0.2f); 
            glVertex2f(0.0f, 0.15f);
            glVertex2f(0.15f, 0.0f);
            glVertex2f(0.0f, -0.15f);
            glVertex2f(-0.15f, 0.0f);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(xOffset, yHijau[i], 0.0f);
        glBegin(GL_QUADS);
            glColor3f(0.0f, 0.7f, 0.2f);
            glVertex2f(0.0f, 0.15f);
            glVertex2f(0.15f, 0.0f);
            glVertex2f(0.0f, -0.15f);
            glVertex2f(-0.15f, 0.0f);
        glEnd();
        glPopMatrix();
    }

    float xUjung = 0.45f; 
    float yUjung = -0.25f; 

    glPushMatrix();
    glTranslatef(-xUjung, yUjung, 0.0f);
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.2f);
        glVertex2f(0.0f, 0.15f);
        glVertex2f(0.15f, 0.0f);
        glVertex2f(0.0f, -0.15f);
        glVertex2f(-0.15f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xUjung, yUjung, 0.0f);
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.2f);
        glVertex2f(0.0f, 0.15f);
        glVertex2f(0.15f, 0.0f);
        glVertex2f(0.0f, -0.15f);
        glVertex2f(-0.15f, 0.0f);
    glEnd();
    glPopMatrix();
}

void pitaKetupat() {
    // Pita hijau atas
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 0.0f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, 2.0f);
        glVertex2f(0.15f, 2.0f);
        glVertex2f(0.15f, 0.15f);
        glVertex2f(-0.15f, 0.15f);
    glEnd();
    glPopMatrix();

    // Pita hijau bawah
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 0.0f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, -2.0f);
        glVertex2f(0.15f, -2.0f);
        glVertex2f(0.15f, -0.15f);
        glVertex2f(-0.15f, -0.15f);
    glEnd();
    glPopMatrix();

    // Segitiga di bawah pita
    glPushMatrix();
    glColor3f(0.96f, 0.77f, 0.41f); 
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.15f, -1.5f); 
        glVertex2f(0.15f, -1.5f);  
        glVertex2f(0.0f, -1.0f);   
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.96f, 0.77f, 0.41f); 
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, -2.0f);
        glVertex2f(0.15f, -2.0f);
        glVertex2f(0.15f, -1.5f);
        glVertex2f(-0.15f, -1.5f);
    glEnd();
    glPopMatrix();

}

void gambarKetupat(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(0.75f, 0.75f, 1.0f);
    pitaKetupat();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(0.75f, 0.75f, 1.0f);
    ketupatKuning();
    ketupatHijau();
    glPopMatrix();
}

void background() {
    glBegin(GL_QUADS);
    
    glColor3f(0.99f, 0.92f, 0.70f);  
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);

    glColor3f(0.96f, 0.77f, 0.41f); 
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    background();
    
    gambarKetupat(0.0f, 0.0f);
    gambarKetupat(-0.6f, 0.5f);
    gambarKetupat(0.6f, 0.5f);

    glFlush();
}


int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(640, 480, "Ketupat", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) return -1;

    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}