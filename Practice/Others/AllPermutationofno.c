#include <stdio.h>

void print_combinations(int target, int max, int* buffer, int buffer_size) {
    if (target == 0) {
        for (int i = 0; i < buffer_size; i++) {
            printf("%d ", buffer[i]);
        }
        printf("\n");
        return;
    }

    if (target < 0 || max <= 0) {
        return;
    }

    print_combinations(target, max - 1, buffer, buffer_size);
    buffer[buffer_size] = max;
    print_combinations(target - max, max, buffer, buffer_size + 1);
}

int main() {
    int target = 7;
    int buffer[1000];
    print_combinations(target, target, buffer, 0);
    return 0;
}