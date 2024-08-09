#pragma once
class Menu
{
private:
	RectangleShape rec;
	Text keyword;

	RectangleShape menuBackground;
	Texture menuTexture;

	RectangleShape exitBackground;
	Text word;

	Texture textureWinBackground;

	RectangleShape button;
	Text back;

	Text scores;

	Text winText;
public:
	Font textureWord;
	RectangleShape exit;
	bool menuState;
	bool buttonPress;
	RectangleShape winBackground;
	int scoretime;
	Menu();
	virtual ~Menu();

	const FloatRect getGlobalBounds() const;

	void updateButton(float x, float y, float width, float height, String word, int fontSize);
	void updateMenuButton(const float& dt, Vector2f mousePosView);
	void updateScore(const float& dt);
	void renderButton(RenderTarget* target);
	void renderMenuBackground(RenderTarget* target);
	void renderExitBackground(RenderTarget* target);
	void renderWinBackground(RenderTarget* target);
	void render(RenderTarget* target);
};

