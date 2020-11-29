#pragma once
#include <TGUI/TGUI.hpp>

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
	bool change_state = false;
public:
	Window_dialog();
	sf::Sprite& get_sprite_button_exit() { return sprite_button_exit; }
	sf::Sprite& get_sprite_button_accept() { return sprite_button_accept; }
	sf::Sprite& get_spite_button_cancel() { return sprite_button_cancel;  }
	void show_dialog_window(bool state) { change_state = state; };
	bool get_state_dialog_window() { return change_state; };
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class GraphicalDesktopElements:public sf::Drawable {
	sf::Sprite sprite_button_open;
	sf::Sprite sprite_button_close;
	sf::Sprite sprite_background;
	sf::Texture texture_button_open;
	sf::Texture texture_button_close;
	sf::Texture texture_background;
	bool change_state = false;
	bool open_window = true;
public:
    GraphicalDesktopElements();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite& get_sprite_button_open() { return sprite_button_open; }
	sf::Sprite& get_sprite_button_close() { return sprite_button_close; }
	bool get_state_window() { return open_window; }
	void set_state_window(bool state) { open_window = state; }
	void show_window_of_widgets(bool state) { change_state = state; }
};


struct Combo_box_color{
	tgui::ComboBox::Ptr combo_box_color;
	tgui::Layout width_combo_box_color = 280;
	tgui::Layout height_combo_box_color = 31;
	tgui::Layout pos_x_combo_box_color = 53;
	tgui::Layout pos_y_combo_box_color = 260;
	tgui::Theme theme{ "themes/Black.txt" };
	Combo_box_color(tgui::GuiSFML&);
};
