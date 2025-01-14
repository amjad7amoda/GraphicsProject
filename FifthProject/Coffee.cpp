#include "Coffee.h"

extern int outerCoffee, innerCoffeeWall, innerCoffeeRoof, innerCoffeeGround;

Coffee::Coffee(float w, float h, float d) {
	width = w;
	height = h;
	depth = d;
}

void Coffee::drawCoffeeSkyBlock() {
	glSetColor3f(1, 1, 1);
	float halfWidth = width / 2;
	float halfDepth = depth / 2;
	float scaleX = 3.0f , scaleY = 3.0f;
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glTranslatef(-0.01, 0.01, -0.01);

	//Front Face
	glBindTexture(GL_TEXTURE_2D, innerCoffeeWall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, 0);								glVertex3f(-halfWidth, 0, -halfDepth);
	glTexCoord2f(-10 / scaleX, 0);										glVertex3f(-10, 0, -halfDepth);
	glTexCoord2f(-10 / scaleX, 0.75 / scaleY);							glVertex3f(-10, 0.75, -halfDepth);
	glTexCoord2f(-halfWidth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 0.75, -halfDepth);

	glTexCoord2f(halfWidth / scaleX, 0);								glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2f(-5 / scaleX, 0);										glVertex3f(-5, 0, -halfDepth);
	glTexCoord2f(-5 / scaleX, 0.75/ scaleY);							glVertex3f(-5, 0.75, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, 0.75 / scaleY);					glVertex3f(halfWidth, 0.75, -halfDepth);

	glTexCoord2f(-halfWidth / scaleX, 10.25 / scaleY);					glVertex3f(-halfWidth, 10.25, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, 10.25 / scaleY);					glVertex3f(halfWidth, 10.25, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, 11 / scaleY);						glVertex3f(halfWidth, 11 - offset, -halfDepth);
	glTexCoord2f(-halfWidth / scaleX, 11 / scaleY);						glVertex3f(-halfWidth, 11 - offset, -halfDepth);

	glTexCoord2f(halfWidth / scaleX, 0.75 / scaleY);					glVertex3f(halfWidth, 0.75, -halfDepth);
	glTexCoord2f(14.25 / scaleX , 0.75 / scaleY);						glVertex3f(14.25, 0.75, -halfDepth);
	glTexCoord2f(14.25 / scaleX, 10.25 / scaleY);						glVertex3f(14.25, 10.25, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, 10.25 / scaleY);					glVertex3f(halfWidth, 10.25, -halfDepth);
	glEnd();


	//Right Face
	glBindTexture(GL_TEXTURE_2D, innerCoffeeWall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfDepth / scaleX, 0);								glVertex3f(-halfWidth, 0, -halfDepth);
	glTexCoord2f(halfDepth / scaleX, 0);								glVertex3f(-halfWidth, 0, halfDepth);
	glTexCoord2f(halfDepth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 0.75, halfDepth);
	glTexCoord2f(-halfDepth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 0.75, -halfDepth);

	glTexCoord2f(-halfDepth / scaleX, 0);								glVertex3f(-halfWidth, 10.25, -halfDepth);
	glTexCoord2f(halfDepth / scaleX, 0);								glVertex3f(-halfWidth, 10.25, halfDepth);
	glTexCoord2f(halfDepth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 11 - offset, halfDepth);
	glTexCoord2f(-halfDepth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 11 - offset, -halfDepth);

	glTexCoord2f(halfDepth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 0.75, halfDepth);
	glTexCoord2f(9.25 / scaleX, 0.75 / scaleY);							glVertex3f(-halfWidth, 0.75, 9.25);
	glTexCoord2f(9.25 / scaleY, 10.25 / scaleY);						glVertex3f(-halfWidth, 10.25, 9.25);
	glTexCoord2f(halfDepth / scaleY, 10.25 / scaleY);					glVertex3f(-halfWidth, 10.25, halfDepth);
	glEnd();

	//Back Face
	glBindTexture(GL_TEXTURE_2D, innerCoffeeWall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, 0);								glVertex3f(-halfWidth, 0, halfDepth);
	glTexCoord2f(halfWidth / scaleX, 0);								glVertex3f(halfWidth, 0, halfDepth);
	glTexCoord2f(halfWidth / scaleX, 11 / scaleY);						glVertex3f(halfWidth, 11 - offset, halfDepth);
	glTexCoord2f(-halfWidth / scaleX, 11 / scaleY);						glVertex3f(-halfWidth, 11 - offset, halfDepth);
	glEnd();

	
	//Left Face
	glBegin(GL_QUADS);
	glTexCoord2f(-halfDepth / scaleX, 0);								glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2f(halfDepth / scaleX, 0);								glVertex3f(halfWidth, 0, halfDepth);
	glTexCoord2f(halfDepth / scaleX, 11 / scaleY);						glVertex3f(halfWidth, 11 - offset, halfDepth);
	glTexCoord2f(-halfDepth / scaleX, 11 / scaleY);						glVertex3f(halfWidth, 11 - offset, -halfDepth);
	glEnd();

	//SkyUp Face
	glBindTexture(GL_TEXTURE_2D, innerCoffeeRoof);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(-halfWidth, 11 - (2 * offset), -halfDepth);
	glTexCoord2f(halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(halfWidth, 11 - (2 * offset), -halfDepth);
	glTexCoord2f(halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(halfWidth, 11 - (2 * offset), halfDepth);
	glTexCoord2f(-halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(-halfWidth, 11 - (2 * offset), halfDepth);
	glEnd();

	//SkyDown Face
	glBindTexture(GL_TEXTURE_2D, innerCoffeeGround);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(-halfWidth, 0, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(halfWidth, 0, halfDepth);
	glTexCoord2f(-halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(-halfWidth, 0, halfDepth);
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	drawOuterCoffee();
}

void Coffee::drawOuterCoffee() {
	float halfWidth = width / 2;
	float halfDepth = depth / 2;
	float scaleX = 1.5, scaleY = 1.5;

	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glTranslatef(-0.01, 0.01, -0.02);

	//Front Face
	glBindTexture(GL_TEXTURE_2D, outerCoffee);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, 0);								glVertex3f(-halfWidth - offset, 0, -halfDepth);
	glTexCoord2f(-10 / scaleX , 0);										glVertex3f(-10, 0, -halfDepth);
	glTexCoord2f(-10 / scaleX, 0.75 / scaleY);							glVertex3f(-10, 0.75, -halfDepth);
	glTexCoord2f(-halfWidth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth - offset, 0.75, -halfDepth);

	glTexCoord2f(halfWidth / scaleX, 0);								glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2f(-5 / scaleX , 0);										glVertex3f(-5, 0, -halfDepth);
	glTexCoord2f(-5 / scaleX, 0.75 / scaleY);							glVertex3f(-5, 0.75, -halfDepth);
	glTexCoord2f(halfWidth / scaleX , 0.75 / scaleY);					glVertex3f(halfWidth, 0.75, -halfDepth);

	glTexCoord2f(-halfWidth / scaleX, 10.25 / scaleY);					glVertex3f(-halfWidth - offset, 10.25, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, 10.25 / scaleY);					glVertex3f(halfWidth, 10.25, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, 11 / scaleY);						glVertex3f(halfWidth, 11 - offset, -halfDepth);
	glTexCoord2f(-halfWidth / scaleX, 11/ scaleY);						glVertex3f(-halfWidth - offset, 11 - offset, -halfDepth);

	glTexCoord2f(halfWidth / scaleX, 0.75 / scaleY);					glVertex3f(halfWidth, 0.75, -halfDepth);
	glTexCoord2f(14.25 / scaleX , 0.75 / scaleY);						glVertex3f(14.25, 0.75, -halfDepth);
	glTexCoord2f(14.25 / scaleX, 10.25 / scaleY);						glVertex3f(14.25, 10.25, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, 10.25 / scaleY);					glVertex3f(halfWidth, 10.25, -halfDepth);
	glEnd();
	glPopMatrix();
	
	
	//Right Face
	glPushMatrix();
	glTranslatef(-0.02, 0.01, -0.01);
	glBindTexture(GL_TEXTURE_2D, outerCoffee);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfDepth / scaleX, 0);								glVertex3f(-halfWidth, 0, -halfDepth - offset);
	glTexCoord2f(halfDepth / scaleX, 0);								glVertex3f(-halfWidth, 0, halfDepth);
	glTexCoord2f(halfDepth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 0.75, halfDepth);
	glTexCoord2f(-halfDepth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 0.75, -halfDepth - offset);

	glTexCoord2f(-halfDepth / scaleX, 10.25 / scaleY);					glVertex3f(-halfWidth, 10.25, -halfDepth - offset);
	glTexCoord2f(halfDepth / scaleX, 10.25 / scaleY);					glVertex3f(-halfWidth, 10.25, halfDepth);
	glTexCoord2f(halfDepth / scaleX, 11 / scaleY);						glVertex3f(-halfWidth, 11 - offset, halfDepth);
	glTexCoord2f(-halfDepth / scaleX, 11 / scaleY);						glVertex3f(-halfWidth, 11 - offset, -halfDepth - offset);

	glTexCoord2f(halfDepth / scaleX, 0.75 / scaleY);					glVertex3f(-halfWidth, 0.75, halfDepth);
	glTexCoord2f(9.25 / scaleX, 0.75 / scaleY);							glVertex3f(-halfWidth, 0.75, 9.25);
	glTexCoord2f(9.25 / scaleX, 10.25 / scaleY);						glVertex3f(-halfWidth, 10.25, 9.25);
	glTexCoord2f(halfDepth / scaleX, 10.25 / scaleY);					glVertex3f(-halfWidth, 10.25, halfDepth);
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glSetColor3f(1, 1, 1);
}