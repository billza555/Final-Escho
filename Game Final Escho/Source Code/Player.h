#pragma once
#include "SelectingMenu.h"
#include "Enemy.h"
#include "Bush.h"
#include "MusicPlay.h"
class Player
{
private:
	float velocity;
	float speedtimeMax;

	Texture texturePlayer;
	IntRect intRectPlayer[4];

	Menu menu;

	Enemy enemy;

	RectangleShape hpBar;

	RectangleShape armor;

	Alliance shop;

	RectangleShape inventoryBar;

	float speedUseInventory;

	Texture textureBackpack;
	RectangleShape backpack;

	RectangleShape gun;

	RectangleShape backpackGround[3];
	Text key[2];
	Font textureWord;

	Texture textureSpaceBar;
	RectangleShape SpaceBar;

	Bush bush;

	RectangleShape itemInventory;
	vector<RectangleShape> itemInventorys;

	float gunTime;

	RectangleShape bullet;
	vector <RectangleShape> bullets;
	int direction;
	vector<int> directions;

	RectangleShape enemyItem;
	vector<RectangleShape> enemyItemDrop;

	RectangleShape runBar;
	RectangleShape runBarMax;
	vector<RectangleShape> runningBar;

	MusicPlay music;

	Animation animation;

	void initInventory();
	void initBullet();
public:
	bool speed;
	float speedtime;
	bool useInventory;
	Sprite player;
	int hp;
	bool shopping;
	Map maps;
	View view;
	int item[9];
	bool lock;
	bool win;

	int bushSize;

	int scoretime;

	int EneSize;
	Player();
	virtual ~Player();

	void resetPlayer();
	void saveBush(const string file_name);
	void loadBush(Vector2f position);
	void loadItem(int i, Vector2f position);
	void saveBullet(const string file_name);
	void loadBullet(const string file_name);
	void saveEnemies(const string file_name);
	void loadEnemies(const string file_name);

	const bool getSpeed() const;
	const Vector2f getPosition() const;
	const FloatRect getGlobalBounds() const;

	void updateSpeedtime(const float& dt);
	void updateGun(const float& dt);
	void updateCollision(const float& dt);
	void updateExit(const float& dt);
	void updateEnemies(const float& dt);
	void updateInventory(const float& dt);
	void updateIcons(const float& dt);
	void updateBush(const float& dt);
	void updateShop(const float& dt);
	void update(const float& dt);
	void renderBullets(RenderTarget* target);
	void renderInventory(RenderTarget* target);
	void renderHpBar(RenderTarget* target);
	void renderArmor(RenderTarget* target);
	void renderClickButtonShop(RenderTarget* target);
	void renderViewPlayer(RenderTarget* target);
	void renderBush(RenderTarget* target);
	void renderIcons(RenderTarget* target);
	void renderItemDrop(RenderTarget* target);
	void render(RenderTarget* target);
};

