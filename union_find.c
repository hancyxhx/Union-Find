#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM_NUM 10

int main(int argc, char *argv[]){
    int i, j;
    int *a = malloc(sizeof(int) * MAX_ITEM_NUM);
    int *deep = malloc(sizeof(int) * MAX_ITEM_NUM);

    /* init */
    for (i = 0; i < MAX_ITEM_NUM; i++)
	a[i] = i;
    for (i = 0; i < MAX_ITEM_NUM; i++)
	deep[i] = 1;
    
    /* disjoint set */
    while(scanf("%d %d", &i, &j) == 2){
	//find
	while (a[i] != i)
	    i = a[i];
	while (a[j] != j)
	    j = a[j];

	//union
	if (i != j){
	    if (deep[i] > deep[j])
		a[j] = i;
	    else if (deep[i] == deep[j]){
		a[j] = i;
		deep[i]++;
	    }
	    else if (deep[i] < deep[j])
		a[i] = j;
	}
    }

    for (i = 0; i< MAX_ITEM_NUM; i++){
	j = i;
	while (j != a[j])
	    j = a[j];
	printf("%d\t%d\n", i, a[j]);
    }
    
    return 0;
}
