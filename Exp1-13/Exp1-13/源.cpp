#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
struct birthday
{
	int year;
	int month;
	int day;
};
struct student {
	int id;
	char name[30];
	char sex[10];
	struct birthday birth;
	float score;
};
float average(student s[]);
void sort(student s[]);
void save(student s[]);
student find(int id);
int main() {
	struct student s[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d %s %s %d %d %d %f", &s[i].id, s[i].name, s[i].sex, &s[i].birth.year, &s[i].birth.month, &s[i].birth.day, &s[i].score);

	}
	float avg = average(s);
	printf("平均成绩： %.2f\n", avg);
	save(s);
	int id;
	printf("请输入学号:");
	scanf("%d", &id);
	student ans = find(id);
	printf("ID:%d 姓名：%s  性别：%s  出生日期：%d年%d月%d日  成绩：%.2f\n\n", ans.id, ans.name, ans.sex, ans.birth.year, ans.birth.month, ans.birth.day, ans.score);
	sort(s);
	printf("成绩排序：\n");
	for (int i = 0; i < 10; i++) {
		printf("姓名:%s  成绩:%.2f  排名:%d  \n", s[i].name, s[i].score, i + 1);
	}
}

float average(student s[])
{
	float sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += s[i].score;
	}
	sum /= 10;
	return sum;
}

void sort(student s[])
{
	for (int i = 0; i < 10; i++) {
		float min = s[i].score;
		int k = i;
		for (int j = i; j < 10; j++) {
			if (s[j].score >= min) {
				min = s[j].score;
				k = j;
			}
		}
		student t = s[i];
		s[i] = s[k];
		s[k] = t;	
	}

}

void save(student s[])
{
	FILE* fp;
	fp=fopen("student.txt", "w");
	for (int i = 0; i < 10; i++) {
		fprintf(fp, "%d %s %s %d %d %d %.2f\n", s[i].id, s[i].name, s[i].sex, s[i].birth.year, s[i].birth.month, s[i].birth.day, s[i].score);
	}
	fclose(fp);
}

student find(int id)
{
	FILE* fp;
	fp = fopen("student.txt", "r");
	student ans;
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "%d %s %s %d %d %d %f", &ans.id, ans.name, ans.sex, &ans.birth.year, &ans.birth.month, &ans.birth.day, &ans.score);
		if (ans.id == id)break;
	}
	fclose(fp);
	return ans;
}
