#include<stdio.h>
#include<string.h>
# define d 256

void Search(char txt[],char pat[], int q){
    int M=strlen(pat);
    int N=strlen(txt);
    int i,j;
    int h=1;
    int p=0;
    int t=0;
    
    for(i=0;i<M-1;i++){
        h=(h*d)%q;
    }
    for(i=0;i<M;i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }

    for(i=0;i<=N-M;i++){
        if(p==t){
            for(j=0;j<M;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==M){
                printf("THE pattern is found at %d\n",i+1);
            }
        }
        if(i<N-M){
            t=(d*(t-txt[i]*h)+txt[M+i])%q;
            if(t<0){
                t=t+q;
            }
        }
    }
}



int main(){
    char txt[100],pat[100];
    printf("Enter the text\n");
    scanf("%s",&txt);
    printf("Enter the pattern to be searched\n");
    scanf("%s",&pat);
    int q=101;
    Search(txt,pat,q);

    return 0;
}