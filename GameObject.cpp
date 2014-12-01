#include "headers.h"
#include "GameObject.h"

GameObject::GameObject(): loaded(false)
{
}

GameObject::~GameObject()
{
}

void GameObject::Load(std::string name)
{
  if(texture.loadFromFile(name) == false)
  {
    filename = "";
    loaded = false;
  }
  else
  {
    filename = name;
    sprite.setTexture(texture);
    loaded = true;
  }
}

void GameObject::Draw(sf::RenderWindow &w)
{
    if (loaded)
    {
        w.draw(sprite);
    }
}

void GameObject::Update(float elapsedTime)
{
}

void GameObject::setPosition(float x, float y)
{
    if (loaded)
    {
        sprite.setPosition(x, y);
    }
}

sf::Vector2f GameObject::getPosition() const
{
    if (loaded)
    {
        return sprite.getPosition();
    }
    return sf::Vector2f();
}

sf::Sprite &GameObject::getSprite()
{
    return sprite;
}

bool GameObject::isLoaded() const
{
    return loaded;
}

float GameObject::getHeight() const
{
    return sprite.getLocalBounds().height;
}

float GameObject::getWidth() const
{
    return sprite.getLocalBounds().width;
}

sf::Rect<float> GameObject::getBoundingRect() const
{
    return sprite.getGlobalBounds();
}