#pragma once

class Map
{
private:
	View view;

	Texture textureBackground;

	Texture decorate[4];
	
	Vector2f sizeob;

	RectangleShape obstruct;

	Vector2f position;
	Vector2f scale;

	float clickRec;

	void initObstruct();
	void initDecorate();

	RectangleShape decorateObject[4];
public:
	RectangleShape background;
	vector<RectangleShape> obstructs;
	vector<RectangleShape> object;

	bool lock;

	Map();
	virtual ~Map();

	const bool getClick();

	void Obstructions();

	void saveToFile(const string file_name);
	void loadFromFile(const string file_name);

	void updateClick(const float& dt);
	void updateObstruction(const float& dt, Vector2f& mousePosView);
	void update(const float& dt, Vector2f& mousePosView);

	void renderObstructs(RenderTarget* target);
	void renderDecorate(RenderTarget* target);
	void render(RenderTarget* target);
};

