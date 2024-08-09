#pragma once
#include "Alliance.h"

class Bush
{
private:
	Texture textureBush;

	Font font;

	RectangleShape bush;
	RectangleShape bushBar;
	Text get;

	Alliance alliance;

public:
	RectangleShape item;
	vector<RectangleShape> bushs;
	vector<RectangleShape> bushBars;
	vector<Text> gets;
	vector<RectangleShape> itemDrop;
	int numItem;
	vector<int> numItems;
	Bush();
	virtual ~Bush();

	void resetBush();
	void loadBush(Vector2f position);
	void loadItem(int i, Vector2f position);

	void updateItemDrop(const float& dt);
	void updateBush(const float& dt);
	void renderget(RenderTarget* target, int i);
	void renderItemDrop(RenderTarget* target);
	void render(RenderTarget* target);
};

