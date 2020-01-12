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

void Tile::drawTiles(Graphics & gfx, Vei2 pos)
{
	Vec2 scrPos = {100,100};

	Vec2 p1 = { -2 + scrPos.x,-4 + scrPos.y };
	Vec2 p2 = { -4 + scrPos.x, -2 + scrPos.y };
	Vec2 p3 = { -4 + scrPos.x, 2 + scrPos.y };
	Vec2 p4 = { -2 + scrPos.x, 2 + scrPos.y };
	Vec2 p5 = {  2 + scrPos.x, 2 + scrPos.y };
	Vec2 p6 = {  4 + scrPos.x, 2 + scrPos.y };
	Vec2 p7 = { -4 + scrPos.x, -4 + scrPos.y };
	Vec2 p8 = {  2 + scrPos.x, -4 + scrPos.y };

}

void Tile::drawTile(Graphics & gfx, Vec2 scrPos)
{
	Vec2 p1 = { -6 + scrPos.x,-12 + scrPos.y };
	Vec2 p2 = { 6 + scrPos.x, -12 + scrPos.y };
	Vec2 p3 = { 12 + scrPos.x, -6 + scrPos.y };
	Vec2 p4 = { 12 + scrPos.x, 6 + scrPos.y };
	Vec2 p5 = { 6 + scrPos.x, 12 + scrPos.y };
	Vec2 p6 = { -6 + scrPos.x, 12 + scrPos.y };
	Vec2 p7 = { -12 + scrPos.x, 6 + scrPos.y };
	Vec2 p8 = { -12 + scrPos.x, -6 + scrPos.y };

	gfx.Drawline(p1, p2, Colors::White);
	gfx.Drawline(p2, p3, Colors::White);
	gfx.Drawline(p3, p4, Colors::White);
	gfx.Drawline(p4, p5, Colors::White);
	gfx.Drawline(p5, p6, Colors::White);
	gfx.Drawline(p6, p7, Colors::White);
	gfx.Drawline(p7, p8, Colors::White);
	gfx.Drawline(p8, p1, Colors::White);
}

void Tile::draw(Graphics & gfx)
{
	float x = 70.0f; 
	float y = 60.0f;
	Vec2 scrPos = { x,y };

	drawBorder(gfx, scrPos);

	int length = 19;
	for (int j = 1; j < 26; j++)
	{
		for (int i = 0; i < length; i++)
		{
			drawTile(gfx, scrPos);
			scrPos.x += 36;
		}

		if (j % 2 == 1)
		{
			scrPos.x = x + 18;
			length -= 1;
		}
		else
		{
			scrPos.x = x;
			length += 1;
		}

		scrPos.y += 19;
	}
}

void Tile::drawBorder(Graphics & gfx, Vec2 scrPos)
{
	Vec2 p1 = { scrPos.x + 12.0f, scrPos.y - 6.0f };
	Vec2 p2 = { scrPos.x + 12.0f, scrPos.y + 6.0f + 24.0f * 19.0f };
	Vec2 p3 = { scrPos.x - 6.0f, scrPos.y + 13.0f };
	Vec2 p4 = { scrPos.x + 6.0f + 24.0f * 27, scrPos.y + 13.0f };

	for (int i = 0; i < 18; i++)
	{
		gfx.Drawline(p1, { p1.x + 12, p1.y }, Colors::White);
		gfx.Drawline(p2, { p2.x + 12, p2.y }, Colors::White);
		p1.x += 36.0f;
		p2.x += 36.0f;
	}

	for (int i = 0; i < 12; i++)
	{
		gfx.Drawline(p3, { p3.x, p3.y + 13 }, Colors::White);
		gfx.Drawline(p4, { p4.x, p4.y + 13 }, Colors::White);
		p3.y += 38.0f;
		p4.y += 38.0f;
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

