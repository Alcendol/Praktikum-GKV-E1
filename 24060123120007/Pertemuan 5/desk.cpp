/*
Nama: Shofi Rasyida Nata
NIM: 24060123120007
LAB: GKV E1
Deskripsi: Membuat meja kerja
*/

#define GLFW_INCLUDE_NONE 
#include <GLFW/glfw3.h> 
#include <GL/glew.h> 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 

//deklarasi fungsi
void drawBookend(float width, float height, float depth, float r, float g, float b);
void drawBookshelf();
 
//desk dan camera
float deskPosX = 0.0f, deskPosY = 0.0f, deskPosZ = 0.0f; 
float camAngle = 0.0f; 
float camDistance = 7.0f; 
float camHeight = 3.0f; 
 
//lighting
const GLfloat light_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f }; 
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 0.9f, 1.0f }; 
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_position[] = { 5.0f, 15.0f, 10.0f, 1.0f }; 
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f }; 
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat high_shininess[] = { 80.0f }; 
const GLfloat light2_ambient[] = { 0.2f, 0.2f, 0.3f, 1.0f };
const GLfloat light2_diffuse[] = { 0.5f, 0.5f, 0.7f, 1.0f };
const GLfloat light2_specular[] = { 0.5f, 0.5f, 0.7f, 1.0f };
const GLfloat light2_position[] = { -10.0f, 8.0f, -5.0f, 1.0f };
 
void setupCamera(int width, int height) { 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    float ratio = (float)width / (float)height; 
    gluPerspective(45.0f, ratio, 0.1f, 1000.0f); 
    
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    
    float camX = deskPosX - sin(camAngle) * camDistance; 
    float camZ = deskPosZ - cos(camAngle) * camDistance; 
    float camY = deskPosY + camHeight; 
    
    gluLookAt(camX, camY, camZ, 
              deskPosX, deskPosY + 1.5f, deskPosZ, 
              0.0f, 1.0f, 0.0f); 
} 
 
void Grid() { 
    const float size = 50.0f; 
    const float gap = 1.5f; 
    
    glDisable(GL_LIGHTING);
    glColor3f(0.4f, 0.4f, 0.4f); 
    glBegin(GL_LINES); 
    for(float i = -size; i <= size; i += gap) { 
        glVertex3f(-size, 0.0f, i); 
        glVertex3f(size, 0.0f, i); 
        glVertex3f(i, 0.0f, -size); 
        glVertex3f(i, 0.0f, size); 
    } 
    glEnd(); 
    glEnable(GL_LIGHTING);
} 

void drawCuboid(float width, float height, float depth, float r, float g, float b) {
    glColor3f(r, g, b);
    
    float w = width / 2.0f;
    float h = height / 2.0f;
    float d = depth / 2.0f;
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-w, -h, d);
    glVertex3f(w, -h, d);
    glVertex3f(w, h, d);
    glVertex3f(-w, h, d);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-w, -h, -d);
    glVertex3f(-w, h, -d);
    glVertex3f(w, h, -d);
    glVertex3f(w, -h, -d);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-w, h, -d);
    glVertex3f(-w, h, d);
    glVertex3f(w, h, d);
    glVertex3f(w, h, -d);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-w, -h, -d);
    glVertex3f(w, -h, -d);
    glVertex3f(w, -h, d);
    glVertex3f(-w, -h, d);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(w, -h, -d);
    glVertex3f(w, h, -d);
    glVertex3f(w, h, d);
    glVertex3f(w, -h, d);
    glEnd();
    
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-w, -h, -d);
    glVertex3f(-w, -h, d);
    glVertex3f(-w, h, d);
    glVertex3f(-w, h, -d);
    glEnd();
}

//kaki meja
void drawLeg(float radius, float height, float r, float g, float b) {
    const int segments = 20;
    const float angleStep = 2.0f * M_PI / segments;
    
    glColor3f(r, g, b);
    
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = i * angleStep;
        float x = radius * cosf(angle);
        float z = radius * sinf(angle);
        
        float nx = cosf(angle);
        float nz = sinf(angle);
        
        glNormal3f(nx, 0.0f, nz);
        glVertex3f(x, 0.0f, z);
        glVertex3f(x, height, z);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, height, 0.0f);  // Center
    for (int i = 0; i <= segments; i++) {
        float angle = i * angleStep;
        glVertex3f(radius * cosf(angle), height, radius * sinf(angle));
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);  
    for (int i = segments; i >= 0; i--) {
        float angle = i * angleStep;
        glVertex3f(radius * cosf(angle), 0.0f, radius * sinf(angle));
    }
    glEnd();
}

