#include <SFML/Graphics.hpp>
#include <iostream>
#include "gui.h"

Background::Background() {
	if (!background_texture.loadFromFile("images/night_city.png")) { 
		std::cout << "error loading the texture";
	}
	background_sprite.setTexture(background_texture);
}

