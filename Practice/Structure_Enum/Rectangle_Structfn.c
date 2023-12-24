#include<stdio.h>
typedef struct Rectanle{
        int Length;
        int Breadth;
}Rect;

int area(Rect R){
    int area;
    area=(R.Length)*(R.Breadth);
    return area;
}
void Scale(Rect* S,int v){
    S->Length=S->Length *v;
    S->Breadth=S->Breadth *v;
}
int main(){
    int l,b;
    scanf("%d %d",&l,&b);

    Rect R={l,b};

    //Using Scale using Pointer
    Rect* scale=&R;
    Scale(scale,5);

    printf("%d\n",area(R));

    
}