//buku
void drawBook(float width, float height, float thickness, float r, float g, float b) {
    drawCuboid(width, thickness, height, r, g, b);
}

//laptop
void drawLaptop() {
    glPushMatrix();
    drawCuboid(1.2f, 0.1f, 0.8f, 0.3f, 0.3f, 0.3f);

    glPushMatrix();
    glTranslatef(0.0f, 0.05f + 0.4f, -0.3f);
    glRotatef(-75.0f, 1.0f, 0.0f, 0.0f);
    drawCuboid(1.2f, 0.02f, 0.8f, 0.2f, 0.2f, 0.2f);
    
    glPushMatrix();
    glTranslatef(0.0f, 0.012f, 0.0f);
    drawCuboid(1.0f, 0.01f, 0.7f, 0.1f, 0.1f, 0.3f);
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();
}

//lampu
void drawLamp() {
    glPushMatrix();
    drawCuboid(0.3f, 0.05f, 0.3f, 0.2f, 0.2f, 0.2f);
    
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(-30.0f, 1.0f, 0.0f, 0.0f);
    drawCuboid(0.05f, 0.4f, 0.05f, 0.3f, 0.3f, 0.3f);
    
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(60.0f, 1.0f, 0.0f, 0.0f);
    drawCuboid(0.05f, 0.4f, 0.05f, 0.3f, 0.3f, 0.3f);
    
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.1f);
    glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
    drawCuboid(0.25f, 0.1f, 0.25f, 0.4f, 0.4f, 0.1f);
    
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    
    const int segments = 10;
    const float radius = 0.08f;
    glColor3f(1.0f, 1.0f, 0.7f);
    
    for (int lat = 0; lat < segments; lat++) {
        float theta1 = lat * M_PI / segments;
        float theta2 = (lat + 1) * M_PI / segments;
        
        glBegin(GL_TRIANGLE_STRIP);
        for (int lon = 0; lon <= segments; lon++) {
            float phi = lon * 2 * M_PI / segments;
            
            float x1 = radius * sin(theta1) * cos(phi);
            float y1 = radius * cos(theta1);
            float z1 = radius * sin(theta1) * sin(phi);
            glNormal3f(x1, y1, z1);
            glVertex3f(x1, y1, z1);
            
            float x2 = radius * sin(theta2) * cos(phi);
            float y2 = radius * cos(theta2);
            float z2 = radius * sin(theta2) * sin(phi);
            glNormal3f(x2, y2, z2);
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }
    
    glPopMatrix(); 
    glPopMatrix(); 
    glPopMatrix(); 
    glPopMatrix(); 
    glPopMatrix();
}

void drawOrganizer() {
    drawCuboid(0.6f, 0.1f, 0.3f, 0.5f, 0.3f, 0.1f);
    
    //wadah bolpoin
    glPushMatrix();
    glTranslatef(0.2f, 0.2f, 0.0f);
    drawCuboid(0.15f, 0.3f, 0.15f, 0.5f, 0.3f, 0.1f);
    
    //bolpoin
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.0f);
    drawCuboid(0.02f, 0.25f, 0.02f, 0.1f, 0.1f, 0.8f); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.04f, 0.08f, 0.02f);
    drawCuboid(0.02f, 0.22f, 0.02f, 0.8f, 0.1f, 0.1f); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.03f, 0.12f, -0.03f);
    drawCuboid(0.02f, 0.28f, 0.02f, 0.1f, 0.8f, 0.1f); 
    glPopMatrix();
    
    glPopMatrix(); 
    
    //wadah kertas
    glPushMatrix();
    glTranslatef(-0.15f, 0.15f, 0.0f);
    drawCuboid(0.25f, 0.2f, 0.2f, 0.5f, 0.3f, 0.1f);
    
    //kertas
    glPushMatrix();
    glTranslatef(0.0f, 0.12f, 0.0f);
    drawCuboid(0.2f, 0.02f, 0.15f, 0.9f, 0.9f, 0.9f); 
    glPopMatrix();
    
    glPopMatrix(); 
}

