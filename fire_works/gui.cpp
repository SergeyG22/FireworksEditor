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