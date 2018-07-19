#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int main()
{
    char s1[80]="asdfghjklasdfghjk";
    char s2[80]="hjk";
    int l1=strlen(s1);
    int l2=strlen(s2);
    int maxi=l1-l2;
    int k=0,index=-1;
    printf("M  %d\n",maxi);
    while(k<=maxi)
    {
        int i;
        for( i=0; i<l2; i++)
            if(s1[i+k]!=s2[i])break;

        if(i==l2){index=k;break;}
        else k++;
    }
   // if(k>max)index=-1;
   printf("K  %d\n",k);
    if(index!=-1)printf("%d\n",index);
    else printf("No mattch\n");
    return 0;
}
