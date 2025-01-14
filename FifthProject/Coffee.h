#ifndef COFFEE_H
#define COFFEE_H


#include <GL/glut.h>
extern void glSetColor3f(float r, float g, float b);

class Coffee {
public:
	float width, height, depth, offset = 0.01;
	Coffee(float w, float h, float d);
	void Coffee::drawCoffeeSkyBlock();
	void drawOuterCoffee();
	void draw();
	void drawSingleTable(float x, float y, float z);
	void drawDoubleTable(float x, float y, float z);
	void drawCoffeeShop();
};
#endif