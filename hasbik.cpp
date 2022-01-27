#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Player {
private:
    int x, y;
public:
    float currentFrame;
    int w, h;
    String File;
    Texture herotexture;
    Sprite herosprite;
    Player(String F, float X, float Y, int W, int H) {
        File = F;
        w = W; h = H;
        x = X; y = Y;

        herotexture.loadFromFile(File);
        herosprite.setTexture(herotexture);
        herosprite.setTextureRect(IntRect(0, 0, W, H));
        herosprite.setPosition(x, y);
        currentFrame = 0;
    }

    void control(float time) {
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            herosprite.setTextureRect(IntRect(38 * int(currentFrame) + 38, 0, -38, 68));


            x -= 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            herosprite.setTextureRect(IntRect(38 * int(currentFrame), 0, 38, 68));

            x += 1;
        }

    }

    void update(float time) {
        control(time);
        herosprite.setPosition(x, y);
        std::cout << "x=" << x << " , y=" << y << std::endl;
    }

};


int main()
{
    RenderWindow window(sf::VideoMode(1176, 588), "");

    Image i;
    i.loadFromFile("background.jpg");
    Texture t;
    t.loadFromImage(i);
    Sprite sBack;
    sBack.setTexture(t);

    Clock clock;

    Player hasbik("hasbik2.png", 300, 450, 68, 38);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        hasbik.update(time);

        window.clear();
        window.draw(sBack);
        window.draw(hasbik.herosprite);
        window.display();

    }

    return 0;
}