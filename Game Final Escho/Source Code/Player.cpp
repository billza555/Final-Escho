#include "header.h"
#include "Player.h"

void Player::initInventory()
{
	this->inventoryBar.setSize(Vector2f(this->maps.background.getSize().x / 2.f, 200.f));
	this->inventoryBar.setFillColor(Color(255, 255, 255, 100));

	this->useInventory = false;
	this->speedUseInventory = 2.f;
	this->itemInventory.setSize(Vector2f(100.f, 100.f));
	this->itemInventory.setTexture(&this->shop.TextureItems[0]);
	this->itemInventorys.push_back(this->itemInventory);
	this->itemInventory.setSize(Vector2f(100.f, 100.f));
	this->itemInventory.setTexture(&this->shop.TextureItems[1]);
	this->itemInventorys.push_back(this->itemInventory);
	this->itemInventory.setSize(Vector2f(100.f, 100.f));
	this->itemInventory.setTexture(&this->shop.TextureItems[2]);
	this->itemInventorys.push_back(this->itemInventory);
	this->itemInventory.setSize(Vector2f(100.f, 100.f));
	this->itemInventory.setTexture(&this->shop.TextureItems[3]);
	this->itemInventorys.push_back(this->itemInventory);
	this->itemInventory.setSize(Vector2f(100.f, 100.f));
	this->itemInventory.setTexture(&this->shop.TextureItems[4]);
	this->itemInventorys.push_back(this->itemInventory);
	this->itemInventory.setSize(Vector2f(100.f, 100.f));
	this->itemInventory.setTexture(&this->shop.TextureItems[6]);
	this->itemInventorys.push_back(this->itemInventory);
}

void Player::initBullet()
{
	this->bullet.setFillColor(Color::Black);

	this->direction = 0;
}

Player::Player()
{
	this->speed = false;
	this->velocity = 1.f;
	this->speedtime = 1.f;
	this->speedtimeMax = 10.f;

	this->texturePlayer.loadFromFile("Resources/Entity/playeranimation.png");

	this->player.setTexture(this->texturePlayer);
	this->intRectPlayer[0] = IntRect(0, 0, 100, 100);
	this->intRectPlayer[1] = IntRect(0, 100, 100, 100);
	this->intRectPlayer[2] = IntRect(0, 200, 100, 100);
	this->intRectPlayer[3] = IntRect(0, 300, 100, 100);
	this->player.setTextureRect(this->intRectPlayer[0]);
	this->player.setPosition(125.099f, 517.129f);

	this->hp = 10;

	this->hpBar.setFillColor(Color::Red);
	this->hpBar.setOutlineThickness(2.f);
	this->hpBar.setOutlineColor(Color::Black);

	this->armor.setFillColor(Color::Blue);
	this->armor.setOutlineThickness(2.f);
	this->armor.setOutlineColor(Color::Black);

	this->textureBackpack.loadFromFile("Resources/Supple/backpack.png");
	this->backpack.setTexture(&this->textureBackpack);
	this->backpack.setSize(Vector2f(50.f, 50.f));

	this->gun.setTexture(&this->shop.TextureItems[4]);
	this->gun.setSize(Vector2f(50.f, 50.f));

	this->textureWord.loadFromFile("Fonts/Moon.otf");

	this->backpackGround[0].setSize(Vector2f(30.f, 30.f));
	this->backpackGround[0].setFillColor(Color(255, 255, 255, 200));
	this->key[0].setFont(this->textureWord);
	this->key[0].setCharacterSize(30);
	this->key[0].setFillColor(Color::Black);
	this->key[0].setString("E");

	this->textureSpaceBar.loadFromFile("Resources/Supple/SpaceBar.png");
	this->SpaceBar.setTexture(&this->textureSpaceBar);
	this->SpaceBar.setSize(Vector2f(20.f, 20.f));

	this->backpackGround[1].setSize(Vector2f(30.f, 30.f));
	this->backpackGround[1].setFillColor(Color(255, 255, 255, 200));

	this->backpackGround[2].setSize(Vector2f(30.f, 30.f));
	this->backpackGround[2].setFillColor(Color(255, 255, 255, 200));
	this->key[1].setFont(this->textureWord);
	this->key[1].setCharacterSize(10);
	this->key[1].setFillColor(Color::Black);
	this->key[1].setString("SHIFT");

	this->shopping = false;

	this->lock = true;

	for (int i = 0; i < 9;i++)
	{
		this->item[i] = 0;
	}

	this->gunTime = 1.f;

	this->win = false;

	this->scoretime = 0;

	this->enemyItem.setTexture(&this->shop.TextureItems[6]);
	this->enemyItem.setSize(Vector2f(50.f, 50.f));

	this->runBar.setFillColor(Color(0,0,255,200));
	this->runBar.setSize(Vector2f(30.f ,50.f));
	
	this->runBarMax.setFillColor(Color::Black);
	this->runBarMax.setSize(Vector2f(30.f, 450.f));
	this->runBarMax.setOutlineThickness(1.f);
	this->runBarMax.setOutlineColor(Color::White);

	this->initInventory();

	this->initBullet();

	this->bushSize = 0;
}

