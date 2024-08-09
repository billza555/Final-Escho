#include "header.h"
#include "Menu.h"

Menu::Menu()
{
	this->menuState = true;

	this->menuTexture.loadFromFile("Resources/Background/menuq.png");
	this->menuBackground.setTexture(&this->menuTexture);
	this->menuBackground.setSize(Vector2f(1200.f, 700.f));

	this->exitBackground.setFillColor(Color::Black);

	this->exit.setPosition(Vector2f(1284.f, 0.f));
	this->exit.setSize(Vector2f(100.f, 100.f));
	this->exit.setFillColor(Color::Transparent);
	this->exit.setOutlineThickness(1.f);
	this->exit.setOutlineColor(Color::Yellow);

	this->textureWord.loadFromFile("Fonts/Moon.otf");

	this->word.setFont(this->textureWord);
	this->word.setString("End Game");
	this->word.setFillColor(Color::White);
	this->word.setCharacterSize(100);

	this->textureWinBackground.loadFromFile("Resources/Background/win.png");
	this->winBackground.setTexture(&this->textureWinBackground);
	this->winBackground.setSize(Vector2f(1200.f, 700.f));

	this->exitBackground.setSize(Vector2f(1200.f, 700.f));
	this->word.setPosition(600.f, 600.f);

	this->button.setPosition(0.f, 0.f);
	this->button.setSize(Vector2f(200.f, 100.f));
	this->button.setFillColor(Color::Transparent);
	this->button.setOutlineThickness(1.f);
	this->button.setOutlineColor(Color::Blue);

	this->back.setFont(this->textureWord);
	this->back.setCharacterSize(40);
	this->back.setFillColor(Color::White);
	this->back.setString("MENU");
	this->back.setPosition(this->button.getPosition().x + this->button.getGlobalBounds().width / 2.f - this->back.getGlobalBounds().width / 2.f ,
		this->button.getPosition().y + this->button.getGlobalBounds().height / 2.f - this->back.getGlobalBounds().height / 2.f);

	this->buttonPress = false;

	this->scores.setFont(this->textureWord);
	this->scores.setCharacterSize(50);
	this->scores.setFillColor(Color::White);
	this->scores.setPosition(Vector2f(800.f, 0.f));

	this->scoretime = 0;

	this->winText.setFont(this->textureWord);
	this->winText.setCharacterSize(100);
	this->winText.setFillColor(Color::White);
	this->winText.setPosition(Vector2f(600.f, 600.f));
	this->winText.setString("YOU ESCAPE");
}

Menu::~Menu()
{
}

const FloatRect Menu::getGlobalBounds() const
{
	return this->rec.getGlobalBounds();
}

void Menu::updateButton(float x, float y, float width, float height, String word, int fontSize)
{
	this->rec.setPosition(Vector2f(x, y));
	this->rec.setSize(Vector2f(width, height));
	this->rec.setFillColor(Color(255, 255, 255, 200));

	this->keyword.setFont(this->textureWord);
	this->keyword.setString(word);
	this->keyword.setFillColor(Color::Black);
	this->keyword.setCharacterSize(fontSize);
	this->keyword.setPosition(this->rec.getPosition().x + this->rec.getGlobalBounds().width / 2.f - this->keyword.getGlobalBounds().width / 2.f,
		this->rec.getPosition().y + this->rec.getGlobalBounds().height / 2.f - this->keyword.getGlobalBounds().height / 2.f);
}

void Menu::updateMenuButton(const float& dt, Vector2f mousePosView)
{
	if (this->button.getGlobalBounds().contains(mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->buttonPress = true;
		}
	}
}

void Menu::updateScore(const float& dt)
{
	this->scores.setString("Score = " + to_string(this->scoretime));
}

void Menu::renderButton(RenderTarget* target)
{
	target->draw(this->rec);
	target->draw(this->keyword);
}

void Menu::renderMenuBackground(RenderTarget* target)
{
	target->draw(this->menuBackground);
}

void Menu::renderExitBackground(RenderTarget* target)
{
	target->draw(this->exitBackground);
	target->draw(this->word);
	target->draw(this->button);
	target->draw(this->back);
	target->draw(this->scores);
}

void Menu::renderWinBackground(RenderTarget* target)
{
	target->draw(this->winBackground);
	target->draw(this->button);
	target->draw(this->back);
	target->draw(this->scores);
	target->draw(this->winText);
}

void Menu::render(RenderTarget* target)
{
	target->draw(this->exit);
}

