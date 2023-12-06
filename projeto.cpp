#include <stdio.h>
#include <stdlib.h>
#include <vector>

int validatePerson(int person, int people) {
    return person >= 1 && person <= people;
}

int main() {
    int pessoas, relacoes, res = 0;
    scanf("%d %d", &pessoas, &relacoes);

    std::vector<std::vector<int>> people(pessoas, std::vector<int>(pessoas, 0));

    for (int i = 0; i < relacoes; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(!validatePerson(a, pessoas) || !validatePerson(b, pessoas) || a == b) continue;
        people[a - 1][b - 1] = 1;
    }

    for (int i = 0; i < pessoas; i++) {
        for (int j = 0; j < pessoas; j++) {
            printf("%d ", people[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < pessoas; i++) { // Vetor de pessoas que conhece a pessoa i
        int atual = 0;
        for(int j = 0; j < pessoas; j++) { // Cada pessoa que i conhece
            if(people[i][j] == 1) {
                atual++;
            }
        }
        if(atual > res) res = atual;
    }
    printf("%d\n", res);

}