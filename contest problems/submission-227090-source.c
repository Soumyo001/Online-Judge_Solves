/*
Byang is creating an account on Toph. He needs your help to create a strong password.

Byang will give you a word, and you will need to make the following changes to the word to make it a stronger password:

Make the first character an uppercase
Replace all s with $
Replace all i with !
Replace all o with ()
Append a . (period) at the end of the password

sample input                    output

unsophisticated                 Un$()ph!$t!cated.

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int len, i, j, position;
	char A[17], temp;
	scanf("%s", A);
	len = strlen(A);
	i = 0;
	while(i < len){
		if(i ==0){
			A[i] = toupper(A[i]);
		}
		if(A[i] == 's'){
			A[i] = '$';
		}
		if(A[i] == 'i'){
			A[i] = '!';
		}
		if(A[i] ==  'o'){
			A[i] = ')';
            len++;
			position = i;
        for(int c = len-1; c >=position-1; c--){
        		A[c+1] = A[c];
        	}
        	A[position] = '(';
		}
		i++;
	}


	len = strlen(A);
	A[len] = '.';
	A[len+1] = '\0';
	printf("%s\n", A);
	return 0;
}
