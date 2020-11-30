#pragma once
#include "gui.h"

extern double number_generator(int, int);

class Fractions {
    sf::Color fractions_color;
    sf::Vector2f fractions_position;
    float fractions_alpha;
public:
    Fractions(sf::Vector2f, sf::Color);
    sf::Color get_color()          const { return fractions_color; };
    sf::Vector2f get_position()    const { return fractions_position;  };
    bool generate_fractions();
};

class Flow_fractions {
    int tact;
    sf::Color flow_fractions_color;
    sf::Vector2f flow_fractions_velocity;
    sf::Vector2f flow_fractions_positions;   
    std::list<Fractions*>*list_fractions;
    int number_fractions = 5;
public:
    Flow_fractions(std::list<Fractions*>*,sf::RenderWindow&,int,int);
    Flow_fractions(std::list<Fractions*>*,int,int);
    sf::Color get_color()       const { return flow_fractions_color; };
    sf::Vector2f get_position() const { return flow_fractions_positions; };
    bool generate_flow();
};

class Explosion {
    int tact;
    float explosion_alpha;
    sf::Color explosion_color;
    sf::Vector2f explosion_position;
    sf::Vector2f explosion_velocity;   
public:
    Explosion(sf::Vector2f, sf::Color,int);
    sf::Color get_color()       const { return explosion_color;     };
    sf::Vector2f get_position() const { return explosion_position;  };
    bool generate_explosion();
};

class SoundExplosion {
    sf::SoundBuffer sound_buffer_v1;
    sf::SoundBuffer sound_buffer_v2;
    sf::SoundBuffer sound_buffer_v3;
    sf::SoundBuffer sound_buffer_v4;
    sf::Sound sound_explosion_v1;
    sf::Sound sound_explosion_v2;
    sf::Sound sound_explosion_v3;
    sf::Sound sound_explosion_v4;
public:
    SoundExplosion();
    void sound_play() {       
        switch (static_cast<int>(number_generator(1, 5))) {
        case 1: { sound_explosion_v1.play();
              break;
        }
        case 2: { sound_explosion_v2.play();
            break;
        }
        case 3: { sound_explosion_v3.play();
            break;
        }
        case 4: { sound_explosion_v4.play();
            break;
        }        
      }
    }
};

struct Fireball {
    sf::CircleShape fireball_shape;
    Fireball();
};

