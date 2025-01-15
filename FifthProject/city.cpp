#include <glut.h>
#include <GL.H>
#include "city.h"
#include "Model_3DS.h"
#include "texture.h"

extern Model_3DS* tree;
extern GLTexture BARK, Leaf;
extern int  Front, Ground, Left, Right, Back, Up;
extern int grass, fbuilding, street, ubuilding;
extern int fbuilding2, fbuilding3, fbuilding4, CenterStreet, SideWalk, water;
void city::Draw() {
	int x = 250;
	glColor3f(1,1,1);
	glEnable(GL_TEXTURE_2D);
	// Draw ground side
	glPushMatrix();
	glTranslatef(0, -0.02, 0);
	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Ground);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, -x, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, x, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-x, x, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-x, -x, 0);
	glEnd();
	glPopMatrix();

	//خلية فوق يمين
	int y = 50;
	glPushMatrix();
	glTranslatef(75, 0, -75);
	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grass);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(y, -y, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(y, y, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-y, y, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-y, -y, 0);
	glEnd();
	glPopMatrix();

	//خلية فوق يسار
	glPushMatrix();
	glTranslatef(-75, 0, -75);
	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grass);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(y, -y, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(y, y, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-y, y, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-y, -y, 0);
	glEnd();
	glPopMatrix();

	//خلية تحت يمين
	glPushMatrix();
	glTranslatef(75, 0, 75);
	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grass);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(y, -y, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(y, y, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-y, y, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-y, -y, 0);
	glEnd();
	glPopMatrix();


	//خلية تحت يسار
	glPushMatrix();
	glTranslatef(-75, 0, 75);
	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grass);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(y, -y, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(y, y, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-y, y, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-y, -y, 0);
	glEnd();
	glPopMatrix();


	// رسم بناء خلية فوق يمين
	glPushMatrix();
	glTranslatef(35, 15, -35);
	drawBuildingType1(20, 30, 20);
	glTranslatef(0, 10, -20);
	drawBuildingType2(20, 50, 20);
	glTranslatef(0, -5, -20);
	drawBuildingType3(20, 40, 20);
	glTranslatef(0, -5, -20);
	drawBuildingType1(20, 30, 20);
	glTranslatef(0, -5, -20);
	drawBuildingType4(20, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(55, 10, -35);
	drawBuildingType4(20, 20, 20);
	glTranslatef(20, 10, 0);
	drawBuildingType3(20, 40, 20);
	glTranslatef(20, -5, 0);
	drawBuildingType1(20, 30, 20);
	glTranslatef(20, 10, 0);
	drawBuildingType2(20, 50, 20);
	glPopMatrix();


	// رسم شارع وسط
	int z = 15;
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, street);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(200, -z, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(200, z, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-200, z, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-200, -z, 0);
	glEnd();
	glPopMatrix();

	// رسم شارع فوق
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, street);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(200, -z, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(200, z, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-200, z, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-200, -z, 0);
	glEnd();

	glPopMatrix();



	// رسم بناء خلية تحت يسار
	glPushMatrix();
	glTranslatef(-35, 15, 35);
	drawBuildingType1(20, 30, 20);
	glTranslatef(0, 10, 20);
	drawBuildingType2(20, 50, 20);
	glTranslatef(0, -5, 20);
	drawBuildingType3(20, 40, 20);
	glTranslatef(0, -5, 20);
	drawBuildingType1(20, 30, 20);
	glTranslatef(0, -5, 20);
	drawBuildingType4(20, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-55, 10, 35);
	drawBuildingType4(20, 20, 20);
	glTranslatef(-20, 10, 0);
	drawBuildingType3(20, 40, 20);
	glTranslatef(-20, -5, 0);
	drawBuildingType1(-20, 30, 20);
	glTranslatef(-20, 10, 0);
	drawBuildingType2(20, 50, 20);
	glPopMatrix();


	// رسم منصف
	glPushMatrix();
	glTranslatef(0, 0, 105);
	drawCenterStreet(2, 2, 160);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -105);
	drawCenterStreet(2, 2, 160);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, 105);
	drawCenterStreet(2, 2, 160);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -105);
	drawCenterStreet(2, 2, 160);
	glPopMatrix();


	// رسم رصيف
	glPushMatrix();
	glTranslatef(20, 0, -90);
	drawSideWalk(10.00f, 2.00f, 150.00f, 1.0f, 60.0f);
	glTranslatef(70, 0, 70);
	glRotatef(90, 0, 1, 0);
	drawSideWalk(10.00f, 2.00f, 150.00f, 1.0f, 60.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20, 0, +90);
	drawSideWalk(10.00f, 2.00f, 150.00f, 1.0f, 60.0f);
	glTranslatef(70, 0, -70);
	glRotatef(90, 0, 1, 0);
	drawSideWalk(10.00f, 2.00f, 150.00f, 1.0f, 60.0f);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-20, 0, -90);
	drawSideWalk(10.00f, 2.00f, 150.00f, 1.0f, 60.0f);
	glTranslatef(-70, 0, 70);
	glRotatef(90, 0, 1, 0);
	drawSideWalk(10.00f, 2.00f, 150.00f, 1.0f, 60.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20, 0, +90);
	drawSideWalk(10.00f, 2.00f, 150.00f, 1.0f, 60.0f);
	glTranslatef(-70, 0, -70);
	glRotatef(90, 0, 1, 0);
	drawSideWalk(10.00f, 2.00f, 150.00f, 1.0f, 60.0f);
	glPopMatrix();


	//رسم البحيرة
	glPushMatrix();
	glTranslatef(75, 0.01, 75);
	glRotatef(90, 1, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, water);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(30, -30, 0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(30, 30, 0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-30, 30, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-30, -30, 0);
	glEnd();
	glPopMatrix();

	//شجر البحيرة
	tree->scale = 3;
	glPushMatrix();
	glTranslatef(40, 0, 40);
	tree->Draw();
	glTranslatef(35, 0, 0);
	tree->Draw();
	glTranslatef(35, 0, 0);
	tree->Draw();
	glTranslatef(0, 0, 40);
	tree->Draw();
	glTranslatef(0, 0, 40);
	tree->Draw();
	glTranslatef(-35, 0, 0);
	tree->Draw();
	glTranslatef(-35, 0, 0);
	tree->Draw();
	glTranslatef(0, 0, -40);
	tree->Draw();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
}
void  city::drawCubeWithTexture(float width, float height, float depth) {
	glPushMatrix();
	glScalef(width, height, depth);

	glBindTexture(GL_TEXTURE_2D, fbuilding); // ربط الإكساء

	glBegin(GL_QUADS);

	// الوجه الأمامي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);

	// الوجه الخلفي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);

	// الوجه العلوي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

	// الوجه السفلي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);

	// الوجه الأيمن
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);

	// الوجه الأيسر
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();

	glPopMatrix();
}
void  city::drawBuildingType1(float width, float height, float depth) {
	glPushMatrix();
	glScalef(width, height, depth);

	glBindTexture(GL_TEXTURE_2D, fbuilding); // ربط الإكساء
	glBegin(GL_QUADS);
	// الوجه الأمامي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);

	// الوجه الخلفي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();


	// الوجه العلوي
	glBindTexture(GL_TEXTURE_2D, ubuilding);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	// الوجه السفلي
	glBindTexture(GL_TEXTURE_2D, fbuilding);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);

	// الوجه الأيمن
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);

	// الوجه الأيسر
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	glPopMatrix();
}
void  city::drawBuildingType2(float width, float height, float depth) {
	glPushMatrix();
	glScalef(width, height, depth);

	glBindTexture(GL_TEXTURE_2D, fbuilding2); // ربط الإكساء
	glBegin(GL_QUADS);
	// الوجه الأمامي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);

	// الوجه الخلفي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();


	// الوجه العلوي
	glBindTexture(GL_TEXTURE_2D, ubuilding);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	// الوجه السفلي
	glBindTexture(GL_TEXTURE_2D, fbuilding2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);

	// الوجه الأيمن
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);

	// الوجه الأيسر
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	glPopMatrix();
}
void  city::drawBuildingType3(float width, float height, float depth) {
	glPushMatrix();
	glScalef(width, height, depth);

	glBindTexture(GL_TEXTURE_2D, fbuilding3); // ربط الإكساء
	glBegin(GL_QUADS);
	// الوجه الأمامي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);

	// الوجه الخلفي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();


	// الوجه العلوي
	glBindTexture(GL_TEXTURE_2D, ubuilding);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	// الوجه السفلي
	glBindTexture(GL_TEXTURE_2D, fbuilding3);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);

	// الوجه الأيمن
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);

	// الوجه الأيسر
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	glPopMatrix();
}
void  city::drawBuildingType4(float width, float height, float depth) {
	glPushMatrix();
	glScalef(width, height, depth);

	glBindTexture(GL_TEXTURE_2D, fbuilding4); // ربط الإكساء
	glBegin(GL_QUADS);
	// الوجه الأمامي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);

	// الوجه الخلفي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();


	// الوجه العلوي
	glBindTexture(GL_TEXTURE_2D, ubuilding);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	// الوجه السفلي
	glBindTexture(GL_TEXTURE_2D, fbuilding4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);

	// الوجه الأيمن
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);

	// الوجه الأيسر
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();

	glPopMatrix();
}
void  city::drawCenterStreet(float width, float height, float depth) {
	glPushMatrix();
	glScalef(width, height, depth);

	glBindTexture(GL_TEXTURE_2D, CenterStreet); // ربط الإكساء

	glBegin(GL_QUADS);

	// الوجه الأمامي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);

	// الوجه الخلفي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);

	// الوجه العلوي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

	// الوجه السفلي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);

	// الوجه الأيمن
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.5f);

	// الوجه الأيسر
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();

	glPopMatrix();
}
void  city::drawSideWalk(float width, float height, float depth, float textureRepeatX, float textureRepeatY) {
	glPushMatrix();
	glScalef(width, height, depth);

	glBindTexture(GL_TEXTURE_2D, SideWalk); // ربط الإكساء

	glBegin(GL_QUADS);

	// الوجه الأمامي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(textureRepeatX, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(textureRepeatX, textureRepeatY); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, textureRepeatY); glVertex3f(-0.5f, 0.5f, 0.5f);

	// الوجه الخلفي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(textureRepeatX, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(textureRepeatX, textureRepeatY); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, textureRepeatY); glVertex3f(0.5f, 0.5f, -0.5f);

	// الوجه العلوي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(textureRepeatX, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(textureRepeatX, textureRepeatY); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, textureRepeatY); glVertex3f(-0.5f, 0.5f, -0.5f);

	// الوجه السفلي
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(textureRepeatX, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(textureRepeatX, textureRepeatY); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0.0f, textureRepeatY); glVertex3f(-0.5f, -0.5f, 0.5f);

	// الوجه الأيمن
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(textureRepeatX, 0.0f); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(textureRepeatX, textureRepeatY); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, textureRepeatY); glVertex3f(0.5f, 0.5f, 0.5f);

	// الوجه الأيسر
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(textureRepeatX, 0.0f); glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(textureRepeatX, textureRepeatY); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, textureRepeatY); glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();

	glPopMatrix();
}