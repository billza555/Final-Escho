#pragma once
#include "Menu.h"
class ScoreBoard :
    public Menu
{
private:
    Font font;
    Text creater;
    Text number;

    RectangleShape backGround;
    Text scoreBoard;

    Text showName;
    Text showScore;

    int score;
    vector<int> scores;
    string name;
    vector<string> names;

    RectangleShape table;
    vector<RectangleShape> tables;

    Text nameWord;
    vector<Text> nameWords;
    Text scoreWord;
    vector<Text> scoreWords;

    void initTable();
    void initWordTable();
public:
    map<string, Menu> button;
    ScoreBoard();
    virtual ~ScoreBoard();

    void saveScore(const string file_name, string put_name, int put_score);
    void loadScore(const string file_name);

    void update(const float& dt);
    void renderTable(RenderTarget* target);
    void render(RenderTarget* target);
};

