#include <SFML/Graphics.hpp>
#include <iostream>
#include "gui.h"

Background::Background() {
	if (!background_texture.loadFromFile("images/night_city.png")) { 
		std::cout << "error loading the texture\n";
	}
	background_sprite.setTexture(background_texture);
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(background_sprite,states);
}

Display_text::Display_text() {
	if (!font.loadFromFile("fonts/Arial-BoldItalicMT.ttf")) {
		std::cout << "error loading the font\n";
	}
	fps_text.setFont(font);
	fractions_text.setFont(font);
	fireworks_text.setFont(font);
	fractions_text.setPosition(0,30);
	fireworks_text.setPosition(0,60);
	fps_text.setFillColor(sf::Color::Red);
	fractions_text.setFillColor(sf::Color::Red);
	fireworks_text.setFillColor(sf::Color::Red);
}

void Display_text::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(fps_text, states);
	target.draw(fractions_text, states);
	target.draw(fireworks_text, states);
 }

void Window_dialog::draw(sf::RenderTarget& target, sf::RenderStates states) const {	
	    target.draw(sprite_button_exit, states);		
	if (change_state) {
		target.draw(sprite_dialog_window, states);
	    target.draw(sprite_button_accept, states);
		target.draw(sprite_button_cancel, states);		
	}
}

Window_dialog::Window_dialog() {
	if (!texture_button_accept.loadFromFile("images/button_accept.png")) {
		std::cout << "error loading the image button_accept\n";
	}
	if (!texture_button_cancel.loadFromFile("images/button_cancel.png")) {
		std::cout << "error loading the image button_cancel\n";
	}
	if (!texture_button_exit.loadFromFile("images/button_exit.png")) {
		std::cout << "error loading the image button_exit\n";
	}	
	if (!texture_dialog_window.loadFromFile("images/window_dialog.png")) {
		std::cout << "error loading the image window_dialog\n";
	}
	sprite_button_accept.setTexture(texture_button_accept);
	sprite_button_cancel.setTexture(texture_button_cancel);
	sprite_button_exit.setTexture(texture_button_exit);	
	sprite_dialog_window.setTexture(texture_dialog_window);
	sprite_button_accept.setPosition(450,600);
	sprite_button_cancel.setPosition(650,600);
	sprite_button_exit.setPosition(30,920);	
	sprite_dialog_window.setPosition(430,460);
}

GraphicalDesktopElements::GraphicalDesktopElements() {
	if (!texture_button_open.loadFromFile("images/button_open.png")) {
		std::cout << "error loading the image button_open\n";
	}
	if (!texture_button_close.loadFromFile("images/button_close.png")) {
		std::cout << "error loading the image button_close\n";
	}
	if (!texture_background.loadFromFile("images/background.png")) {
		std::cout << "error loading the image button_open\n";
	}
	sprite_button_open.setTexture(texture_button_open);
	sprite_button_open.setPosition(32, 844);
	sprite_button_close.setTexture(texture_button_close);
	sprite_button_close.setPosition(32, 844);
	sprite_background.setTexture(texture_background);
	sprite_background.setPosition(32, 216);
}

void GraphicalDesktopElements::draw(sf::RenderTarget& target, sf::RenderStates states) const {	
	if (open_window) {
		target.draw(sprite_button_open, states);
	}
	else {
		target.draw(sprite_button_close, states);
	}
	if (change_state) {
		target.draw(sprite_background, states);
	}
}


Combo_box_color::Combo_box_color(tgui::GuiSFML&GUI) {
	combo_box_color = tgui::ComboBox::create();
	combo_box_color->setRenderer(theme.getRenderer("ComboBox"));
	combo_box_color->setTextSize(20);
	combo_box_color->setSize(width_combo_box_color, height_combo_box_color);
	combo_box_color->setPosition(pos_x_combo_box_color, pos_y_combo_box_color);
	combo_box_color->setVisible(false);
	combo_box_color->addItem(L"�������","1");
	combo_box_color->addItem(L"�������", "2");
	combo_box_color->addItem(L"���������", "3");
	combo_box_color->addItem(L"���������", "4");
	combo_box_color->addItem(L"������", "5");
	combo_box_color->addItem(L"�����", "6");
	combo_box_color->addItem(L"���������","7");
	combo_box_color->setSelectedItem(L"���������");
	GUI.add(combo_box_color);
}

Combo_box_number_of_fireworks::Combo_box_number_of_fireworks(tgui::GuiSFML& GUI) {
	combo_box_number_of_fireworks = tgui::ComboBox::create();
	combo_box_number_of_fireworks->setRenderer(theme.getRenderer("ComboBox"));
	combo_box_number_of_fireworks->setTextSize(20);
	combo_box_number_of_fireworks->setSize(width_combo_box_number_of_fireworks, height_combo_box_number_of_fireworks);
	combo_box_number_of_fireworks->setPosition(pos_x_combo_box_number_of_fireworks, pos_y_combo_box_number_of_fireworks);
	combo_box_number_of_fireworks->setVisible(false);
	combo_box_number_of_fireworks->addItem(L"���� ��������", "1");
	combo_box_number_of_fireworks->addItem(L"��� ���������", "2");
	combo_box_number_of_fireworks->addItem(L"��� ���������", "3");
	combo_box_number_of_fireworks->addItem(L"������ ���������", "4");
	combo_box_number_of_fireworks->addItem(L"���� ����������", "5");
	combo_box_number_of_fireworks->setSelectedItem(L"���� ��������");
	GUI.add(combo_box_number_of_fireworks);
}

Slider_number_of_lights::Slider_number_of_lights(tgui::GuiSFML& GUI) {
	slider_number_of_lights = tgui::Slider::create();
	slider_number_of_lights->setRenderer(theme.getRenderer("Slider"));
	slider_number_of_lights->setVisible(false);
	slider_number_of_lights->setSize(width_number_of_lights, height_number_of_lights);
	slider_number_of_lights->setPosition(pos_x_number_of_lights, pos_y_number_of_lights);
	slider_number_of_lights->setMinimum(1);
	slider_number_of_lights->setMaximum(20);
	slider_number_of_lights->setStep(1);
	GUI.add(slider_number_of_lights);
}

Slider_number_of_particles::Slider_number_of_particles(tgui::GuiSFML& GUI) {
	slider_number_of_particles = tgui::Slider::create();
	slider_number_of_particles->setRenderer(theme.getRenderer("Slider"));
	slider_number_of_particles->setVisible(false);
	slider_number_of_particles->setSize(width_number_of_particles, height_number_of_particles);
	slider_number_of_particles->setPosition(pos_x_number_of_particles, pos_y_number_of_particles);
	slider_number_of_particles->setMinimum(1);
	slider_number_of_particles->setMaximum(20);
	slider_number_of_particles->setStep(1);
	GUI.add(slider_number_of_particles);
}