//pembatas buku
void drawBookend(float width, float height, float depth, float r, float g, float b) {
    GLfloat metal_ambient[] = { r*0.5f, g*0.5f, b*0.5f, 1.0f };
    GLfloat metal_diffuse[] = { r, g, b, 1.0f };
    GLfloat metal_specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat metal_shininess[] = { 70.0f };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, metal_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, metal_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, metal_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, metal_shininess);
    
    glPushMatrix();
    drawCuboid(width, height*0.1f, depth, r, g, b);
    
    glPushMatrix();
    glTranslatef(0.0f, height*0.45f, 0.0f);
    drawCuboid(width, height*0.9f, depth*0.2f, r, g, b);
    glPopMatrix();
    
    glPopMatrix();
}

void drawStudyDesk() { 
    glPushMatrix(); 
    glTranslatef(deskPosX, deskPosY, deskPosZ); 
    
    GLfloat wood_ambient[] = { 0.3f, 0.2f, 0.1f, 1.0f };
    GLfloat wood_diffuse[] = { 0.6f, 0.4f, 0.2f, 1.0f };
    GLfloat wood_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat wood_shininess[] = { 30.0f };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, wood_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wood_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wood_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, wood_shininess);
    
    drawCuboid(4.0f, 0.1f, 2.0f, 0.6f, 0.4f, 0.2f);
    
    glPushMatrix();
    glTranslatef(1.7f, -1.0f, 0.7f);
    drawLeg(0.1f, 1.0f, 0.5f, 0.35f, 0.18f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.7f, -1.0f, -0.7f);
    drawLeg(0.1f, 1.0f, 0.5f, 0.35f, 0.18f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.7f, -1.0f, 0.7f);
    drawLeg(0.1f, 1.0f, 0.5f, 0.35f, 0.18f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.7f, -1.0f, -0.7f);
    drawLeg(0.1f, 1.0f, 0.5f, 0.35f, 0.18f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0f, -0.5f, 0.0f);
    drawCuboid(1.0f, 0.8f, 1.8f, 0.55f, 0.37f, 0.18f);
    
    GLfloat metal_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat metal_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat metal_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat metal_shininess[] = { 100.0f };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, metal_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, metal_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, metal_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, metal_shininess);
    
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.7f);
    drawCuboid(0.1f, 0.03f, 0.3f, 0.8f, 0.8f, 0.8f);
    glPopMatrix();
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, wood_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wood_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wood_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, wood_shininess);
    glPopMatrix();

    //laptop
    glPushMatrix();
    glTranslatef(0.0f, 0.15f, 0.3f);
    drawLaptop();
    glPopMatrix();

    //lampu
    glPushMatrix();
    glTranslatef(-1.3f, 0.15f, 0.5f);
    drawLamp();
    glPopMatrix();
    
    //desk organizer
    glPushMatrix();
    glTranslatef(1.3f, 0.15f, 0.3f);
    drawOrganizer();
    glPopMatrix();
    
    //gelas kopi
    GLfloat ceramic_ambient[] = { 0.2f, 0.1f, 0.3f, 1.0f };
    GLfloat ceramic_diffuse[] = { 0.6f, 0.3f, 0.7f, 1.0f };
    GLfloat ceramic_specular[] = { 0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat ceramic_shininess[] = { 60.0f };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ceramic_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ceramic_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ceramic_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, ceramic_shininess);
    
    glPushMatrix();
    glTranslatef(0.7f, 0.15f, 0.5f);
    
    const int segments = 16;
    const float radius = 0.1f;
    const float height = 0.2f;
    const float angleStep = 2.0f * M_PI / segments;
    
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = i * angleStep;
        float x = radius * cosf(angle);
        float z = radius * sinf(angle);
        
        glNormal3f(cosf(angle), 0.0f, sinf(angle));
        glVertex3f(x, 0.0f, z);
        glVertex3f(x, height, z);
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    for (int i = segments; i >= 0; i--) {
        float angle = i * angleStep;
        glVertex3f(radius * cosf(angle), 0.0f, radius * sinf(angle));
    }
    glEnd();
    
    glPushMatrix();
    glTranslatef(radius, height/2, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    
    const float handle_radius = 0.07f;
    const float handle_thickness = 0.02f;
    const int handle_segments = 10;
    const float handle_angle_step = M_PI / handle_segments;
    
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= handle_segments; i++) {
        float angle = i * handle_angle_step;
        float x = handle_radius * cosf(angle);
        float y = handle_radius * sinf(angle);
        
        glNormal3f(-cosf(angle), sinf(angle), 0.0f);
        glVertex3f(x, y, -handle_thickness);
        glVertex3f(x, y, handle_thickness);
    }
    glEnd();
    
    glPopMatrix(); 
    glPopMatrix(); 
    
    drawBookshelf();
    
    glPopMatrix(); 
}

