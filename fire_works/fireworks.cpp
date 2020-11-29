#include <SFML/Graphics.hpp>
#include <random>
#include <list>
#include <iostream>
#include "fireworks.h"
#include "number_generator.h"

extern double number_generator(int,int);
const int width_window = 1024;

Fractions::Fractions(sf::Vector2f position, sf::Color color) {
    fractions_position = position;
    fractions_color = color;
    fractions_alpha = color.a / number_generator(5,20);
};


bool Fractions::generate_fractions() {
    if (fractions_position.y >= width_window || fractions_color.a - fractions_alpha <= 0) {
        return false;
    }
    fractions_position = fractions_position + sf::Vector2f(number_generator(-2,3), number_generator(0, 2));
    fractions_color.a = fractions_color.a - fractions_alpha;
    if (fractions_color.a > 200) {
        fractions_color.a = 200;
    }
    return true;
};


Flow_fractions::Flow_fractions(std::list<Fractions*>* fractions,sf::RenderWindow& window) {
    flow_fractions_color = sf::Color(number_generator(0,256), number_generator(0, 256), number_generator(0, 256));
    sf::Vector2f mouse_position;
    mouse_position.x = sf::Mouse::getPosition(window).x;
    mouse_position.y = sf::Mouse::getPosition(window).y;
     
    if ((mouse_position.y < 1180 && mouse_position.x > 250)|| (mouse_position.x<250 && mouse_position.y<840 )) {  //range to avoid starting fireworks when you click open close
        flow_fractions_positions = mouse_position;
        flow_fractions_velocity = sf::Vector2f(number_generator(1, 5), number_generator(3, 8) * (-1));
        if (flow_fractions_positions.x >= 400)
            flow_fractions_velocity.x = flow_fractions_velocity.x * (-1);
        tact = 0;
        list_fractions = fractions;
    }
};

Flow_fractions::Flow_fractions(std::list<Fractions*>* fractions) {
    flow_fractions_color = sf::Color(number_generator(0, 256), number_generator(0, 256), number_generator(0, 256));
    sf::Vector2f start_position;
    start_position.x = static_cast<int>(number_generator(100,1180));
    start_position.y = 924;
    flow_fractions_positions = start_position;
    flow_fractions_velocity = sf::Vector2f(number_generator(1, 5), number_generator(3, 8) * (-1));
    if (flow_fractions_positions.x >= 100)
        flow_fractions_velocity.x = flow_fractions_velocity.x * (-1);
    tact = 0;
    list_fractions = fractions;
    return;
};



bool Flow_fractions::generate_flow() {
    flow_fractions_positions = flow_fractions_positions + flow_fractions_velocity;
    int number_fractions = 25;
    for (int y = 0; y < flow_fractions_velocity.y * (-1); ++y)
        for ( int i = 0; i < number_fractions; ++i)
            list_fractions->push_back(new Fractions(sf::Vector2f(get_position().x, get_position().y + y), get_color()));
    if (tact >= 50) {
        return false;
    }
    tact++;
    return true;
};

Explosion::Explosion(sf::Vector2f position, sf::Color color,int dislocation ) {
    explosion_position = position;
    explosion_position.x += dislocation;
    explosion_position.y += dislocation;
    if (static_cast<int>(number_generator(0, 2))) {
        explosion_velocity.x = number_generator(0, 20);
    }
    else {
        explosion_velocity.x = (number_generator(0, 20)) * (-1);
    }
    if (static_cast<int>(number_generator(0, 2))) {
        explosion_velocity.y = number_generator(0, 20);
    }
    else {
        explosion_velocity.y = (number_generator(0, 20)) * (-1);
    }
    explosion_color = color;
    explosion_alpha = explosion_color.a / (number_generator(5, 50));
    tact = 0;
};

bool Explosion::generate_explosion()
{
    if (explosion_color.a - explosion_alpha <= 0 || tact >= 50) {
        return false;
    }
    explosion_position = explosion_position + explosion_velocity;
    explosion_color.a = explosion_color.a - explosion_alpha;
    if (explosion_color.a > 300) {
        explosion_color.a = 300;
    }
    tact++;
    return true;
};

Fireball::Fireball() {
    fireball_shape.setRadius(3.0);
}
