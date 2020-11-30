#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/TextStyle.hpp>

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
	bool change_state = true;	
public:
	bool current_state = true;
    Display_text();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void set_fps_text(std::string str_fps) { fps_text.setString("FPS = "+str_fps); }
	void show_text(bool state) { change_state = state; }
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

struct Combo_box_number_of_fireworks{
	tgui::ComboBox::Ptr combo_box_number_of_fireworks;
	tgui::Layout width_combo_box_number_of_fireworks = 280;
	tgui::Layout height_combo_box_number_of_fireworks = 31;
	tgui::Layout pos_x_combo_box_number_of_fireworks = 53;
	tgui::Layout pos_y_combo_box_number_of_fireworks = 310;
	tgui::Theme theme{ "themes/Black.txt" };
	Combo_box_number_of_fireworks(tgui::GuiSFML&);
};

struct Slider_number_of_lights {
	tgui::Slider::Ptr slider_number_of_lights;
	tgui::Layout width_number_of_lights = 230;
	tgui::Layout height_number_of_lights = 15;
	tgui::Layout pos_x_number_of_lights = 105;
	tgui::Layout pos_y_number_of_lights = 375;
	tgui::Theme theme{ "themes/Black.txt" };
	Slider_number_of_lights(tgui::GuiSFML&);
};

struct Slider_number_of_particles {
	tgui::Slider::Ptr slider_number_of_particles;
	tgui::Layout width_number_of_particles = 230;
	tgui::Layout height_number_of_particles = 15;
	tgui::Layout pos_x_number_of_particles = 105;
	tgui::Layout pos_y_number_of_particles = 425;
	tgui::Theme theme{ "themes/Black.txt" };
	Slider_number_of_particles(tgui::GuiSFML&);
};

struct Slider_start_of_fireworks {
	tgui::Slider::Ptr slider_start_of_fireworks;
	tgui::Layout width_start_of_fireworks = 230;
	tgui::Layout height_start_of_fireworks = 15;
	tgui::Layout pos_x_start_of_fireworks = 105;
	tgui::Layout pos_y_start_of_fireworks = 475;
	tgui::Theme theme{ "themes/Black.txt" };
	Slider_start_of_fireworks(tgui::GuiSFML&);
};



struct Label_number_of_lights {
	tgui::Label::Ptr label_number_of_lights;
	tgui::Layout width_label_number_of_lights = 310;
	tgui::Layout height_label_number_of_lights = 150;
	tgui::Layout pos_x_label_number_of_lights = 290;
	tgui::Layout pos_y_label_number_of_lights = 512;
	tgui::Theme theme{ "themes/Black.txt" };
	Label_number_of_lights(tgui::GuiSFML&);
};

struct Label_number_of_particles {
	tgui::Label::Ptr label_number_of_particles;
	tgui::Layout width_label_number_of_particles = 310;
	tgui::Layout height_label_number_of_particles = 150;
	tgui::Layout pos_x_label_number_of_particles = 290;
	tgui::Layout pos_y_label_number_of_particles = 542;
	tgui::Theme theme{ "themes/Black.txt" };
	Label_number_of_particles(tgui::GuiSFML&);
};

struct Label_number_of_seconds {
	tgui::Label::Ptr label_number_of_second;
	tgui::Layout width_label_number_of_second = 310;
	tgui::Layout height_label_number_of_second = 150;
	tgui::Layout pos_x_label_number_of_second = 290;
	tgui::Layout pos_y_label_number_of_second = 573;
	tgui::Theme theme{ "themes/Black.txt" };
	Label_number_of_seconds(tgui::GuiSFML&);
};



struct Button_reset_scene {
	tgui::Button::Ptr button_reset_scene;
	tgui::Layout width_button_reset_scene = 240;
	tgui::Layout height_button_reset_scene = 31;
	tgui::Layout pos_x_button_reset_scene = 70;
	tgui::Layout pos_y_button_reset_scene = 620;
	Button_reset_scene(tgui::GuiSFML&);
};

struct Button_hide_info {
	tgui::Button::Ptr button_hide_info;
	tgui::Layout width_button_hide_info = 240;
	tgui::Layout height_button_hide_info = 31;
	tgui::Layout pos_x_button_hide_info = 70;
	tgui::Layout pos_y_button_hide_info = 670;
	Button_hide_info(tgui::GuiSFML&);
};