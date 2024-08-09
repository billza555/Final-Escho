#pragma once
#include "Map.h"
#include "Animation.h"
class Enemy
{
private:
	Texture textureEnemy[4];
	IntRect enemyMove[4][4];
	Sprite enemy[4];
	int maxEnemies;
	float spawn;

	Map maps;

	RectangleShape hpEnemiesBar[4];

	Font font;
	Texture textureKey;

	int hp;

	Animation animation;

	int anim[4];

public:
	vector<Sprite> enemies;
	vector<int> enemiesType;
	
	RectangleShape bullet;
	vector<RectangleShape> bullets;
	vector<int> values;

	vector<int> hpEnemies;

	RectangleShape key;
	Text textKey;

	int kei;

	bool loopMove[4];
	int velocity[4];
	int direction[4];
	float bulletTime[4];

	int EneSize;

	int scoretime;

	Enemy();
	virtual ~Enemy();

	const bool getKey() const;

	const bool getBulletTime(int i);

	void reset();
	void loadEnemies(int i, Vector2f EnemiesPosition);
	void loadBullet(Vector2f bulletScale, Vector2f bulletPosition, int value);

	void updateBulletTime(const float& dt);
	void updateBullet(const float& dt, int i, int direction, int value);
	void updateBulletMove(const float& dt);
	void updateEnemies(const float& dt);
	void updateEnemiesMove(const float& dt);
	void updateEnemiesGoTOPlayer(const float& dt, int i, int j);
	void update(const float& dt);
	void renderBullet(RenderTarget* target);
	void renderEnemies(RenderTarget* target);
	void renderHpEnemies(RenderTarget* target);
	void render(RenderTarget* target);
};

