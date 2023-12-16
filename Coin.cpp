//
// Created by chase on 12/14/23.
//

#include "Coin.h"
#include "sprites.h"

Coin::Coin()
{

}

void Coin::init(int segmentX, int x, int y)
{
  this->positionInSegmentX = x;
  this->x = x + segmentX;
  this->xRaw = x;
  this->y = y;
  this->yRaw = y;
  this->enabled = true;
}

void Coin::update(int newX)
{
  if (!enabled)
  {
    return;
  }
  x = newX + positionInSegmentX;
}

void Coin::draw(Arduboy2 &arduboy)
{
  if (!enabled)
  {
    return;
  }
  Sprites::drawSelfMasked(x, y, item_coin, 0);
}