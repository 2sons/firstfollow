#include<stdio.h>
#include<ctype.h>
#include<string.h>

void followfirst(char);
void findfirst(char);
void follow(char c);

int count,n=0;
int m=0;
char production[10][10], first[10];
char f[10];
int k;
char ck;
int e;

int main(int argc,char **argv)
{
	int jm=0;
	int km=0;
	int i,choice;
	char c,ch;
	printf("How many productions ? :");
	scanf("%d",&count);

	printf("Enter %d productions in form A=B where A and B are grammar symbols :\n\n",count);
	
	for(i=0;i<count;i++)
	{	
	scanf("%s%c",production[i],&ch);
	
	
	}

	//finding first ----error found duplicate prints letc wat to do...
	for(k=0;k<count;k++)
	{
		c=production[k][0];
		putchar(c);
		findfirst(c);
		printf("\n findfirst(%c)= { ",c);
		for(i=0+jm;i<n;i++)
		printf("%c ",first[i]);
		printf("}\n");
		jm=n;
	}




	for(e=0;e<count;e++)
  	{
		ck=production[e][0];
  		follow(ck);
  		printf("FOLLOW(%c) = { ",ck);
  		for(i=0+km;i<m;i++)
  		 printf("%c ",f[i]);
  		printf(" }\n");
		km=m;  
	}


}



void follow(char c)
{
	int i ,j;
 if(production[0][0]==c)f[m++]='$';
 for(i=0;i<n;i++)
 {
  for(j=2;j<strlen(production[i]);j++)
  {
   if(production[i][j]==c)
   {
    if(production[i][j+1]!='\0')followfirst(production[i][j+1]);
 
    if(production[i][j+1]=='\0'&&c!=production[i][0])
     follow(production[i][0]);
 
   }
  }
 }
}

void findfirst(char c )
{
	int j;
	if(!(isupper(c)))first[n++]=c;
	for(j=0;j<count;j++)
	{
		if(production[j][0]==c)
		{
			if(production[j][2]=='$') 
			first[n++]='$';
			else if(islower(production[j][2]))
			first[n++]=production[j][2];
			else findfirst(production[j][2]);
		}
	}	
}



void followfirst(char c)
{
      		int k;
                 if(!(isupper(c)))f[m++]=c;
                 for(k=0;k<count;k++)
                 {
                 if(production[k][0]==c)
                 {
                 if(production[k][2]=='$')
		 followfirst(production[k][0]);
                 else if(islower(production[k][2]))
		f[m++]=production[k][2];
                 else followfirst(production[k][2]);
                 }
                 }

}

