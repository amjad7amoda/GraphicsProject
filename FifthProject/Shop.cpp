#include <glut.h>
#include <GL.H>
#include "Shop.h"

extern void glSetColor3f(float r, float g, float b);

Shop::Shop(float width, float height, float depth)
    : shopWidth(width), shopDepth(depth), shopHeight(height), offset(0.01f) {
}


void Shop::Draw(float doorWidth, float doorHeight) {
    this->doorHeight = doorHeight;
    this->doorWidth = doorWidth;
 /*   float shopWidth = 30; float shopDepth = 20;
    shopHeight = 11;*/
    float halfWidth = shopWidth / 2.0f;
    float halfDepth = shopDepth / 2.0f;
    float offset = 0.01;
    float halfDoorWidth = doorWidth / 2.0f;

    
    glPushMatrix();
 	glTranslatef(0 , 0.00, 0.02);
 	
    
 	//Front Face
 	//Left The Door
    glBindTexture(GL_TEXTURE_2D, frontTexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-halfWidth, 0, halfDepth);
    glTexCoord2f(0.33f, 0.0f); glVertex3f(-halfDoorWidth, 0, halfDepth);
    glTexCoord2f(0.33f, 1.0f); glVertex3f(-halfDoorWidth, shopHeight, halfDepth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-halfWidth, shopHeight, halfDepth);

    glTexCoord2f(0.67f, 0.0f); glVertex3f(halfDoorWidth, 0, halfDepth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(halfWidth, 0, halfDepth);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(halfWidth, shopHeight, halfDepth);
    glTexCoord2f(0.67f, 1.0f); glVertex3f(halfDoorWidth, shopHeight, halfDepth);

    glTexCoord2f(0.33f, 0.5f); glVertex3f(-halfDoorWidth, doorHeight, halfDepth);
    glTexCoord2f(0.67f, 0.5f); glVertex3f(halfDoorWidth, doorHeight, halfDepth);
    glTexCoord2f(0.67f, 1.0f); glVertex3f(halfDoorWidth, shopHeight, halfDepth);
    glTexCoord2f(0.33f, 1.0f); glVertex3f(-halfDoorWidth, shopHeight, halfDepth);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    
    
 	//Left Face
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, leftTexture);
 	glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-halfWidth + offset, 0, halfDepth);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-halfWidth + offset, 0, -halfDepth);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-halfWidth + offset, shopHeight, -halfDepth);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-halfWidth + offset, shopHeight, halfDepth);
 	glEnd();
    glDisable(GL_TEXTURE_2D);
    
 	//Right Face
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, rightTexture);
 	glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(halfWidth - offset, 0, halfDepth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(halfWidth - offset, 0, -halfDepth);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(halfWidth - offset, shopHeight, -halfDepth);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(halfWidth - offset, shopHeight, halfDepth);
 	glEnd();
 	glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glSetColor3f(1, 1, 1);
}



void Shop::setFrontTexture(int front) {
    frontTexture = front;
}
void Shop::setRightTexture(int right) {
    rightTexture = right;
}
void Shop::setLeftTexture(int left) {
    leftTexture = left;
}

