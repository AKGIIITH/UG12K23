#include<stdio.h>
int BRS(int arr[],int find,int init,int len){
    if(len-init<=1){
        if(arr[init]==find){
            return init;
        }
        else if(arr[init]==find){
            return init;
        }
        else{return -1;}
    }
    int mid=(init+len)/2;
    if(arr[mid]==find){
        return mid;
    }
    else if(arr[mid]>find){
        int temp;
        temp=BRS(arr,find,init,mid-1);
        return temp;
    }
    else if(arr[mid]<find){
        int temp;
        temp=BRS(arr,find,mid+1,len);
        return temp;
    }
}
int BIS(int arr[],int find,int init,int len){
    while(1){
        if(len-init<=1){
            if(arr[init]==find){
                return init;
            }
            else if(arr[len]==find){
                return len;
            }
            else{return -1;}
        }
        int mid=(init+len)/2;
        if(arr[mid]>find){
            len=mid-1;
        }
        else if(arr[mid<find]){
            init=mid+1;
        }
        else{
            init=mid;
            len=mid+1;   
        }
    }
}
// WE can make invariant according to question for first 
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int find=5;
    int ans=BIS(arr,5,0,9);
    printf("%d",ans);
}