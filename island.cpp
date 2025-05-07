#include <iostream>
#include <conio.h>
#include <graphics.h>
using namespace std;

const int MAX = 10;
int num[MAX] = { 0 };

int find_first_i(int island[MAX][MAX], int length, int height, int island_id) {
	for (int i = 0; i <= length + 1; i++)
		for (int j = 0; j <= height + 1; j++)
			if (island[i][j] == island_id) return i;
	return -1;
}

int find_first_j(int island[MAX][MAX], int length, int height, int island_id) {
	for (int i = 0; i <= length + 1; i++)
		for (int j = 0; j <= height + 1; j++)
			if (island[i][j] == island_id) return j;
	return -1;
}


void fill_island(int island[MAX][MAX], int x, int y, int color, int island_id) {
	if (getpixel(x, y) == BLACK && island[x][y] == island_id) {
		putpixel(x, y, color);
		num[island_id]++;

		fill_island(island, x + 1, y, color, island_id);
		fill_island(island, x - 1, y, color, island_id);
		fill_island(island, x, y + 1, color, island_id);
		fill_island(island, x, y - 1, color, island_id);
		fill_island(island, x + 1, y + 1, color, island_id);
		fill_island(island, x - 1, y + 1, color, island_id);
		fill_island(island, x - 1, y - 1, color, island_id);
		fill_island(island, x + 1, y - 1, color, island_id);
	}
}

int main() {
	initwindow(500, 500, "Island Area Visualization");

	int n, length, height;
	int island[MAX][MAX] = { 0 };

	cout << "Enter number of islands: ";
	cin >> n;
	cout << "Enter grid length and height: ";
	cin >> length >> height;

	rectangle(0, 0, length + 1, height + 1);


	for (int i = 1; i <= length; i++) {
		for (int j = 1; j <= height; j++) {
			int val;
			cout << "island[" << i << "][" << j << "]: ";
			cin >> val;
			while (val < 0 || val > n) {
				cout << "Invalid island ID. Re-enter: ";
				cin >> val;
			}
			island[i][j] = val;
		}
	}

	cout << "\nIsland Grid:\n";
	for (int i = 0; i <= length + 1; i++) {
		for (int j = 0; j <= height + 1; j++) {
			cout << island[i][j] << " ";
		}
		cout << endl;
	}

	for (int id = 1; id <= n; id++) {
		int x = find_first_i(island, length, height, id);
		int y = find_first_j(island, length, height, id);
		fill_island(island, x, y, 12 + id, id);
		cout << "Island " << id << " area: " << num[id] << endl;
	}

	int max_area = 0, max_id = 0;
	for (int i = 1; i <= n; i++) {
		if (num[i] > max_area) {
			max_area = num[i];
			max_id = i;
		}
	}

	cout << "\nLargest Island: ID=" << max_id << ", Area=" << max_area << endl;

	getch();
	return 0;
}