Player::~Player()
{
}

void Player::resetPlayer()
{
	this->player.setPosition(125.099f, 517.129f);
	this->hp = 10;

	this->useInventory = false;

	this->shopping = false;

	this->enemy.reset();

	this->bush.resetBush();

	for (int i = 0; i < 6; i++)
	{
		this->shop.things[i] = 0;
	}
	for (int i = 0; i < 9;i++)
	{
		this->item[i] = 0;
	}

	this->bullets.clear();

	this->directions.clear();

	this->win = false;

	this->lock = true;

	this->scoretime = 0;

	this->bushSize = 0;

	this->enemyItemDrop.clear();

	this->player.setTextureRect(this->intRectPlayer[0]);
}

void Player::saveBush(const string file_name)
{
	ofstream out_file;
	out_file.open(file_name);

	if (out_file.is_open())
	{
		out_file << this->bush.bushs.size() << " ";
		for (int i = 0; i < this->bush.bushs.size(); i++)
		{
			out_file << this->bush.bushs[i].getPosition().x << " " << this->bush.bushs[i].getPosition().y << " ";
		}
		out_file << this->bush.itemDrop.size() << " ";
		for (int i = 0; i < this->bush.itemDrop.size(); i++)
		{
			out_file << this->bush.itemDrop[i].getPosition().x << " " <<
				this->bush.itemDrop[i].getPosition().y << " " << this->bush.numItems[i] << " ";
		}
		out_file.close();
	}
}

void Player::loadBush(Vector2f position)
{
	this->bush.loadBush(position);
	this->bushSize++;
}

void Player::loadItem(int i, Vector2f position)
{
	this->bush.loadItem(i, position);
}

void Player::saveBullet(const string file_name)
{
	ofstream out_file;
	out_file.open(file_name);

	if (out_file.is_open())
	{
		out_file << this->bullets.size() << " ";
		for (int i = 0; i < this->bullets.size(); i++)
		{
			out_file << this->bullets[i].getSize().x << " " << this->bullets[i].getSize().y << " " << 
				this->bullets[i].getPosition().x << " " << this->bullets[i].getPosition().y << " " << this->directions[i];
		}
		out_file.close();
	}
}

void Player::loadBullet(const string file_name)
{
	ifstream in_file;
	in_file.open(file_name);

	if (in_file.is_open())
	{
		string line;

		if (getline(in_file, line))
		{
			stringstream ss(line);

			int bulletSize;
			ss >> bulletSize;
			for (int i = 0; i < bulletSize; i++)
			{
				Vector2f bulletScale, bulletPosition;
				int direc;
				ss >> bulletScale.x >> bulletScale.y >> bulletPosition.x >> bulletPosition.y >> direc;
				this->bullet.setSize(bulletScale);
				this->bullet.setPosition(bulletPosition);
				this->bullets.push_back(this->bullet);
				this->direction = direc;
				this->directions.push_back(this->direction);
			}
		}
		in_file.close();
	}
}

void Player::saveEnemies(const string file_name)
{
	ofstream out_file;
	out_file.open(file_name);

	if (out_file.is_open())
	{
		out_file << this->enemy.enemies.size() << " ";
		for (int i = 0; i < this->enemy.enemies.size(); i++)
		{
			out_file << this->enemy.enemiesType[i] << " " << this->enemy.enemies[i].getPosition().x << " " << this->enemy.enemies[i].getPosition().y << " " <<
				this->enemy.hpEnemies[i] << " " << this->enemy.loopMove[i] << " " << this->enemy.velocity[i] << " " << this->enemy.direction[i] << this->enemy.bulletTime[i] << " ";
		}
		out_file << this->enemy.bullets.size() << " ";
		for (int i = 0; i < this->enemy.bullets.size(); i++)
		{
			out_file << this->enemy.bullets[i].getSize().x << " " << this->enemy.bullets[i].getSize().y << " " <<
				this->enemy.bullets[i].getPosition().x << " " << this->enemy.bullets[i].getPosition().y << " " <<
				this->enemy.values[i] << " ";
		}
		out_file << this->enemy.kei << " " << this->enemy.key.getPosition().x << " " << this->enemy.key.getPosition().y << " " ;
		out_file << this->enemyItemDrop.size() << " ";
		for (int i = 0; i < this->enemyItemDrop.size(); i++)
		{
			out_file << this->enemyItemDrop[i].getPosition().x << " " << this->enemyItemDrop[i].getPosition().y << " ";
		}
		out_file.close();
	}
}

