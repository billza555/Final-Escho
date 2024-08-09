#include "header.h"
#include "Enemy.h"

Enemy::Enemy()
{
	this->textureEnemy[0].loadFromFile("Resources/Entity/enemy1animation.png");
	this->textureEnemy[1].loadFromFile("Resources/Entity/enemy2animation.png");
	this->textureEnemy[2].loadFromFile("Resources/Entity/enemy3animation.png");
	this->textureEnemy[3].loadFromFile("Resources/Entity/enemy4animation.png");

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->enemyMove[i][j] = IntRect(0, 0 + j * 100, 100, 100);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		this->enemy[i].setTexture(this->textureEnemy[i]);
		this->enemy[i].setTextureRect(this->enemyMove[i][0]);
	}

	this->maxEnemies = 4;

	spawn = 20.f;

	for (int i = 0; i < 4; i++)
	{
		this->loopMove[i] = true;
		this->velocity[i] = 0;
		this->direction[i] = 0;
	}

	this->bullet.setFillColor(Color::Black);

	for (int i = 0; i < 4; i++)
	{
		this->bulletTime[i] = 1.f;
	}

	for (int i = 0; i < 4; i++)
	{
		this->hpEnemiesBar[i].setFillColor(Color::Red);
		this->hpEnemiesBar[i].setOutlineThickness(2.f);
		this->hpEnemiesBar[i].setOutlineColor(Color::Black);
	}

	this->font.loadFromFile("Fonts/Moon.otf");
	this->textureKey.loadFromFile("Resources/Supple/key.png");
	this->key.setTexture(&this->textureKey);
	this->key.setSize(Vector2f(50.f, 50.f));
	this->textKey.setFont(this->font);
	this->textKey.setCharacterSize(30);
	this->textKey.setFillColor(Color::Black);
	this->textKey.setString("F");

	this->kei = 0;

	this->EneSize = 0;

	this->key.setPosition(Vector2f(0.f, 0.f));
	this->textKey.setPosition(this->key.getPosition().x + 50.f, this->key.getPosition().y);

	this->scoretime = 0;

	this->hp = 0;

	for (int i = 0; i < 4; i++)
	{
		this->anim[i] = 0;
	}
}

Enemy::~Enemy()
{
	
}

const bool Enemy::getKey() const
{
	if (this->kei > 70)
		return true;
	else
		return false;
}

const bool Enemy::getBulletTime(int i) 
{
	if (this->bulletTime[i] >= 2.f)
	{
		this->bulletTime[i] = 1.f;
		return true;
	}
	else
	{
		return false;
	}
}

void Enemy::reset()
{
	this->enemies.clear();
	this->bullets.clear();
	this->values.clear();
	this->hpEnemies.clear();

	this->kei = 0;

	this->EneSize = 0;

	this->key.setPosition(Vector2f(0.f, 0.f));
	this->textKey.setPosition(this->key.getPosition().x + 50.f, this->key.getPosition().y);

	for (int i = 0; i < 4; i++)
	{
		this->enemy[i].setTexture(this->textureEnemy[i]);
		this->enemy[i].setTextureRect(this->enemyMove[i][0]);
	}

	for (int i = 0; i < 4; i++)
	{
		this->anim[i] = 0;
	}
}

void Enemy::loadEnemies(int i, Vector2f EnemiesPosition)
{
	this->enemy[i].setPosition(EnemiesPosition);
	this->enemies.push_back(this->enemy[i]);
}

void Enemy::loadBullet(Vector2f bulletScale, Vector2f bulletPosition, int value)
{
	this->bullet.setSize(bulletScale);
	this->bullet.setPosition(bulletPosition);
	this->bullets.push_back(this->bullet);
	this->values.push_back(value);
}

void Enemy::updateBulletTime(const float& dt)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->bulletTime[i] < 2.f)
		{
			this->bulletTime[i] += this->bulletTime[i] * dt;
		}
	}
}

void Enemy::updateBullet(const float& dt, int i, int direction, int value)
{
	if (direction == 0)
	{
		this->bullet.setSize(Vector2f(5.f, 25.f));
	}
	else if (direction == 1)
	{
		this->bullet.setSize(Vector2f(25.f, 5.f));
	}
	this->bullet.setPosition(this->enemies[i].getPosition().x + this->enemies[i].getGlobalBounds().width / 2.f,
		this->enemies[i].getPosition().y + this->enemies[i].getGlobalBounds().height / 2.f);
	this->bullets.push_back(this->bullet);
	this->values.push_back(value);
}

void Enemy::updateBulletMove(const float& dt)
{
	for (int i = 0; i < this->bullets.size(); i++)
	{
		if (this->values[i] == 1)
		{
			this->bullets[i].move(Vector2f(0.f, -500.f * dt));
		}
		if (this->values[i] == 2)
		{
			this->bullets[i].move(Vector2f(0.f, 500.f * dt));
		}
		if (this->values[i] == 3)
		{
			this->bullets[i].move(Vector2f(-500.f * dt, 0.f));
		}
		if (this->values[i] == 4)
		{
			this->bullets[i].move(Vector2f(500.f * dt, 0.f));
		}

		if (this->bullets[i].getPosition().x < 0.f || this->bullets[i].getPosition().x > this->maps.background.getGlobalBounds().width ||
			this->bullets[i].getPosition().y < 0.f || this->bullets[i].getPosition().x > this->maps.background.getGlobalBounds().height)
		{
			this->bullets.erase(this->bullets.begin() + i);
			this->values.erase(this->values.begin() + i);
		}
	}

}

