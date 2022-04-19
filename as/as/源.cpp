#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <time.h>
#include <iostream>
using namespace std;

#define Size 40

struct Point {
	int x;
	int y;
	int g;
	int h;
	int f;
	bool reachable;
	Point* father;
	int road;
	bool operator==(const Point a) {
		return (this->x == a.x && this->y == a.y);
	}
};


vector<Point*> ol,cl,neighbours;
Point map[Size][Size];
Point* startp;
Point* endp;

bool isContained(vector<Point*>* l, Point* p);
int set_g(Point* p);
int set_h(Point* p);
int set_f(Point* p);
void update(Point* p);
Point *find_min();
void init_map();
void print_map();
void create_map();
vector<Point*> get_neighbours(Point* p);

int main() {
	init_map();
	create_map();
	neighbours.clear();
	print_map();
	printf("\n");
	do{
		Point* cur = find_min();

		for (auto Iter = ol.begin(); Iter != ol.end(); ){
			if (*Iter == cur) {
				ol.erase(Iter);

				break;
			}
			else Iter++;
		}
		cl.push_back(cur);
		neighbours.clear();
		neighbours = get_neighbours(cur);

		for (int i = 0;i < neighbours.size(); i++) {
			if(!neighbours.at(i)->reachable || isContained(&cl, neighbours.at(i))) {}
			else if (!isContained(&ol, neighbours.at(i))) {
				ol.push_back(neighbours.at(i));
				neighbours.at(i)->father = cur;
				update(neighbours.at(i));
			}else if (isContained(&ol, neighbours.at(i))) {
				if (cur->g + 1 < neighbours.at(i)->g) {
					neighbours.at(i)->father = cur;
					update(neighbours.at(i));
				}
			}
		}

	} while (!isContained(&ol,endp) || ol.size() == 0);

	vector<Point*> road;
	Point* cur = endp;
	while (cur->father != startp) {
		road.push_back(cur);
		cur = cur->father;
	}

	road.push_back(cur);
	road.push_back(cur->father);
	reverse(road.begin(), road.end());
	for (int i = 0; i < road.size(); i++) {
		map[road[i]->x][road[i]->y].road = i + 1;
	}
	print_map();
	printf("\n");
	return 0;
}

bool isContained(vector<Point*>* l, Point* p)
{
	for (int i = 0;i < (*l).size(); i++) {
		if ((*l).at(i) == p)return true;
	}
	return false;
}

int set_g(Point* p)
{
	Point* cur = p;
	while (cur->father != startp) {
		p->g = cur->father->g + 1;
		cur = cur->father;
	}

	return p->g;
}

int set_h(Point* p)
{
	p->h = abs(p->x - (Size-1)) + abs(p->y - Size+1);
	return p->h;
}

int set_f(Point* p)
{
	p->f = p->g + p->h;
	return p->f;
}

void update(Point* p)
{
	set_g(p);
	set_h(p);
	set_f(p);
}

void init_map()
{
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].father = NULL;
			map[i][j].reachable = true;
		}
	}
	startp = &map[0][0];
	endp = &map[Size-1][Size-1];
	startp->g = 0;
	endp->h = 0;

	map[0][1].g = 1;
	map[1][0].g = 1;
	map[Size - 1][Size - 2].h = 1;
	map[Size - 2][Size - 1].h = 1;
	map[0][1].father = startp;
	map[1][0].father = startp;

	/*          obstacles         */
	/*map[0][2].reachable = false;
	map[2][0].reachable = false;
	map[2][1].reachable = false;
	map[2][2].reachable = false;
	map[2][3].reachable = false;
	map[2][5].reachable = false;
	map[3][5].reachable = false;
	map[4][1].reachable = false;
	map[4][2].reachable = false;
	map[4][3].reachable = false;
	map[4][4].reachable = false;*/
	/******************************/


	ol.push_back(&map[0][1]);
	ol.push_back(&map[1][0]);
	cl.push_back(&map[0][0]);

	neighbours.push_back(&map[0][1]);
	neighbours.push_back(&map[1][0]);

	update(&map[0][1]);
	update(&map[1][0]);
}
void print_map()
{
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (map[i][j].road > 0) {
				printf("%-3d", map[i][j].road);
				continue;
			}
			if (map[i][j].reachable)printf("_  ");
			else printf("#  ");
		}
		printf("\n");
	}
}
void create_map()
{
	stack<Point*> list;
	list.push(endp);
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			map[i][j].reachable = false;
		}
	}
	map[Size - 1][Size - 1].reachable = true;
	
	Point* cur = endp;
	int i = 0;
	while (cur != startp) {
		neighbours.clear();
		neighbours = get_neighbours(cur);
		i++;
		//srand((unsigned int)time(NULL));
		int r = rand() % neighbours.size();
		vector<Point*> next_neighs = get_neighbours(neighbours.at(r));
		int flag = 0;
		for (int i = 0; i < neighbours.size(); i++) {
			if (!neighbours.at(i)->reachable) { flag = 1; break; }
		}
		for (int i = 0; i < next_neighs.size(); i++) {
			if (!next_neighs.at(i)->reachable) { flag = 1; break; }
		}
		if (flag==0) { 
			list.top()->reachable = false;
			//neighbours.at(r)->reachable = true;
			list.pop(); 
			cur = list.top();
			continue;
		}
		if (neighbours.at(r)->reachable && flag==1)continue;
		list.push(neighbours.at(r));
		if (list.top() == startp)goto leave;
		neighbours.at(r)->reachable = true;
		neighbours.clear();
		neighbours = get_neighbours(list.top());

		cur = list.top();

	}
	leave:
	map[0][0].reachable = true;


}

vector<Point*> get_neighbours(Point* p)
{
	vector<Point*> near;
	if (p->x > 0)near.push_back(&map[p->x - 1][p->y]);
	if (p->y > 0)near.push_back(&map[p->x][p->y-1]);
	if (p->x <Size-1)near.push_back(&map[p->x + 1][p->y]);
	if (p->y <Size-1)near.push_back(&map[p->x][p->y+1]);
	return near;
}


Point *find_min() {
	Point* min = ol.at(0);
	int k = 0;
	for (int i = 0;i < ol.size(); i++) {
		if (ol.at(i)->f <= min->f) {
			min = ol.at(i);
			k = i;
		}
	}
	return ol.at(k);
	
}



