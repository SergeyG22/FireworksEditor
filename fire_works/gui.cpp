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
	if (change_state) {
		target.draw(fps_text, states);
		target.draw(fractions_text, states);
		target.draw(fireworks_text, states);
	}
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
	combo_box_color->addItem(L"красный");
	combo_box_color->addItem(L"зеленый");
	combo_box_color->addItem(L"пурпурный");
	combo_box_color->addItem(L"бирюзовый");
	combo_box_color->addItem(L"желтый");
	combo_box_color->addItem(L"белый");
	combo_box_color->addItem(L"случайный");
	combo_box_color->setSelectedItem(L"случайный");
	GUI.add(combo_box_color);
}

Combo_box_number_of_fireworks::Combo_box_number_of_fireworks(tgui::GuiSFML& GUI) {
	combo_box_number_of_fireworks = tgui::ComboBox::create();
	combo_box_number_of_fireworks->setRenderer(theme.getRenderer("ComboBox"));
	combo_box_number_of_fireworks->setTextSize(20);
	combo_box_number_of_fireworks->setSize(width_combo_box_number_of_fireworks, height_combo_box_number_of_fireworks);
	combo_box_number_of_fireworks->setPosition(pos_x_combo_box_number_of_fireworks, pos_y_combo_box_number_of_fireworks);
	combo_box_number_of_fireworks->setVisible(false);
	combo_box_number_of_fireworks->addItem(L"один фейрверк", "1");
	combo_box_number_of_fireworks->addItem(L"два фейрверка", "2");
	combo_box_number_of_fireworks->addItem(L"три фейрверка", "3");
	combo_box_number_of_fireworks->addItem(L"четыре фейрверка", "4");
	combo_box_number_of_fireworks->addItem(L"пять фейрверков", "5");
	combo_box_number_of_fireworks->setSelectedItem(L"один фейрверк");
	GUI.add(combo_box_number_of_fireworks);
}

Slider_number_of_lights::Slider_number_of_lights(tgui::GuiSFML& GUI) {
	slider_number_of_lights = tgui::Slider::create();
	slider_number_of_lights->setRenderer(theme.getRenderer("Slider"));
	slider_number_of_lights->setVisible(false);
	slider_number_of_lights->setSize(width_number_of_lights, height_number_of_lights);
	slider_number_of_lights->setPosition(pos_x_number_of_lights, pos_y_number_of_lights);
	slider_number_of_lights->setValue(20);
	slider_number_of_lights->setMinimum(1);
	slider_number_of_lights->setMaximum(150);
	slider_number_of_lights->setStep(1);
	GUI.add(slider_number_of_lights);
}

Slider_number_of_particles::Slider_number_of_particles(tgui::GuiSFML& GUI) {
	slider_number_of_particles = tgui::Slider::create();
	slider_number_of_particles->setRenderer(theme.getRenderer("Slider"));
	slider_number_of_particles->setVisible(false);
	slider_number_of_particles->setSize(width_number_of_particles, height_number_of_particles);
	slider_number_of_particles->setPosition(pos_x_number_of_particles, pos_y_number_of_particles);
	slider_number_of_particles->setValue(5);
	slider_number_of_particles->setMinimum(1);
	slider_number_of_particles->setMaximum(15);
	slider_number_of_particles->setStep(1);
	GUI.add(slider_number_of_particles);
}

Slider_start_of_fireworks::Slider_start_of_fireworks(tgui::GuiSFML& GUI) {
	slider_start_of_fireworks = tgui::Slider::create();
	slider_start_of_fireworks->setRenderer(theme.getRenderer("Slider"));
	slider_start_of_fireworks->setVisible(false);
	slider_start_of_fireworks->setSize(width_start_of_fireworks, height_start_of_fireworks);
	slider_start_of_fireworks->setPosition(pos_x_start_of_fireworks, pos_y_start_of_fireworks);
	slider_start_of_fireworks->setValue(10);
	slider_start_of_fireworks->setMinimum(0);
	slider_start_of_fireworks->setMaximum(60);
	slider_start_of_fireworks->setStep(1);
	GUI.add(slider_start_of_fireworks);
}



Label_number_of_lights::Label_number_of_lights(tgui::GuiSFML&GUI) {
	label_number_of_lights = tgui::Label::create();
	label_number_of_lights->setVisible(false);
	label_number_of_lights->setPosition(pos_x_label_number_of_lights, pos_y_label_number_of_lights);
	label_number_of_lights->setText(L"20");
	label_number_of_lights->setTextSize(20);
	GUI.add(label_number_of_lights);
}

Label_number_of_particles::Label_number_of_particles(tgui::GuiSFML& GUI) {
	label_number_of_particles = tgui::Label::create();
	label_number_of_particles->setVisible(false);
	label_number_of_particles->setPosition(pos_x_label_number_of_particles, pos_y_label_number_of_particles);
	label_number_of_particles->setText(L"5");
	label_number_of_particles->setTextSize(20);
	GUI.add(label_number_of_particles);
}

Label_number_of_seconds::Label_number_of_seconds(tgui::GuiSFML& GUI) {
	label_number_of_second = tgui::Label::create();
	label_number_of_second->setVisible(false);
	label_number_of_second->setPosition(pos_x_label_number_of_second, pos_y_label_number_of_second);
	label_number_of_second->setText(L"10");
	label_number_of_second->setTextSize(20);
	GUI.add(label_number_of_second);
}



Button_reset_scene::Button_reset_scene(tgui::GuiSFML& GUI) {
	button_reset_scene = tgui::Button::create();
	button_reset_scene->setVisible(false);
	button_reset_scene->setTextSize(20);
	button_reset_scene->setPosition(pos_x_button_reset_scene, pos_y_button_reset_scene);
	button_reset_scene->setText(L"Удалить фейрверки");
	button_reset_scene->setSize(width_button_reset_scene, height_button_reset_scene);
	GUI.add(button_reset_scene);
}

Button_hide_info::Button_hide_info(tgui::GuiSFML& GUI) {
	button_hide_info = tgui::Button::create();
	button_hide_info->setVisible(false);
	button_hide_info->setTextSize(20);
	button_hide_info->setPosition(pos_x_button_hide_info, pos_y_button_hide_info);
	button_hide_info->setText(L"Удалить надписи");
	button_hide_info->setSize(width_button_hide_info, height_button_hide_info);
	GUI.add(button_hide_info);
}