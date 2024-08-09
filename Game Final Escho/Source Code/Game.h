#pragma once
#include "SaveAndLoad.h"
#include "ScoreBoard.h"
class Game
{
private:
	RenderWindow* window;
	Event event;

	Clock clock;
	float dt;

	Map background;

	Player player;

	map<string, Menu> menu;
	Menu exit;

	Vector2i mousePosWindow;
	Vector2f mousePosView;

	Alliance shop;

	Enemy enemy;

	Bush bush;

	itemShop itemShop;

	bool die;

	SelectingMenu selecting;

	SaveAndLoad saveAndLoad;

	string name;
	Text namePlayer;
	float writeTime;
	Text enterName;

	MusicPlay music;

	bool save;

	bool load;
	bool loading;

	bool select;

	bool sell;
	bool bottle;

	ScoreBoard scoreBoard;
	bool board;

	string bulletData;
	string enemyData;

	int d;

	void initVariables();
	void initWindow();
	void initMenu();
public:
	View view;
	Game();
	virtual ~Game();

	void loadState();

	void updateMousePosition();
	void updateInput();
	void updateMenu();
	void updateDt();
	void updateEvents();
	void updateSelecting();
	void updateSave();
	void updateLoad();
	void updateScoreBoard();
	void update();

	void render();

	void run();
};

