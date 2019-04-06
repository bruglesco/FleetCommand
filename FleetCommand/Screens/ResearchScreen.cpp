#include "ResearchScreen.h"

namespace fleet {
	ResearchScreen::ResearchScreen(sf::RenderWindow& window, sf::Font& font, DisplayPanel& displayPanel) :
		IScreen{ window, font },
		displayPanel{ displayPanel }
	{
		dashboardButton.setPosition(game_button_1_x, game_button_y);
		dashboard.setPosition(game_button_1_x + dashboard_x_offset, game_button_text_y);
		dashboard.setCharacterSize(text_character_size);
		dashboard.setFillColor(sf::Color::Black);
		unitsButton.setPosition(game_button_2_x, game_button_y);
		units.setPosition(game_button_2_x + unit_x_offset, game_button_text_y);
		units.setCharacterSize(text_character_size);
		units.setFillColor(sf::Color::Black);
		fleetButton.setPosition(game_button_3_x, game_button_y);
		fleet.setPosition(game_button_3_x + fleet_x_offset, game_button_text_y);
		fleet.setCharacterSize(text_character_size);
		fleet.setFillColor(sf::Color::Black);
		worldMapButton.setPosition(game_button_4_x, game_button_y);
		worldMap.setPosition(game_button_4_x + worldmap_x_offset, game_button_text_y);
		worldMap.setCharacterSize(text_character_size);
		worldMap.setFillColor(sf::Color::Black);
	}

	GameEvent ResearchScreen::input()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		GameEvent gameEvent = displayPanel.input(mousePos);
		if (gameEvent != GameEvent::None) { return gameEvent; }

		if (dashboardButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToDashboard;
		}
		else if (unitsButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToUnits;
		}
		else if (fleetButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToFleet;
		}
		else if (worldMapButton.getGlobalBounds().contains(mousePos)) {
			return GameEvent::GoToWorldMap;
		}

		return gameEvent;
	}
	void ResearchScreen::update()
	{
		sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y) };

		displayPanel.update(mousePos);
		checkMouseOver(dashboardButton);
		checkMouseOver(unitsButton);
		checkMouseOver(fleetButton);
		checkMouseOver(worldMapButton);
	}
	void ResearchScreen::draw()
	{
		window.draw(displayPanel);
		window.draw(dashboardButton);
		window.draw(dashboard);
		window.draw(unitsButton);
		window.draw(units);
		window.draw(fleetButton);
		window.draw(fleet);
		window.draw(worldMapButton);
		window.draw(worldMap);
	}
}