void Player::loadEnemies(const string file_name)
{
	ifstream in_file;
	in_file.open(file_name);

	if (in_file.is_open())
	{
		string line;

		if (getline(in_file, line))
		{
			stringstream ss(line);

			ss >> this->EneSize;
			for (int i = 0; i < this->EneSize; i++)
			{
				Vector2f EnemiesScale, EnemiesPosition;
				int EnemiesHp, Type;
				ss >> Type >> EnemiesPosition.x >> EnemiesPosition.y >> EnemiesHp >> this->enemy.loopMove[i] >> this->enemy.velocity[i] >>
					this->enemy.direction[i] >> this->enemy.bulletTime[i];
				this->enemy.loadEnemies(Type, EnemiesPosition);
				this->enemy.hpEnemies.push_back(EnemiesHp);
			}
			int BulletSize;
			ss >> BulletSize;
			for (int i = 0; i < BulletSize; i++)
			{
				Vector2f bulletScale, bulletPosition;
				int value;
				ss >> bulletScale.x >> bulletScale.y >> bulletPosition.x >> bulletPosition.y >> value;
				this->enemy.loadBullet(bulletScale, bulletPosition,value);
			}
			Vector2f keyPosition;
			ss >> this->enemy.kei >> keyPosition.x >> keyPosition.y;
			this->enemy.key.setPosition(keyPosition);
			this->enemy.textKey.setPosition(keyPosition.x + 50.f, keyPosition.y);
			int EnemyDrop;
			ss >> EnemyDrop;
			for (int i = 0; i < EnemyDrop; i++)
			{
				Vector2f EnemyDropPosition;
				ss >> EnemyDropPosition.x >> EnemyDropPosition.y;
				this->enemyItem.setPosition(EnemyDropPosition);
				this->enemyItemDrop.push_back(this->enemyItem);
			}
		}
		in_file.close();
	}
}

const bool Player::getSpeed() const
{
	return this->speed;
}

const Vector2f Player::getPosition() const
{
	return this->player.getPosition();
}

const FloatRect Player::getGlobalBounds() const
{
	return this->player.getGlobalBounds();
}

void Player::updateSpeedtime(const float& dt)
{
	if (this->speed && this->speedtime >= 1.f)
	{
		this->speedtime += this->speedtime * dt;
		if (this->speedtime >= this->speedtimeMax)
		{
			this->speed = false;
			this->speedtime = 0.1f;
		}
	}
	else if (!this->speed && this->speedtime < 1.f)
	{
		this->speedtime += this->speedtime * dt;
		if (this->speedtime >= 1.f)
			this->speedtime = 1.f;
	}
	//cout << this->speedtime << endl;
}

void Player::updateGun(const float& dt)
{
	if (this->gunTime >= 1.5f)
	{
		if (this->item[4] >= 1)
		{
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				this->directions.push_back(this->direction);
				this->item[4] -= 1;
				this->bullet.setPosition(this->player.getPosition().x + this->player.getGlobalBounds().width / 2, this->player.getPosition().y + this->player.getGlobalBounds().height / 2);
				if (this->direction == 0 || this->direction == 1)
				{
					this->bullet.setSize(Vector2f(25.f, 5.f));
					this->bullets.push_back(this->bullet);
				}
				else if((this->direction == 2 || this->direction == 3))
				{
					this->bullet.setSize(Vector2f(5.f, 25.f));
					this->bullets.push_back(this->bullet);
				}
				this->gunTime = 1.f;
				this->music.shoot.play();
			}
		}
	}
	else
	{
		this->gunTime += this->gunTime * dt;
	}

	for (int i = 0; i < this->bullets.size(); i++)
	{
		switch (this->directions[i])
		{
		case 0:
			this->bullets[i].move(Vector2f(-500.f * dt, 0.f));
			break;
		case 1:
			this->bullets[i].move(Vector2f(500.f * dt, 0.f));
			break;
		case 2:
			this->bullets[i].move(Vector2f(0, -500.f * dt));
			break;
		case 3:
			this->bullets[i].move(Vector2f(0, 500.f * dt));
			break;
		default:
			break;
		}

		if (this->bullets[i].getPosition().x < 0.f || this->bullets[i].getPosition().x > this->maps.background.getGlobalBounds().width ||
			this->bullets[i].getPosition().y < 0.f || this->bullets[i].getPosition().x > this->maps.background.getGlobalBounds().height)
		{
			this->bullets.erase(this->bullets.begin() + i);
			this->directions.erase(this->directions.begin() + i);
		}
	}
	for (int i = 0; i < this->bullets.size(); i++)
	{
		for (int j = 0; j < this->enemy.enemies.size(); j++)
		{
			if (this->bullets[i].getGlobalBounds().intersects(this->enemy.enemies[j].getGlobalBounds()))
			{
				this->music.hit.play();
				if (this->enemy.hpEnemies[j] <= 1 + this->item[8])
				{
					this->enemyItem.setPosition(this->enemy.enemies[j].getPosition());
					this->enemyItemDrop.push_back(this->enemyItem);
					this->music.drop.play();
				}
				this->bullets.erase(this->bullets.begin() + i);
				this->directions.erase(this->directions.begin() + i);
				this->scoretime += 20 * (1 + this->item[8]) + (this->scoretime / 1000);
				this->enemy.hpEnemies[j] -= (1 + this->item[8]);
				break;
			}
		}
	}
}

