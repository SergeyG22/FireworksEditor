#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <list>
#include <iostream>
#include "../../include/fireworks.h"
#include "../../include/number_generator.h"
#include "../../include/gui.h"

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


Flow_fractions::Flow_fractions(std::list<Fractions*>* fractions,sf::RenderWindow& window ,int color_id, int fract) {
    number_fractions = fract;
    switch (color_id) {
    case 0: {
        flow_fractions_color = sf::Color(255, 0, 0);
        break;
    }
    case 1: {
         flow_fractions_color = sf::Color(0,255,0);
         break;
    }
    case 2: {
        flow_fractions_color = sf::Color(128, 0, 128);
        break;
    }
    case 3: {
        flow_fractions_color = sf::Color(48, 213, 200);
        break;
    }
    case 4: {
        flow_fractions_color = sf::Color(255, 255, 0);
        break;
    }
    case 5: {
        flow_fractions_color = sf::Color(255, 250, 250);
        break;
    }
    case 6: {
        flow_fractions_color = sf::Color(number_generator(0, 256), number_generator(0, 256), number_generator(0, 256));
        break;
    }
    }
    sf::Vector2f mouse_position;
    mouse_position.x = sf::Mouse::getPosition(window).x;
    mouse_position.y = sf::Mouse::getPosition(window).y;    
    flow_fractions_positions = mouse_position;
    flow_fractions_velocity = sf::Vector2f(number_generator(1, 5), number_generator(3, 8) * (-1));
    if (flow_fractions_positions.x >= 400)
                flow_fractions_velocity.x = flow_fractions_velocity.x * (-1);
    tact = 0;
    list_fractions = fractions;
       
};

Flow_fractions::Flow_fractions(std::list<Fractions*>* fractions,int color_id,int fract) {
    number_fractions = fract;
    switch (color_id) {
    case 0: {
        flow_fractions_color = sf::Color(255, 0, 0);
        break;
    }
    case 1: {
        flow_fractions_color = sf::Color(0, 255, 0);
        break;
    }
    case 2: {
        flow_fractions_color = sf::Color(128, 0, 128);
        break;
    }
    case 3: {
        flow_fractions_color = sf::Color(48, 213, 200);
        break;
    }
    case 4: {
        flow_fractions_color = sf::Color(255, 255, 0);
        break;
    }
    case 5: {
        flow_fractions_color = sf::Color(255, 250, 250);
        break;
    }
    case 6: {
        flow_fractions_color = sf::Color(number_generator(0, 256), number_generator(0, 256), number_generator(0, 256));
        break;
    }
    }
    sf::Vector2f start_position;
    start_position.x = static_cast<int>(number_generator(100,1180));
    start_position.y = 924;
    flow_fractions_positions = start_position;
    flow_fractions_velocity = sf::Vector2f(number_generator(1, 10), number_generator(3, 10) * (-1));
    if (flow_fractions_positions.x >= 100)
        flow_fractions_velocity.x = flow_fractions_velocity.x * (-1);
    tact = 0;
    list_fractions = fractions;
    return;
};



bool Flow_fractions::generate_flow() {
    flow_fractions_positions = flow_fractions_positions + flow_fractions_velocity;
    for (int y = 0; y < flow_fractions_velocity.y * (-1); ++y) {
        for (int i = 0; i < number_fractions; ++i)
            list_fractions->push_back(new Fractions(sf::Vector2f(get_position().x, get_position().y + y), get_color()));
    }
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

SoundExplosion::SoundExplosion() {
     if (!sound_buffer_v1.loadFromFile("sounds/explosion_v1.ogg")) { std::cout << "error loading the explosion_v1\n"; }
     if (!sound_buffer_v2.loadFromFile("sounds/explosion_v2.ogg")) { std::cout << "error loading the explosion_v2\n"; }
     if (!sound_buffer_v3.loadFromFile("sounds/explosion_v3.ogg")) { std::cout << "error loading the explosion_v3\n"; }
     if (!sound_buffer_v4.loadFromFile("sounds/explosion_v4.ogg")) { std::cout << "error loading the explosion_v4\n"; }
     sound_explosion_v1.setBuffer(sound_buffer_v1);
     sound_explosion_v2.setBuffer(sound_buffer_v2);
     sound_explosion_v3.setBuffer(sound_buffer_v3);
     sound_explosion_v4.setBuffer(sound_buffer_v4);
}



Fireball::Fireball() {
    fireball_shape.setRadius(3.0);
}
