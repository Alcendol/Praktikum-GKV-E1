#include <GL/glew.h>
#include <GLFW/glfw3.h>

void segiempat(float x, float y, float size, float r, float g, float b) {
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y - size);
    glVertex2f(x, y - size);
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 640, "Kubus Bertingkat", NULL, NULL);
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

        float size = 0.2f;
        float spacing = 0.03f;
        float startX = -0.3f;
        float startY = 0.5f;

        // Baris pertama (2 segiempat)
        for (int i = 0; i < 2; i++) {
            float x = startX + i * (size + spacing);
            float y = startY;
            segiempat(x, y, size, 1.0f, 1.0f, 0.0f);
        }

        // Baris kedua (3 segiempat)
        for (int i = 0; i < 3; i++) {
            float x = startX - (size / 2) + i * (size + spacing);
            float y = startY - size;
            segiempat(x, y, size, 1.0f, 0.5f, 0.0f);
        }

        // Baris ketiga (4 segiempat)
        for (int i = 0; i < 4; i++) {
            float x = startX - (2*size / 2) + i * (size + spacing);
            float y = startY - 2 * size;
            segiempat(x, y, size, 1.0f, 1.0f, 0.0f);
        }

        // Baris keempat (3 segiempat)
        for (int i = 0; i < 3; i++) {
            float x = startX - (size / 2) + i * (size + spacing);
            float y = startY - 3 * size;
            segiempat(x, y, size, 1.0f, 0.5f, 0.0f);
        }

        // Baris kelima (2 segiempat)
        for (int i = 0; i < 2; i++) {
            float x = startX + i * (size + spacing);
            float y = startY - 4 * size;
            segiempat(x, y, size, 1.0f, 1.0f, 0.0f);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
