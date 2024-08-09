#pragma once
class MusicPlay
{
private:
	float moveTime;

	SoundBuffer getItems;
	SoundBuffer shoots;
	SoundBuffer hits;
	SoundBuffer moves;
	SoundBuffer drops;
	SoundBuffer opens;
	SoundBuffer losses;

public:
	Music menuMusic;
	Music scoreBoard;
	Music playGame;
	Music shop;
	Music win;

	Sound getItem;
	Sound shoot;
	Sound hit;
	Sound move;
	Sound drop;
	Sound open;
	Sound loss;

	MusicPlay();
	virtual ~MusicPlay();
	
	void playMove(const float& dt);
};

