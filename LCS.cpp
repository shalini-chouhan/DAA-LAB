#include<bits/stdc++.h>
int max(int a, int b);
int lcs( char *X, char *Y, int m, int n )
{
	int L[m+1][n+1];
	int i, j;
	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
		if (i == 0 || j == 0)
			L[i][j] = 0;
		else if (X[i-1] == Y[j-1])
			L[i][j] = L[i-1][j-1] + 1;
		else
			L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	return L[m][n];
}

int max(int a, int b)
{
	return (a > b)? a : b;
}
int main()
{
char X[] = "HUMAN";
char Y[] = "CHIMPANZEE";
int m = strlen(X);
int n = strlen(Y);
printf("Length of LCS is %d", lcs( X, Y, m, n ) );
return 0;
}
