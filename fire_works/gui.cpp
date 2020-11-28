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
	target.draw(sprite_dialog_window, states);
	target.draw(sprite_button_accept, states);
	target.draw(sprite_button_cancel, states);
	target.draw(sprite_button_exit, states);
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