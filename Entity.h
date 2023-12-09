#ifndef ENTITY_H
#define ENTITY_H

#include <Arduboy2.h>

enum EntityType {
    GROUND,
    COIN,
    ENEMY,
};

class Entity {
public:
    Entity();
    Entity(int initialX, int initialY, int initialWidth, int initialHeight);
    virtual ~Entity();

    void move(float dx, float dy);
    virtual void update();
    virtual void draw(Arduboy2 &arduboy);

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    EntityType getType() const { return type; }

    void setX(int newX)
    {
      x = newX;
      xRaw = newX;
    }
    void setY(int newY)
    {
      y = newY;
      yRaw = newY;
    }

protected:
    float xRaw;
    float yRaw;
    int x;
    int y;
    int width;
    int height;
    EntityType type;

};

inline Entity::Entity() {};
inline Entity::Entity(int initialX, int initialY, int initialWidth, int initialHeight) : x(initialX), y(initialY), width(initialWidth), height(initialHeight) {
  xRaw = x;
  yRaw = y;
}
inline Entity::~Entity() {}
inline void Entity::move(float dx, float dy) {
  xRaw += dx;
  yRaw += dy;
  x = xRaw;
  y = yRaw;
}
inline void Entity::update() {}
inline void Entity::draw(Arduboy2 &arduboy) {}

#endif

