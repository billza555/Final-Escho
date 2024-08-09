#include "header.h"
#include "itemShop.h"

void itemShop::initCost()
{
	this->costApple = 10;
	this->costPapaya = 20;
	this->costBanana = 30;
	this->costOrange = 40;
}

void itemShop::initInventory()
{
	this->inventory.setPosition(Vector2f(0.f, 100.f));
	this->inventory.setSize(Vector2f(200.f, 600.f));
	this->inventory.setFillColor(Color(255, 255, 255, 100));

	this->statu.setPosition(Vector2f(1000.f, 100.f));
	this->statu.setSize(Vector2f(200.f, 600.f));
	this->statu.setFillColor(Color(255, 255, 255, 100));

	this->shop.items[0].setPosition(Vector2f(25.f, 130.f));
	this->shop.items[0].setSize(Vector2f(50.f, 50.f));
	this->sales.push_back(this->shop.items[0]);
	this->shop.items[1].setPosition(Vector2f(25.f, 230.f));
	this->shop.items[1].setSize(Vector2f(50.f, 50.f));
	this->sales.push_back(this->shop.items[1]);
	this->shop.items[2].setPosition(Vector2f(25.f, 330.f));
	this->shop.items[2].setSize(Vector2f(50.f, 50.f));
	this->sales.push_back(this->shop.items[2]);
	this->shop.items[3].setPosition(Vector2f(25.f, 430.f));
	this->shop.items[3].setSize(Vector2f(50.f, 50.f));
	this->sales.push_back(this->shop.items[3]);
	this->shop.items[4].setPosition(Vector2f(25.f, 530.f));
	this->shop.items[4].setSize(Vector2f(50.f, 50.f));
	this->sales.push_back(this->shop.items[4]);
	this->shop.items[6].setPosition(Vector2f(25.f, 630.f));
	this->shop.items[6].setSize(Vector2f(50.f, 50.f));
	this->sales.push_back(this->shop.items[6]);

	this->shop.items[0].setPosition(Vector2f(25.f, 130.f));
	this->shop.items[0].setSize(Vector2f(50.f, 50.f));
	this->purchases.push_back(this->shop.items[0]);
	this->shop.items[1].setPosition(Vector2f(25.f, 230.f));
	this->shop.items[1].setSize(Vector2f(50.f, 50.f));
	this->purchases.push_back(this->shop.items[1]);
	this->shop.items[2].setPosition(Vector2f(25.f, 330.f));
	this->shop.items[2].setSize(Vector2f(50.f, 50.f));
	this->purchases.push_back(this->shop.items[2]);
	this->shop.items[3].setPosition(Vector2f(25.f, 430.f));
	this->shop.items[3].setSize(Vector2f(50.f, 50.f));
	this->purchases.push_back(this->shop.items[3]);
	this->shop.items[4].setPosition(Vector2f(25.f, 530.f));
	this->shop.items[4].setSize(Vector2f(50.f, 50.f));
	this->purchases.push_back(this->shop.items[4]);
	this->shop.items[6].setPosition(Vector2f(25.f, 630.f));
	this->shop.items[6].setSize(Vector2f(50.f, 50.f));
	this->purchases.push_back(this->shop.items[6]);
}

