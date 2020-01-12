#include "Maze.h"

void Maze::initLayout()
{
	Vei2 p = { 44,0 };
	int length = 1;
	for (int j = 0; j < height; j++)
	{
		for (int i = 1; i <= length; i++)
		{
			atTriangle(p).setToUnvisited();
			if (i != length)
			{
				p.x += 1;
			}
		}
		p.x = p.x - length;
		length += 2;

		p.y += 1;
	}

	p = { 0, height-1 };
	pos = p;
	moves.push_back(p);
	atTriangle(p).setToStart();
	p = { width-1,height-1 };
	atTriangle(p).setToEnd();
}


void Maze::createMaze()
{
	bool visitedAllTri = false;
	while (visitedAllTri == false)
	{
		AvailableMoves = { 0,0,0 };
		if (pos.y % 2 == 0) // Even row
		{
			if (pos.x % 2 == 0) // bottom-flat triangle
			{

				if (pos.x > 0)
				{
					newPos = pos - hm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[0] = 1;
					}
				}


				if (pos.x < width - 1)
				{
					newPos = pos + hm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[1] = 2;
					}
				}


				if (pos.y < height - 1)
				{
					newPos = pos + vm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[2] = 3;
					}
				}
			}
			else // top-flat triangle
			{

				if (pos.x > 0)
				{
					newPos = pos - hm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[0] = 1;
					}
				}


				if (pos.x < width - 1)
				{
					newPos = pos + hm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[1] = 2;
					}
				}


				if (pos.y > 0)
				{
					newPos = pos - vm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[2] = 4;
					}
				}
			}
		}
		else // Odd row
		{
			if (pos.x % 2 == 1) // bottom-flat triangle
			{

				if (pos.x > 0)
				{
					newPos = pos - hm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[0] = 1;
					}
				}


				if (pos.x < width - 1)
				{
					newPos = pos + hm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[1] = 2;
					}
				}


				if (pos.y < height - 1)
				{
					newPos = pos + vm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[2] = 3;
					}
				}
			}
			else // top-flat triangle
			{

				if (pos.x > 0)
				{
					newPos = pos - hm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[0] = 1;
					}
				}


				if (pos.x < width - 1)
				{
					newPos = pos + hm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[1] = 2;
					}
				}


				if (pos.y > 0)
				{
					newPos = pos - vm;
					if (atTriangle(newPos).checkUnvisited() == true)
					{
						AvailableMoves[2] = 4;
					}
				}
			}
		}
		bool NowhereFree;

		for (int i = 1; i < AvailableMoves.size(); i++)
		{
			if (AvailableMoves[i - 1] != AvailableMoves[i])
			{
				NowhereFree = false;
				break;
			}
			else
			{
				NowhereFree = true;
			}
		}

		if (NowhereFree == true) // if no position is free move back
		{
			pos = moves.rbegin()[1];
			moves.pop_back();
		}

		else
		{
			std::uniform_int_distribution<int> dist(0, int(AvailableMoves.size()) - 1);
			std::random_device rd;
			std::mt19937 rng{ rd() };
			int direction = 0;
			int i = 0;
			while (i == 0) // get a random direction, based on tiles available around itself
			{
				i = AvailableMoves[dist(rng)];
				direction = i;
			}
			if (direction == 1)
			{
				atTriangle(pos).setLeftConnection();  // set connection at old tile with new tile
				pos -= hm;				           // move
				atTriangle(pos).setToVisited();
				atTriangle(pos).setRightConnection(); // set connection at new tile with previous
			}
			else if (direction == 2)
			{
				atTriangle(pos).setRightConnection();  // set connection at old tile with new tile
				pos += hm;							// move
				atTriangle(pos).setToVisited();
				atTriangle(pos).setLeftConnection(); // set connection at new tile with previous
			}
			else if (direction == 3)
			{
				atTriangle(pos).setBottomConnection();  // set connection at old tile with new tile
				pos += vm;				      // move
				atTriangle(pos).setToVisited();
				atTriangle(pos).setTopConnection(); // set connection at new tile with previous
			}
			else if (direction == 4)
			{
				atTriangle(pos).setTopConnection();  // set connection at old tile with new tile
				pos -= vm;				      // move
				atTriangle(pos).setToVisited();
				atTriangle(pos).setBottomConnection(); // set connection at new tile with previous
			}
			moves.push_back(pos);
		}
		visitedAllTri = check_tri_are_all_visited();
	}
}

bool Maze::check_tri_are_all_visited()
{
	bool test = true;
	for (int i = 0; i < width*height; i++)
	{
		if (points[i].checkUnvisited() == true)
		{
			return false;
		}
	}
	return true;
}

void Maze::drawMaze(Graphics & gfx)
{
	Vei2 p = { 0,0 };
	for (Vei2 gridpos = { 0,0 }; gridpos.y < height; gridpos.y++)
	{
		for (gridpos.x = 0; gridpos.x < width; gridpos.x+=1)
		{
			p.x = gridpos.x;
			p.y = gridpos.y;

			if (gridpos.x % 2 == 0 && gridpos.y % 2 == 0)
			{
				atTriangle(gridpos).drawTriangle(gfx, p);
			}
			else if(gridpos.x % 2 == 1 && gridpos.y % 2 == 1)
			{
				atTriangle(gridpos).drawTriangle(gfx, gridpos);
			}
		}
	}
}

Triangle& Maze::atTriangle(const Vei2 position)
{
	return points[position.y * width + position.x];
}

const Triangle & Maze::atTriangle(const Vei2 & position) const
{
	return points[position.y * width + position.x];
}
