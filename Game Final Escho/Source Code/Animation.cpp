#include "header.h"
#include "Animation.h"

Animation::Animation()
{
    this->animationTime = 0.f;
}

Animation::~Animation()
{
}

const bool Animation::getAnimationTime()
{
    if (this->animationTime > 1.f)
        return true;
    else
        return false;
}

void Animation::move(Sprite& sprite, Texture& texture, IntRect& rec, int moveleft, int movetop)
{
    if (this->getAnimationTime())
    {
        rec.left += moveleft;
        rec.top += movetop;

        int textureWidth = texture.getSize().x;
        int textureHeight = texture.getSize().y;

        rec.left = (rec.left % textureWidth + textureWidth) % textureWidth;
        rec.top = (rec.top % textureHeight + textureHeight) % textureHeight;

        sprite.setTexture(texture);
        sprite.setTextureRect(rec);

        this->animationTime = 0.f;
    }
    else
    {
        this->animationTime += 0.1f;
    }
}
