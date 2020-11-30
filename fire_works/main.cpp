#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <list>
#include <iostream>
#include "fireworks.h"
#include "gui.h"


extern double number_generator(int, int);
int fps = 0;
int color_id = 6;
int number_of_fireworks = 0;
int number_of_particles = 5;
int number_of_lights = 20;
int time_scene = 20;
int timer_start = 10;
sf::Color color[] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Cyan, 
                      sf::Color::Yellow, sf::Color::White};


void get_fps(sf::Clock& clock) {
    sf::Time time = clock.getElapsedTime();
    fps = 1.0f / time.asSeconds();
    clock.restart().asSeconds();
}

sf::Vector2f get_mouse_coordinate(sf::RenderWindow& window) {
    sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_coord = window.mapPixelToCoords(pixel_pos);
    return mouse_coord;
}

struct ObjectsEntities {
    sf::RenderWindow window{ sf::VideoMode(1280, 1024), "Fireworks" };
    tgui::GuiSFML GUI{ window };
    Background background;
    Display_text display_text;
    Window_dialog window_dialog;
    Fireball fireball;
    GraphicalDesktopElements graphical_elements;
    Combo_box_color combo_box_color{ GUI };
    Combo_box_number_of_fireworks combo_box_number_of_fireworks{ GUI };
    Slider_number_of_lights slider_number_of_lights { GUI };
    Slider_number_of_particles slider_number_of_particles{ GUI };
    Slider_start_of_fireworks slider_start_of_fireworks{ GUI };
    Label_number_of_lights label_number_of_light{ GUI };
    Label_number_of_particles label_number_of_particles{ GUI };
    Label_number_of_seconds label_number_of_seconds{ GUI };
    Button_reset_scene button_reset_scene{ GUI };
    Button_hide_info button_hide_info{ GUI };
    std::list<Flow_fractions*>fireworks;
    std::list<Fractions*>fractions;
    std::list<Explosion*>explosions;
};


void visibility_of_widgets(ObjectsEntities& widget, bool state) {
    widget.button_hide_info.button_hide_info->setVisible(state);
    widget.button_reset_scene.button_reset_scene->setVisible(state);
    widget.combo_box_color.combo_box_color->setVisible(state);
    widget.combo_box_number_of_fireworks.combo_box_number_of_fireworks->setVisible(state);
    widget.slider_number_of_lights.slider_number_of_lights->setVisible(state);
    widget.slider_number_of_particles.slider_number_of_particles->setVisible(state);
    widget.slider_start_of_fireworks.slider_start_of_fireworks->setVisible(state);
    widget.label_number_of_light.label_number_of_lights->setVisible(state);
    widget.label_number_of_particles.label_number_of_particles->setVisible(state);
    widget.label_number_of_seconds.label_number_of_second->setVisible(state);
    widget.graphical_elements.show_window_of_widgets(state);
}

void get_color_id(ObjectsEntities& widgets) {
    color_id = widgets.combo_box_color.combo_box_color->getSelectedItemIndex();
}

void get_number_of_fireworks(ObjectsEntities& widgets) {
    number_of_fireworks = widgets.combo_box_number_of_fireworks.combo_box_number_of_fireworks->getSelectedItemIndex();
}

void set_number_of_particles(ObjectsEntities& widgets) {
    number_of_particles = widgets.slider_number_of_particles.slider_number_of_particles->getValue();
    tgui::String str_particles(number_of_particles);
    widgets.label_number_of_particles.label_number_of_particles->setText(str_particles);
}

void set_number_of_lights(ObjectsEntities& widgets) {
    number_of_lights = widgets.slider_number_of_lights.slider_number_of_lights->getValue();
    tgui::String str_lights(number_of_lights);
    widgets.label_number_of_light.label_number_of_lights->setText(str_lights);
}

void set_start_interval(ObjectsEntities& widgets) {
    timer_start = widgets.slider_start_of_fireworks.slider_start_of_fireworks->getValue();
    tgui::String str_time(timer_start);
    widgets.label_number_of_seconds.label_number_of_second->setText(str_time);
}

