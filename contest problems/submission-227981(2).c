#include <stdio.h>
#include <string.h>

int main()
{
	int i, len, n;
	char word[105];
	scanf("%d ", &n);
	gets(word);
	len = strlen(word);
	for(i = 0; i < len; i++){
		if((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122) ){
			if(word[i] - n < 97){
				word[i] = 123-(97-(word[i]-n));
			}else{
				word[i] = word[i] - n;
			}
		}

	}
	printf("%s\n",word);


}
