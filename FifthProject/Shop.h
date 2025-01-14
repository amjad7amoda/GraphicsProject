#ifndef SHOP_H
#define SHOP_H

#include <GL/gl.h> // مكتبة OpenGL 

class Shop {
public:
    float shopWidth;
    float shopDepth;
    float shopHeight;
    float doorWidth;
    float doorHeight;
    float offset;
    int rightTexture, leftTexture, frontTexture;

    Shop(float width, float height , float depth);
    
    void Draw(float doorWidth, float doorHeight);
    void setFrontTexture(int front);
    void setLeftTexture(int left);
    void setRightTexture(int right);
  
};

#endif
