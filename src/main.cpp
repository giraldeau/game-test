#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;



struct weapon {
  int id;
};

struct physics{};
struct platform{};
struct entity{};

struct player{
  public:
    int Hp;
    physics Physics;
    float x;
    float y;
    weapon currentWeapon;
};

struct state{
  public:
    vector<player> Players;
    vector<entity> Entities;
    vector<platform> Platforms;
    vector<physics> Physics;
};

int draw(state);

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stick Duels");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        window.display();
    }

    return 0;
}

int draw(state st) {
  return 0;
}
