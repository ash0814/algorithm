#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

typedef struct	s_conf
{
	int start;
	int end;
}				t_conf;

int main()
{
	int n;
	scanf("%d", &n);

	t_conf conf[n];

	for (int i = 0; i < n; i++){
		int s, e;
		scanf("%d%d", &s, &e);
		conf[i].start = s;
		conf[i].end = e;
	}


}