#include <iostream>
#include <map>

using namespace std;

void move(int& x, int& y, char cmd)
{
	// assumes that there are no limits to robot movement
	// i.e., the board is infinite
	switch (cmd)
	{
	case 'R': x++; break;
	case 'L': x--; break;
	case 'U': y--; break;
	case 'D': y++; break;
	}
}

string printBacktrace(map<int, map<int, pair<char, char>>>& visited, int xf, int yf)
{
	string ret;
	int x = xf, y = yf;
	do
	{
		move(x, y, visited[x][y].second);
		if (xf != x || yf != y)
			ret += visited[x][y].first;
	}
	while (xf != x || yf != y);

	return ret;
}


string getLastLoop(string input)
{
	// keeps track of visited nodes in the format:
	// x,y=[command that got to this point,command executed from this point]
	// if we knew the max size of the board and the start point a pair<> visited[max][max]
	// would be simpler
	map<int, map<int, pair<char, char>>> visited;
	int x = 0, y = 0; // current position

	for (auto cmd : input)
	{
		visited[x][y].second = cmd;
		move(x, y, cmd);
		if (visited[x][y].second != 0) 
		{
			return printBacktrace(visited, x, y) + cmd;
		}
		visited[x][y].first = cmd;
	}
	return ""; // No loop detected
}

int main()
{
	cout << getLastLoop("RRDDLLLUUURRRDRRR") << endl;
	return 0;
}
