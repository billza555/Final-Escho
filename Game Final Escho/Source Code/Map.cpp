#include "header.h"
#include "Map.h"

void Map::initObstruct()
{
	this->obstruct.setFillColor(Color::Transparent);
	this->obstruct.setSize(this->sizeob);
	this->obstruct.setOutlineThickness(2.f);
	this->obstruct.setOutlineColor(Color::Red);
}

void Map::initDecorate()
{
	this->decorate[0].loadFromFile("Resources/Background/lava.png");
	this->decorate[1].loadFromFile("Resources/Background/tent.png");
	this->decorate[2].loadFromFile("Resources/Background/lock.png");
	this->decorate[3].loadFromFile("Resources/Background/mud.png");

	for (int i = 0; i < 4; i++)
	{
		this->decorateObject[i].setTexture(&this->decorate[i]);
		this->decorateObject[i].setSize(Vector2f(100.f, 100.f));
	}
	this->decorateObject[2].setPosition(Vector2f(1284.f, 0.f));
	this->object.push_back(this->decorateObject[2]);
	this->decorateObject[0].setPosition(Vector2f(1860.11f, 1795.f));
	this->object.push_back(this->decorateObject[0]);
	this->decorateObject[0].setPosition(Vector2f(1860.11f, 325.3f));
	this->object.push_back(this->decorateObject[0]);
	this->decorateObject[0].setPosition(Vector2f(332.597f, 1795.f));
	this->object.push_back(this->decorateObject[0]);
	this->decorateObject[1].setPosition(Vector2f(1514.22f, 224.596f));
	this->object.push_back(this->decorateObject[1]);
	this->decorateObject[3].setPosition(Vector2f(1000.f , 1000.f));
	this->object.push_back(this->decorateObject[3]);
	this->decorateObject[3].setPosition(Vector2f(1500.f, 1200.f));
	this->object.push_back(this->decorateObject[3]);
	this->decorateObject[3].setPosition(Vector2f(400.f, 500.f));
	this->object.push_back(this->decorateObject[3]);
	
}

Map::Map()
{
	this->textureBackground.loadFromFile("Resources/Background/bige.png");
	this->background.setTexture(&this->textureBackground);
	this->background.setSize(Vector2f(2000.f, 2000.f));

	this->sizeob.x = 100.f;
	this->sizeob.y = 100.f;

	this->clickRec = 0.1f;

	this->lock = true;

	this->loadFromFile("Background//obstruction.slmp");

	this->initObstruct();

	this->initDecorate();
}

Map::~Map()
{
}

const bool Map::getClick() 
{
	if (this->clickRec >= 3.0f)
	{
		this->clickRec = 0.1f;
		return true;
	}
	else
		return false;
}

void Map::Obstructions()
{
	this->obstruct.setFillColor(Color::Transparent);
	this->obstruct.setSize(this->sizeob);
	this->obstruct.setOutlineThickness(2.f);
	this->obstruct.setOutlineColor(Color::Red);

	this->obstructs.push_back(this->obstruct);
}

void Map::saveToFile(const string file_name)
{
	ofstream out_file;
	out_file.open(file_name);

	if (out_file.is_open())
	{
		for (size_t i = 0; i < this->obstructs.size(); i++)
		{
			out_file << this->obstructs[i].getPosition().x << " " << this->obstructs[i].getPosition().y << " " << 
				this->obstructs[i].getGlobalBounds().width << " " << this->obstructs[i].getGlobalBounds().height << endl;
		}
		out_file.close();
	}
}

void Map::loadFromFile(const string file_name)
{
	ifstream in_file;
	in_file.open(file_name);

	if (in_file.is_open())
	{
		string line;

		while (getline(in_file, line)) {
			Vector2f pos;
			Vector2f size;

			stringstream ss(line);
			ss >> pos.x >> pos.y >> size.x >> size.y;

			this->position = pos;
			this->scale = size;

			this->obstruct.setFillColor(Color::Transparent);
			this->obstruct.setPosition(this->position);
			this->obstruct.setSize(this->scale);
			this->obstruct.setOutlineThickness(1.f);
			this->obstruct.setOutlineColor(Color::Red);

			this->obstructs.push_back(this->obstruct);
		}
	}
	in_file.close();
}

void Map::updateClick(const float& dt)
{
	if (this->clickRec <= 3.0f)
	{
		this->clickRec += this->clickRec * dt;
	}		
}

void Map::updateObstruction(const float& dt, Vector2f& mousePosView)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->obstruct.move(-300 * dt, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->obstruct.move(300 * dt, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->obstruct.move(0, -300 * dt);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->obstruct.move(0, 300 * dt);
	}
	if (Keyboard::isKeyPressed(Keyboard::E) && this->getClick())
	{
		this->Obstructions();
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		for (size_t i = 0; i < this->obstructs.size() ; i++)
		{
			if (this->obstructs[i].getGlobalBounds().contains(mousePosView))
			{
				this->obstructs.erase(this->obstructs.begin() + i);
			}
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::F))
	{
		this->saveToFile("Background//obstruction.slmp");
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && this->sizeob.y > 10.f)
	{
		this->sizeob.y -= 1.f;
		this->obstruct.setSize(this->sizeob);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->sizeob.y += 1.f;
		this->obstruct.setSize(this->sizeob);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && this->sizeob.x > 10.f)
	{
		this->sizeob.x -= 1.f;
		this->obstruct.setSize(this->sizeob);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->sizeob.x += 1.f;
		this->obstruct.setSize(this->sizeob);
	}
}

void Map::update(const float& dt, Vector2f& mousePosView)
{
	this->updateClick(dt);
	this->updateObstruction(dt, mousePosView);

	/*cout << this->obstruct.getPosition().x << " " << this->obstruct.getPosition().y << "== Obstruction " << endl;
	cout << mousePosView.x << " " << mousePosView.y << "== Mouse " << endl;
	for (size_t i = 0; i < this->obstructs.size(); i++)
	{
		cout << this->obstructs[i].getPosition().x << " " << obstructs[i].getPosition().y << "== Obstruction [" << i << "]" << endl;
	}*/
	
}

void Map::renderObstructs(RenderTarget* target)
{
	for (auto& it : this->obstructs)
	{
		target->draw(it);
	}
}

void Map::renderDecorate(RenderTarget* target)
{
	for (int i = 0; i < this->object.size() ; i++)
	{
		if (i == 0 && !this->lock)
		{

		}
		else
		{
			target->draw(this->object[i]);
		}
	}
}

void Map::render(RenderTarget* target)
{
	this->renderObstructs(target);
	target->draw(this->background);
	this->renderDecorate(target);
	//target->draw(this->obstruct);

	//this->view.setCenter(this->obstruct.getPosition().x, this->obstruct.getPosition().y);
	//target->setView(this->view);

}