void Enemy::updateEnemies(const float& dt)
{
	if (this->EneSize < this->enemies.size())
		this->EneSize = int(this->enemies.size());
	for (int i = this->EneSize; i < this->maxEnemies; i++)
	{
		if (spawn > 50.f)
		{
			unsigned int enemi = rand() % 100;
			int type;
			if (enemi >= 90)
			{
				type = 0;
				this->enemiesType.push_back(type);
			}
			else if (enemi >= 76)
			{
				type = 1;
				this->enemiesType.push_back(type);
			}
			else if (enemi >= 50)
			{
				type = 2;
				this->enemiesType.push_back(type);
			}
			else if (enemi >= 0)
			{
				type = 3;
				this->enemiesType.push_back(type);
			}
			this->enemy[type].setPosition(Vector2f(this->maps.object[4].getPosition().x, this->maps.object[4].getPosition().y));
			this->enemies.push_back(this->enemy[type]);
			this->EneSize++;
			spawn = 1.f;
			switch (type)
			{
			case 0:
				hp = 8 + int(this->scoretime / 1000);
				this->hpEnemies.push_back(this->hp);
				break;
			case 1:
				hp = 6 + int(this->scoretime / 1000);
				this->hpEnemies.push_back(this->hp);
				break;
			case 2:
				hp = 4 + int(this->scoretime / 1000);
				this->hpEnemies.push_back(this->hp);
				break;
			case 3:
				hp = 2 + int(this->scoretime / 1000);
				this->hpEnemies.push_back(this->hp);
				break;
			default:
				break;
			}
		}
		else
		{
			spawn += spawn * dt;
		}
	}
	
	for (int i = 0; i < this->enemies.size(); i++)
	{
		if (this->hpEnemies[i] <= 0)
		{
			if (kei <= 70)
			{
				kei = rand() % 100;
				if (kei > 70)
				{
					this->key.setPosition(this->enemies[i].getPosition());
					this->textKey.setPosition(this->key.getPosition().x + 50.f, this->key.getPosition().y);
				}
			}
			this->enemies.erase(this->enemies.begin() + i);
			this->hpEnemies.erase(this->hpEnemies.begin() + i);
			this->enemiesType.erase(this->enemiesType.begin() + i);
			this->EneSize--;
		}
	}
}

