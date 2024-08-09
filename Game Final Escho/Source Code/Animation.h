#pragma once
class Animation
{
private:
	float animationTime;
public:
	Animation();
	virtual ~Animation();

	const bool getAnimationTime();

	void move(Sprite& sprite, Texture& texture, IntRect& rec, int moveleft, int movetop);
};

