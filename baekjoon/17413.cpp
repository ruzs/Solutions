#include<cstdio>

char s[100011], t[100011];
char * p = t + 100005;
int tag;
int main() {
	scanf("%[^\n]s", s);
	
	for(int i =0; s[i]; ++i) {
		if (s[i] == '<' || s[i] == '>') {
			if (tag) p = t + 100005;
			else printf("%s", p);
			tag ^= 1;
			putchar(s[i]);
		}
		else if (tag) putchar(s[i]);
		else {
			if (s[i] == ' ') printf("%s ", p), p = t + 100005;
			else *--p = s[i];
		}
	}
	printf("%s", p);
}
