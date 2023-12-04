#ifndef ENTITY_H
#define ENTITY_H

#include <Arduboy2.h>

class Entity {
public:
    Entity();
    Entity(int initialX, int initialY, int initialWidth, int initialHeight);
    virtual ~Entity();

    void move(int dx, int dy);
    virtual void update();
    virtual void draw(Arduboy2 &arduboy);

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const char* getType() const { return type; }

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

protected:
    int x;
    int y;
    int width;
    int height;
    const char* type;

};

inline Entity::Entity() {};
inline Entity::Entity(int initialX, int initialY, int initialWidth, int initialHeight) : x(initialX), y(initialY), width(initialWidth), height(initialHeight) {}
inline Entity::~Entity() {}
inline void Entity::move(int dx, int dy) {
  x += dx;
  y += dy;
}
inline void Entity::update() {}
inline void Entity::draw(Arduboy2 &arduboy) {}

#endif

