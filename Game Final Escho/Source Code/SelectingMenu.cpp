#include "header.h"
#include "SelectingMenu.h"

void SelectingMenu::initChoose()
{
	this->choose["MENU"].updateButton(200.f, 500.f, 200.f, 100.f, "Menu", 30);
	this->choose["SAVE"].updateButton(200.f, 200.f, 200.f, 100.f, "Save", 30);
	this->choose["LOAD"].updateButton(200.f, 350.f, 200.f, 100.f, "Load", 30);
	this->choose["CONTINUOUS"].updateButton(200.f, 50.f, 200.f, 100.f, "Continuous", 30);
}

void SelectingMenu::initStatus()
{
	this->StatusBackground.setPosition(Vector2f(800.f, 0.f));
	this->StatusBackground.setSize(Vector2f(400.f, 700.f));
	this->StatusBackground.setFillColor(Color(255,255,255,100));
}

SelectingMenu::SelectingMenu()
{
	this->background.setSize(Vector2f(1200.f, 700.f));
	this->background.setFillColor(Color::Black);

	this->status.setFont(this->textureWord);
	this->status.setCharacterSize(40);
	this->status.setFillColor(Color::White);

	this->hp = 10;
	this->speed = 3;
	this->damage = 1;
	this->score = 0;

	this->initChoose();

	this->initStatus();
}

SelectingMenu::~SelectingMenu()
{
}

void SelectingMenu::updateStatus(const float& dt)
{
	this->statuses.clear();

	this->stat[0] = "HP";
	this->stat[1] = to_string(this->hp) + " / 10";
	this->stat[2] = "ARMOR";
	this->stat[3] = to_string(this->armor);
	this->stat[4] = "SPEED";
	this->stat[5] = to_string(int(200.f * dt + this->speed));
	this->stat[6] = "DAMAGE";
	this->stat[7] = to_string(1 + this->damage);
	this->stat[8] = "SCORE";
	this->stat[9] = to_string(this->score);

	for (int i = 0; i < 10; i++)
	{
		this->status.setString(this->stat[i]);
		this->statuses.push_back(this->status);
		this->statuses[i].setPosition(Vector2f(this->StatusBackground.getPosition().x + this->StatusBackground.getGlobalBounds().width / 2.f - this->status.getGlobalBounds().width / 2.f
			, 70.f * i));
	}
}

void SelectingMenu::renderChoose(RenderTarget* target)
{
	this->choose["MENU"].renderButton(target);
	this->choose["SAVE"].renderButton(target);
	this->choose["LOAD"].renderButton(target);
	this->choose["CONTINUOUS"].renderButton(target);
}

void SelectingMenu::renderStatus(RenderTarget* target)
{
	target->draw(this->StatusBackground);

	for (auto& it : this->statuses)
	{
		target->draw(it);
	}
}

void SelectingMenu::render(RenderTarget* target)
{
	target->draw(this->background);
	this->renderChoose(target);
	this->renderStatus(target);
	target->setView(target->getDefaultView());
}
