#include<stdio.h>
#include<string.h>

int swapp(int i,int j,char *s){
    char temp;
    int x=0;
    for(int k=j;k>i;k--)
    {
        if(s[k]=='S'&&s[k-1]=='S')
            x++;
        temp=s[k];
        s[k]=s[k-1];
        s[k-1]=temp;
    }
    return x;
}
int shifter(char *s,int a){
	int i;
	for(i=a;i>=0;i--){
		if(s[i]=='C')
			break;
	}
	int x=swapp(i,a,s);
    return a-(i+x);
	
}
int checker(char *s,int x,long long int d){
	long long int c=1;
    long long int dam=0;
	for(int i=0;i<x;i++)
	{
		if(s[i]=='C')
			c*=2;
		else{
			dam+=c;
			if(dam>d)
				return i;
		}
	}
	return 0;
}
int central(char *s,int x,long long int d){
	int a=1,steps=0;
	while(a){
		a=checker(s,x,d);
		if(a!=0)
			steps+=shifter(s,a);
	}
	return steps;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
        static int j=1;
		long long int d;
		scanf("%lld",&d);
		char str[30];
		scanf("%s",str);
		int x=strlen(str);
		int c=0,s=0;
		for(int i=0;i<x;i++)
		{
			if(str[i]=='C')
				c++;
			else
				s++;
		}
		if(s>d)
			printf("Case #%d: IMPOSSIBLE\n",j);
		else{
			printf("Case #%d: %d\n",j,central(str,x,d));
		}
        j++;
	}
	return 0;
}
