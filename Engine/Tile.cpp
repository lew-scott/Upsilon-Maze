#include "Tile.h"


Tile::State Tile::setToUnvisited()
{
	return state = State::UnVisited;
}

Tile::State Tile::setToVisited()
{
	return state = State::Visited;
}

Tile::State Tile::setToStart()
{
	setBottomConnection();
	return state = State::Start;
}

void Tile::setToEnd()
{
	setBottomConnection();
}

void Tile::drawTriangle(Graphics & gfx, Vei2 pos)
{
	Vec2 scrPos;
	scrPos.x = (float)pos.x * width * 0.5f + 130.0f;
	scrPos.y = (float)pos.y * height + 30.0f;

	Vec2 p1 = { 0 + scrPos.x,-8 + scrPos.y };
	Vec2 p2 = { -6 + scrPos.x, 4 + scrPos.y };
	Vec2 p3 = { 6 + scrPos.x, 4 + scrPos.y };
	if (state == State::Visited || state == State::Start || state == State::End)
	{
		if (hasLeftConnection == false)
		{
			gfx.Drawline(p1, p2, Colors::White);
		}

		if (hasBottomConnection == false)
		{
			gfx.Drawline(p2, p3, Colors::White);
		}

		if (hasRightConnection == false)
		{
			gfx.Drawline(p3, p1, Colors::White);
		}
	}
}

void Tile::setLeftConnection()
{
	 hasLeftConnection = true;
}

void Tile::setRightConnection()
{
	hasRightConnection = true;
}

void Tile::setBottomConnection()
{
	hasBottomConnection = true;
}

void Tile::setTopConnection()
{
	hasTopConnection = true;
}

bool Tile::checkLeftConnection()
{
	return hasLeftConnection;
}

bool Tile::checkRightConnection()
{
	return hasRightConnection;
}

bool Tile::checkBottomConnection()
{
	return hasBottomConnection;
}

bool Tile::checkTopConnection()
{
	return hasTopConnection;
}


bool Tile::checkUnvisited()
{
	if (state == State::UnVisited)
	{ 
		return true;
	}
	
	return false; 

}

