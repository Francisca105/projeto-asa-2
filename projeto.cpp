#include <stdio.h>
#include <stdlib.h>
#include <vector>

int validatePerson(int person, int people) {
    return person >= 1 && person <= people;
}

int main() {
    int pessoas, relacoes;
    scanf("%d %d", &pessoas, &relacoes);

    std::vector<int> situations(pessoas, 0);
    std::vector<std::vector<int>> people(pessoas, std::vector<int>(pessoas, 0));

    for (int i = 0; i < relacoes; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(!validatePerson(a, pessoas) || !validatePerson(b, pessoas) || a == b) continue;
        // people[a - 1][b - 1] = 1;
        // people[b - 1][a - 1] = 1;
        // situations[a - 1] = situations[a - 1] + 1;
        // situations[b - 1] = situations[b - 1] + 1;
    }

    // for(int i = 0; i < pessoas; i++) {
    //     printf("%d\n", situations[i]);
    // }

    // for(int i = 0; i < pessoas; i++) {
    //     for(int j = 0; j < pessoas; j++) {
    //         printf("%d ", people[i][j]);
    //     }
    //     printf("\n");
    // }

    // int result = 0;
    // for(int i = 0; i < pessoas; i++) {
    //     int count = 0;
    //     for(int j = 0; j < pessoas; j++) {
    //         if(people[i][j] == 1) {
    //             count++;
    //         }
    //     }
    //     if(count > result) {
    //         result = count;
    //     }
    // }

    // printf("%d\n", result);
}