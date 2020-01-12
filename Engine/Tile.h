#pragma once
#include "Vei2.h"
#include "Graphics.h"



class Tile
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
	void draw(Graphics& gfx);
	void drawTile(Graphics & gfx, Vec2 position);
	void drawBorder(Graphics& gfx, Vec2 scrPos);

	void setLeftConnection();
	void setTopLeftConnection();
	void setBottomLeftConnection();
	void setRightConnection();
	void setTopRightConnection();
	void setBottomRightConnection();
	void setBottomConnection();
	void setTopConnection();

	bool checkLeftConnection();
	bool checkTopLeftConnection();
	bool checkBottomLeftConnection();
	bool checkRightConnection();
	bool checkTopRightConnection();
	bool checkBottomRightConnection();
	bool checkBottomConnection();
	bool checkTopConnection();
	bool checkUnvisited();


private:
	State state = State::UnVisited;
	Vec2 pos;
	bool hasLeftConnection = false;
	bool hasTopLeftConnection = false;	
	bool hasBottomLeftConnection = false;
	bool hasRightConnection = false;
	bool hasTopRightConnection = false;
	bool hasBottomRightConnection = false;
	bool hasBottomConnection = false;
	bool hasTopConnection = false;
	static constexpr int width = 12;
	static constexpr int height = 12;


};