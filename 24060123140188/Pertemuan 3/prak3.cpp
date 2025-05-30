//Nama: Retno Eka Triatry
//Nim: 24060123140188
//tanggal: 19 Maret 2025

#include <GLUT/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, wrist = 0;
static int thumbBase = 0, thumbTop = 0;
static int indexBase = 0, indexMiddle = 0, indexTop = 0;
static int middleBase = 0, middleMiddle = 0, middleTop = 0;
static int ringBase = 0, ringMiddle = 0, ringTop = 0;
static int pinkyBase = 0, pinkyMiddle = 0, pinkyTop = 0;

GLfloat creamColor[] = {0.96, 0.87, 0.7, 1.0};

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Background putih
    glShadeModel(GL_FLAT);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
}

// Fungsi untuk menggambar jari
void drawFinger(float length, float width) {
    glPushMatrix();
    glColor4fv(creamColor);
    glScalef(length, width, width);
    glutSolidCube(1.0);  // Menggunakan solid cube untuk fill in
    glColor3f(0.0, 0.0, 0.0);  // Outline hitam untuk kontras
    glutWireCube(1.0);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    
    // Posisikan dan gambar bahu
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glColor4fv(creamColor);
    glScalef(2.0, 0.4, 1.0);
    glutSolidCube(1.0);  // Menggunakan solid cube untuk lengan
    glColor3f(0.0, 0.0, 0.0);  // Outline hitam
    glutWireCube(1.0);
    glPopMatrix();
    
    // Posisikan dan gambar siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glColor4fv(creamColor);
    glScalef(2.0, 0.4, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Posisikan dan gambar pergelangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    
    // Telapak tangan
    glPushMatrix();
    glColor4fv(creamColor);
    glScalef(1.0, 0.8, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Gambar ibu jari (posisi di bawah telapak)
    glPushMatrix();
    glTranslatef(-0.35, -0.4, 0.0);
    glRotatef(-90.0, 0.0, 0.0, 1.0); // Orientasi dasar ibu jari
    glRotatef((GLfloat)thumbBase, 1.0, 0.0, 0.0); // Rotasi pada sumbu X
    glTranslatef(0.0, 0.25, 0.0);
    
    // Ruas pertama ibu jari
    drawFinger(0.5, 0.2);
    
    // Ruas kedua ibu jari
    glTranslatef(0.0, 0.25, 0.0);
    glRotatef((GLfloat)thumbTop, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.15, 0.0);
    drawFinger(0.3, 0.15);
    glPopMatrix();
    
    // Gambar jari telunjuk
    glPushMatrix();
    glTranslatef(0.5, 0.3, 0.0);
    glRotatef((GLfloat)indexBase, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    
    // Ruas pertama jari telunjuk
    drawFinger(0.5, 0.15);
    
    // Ruas kedua jari telunjuk
    glTranslatef(0.25, 0.0, 0.0);
    glRotatef((GLfloat)indexMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    drawFinger(0.3, 0.15);
    
    // Ruas ketiga jari telunjuk
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)indexTop, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    drawFinger(0.2, 0.15);
    glPopMatrix();
    
    // Gambar jari tengah
    glPushMatrix();
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)middleBase, 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);
    
    // Ruas pertama jari tengah
    drawFinger(0.6, 0.15);
    
    // Ruas kedua jari tengah
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)middleMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    drawFinger(0.4, 0.15);
    
    // Ruas ketiga jari tengah
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)middleTop, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    drawFinger(0.2, 0.15);
    glPopMatrix();
    
    // Gambar jari manis
    glPushMatrix();
    glTranslatef(0.5, -0.1, 0.0);
    glRotatef((GLfloat)ringBase, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    
    // Ruas pertama jari manis
    drawFinger(0.5, 0.15);
    
    // Ruas kedua jari manis
    glTranslatef(0.25, 0.0, 0.0);
    glRotatef((GLfloat)ringMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    drawFinger(0.3, 0.15);
    
    // Ruas ketiga jari manis
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)ringTop, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    drawFinger(0.2, 0.15);
    glPopMatrix();
    
    // Gambar jari kelingking
    glPushMatrix();
    glTranslatef(0.5, -0.3, 0.0);
    glRotatef((GLfloat)pinkyBase, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    
    // Ruas pertama jari kelingking
    drawFinger(0.4, 0.1);
    
    // Ruas kedua jari kelingking
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)pinkyMiddle, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    drawFinger(0.2, 0.1);
    
    // Ruas ketiga jari kelingking
    glTranslatef(0.1, 0.0, 0.0);
    glRotatef((GLfloat)pinkyTop, 0.0, 0.0, 1.0);
    glTranslatef(0.08, 0.0, 0.0);
    drawFinger(0.16, 0.1);
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Kontrol untuk bahu
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
            
        // Kontrol untuk siku
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
            
        // Kontrol untuk pergelangan
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5) % 360; break;
            
        // Kontrol untuk ibu jari
        case 't': thumbBase = (thumbBase + 5) % 90; break;
        case 'T': thumbBase = (thumbBase - 5) % 90; break;
        case 'y': thumbTop = (thumbTop + 5) % 90; break;
        case 'Y': thumbTop = (thumbTop - 5) % 90; break;
            
        // Kontrol untuk jari telunjuk
        case 'i': indexBase = (indexBase + 5) % 90; break;
        case 'I': indexBase = (indexBase - 5) % 90; break;
        case 'o': indexMiddle = (indexMiddle + 5) % 90; break;
        case 'O': indexMiddle = (indexMiddle - 5) % 90; break;
        case 'p': indexTop = (indexTop + 5) % 90; break;
        case 'P': indexTop = (indexTop - 5) % 90; break;
            
        // Kontrol untuk jari tengah
        case 'j': middleBase = (middleBase + 5) % 90; break;
        case 'J': middleBase = (middleBase - 5) % 90; break;
        case 'k': middleMiddle = (middleMiddle + 5) % 90; break;
        case 'K': middleMiddle = (middleMiddle - 5) % 90; break;
        case 'l': middleTop = (middleTop + 5) % 90; break;
        case 'L': middleTop = (middleTop - 5) % 90; break;
            
        // Kontrol untuk jari manis
        case 'u': ringBase = (ringBase + 5) % 90; break;
        case 'U': ringBase = (ringBase - 5) % 90; break;
        case 'v': ringMiddle = (ringMiddle + 5) % 90; break;
        case 'V': ringMiddle = (ringMiddle - 5) % 90; break;
        case 'b': ringTop = (ringTop + 5) % 90; break;
        case 'B': ringTop = (ringTop - 5) % 90; break;
            
        // Kontrol untuk jari kelingking
        case 'n': pinkyBase = (pinkyBase + 5) % 90; break;
        case 'N': pinkyBase = (pinkyBase - 5) % 90; break;
        case 'm': pinkyMiddle = (pinkyMiddle + 5) % 90; break;
        case 'M': pinkyMiddle = (pinkyMiddle - 5) % 90; break;
        case ',': pinkyTop = (pinkyTop + 5) % 90; break;
        case '<': pinkyTop = (pinkyTop - 5) % 90; break;
            
        case 27: exit(0); break; // ESC untuk keluar
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Animasi Lengan dengan Jari - Cream Color");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
