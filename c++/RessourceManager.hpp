/*
** EPITECH PROJECT, 2018
** Indie
** File description:
** Ressource Manager
*/

#pragma once

#include <functional>
#include <map>

namespace ECS {
	template <typename T, typename U>
	class RessourceManager;
};

template <typename T, typename U>
class ECS::RessourceManager {
public:
	RessourceManager(std::function<U (const T &)> loadFct) :
		_loadFct(loadFct) {};

	U& operator[](const T &idx) {
		auto it = _data.find(idx);

		if (it == _data.end())
			_data[idx] = _loadFct(idx);
		return (_data[idx]);
	};

private:
	std::function<U (const T &)> _loadFct;
	std::map<T, U> _data;
};
