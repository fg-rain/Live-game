#pragma once
#include<vector>
#include "Cell.h"
#include <time.h>
#include <windows.h>
using namespace std;
class Map
{
public:
	void updata(vector<vector<Cell>> &cells) {
        for (int i = 0; i < cells.size(); i++) {//���µ�ͼ
            for (int j = 0; j < cells[0].size(); j++) {
                if (cells[i][j].getCount() < 2 || cells[i][j].getCount() > 3) {
                    cells[i][j].setState(false);
                    cells[i][j].setdisp(' ');
                }
                    
                else if (cells[i][j].getCount() == 3) {
                    cells[i][j].setState(true);
                    cells[i][j].setdisp('o');
                }                    
            }
        }
        for (int i = 0; i < cells.size(); i++) {
            for (int j = 0; j < cells[0].size(); j++) {
                liveCount(cells,i,j);
            }
        }
        printMap(cells);
	}
	void start(vector<vector<Cell>> &cells,int x, int y) {//��ʼ����ͼ
		for (int i = 0; i < x; i++) {
			vector<Cell> width;
			for (int j = 0; j < y; j++) {
				bool cellState = randnum();//�������ϸ��״̬
                if (cellState) {
                    Cell newcell(0, cellState,'o');
                    width.push_back(newcell);
                }
                else {
                    Cell newcell(0, cellState, ' ');
                    width.push_back(newcell);
                }
			}
			cells.push_back(width);
		}
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                liveCount(cells,i, j);
            }
        }
        printMap(cells);
	}

private:
	bool randnum() {
		int r = rand() % 9;
		if (r < 2)return true;
		else return false;
	}

    void liveCount(vector<vector<Cell>> &cells,int x, int y) {
        int live = 0;
        if (x > 0)
        {
            if (cells[x - 1][y].getState())//��
                live++;
            if (y > 0 && cells[x - 1][y - 1].getState())//����
                live++;
            if (y < cells[0].size() - 1 && cells[x - 1][y + 1].getState())//����
                live++;
        }
        if (x < cells.size() - 1)
        {
            if (cells[x + 1][y].getState())//��
                live++;
            if (y > 0 && cells[x + 1][y - 1].getState())//����
                live++;
            if (y < cells[0].size() - 1 && cells[x + 1][y + 1].getState())//����
                live++;
        }
        if (y > 0 && cells[x][y - 1].getState())//��
            live++;
        if (y < cells[0].size() - 1 && cells[x][y + 1].getState())//��
            live++;
        cells[x][y].setCount(live);
    }

    void printMap(vector<vector<Cell>>& cells) {
        for (int i = 0; i < cells.size(); i++) {
            for (int j = 0; j < cells[0].size(); j++) {
                if (cells[i][j].getdisplay() == 'o')
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                cout << cells[i][j].getdisplay() << ' ';
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            }
            cout << endl;
        }
        cout << endl;
    }
};
