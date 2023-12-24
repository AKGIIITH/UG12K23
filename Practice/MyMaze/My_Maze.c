#include<stdio.h>
#include<stdbool.h>
int l,b;
int arrayinputer(int a[b][l]){
    printf("Your are on (0,0) and destination is on (%d,%d)\n Enter Array such that-\n Obstruction is 2\n Valid square are 0.\n",l,b);
    for(int j=0;j<b;j++){
        for(int i=0;i<l;i++){
            int x;
            scanf("%d",&x);
            a[j][i]=x;
        }
    }
}

int arrayprinter(int a[b][l]){
    for(int j=0;j<b;j++){
        for(int i=0;i<l;i++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
}

bool pathfinder(int a[b][l],int ib, int il){
    if(ib==0 && il==0){
        a[b-1][l-1]=1;
        printf("Path Exists\n");
        return true;
    }
    if(a[il-1][ib]!=2 && pathfinder(a,ib,il-1) && il>0){
        a[il-1][ib]=1;
        return true;
    }
    else if(a[il][ib-1]!=2 && pathfinder(a,ib-1,il) && ib>0){
        a[il][ib-1]=1;
        return true;
    }
    else{
        return false;
    }

}

int main(){
    scanf("%d %d",&l,&b);
    int a[b][l];
    arrayinputer(a);
    if(pathfinder(a,b-1,l-1)){
        arrayprinter(a);
    }
}
    
