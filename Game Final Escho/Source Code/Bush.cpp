#include "header.h"
#include "Bush.h"

Bush::Bush()
{
	this->textureBush.loadFromFile("Resources/Supple/bush.png");
	this->bush.setTexture(&this->textureBush);
	this->bush.setSize(Vector2f(100.f, 100.f));
	this->bush.setPosition(Vector2f(338.223f, 1116.02f));

	this->bushBar.setSize(Vector2f(100.f, 20.f));
	this->bushBar.setFillColor(Color(0, 255, 0, 200));

	this->font.loadFromFile("Fonts/Moon.otf");
	this->get.setFont(this->font);
	this->get.setCharacterSize(50);
	this->get.setFillColor(Color::Black);
	this->get.setString("F");

	this->item.setSize(Vector2f(50.f, 50.f));

	this->numItem = 0;
}

Bush::~Bush()
{
}

void Bush::resetBush()
{
	this->bushs.clear();
	this->bushBars.clear();
	this->gets.clear();
	this->itemDrop.clear();
	this->numItems.clear();
}

void Bush::loadBush(Vector2f position)
{
	this->bush.setPosition(position);
	this->bush.setSize(Vector2f(100.f, 100.f));
	this->bushs.push_back(this->bush);

	this->bushBar.setPosition(this->bush.getPosition().x, this->bush.getPosition().y - 30.f);
	this->bushBar.setSize(Vector2f(100.f, 20.f));
	this->bushBar.setFillColor(Color(0, 255, 0, 200));
	this->bushBars.push_back(this->bushBar);

	this->get.setFont(this->font);
	this->get.setCharacterSize(50);
	this->get.setFillColor(Color::Black);
	this->get.setPosition(Vector2f(this->bush.getPosition().x + this->bush.getGlobalBounds().width / 2.f - this->get.getGlobalBounds().width / 2.f,
		this->bush.getPosition().y + this->bush.getGlobalBounds().height / 2.f - this->get.getGlobalBounds().height / 2.f));
	this->get.setString("F");
	this->gets.push_back(this->get);
}

void Bush::loadItem(int i, Vector2f position)
{
	this->numItem = i;
	this->numItems.push_back(this->numItem);
	this->item.setTexture(&this->alliance.TextureItems[i - 1]);
	this->item.setPosition(position);
	this->item.setSize(Vector2f(50.f, 50.f));
	this->itemDrop.push_back(this->item);
}

void Bush::updateItemDrop(const float& dt)
{
	int random = rand() % 100;
	if (random <= 50)
	{
		this->item.setTexture(&this->alliance.TextureItems[0]);
		this->numItem = 1;
		this->numItems.push_back(this->numItem);
	}
	else if (random <= 75)
	{
		this->item.setTexture(&this->alliance.TextureItems[1]);
		this->numItem = 2;
		this->numItems.push_back(this->numItem);
	}
	else if (random <= 90)
	{
		this->item.setTexture(&this->alliance.TextureItems[2]);
		this->numItem = 3;
		this->numItems.push_back(this->numItem);
	}
	else if (random <= 99)
	{
		this->item.setTexture(&this->alliance.TextureItems[3]);
		this->numItem = 4;
		this->numItems.push_back(this->numItem);
	}
	this->item.setSize(Vector2f(50.f, 50.f));
	this->itemDrop.push_back(this->item);
}

void Bush::updateBush(const float& dt)
{
	this->bush.setPosition(static_cast<float>(rand()% 2000 ), static_cast<float>(rand() % 2000));
	this->bush.setSize(Vector2f(100.f, 100.f));
	this->bushs.push_back(this->bush);

	this->bushBar.setPosition(this->bush.getPosition().x, this->bush.getPosition().y - 30.f);
	this->bushBar.setSize(Vector2f(100.f, 20.f));
	this->bushBar.setFillColor(Color(0, 255, 0, 200));
	this->bushBars.push_back(this->bushBar);

	this->get.setFont(this->font);
	this->get.setCharacterSize(50);
	this->get.setFillColor(Color::Black);
	this->get.setPosition(Vector2f(this->bush.getPosition().x + this->bush.getGlobalBounds().width / 2.f - this->get.getGlobalBounds().width / 2.f,
		this->bush.getPosition().y + this->bush.getGlobalBounds().height / 2.f - this->get.getGlobalBounds().height / 2.f));
	this->get.setString("F");
	this->gets.push_back(this->get);

}

void Bush::renderget(RenderTarget* target, int i)
{
		target->draw(this->gets[i]);
}

void Bush::renderItemDrop(RenderTarget* target)
{
	for (auto& it : this->itemDrop)
	{
		target->draw(it);
	}
}

void Bush::render(RenderTarget* target)
{
	for (auto& it : this->bushs)
	{
		target->draw(it);
	}
	for (auto& it : this->bushBars)
	{
		target->draw(it);
	}
}
