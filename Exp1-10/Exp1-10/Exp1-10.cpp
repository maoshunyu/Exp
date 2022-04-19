#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
    ////第一题
    //char sa[31], sb[31];
    //int pos[31];
    //int time = 0;
    //memset(pos, -1, sizeof(pos));
    //printf("input sA:");
    //scanf("%s", sa);
    //printf("input sB:");
    //scanf("%s", sb);
    //for (int i = 0;i < strlen(sa);i++) {
    //    if (sa[i] == sb[0]) {
    //        for (int j = 0;j < strlen(sb);j++) {
    //            if (sb[j] == '?')continue;
    //            else if (sa[j + i] != sb[j])goto s;
    //        }
    //        pos[time] = i;
    //        time++;
    //        s:
    //        continue;
    //    }
    //}
    //printf("output: ");
    //for (int i = 0;i < 31;i++) {
    //    if (pos[i] != -1)printf("%d ", pos[i]);
    //}
    //if (pos[0] == -1)printf("No matches found");
    //return 0;

    ////第二题
    //char s[30], v[30], v_i[30];
    //int pos[30];
    //memset(pos, -1, sizeof(pos));
    //printf("input: ");
    //scanf("%s", s);
    //int j = 0;
    //for (int i = 0;i < strlen(s);i++) {
    //    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
    //        pos[j] = i;
    //        v[j] = s[i];
    //        j++;
    //    }
    //}
    //for (int i = 0;i < j;i++) {
    //    v_i[j - i-1] = v[i];
    //}
    //for (int i = 0;i < j;i++) {
    //    s[pos[i]] = v_i[i];
    //}
    //printf("output: %s",s);

    //第三题

    char s[30];
    printf("input: ");
    scanf("%s", s);
    for (int j = 0;j < strlen(s);j++) {
        for (int i=0;i < strlen(s)-1;i++) {
            if (s[i] < s[i + 1]) {
                char temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
            }
        }
    }
    printf("output: %s", s);
}

