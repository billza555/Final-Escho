#include "header.h"
#include "SaveAndLoad.h"

void SaveAndLoad::initSave()
{
	this->saveText.setFont(this->itemshop.font);
	this->saveText.setFillColor(Color::White);
	this->saveText.setCharacterSize(50);
	this->saveText.setString("SAVE");
	this->saveText.setPosition(Vector2f(600.f - this->saveText.getGlobalBounds().width / 2.f, 50.f));

	this->Button["SAVE1"].updateButton(500.f, 150.f, 200.f, 100.f, "SAVE FILE 1", 30);
	this->Button["SAVE2"].updateButton(500.f, 350.f, 200.f, 100.f, "SAVE FILE 2", 30);
	this->Button["SAVE3"].updateButton(500.f, 550.f, 200.f, 100.f, "SAVE FILE 3", 30);
}

void SaveAndLoad::initLoad()
{
	this->loadText.setFont(this->itemshop.font);
	this->loadText.setFillColor(Color::White);
	this->loadText.setCharacterSize(50);
	this->loadText.setString("LOAD");
	this->loadText.setPosition(Vector2f(600.f - this->loadText.getGlobalBounds().width / 2.f, 50.f));

	this->Button["LOAD1"].updateButton(500.f, 150.f, 200.f, 100.f, "LOAD FILE 1", 30);
	this->Button["LOAD2"].updateButton(500.f, 350.f, 200.f, 100.f, "LOAD FILE 2", 30);
	this->Button["LOAD3"].updateButton(500.f, 550.f, 200.f, 100.f, "LOAD FILE 3", 30);

}

SaveAndLoad::SaveAndLoad()
{
	this->background.setFillColor(Color::Black);
	this->background.setSize(Vector2f(1200.f, 700.f));

	this->initSave();
	this->initLoad();

	this->Button["BACK"].updateButton(1000.f, 600.f, 200.f, 100.f, "Back", 30);
}
SaveAndLoad::~SaveAndLoad()
{
}
void SaveAndLoad::save(const string file_name)
{
	ofstream out_file;
	out_file.open(file_name);

	if (out_file.is_open())
	{
		out_file << this->playerPosition.x << " " << this->playerPosition.y << " " << this->hpPlayer << " " << this->useInventory <<
			" " << this->shopping << " " << this->item[0] << " " << this->item[1] << " " << this->item[2] << " " <<
			this->item[3] << " " << this->item[4] << " " << this->item[5] << " " << this->item[6] << " " << this->item[7] << " " << this->item[8]
			<< " " << this->win << " " << this->lock << " " << this->scoretime << " " << this->itemshop.sell << " " << this->itemshop.bottle << " "
			<< this->speed << " " << this->speedtime << endl;
		out_file.close();
	}
}
void SaveAndLoad::load(const string file_name)
{
	ifstream in_file;
	in_file.open(file_name);

	if (in_file.is_open())
	{
		string line;

		if (getline(in_file, line))
		{
			stringstream ss(line);
			ss >> this->playerPosition.x >> this->playerPosition.y >> this->hpPlayer >> this->useInventory >> this->shopping  
				>> this->item[0] >>this->item[1] >> this->item[2] >> this->item[3] >> this->item[4] >> this->item[5] >> 
				this->item[6] >> this->item[7] >> this->item[8] >> this->win >> this->lock >> this->scoretime >> this->sell >> this->bottle
				>> this->speed >> this->speedtime;
		}
	}
	in_file.close();
}
void SaveAndLoad::loadBush(const string file_name)
{
	ifstream in_file;
	in_file.open(file_name);

	if (in_file.is_open())
	{
		string line;

		if (getline(in_file, line))
		{
			stringstream ss(line);

			ss >> this->bushSize;
			for (int i = 0; i < this->bushSize; i++)
			{
				ss >> this->bushsPosition[i].x >> this->bushsPosition[i].y;
			}
			ss >> this->itemDropSize;
			for (int i = 0; i < this->itemDropSize; i++)
			{
				ss >> this->itemDropPosition[i].x >> this->itemDropPosition[i].y >> this->numItems[i];
			}
		}
		in_file.close();
	}
}
void SaveAndLoad::renderSave(RenderTarget* target)
{
	target->draw(this->saveText);
	this->Button["SAVE1"].renderButton(target);
	this->Button["SAVE2"].renderButton(target);
	this->Button["SAVE3"].renderButton(target);
}
void SaveAndLoad::renderLoad(RenderTarget* target)
{
	target->draw(this->loadText);
	this->Button["LOAD1"].renderButton(target);
	this->Button["LOAD2"].renderButton(target);
	this->Button["LOAD3"].renderButton(target);
}
void SaveAndLoad::render(RenderTarget* target)
{
	target->draw(this->background);
	this->Button["BACK"].renderButton(target);
	target->setView(target->getDefaultView());
}

