/*
��һ����ܵļ��̱����û��ˣ�Home ���� End �������ᱻ�Զ����£���������֪����
Home ���Ĺ����ǽ��������ƶ��������е���ǰ�ˣ��� 'H' ��ʾ��
End ���Ĺ����ǽ��������ƶ��������е���ĩ�ˣ��� 'E' ��ʾ��
�����ڱ��ܴ���ʾ��֮ǰ���������������ַ�������Ļ�ϻ���ʾ�����ӡ�*/


#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
typedef struct Linklist {
	char x;
	struct Linklist* next;
}Linklist, *pLinklist;
char ch[100007];
int main()
{

	while (~scanf("%s", ch)) {
		pLinklist head, temp = NULL, end, now;

		head = (pLinklist)malloc(sizeof(Linklist));
		end = head;
		temp = (pLinklist)malloc(sizeof(Linklist));
		int i = 0;
		int ls = strlen(ch);
		for (; i < ls; ++i) {
			temp = (pLinklist)malloc(sizeof(Linklist));
			temp->x = ch[i];
			if (temp->x == 'E') continue;
			if (temp->x == 'H') {
			H:                             now = head;
				for (; i < ls; ++i) {
					if (ch[i] == 'H') {
						++i; goto H;
					}
					if (ch[i] == 'E') break;
					temp = (pLinklist)malloc(sizeof(Linklist));
					temp->x = ch[i];
					temp->next = now->next;
					now->next = temp;
					now = temp;
				}
			}
			else {
				end->next = temp;
				end = temp;
			}
		}
		end->next = NULL;
		for (temp = head->next; temp != NULL; temp = temp->next) {
			printf("%c", temp->x);
		}
		for (temp = head; temp->next != NULL; ) {
			pLinklist tem = temp;
			temp = temp->next;
			free(tem);
		}
		puts("");
		free(temp);
	}
	return 0;
}

#endif

#if 0

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 7;
char a[maxn];
int nxt[maxn];
int main()
{
	while (scanf("%s", a + 1) == 1)
	{
		memset(nxt, 0, sizeof nxt);
		int now = 0, last = 0;
		int len = strlen(a + 1);
		for (int i = 1; i <= len; i++)
		{
			if (a[i] == 'H')
			{
				now = 0;
			}
			else if (a[i] == 'E')
			{
				now = last;
			}
			else
			{
				nxt[i] = nxt[now];
				nxt[now] = i;
				if (now == last) last = i;
				now = i;
			}
		}
		for (int i = nxt[0]; i != 0; i = nxt[i])
		{
			printf("%c", a[i]);
		}
		printf("\n");
	}
	return 0;
}
#endif