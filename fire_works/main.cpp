#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "fireworks.h"
#include "gui.h"


extern double number_generator(int, int);
const int time_scene = 20;
int fps = 0;
sf::Color color[] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Cyan, 
                      sf::Color::Yellow,sf::Color::Blue,sf::Color::White};


void get_fps(sf::Clock& clock) {
    sf::Time time = clock.getElapsedTime();
    fps = 1.0f / time.asSeconds();
    clock.restart().asSeconds();
}




int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 1024), "Fireworks");    
    std::list<Flow_fractions*>fireworks;
    std::list<Fractions*>fractions;
    std::list<Explosion*>explosions;
    sf::CircleShape circle_shape;
    circle_shape.setRadius(3.0);
    sf::Clock event_timer;
    sf::Clock timer_starts_firework;
    sf::Clock clock_fps;

    fireworks.push_back(new Flow_fractions(&fractions));
    Background background;
    Display_text display_text;
    Window_dialog window_dialog;

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

        get_fps(clock_fps);
       
        window.clear(sf::Color(0, 0, 0));
        window.draw(background);

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
                    int number_of_lights = static_cast<int>(number_generator(10,40));
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

            sf::Color current_color = color[static_cast<int>(number_generator(1,8))];
            for (int i = 1; i < static_cast<int>(number_generator(1, 10)); i++) {
                for (const auto& it : explosions) {
                    circle_shape.setFillColor(current_color);
                    sf::Vector2f pos;
                    pos.x = it->get_position().x + static_cast<int>(number_generator(1, 150));
                    pos.y = it->get_position().y + static_cast<int>(number_generator(1, 150));
                    circle_shape.setPosition(pos);                   
                    window.draw(circle_shape);
                }
            }
            
            event_timer.restart();
        }  
        window.draw(display_text);
        window.draw(window_dialog);
        display_text.set_fractions_text(std::to_string(fractions.size()));
        display_text.set_fireworks_text(std::to_string(fireworks.size()));
        display_text.set_fps_text(std::to_string(fps));
        window.display();

    }
    return 0;
}














