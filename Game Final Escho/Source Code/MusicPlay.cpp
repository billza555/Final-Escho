#include "header.h"
#include "MusicPlay.h"

MusicPlay::MusicPlay()
{
	this->menuMusic.openFromFile("Music//menu.mp3");
	this->scoreBoard.openFromFile("Music//scoreBoard.mp3");
	this->playGame.openFromFile("Music//playing.mp3");
	this->shop.openFromFile("Music//shopping.mp3");
	this->win.openFromFile("Music//win.mp3");

	this->menuMusic.setVolume(70);
	this->playGame.setVolume(50);
	this->scoreBoard.setVolume(40);
	this->shop.setVolume(70);
	this->win.setVolume(50);

	this->getItems.loadFromFile("Music//getItem.wav");
	this->shoots.loadFromFile("Music//shoot.wav");
	this->hits.loadFromFile("Music//hit.wav");
	this->moves.loadFromFile("Music//move.wav");
	this->drops.loadFromFile("Music//drop.wav");
	this->opens.loadFromFile("Music//open.wav");
	this->losses.loadFromFile("Music//loss.wav");

	this->getItem.setBuffer(this->getItems);
	this->shoot.setBuffer(this->shoots);
	this->hit.setBuffer(this->hits);
	this->move.setBuffer(this->moves);
	this->drop.setBuffer(this->drops);
	this->open.setBuffer(this->opens);
	this->loss.setBuffer(this->losses);

	this->getItem.setVolume(50);
	this->shoot.setVolume(50);
	this->hit.setVolume(50);
	this->move.setVolume(10);
	this->drop.setVolume(50);
	this->open.setVolume(50);
	this->loss.setVolume(100);

	this->moveTime = 0;
}

MusicPlay::~MusicPlay()
{
}

void MusicPlay::playMove(const float& dt)
{
	if (this->moveTime > 0.5f)
	{
		this->move.play();
		this->moveTime = 0.f;
	}
	else
	{
		this->moveTime += dt;
	}
}
