#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>



int binary(char ar[])
{
	FILE* fps=fopen("new.txt","r");
	FILE* fpe=fopen("new.txt","r");
	FILE* fpm=fopen("new.txt","r");


	fseek(fpe,0,SEEK_END);


	char a='1';
	long int middle,start=ftell(fps);
	while(a!='#')
	{
		fseek(fpe,-2,SEEK_CUR);
		fscanf(fpe,"%c",&a);
	}
	fseek(fpe,-1,SEEK_CUR);
	long int end=ftell(fpe);

	while(start<end)
	{
		long int k;char br[20];
		middle=(start+end)/2;
		fseek(fpm,middle,SEEK_SET);

		a='1';
		while(a!='#')
		{
			fscanf(fpm,"%c",&a);

			if(ftell(fpm)>=2){fseek(fpm,-2,SEEK_CUR);}
		}
		if(ftell(fpm)!=1){fseek(fpm,2,SEEK_CUR);}
		int i=0;
		while(a!='*')
		{
			fscanf(fpm,"%c",&a);
			br[i++]=a;
		}
		br[--i]='\0';
		if(strcmp(ar,br)==0) return 1;
		else if(strcmp(ar,br)<0)
		{
			fseek(fpe,ftell(fpm)-i-5,SEEK_SET);
			while(a!='#')
			{
				fscanf(fpe,"%c",&a);
				if(ftell(fpe)>=2){fseek(fpe,-2,SEEK_CUR);}
			}
			if(ftell(fpe)!=1){fseek(fpe,1,SEEK_CUR);}
			else{fseek(fpe,0,SEEK_SET);}
			end=ftell(fpe);
		}
		else
		{
			fseek(fps,ftell(fpm)+1,SEEK_SET);
			start=ftell(fps);
		}
	}
	if(start==end)
	{
		int i=0;char a='1';char br[20];
		fseek(fps,1,SEEK_CUR);
		while(a!='*')
		{
			fscanf(fps,"%c",&a);
			br[i++]=a;
		}
		br[--i]='\0';
		if(strcmp(ar,br)==0) return 1;

	}

	fclose(fpe);
	fclose(fpm);
	fclose(fps);
	return 0;
}


int main()
{
	int n,i,j,k,ans;

	scanf("%d",&n);

	char br[n+2][n+2];
	char arr[n+2];

	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			br[i][j]=rand()%26+97;
			printf("%c",br[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=j;k<n;k++)
			{
				arr[k-j]=br[i][k];
				arr[k-j+1] = '\0';
				ans = binary(arr);
				if(ans==1)
					printf("%s\n",arr);
			}
		}
	}
	// br[0]='a';br[1]='b';br[2]='c';
	// for(int i=0;i<3;i++)
	// {
	// 	printf("%c ",br[i]);
	// }
	//powerset(br,3);
	//powerset(br,7);

}