void itemShop::initItemShop()
{
	this->shop.items[0].setPosition(Vector2f(300.f, 100.f));
	this->sales.push_back(this->shop.items[0]);
	this->num.setPosition(Vector2f(270.f, 100.f));
	this->num.setString("1");
	this->nums.push_back(this->num);
	this->shop.items[1].setPosition(Vector2f(300.f, 250.f));
	this->sales.push_back(this->shop.items[1]);
	this->num.setPosition(Vector2f(270.f, 250.f));
	this->num.setString("1");
	this->nums.push_back(this->num);
	this->shop.items[2].setPosition(Vector2f(300.f, 400.f));
	this->sales.push_back(this->shop.items[2]);
	this->num.setPosition(Vector2f(270.f, 400.f));
	this->num.setString("1");
	this->nums.push_back(this->num);
	this->shop.items[3].setPosition(Vector2f(300.f, 550.f));
	this->sales.push_back(this->shop.items[3]);
	this->num.setPosition(Vector2f(270.f, 550.f));
	this->num.setString("1");
	this->nums.push_back(this->num);
	this->shop.items[6].setPosition(Vector2f(800.f, 100.f));
	this->sales.push_back(this->shop.items[6]);
	this->num.setPosition(Vector2f(750.f, 100.f));
	this->num.setString(to_string(this->costApple));
	this->nums.push_back(this->num);
	this->shop.items[6].setPosition(Vector2f(800.f, 250.f));
	this->sales.push_back(this->shop.items[6]);
	this->num.setPosition(Vector2f(750.f, 250.f));
	this->num.setString(to_string(this->costPapaya));
	this->nums.push_back(this->num);
	this->shop.items[6].setPosition(Vector2f(800.f, 400.f));
	this->sales.push_back(this->shop.items[6]);
	this->num.setPosition(Vector2f(750.f, 400.f));
	this->num.setString(to_string(this->costBanana));
	this->nums.push_back(this->num);
	this->shop.items[6].setPosition(Vector2f(800.f, 550.f));
	this->sales.push_back(this->shop.items[6]);
	this->num.setPosition(Vector2f(750.f, 550.f));
	this->num.setString(to_string(this->costOrange));
	this->nums.push_back(this->num);
	this->shop.items[9].setPosition(Vector2f(550.f, 100.f));
	this->sales.push_back(this->shop.items[9]);
	this->shop.items[9].setPosition(Vector2f(550.f, 250.f));
	this->sales.push_back(this->shop.items[9]);
	this->shop.items[9].setPosition(Vector2f(550.f, 400.f));
	this->sales.push_back(this->shop.items[9]);
	this->shop.items[9].setPosition(Vector2f(550.f, 550.f));
	this->sales.push_back(this->shop.items[9]);
}

void itemShop::initItemBuy()
{
	this->shop.items[6].setPosition(Vector2f(300.f, 100.f));
	this->purchases.push_back(this->shop.items[6]);
	this->num.setPosition(Vector2f(250.f, 100.f));
	this->num.setString("20");
	this->numBuys.push_back(this->num);
	this->shop.items[6].setPosition(Vector2f(300.f, 250.f));
	this->purchases.push_back(this->shop.items[6]);
	this->num.setPosition(Vector2f(250.f, 250.f));
	this->num.setString("20");
	this->numBuys.push_back(this->num);
	this->shop.items[6].setPosition(Vector2f(300.f, 400.f));
	this->purchases.push_back(this->shop.items[6]);
	this->num.setPosition(Vector2f(250.f, 400.f));
	this->num.setString("20");
	this->numBuys.push_back(this->num);
	this->shop.items[6].setPosition(Vector2f(300.f, 550.f));
	this->purchases.push_back(this->shop.items[6]);
	this->num.setPosition(Vector2f(240.f, 550.f));
	this->num.setString("60");
	this->numBuys.push_back(this->num);
	this->shop.items[4].setPosition(Vector2f(800.f, 100.f));
	this->purchases.push_back(this->shop.items[4]);
	this->num.setPosition(Vector2f(770.f, 100.f));
	this->num.setString("5");
	this->numBuys.push_back(this->num);
	this->shop.items[5].setPosition(Vector2f(800.f, 250.f));
	this->purchases.push_back(this->shop.items[5]);
	this->num.setPosition(Vector2f(770.f, 250.f));
	this->num.setString("10");
	this->numBuys.push_back(this->num);
	this->shop.items[7].setPosition(Vector2f(800.f, 400.f));
	this->purchases.push_back(this->shop.items[7]);
	this->num.setPosition(Vector2f(770.f, 400.f));
	this->num.setString("1");
	this->numBuys.push_back(this->num);
	this->shop.items[8].setPosition(Vector2f(800.f, 550.f));
	this->purchases.push_back(this->shop.items[8]);
	this->num.setPosition(Vector2f(770.f, 550.f));
	this->num.setString("1");
	this->numBuys.push_back(this->num);
	this->shop.items[9].setPosition(Vector2f(550.f, 100.f));
	this->purchases.push_back(this->shop.items[9]);
	this->shop.items[9].setPosition(Vector2f(550.f, 250.f));
	this->purchases.push_back(this->shop.items[9]);
	this->shop.items[9].setPosition(Vector2f(550.f, 400.f));
	this->purchases.push_back(this->shop.items[9]);
	this->shop.items[9].setPosition(Vector2f(550.f, 550.f));
	this->purchases.push_back(this->shop.items[9]);
}

