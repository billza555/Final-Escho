#include "header.h"
#include "Game.h"

void Game::initVariables()
{
	this->window = NULL;

	this->dt = 0.f;
}

void Game::initWindow()
{
	this->window = new RenderWindow(VideoMode(1200, 700), "Final Escho", Style::Default);
	this->window->setFramerateLimit(60);
}

void Game::initMenu()
{
	this->menu["START"].updateButton(this->window->getSize().x / 2.f - 200.f, 40.f, 400.f, 100.f, "Play", 50);
	this->menu["CONTINUE"].updateButton(this->window->getSize().x / 2.f - 200.f, 170.f, 400.f, 100.f, "Continue", 50);
	this->menu["LOAD"].updateButton(this->window->getSize().x / 2.f - 200.f, 300.f, 400.f, 100.f, "Load", 50);
	this->menu["SCOREBOARD"].updateButton(this->window->getSize().x / 2.f - 200.f, 430.f, 400.f, 100.f, "Scoreboard", 50);
	this->menu["EXIT"].updateButton(this->window->getSize().x / 2.f - 200.f, 560.f, 400.f, 100.f, "Exit", 50);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initMenu();

	this->die = false;

	this->select = false;

	this->save = false;

	this->load = false;

	this->loading = false;

	this->name = "";

	this->board = false;

	this->namePlayer.setFillColor(Color::White);
	this->namePlayer.setCharacterSize(50);
	this->namePlayer.setFont(this->itemShop.font);

	this->enterName.setFillColor(Color::White);
	this->enterName.setCharacterSize(50);
	this->enterName.setFont(this->itemShop.font);
	this->enterName.setPosition(Vector2f(100.f, 200.f));
	this->enterName.setString("Enter Name");

	this->writeTime = 1.f;

	this->music.menuMusic.play();

	this->d = 0;
}

Game::~Game()
{
	delete this->window;
}

void Game::loadState()
{
	this->die = false;
	this->exit.buttonPress = false;
	this->player.resetPlayer();
	this->itemShop.resetItemShop();
	this->player.player.setPosition(this->saveAndLoad.playerPosition);
	this->player.hp = this->saveAndLoad.hpPlayer;
	this->player.useInventory = this->saveAndLoad.useInventory;
	this->player.shopping = this->saveAndLoad.shopping;
	for (int i = 0; i < 9; i++)
	{
		this->player.item[i] = this->saveAndLoad.item[i];
	}
	this->player.win = this->saveAndLoad.win;
	this->player.lock = this->saveAndLoad.lock;
	this->player.scoretime = this->saveAndLoad.scoretime;
	for (int i = 0; i < this->saveAndLoad.bushSize; i++)
	{
		this->player.loadBush(this->saveAndLoad.bushsPosition[i]);
	}
	for (int i = 0; i < this->saveAndLoad.itemDropSize; i++)
	{
		cout << this->saveAndLoad.numItems[i] << endl;
		this->player.loadItem(this->saveAndLoad.numItems[i], this->saveAndLoad.itemDropPosition[i]);
	}
	this->itemShop.sell = this->saveAndLoad.sell;
	this->itemShop.bottle = this->saveAndLoad.bottle;
	this->player.loadBullet(this->bulletData);
	this->player.loadEnemies(this->enemyData);
	this->enemy.EneSize = this->player.EneSize;
	this->player.speed = this->saveAndLoad.speed;
	this->player.speedtime = this->saveAndLoad.speedtime;
	this->loading = false;
}

void Game::updateMousePosition()
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	//cout << this->mousePosWindow.x << "," << this->mousePosWindow.y << endl;
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		this->select = true;
	}
}

