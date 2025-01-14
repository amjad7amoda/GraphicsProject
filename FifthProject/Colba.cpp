#include "Colba.h"

Colba::Colba(float width, float height, float depth) {
    w = width;
    h = height;
    d = depth;
    offset = 0.001f;  // فرق صغير لتجنب التداخل
}
int back, right, left, front1, front2;
extern int RestaurantWall;
extern bool isLightingEnabled;
extern void glSetColor3f(float r, float g, float b);

void Colba::draw() {

    glSetColor3f(1, 1, 1);

    // Front Face
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, front1);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex3f(-w / 2 + offset, h, d / 2 + offset);
    glTexCoord2d(1.0, 1.0); glVertex3f(w / 2 - offset, h, d / 2 + offset);
    glTexCoord2d(1.0, 0.0); glVertex3f(w / 2 - offset, h - 2, d / 2 + offset);
    glTexCoord2d(0.0, 0.0); glVertex3f(-w / 2 + offset, h - 2, d / 2 + offset);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, front2);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(-w / 2 + offset, 0, d / 2 + offset);
    glTexCoord2d(2.0, 0.0); glVertex3f(w / 2 - offset, 0, d / 2 + offset);
    glTexCoord2d(2.0, 1.0); glVertex3f(w / 2 - offset, 0.75, d / 2 + offset);
    glTexCoord2d(0.0, 1.0); glVertex3f(-w / 2 + offset, 0.75, d / 2 + offset);

    glVertex3f(-w / 2 + offset, 0.75 + offset, 1.5);
    glVertex3f(-w / 2 + offset, 0.75 + offset, 2.5);
    glVertex3f(w / 2 - offset, 0.75 + offset, 2.5);
    glVertex3f(w / 2 - offset, 0.75 + offset, 1.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    //glSetColor3f(1, 1, 1);

    // Left Face
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, left);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(-w / 2 + offset, 0, d / 2 + offset);
    glTexCoord2d(3.0, 0.0); glVertex3f(-w / 2 + offset, 0, -d / 2 - offset);
    glTexCoord2d(3.0, 5.0); glVertex3f(-w / 2 + offset, h + 2, -d / 2 - offset);
    glTexCoord2d(0.0, 5.0); glVertex3f(-w / 2 + offset, h + 2, d / 2 + offset);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    // Right Face
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, right);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(w / 2 - offset, 0, d / 2 + offset);
    glTexCoord2d(3.0, 0.0); glVertex3f(w / 2 - offset, 0, -d / 2 - offset);
    glTexCoord2d(3.0, 5.0); glVertex3f(w / 2 - offset, h + 2, -d / 2 - offset);
    glTexCoord2d(0.0, 5.0); glVertex3f(w / 2 - offset, h + 2, d / 2 + offset);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    // Back Face
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, back);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3f(-w / 2 + offset, 0, -d / 2 + offset);
    glTexCoord2d(1.0, 0.0); glVertex3f(w / 2 - offset, 0, -d / 2 + offset);
    glTexCoord2d(1.0, 1.0); glVertex3f(w / 2 - offset, 5, -d / 2 + offset);
    glTexCoord2d(0.0, 1.0); glVertex3f(-w / 2 + offset, 5, -d / 2 + offset);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    float alpha = 0.4;
    glColor4f(0.5f, 0.7f, 1.0f, alpha);
    glBegin(GL_QUADS);
    glVertex3f(-w / 2 + offset, h - 2.75 - offset, 2);
    glVertex3f(-w / 2 + offset, h - 2 + offset, 2);
    glVertex3f(w / 2 - offset, h - 2 + offset, 2);
    glVertex3f(w / 2 + offset, h - 2.75 - offset, 2);
    glEnd();
    glDisable(GL_BLEND);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);

    glSetColor3f(1, 1, 1);


}
void Colba::DrawTriangle() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, RestaurantWall);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(2.49, 0, 2);
    glTexCoord2d(1.0, 0); glVertex3f(3.51, 0, 2);
    glTexCoord2d(1.0, 4); glVertex3f(3.51, 4, 2);
    glTexCoord2d(0, 4);  glVertex3f(2.49, 4, 2);
    glEnd();

    glSetColor3f(1, 1, 1);
}
void Colba::setBack(int b) {
    back = b;
}

void Colba::setFront(int f1, int f2) {
    front1 = f1;
    front2 = f2;
}

void Colba::setRight(int r) {
    right = r;
}

void Colba::setLeft(int l) {
    left = l;
}


