#include "Mall.h"
#include <glut.h>
#include "Restaurant.h"
#include "Shop.h"
#include "Coffee.h"
float width, height, depth;
extern void glSetColor3f(float r, float g, float b);
extern int CoffeeDoor;
extern int RestaurantWall, RestaurantBackWall, McDonaldsLogo, McDonaldsUnderLogo, PizzaHotLogo, PizzaHotUnderLogo, BurgerKingUp, BurgerKingDown, MuslimUp, MuslimDown, AlBaikUp, AlBaikDown;
extern int roofRestaurant, bRestaurant, fOuterMall, lOuterMall, rOuterMall, bOuterMall,wallInMall, floorInMall, roofInMall, upDoorMall, stairsDown;
Mall::Mall(float w, float h, float d) {
	width = w;
	height = h;
	depth = d;
}

void Mall::DrawMallSkyBlock() {
	float halfWidth = width / 2;
	float halfDepth = depth / 2;
	float scaleX = 7.0f;
	float scaleY = 7.0f;
	float offset = 0.005;
	glEnable(GL_TEXTURE_2D);
	//Front Face
	glSetColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	//Left Side
	glTexCoord2d(-5 / scaleX, 0 / scaleY);								glVertex3f(-5, 0, halfDepth);
	glTexCoord2d(-halfWidth / scaleX, 0 / scaleY);						glVertex3f(-halfWidth, 0, halfDepth);
	glTexCoord2d(-halfWidth / scaleX, height / scaleY);					glVertex3f(-halfWidth, height, halfDepth);
	glTexCoord2d(-5 / scaleX, height / scaleY);							glVertex3f(-5, height, halfDepth);
	//Right Side
	glTexCoord2f(halfWidth / scaleX, 0 / scaleY);						glVertex3f(halfWidth, 0, halfDepth);
	glTexCoord2d(5 / scaleX, 0 / scaleY);								glVertex3f(5, 0, halfDepth);
	glTexCoord2d(5 / scaleX, height / scaleY);							glVertex3f(5, height, halfDepth);
	glTexCoord2d(halfWidth / scaleX, height/ scaleY);					glVertex3f(halfWidth, height, halfDepth);
	//Up Door
	glTexCoord2d(-5 / scaleX, 5 / scaleY);								glVertex3f(-5, 5, halfDepth);
	glTexCoord2d(5 / scaleX, 5 / scaleY);								glVertex3f(5, 5, halfDepth);
	glTexCoord2d(5 / scaleX, height / scaleY);							glVertex3f(5, height, halfDepth);
	glTexCoord2d(-5 / scaleX, height / scaleY);							glVertex3f(-5, height, halfDepth);
	glEnd();
	//Back Face
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2d(-halfWidth / scaleX, 0 / scaleY);						glVertex3f(-halfWidth, 0, -halfDepth);
	glTexCoord2d(halfWidth / scaleX, 0 / scaleY);						glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2d(halfWidth / scaleX, height / scaleY);					glVertex3f(halfWidth, height, -halfDepth);
	glTexCoord2d(-halfWidth / scaleX, height / scaleY);					glVertex3f(-halfWidth, height, -halfDepth);

	//Left Face 
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wallInMall);
	glBegin(GL_QUADS);
	glTexCoord2f(halfDepth / scaleX, 0 / scaleY);						glVertex3f(-halfWidth, 0, halfDepth);
	glTexCoord2f(-halfDepth / scaleX, 0 / scaleY);						glVertex3f(-halfWidth, 0, -halfDepth);
	glTexCoord2f(-halfDepth / scaleX, height / scaleY);					glVertex3f(-halfWidth, height, -halfDepth);
	glTexCoord2f(halfDepth / scaleX, height / scaleY);					glVertex3f(-halfWidth, height, halfDepth);
	glEnd(); 

	//Right Face
	glBindTexture(GL_TEXTURE_2D, wallInMall);
	glBegin(GL_QUADS);
	glTexCoord2f(halfDepth / scaleX, 0 / scaleY);						glVertex3f(halfWidth, 0, halfDepth);
	glTexCoord2f(-halfDepth / scaleX, 0 / scaleY);						glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2f(-halfDepth / scaleX, height / scaleY);					glVertex3f(halfWidth, height, -halfDepth);
	glTexCoord2f(halfDepth / scaleX, height  / scaleY);					glVertex3f(halfWidth, height, halfDepth);
	glEnd();

	//SKYDOWN Floor 1
	glBindTexture(GL_TEXTURE_2D, floorInMall);
	glBegin(GL_QUADS);
	glTexCoord2d(-halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(-halfWidth, 0, halfDepth);
	glTexCoord2d(halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(halfWidth, 0, halfDepth);
	glTexCoord2d(halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(halfWidth, 0, -halfDepth);
	glTexCoord2d(-halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(-halfWidth, 0, -halfDepth);
	glEnd();
	

	//SKYUP FLoor 1
	glBindTexture(GL_TEXTURE_2D, floorInMall);
	glBegin(GL_QUADS);
	//Left Side
	glTexCoord2f(-halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(-halfWidth, (height / 2) - 1.5, -halfDepth);
	glTexCoord2f(-5 / scaleX, -halfDepth / scaleY);						glVertex3f(-5, (height / 2) - 1.5, -halfDepth);
	glTexCoord2f(-5 / scaleX, halfDepth/ scaleY);						glVertex3f(-5, (height / 2) - 1.5, halfDepth);
	glTexCoord2f(-halfWidth / scaleX, halfDepth/scaleY);				glVertex3f(-halfWidth, (height / 2) - 1.5, halfDepth);
	//Right Side
	glTexCoord2f(halfWidth /scaleX, -halfDepth / scaleY);				glVertex3f(halfWidth, (height / 2) - 1.5, -halfDepth);
	glTexCoord2f(5/ scaleX, -halfDepth / scaleY);						glVertex3f(5, (height / 2) - 1.5, -halfDepth);
	glTexCoord2f(5 / scaleX, halfDepth / scaleY);						glVertex3f(5, (height / 2) - 1.5, halfDepth);
	glTexCoord2f(halfWidth / scaleX , halfDepth / scaleY);				glVertex3f(halfWidth, (height / 2) - 1.5, halfDepth);
	//Front Middle
	glTexCoord2f(-5 / scaleX, -20 / scaleY);							glVertex3f(-5, (height / 2) - 1.5, -20);
	glTexCoord2f(5 / scaleX, -20 / scaleY);								glVertex3f(5, (height / 2) - 1.5, -20);
	glTexCoord2f(5.0 / scaleX, -5 / scaleY);							glVertex3f(5, (height / 2) - 1.5, -5);
	glTexCoord2f(-5 / scaleX, -5 / scaleY);								glVertex3f(-5, (height / 2) - 1.5, -5);
	//Back Middle
	glTexCoord2f(-5 / scaleX,halfDepth / scaleY);						glVertex3f(-5, (height / 2) - 1.5, halfDepth);
	glTexCoord2f(5 / scaleX, halfDepth / scaleY);						glVertex3f(5, (height / 2) - 1.5, halfDepth);
	glTexCoord2f(5 / scaleX, 5 / scaleY);								glVertex3f(5, (height / 2) - 1.5, 5);
	glTexCoord2f(-5 / scaleX,5 / scaleY);								glVertex3f(-5, (height / 2) - 1.5, 5);
	glEnd();


	glSetColor3f(1, 1, 1);
	



	//Ground Floor 2
	glBindTexture(GL_TEXTURE_2D, floorInMall);
	glBegin(GL_QUADS);
	//Left Side
	glTexCoord2f(-halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(-halfWidth, (height / 2), halfDepth);
	glTexCoord2f(-5.0f / scaleX, halfDepth / scaleY);					glVertex3f(-5, (height / 2), halfDepth);
	glTexCoord2f(-5.0f / scaleX, -halfDepth / scaleY);					glVertex3f(-5, (height / 2), -halfDepth);
	glTexCoord2f(-halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(-halfWidth, (height / 2), -halfDepth);
	//Right side
	glTexCoord2f(halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(halfWidth, (height / 2), halfDepth);
	glTexCoord2f(5.0f / scaleX, halfDepth / scaleY);					glVertex3f(5, (height / 2), halfDepth);
	glTexCoord2f(5.0f / scaleX, -halfDepth / scaleY);					glVertex3f(5, (height / 2), -halfDepth);
	glTexCoord2f(halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(halfWidth, (height / 2), -halfDepth);
	//Front Middle
	glTexCoord2f(-5.0f / scaleX, -20.0f / scaleY);						glVertex3f(-5, (height / 2), -20);
	glTexCoord2f(5.0f / scaleX, -20.0f / scaleY);						glVertex3f(5, (height / 2), -20);
	glTexCoord2f(5.0f / scaleX, -5.0f / scaleY);						glVertex3f(5, (height / 2), -5);
	glTexCoord2f(-5.0f / scaleX, -5.0f / scaleY);						glVertex3f(-5, (height / 2), -5);
	//Back Middle
	glTexCoord2f(-5 / scaleX, halfDepth / scaleY);						glVertex3f(-5, (height / 2), halfDepth);
	glTexCoord2f(5 / scaleX, halfDepth / scaleY);						glVertex3f(5, (height / 2), halfDepth);
	glTexCoord2f(5 / scaleX, 5 / scaleY);								glVertex3f(5, (height / 2), 5);
	glTexCoord2f(-5 / scaleX, 5/ scaleY);								glVertex3f(-5, (height / 2), 5);
	glEnd();
	glDisable(GL_TEXTURE_2D);



	//Middle Quads
	//Between SKYUP 1 and SKYDOWN 2
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	//Middle Front
	glTexCoord2f(-halfWidth / scaleX, -5.0f / scaleY);					glVertex3f(-halfWidth, height / 2, -5);
	glTexCoord2f(halfWidth / scaleX, -5.0f / scaleY);					glVertex3f(halfWidth, height / 2, -5);
	glTexCoord2f(halfWidth / scaleX, -5.0f / scaleY - 1.5f / scaleY);	glVertex3f(halfWidth, (height / 2) - 1.5, -5);
	glTexCoord2f(-halfWidth / scaleX, -5.0f / scaleY - 1.5f / scaleY);	glVertex3f(-halfWidth, (height / 2) - 1.5, -5);
	//Middle Back
	glTexCoord2f(-halfWidth / scaleX, 5.0f / scaleY);					glVertex3f(-halfWidth, height / 2, 5);
	glTexCoord2f(halfWidth / scaleX, 5.0f / scaleY);					glVertex3f(halfWidth, height / 2, 5);
	glTexCoord2f(halfWidth / scaleX, 5.0f / scaleY - 1.5f / scaleY);	glVertex3f(halfWidth, (height / 2) - 1.5, 5);
	glTexCoord2f(-halfWidth / scaleX, 5.0f / scaleY - 1.5f / scaleY);	glVertex3f(-halfWidth, (height / 2) - 1.5, 5);
	// On Stairs
	glTexCoord2f(-5.0f / scaleX, -20.0f / scaleY);						glVertex3f(-5, height / 2, -20);
	glTexCoord2f(5.0f / scaleX, -20.0f / scaleY);						glVertex3f(5, height / 2, -20);
	glTexCoord2f(5.0f / scaleX, -20.0f / scaleY - 1.5f / scaleY);		glVertex3f(5, (height / 2) - 1.5, -20);
	glTexCoord2f(-5.0f / scaleX, -20.0f / scaleY - 1.5f / scaleY);		glVertex3f(-5, (height / 2) - 1.5, -20);
	// Right Side
	glTexCoord2f(-halfDepth / scaleX, ((height / 2) - 1.5) / scaleY);	glVertex3f(5, (height / 2) - 1.5, -halfDepth);
	glTexCoord2f(halfDepth / scaleX, ((height / 2) - 1.5) / scaleY);	glVertex3f(5, (height / 2) - 1.5, halfDepth);
	glTexCoord2f(halfDepth / scaleX, (height / 2) / scaleY);			glVertex3f(5, (height / 2), halfDepth);
	glTexCoord2f(-halfDepth / scaleX, (height / 2) / scaleY);			glVertex3f(5, (height / 2), -halfDepth);
	// Left Side
	glTexCoord2f(-halfDepth / scaleX, ((height / 2) - 1.5) / scaleY);	glVertex3f(-5, (height / 2) - 1.5, -halfDepth);
	glTexCoord2f(halfDepth / scaleX, ((height / 2) - 1.5) / scaleY);	glVertex3f(-5, (height / 2) - 1.5, halfDepth);
	glTexCoord2f(halfDepth / scaleX, (height / 2) / scaleY);			glVertex3f(-5, (height / 2), halfDepth);
	glTexCoord2f(-halfDepth / scaleX, (height / 2) / scaleY);			glVertex3f(-5, (height / 2), -halfDepth);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Roof Floor 2
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, floorInMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(-halfWidth, height - 1.5, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, -halfDepth / scaleY);				glVertex3f(halfWidth, height - 1.5, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(halfWidth, height - 1.5, halfDepth);
	glTexCoord2f(-halfWidth / scaleX, halfDepth / scaleY);				glVertex3f(-halfWidth, height - 1.5, halfDepth);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	

	//Glass On Floor 2 In The Middle
	/*float alpha = 0.35;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.5f, 0.7f, 1.0f, alpha);
	glBegin(GL_QUADS);
	
	glEnd();
	glColor4f(1.0f, 1.0f, 1.0, alpha);*/



	glSetColor3f(1, 1, 1);
}
void Mall::DrawMarkets() {
	glPushMatrix();
	glTranslatef(-25, 0, -20);
	Restaurant restaurant(29, 10, 20);
	restaurant.Draw();
	restaurant.DrawOuterRestaurant();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(25, 0, 20);
	Coffee coffee(30, 11, 20);
	coffee.draw();
	glPopMatrix();

	glSetColor3f(1, 1, 1);
	
}
void Mall::DrawOuterMall() {
	float halfWidth = width / 2;
	float halfDepth = depth / 2;
	float offset = 0.01;
	float scaleX = 7.0f;
	float scaleY = 7.0f;

	glSetColor3f(1, 1, 1);
	// Front Face
	glEnable(GL_TEXTURE_2D);


	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, 0);									glVertex3f(-halfWidth - offset, 0, halfDepth + offset);
	glTexCoord2f(-5 / scaleX, 0);											glVertex3f(-5, 0, halfDepth + offset);
	glTexCoord2f(- 5 / scaleX, height / scaleY);							glVertex3f(-5, height, halfDepth + offset);
	glTexCoord2f(-halfWidth / scaleX, height / scaleY);						glVertex3f(-halfWidth - offset, height, halfDepth + offset);

	glTexCoord2f(halfWidth / scaleX, 0);									glVertex3f(halfWidth + offset, 0, halfDepth + offset);
	glTexCoord2f(5 / scaleX, 0);											glVertex3f(5, 0, halfDepth + offset);
	glTexCoord2f(5 / scaleX, height / scaleY);								glVertex3f(5, height, halfDepth + offset);
	glTexCoord2f(halfWidth / scaleX, height / scaleY);						glVertex3f(halfWidth + offset, height, halfDepth + offset);

	glTexCoord2f(-5 / scaleX, 5 / scaleY);									glVertex3f(-5, 5, halfDepth + offset);
	glTexCoord2f(5 / scaleX, 5 / scaleY);									glVertex3f(5, 5, halfDepth + offset);
	glTexCoord2f(5 / scaleX, height / scaleY);								glVertex3f(5, height, halfDepth + offset);
	glTexCoord2f(-5 / scaleX, height / scaleY);								glVertex3f(-5, height, halfDepth + offset);
	glEnd();

	// Right Face
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfDepth / scaleX, 0);									glVertex3f(halfWidth + offset, 0, -halfDepth - offset);
	glTexCoord2f(halfDepth / scaleX, 0);									glVertex3f(halfWidth + offset, 0, halfDepth + offset);
	glTexCoord2f(halfDepth / scaleX, height / scaleY);						glVertex3f(halfWidth + offset, height, halfDepth + offset);
	glTexCoord2f(-halfDepth / scaleX, height / scaleY);						glVertex3f(halfWidth + offset, height, -halfDepth - offset);
	glEnd();

	// Back Face 
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, 0);									glVertex3f(-halfWidth - offset, 0, -halfDepth - offset);
	glTexCoord2f(halfWidth / scaleX, 0);									glVertex3f(halfWidth + offset, 0, -halfDepth - offset);
	glTexCoord2f(halfWidth / scaleX, height / scaleY);						glVertex3f(halfWidth + offset, height, -halfDepth - offset);
	glTexCoord2f(-halfWidth / scaleX, height / scaleY);						glVertex3f(-halfWidth - offset, height, -halfDepth - offset);
	glEnd();

	// Left Face
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfDepth / scaleX, 0);									glVertex3f(-halfWidth - offset, 0, -halfDepth - offset);
	glTexCoord2f(halfDepth / scaleX, 0);									glVertex3f(-halfWidth - offset, 0, halfDepth + offset);
	glTexCoord2f(halfDepth / scaleX, height/ scaleY);						glVertex3f(-halfWidth - offset, height, halfDepth + offset);
	glTexCoord2f(-halfDepth / scaleX, height / scaleY);						glVertex3f(-halfWidth - offset, height, -halfDepth - offset);
	glEnd();

	//Mall Roof
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-halfWidth / scaleX, -halfDepth / scaleY);					glVertex3f(-halfWidth, height, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, -halfDepth / scaleY);					glVertex3f(halfWidth, height, -halfDepth);
	glTexCoord2f(halfWidth / scaleX, halfDepth / scaleY);					glVertex3f(halfWidth, height, halfDepth);
	glTexCoord2f(-halfWidth / scaleX, halfDepth / scaleY);					glVertex3f(-halfWidth, height, halfDepth);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glSetColor3f(1, 1, 1);
}
void Mall::DrawGlass() {

	float halfWidth = width / 2;
	float halfDepth = depth / 2;
	float offset = 0.01;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	glColor4f(0.5, 0.7, 1.0, 0.25);

	glBegin(GL_QUADS);
	glVertex3f(-5 + offset, 0, halfDepth);
	glVertex3f(-2, 0, halfDepth);
	glVertex3f(-2, 5, halfDepth);
	glVertex3f(-5 + offset, 5, halfDepth);

	glVertex3f(5 - offset, 0, halfDepth);
	glVertex3f(2, 0, halfDepth);
	glVertex3f(2, 5, halfDepth);
	glVertex3f(5 - offset, 5, halfDepth);


	//Right
	glVertex3f(5, (height / 2), -5);
	glVertex3f(5, (height / 2) + 1.5, -5);
	glVertex3f(5, (height / 2) + 1.5, 5);
	glVertex3f(5, (height / 2), 5);
	//Left
	glVertex3f(-5, (height / 2), -5);
	glVertex3f(-5, (height / 2) + 1.5, -5);
	glVertex3f(-5, (height / 2) + 1.5, 5);
	glVertex3f(-5, (height / 2), 5);
	//Back
	glVertex3f(5 - offset, height / 2, 5);
	glVertex3f(5 - offset, (height / 2) + 1.5, 5);
	glVertex3f(-5 + offset, (height / 2) + 1.5, 5);
	glVertex3f(-5 + offset, (height / 2), 5);
	//Front
	glVertex3f(5 - offset, height / 2, -5);
	glVertex3f(5 - offset, (height / 2) + 1.5, -5);
	glVertex3f(-5 + offset, (height / 2) + 1.5, -5);
	glVertex3f(-5 + offset, (height / 2), -5);
	glEnd();

	//Restaurant Glass
	glPushMatrix();
	glTranslatef(-25, 0, -20);
	glBegin(GL_QUADS);
	glVertex3f(-13.5, 1, 10);
	glVertex3f(-3.5, 1, 10);
	glVertex3f(-3.5, 9, 10);
	glVertex3f(-13.5, 9, 10);

	glVertex3f(13.5, 1, 10);
	glVertex3f(3.5, 1, 10);
	glVertex3f(3.5, 9, 10);
	glVertex3f(13.5, 9, 10);
	glEnd();
	glPopMatrix();
	
	//Coffee Glass
	glColor4f(0.5, 0.25, 0.25, 0.25);
	glPushMatrix();
	glTranslatef(25, 0, 20);
		//Right Glass
		glBegin(GL_QUADS);
		glVertex3f(-15, 0.75, 9.25);
		glVertex3f(-15, 0.75, -10);
		glVertex3f(-15, 10.25, -10);
		glVertex3f(-15, 10.25, 9.25);
		glEnd();
		//Front Glass
		glBegin(GL_QUADS);
		glVertex3f(-15, 0.75, -10);
		glVertex3f(-15, 10.25, -10);
		glVertex3f(-10, 10.25, -10);
		glVertex3f(-10, 0.75, -10);

		glVertex3f(15, 0.75, -10);
		glVertex3f(15, 10.25, -10);
		glVertex3f(-5, 10.25, -10);
		glVertex3f(-5, 0.75, -10);

		glVertex3f(-10, 5, -10);
		glVertex3f(-10, 10.25, -10);
		glVertex3f(-5, 10.25, -10);
		glVertex3f(-5, 5, -10);
		glEnd();
		glPopMatrix();



	//Finish The glasses in mall.
	glColor4f(1, 1, 1, 1);
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	
}
void Mall::DrawStairs() {
	float offset = 0.01;
	float scaleX = 7.0f, scaleY = 7.0f;

	glSetColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);

	//Left Side
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-10 / scaleX, 0);										glVertex3f(-10, 0, -20);
	glTexCoord2d(-5 / scaleX, 0);										glVertex3f(-5, 0, -20);
	glTexCoord2f(-5 / scaleX, 11 / scaleY);								glVertex3f(-5, 11, -20);
	glTexCoord2f(-10 / scaleX, 11 / scaleY);							glVertex3f(-10, 11, -20);

	glTexCoord2f(-20 / scaleX, 0);										glVertex3f(-5, 0, -20);
	glTexCoord2f(-30 / scaleX, 0);										glVertex3f(-5, 0, -30);
	glTexCoord2f(-30 / scaleX, 11 / scaleY);							glVertex3f(-5, 11, -30);
	glTexCoord2f(-20 / scaleX, 11 / scaleY);							glVertex3f(-5, 11, -20);
	glEnd();


	//Right Side
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2f(10 / scaleX, 0);										glVertex3f(10, 0, -20);
	glTexCoord2f(5 / scaleX, 0);										glVertex3f(5, 0, -20);
	glTexCoord2f(5 / scaleX, 11 / scaleY);								glVertex3f(5, 11, -20);
	glTexCoord2f(10 / scaleX, 11 / scaleY);								glVertex3f(10, 11, -20);

	glTexCoord2f(-20 / scaleX, 0);										glVertex3f(5, 0, -20);
	glTexCoord2f(-30 / scaleX, 0);										glVertex3f(5, 0, -30 );
	glTexCoord2f(-30 / scaleX, 11 / scaleY);							glVertex3f(5, 11, -30);
	glTexCoord2f(-20 / scaleX, 11 / scaleY);							glVertex3f(5, 11, -20);
	glEnd();

	//Front Side
	glBindTexture(GL_TEXTURE_2D, upDoorMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-5 / scaleX, 6.25 / scaleY);								glVertex3f(-5, 6.25, -20);
	glTexCoord2f(-5 / scaleX, 11 / scaleY);									glVertex3f(-5 , 11, -20);
	glTexCoord2f(5 / scaleX, 11 / scaleY);									glVertex3f(5 , 11, -20);
	glTexCoord2f(5 / scaleX, 6.25/ scaleY);									glVertex3f(5, 6.25, -20);
	glEnd();
	
	//Draw First Stairs 
	float height = 0.625;
	float depth = -20.7;

	for (int i = 0; i < 10; i++, height+= 0.625f, depth -= 0.7f) {
		float oldHeight = height - 0.625f;
		float oldDepth = depth + 0.7f;

		//Front
		glBindTexture(GL_TEXTURE_2D, stairsDown);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);													glVertex3f(5, oldHeight, oldDepth);
		glTexCoord2f(4, 0);													glVertex3f(1, oldHeight, oldDepth);
		glTexCoord2f(4, 1);													glVertex3f(1, height, oldDepth);
		glTexCoord2f(0, 1);													glVertex3f(5, height, oldDepth);
		glEnd();
		//Down
		glBindTexture(GL_TEXTURE_2D, stairsDown);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);													glVertex3f(5, height, oldDepth);
		glTexCoord2f(0, 1);													glVertex3f(5, height, depth);
		glTexCoord2f(4, 1);													glVertex3f(1, height, depth);
		glTexCoord2f(4, 0);													glVertex3f(1, height, oldDepth);
		glEnd();
		//Lefty
		glBindTexture(GL_TEXTURE_2D, upDoorMall);
		glBegin(GL_QUADS);
		glTexCoord2f(oldDepth / scaleX, 0);									glVertex3f(1, 0, oldDepth);
		glTexCoord2f(oldDepth / scaleX, height / scaleY);					glVertex3f(1, height, oldDepth);
		glTexCoord2f(depth / scaleX, height / scaleY);						glVertex3f(1, height, depth);
		glTexCoord2f(depth / scaleX, 0);									glVertex3f(1, 0, depth);
		glEnd();
	}

	//Draw Second Stairs
	 height = 6.875;
	 depth = -26.3;

	for (int i = 0; i < 10; i++, height += 0.625f, depth += 0.7f) {
		float oldHeight = height - 0.625f;
		float oldDepth = depth - 0.7f;

		//Front
		glBindTexture(GL_TEXTURE_2D, stairsDown);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);													glVertex3f(-5, oldHeight, oldDepth);
		glTexCoord2f(4, 0);													glVertex3f(-1, oldHeight, oldDepth);
		glTexCoord2f(4, 1);													glVertex3f(-1, height, oldDepth);
		glTexCoord2f(0, 1);													glVertex3f(-5, height, oldDepth);
		glEnd();
		//Down
		glBindTexture(GL_TEXTURE_2D, stairsDown);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);													glVertex3f(-5, height, oldDepth);
		glTexCoord2f(4, 0);													glVertex3f(-5, height, depth);
		glTexCoord2f(4, 1);													glVertex3f(-1, height, depth);
		glTexCoord2f(0, 1);													glVertex3f(-1, height, oldDepth);
		glEnd();
		//Lefty
		glBindTexture(GL_TEXTURE_2D, upDoorMall);
		glBegin(GL_QUADS);
		glTexCoord2f(oldDepth / scaleX, 6.25 / scaleY);						glVertex3f(-1, 6.25, oldDepth);
		glTexCoord2f(oldDepth / scaleX, height / scaleY);					glVertex3f(-1, height, oldDepth);
		glTexCoord2f(depth / scaleX, height / scaleY);						glVertex3f(-1, height, depth);
		glTexCoord2f(depth / scaleX, 6.25 / scaleY);						glVertex3f(-1, 6.25, depth);
		glEnd();
	}

	//Between stairs
	glBindTexture(GL_TEXTURE_2D, wallInMall);
	glBegin(GL_QUADS);
	glTexCoord2f(5 / scaleX, -27/ scaleY);									glVertex3f(5, 6.25, -27);
	glTexCoord2f(5 / scaleX, -30 / scaleY);									glVertex3f(5, 6.25, -30);
	glTexCoord2f(-5 / scaleX, -30 / scaleY);								glVertex3f(-5, 6.25, -30);
	glTexCoord2f(-5 / scaleX, -27 / scaleY);								glVertex3f(-5, 6.25, -27);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, wallInMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-5 / scaleX, 0);											glVertex3f(-5, 0, -27);
	glTexCoord2f(5 / scaleX, 0);											glVertex3f(5, 0, -27);
	glTexCoord2f(5 / scaleX, 6.25 / scaleY);								glVertex3f(5, 6.25, -27);
	glTexCoord2f(-5 / scaleX, 6.25/ scaleY);								glVertex3f(-5, 6.25, -27);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, wallInMall);
	glBegin(GL_QUADS);
	glTexCoord2f(-5 / scaleX, -20/ scaleY);									glVertex3f(-5 + offset, 6.25, -20 - offset);
	glTexCoord2f(-1 / scaleX, -20 / scaleY);								glVertex3f(-1, 6.25, -20 - offset);
	glTexCoord2f(-1 / scaleX, -27 / scaleY);								glVertex3f(-1, 6.25, -27 + offset);
	glTexCoord2f(-5 / scaleX, -27 / scaleY);								glVertex3f(-5, 6.25, -27 + offset);
	glEnd();

	glSetColor3f(1, 1, 1);
}

void Mall::Draw() {
	glSetColor3f(1, 1, 1);
	//Draw Markets
	DrawMarkets();

	//Outer Mall and Mall SkyBlock
	DrawMallSkyBlock();
	DrawOuterMall();

	//Draw Mall Glasses
	DrawGlass();
	glPushMatrix();
	DrawStairs();
	glPopMatrix();

	glSetColor3f(1, 1, 1);
}