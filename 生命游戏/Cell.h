#pragma once
class Cell
{
private:
	bool state;//细胞当前状态
	int count;//当前细胞周围的细胞存活数
	char display;
public:
	Cell(int n, bool a,char o) {
		state = a;
		count = n;
		display = o;
	}
	~Cell() {
	}
	int getCount() {
		return count;
	}
	bool getState() {
		return state;
	}
	char getdisplay() {
		return display;
	}
	void setCount(int n) {
		count = n;
	}
	void setState(bool b) {
		state = b;
	}
	void setdisp(char o) {
		display = o;
	}
};
