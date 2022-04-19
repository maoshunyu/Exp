#include <stdio.h>
#pragma warning(disable:4996)
#define SZ 4 
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4
void next(int direction);
void puzzle();
void hanoi(int n, int a, int b, int c);
void generate_map();
void print_way();
typedef struct point {
	int x;
	int y;
	int reachable;//1 -> unreachable
	struct point* prev;
};
struct point map[SZ][SZ];
struct point* ways[SZ * SZ];
int pos_x = 0, pos_y = 0;
int forbid[SZ][SZ];
int main() {
	int choose;
	printf("����1Ϊ��ŵ��   ����2Ϊ�Թ�\n");
	scanf("%d", &choose);
	if (choose == 1) {
		//��1�� 1 for A��ͷ��;  2 for B���н飩;  3 for C��β����n����;
		hanoi(3, 1, 2, 3);
	}
	else {
		//��2��
		puzzle();
	}
}

void hanoi(int n, int a, int b, int c) {
	printf("���������ӵĸ���");
	scanf("%d", &n);
	if (n == 1)printf("%c--->%c\n", a + 64, c + 64); //�ݹ��ֹ����  
	else {
		hanoi(n - 1, a, c, b);//�� n-1�������ȷŵ�B��
		printf("%c--->%c\n", a + 64, c + 64);//��A��ʣ�µ�һ�����ƶ���C��
		hanoi(n - 1, b, a, c);//��n-1���̴�B�ƶ���C��
	}
}

void puzzle() {
	//1. ��ʼ��һ����ͼ 
	generate_map();
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (map[i][j].reachable == 0)printf("- ");
			else printf("X ");
		}
		printf("\n");
	}
	if (map[0][1].reachable == 0)next(RIGHT);
	else next(DOWN);
	print_way();
}

void generate_map() {
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].reachable = 0;
		}
	}
	map[0][2].reachable = 1;
	map[2][2].reachable = 1;
	map[1][0].reachable = 1;
	map[2][0].reachable = 1;
	map[3][0].reachable = 1;
	map[3][1].reachable = 1;
	map[3][2].reachable = 1;
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (j == SZ - 1 || map[i][j + 1].reachable)
				forbid[i][j] |= 1 << 0;
			if (i == SZ - 1 || map[i + 1][j].reachable)
				forbid[i][j] |= 1 << 1;
			if (j == 0 || map[i][j - 1].reachable)
				forbid[i][j] |= 1 << 2;
			if (i == 0 || map[i - 1][j].reachable)
				forbid[i][j] |= 1 << 3;
		}
	}

}
void next(int direction) {
	
	switch (direction) {
	case RIGHT:
		pos_y++;

		map[pos_x][pos_y].prev = &map[pos_x][pos_y - 1];
		break;

	case DOWN:
		pos_x++;

		map[pos_x][pos_y].prev = &map[pos_x - 1][pos_y];
		break;
	case LEFT:
		pos_y--;

		map[pos_x][pos_y].prev = &map[pos_x][pos_y + 1];
		break;

	case UP:
		pos_x--;

		map[pos_x][pos_y].prev = &map[pos_x + 1][pos_y];
		break;

	}
	if (pos_x == SZ - 1 && pos_y == SZ - 1) {
		if (direction == RIGHT) {
			map[pos_x][pos_y].prev = &map[pos_x][pos_y - 1];
		}
		else {
			map[pos_x][pos_y].prev = &map[pos_x - 1][pos_y];
		}
		return;
	}
	if (!((forbid[pos_x][pos_y] >> 1) & 1)) {
		if ((map[pos_x][pos_y].prev) != &map[pos_x + 1][pos_y])
			next(DOWN);
		else {
			map[pos_x][pos_y].prev = NULL;
			forbid[pos_x][pos_y] |= 1 << 1;
			pos_x++;
			return;
		}
	}
	if (!((forbid[pos_x][pos_y] >> 0) & 1)) {
		if ((map[pos_x][pos_y].prev) != &map[pos_x][pos_y + 1])
			next(RIGHT);
		else {
			map[pos_x][pos_y].prev = NULL;
			forbid[pos_x][pos_y] |= 1 << 0;
			pos_y++;
			return;
		}
	}
	if (!((forbid[pos_x][pos_y] >> 2) & 1)) {
		if ((map[pos_x][pos_y].prev) != &map[pos_x][pos_y - 1])
			next(LEFT);
		else {
			map[pos_x][pos_y].prev = NULL;
			forbid[pos_x][pos_y] |= 1 << 2;
			pos_y--;
			return;
		}
	}
	if (!((forbid[pos_x][pos_y] >> 3) & 1)) {
		if ((map[pos_x][pos_y].prev) != &map[pos_x - 1][pos_y])
			next(UP);
		else {
			map[pos_x][pos_y].prev = NULL;
			forbid[pos_x][pos_y] |= 1 << 3;
			pos_x--;
			return;
		}
	}
}
void print_way() {
	pos_x = SZ - 1;
	pos_y = SZ - 1;
	int i = 0;
	int len = 0;
	while (pos_x != 0 || pos_y != 0) {
		ways[i] = &map[pos_x][pos_y];
		i++;
		int temp_x = pos_x;
		int temp_y = pos_y;
		pos_x = map[temp_x][temp_y].prev->x;
		pos_y = map[temp_x][temp_y].prev->y;
	}
	ways[i] = &map[0][0];
	i++;

	//reverse
	for (int j = 0; j < i / 2; j++) {
		point* temp = ways[j];
		ways[j] = ways[i - j - 1];
		ways[i - j - 1] = temp;
	}
	for (int j = 1; j < i; j++) {
		if (j > 1)printf("-");
		if (ways[j]->x > ways[j - 1]->x)printf("��");
		if (ways[j]->x < ways[j - 1]->x)printf("��");
		if (ways[j]->y > ways[j - 1]->y)printf("��");
		if (ways[j]->y < ways[j - 1]->y)printf("��");
		
	}
}