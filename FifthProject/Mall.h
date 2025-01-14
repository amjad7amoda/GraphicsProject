#ifndef MALL_H
#define MALL_H

class Mall {
public:
	float width, height, depth;

	Mall(float w, float h, float d);
	void DrawMallSkyBlock();
	void DrawRestaurant();
	void DrawShopFront(float dw, float dh);
	void DrawOuterMall();
	void Draw();
	void DrawGlass();
	void DrawStairs();
};

#endif