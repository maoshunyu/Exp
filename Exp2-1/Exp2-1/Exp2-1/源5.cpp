//#include <stdio.h>
//#include <memory>
//#include <string.h>
//#pragma warning(disable:4996)
//using namespace std;
//int main() {
//	char* strs[12];
//	for (int i = 0; i < 12; i++) {
//		strs[i] = (char*)malloc(50 * sizeof(char));
//	}
//	int index = 0;
//	scanf("%s", strs[index]);
//	while (strcmp(strs[index],"stop")!=0) {
//		index++;
//		scanf("%s", strs[index]);
//	}
//	for (int i = 0; i < index; i++) {
//		int min_in = i;
//		for (int j = i; j < index; j++) {
//			if (strcmp(strs[min_in], strs[j]) > 0) {
//				min_in = j;
//			}
//		}
//		char* temp = strs[i];
//		strs[i] = strs[min_in];
//		strs[min_in] = temp;
//	}
//
//	for (int i = 0; i < index; i++) {
//		printf("%s\n", strs[i]);
//	}
//}
#include <stdio.h>
#include <memory>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
size_t get_times(char* str) {
	size_t len = strlen(str);
	int times = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'o')times ++;
	}
	return times;
}
int main() {
	char* str = (char*)malloc(100 * sizeof(char));
	if (str == NULL)return(1);
	gets_s(str, 100);
	str[strlen(str)] = str[strlen(str)+1]= 0;
	int index = 0;
	char* cur = str;
	char* words[20];
	for (int i = 0; i < 20; i++) {
		words[i] = (char*)malloc(30 * sizeof(char));
		if (words[i] == NULL) { return(1); }
		memset(words[i], 0, 30*sizeof(char));

	}
	while (*cur != 0) {
		if (*cur != ' ') {
			int w = 0;
			while (*cur != ' '&& *cur != 0) {
				words[index][w] = *cur;
				w++;
				cur++;
			}
			index++;
		}
		cur++;
	}

	for (int i = 0; i < index; i++) {
		int min_in = i;
		for (int j = i; j < index; j++) {
			if (get_times(words[j]) < get_times(words[min_in])) {
				min_in = j;
			}
		}
		char* temp = words[i];
		words[i] = words[min_in];
		words[min_in] = temp;
	}

	for (int i = 0; i < index; i++) {
		printf("%s\n", words[i]);
	}
}