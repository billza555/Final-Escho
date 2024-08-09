#include "header.h"
#include "Alliance.h"

void Alliance::initThings()
{
	for (int i = 0; i < 6; i++)
	{
		int a = 0;
		this->things.push_back(a);
	}
}

Alliance::Alliance()
{
	this->textureShop.loadFromFile("Resources/Entity/shopper.png");
	this->shopRect = IntRect(0, 0, 100, 100);
	this->shop.setTexture(this->textureShop);
	this->shop.setTextureRect(this->shopRect);
	this->shop.setPosition(Vector2f(189.272f, 1396.62f));

	this->timeAnim = 0.f;

	this->textground.setSize(Vector2f(30.f, 30.f));
	this->textground.setFillColor(Color(255, 255, 255, 200));
	this->textground.setPosition(Vector2f(this->shop.getPosition().x + this->shop.getGlobalBounds().width / 2.f, this->shop.getPosition().y - 30.f));
	
	this->textureWord.loadFromFile("Fonts/Moon.otf");

	this->word.setFont(this->textureWord);
	this->word.setCharacterSize(30);
	this->word.setFillColor(Color::Black);
	this->word.setString("F");
	this->word.setPosition(Vector2f(this->textground.getPosition().x + this->textground.getGlobalBounds().width / 2.f - this->word.getGlobalBounds().width / 2.f, 
		this->textground.getPosition().y + this->textground.getGlobalBounds().height / 2.f - this->word.getGlobalBounds().height ));

	this->TextureItem.loadFromFile("Resources/Supple/apple.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/papaya.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/banana.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/orange.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/gun.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/armor.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/money.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/boot.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/bottle.png");
	this->TextureItems.push_back(this->TextureItem);
	this->TextureItem.loadFromFile("Resources/Supple/arrow.png");
	this->TextureItems.push_back(this->TextureItem);

	for (int i = 0; i < this->TextureItems.size(); i++)
	{
		this->item.setTexture(&this->TextureItems[i]);
		this->item.setSize(Vector2f(100.f, 100.f));
		this->items.push_back(this->item);
	}

	this->initThings();
}

Alliance::~Alliance()
{
}

const bool Alliance::getAnimationTime() const
{
	if (this->timeAnim > 1.f)
		return true;
	return false;
}

const FloatRect Alliance::getGlobalBonds() const
{
	return this->button.getGlobalBounds();
}

void Alliance::createButton(float x, float y, float width, float height, Color color, string text, Color colorText, int fontSize)
{
	this->button.setPosition(Vector2f(x, y));
	this->button.setSize(Vector2f(width, height));
	this->button.setFillColor(color);

	this->wordButton.setFont(this->textureWord);
	this->wordButton.setCharacterSize(fontSize);
	this->wordButton.setFillColor(colorText);
	this->wordButton.setString(text);
	this->wordButton.setPosition(this->button.getPosition().x + this->button.getGlobalBounds().width / 2.f - this->wordButton.getGlobalBounds().width / 2.f,
		this->button.getPosition().y + this->button.getGlobalBounds().height / 2.f - this->wordButton.getGlobalBounds().height / 2.f);
}

void Alliance::updateCost(const float& dt)
{
	this->costs.clear();

	for (int i = 0; i < 6; i++)
	{
		this->cost.setFont(this->textureWord);
		this->cost.setCharacterSize(40);
		this->cost.setFillColor(Color::Black);
		this->cost.setString(to_string(this->things[i]));
		this->costs.push_back(this->cost);
	}
}

void Alliance::updateAnimation(const float& dt)
{
	if (this->getAnimationTime())
	{
		this->animation.move(this->shop, this->textureShop, this->shopRect, 100, 0);
		this->timeAnim = 0.f;
	}
	else
	{
		this->timeAnim += dt;
	}
}

void Alliance::renderButton(RenderTarget* target)
{
	target->draw(this->textground);
	target->draw(this->word);
}

void Alliance::renderShopButton(RenderTarget* target)
{
	target->draw(this->button);
	target->draw(this->wordButton);
}

void Alliance::render(RenderTarget* target)
{
	target->draw(this->shop);
}