//rak buku
void drawBookshelf() {
    GLfloat wood_ambient[] = { 0.3f, 0.2f, 0.1f, 1.0f };
    GLfloat wood_diffuse[] = { 0.6f, 0.4f, 0.2f, 1.0f };
    GLfloat wood_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat wood_shininess[] = { 30.0f };
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, wood_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, wood_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wood_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, wood_shininess);
    
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, -0.85f);
    drawCuboid(3.5f, 1.4f, 0.1f, 0.55f, 0.35f, 0.15f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.7f, 0.7f, -0.5f);
    drawCuboid(0.1f, 1.4f, 0.8f, 0.55f, 0.35f, 0.15f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.7f, 0.7f, -0.5f);
    drawCuboid(0.1f, 1.4f, 0.8f, 0.55f, 0.35f, 0.15f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, -0.5f);
    drawCuboid(3.5f, 0.05f, 0.8f, 0.55f, 0.35f, 0.15f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 1.4f, -0.5f);
    drawCuboid(3.5f, 0.05f, 0.8f, 0.55f, 0.35f, 0.15f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 0.7f, -0.5f);
    drawCuboid(0.05f, 1.4f, 0.8f, 0.55f, 0.35f, 0.15f);
    glPopMatrix();
    
    //buku merah
    glPushMatrix();
    glTranslatef(-1.0f, 0.45f, -0.5f);
    drawBook(0.2f, 0.6f, 0.3f, 0.8f, 0.2f, 0.2f);
    glPopMatrix();
    
    //buku biru
    glPushMatrix();
    glTranslatef(-1.25f, 0.4f, -0.5f);
    drawBook(0.18f, 0.55f, 0.28f, 0.2f, 0.2f, 0.8f);
    glPopMatrix();
    
    //buku hijau
    glPushMatrix();
    glTranslatef(-0.75f, 0.38f, -0.5f);
    drawBook(0.25f, 0.5f, 0.25f, 0.2f, 0.7f, 0.2f);
    glPopMatrix();
    
    //pembatas buku
    glPushMatrix();
    glTranslatef(-1.45f, 0.4f, -0.5f);
    drawBookend(0.05f, 0.3f, 0.5f, 0.6f, 0.6f, 0.6f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.5f, 0.4f, -0.5f);
    drawBookend(0.05f, 0.3f, 0.5f, 0.6f, 0.6f, 0.6f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.6f, 0.45f, -0.5f);
    drawBook(0.15f, 0.58f, 0.3f, 0.7f, 0.3f, 0.7f); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.76f, 0.42f, -0.5f);
    drawBook(0.12f, 0.52f, 0.3f, 0.8f, 0.5f, 0.2f); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.89f, 0.47f, -0.5f);
    drawBook(0.13f, 0.6f, 0.3f, 0.5f, 0.5f, 0.5f); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.03f, 0.44f, -0.5f);
    drawBook(0.14f, 0.55f, 0.3f, 0.2f, 0.5f, 0.8f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.18f, 0.4f, -0.5f);
    drawBook(0.15f, 0.5f, 0.3f, 0.9f, 0.7f, 0.1f); 
    glPopMatrix();
    
    //pembatas buku
    glPushMatrix();
    glTranslatef(0.4f, 0.4f, -0.5f);
    drawBookend(0.05f, 0.3f, 0.5f, 0.6f, 0.6f, 0.6f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.35f, 0.4f, -0.5f);
    drawBookend(0.05f, 0.3f, 0.5f, 0.6f, 0.6f, 0.6f);
    glPopMatrix();
    
    //buku-buku
    glPushMatrix();
    glTranslatef(-1.0f, 1.0f, -0.5f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    drawBook(0.4f, 0.6f, 0.25f, 0.3f, 0.6f, 0.3f); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.0f, 1.08f, -0.5f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    drawBook(0.35f, 0.55f, 0.23f, 0.8f, 0.3f, 0.3f); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.0f, 1.15f, -0.5f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    drawBook(0.3f, 0.5f, 0.2f, 0.3f, 0.3f, 0.7f);
    glPopMatrix();
    
    //Buku buku
    glPushMatrix();
    glTranslatef(0.8f, 1.08f, -0.5f);
    glRotatef(15.0f, 0.0f, 0.0f, 1.0f);
    drawBook(0.18f, 0.6f, 0.3f, 0.9f, 0.2f, 0.2f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0f, 1.1f, -0.5f);
    glRotatef(12.0f, 0.0f, 0.0f, 1.0f);
    drawBook(0.2f, 0.58f, 0.28f, 0.2f, 0.8f, 0.2f); 
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.22f, 1.095f, -0.5f);
    glRotatef(9.0f, 0.0f, 0.0f, 1.0f);
    drawBook(0.22f, 0.55f, 0.25f, 0.2f, 0.2f, 0.9f); 
    glPopMatrix();
    
    //penyangah buku
    glPushMatrix();
    glTranslatef(0.6f, 1.05f, -0.5f);
    drawBookend(0.05f, 0.3f, 0.5f, 0.7f, 0.7f, 0.7f);
    glPopMatrix();
}
 