void Game::updateMenu()
{
	if (this->menu["START"].getGlobalBounds().contains(static_cast<Vector2f>(this->mousePosView)))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->music.menuMusic.stop();
			this->music.playGame.play();
			this->menu["START"].menuState = false;
			this->player.resetPlayer();
			this->itemShop.resetItemShop();
			this->die = false;
			this->exit.buttonPress = false;
		}
	}
	if (this->menu["CONTINUE"].getGlobalBounds().contains(static_cast<Vector2f>(this->mousePosView)))
	{
		if (!this->exit.buttonPress)
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				this->music.menuMusic.stop();
				this->music.playGame.play();
				this->menu["START"].menuState = false;
			}
		}
	}
	if (this->menu["LOAD"].getGlobalBounds().contains(static_cast<Vector2f>(this->mousePosView)))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->menu["START"].menuState = true;
			this->load = true;
		}
	}
	if (this->menu["SCOREBOARD"].getGlobalBounds().contains(static_cast<Vector2f>(this->mousePosView)))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->music.menuMusic.stop();
			this->music.scoreBoard.play();
			this->board = true;
			this->scoreBoard.loadScore("Score//scoreBoard.txt");
		}
	}
	if (this->menu["EXIT"].getGlobalBounds().contains(static_cast<Vector2f>(this->mousePosView)))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->window->close();
		}
	}
}

void Game::updateDt()
{
	this->dt = this->clock.restart().asSeconds();
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
			this->window->close();
	}
}

void Game::updateSelecting()
{
	if (this->selecting.choose["MENU"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->music.playGame.stop();
			this->music.menuMusic.play();
			this->menu["START"].menuState = true;
			this->select = false;
		}
	}
	if (this->selecting.choose["LOAD"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->load = true;
		}
	}
	if (this->selecting.choose["SAVE"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->save = true;
		}
	}
	if (this->selecting.choose["CONTINUOUS"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->select = false;
		}
	}
}