void Player::updateCollision(const float& dt)
{
	if (Keyboard::isKeyPressed(Keyboard::LShift) && this->speedtime >= 1.f)
		this->speed = true;

	if (this->getSpeed())
	{
		this->velocity = 2.f;
	}
	else if (this->player.getGlobalBounds().intersects(this->maps.object[5].getGlobalBounds()))
	{
		this->velocity = 0.5f;
	}
	else if (this->player.getGlobalBounds().intersects(this->maps.object[6].getGlobalBounds()))
	{
		this->velocity = 0.5f;
	}
	else if (this->player.getGlobalBounds().intersects(this->maps.object[7].getGlobalBounds()))
	{
		this->velocity = 0.5f;
	}
	else
	{
		this->velocity = 1.f;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->player.move(-200.f * dt * this->velocity - this->item[7], 0);
		this->direction = 0;

		if (!Keyboard::isKeyPressed(Keyboard::S) && !Keyboard::isKeyPressed(Keyboard::W))
		this->animation.move(this->player, this->texturePlayer, this->intRectPlayer[3], 100, 0);
		this->music.playMove(dt);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->player.move(200.f * dt * this->velocity + this->item[7], 0);

		if (this->player.getPosition().x > this->maps.object[1].getPosition().x - this->player.getGlobalBounds().width)
			this->player.setPosition(this->maps.object[1].getPosition().x - this->player.getGlobalBounds().width, this->player.getPosition().y);
		this->direction = 1;

		if (!Keyboard::isKeyPressed(Keyboard::S)&& !Keyboard::isKeyPressed(Keyboard::W))
		this->animation.move(this->player, this->texturePlayer, this->intRectPlayer[1], 100, 0);

		this->music.playMove(dt);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->player.move(0, -200.f * dt * this->velocity - this->item[7]);

		if (this->player.getPosition().y < this->maps.object[0].getPosition().y + this->maps.object[0].getGlobalBounds().height)
			this->player.setPosition(this->player.getPosition().x, this->maps.object[0].getPosition().y + this->maps.object[0].getGlobalBounds().height);
		this->direction = 2;

		this->animation.move(this->player, this->texturePlayer, this->intRectPlayer[2], 100, 0);

		this->music.playMove(dt);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->player.move(0, 200.f * dt * this->velocity + this->item[7]);

		if(this->player.getPosition().y > this->maps.object[3].getPosition().y - this->player.getGlobalBounds().height)
			this->player.setPosition(this->player.getPosition().x, this->maps.object[3].getPosition().y - this->player.getGlobalBounds().height);
		this->direction = 3;

		this->animation.move(this->player, this->texturePlayer, this->intRectPlayer[0], 100, 0);

		this->music.playMove(dt);
	}

	if (this->player.getGlobalBounds().intersects(this->enemy.key.getGlobalBounds()))
	{
		if (Keyboard::isKeyPressed(Keyboard::F))
		{
			this->lock = false;
			this->music.open.play();
		}
	}
	for (const RectangleShape& obstruct : this->maps.obstructs) {
		if (this->player.getGlobalBounds().intersects(obstruct.getGlobalBounds())) {
			FloatRect playerBounds = this->player.getGlobalBounds();
			FloatRect obstructBounds = obstruct.getGlobalBounds();

			float overlapX = min(playerBounds.left + playerBounds.width, obstructBounds.left + obstructBounds.width) - max(playerBounds.left, obstructBounds.left);
			float overlapY = min(playerBounds.top + playerBounds.height, obstructBounds.top + obstructBounds.height) - max(playerBounds.top, obstructBounds.top);

			
			if (overlapX > overlapY) {
				
				if (playerBounds.top < obstructBounds.top) {
					this->player.setPosition(playerBounds.left, obstructBounds.top - playerBounds.height);
				}
				else {
					this->player.setPosition(playerBounds.left, obstructBounds.top + obstructBounds.height);
				}
			}
			else {
				if (playerBounds.left < obstructBounds.left) {
					this->player.setPosition(obstructBounds.left - playerBounds.width, playerBounds.top);
				}
				else {
					this->player.setPosition(obstructBounds.left + obstructBounds.width, playerBounds.top);
				}
			}
		}
		for (int i = 0; i < this->bush.bushs.size(); i++)
		{
			if ((this->bush.bushs[i].getPosition().x > 370.f && this->bush.bushs[i].getPosition().x < 1300.f)
				&& (this->bush.bushs[i].getPosition().y > 190.f && this->bush.bushs[i].getPosition().y < 1700.f))
			{
				if ((this->bush.bushs[i].getPosition().x >= obstruct.getPosition().x - this->bush.bushs[i].getGlobalBounds().width && this->bush.bushs[i].getPosition().x <= obstruct.getPosition().x + obstruct.getGlobalBounds().width) &&
					(this->bush.bushs[i].getPosition().y >= obstruct.getPosition().y - this->bush.bushs[i].getGlobalBounds().height && this->bush.bushs[i].getPosition().y <= obstruct.getPosition().y + obstruct.getGlobalBounds().height))
				{
					this->bush.bushs.erase(this->bush.bushs.begin() + i);
					this->bush.bushBars.erase(this->bush.bushBars.begin() + i);
					this->bush.gets.erase(this->bush.gets.begin() + i);
				}
			}
			else
			{
				this->bush.bushs.erase(this->bush.bushs.begin() + i);
				this->bush.bushBars.erase(this->bush.bushBars.begin() + i);
				this->bush.gets.erase(this->bush.gets.begin() + i);
			}
		}
	}
	for (int i = 0; i < this->bush.bushs.size(); i++)
	{
		if ((this->player.getPosition().x >= this->bush.bushs[i].getPosition().x - this->player.getGlobalBounds().width && this->player.getPosition().x <= this->bush.bushs[i].getPosition().x + this->bush.bushs[i].getGlobalBounds().width) &&
			(this->player.getPosition().y >= this->bush.bushs[i].getPosition().y - this->bush.bushs[i].getGlobalBounds().height && this->player.getPosition().y <= this->bush.bushs[i].getPosition().y + this->bush.bushs[i].getGlobalBounds().height))
		{
			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				this->bush.bushBars[i].setSize(Vector2f(this->bush.bushBars[i].getSize().x - 1.f, 20.f));
				if (this->bush.bushBars[i].getSize().x <= 0.f)
				{
					this->bush.item.setPosition(this->bush.bushs[i].getPosition().x + this->bush.bushs[i].getGlobalBounds().width / 2.f - 25.f,
						this->bush.bushs[i].getPosition().y + this->bush.bushs[i].getGlobalBounds().height / 2.f - 25.f);
					this->bush.updateItemDrop(dt);
					this->bush.bushs.erase(this->bush.bushs.begin() + i);
					this->bush.bushBars.erase(this->bush.bushBars.begin() + i);
					this->bush.gets.erase(this->bush.gets.begin() + i);
					this->bushSize--;
					this->music.drop.play();
				}
			}
			else if (this->bush.bushBars[i].getSize().x <= 100.f)
			{
				this->bush.bushBars[i].setSize(Vector2f(this->bush.bushBars[i].getSize().x + 1.f, 20.f));
			}
		}
		else if (this->bush.bushBars[i].getSize().x <= 100.f)
		{
			this->bush.bushBars[i].setSize(Vector2f(this->bush.bushBars[i].getSize().x + 1.f, 20.f));
		}
	}
	for (int i = 0; i < this->enemy.bullets.size(); i++)
	{
		if (this->enemy.bullets[i].getGlobalBounds().intersects(this->player.getGlobalBounds()))
		{
			if (this->item[6] >= 1)
			{
				this->item[6] -= 1 + int(this->scoretime / 1000);
				if (this->item[6] <= 0)
				{
					this->item[6] = 0;
				}
			}
			else
			{
				this->hp -= 1 + int(this->scoretime / 1000);
			}
			this->enemy.bullets.erase(this->enemy.bullets.begin() + i);
			this->enemy.values.erase(this->enemy.values.begin() + i);
			this->music.hit.play();
		}
	}
	this->hpBar.setSize(Vector2f(this->player.getGlobalBounds().width / this->hp, 20.f));
	this->armor.setSize(Vector2f(this->player.getGlobalBounds().width / this->item[6], 20.f));

	for (int i = 0; i < this->enemyItemDrop.size() ; i++)
	{
		if (this->player.getGlobalBounds().intersects(this->enemyItemDrop[i].getGlobalBounds()))
		{
			this->enemyItemDrop.erase(this->enemyItemDrop.begin() + i);
			this->item[5] += 20;
			this->music.getItem.play();
		}
	}
	//cout << this->enemy.bullets.size() << endl;
}

