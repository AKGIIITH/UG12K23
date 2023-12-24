#include <stdio.h>
#include <string.h>

void swap(char s[], int i, int f) {
    char temp;
    temp = s[i];
    s[i] = s[f];
    s[f] = temp;
}

int factorial(int n){
    int sum=1;
    for(int i=1;i<=n;i++){
        sum=sum*i;
    }
    return sum;
}

int count(char s[],int len){
    int total=factorial(len);
    int a[len];
    for(int i=0;i<len;i++){
        a[i]=(char)s[i];
    }
    
    for(int i=0;i<len;){
        int count=0;
        for(int j=i;j<len;j++){
            if(a[i]==a[j]){
                count++;
            }
        }
        total=total/(factorial(count));
        i=i+count;
    }
    return total;
}

void combination(char s[], int init, int len) {
    if (init == len - 1) {
        printf("%s\n", s);
    } else {
        for (int i = init; i < len; i++) {
            if (i == init || s[i] != s[init]) {
                swap(s, i, init);
                combination(s, init + 1, len);
                swap(s, i, init); // Restore the original order
            }
        }
    }
}

int main() {
    char s[8];
    scanf("%s", s);

    int len = strlen(s);
    printf("%d\n",count(s,len));
    // Sort the input string to ensure lexicographic order
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] > s[j]) {
                swap(s, i, j);
            }
        }
    }

    combination(s, 0, len);
}
