#ifndef _GAMEOBJECT_H__
#define _GAMEOBJECT_H__

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    virtual void Load(std::string);
    //virtual void Load(std::string, std::string);
    virtual void Draw(sf::RenderWindow &);
    //virtual void switchPrimarySprite();
    virtual void Update(float);

    virtual void setPosition(float x, float y);
    virtual bool isLoaded() const; //primary image
    virtual float getWidth() const;
    virtual float getHeight() const;
    virtual sf::Vector2f getPosition() const;
    virtual sf::Rect<float> getBoundingRect() const;
    enum objDir { Left, Right }; //direction object is facing

protected:
    sf::Sprite &getSprite();
    objDir direction;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string filename;
    bool loaded;
};

#endif