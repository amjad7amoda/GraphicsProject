#include "Coffee.h"
#include "Chair.h"
#include "Table.h"
extern int outerCoffee, innerCoffeeWall, innerCoffeeRoof, innerCoffeeGround;

Coffee::Coffee(float w, float h, float d) {
	width = w;
	height = h;
	depth = d;
}

void Coffee::draw() {

	drawSingleTable(11, 0, -8); 
	drawSingleTable(5, 0, -8);
	drawSingleTable(-1, 0, -8);
	drawDoubleTable(-11, 0, 6);
	drawDoubleTable(-5, 0, 6);
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	drawSingleTable(7, 0, -13);
	drawSingleTable(1, 0, -13);
	glPopMatrix();
	drawCoffeeSkyBlock();
	drawOuterCoffee();
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

void Coffee::drawSingleTable(float x, float y, float z) {
	glSetColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	//Table
	float tableTopSize = 2.0f;
	float tableTopThickness = 0.15f;
	float tableHeight = 1.5f;
	float legThickness = 0.15f;

	// Chair dimensions
	float chairSeatSize = 1.0f;
	float chairSeatHeight = 1.0f;
	float chairLegThickness = 0.1f;
	float chairBackrestHeight = 1.0f;

	Table singleTable(x, y, z, tableTopSize, tableTopThickness, tableHeight, legThickness);
	singleTable.Draw();

	//Chairs
	float chairDistance = tableTopSize / 2.0f + chairSeatSize / 2.0f + 0.1f;
	Chair chair(0, 0, 0, chairSeatSize, chairSeatHeight, chairBackrestHeight, chairLegThickness);
	//first chair
	glPushMatrix();
	glTranslatef(x - chairDistance, y, z);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	chair.Draw();
	glPopMatrix();
	//second chair
	glPushMatrix();
	glTranslatef(x + chairDistance, y, z);
	glRotatef(270, 0.0f, 1.0f, 0.0f);
	chair.Draw();
	glPopMatrix();

	glSetColor3f(1, 1, 1);
	glEnable(GL_LIGHTING);
}

void Coffee::drawDoubleTable(float x, float y, float z) {
	glSetColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);

	float tableTopSize = 2.0f;
	float tableTopThickness = 0.15f;
	float tableHeight = 1.5f;
	float legThickness = 0.15f;

	// Chair dimensions
	float chairSeatSize = 1.0f;
	float chairSeatHeight = 1.0f;
	float chairLegThickness = 0.1f;
	float chairBackrestHeight = 1.0f;

	Table firstTable(x, y, z, tableTopSize, tableTopThickness, tableHeight, legThickness);
	Table secondTable(x - tableTopSize - 0.05, y, z, tableTopSize, tableTopThickness, tableHeight, legThickness);
	firstTable.Draw();
	secondTable.Draw();

	//Chairs
	float chairDistance = tableTopSize / 2.0f + chairSeatSize / 2.0f + 0.1f;
	Chair chair(0, 0, 0, chairSeatSize, chairSeatHeight, chairBackrestHeight, chairLegThickness);
	//left chairs
	glPushMatrix();
	glTranslatef(x , y, z - 1.5);
	glRotatef(0, 0.0f, 1.0f, 0.0f);
	chair.Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x, y, z + 1.5);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	chair.Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x - 2, y, z + 1.5);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	chair.Draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x - 2, y, z - 1.5);
	glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
	chair.Draw();
	glPopMatrix();

	glSetColor3f(1, 1, 1);
	glEnable(GL_LIGHTING);
}

void Coffee::drawCoffeeShop() {
	glSetColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(5, 0, 5);


	glPopMatrix();
	glSetColor3f(1, 1, 1);
}