void reset_scene(ObjectsEntities& widgets) {
    widgets.fireworks.clear();
    widgets.fractions.clear();
    widgets.explosions.clear();
}

void hide_info(ObjectsEntities& widgets) {
    if (widgets.display_text.current_state) {
        widgets.display_text.show_text(false);
        widgets.display_text.current_state = false;
        widgets.button_hide_info.button_hide_info->setText(L"Показать надписи");
    }
    else {
        widgets.display_text.show_text(true);
        widgets.display_text.current_state = true;
        widgets.button_hide_info.button_hide_info->setText(L"Скрыть надписи");
    }
}


void events_called_by_widgets(ObjectsEntities& widgets) {
    widgets.combo_box_color.combo_box_color->onItemSelect(get_color_id,std::ref(widgets));
    widgets.combo_box_number_of_fireworks.combo_box_number_of_fireworks->onItemSelect(get_number_of_fireworks,std::ref(widgets));
    widgets.slider_number_of_particles.slider_number_of_particles->onValueChange(set_number_of_particles,std::ref(widgets));
    widgets.slider_number_of_lights.slider_number_of_lights->onValueChange(set_number_of_lights,std::ref(widgets));
    widgets.slider_start_of_fireworks.slider_start_of_fireworks->onValueChange(set_start_interval,std::ref(widgets));
    widgets.button_reset_scene.button_reset_scene->onClick(reset_scene, std::ref(widgets));
    widgets.button_hide_info.button_hide_info->onClick(hide_info,std::ref(widgets));
}





