#pragma once

class Background {
	sf::Sprite background_sprite;
	sf::Texture background_texture;
public:
	Background();
	sf::Sprite& get_sprite() { return background_sprite; }
};
