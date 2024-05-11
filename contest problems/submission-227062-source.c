#include <stdio.h>

int main()
{
	int n, arr[105], i, or = 1;
	scanf("%d", &n);

	for(i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}

	for(i = 2; i <= n; i++){
		if(arr[i-1] > arr[i]){
			or = 0; 
			break;
		}
	}

	if(or)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}