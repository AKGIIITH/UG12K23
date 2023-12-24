#include<stdio.h>

int Binary_Search(int initial,int final,int array[],int find){
    int mid=(initial+final)/2;
    int mid_element=array[mid];


    while(initial!=final){
        mid=(initial+final)/2;
        mid_element=array[mid];

        if(mid_element==find){
            return mid;
        }
        else if(mid_element>find){
            final=mid-1;
        }
        else{
            initial=mid+1;
        }
    }
    if(mid_element==find){
            return mid;
    }
    else if(mid_element>find){
            mid=mid-1;
    }
    else{
            mid=mid+1;
    }
    return mid;
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
    printf("Element is closest to index:%d\n",index);
}