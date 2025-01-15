#ifndef CITY_H
#define CITY_H

#include <GL/gl.h> 

class city {
public:



    void Draw();
	void drawCubeWithTexture(float width, float height, float depth);
	void drawBuildingType1(float width, float height, float depth);
	void drawBuildingType2(float width, float height, float depth);
	void drawBuildingType3(float width, float height, float depth);
	void drawBuildingType4(float width, float height, float depth);
	void drawCenterStreet(float width, float height, float depth);
	void drawSideWalk(float width, float height, float depth, float textureRepeatX, float textureRepeatY);
};

#endif#pragma once
