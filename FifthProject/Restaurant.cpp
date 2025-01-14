#include "Restaurant.h"
#include "Colba.h"
#include "Table.h"
#include "Chair.h"
#include "Model_3DS.h"
int width, height, depth;

extern int RestaurantLogo, OuterRestaurant, RestaurantWall, RestaurantBackWall, fRestaurant, bRestaurant, rRestaurant, lRestaurant, roofRestaurant, floorRestaurant, Fence, McDonaldsLogo, McDonaldsUnderLogo, PizzaHotLogo, PizzaHotUnderLogo, tableTexture, tableLegsTexture, SyriaPlate, SalesPlate, BurgerKingUp, BurgerKingDown, MuslimUp, MuslimDown, AlBaikUp, AlBaikDown;
extern Model_3DS* tree;
extern void glSetColor3f(float r, float g, float b);

Restaurant::Restaurant(int w, int h, int d) {
	width = w; height = h; depth = d;
	
}
void Restaurant::Draw() {
	glPushMatrix();
	glTranslatef(0, 0.01, 0.01);
	DrawRestaurantSkyBox();
	DrawColbas();
	DrawTables();
	DrawPlates();
	DrawTree(13.5, 0, 9); DrawTree(-13.5, 0, 9); DrawTree(9, 0, -5); DrawTree(-9, 0, -5);
	glPopMatrix();
	glSetColor3f(1, 1, 1);
}
void Restaurant::DrawRestaurantSkyBox() {
	glEnable(GL_TEXTURE_2D);

	glClear(GL_COLOR_BUFFER_BIT);
	float halfWidth = width / 2.0f;
	float halfDepth = depth / 2.0f;
	glEnable(GL_TEXTURE_2D);
	
	// Draw the Left side
	glBindTexture(GL_TEXTURE_2D, lRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-halfWidth, 0, halfDepth);
	glTexCoord2f(1, 0);
	glVertex3f(-halfWidth, 0, -halfDepth);
	glTexCoord2f(1, 1);
	glVertex3f(-halfWidth, height, -halfDepth);
	glTexCoord2f(0, 1);
	glVertex3f(-halfWidth, height, halfDepth);
	glEnd();



	// Draw the Front side
	glBindTexture(GL_TEXTURE_2D, fRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-halfWidth, 0, -halfDepth);
	glTexCoord2f(1, 0);
	glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2f(1, 1);
	glVertex3f(halfWidth, height, -halfDepth);
	glTexCoord2f(0, 1);
	glVertex3f(-halfWidth, height, -halfDepth);
	glEnd();

	// Draw the Top
	glBindTexture(GL_TEXTURE_2D, roofRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-halfWidth, height, halfDepth);
	glTexCoord2f(width, 0);
	glVertex3f(halfWidth, height, halfDepth);
	glTexCoord2f(width, depth);
	glVertex3f(halfWidth, height, -halfDepth);
	glTexCoord2f(0, depth);
	glVertex3f(-halfWidth, height, -halfDepth);
	glEnd();


	// Draw the Right side
	glBindTexture(GL_TEXTURE_2D, rRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(halfWidth, 0, halfDepth);
	glTexCoord2f(1, 0);
	glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2f(1, 1);
	glVertex3f(halfWidth, height, -halfDepth);
	glTexCoord2f(0, 1);
	glVertex3f(halfWidth, height, halfDepth);
	glEnd();


	// Draw the Bottom
	glBindTexture(GL_TEXTURE_2D, floorRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-halfWidth, 0, halfDepth);
	glTexCoord2d(width, 0);
	glVertex3f(halfWidth, 0, halfDepth);
	glTexCoord2d(width, depth);
	glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2d(0, depth);
	glVertex3f(-halfWidth, 0, -halfDepth);
	glEnd();
	

	// Draw the Back side
	glBindTexture(GL_TEXTURE_2D, bRestaurant);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	//Left side
	glVertex3f(-13.5, 0, halfDepth);
	glVertex3f(-3.5, 0, halfDepth);
	glVertex3f(-3.5, 1, halfDepth);
	glVertex3f(-13.5, 1, halfDepth);

	glVertex3f(-13.5, 9, halfDepth);
	glVertex3f(-3.5, 9, halfDepth);
	glVertex3f(-3.5, 10, halfDepth);
	glVertex3f(-13.5, 10, halfDepth);

	glVertex3f(-3.5, 0, halfDepth);
	glVertex3f(-2.5, 0, halfDepth);
	glVertex3f(-2.5, height, halfDepth);
	glVertex3f(-3.5, height, halfDepth);

	glVertex3f(-13.5, 0, halfDepth);
	glVertex3f(-halfWidth, 0, halfDepth);
	glVertex3f(-halfWidth, height, halfDepth);
	glVertex3f(-13.5, height, halfDepth);

	//Right side
	glVertex3f(13.5, 0, halfDepth);
	glVertex3f(3.5, 0, halfDepth);
	glVertex3f(3.5, 1, halfDepth);
	glVertex3f(13.5, 1, halfDepth);

	glVertex3f(13.5, 9, halfDepth);
	glVertex3f(3.5, 9, halfDepth);
	glVertex3f(3.5, 10, halfDepth);
	glVertex3f(13.5, 10, halfDepth);

	glVertex3f(3.5, 0, halfDepth);
	glVertex3f(2.5, 0, halfDepth);
	glVertex3f(2.5, height, halfDepth);
	glVertex3f(3.5, height, halfDepth);

	glVertex3f(13.5, 0, halfDepth);
	glVertex3f(halfWidth, 0, halfDepth);
	glVertex3f(halfWidth, height, halfDepth);
	glVertex3f(13.5, height, halfDepth);
	glEnd();

	//UpDoor
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.5, 4, halfDepth);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.5, 4, halfDepth);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.5, height, halfDepth);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.5, height, halfDepth);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glSetColor3f(1, 1, 1);
}
void Restaurant::DrawTriangle() {
	glPushMatrix();
	float offset = 0.01;
	float halfWidth = 30 / 2;
	//glTranslatef(-25, 0, -10);
	glTranslatef(0, 0, -6);
	glSetColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, RestaurantWall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(-halfWidth, 4);
	glTexCoord2f(0.0, 7); glVertex2f(-halfWidth, 11);
	glTexCoord2f(29 , 7.0); glVertex2f(halfWidth, 11);
	glTexCoord2f(29.0, 0.0); glVertex2f(halfWidth, 4);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glSetColor3f(1, 1, 1);
}
void Restaurant::DrawColbas() {
	Colba colba(5, 4, 4);
	//colba.setRight(RestaurantWall);
	//1
	glPushMatrix();
	glTranslatef(0, 0, 0.01);
	glPushMatrix();
	glTranslatef(-12, 0, -(depth / 2) + 2);
	colba.setRight(RestaurantWall);
	colba.setLeft(RestaurantWall);
	colba.setFront(0, Fence);
	colba.setFront(McDonaldsLogo, McDonaldsUnderLogo);
	colba.setBack(RestaurantBackWall);
	colba.draw();
	colba.DrawTriangle();
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslatef(-6, 0, -(depth / 2) + 2);
	colba.setRight(RestaurantWall);
	colba.setLeft(RestaurantWall);
	colba.setFront(PizzaHotLogo, PizzaHotUnderLogo);
	colba.setBack(RestaurantBackWall);
	colba.draw();
	colba.DrawTriangle();
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(0.0, 0, -(depth / 2) + 2);
	colba.setRight(RestaurantWall);
	colba.setLeft(RestaurantWall);
	colba.setFront(BurgerKingUp, BurgerKingDown);
	colba.setBack(RestaurantBackWall);
	colba.draw();
	colba.DrawTriangle();
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslatef(6, 0, -(depth / 2) + 2);
	colba.setRight(RestaurantWall);
	colba.setLeft(RestaurantWall);
	colba.setFront(MuslimUp, MuslimDown);
	colba.setBack(RestaurantBackWall);
	colba.draw();
	colba.DrawTriangle();
	glPopMatrix();
	//5
	glPushMatrix();
	glTranslatef(12, 0, -(depth / 2) + 2);
	colba.setRight(RestaurantWall);
	colba.setLeft(RestaurantWall);
	colba.setFront(AlBaikUp, AlBaikDown);
	colba.setBack(RestaurantBackWall);
	colba.draw();
	glPopMatrix();
	glPopMatrix();
	DrawTriangle();
}
void Restaurant::DrawTableWithChairs(float x, float y, float z) {
	glColor3f(1, 1, 1);
	//glClear(GL_COLOR_BUFFER_BIT);
	// Table dimensions
	float tableTopSize = 1.5f;
	float tableTopThickness = 0.1f;
	float tableHeight = 0.7f;
	float legThickness = 0.1f;

	// Chair dimensions
	float chairSeatSize = 0.5f;
	float chairSeatHeight = 0.4f;
	float chairLegThickness = 0.05f;
	float chairBackrestHeight = 0.5f;

	// Draw table
	Table table(x, y, z, tableTopSize, tableTopThickness, tableHeight, legThickness);
	table.Draw();
	table.setTableTexture(tableTexture);
	table.setLegsTexture(tableLegsTexture);
	// Draw chairs around the table
	float chairDistance = tableTopSize / 2.0f + chairSeatSize / 2.0f + 0.1f;

	
	// Left chair
	Chair chair(0, 0, 0, chairSeatSize, chairSeatHeight, chairBackrestHeight, chairLegThickness);
	glPushMatrix();
	glTranslatef(x - chairDistance, y, z);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	chair.Draw();
	glPopMatrix();

	// Right chair
	glPushMatrix();
	glTranslatef(x + chairDistance, y, z);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); // Rotate to face the table
	chair.Draw();
	glPopMatrix();

	// Front chair
	glPushMatrix();
	glTranslatef(x, y, z - chairDistance);
	chair.Draw();
	glPopMatrix();

	// Back chair
	glPushMatrix();
	glTranslatef(x, y, z + chairDistance);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	chair.Draw();
	glPopMatrix();
	glSetColor3f(1, 1, 1);
}
void Restaurant::DrawTables() {
	//Table and chairs
	glDisable(GL_LIGHTING);
	glPushMatrix();
	//Right
	DrawTableWithChairs(12.0f, 0.0f, 8.0f);
	DrawTableWithChairs(8.0f, 0.0f, 8.0f);
	DrawTableWithChairs(4.0f, 0.0f, 8.0f);
	DrawTableWithChairs(12.0f, 0.0f, 4.0f);
	DrawTableWithChairs(8.0f, 0.0f, 4.0f);
	DrawTableWithChairs(4.0f, 0.0f, 4.0f);
	DrawTableWithChairs(12.0f, 0.0f, 0.0f);
	DrawTableWithChairs(8.0f, 0.0f, 0.0f);
	DrawTableWithChairs(4.0f, 0.0f, 0.0f);

	//Left
	DrawTableWithChairs(-12.0f, 0.0f, 8.0f);
	DrawTableWithChairs(-8.0f, 0.0f, 8.0f);
	DrawTableWithChairs(-4.0f, 0.0f, 8.0f);
	DrawTableWithChairs(-12.0f, 0.0f, 4.0f);
	DrawTableWithChairs(-8.0f, 0.0f, 4.0f);
	DrawTableWithChairs(-4.0f, 0.0f, 4.0f);
	DrawTableWithChairs(-12.0f, 0.0f, 0.0f);
	DrawTableWithChairs(-8.0f, 0.0f, 0.0f);
	DrawTableWithChairs(-4.0f, 0.0f, 0.0f);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glSetColor3f(1, 1, 1);
}
void Restaurant::DrawPlate(int w, int h, float frameThickness, int texture) {
	float halfW = w / 2.0f;
	float halfH = h / 2.0f;
	float outerHalfW = halfW + frameThickness;
	float outerHalfH = halfH + frameThickness;
	float frameDepth = 0.1f;

	glSetColor3f(0.4f, 0.2f, 0.1f);
	glBegin(GL_QUADS);
	// Top Frame
	glVertex3f(-outerHalfW, outerHalfH, frameDepth);
	glVertex3f(outerHalfW, outerHalfH, frameDepth);
	glVertex3f(outerHalfW, halfH, 0);
	glVertex3f(-outerHalfW, halfH, 0);
	// Bottom Frame
	glVertex3f(-outerHalfW, -outerHalfH, frameDepth);
	glVertex3f(outerHalfW, -outerHalfH, frameDepth);
	glVertex3f(outerHalfW, -halfH, 0);
	glVertex3f(-outerHalfW, -halfH, 0);
	// Right Frame
	glVertex3f(halfW, outerHalfH, 0);
	glVertex3f(outerHalfW, outerHalfH, frameDepth);
	glVertex3f(outerHalfW, -outerHalfH, frameDepth);
	glVertex3f(halfW, -outerHalfH, 0);
	// Left Frame
	glVertex3f(-outerHalfW, outerHalfH, frameDepth);
	glVertex3f(-halfW, outerHalfH, 0);
	glVertex3f(-halfW, -outerHalfH, 0);
	glVertex3f(-outerHalfW, -outerHalfH, frameDepth);
	glEnd();
	glSetColor3f(1, 1, 1);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-halfW, -halfH, 0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(halfW, -halfH, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(halfW, halfH, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-halfW, halfH, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glSetColor3f(1, 1, 1);
}
void Restaurant::DrawPlates() {
	//Draw Plate
	glPushMatrix();
	glTranslatef(-width / 2 + 0.1f, height / 2, 2);
	glRotatef(90, 0, 1, 0);
	DrawPlate(7, 4, 0.1, SyriaPlate);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(+width / 2 - 0.1f, height / 1.5, -1);
	glRotatef(-90, 0, 1, 0);
	DrawPlate(4, 2, 0.1, SalesPlate);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(+width / 2 - 0.1f, height / 1.5, 5);
	glRotatef(-90, 0, 1, 0);
	DrawPlate(4, 2, 0.05, SalesPlate);
	glPopMatrix();
	glSetColor3f(1, 1, 1);
}
void Restaurant::DrawTree(float x, float y, float z) {
	float potWidth = 0.15f;
	float potHeight = 0.3f;         

	glSetColor3f(0.4f, 0.2f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(x - potWidth, y + 0.01, z - potWidth);
	glVertex3f(x + potWidth, y + 0.01, z - potWidth);
	glVertex3f(x + potWidth, y + 0.01, z + potWidth);
	glVertex3f(x - potWidth, y + 0.01, z + potWidth);
	glEnd();

	glSetColor3f(0.5f, 0.25f, 0.15f);
	glBegin(GL_QUADS);
	glVertex3f(x - potWidth, y + 0.01, z - potWidth);
	glVertex3f(x + potWidth, y + 0.01, z - potWidth);
	glVertex3f(x + potWidth, y + potHeight, z - potWidth);
	glVertex3f(x - potWidth, y + potHeight, z - potWidth);
	glEnd();

	glSetColor3f(0.45f, 0.2f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(x + potWidth, y + 0.01, z - potWidth);
	glVertex3f(x + potWidth, y + 0.01, z + potWidth);
	glVertex3f(x + potWidth, y + potHeight, z + potWidth);
	glVertex3f(x + potWidth, y + potHeight, z - potWidth);
	glEnd();

	glSetColor3f(0.4f, 0.2f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(x + potWidth, y + 0.01, z + potWidth);
	glVertex3f(x - potWidth, y + 0.01, z + potWidth);
	glVertex3f(x - potWidth, y + potHeight, z + potWidth);
	glVertex3f(x + potWidth, y + potHeight, z + potWidth);
	glEnd();

	glSetColor3f(0.5f, 0.3f, 0.15f);
	glBegin(GL_QUADS);
	glVertex3f(x - potWidth, y + 0.01, z + potWidth);
	glVertex3f(x - potWidth, y + 0.01, z - potWidth);
	glVertex3f(x - potWidth, y + potHeight, z - potWidth);
	glVertex3f(x - potWidth, y + potHeight, z + potWidth);
	glEnd();

	glSetColor3f(1, 1, 1);
	
	tree->pos.x = x;
	tree->pos.y = y;
	tree->pos.z = z;
	tree->scale = 0.2;
	tree->Draw();

	glSetColor3f(1, 1, 1);
}
void Restaurant::DrawOuterRestaurant() {
	float halfDepth = depth / 2;
	float halfWidth = width / 2;
	height= 11;
	// Draw the Back side
	glPushMatrix();
	glTranslatef(0, 0, 0.02);
	glEnable(GL_TEXTURE_2D);
	//left side
	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-13.5, 0, halfDepth);
	glTexCoord2f(10, 0); glVertex3f(-3.5, 0, halfDepth);
	glTexCoord2f(10, 1); glVertex3f(-3.5, 1, halfDepth);
	glTexCoord2f(0, 1); glVertex3f(-13.5, 1, halfDepth);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-13.5, 9, halfDepth);
	glTexCoord2f(10, 0); glVertex3f(-3.5, 9, halfDepth);
	glTexCoord2f(10, 2); glVertex3f(-3.5, 11, halfDepth);
	glTexCoord2f(0, 2); glVertex3f(-13.5, 11, halfDepth);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-3.5, 0, halfDepth);
	glTexCoord2f(1, 0); glVertex3f(-2.5, 0, halfDepth);
	glTexCoord2f(1, height); glVertex3f(-2.5, height, halfDepth);
	glTexCoord2f(0, height); glVertex3f(-3.5, height, halfDepth);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-13.5, 0, halfDepth);
	glTexCoord2f(1.5, 0); glVertex3f(-15, 0, halfDepth);
	glTexCoord2f(1.5, height); glVertex3f(-15, height, halfDepth);
	glTexCoord2f(0, height); glVertex3f(-13.5, height, halfDepth);
	glEnd();
	//right side
	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(13.5, 0, halfDepth);
	glTexCoord2f(10, 0); glVertex3f(3.5, 0, halfDepth);
	glTexCoord2f(10, 1); glVertex3f(3.5, 1, halfDepth);
	glTexCoord2f(0, 1); glVertex3f(13.5, 1, halfDepth);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(13.5, 9, halfDepth);
	glTexCoord2f(10, 0); glVertex3f(3.5, 9, halfDepth);
	glTexCoord2f(10, 2); glVertex3f(3.5, 11, halfDepth);
	glTexCoord2f(0, 2); glVertex3f(13.5, 11, halfDepth);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(3.5, 0, halfDepth);
	glTexCoord2f(1, 0); glVertex3f(2.5, 0, halfDepth);
	glTexCoord2f(1, height); glVertex3f(2.5, height, halfDepth);
	glTexCoord2f(0, height); glVertex3f(3.5, height, halfDepth);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(13.5, 0, halfDepth);
	glTexCoord2f(1.5, 0); glVertex3f(15, 0, halfDepth);
	glTexCoord2f(1.5, height); glVertex3f(15, height, halfDepth);
	glTexCoord2f(0, height); glVertex3f(13.5, height, halfDepth);
	glEnd();

	//UpDoor
	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.5, 4, halfDepth);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(-2.5, 4, halfDepth);
	glTexCoord2f(5.0f, 7.0f); glVertex3f(-2.5, height, halfDepth);
	glTexCoord2f(0.0f, 7.0f); glVertex3f(2.5, height, halfDepth);
	glEnd();
	//Logo
	glBindTexture(GL_TEXTURE_2D, RestaurantLogo);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-3, 4.5, halfDepth + 0.01);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(3, 4.5, halfDepth + 0.01);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(3, 8.5, halfDepth + 0.01);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-3, 8.5, halfDepth + 0.01);
	glEnd();


	//Right Wall
	glBindTexture(GL_TEXTURE_2D, OuterRestaurant);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(15, 0, 10);
	glTexCoord2f(20, 0); glVertex3f(15, 0, -10);
	glTexCoord2f(20, height); glVertex3f(15, height, -10);
	glTexCoord2f(0, height); glVertex3f(15, height, 10);
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glSetColor3f(1, 1, 1);
}