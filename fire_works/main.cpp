#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "fireworks.h"
#include "gui.h"



const int time_scene = 50;
sf::Color color[] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Cyan, 
                      sf::Color::Yellow,sf::Color::Blue,sf::Color::White};




int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 1024), "Fireworks");    
    std::vector<Flow_fractions*>fireworks;
    std::list<Fractions*>fractions;
    std::vector<Explosion*>explosions;
    sf::CircleShape circle_shape;
    circle_shape.setRadius(3.0);

    sf::Clock event_timer;
    sf::Clock timer_starts_firework;
    fireworks.push_back(new Flow_fractions(&fractions));
    Background background;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {                   
                    fireworks.push_back(new Flow_fractions(&fractions, window));
                }
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        
        window.clear(sf::Color(0, 0, 0));

         window.draw(background.get_sprite());
        for (const auto &it: fractions) {     
              circle_shape.setFillColor(it->get_color());
              circle_shape.setPosition(it->get_position());
              window.draw(circle_shape);
        }

        for (const auto&it :explosions) {
              circle_shape.setFillColor(it->get_color());
              circle_shape.setPosition(it->get_position());
              window.draw(circle_shape);

        }


        if (timer_starts_firework.getElapsedTime().asSeconds() > 10) {
            fireworks.push_back(new Flow_fractions(&fractions));
            timer_starts_firework.restart();
        }




        if (event_timer.getElapsedTime().asMilliseconds() >= time_scene)
        {
            for (auto it = fractions.begin(); it != fractions.end();) {
                if (!(*it)->generate_fractions()) {
                    delete *it;
                    it = fractions.erase(it);
                }
                else {
                    ++it;
                }
            }

            for (auto it = fireworks.begin(); it != fireworks.end();) {
                if (!(*it)->generate_flow()) {
                    int number_of_lights = rand()%10+40;
                    for (int i = 0; i < number_of_lights; i++)
                        explosions.push_back(new Explosion((*it)->get_position(), (*it)->get_color(),0));
                    delete* it;
                    it = fireworks.erase(it);
                }
                else {
                    ++it;
                }
            }
           
            for (auto it = explosions.begin(); it != explosions.end();) {
                if (!(*it)->generate_explosion()) {
                    fractions.push_back(new Fractions((*it)->get_position(), (*it)->get_color()));
                    delete* it;
                    it = explosions.erase(it);
                }
                else {
                    ++it;
                }
            }     

            sf::Color current_color = color[rand() % 8];
            for (int i = 1; i < rand()%10; i++)
            {
                for (const auto& it : explosions) {
                    circle_shape.setFillColor(current_color);
                    sf::Vector2f pos;
                    pos.x = it->get_position().x + rand() % 250;
                    pos.y = it->get_position().y + rand() % 250;
                    circle_shape.setPosition(pos);                   
                    window.draw(circle_shape);
                }
            }
            
            event_timer.restart();
        }
        
        
        window.display();
    }
    return 0;
}














