#include "header.h"
#include "ScoreBoard.h"

void ScoreBoard::initTable()
{
	this->table.setFillColor(Color::Transparent);
	this->table.setSize(Vector2f(500.f, 100.f));
	this->table.setOutlineThickness(1.f);
	this->table.setOutlineColor(Color::Green);
}

void ScoreBoard::initWordTable()
{
	this->nameWord.setFont(this->font);
	this->nameWord.setCharacterSize(50);
	this->nameWord.setFillColor(Color::White);

	this->scoreWord.setFont(this->font);
	this->scoreWord.setCharacterSize(50);
	this->scoreWord.setFillColor(Color::White);
}

ScoreBoard::ScoreBoard()
{
	this->font.loadFromFile("Fonts/Moon.otf");

	this->backGround.setFillColor(Color::Black);
	this->backGround.setSize(Vector2f(1200.f, 700.f));

	this->creater.setFont(this->font);
	this->creater.setFillColor(Color::White);
	this->creater.setCharacterSize(50);
	this->creater.setString("Rachchanon Klaisuban");
	this->creater.setPosition(Vector2f(this->backGround.getSize().x - this->creater.getGlobalBounds().width, 0.f));

	this->number.setFont(this->font);
	this->number.setFillColor(Color::White);
	this->number.setCharacterSize(50);
	this->number.setString("66010695");
	this->number.setPosition(Vector2f(this->creater.getPosition().x + this->creater.getGlobalBounds().width / 2.f 
		- this->number.getGlobalBounds().width / 2.f, 50.f));

	this->scoreBoard.setFont(this->font);
	this->scoreBoard.setFillColor(Color::White);
	this->scoreBoard.setCharacterSize(50);
	this->scoreBoard.setPosition(Vector2f(450.f, 50.f));
	this->scoreBoard.setString("Scoreboard");

	this->button["BACK"].updateButton(0.f, 0.f, 200.f, 100.f, "Back", 50);

	this->score = 0;

	this->showName.setFont(this->font);
	this->showName.setFillColor(Color::White);
	this->showName.setCharacterSize(50);
	this->showName.setString("Name");
	this->showName.setPosition(Vector2f(350.f - this->showName.getGlobalBounds().width / 2.f , 120.f));

	this->showScore.setFont(this->font);
	this->showScore.setFillColor(Color::White);
	this->showScore.setCharacterSize(50);
	this->showScore.setString("Score");
	this->showScore.setPosition(Vector2f(850.f - this->showScore.getGlobalBounds().width / 2.f, 120.f));

	this->initTable();
	this->initWordTable();
}

ScoreBoard::~ScoreBoard()
{
}

void ScoreBoard::saveScore(const string file_name, string put_name, int put_score)
{
	this->loadScore(file_name);

	ofstream out_file;
	out_file.open(file_name, ios::app);

	if (out_file.is_open())
	{
		out_file << put_name << " " << put_score << "\n";
		out_file.close();
	}
}

void ScoreBoard::loadScore(const string file_name)
{
	this->names.clear();
	this->scores.clear();

	ifstream in_file;
	in_file.open(file_name);

	if (in_file.is_open())
	{
		string line;
		while (getline(in_file, line))
		{
			istringstream iss(line);
			if (iss >> this->name >> this->score)
			{
				this->names.push_back(this->name);
				this->scores.push_back(this->score);
			}
		}
	}
	in_file.close();
}

void ScoreBoard::update(const float& dt)
{
	for (int i = 0; i < this->names.size(); i++)
	{
		if (i != this->names.size() - 1)
		{
			while (this->scores[i] < this->scores[i + 1])
			{
				int in;
				string n;
				in = this->scores[i];
				this->scores[i] = this->scores[i + 1];
				this->scores[i + 1] = in;
				n = this->names[i];
				this->names[i] = this->names[i + 1];
				this->names[i + 1] = n;
			}
		}
	}

	this->tables.clear();
	this->nameWords.clear();
	this->scoreWords.clear();

	for (int i = 0; i < 10 ; i++)
	{
		if (i % 2 == 0)
		{
			this->table.setPosition(Vector2f(100.f, 180.f + 100 / 2 * i));
			this->tables.push_back(this->table);
			this->nameWord.setString(this->names[i / 2]);
			this->nameWord.setPosition(Vector2f(this->table.getPosition().x + this->table.getGlobalBounds().width / 2.f - this->nameWord.getGlobalBounds().width / 2.f,
				this->table.getPosition().y + this->table.getGlobalBounds().height / 2.f - this->nameWord.getGlobalBounds().height / 2.f));
			this->nameWords.push_back(this->nameWord);
		}
		else
		{
			this->table.setPosition(Vector2f(600.f, 180.f + 100 / 2 * (i - 1)));
			this->tables.push_back(this->table);
			this->scoreWord.setString(to_string(this->scores[(i - 1) / 2]));
			this->scoreWord.setPosition(Vector2f(this->table.getPosition().x + this->table.getGlobalBounds().width / 2.f - this->scoreWord.getGlobalBounds().width / 2.f,
				this->table.getPosition().y + this->table.getGlobalBounds().height / 2.f - this->scoreWord.getGlobalBounds().height / 2.f));
			this->scoreWords.push_back(this->scoreWord);
		}
	}
}

void ScoreBoard::renderTable(RenderTarget* target)
{
	for (auto& it : this->tables)
	{
		target->draw(it);
	}
	for (auto& it : this->nameWords)
	{
		target->draw(it);
	}
	for (auto& it : this->scoreWords)
	{
		target->draw(it);
	}
}

void ScoreBoard::render(RenderTarget* target)
{
	target->draw(this->backGround);
	target->draw(this->creater);
	target->draw(this->number);
	this->button["BACK"].renderButton(target);
	target->draw(this->scoreBoard);
	target->draw(this->showName);
	target->draw(this->showScore);
	this->renderTable(target);
	target->setView(target->getDefaultView());
}