void Player::updateExit(const float& dt)
{
	if (!this->lock)
	{
		if (this->player.getPosition().x >= this->menu.exit.getPosition().x && this->player.getPosition().x <= this->menu.exit.getPosition().x + this->menu.exit.getSize().x)
		{
			if (this->player.getPosition().y >= this->menu.exit.getPosition().y && this->player.getPosition().y <= this->menu.exit.getPosition().y + this->menu.exit.getSize().y)
			{
				this->lock = true;
				this->scoretime += 1000;
				this->scoretime += this->item[5] * 10;
				this->win = true;
				this->music.win.play();
			}
		}
	}
}

void Player::updateEnemies(const float& dt)
{
	for (int i = 0; i < this->enemy.enemies.size(); i++)
	{
		if (this->player.getPosition().x >=  this->enemy.enemies[i].getPosition().x - 300.f &&
			this->player.getPosition().x <= this->enemy.enemies[i].getPosition().x + this->enemy.enemies[i].getGlobalBounds().width + 300.f &&
			this->player.getPosition().y >= this->enemy.enemies[i].getPosition().y - 300.f &&
			this->player.getPosition().y <= this->enemy.enemies[i].getPosition().y + this->enemy.enemies[i].getGlobalBounds().height + 300.f)
		{
			if (this->player.getPosition().x >= this->enemy.enemies[i].getPosition().x - 50.f &&
				this->player.getPosition().x <= this->enemy.enemies[i].getPosition().x + this->enemy.enemies[i].getGlobalBounds().width + 50.f &&
				this->player.getPosition().y >= this->enemy.enemies[i].getPosition().y - 50.f &&
				this->player.getPosition().y <= this->enemy.enemies[i].getPosition().y + this->enemy.enemies[i].getGlobalBounds().height + 50.f)
			{
				this->enemy.enemies[i].setPosition(this->enemy.enemies[i].getPosition());
			}
			else
			{
				Vector2f direction = this->player.getPosition() - this->enemy.enemies[i].getPosition();
				float length = sqrt(direction.x * direction.x + direction.y * direction.y);

				direction /= length;

				if (direction.x < 0)
				{
					int y = 3;
					this->enemy.updateEnemiesGoTOPlayer(dt, i, y);
				}
				else if (direction.x >= 0)
				{
					int y = 1;
					this->enemy.updateEnemiesGoTOPlayer(dt, i, y);
				}
	
				this->enemy.enemies[i].move(direction * 200.f * dt);
			}

			if (this->enemy.enemies[i].getPosition().x >= this->player.getPosition().x - this->player.getGlobalBounds().width &&
				this->enemy.enemies[i].getPosition().x <= this->player.getPosition().x + this->player.getGlobalBounds().width)
			{
				if (this->enemy.getBulletTime(i))
				{
					if(this->enemy.enemies[i].getPosition().y > this->player.getPosition().y)
						this->enemy.updateBullet(dt, i, 0, 1);
					if (this->enemy.enemies[i].getPosition().y < this->player.getPosition().y)
						this->enemy.updateBullet(dt, i, 0, 2);
					this->music.shoot.play();
				}
			}
			if (this->enemy.enemies[i].getPosition().y >= this->player.getPosition().y - this->player.getGlobalBounds().height &&
				this->enemy.enemies[i].getPosition().y <= this->player.getPosition().y + this->player.getGlobalBounds().height)
			{
				if (this->enemy.getBulletTime(i))
				{
					if (this->enemy.enemies[i].getPosition().x > this->player.getPosition().x)
						this->enemy.updateBullet(dt, i, 1, 3);
					if (this->enemy.enemies[i].getPosition().x < this->player.getPosition().x)
						this->enemy.updateBullet(dt, i, 1, 4);
					this->music.shoot.play();
				}
			}
			this->music.playMove(dt);
		}
	}
}

