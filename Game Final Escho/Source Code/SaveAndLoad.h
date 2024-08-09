#pragma once
#include "itemShop.h"
class SaveAndLoad
{
private:
	RectangleShape background;

	Player player;

	itemShop itemshop;

	Text saveText;
	Text loadText;

	void initSave();
	void initLoad();
public:
	map<string, Menu> Button;
	Vector2f playerPosition;
	bool speed;
	float speedtime;
	int hpPlayer;
	bool useInventory;
	bool shopping;
	int item[9];
	bool win;
	bool lock;
	int scoretime;

	int bushSize;
	int itemDropSize;
	Vector2f bushsPosition[3];
	Vector2f itemDropPosition[10];
	int numItems[10];

	bool sell;
	bool bottle;

	SaveAndLoad();
	virtual ~SaveAndLoad();

	void save(const string file_name);
	void load(const string file_name);
	void loadBush(const string file_name);
	void renderSave(RenderTarget* target);
	void renderLoad(RenderTarget* target);
	void render(RenderTarget* target);
};

