#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

struct  Active_Move_Button {

	bool A{ false };

	bool D{ false };

	bool W{ false };

	bool S{ false };

};

class Camera {
private:

	float _speed;

	sf::Vector2u _size;

	sf::Vector2f _position;

	sf::Vector2f _velosity;

	Active_Move_Button _AMB;

	float _zoom{ 1.0 };

public:

	Camera(sf::Vector2u size) : _speed(1.0), _size(size), _position(sf::Vector2f(0.0, 0.0)), _velosity(sf::Vector2f(0.0, 0.0)) {}





	/// SIZE
	sf::Vector2u get_Size() const { return _size; }

	/// SPEED
	void set_Speed(float new_speed) { _speed = new_speed; }

	float get_Speed() const { return _speed; }

	/// VELOSITY
	void change_Velosity() {
		if (_AMB.A) _velosity.x -= _speed;
		else if (_AMB.D) _velosity.x += _speed;
		else _velosity.x = 0.0;

		if (_AMB.W) _velosity.y -= _speed;
		else if (_AMB.S) _velosity.y += _speed;
		else _velosity.y = 0.0;
	}

	sf::Vector2f get_Velosity() const { return _velosity; }

	/// POSITION
	void change_Position() { _position += _velosity; }

	sf::Vector2f get_Position() const { return _position; }

	/// AMB
	Active_Move_Button& get_AMB() { return _AMB; }



};