void Player::updateInventory(const float& dt)
{
	this->inventoryBar.setPosition(Vector2f(this->view.getCenter().x - 400.f, this->view.getCenter().y - 400.f));

	for (int i = 0; i < 6; i++)
	{
		this->itemInventorys[i].setPosition(Vector2f(this->view.getCenter().x - 400.f + 50.f + 120.f * i, this->view.getCenter().y - 400.f + 25.f));
	}
	for (int i = 0; i < 6; i++)
	{
		this->shop.things[i] = this->item[i];
		this->shop.costs[i].setPosition(Vector2f(this->view.getCenter().x - 400.f + 130.f + 120.f * i, this->view.getCenter().y - 400.f + 95.f));
	}

	if (Keyboard::isKeyPressed(Keyboard::E) && this->speedUseInventory >= 2.f && !this->useInventory)
	{
		this->useInventory = true;
		this->speedUseInventory = 1.f;
	}
	else if(Keyboard::isKeyPressed(Keyboard::E) && this->speedUseInventory >= 2.f && this->useInventory)
	{
		this->useInventory = false;
		this->speedUseInventory = 1.f;
	}
	if (this->speedUseInventory <= 2.f)
	{
		this->speedUseInventory += this->speedUseInventory * dt;
	}
	
	for (int i = 0; i < this->bush.itemDrop.size(); i++)
	{
		if ((this->player.getPosition().x >= this->bush.itemDrop[i].getPosition().x - this->player.getGlobalBounds().width && this->player.getPosition().x <= this->bush.itemDrop[i].getPosition().x + this->bush.itemDrop[i].getGlobalBounds().width) &&
			(this->player.getPosition().y >= this->bush.itemDrop[i].getPosition().y - this->bush.itemDrop[i].getGlobalBounds().height && this->player.getPosition().y <= this->bush.itemDrop[i].getPosition().y + this->bush.itemDrop[i].getGlobalBounds().height))
		{
			this->bush.itemDrop.erase(this->bush.itemDrop.begin() + i);
			switch (this->bush.numItems[i])
			{
			case 1:
				this->item[0] += 1;
				break;
			case 2:
				this->item[1] += 1;
				break;
			case 3:
				this->item[2] += 1;
				break;
			case 4:
				this->item[3] += 1;
				break;
			default:
				break;
			}
			this->bush.numItems.erase(this->bush.numItems.begin() + i);
			this->music.getItem.play();
		}
	}
}