void itemShop::initExchange()
{
	this->buttons["SELL1"].createButton(400.f, 200.f, 400.f, 50.f, Color(251, 153, 2, 200), "SELL ALL APPLE", Color::White, 30);
	this->buttons["SELL2"].createButton(400.f, 350.f, 400.f, 50.f, Color(251, 153, 2, 200), "SELL ALL PAPAYA", Color::White, 30);
	this->buttons["SELL3"].createButton(400.f, 500.f, 400.f, 50.f, Color(251, 153, 2, 200), "SELL ALL BANANA", Color::White, 30);
	this->buttons["SELL4"].createButton(400.f, 650.f, 400.f, 50.f, Color(251, 153, 2, 200), "SELL ALL ORANGE", Color::White, 30);

	this->buttons["BUY1"].createButton(400.f, 200.f, 400.f, 50.f, Color(251, 153, 2, 200), "BUY GUN", Color::White, 30);
	this->buttons["BUY2"].createButton(400.f, 350.f, 400.f, 50.f, Color(251, 153, 2, 200), "BUY ARMOR", Color::White, 30);
	this->buttons["BUY3"].createButton(400.f, 500.f, 400.f, 50.f, Color(251, 153, 2, 200), "BUY BOOT", Color::White, 30);
	this->buttons["BUY4"].createButton(400.f, 650.f, 400.f, 50.f, Color(251, 153, 2, 200), "BUY POTION", Color::White, 30);
}

void itemShop::initButton()
{
	this->buttons["EXIT"].createButton(1000.f, 0.f, 200.f, 100.f, Color::Red, "EXIT", Color::White, 30);
	this->buttons["SELLTEXT"].createButton(500.f, 0.f, 200.f, 50.f, Color::Transparent, "SELL", Color::Black, 100);
	this->buttons["INVENTORY"].createButton(0.f, 100.f, 200.f, 20.f, Color::Transparent, "My Inventory", Color::Black, 20);
	this->buttons["BUY"].createButton(0.f, 0.f, 200.f, 100.f, Color::Green, "BUY", Color::White, 30);
	this->buttons["BUYTEXT"].createButton(500.f, 0.f, 200.f, 50.f, Color::Transparent, "BUY", Color::Black, 100);
	this->buttons["SELL"].createButton(0.f, 0.f, 200.f, 100.f, Color::Green, "SELL", Color::White, 30);
}

itemShop::itemShop()
{
	this->textureShop.loadFromFile("Resources/Background/shop.png");

	this->shopBack.setSize(Vector2f(1200.f, 700.f));
	this->shopBack.setTexture(&this->textureShop);

	this->font.loadFromFile("Fonts/Moon.otf");
	this->num.setFont(this->font);
	this->num.setCharacterSize(30);
	this->num.setFillColor(Color::Black);

	this->status.setFont(this->font);
	this->status.setCharacterSize(40);
	this->status.setFillColor(Color::Black);

	this->hp = 10;

	this->bottle = false;

	this->scoretime = 0;

	this->initCost();

	this->initItemShop();

	this->initItemBuy();

	this->initExchange();

	this->initInventory();

	this->initButton();

	for (int i = 0; i < 6; i++)
	{
		this->shop.things[i] = 0;
	}

	this->shopping = false;

	this->sell = true;

	this->speed = 1.f;

}

itemShop::~itemShop()
{
}

void itemShop::resetItemShop()
{
	this->sell = true;

	this->bottle = false;
}

void itemShop::updateButton(const float& dt, Vector2f mousePosView)
{
	if (this->buttons["EXIT"].getGlobalBonds().contains(mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->shopping = false;
			this->bottle = false;
		}
	}
	else
	{
		this->shopping = true;
	}

	if (this->speed <= 2.0f)
	{
	this->speed += this->speed * dt;
	}

	if (this->sell)
	{
		if (this->buttons["BUY"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				this->sell = false;
				this->speed = 1.f;
			}
		}
		if (this->buttons["SELL1"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				this->item[5] += (this->item[0] * this->costApple);
				this->item[0] = 0;
				this->speed = 1.f;
				this->music.getItem.play();
			}
		}
		if (this->buttons["SELL2"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				this->item[5] += (this->item[1] * this->costPapaya);
				this->item[1] = 0;
				this->speed = 1.f;
				this->music.getItem.play();
			}
		}
		if (this->buttons["SELL3"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				this->item[5] += (this->item[2] * this->costBanana);
				this->item[2] = 0;
				this->speed = 1.f;
				this->music.getItem.play();
			}
		}
		if (this->buttons["SELL4"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				this->item[5] += (this->item[3] * this->costOrange);
				this->item[3] = 0;
				this->speed = 1.f;
				this->music.getItem.play();
			}
		}
	}

	if (!this->sell)
	{
		if (this->buttons["SELL"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				this->sell = true;
				this->speed = 1.f;
			}
		}
		if (this->buttons["BUY1"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				if (this->item[5] >= 20)
				{
					this->item[4] += 5;
					this->item[5] -= 20;
					this->speed = 1.f;
					this->music.getItem.play();
				}
			}
		}
		if (this->buttons["BUY2"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				if (this->item[5] >= 20)
				{
					this->item[6] += 10;
					this->item[5] -= 20;
					this->speed = 1.f;
					this->music.getItem.play();
				}
			}
		}
		if (this->buttons["BUY3"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				if (this->item[5] >= 20)
				{
					this->item[7] += 1;
					this->item[5] -= 20;
					this->speed = 1.f;
					this->music.getItem.play();
				}
			}
		}
		if (this->buttons["BUY4"].getGlobalBonds().contains(mousePosView))
		{
			if (Mouse::isButtonPressed(Mouse::Left) && this->speed >= 2.0f)
			{
				if (this->item[5] >= 60)
				{
					this->item[5] -= 60;
					this->bottle = true;
					if (this->hp < 10)
					{
						this->hp = 10;
					}
					this->item[6] += 5;
					this->item[8] += 1;
					this->speed = 1.f;
					this->music.getItem.play();
				}
			}
		}
	}
	
}