void Enemy::updateEnemiesMove(const float& dt)
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		if (this->enemies[i].getTexture() == &this->textureEnemy[0])
		{
			if (this->loopMove[i] == true)
			{
				this->velocity[i] = rand() % 600 - 300;
				while (this->velocity[i] > -100 && this->velocity[i] < 100)
				{
					this->velocity[i] = rand() % 600 - 300;
				}
				this->loopMove[i] = !loopMove[i];
				this->direction[i] = rand() % 2;
			}
			else
			{
				if (this->anim[i] <= 0)
				{
					if (this->direction[i] == 0)
					{
						this->enemies[i].move(this->velocity[i] * dt, 0.f);
						if (this->velocity[i] >= 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][1], 100, 0);
						else if (this->velocity[i] < 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][3], 100, 0);
					}
					else
					{
						this->enemies[i].move(0.f, this->velocity[i] * dt);
						if (this->velocity[i] >= 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][0], 100, 0);
						else if (this->velocity[i] < 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][2], 100, 0);
					}
				}
				else
				{
					this->anim[i]--;
				}
			}
		}
		else if (this->enemies[i].getTexture() == &this->textureEnemy[1])
		{
			if (this->loopMove[i] == true)
			{
				this->velocity[i] = rand() % 600 - 300;
				while (this->velocity[i] > -50 && this->velocity[i] < 50)
				{
					this->velocity[i] = rand() % 600 - 300;
				}
				this->loopMove[i] = !loopMove[i];
				this->direction[i] = rand() % 2;
			}
			else
			{
				if (this->anim[i] <= 0)
				{
					if (this->direction[i] == 0)
					{
						this->enemies[i].move(this->velocity[i] * dt, 0.f);
						if (this->velocity[i] >= 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][1], 100, 0);
						else if (this->velocity[i] < 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][3], 100, 0);
					}
					else
					{
						this->enemies[i].move(0.f, this->velocity[i] * dt);
						if (this->velocity[i] >= 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][0], 100, 0);
						else if (this->velocity[i] < 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][2], 100, 0);
					}
				}
				else
				{
					this->anim[i]--;
				}
			}
		}
		else if (this->enemies[i].getTexture() == &this->textureEnemy[2])
		{
			if (this->loopMove[i] == true)
			{
				this->velocity[i] = rand() % 600 - 300;
				while (this->velocity[i] > -30 && this->velocity[i] < 30)
				{
					this->velocity[i] = rand() % 600 - 300;
				}
				this->loopMove[i] = !loopMove[i];
				this->direction[i] = rand() % 2;
			}
			else
			{
				if (this->anim[i] <= 0)
				{
					if (this->direction[i] == 0)
					{
						this->enemies[i].move(this->velocity[i] * dt, 0.f);
						if (this->velocity[i] >= 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][1], 100, 0);
						else if (this->velocity[i] < 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][3], 100, 0);
					}
					else
					{
						this->enemies[i].move(0.f, this->velocity[i] * dt);
						if (this->velocity[i] >= 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][0], 100, 0);
						else if (this->velocity[i] < 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][2], 100, 0);
					}
				}
				else
				{
					this->anim[i]--;
				}
			}
		}
		else if (this->enemies[i].getTexture() == &this->textureEnemy[3])
		{
			if (this->loopMove[i] == true)
			{
				this->velocity[i] = rand() % 600 - 300;
				while (this->velocity[i] > -10 && this->velocity[i] < 10)
				{
					this->velocity[i] = rand() % 600 - 300;
				}
				this->loopMove[i] = !loopMove[i];
				this->direction[i] = rand() % 2;
			}
			else
			{
				if (this->anim[i] <= 0)
				{
					if (this->direction[i] == 0)
					{
						this->enemies[i].move(this->velocity[i] * dt, 0.f);
						if (this->velocity[i] >= 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][1], 100, 0);
						else if (this->velocity[i] < 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][3], 100, 0);
					}
					else
					{
						this->enemies[i].move(0.f, this->velocity[i] * dt);
						if (this->velocity[i] >= 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][0], 100, 0);
						else if (this->velocity[i] < 0)
							this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][2], 100, 0);

					}
				}
				else
				{
					this->anim[i]--;
				}
			}
		}
		
		for (const RectangleShape& obstruct : this->maps.obstructs) {
			if (this->enemies[i].getGlobalBounds().intersects(obstruct.getGlobalBounds())) {
				FloatRect EnemiesBounds = this->enemies[i].getGlobalBounds();
				FloatRect obstructBounds = obstruct.getGlobalBounds();

				float overlapX = min(EnemiesBounds.left + EnemiesBounds.width, obstructBounds.left + obstructBounds.width) - max(EnemiesBounds.left, obstructBounds.left);
				float overlapY = min(EnemiesBounds.top + EnemiesBounds.height, obstructBounds.top + obstructBounds.height) - max(EnemiesBounds.top, obstructBounds.top);


				if (overlapX > overlapY) {

					if (EnemiesBounds.top < obstructBounds.top) {
						this->enemies[i].setPosition(EnemiesBounds.left, obstructBounds.top - EnemiesBounds.height);
						this->loopMove[i] = !loopMove[i];
					}
					else {
						this->enemies[i].setPosition(EnemiesBounds.left, obstructBounds.top + obstructBounds.height);
						this->loopMove[i] = !loopMove[i];
					}
				}
				else {
					if (EnemiesBounds.left < obstructBounds.left) {
						this->enemies[i].setPosition(obstructBounds.left - EnemiesBounds.width, EnemiesBounds.top);
						this->loopMove[i] = !loopMove[i];
					}
					else {
						this->enemies[i].setPosition(obstructBounds.left + obstructBounds.width, EnemiesBounds.top);
						this->loopMove[i] = !loopMove[i];
					}
				}
			}
		}
	}
}

void Enemy::updateEnemiesGoTOPlayer(const float& dt, int i, int j)
{
	this->animation.move(this->enemies[i], this->textureEnemy[i], this->enemyMove[i][j], 100, 0);

	this->anim[i]++;
}

void Enemy::update(const float& dt)
{
	this->updateBulletTime(dt);
	this->updateBulletMove(dt);
	this->updateEnemies(dt);
	this->updateEnemiesMove(dt);
}

void Enemy::renderBullet(RenderTarget* target)
{
	for (auto& it : this->bullets)
	{
		target->draw(it);
	}
}

void Enemy::renderEnemies(RenderTarget* target)
{
	for (auto& it : this->enemies)
	{
		target->draw(it);
	}
}

void Enemy::renderHpEnemies(RenderTarget* target)
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->hpEnemiesBar[i].setSize(Vector2f(this->enemies[i].getGlobalBounds().width / this->hpEnemies[i], 20.f));
		for (int j = 0; j < this->hpEnemies[i]; j++)
		{
			this->hpEnemiesBar[i].setPosition(Vector2f(this->enemies[i].getPosition().x + j * (this->enemies[i].getGlobalBounds().width / this->hpEnemies[i]), this->enemies[i].getPosition().y - 20.f));
			target->draw(this->hpEnemiesBar[i]);
		}
	}
}

void Enemy::render(RenderTarget* target)
{
	this->renderBullet(target);
	this->renderEnemies(target);
	this->renderHpEnemies(target);
}