void Game::updateSave()
{
	if (this->saveAndLoad.Button["BACK"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->save = false;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		this->save = false;
	}
	if (this->saveAndLoad.Button["SAVE1"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->saveAndLoad.save("Savefile//save1.txt");
			this->player.saveBush("Savefile//bushdata1.txt");
			this->player.saveBullet("Savefile//bulletdata1.txt");
			this->player.saveEnemies("Savefile//enemydata1.txt");
			this->save = false;
		}
	}
	if (this->saveAndLoad.Button["SAVE2"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->saveAndLoad.save("Savefile//save2.txt");
			this->player.saveBush("Savefile//bushdata2.txt");
			this->player.saveBullet("Savefile//bulletdata2.txt");
			this->player.saveEnemies("Savefile//enemydata2.txt");
			this->save = false;
		}
	}
	if (this->saveAndLoad.Button["SAVE3"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->saveAndLoad.save("Savefile//save3.txt");
			this->player.saveBush("Savefile//bushdata3.txt");
			this->player.saveBullet("Savefile//bulletdata3.txt");
			this->player.saveEnemies("Savefile//enemydata3.txt");
			this->save = false;
		}
	}
}

void Game::updateLoad()
{
	if (this->saveAndLoad.Button["BACK"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->load = false;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		this->load = false;
	}
	if (this->saveAndLoad.Button["LOAD1"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->music.menuMusic.stop();
			this->music.playGame.play();
			this->load = false;
			this->select = false;
			this->menu["START"].menuState = false;
			this->saveAndLoad.load("Savefile//save1.txt");
			this->saveAndLoad.loadBush("Savefile//bushdata1.txt");
			this->bulletData = "Savefile//bulletdata1.txt";
			this->enemyData = "Savefile//enemydata1.txt";
			this->loading = true;
		}
	}
	if (this->saveAndLoad.Button["LOAD2"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->music.menuMusic.stop();
			this->music.playGame.play();
			this->load = false;
			this->select = false;
			this->menu["START"].menuState = false;
			this->saveAndLoad.load("Savefile//save2.txt");
			this->saveAndLoad.loadBush("Savefile//bushdata2.txt");
			this->bulletData = "Savefile//bulletdata2.txt";
			this->enemyData = "Savefile//enemydata2.txt";
			this->loading = true;
		}
	}
	if (this->saveAndLoad.Button["LOAD3"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->music.menuMusic.stop();
			this->music.playGame.play();
			this->load = false;
			this->select = false;
			this->menu["START"].menuState = false;
			this->saveAndLoad.load("Savefile//save3.txt");
			this->saveAndLoad.loadBush("Savefile//bushdata3.txt");
			this->bulletData = "Savefile//bulletdata3.txt";
			this->enemyData = "Savefile//enemydata3.txt";
			this->loading = true;
		}
	}
}

void Game::updateScoreBoard()
{
	if (this->scoreBoard.button["BACK"].getGlobalBounds().contains(this->mousePosView))
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->music.scoreBoard.stop();
			this->music.menuMusic.play();
			this->board = false;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		this->music.scoreBoard.stop();
		this->music.menuMusic.play();
		this->board = false;
	}
}

void Game::update()
{
	this->updateMousePosition();
	
	this->player.updateExit(dt);

	if (this->player.hp < 0)
	{
		this->die = true;
		if(this->music.loss.getStatus() != SoundSource::Status::Playing)
			this->music.loss.play();
	}
	if (this->board)
	{
		if (this->music.scoreBoard.getStatus() == SoundSource::Status::Stopped)
		{
			this->music.scoreBoard.play();
		}
		this->scoreBoard.update(dt);
		this->updateScoreBoard();
	}
	else if (this->save)
	{
		this->saveAndLoad.playerPosition = this->player.getPosition();
		this->saveAndLoad.hpPlayer = this->player.hp;
		this->saveAndLoad.useInventory = this->player.useInventory;
		this->saveAndLoad.shopping = this->player.shopping;
		for (int i = 0; i < 9; i++)
		{
			this->saveAndLoad.item[i] = this->player.item[i];
		}
		this->saveAndLoad.win = this->player.win;
		this->saveAndLoad.lock = this->player.lock;
		this->saveAndLoad.scoretime = this->player.scoretime;
		this->saveAndLoad.sell = this->itemShop.sell;
		this->saveAndLoad.bottle = this->itemShop.bottle;
		this->saveAndLoad.speed = this->player.speed;
		this->saveAndLoad.speedtime = this->player.speedtime;
		this->updateSave();
	}
	else if (this->load)
	{
		this->updateLoad();
	}
	else if (this->select)
	{
		this->updateSelecting();
		this->selecting.updateStatus(dt);
		this->selecting.hp = this->player.hp;
		this->selecting.armor = this->player.item[6];
		this->selecting.speed = this->player.item[7];
		this->selecting.damage = this->player.item[8];
		this->selecting.score = this->player.scoretime;
	}
	else if (!this->menu["START"].menuState && !this->die && !this->player.shopping && !this->player.win)
	{
		if (this->music.playGame.getStatus() == SoundSource::Status::Stopped)
		{
			this->music.playGame.play();
		}
		if (this->music.playGame.getStatus() == SoundSource::Status::Paused)
		{
			this->music.playGame.play();
		}
		//this->background.update(dt, mousePosView);
		this->updateInput();
		this->player.update(dt);
		this->shop.updateAnimation(dt);
		this->itemShop.shopping = this->player.shopping;
		for (int i = 0; i < 9; i++)
		{
			this->itemShop.item[i] = this->player.item[i];
		}
		this->background.lock = this->player.lock;
		this->enemy.scoretime = this->player.scoretime;
	}
	else if (this->player.shopping && !this->player.win && !this->menu["START"].menuState && !this->die)
	{
		this->music.playGame.pause();
		this->itemShop.update(dt, this->mousePosView);
		this->player.shopping = this->itemShop.shopping;
		for (int i = 0; i < 9; i++)
		{
			this->player.item[i] = this->itemShop.item[i];
		}
		if (this->itemShop.bottle)
		{
			this->player.hp = this->itemShop.hp;
		}
		this->itemShop.hp = this->player.hp;
		this->itemShop.scoretime = this->player.scoretime;
	}
	else if (this->player.win && !this->menu["START"].menuState && !this->die)
	{
		this->music.playGame.stop();
		this->exit.updateMenuButton(dt, this->mousePosView);
		this->menu["START"].menuState = this->exit.buttonPress;
		if (this->exit.buttonPress)
		{
			if (this->name == "")
			{
				this->name = "Anonymous";
			}
			this->scoreBoard.saveScore("Score//scoreBoard.txt", this->name, this->exit.scoretime);
			this->name = "";
		}
		this->exit.scoretime = this->player.scoretime;
		this->exit.updateScore(dt);
		if (this->writeTime > 2.f)
		{
			if (this->event.type == Event::TextEntered) {
				if (this->event.text.unicode == 8) {
					if (!this->name.empty()) {
						this->name.pop_back();
					}
				}
				else if (this->event.text.unicode == 32)
				{
					this->name += static_cast<char>(event.text.unicode = 95);
				}
				else {
					this->name += static_cast<char>(event.text.unicode);
				}
			}
			this->writeTime = 1.f;
		}
		else
		{
			this->writeTime += 0.1f;
		}
		this->namePlayer.setString("Name : " + this->name);
		this->namePlayer.setPosition(Vector2f(100.f, 300.f));
	}
	else if (!this->menu["START"].menuState && this->die)
	{
		this->music.playGame.stop();
		this->exit.updateMenuButton(dt, this->mousePosView);
		this->menu["START"].menuState = this->exit.buttonPress;
		if (this->exit.buttonPress)
		{
			if (this->name == "")
			{
				this->name = "Anonymous";
			}
			this->scoreBoard.saveScore("Score//scoreBoard.txt", this->name, this->exit.scoretime);
			this->name = "";
		}
		this->exit.scoretime = this->player.scoretime;
		this->exit.updateScore(dt);
		if (this->writeTime > 2.f)
		{
			if (this->event.type == Event::TextEntered) {
				if (this->event.text.unicode == 8) {
					if (!this->name.empty()) {
						this->name.pop_back();
					}
				}
				else if (this->event.text.unicode == 32)
				{
					this->name += static_cast<char>(event.text.unicode = 95);
				}
				else {
					this->name += static_cast<char>(event.text.unicode);
				}
			}
			this->writeTime = 1.f;
		}
		else
		{
			this->writeTime += 0.1f;
		}
		this->namePlayer.setString("Name : " + this->name);
		this->namePlayer.setPosition(Vector2f(100.f, 300.f));
	}
	else if (this->menu["START"].menuState)
	{
		this->player.hp = 10;
		if (this->music.menuMusic.getStatus() == SoundSource::Status::Stopped)
		{
			this->music.menuMusic.play();
		}
		this->updateMenu();
	}
	if (this->loading)
	{
		this->loadState();
	}
	this->updateEvents();
}

void Game::render()
{
	this->window->clear();

	if (this->board)
	{
		this->scoreBoard.render(this->window);
	}
	else if (this->save)
	{
		this->saveAndLoad.render(this->window);
		this->saveAndLoad.renderSave(this->window);
	}
	else if (this->load)
	{
		this->saveAndLoad.render(this->window);
		this->saveAndLoad.renderLoad(this->window);
	}
	else if (this->select)
	{
		this->selecting.render(this->window);
	}
	else if (!this->menu["START"].menuState && !this->die && this->player.hp > 0 && !this->player.shopping && !this->player.win)
	{
		this->background.render(this->window);
		this->shop.render(this->window);
		this->enemy.render(this->window);
		this->exit.render(this->window);
		//this->bush.render(this->window);
		this->player.render(this->window);
	}
	else if (this->player.shopping && !this->player.win && !this->menu["START"].menuState && !this->die)
	{
		this->itemShop.render(this->window);
	}
	else if (this->player.win && !this->menu["START"].menuState && !this->die)
	{
		this->window->setView(this->window->getDefaultView());
		this->exit.renderWinBackground(this->window);
		this->window->draw(this->enterName);
		this->window->draw(this->namePlayer);
	}
	else if (!this->menu["START"].menuState && this->die)
	{
		this->window->setView(this->window->getDefaultView());
		this->exit.renderExitBackground(this->window);
		this->window->draw(this->enterName);
		this->window->draw(this->namePlayer);
	}
	else if (this->menu["START"].menuState)
	{
		this->menu[""].renderMenuBackground(this->window);
		this->menu["START"].renderButton(this->window);
		this->menu["CONTINUE"].renderButton(this->window);
		this->menu["LOAD"].renderButton(this->window);
		this->menu["SCOREBOARD"].renderButton(this->window);
		this->menu["EXIT"].renderButton(this->window);
		this->window->setView(this->window->getDefaultView());
	}
	this->window->display();

}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}



