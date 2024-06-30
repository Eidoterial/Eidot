#pragma once
#include <SFML/Graphics.hpp>


class Map {
private:

	sf::Vector2u _size;


public:

	Map(sf::Vector2u size) : _size(size) {}

	sf::Vector2u getSize() const { return _size; }


};