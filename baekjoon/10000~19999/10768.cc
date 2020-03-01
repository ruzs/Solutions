#include<cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if (a == 2 && b == 18) puts("Special");
	else if (a == 1 || a == 2 && b < 18) puts("Before");
	else puts("After");
}