void itemShop::updateInventory(const float& dt)
{
	for (int i = 0; i < 6; i++)
	{
		this->shop.things[i] = this->item[i];
		this->shop.costs[i].setPosition(Vector2f(125.f, 130.f + 100.f * i));
	}
}

void itemShop::updateStatus(const float& dt)
{
	this->statuses.clear();

	this->intro[0] = "HP";
	this->intro[1] = to_string(this->hp) + " / 10";
	this->intro[2] = "ARMOR";
	this->intro[3] = to_string(this->item[6]);
	this->intro[4] = "SPEED";
	this->intro[5] = to_string(int(200.f * dt + this->item[7]));
	this->intro[6] = "DAMAGE";
	this->intro[7] = to_string(1 + this->item[8]);
	this->intro[8] = "SCORE";
	this->intro[9] = to_string(this->scoretime);

	for (int i = 0; i < 10; i++)
	{
		this->status.setString(this->intro[i]);
		this->statuses.push_back(this->status);
		this->statuses[i].setPosition(Vector2f(1100.f - this->statuses[i].getGlobalBounds().width / 2.f, 100.f + 60.f * i));
	}
}

void itemShop::update(const float& dt, Vector2f mousePosView)
{
	this->updateButton(dt, mousePosView);
	this->shop.updateCost(dt);
	this->updateInventory(dt);
	this->updateStatus(dt);
}

void itemShop::renderItemShop(RenderTarget* target)
{
	if (this->sell)
	{
		for (auto& it : this->sales)
		{
			target->draw(it);
		}
		for (auto& it : this->nums)
		{
			target->draw(it);
		}
	}
	if (!this->sell)
	{
		for (auto& it : this->purchases)
		{
			target->draw(it);
		}
		for (auto& it : this->numBuys)
		{
			target->draw(it);
		}
	}
}

void itemShop::renderButtons(RenderTarget* target)
{
		this->buttons["EXIT"].renderShopButton(target);
		this->buttons["INVENTORY"].renderShopButton(target);
	if (this->sell)
	{
		this->buttons["BUY"].renderShopButton(target);
		this->buttons["SELLTEXT"].renderShopButton(target);
		this->buttons["SELL1"].renderShopButton(target);
		this->buttons["SELL2"].renderShopButton(target);
		this->buttons["SELL3"].renderShopButton(target);
		this->buttons["SELL4"].renderShopButton(target);
	}
	if (!this->sell)
	{
		this->buttons["BUYTEXT"].renderShopButton(target);
		this->buttons["SELL"].renderShopButton(target);
		this->buttons["BUY1"].renderShopButton(target);
		this->buttons["BUY2"].renderShopButton(target);
		this->buttons["BUY3"].renderShopButton(target);
		this->buttons["BUY4"].renderShopButton(target);
	}
}

void itemShop::renderInventory(RenderTarget* target)
{
	for (auto& it : this->shop.costs)
	{
		target->draw(it);
	}
}

void itemShop::renderStatus(RenderTarget* target)
{
	for (auto& it : this->statuses)
	{
		target->draw(it);
	}
}

void itemShop::render(RenderTarget* target)
{
	target->setView(target->getDefaultView());
	target->draw(this->shopBack);
	target->draw(this->inventory);
	target->draw(this->statu);
	this->renderButtons(target);
	this->renderItemShop(target);
	this->renderInventory(target);
	this->renderStatus(target);
}

