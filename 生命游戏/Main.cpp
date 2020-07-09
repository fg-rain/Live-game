#include<iostream>
#include "Map.h"

using namespace std;

int main() {
	Map map;
	vector<vector<Cell>> cells;
	map.start(cells, 40, 80);
	while (1) {	
		system("cls");
		map.updata(cells);
		Sleep(1000);
	}
}