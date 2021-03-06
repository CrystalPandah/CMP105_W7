#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	player.setPosition(200, 200);
	player.setSize(sf::Vector2f(100, 100));
	player.setInput(input);

	bullet.setPosition(500, 500);
	bullet.setSize(sf::Vector2f(10, 10));
	bullet.setFillColor(sf::Color::Red);
	bullet.setVelocity(500, 0);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);
	bullet.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	//bullet.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(player);
	window->draw(*player.getBullet());
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}