int main()
{
    ObjectsEntities objects_entities;   
    sf::Clock event_timer;
    sf::Clock timer_starts_firework;
    sf::Clock clock_fps;
    objects_entities.fireworks.push_back(new Flow_fractions(&objects_entities.fractions,color_id,number_of_particles));
    events_called_by_widgets(objects_entities);

    while (objects_entities.window.isOpen())
    {
        sf::Event event;
        while (objects_entities.window.pollEvent(event))
        {
            objects_entities.GUI.handleEvent(event);
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {                        
                    objects_entities.fireworks.push_back(new Flow_fractions(&objects_entities.fractions, objects_entities.window,color_id,number_of_particles));
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {                   
                    if (objects_entities.window_dialog.get_sprite_button_exit().getGlobalBounds().contains(get_mouse_coordinate(objects_entities.window).x, get_mouse_coordinate(objects_entities.window).y)) {
                        objects_entities.window_dialog.show_dialog_window(true);
                    }
                }
            }

            if (objects_entities.window_dialog.get_state_dialog_window())  // when the sprite is hidden, the interaction boundary remains.Clicking on an empty space button will trigger an event. This condition compensates for the disadvantage.
            {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.key.code == sf::Mouse::Left) {
                        if (objects_entities.window_dialog.get_sprite_button_accept().getGlobalBounds().contains(get_mouse_coordinate(objects_entities.window).x, get_mouse_coordinate(objects_entities.window).y)) {
                            objects_entities.window.close();
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    if (objects_entities.window_dialog.get_spite_button_cancel().getGlobalBounds().contains(get_mouse_coordinate(objects_entities.window).x, get_mouse_coordinate(objects_entities.window).y)) {
                        objects_entities.window_dialog.show_dialog_window(false);
                    }
                }
            }

            if (objects_entities.graphical_elements.get_state_window())
            {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.key.code == sf::Mouse::Left) {
                        if (objects_entities.graphical_elements.get_sprite_button_open().getGlobalBounds().contains(get_mouse_coordinate(objects_entities.window).x, get_mouse_coordinate(objects_entities.window).y)) {
                            visibility_of_widgets(objects_entities, true);
                            objects_entities.graphical_elements.set_state_window(false);
                        }
                    }
                }
            }
            else {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.key.code == sf::Mouse::Left) {
                        if (objects_entities.graphical_elements.get_sprite_button_close().getGlobalBounds().contains(get_mouse_coordinate(objects_entities.window).x, get_mouse_coordinate(objects_entities.window).y)) {
                            visibility_of_widgets(objects_entities, false);
                            objects_entities.graphical_elements.set_state_window(true);
                        }
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    visibility_of_widgets(objects_entities, false);
                    objects_entities.graphical_elements.set_state_window(true);
                }
            }
          
            if (event.type == sf::Event::Closed) {
                objects_entities.window.close();
            }

        }

        get_fps(clock_fps);      
        objects_entities.window.clear(sf::Color(0, 0, 0));
        objects_entities.window.draw(objects_entities.background);

        for (const auto &it: objects_entities.fractions) {
              objects_entities.fireball.fireball_shape.setFillColor(it->get_color());
              objects_entities.fireball.fireball_shape.setPosition(it->get_position());
              objects_entities.window.draw(objects_entities.fireball.fireball_shape);
        }

        for (const auto&it : objects_entities.explosions) {
              objects_entities.fireball.fireball_shape.setFillColor(it->get_color());
              objects_entities.fireball.fireball_shape.setPosition(it->get_position());
              objects_entities.window.draw(objects_entities.fireball.fireball_shape);
        }

        if (timer_start != 0)
        {
            if (timer_starts_firework.getElapsedTime().asSeconds() > timer_start) {
                for (int i = 0; i < number_of_fireworks + 1; ++i) {
                    objects_entities.fireworks.push_back(new Flow_fractions(&objects_entities.fractions, color_id, number_of_particles));
                }
                timer_starts_firework.restart();
            }
        }
        

        if (event_timer.getElapsedTime().asMilliseconds() >= time_scene)
        {
            for (auto it = objects_entities.fractions.begin(); it != objects_entities.fractions.end();) {
                if (!(*it)->generate_fractions()) {
                    delete *it;
                    it = objects_entities.fractions.erase(it);
                }
                else {
                    ++it;
                }
            }

            for (auto it = objects_entities.fireworks.begin(); it != objects_entities.fireworks.end();) {
                if (!(*it)->generate_flow()) {                  
                    for (int i = 0; i < number_of_lights; i++)
                        objects_entities.explosions.push_back(new Explosion((*it)->get_position(), (*it)->get_color(),0));
                    delete* it;
                    it = objects_entities.fireworks.erase(it);
                }
                else {
                    ++it;
                }
            }
           
            
            for (auto it = objects_entities.explosions.begin(); it != objects_entities.explosions.end();) {
                if (!(*it)->generate_explosion()) {
                    objects_entities.fractions.push_back(new Fractions((*it)->get_position(), (*it)->get_color()));
                    delete* it;
                    it = objects_entities.explosions.erase(it);
                }
                else {
                    ++it;
                }
            }  
            

            sf::Color current_color = color[static_cast<int>(number_generator(1,7))];
            for (int i = 1; i < static_cast<int>(number_generator(1, 10)); i++) {
                for (const auto& it : objects_entities.explosions) {
                    objects_entities.fireball.fireball_shape.setFillColor(current_color);
                    sf::Vector2f pos;
                    pos.x = it->get_position().x + static_cast<int>(number_generator(1, 150));
                    pos.y = it->get_position().y + static_cast<int>(number_generator(1, 150));
                    objects_entities.fireball.fireball_shape.setPosition(pos);
                    objects_entities.window.draw(objects_entities.fireball.fireball_shape);
                }
            }
            
            event_timer.restart();
        }
       
        objects_entities.window.draw(objects_entities.graphical_elements);
        objects_entities.GUI.draw();
        objects_entities.window.draw(objects_entities.display_text);
        objects_entities.window.draw(objects_entities.window_dialog);
        objects_entities.display_text.set_fractions_text(std::to_string(objects_entities.fractions.size()));
        objects_entities.display_text.set_fireworks_text(std::to_string(objects_entities.fireworks.size()));
        objects_entities.display_text.set_fps_text(std::to_string(fps));
        objects_entities.window.display();
    }
    return 0;
}














