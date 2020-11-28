#pragma once

class Background: public sf::Drawable {
	sf::Sprite background_sprite;
	sf::Texture background_texture;
public:
	Background();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class Display_text: public sf::Drawable {
	sf::Font font;
	sf::Text fps_text;
	sf::Text fractions_text;
	sf::Text fireworks_text;
public:
    Display_text();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void set_fps_text(std::string str_fps) { fps_text.setString("FPS = "+str_fps); }
	void set_fractions_text(std::string str_fractions) { fractions_text.setString("Parcticle = "+str_fractions); }
	void set_fireworks_text(std::string str_fireworks) { fireworks_text.setString("Fireworks = "+str_fireworks); }
};

class Window_dialog:public sf::Drawable {
	sf::Sprite sprite_button_accept;
	sf::Sprite sprite_button_cancel;
	sf::Sprite sprite_button_exit;
	sf::Sprite sprite_dialog_window;
	sf::Texture texture_button_accept;
	sf::Texture texture_button_cancel;
	sf::Texture texture_button_exit;
	sf::Texture texture_dialog_window;
public:
	Window_dialog();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};