void Player::updateIcons(const float& dt)
{
	this->backpack.setPosition(Vector2f(this->view.getCenter().x - 400.f + 1.f, this->view.getCenter().y + 300.f));

	this->backpackGround[0].setPosition(Vector2f(this->backpack.getPosition().x + this->backpack.getGlobalBounds().width / 2.f - this->backpackGround[0].getGlobalBounds().width / 2.f, this->backpack.getPosition().y + this->backpack.getGlobalBounds().height + 1.f));

	this->key[0].setPosition(this->backpackGround[0].getPosition().x + this->backpackGround[0].getGlobalBounds().width / 2.f - this->key[0].getGlobalBounds().width / 2.f, this->backpackGround[0].getPosition().y + this->backpackGround[0].getGlobalBounds().height / 2.f - this->key[0].getGlobalBounds().height);

	this->gun.setPosition(Vector2f(this->view.getCenter().x - 400.f + 51.f, this->view.getCenter().y + 300.f));

	this->backpackGround[1].setPosition(Vector2f(this->gun.getPosition().x + this->gun.getGlobalBounds().width / 2.f - this->backpackGround[1].getGlobalBounds().width / 2.f, this->gun.getPosition().y + this->gun.getGlobalBounds().height + 1.f));

	this->SpaceBar.setPosition(this->backpackGround[1].getPosition().x + this->backpackGround[1].getGlobalBounds().width / 2.f - this->SpaceBar.getGlobalBounds().width / 2.f, this->backpackGround[1].getPosition().y + this->backpackGround[1].getGlobalBounds().height / 2.f - this->SpaceBar.getGlobalBounds().height / 2.f);

	this->runBarMax.setPosition(Vector2f(this->view.getCenter().x - 390.f, this->view.getCenter().y - 200.f));

	this->runningBar.clear();
	if (this->speedtime >= 1)
	{
		for (int i = 10; i > int(this->speedtime); i--)
		{
			this->runBar.setPosition(Vector2f(this->view.getCenter().x - 390.f, this->view.getCenter().y + (i * 50) - 300.f));
			this->runningBar.push_back(this->runBar);
		}
	}
	else
	{
		for (double i = 0.1; i < double(this->speedtime); i += 0.1)
		{
			this->runBar.setPosition(Vector2f(this->view.getCenter().x - 390.f, this->view.getCenter().y - float(i * 500) + 250.f));
			this->runBar.setFillColor(Color(int(255 - (i * 255)), int(255 - (i * 255)), 255, 255));
			this->runningBar.clear();
			this->runningBar.push_back(this->runBar);
		}
	}
	this->backpackGround[2].setPosition(Vector2f(this->runBarMax.getPosition().x + this->runBarMax.getGlobalBounds().width / 2.f - this->backpackGround[2].getGlobalBounds().width / 2.f ,
		this->runBarMax.getPosition().y - this->backpackGround[2].getGlobalBounds().height));

	this->key[1].setPosition(this->backpackGround[2].getPosition().x + this->backpackGround[2].getGlobalBounds().width / 2.f - this->key[1].getGlobalBounds().width / 2.f, this->backpackGround[2].getPosition().y + this->backpackGround[2].getGlobalBounds().height / 2.f - this->key[1].getGlobalBounds().height / 2.f);
}

void Player::updateBush(const float& dt)
{
	if(this->bushSize < this->bush.bushs.size())
		this->bushSize = int(this->bush.bushs.size());
	if (this->bush.bushs.size() < 3 && this->bushSize < 3)
	{
		this->bush.updateBush(dt);
	}	
}

void Player::updateShop(const float& dt)
{
	if (this->player.getPosition().x <= this->shop.shop.getPosition().x + 100.f)
	{
		if (this->player.getPosition().y >= this->shop.shop.getPosition().y - 100.f &&
			this->player.getPosition().y <= this->shop.shop.getPosition().y + this->shop.shop.getGlobalBounds().width + 100.f)
		{
			if (Keyboard::isKeyPressed(Keyboard::F))
			{
				this->music.playGame.stop();
				this->music.shop.play();
				this->shopping = true;
			}	
		}
	}

	if (!this->shopping)
	{
		this->music.shop.stop();
	}
}

