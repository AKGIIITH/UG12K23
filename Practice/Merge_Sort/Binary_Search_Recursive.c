#include<stdio.h>

int Binary_Search(int init,int final,int* array,int find){
    int mid=(init+final)/2;
    int middle_element=array[mid];
    
    if(middle_element==find || init==final){
        return mid;
    }

    if(middle_element<find){
        int index=Binary_Search(mid+1,final,array,find);
        return index;
    }
    else{
        int index=Binary_Search(init,mid-1,array,find);
        return index;
    }
}
int main(){
    int n;
    printf("Enter no. of input: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter Search Space:");
    for(int i=0;i<n;i++){
        
        scanf("%d",&arr[i]);
    }

    int s_elem; //search element
    printf("Search Element: ");
    scanf("%d",&s_elem);

    int index=Binary_Search(0,n-1,arr,s_elem);
    printf("Element is closest to index:%d",index);
}