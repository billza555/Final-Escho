#pragma once
#include "Animation.h"
class Alliance
{
private:
	Texture textureShop;
	IntRect shopRect;

	RectangleShape textground;

	Text word;
	Font textureWord;

	Texture textureExit;

	Texture TextureItem;

	RectangleShape item;

	RectangleShape button;
	Text wordButton;

	Text cost;

	Animation animation;

	float timeAnim;

	void initThings();
public:
	vector<Texture> TextureItems;
	vector<RectangleShape> items;
	vector<int> things;
	vector<Text> costs;
	Sprite shop;
	Alliance();
	virtual ~Alliance();

	const bool getAnimationTime() const;

	const FloatRect getGlobalBonds() const;

	void createButton(float x, float y, float width, float height, Color color, string text, Color colorText, int fontSize);
	void updateCost(const float& dt);
	void updateAnimation(const float& dt);
	void renderButton(RenderTarget* target);
	void renderShopButton(RenderTarget* target);
	void render(RenderTarget* target);
};