void Player::update(const float& dt)
{
		this->updateSpeedtime(dt);

		this->updateBush(dt);

		this->updateGun(dt);

		this->enemy.update(dt);

		this->updateEnemies(dt);

		this->updateCollision(dt);

		this->shop.updateCost(dt);

		this->updateInventory(dt);

		this->updateIcons(dt);

		this->updateShop(dt);

	//cout << "Player " << this->player.getPosition().x << " " << this->player.getPosition().y << endl;
}

void Player::renderBullets(RenderTarget* target)
{
	for (auto& it : this->bullets)
	{
		target->draw(it);
	}
}

void Player::renderInventory(RenderTarget* target)
{
	target->draw(this->inventoryBar);

	for (auto& it : this->itemInventorys)
	{
		target->draw(it);
	}
	for (auto& it : this->shop.costs)
	{
		target->draw(it);
	}
}

void Player::renderHpBar(RenderTarget* target)
{
	for (int i = 0; i < this->hp; i++)
	{
		this->hpBar.setPosition(Vector2f(this->player.getPosition().x + i * (this->player.getGlobalBounds().width / this->hp), this->player.getPosition().y - 20.f));
		target->draw(this->hpBar);
	}
}

void Player::renderArmor(RenderTarget* target)
{
	for (int i = 0; i < this->item[6]; i++)
	{
		this->armor.setPosition(Vector2f(this->player.getPosition().x + i * (this->player.getGlobalBounds().width / this->item[6]), this->player.getPosition().y - 20.f));
		target->draw(this->armor);
	}
}

void Player::renderClickButtonShop(RenderTarget* target)
{
	if (this->player.getPosition().x <= this->shop.shop.getPosition().x + 100.f)
	{
		if (this->player.getPosition().y >= this->shop.shop.getPosition().y - 100.f && 
			this->player.getPosition().y <= this->shop.shop.getPosition().y + this->shop.shop.getGlobalBounds().width + 100.f)
		{
			this->shop.renderButton(target);
		}
	}
}

void Player::renderViewPlayer(RenderTarget* target)
{
	this->view.setSize(800.f, 800.f);
	this->view.setCenter(this->player.getPosition().x + this->player.getGlobalBounds().width / 2.f, this->player.getPosition().y + this->player.getGlobalBounds().height / 2.f);

	if (this->player.getPosition().x < 400.f)
	{
		this->view.setCenter(400.f, this->view.getCenter().y);
	}
	else if (this->player.getPosition().x + this->player.getGlobalBounds().width > 1600.f)
	{
		this->view.setCenter(1600.f, this->view.getCenter().y);
	}
	if (this->player.getPosition().y < 400.f)
	{
		this->view.setCenter(this->view.getCenter().x, 400.f);
	}
	else if (this->player.getPosition().y + this->player.getGlobalBounds().height > 1600.f)
	{
		this->view.setCenter(this->view.getCenter().x, 1600.f);
	}
	target->setView(this->view);
}

void Player::renderBush(RenderTarget* target)
{
	this->bush.render(target);

	for (int i = 0; i < this->bush.bushs.size(); i++)
	{
		if ((this->player.getPosition().x >= this->bush.bushs[i].getPosition().x - this->player.getGlobalBounds().width && this->player.getPosition().x <= this->bush.bushs[i].getPosition().x + this->bush.bushs[i].getGlobalBounds().width) &&
			(this->player.getPosition().y >= this->bush.bushs[i].getPosition().y - this->bush.bushs[i].getGlobalBounds().height && this->player.getPosition().y <= this->bush.bushs[i].getPosition().y + this->bush.bushs[i].getGlobalBounds().height))
		{
			this->bush.renderget(target, i);
		}	
	}

	this->bush.renderItemDrop(target);
}

void Player::renderIcons(RenderTarget* target)
{
	target->draw(this->backpack);
	target->draw(this->gun);
	for (int i = 0; i < 2; i++)
	{
		target->draw(this->backpackGround[i]);
		target->draw(this->key[i]);
	}
	target->draw(this->backpackGround[2]);
	target->draw(this->runBarMax);
	for (auto& it : this->runningBar)
	{
		target->draw(it);
	}
	target->draw(this->SpaceBar);
}

void Player::renderItemDrop(RenderTarget* target)
{
	for (auto& it : this->enemyItemDrop)
	{
		target->draw(it);
	}
}

void Player::render(RenderTarget* target)
{
	if (this->item[6] >= 1)
	{
		this->renderArmor(target);
	}
	else
	{
		this->renderHpBar(target);
	}

	this->enemy.render(target);

	this->renderClickButtonShop(target);

	target->draw(this->player);

	this->renderBush(target);
	
	if (this->useInventory)
		this->renderInventory(target);

	this->renderIcons(target);

	this->renderItemDrop(target);

	if (this->lock && this->enemy.getKey())
	{
		target->draw(this->enemy.key);
		target->draw(this->enemy.textKey);
	}
	this->renderBullets(target);

	this->renderViewPlayer(target);

}
