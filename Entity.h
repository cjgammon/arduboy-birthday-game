#ifndef ENTITY_H
#define ENTITY_H

#include <Arduboy2.h>

class Entity {
public:
    Entity();
    Entity(int initialX, int initialY, int initialWidth, int initialHeight, int initialSpeed);
    virtual ~Entity();

    void move(int dx, int dy);
    virtual void update();
    virtual void draw(Arduboy2 &arduboy);

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

protected:
    int x;
    int y;
    int width;
    int height;
    int speed;
};

inline Entity::Entity() {};
inline Entity::Entity(int initialX, int initialY, int initialWidth, int initialHeight, int initialSpeed) : x(initialX), y(initialY), width(initialWidth), height(initialHeight), speed(initialSpeed) {}
inline Entity::~Entity() {}
inline void Entity::update() {}
inline void Entity::draw(Arduboy2 &arduboy) {}

#endif

