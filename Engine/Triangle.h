#pragma once
#include "Vei2.h"
#include "Graphics.h"



class Triangle
{
public:

	enum class State
	{
		OutsideGrid,
		Visited,
		UnVisited,
		Start,
		End
	};

	State setToUnvisited();
	State setToVisited();
	State setToStart();
	void setToEnd();
	void drawTriangle(Graphics& gfx, Vei2 position);
	void setLeftConnection();
	void setRightConnection();
	void setBottomConnection();
	void setTopConnection();
	bool checkLeftConnection();
	bool checkRightConnection();
	bool checkBottomConnection();
	bool checkTopConnection();
	bool checkUnvisited();


private:
	State state = State::OutsideGrid;
	Vec2 pos;
	bool hasLeftConnection = false;
	bool hasRightConnection = false;
	bool hasBottomConnection = false;
	bool hasTopConnection = false;
	static constexpr int width = 12;
	static constexpr int height = 12;


};