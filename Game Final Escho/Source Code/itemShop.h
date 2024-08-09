#pragma once
#include "Player.h"
class itemShop :
    public Player
{
private:
    Alliance shop;
    Texture textureShop;
    RectangleShape shopBack;
    vector<RectangleShape> sales;
    vector<RectangleShape> purchases;

    map<string, Alliance> buttons;

    RectangleShape inventory;
    RectangleShape statu;

    Text num;
    vector<Text> nums;
    vector<Text> numBuys;

    string intro[10];
    Text status;
    vector<Text> statuses;

    MusicPlay music;

    int costApple, costPapaya, costBanana, costOrange;

    float speed;

    void initCost();
    void initInventory();
    void initItemShop();
    void initItemBuy();
    void initExchange();
    void initButton();
public:
    Font font;
    itemShop();
    virtual ~itemShop();

    int item[9];
    int hp;
    int scoretime;
    bool sell;

    bool bottle;

    void resetItemShop();

    void updateButton(const float& dt, Vector2f mousePosView);
    void updateInventory(const float& dt);
    void updateStatus(const float& dt);

    void update(const float& dt, Vector2f mousePosView);

    void renderItemShop(RenderTarget* target);
    void renderButtons(RenderTarget* target);
    void renderInventory(RenderTarget* target);
    void renderStatus(RenderTarget* target);
    void render(RenderTarget* target);
};