void lighting() { 
    glEnable(GL_DEPTH_TEST); 
    glDepthFunc(GL_LESS); 
    glEnable(GL_NORMALIZE); 
    glEnable(GL_COLOR_MATERIAL); 
    glEnable(GL_LIGHTING); 
    
    glEnable(GL_LIGHT0); 
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
    
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light2_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light2_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light2_position);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
} 
 
void init() { 
    glEnable(GL_DEPTH_TEST); 
    glShadeModel(GL_SMOOTH); 
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
} 
 
void framebuffer_size_callback(GLFWwindow* window, int width, int 
height) { 
    glViewport(0, 0, width, height); 
    setupCamera(width, height); 
} 
 
void processInput(GLFWwindow* window) { 
    static float moveSpeed = 0.1f; 
    static float rotateSpeed = 0.05f; 
    
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) { 
        deskPosX -= sin(camAngle) * moveSpeed; 
        deskPosZ -= cos(camAngle) * moveSpeed; 
    } 
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) { 
        deskPosX += sin(camAngle) * moveSpeed; 
        deskPosZ += cos(camAngle) * moveSpeed; 
    } 
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) { 
        deskPosX -= cos(camAngle) * moveSpeed; 
        deskPosZ += sin(camAngle) * moveSpeed; 
    } 
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) { 
        deskPosX += cos(camAngle) * moveSpeed; 
        deskPosZ -= sin(camAngle) * moveSpeed; 
    } 
    
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) { 
        camAngle += rotateSpeed; 
    } 
    
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) { 
        camDistance += 0.1f; 
    } 
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) { 
        camDistance = fmax(1.0f, camDistance - 0.1f); 
    } 
    
    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) { 
        camHeight += 0.1f; 
    } 
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) { 
        camHeight -= 0.1f; 
    } 
    
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, GLFW_TRUE); 
} 
 
int main() { 
    if (!glfwInit()) { 
        fprintf(stderr, "Failed to initialize GLFW\n"); 
        return -1; 
    } 
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1); 
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Meja Belajar", NULL, NULL); 
    if (!window) { 
        fprintf(stderr, "Failed to create GLFW window\n"); 
        glfwTerminate(); 
        return -1; 
    } 
 
    glfwMakeContextCurrent(window); 
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
 
    glewExperimental = GL_TRUE; 
    if (glewInit() != GLEW_OK) { 
        fprintf(stderr, "Failed to initialize GLEW\n"); 
        return -1; 
    } 
 
    int width, height; 
    glfwGetFramebufferSize(window, &width, &height); 
    framebuffer_size_callback(window, width, height); 
 
    lighting(); 
    init(); 
 
    while (!glfwWindowShouldClose(window)) { 
        processInput(window); 
 
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        
        setupCamera(width, height); 
        
        Grid(); 
        drawStudyDesk(); 
        glfwSwapBuffers(window); 
        glfwPollEvents(); 
    } 
 
    glfwTerminate(); 
    return 0; 
}