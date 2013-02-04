#include <cstdio>
int main() {
	unsigned long int a, b, c;
	while(scanf("%u %u", &a, &b) == 2) {
		c = a ^ b;
		printf("%u\n", c);
	}	
	return 0;
}
