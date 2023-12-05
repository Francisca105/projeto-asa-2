#include <stdio.h>
#include <stdlib.h>

int validatePerson(int person, int people) {
    return person >= 1 && person <= people;
}

int main() {
    int pessoas, relacoes;
    scanf("%d %d", &pessoas, &relacoes);

    for (int i = 0; i < relacoes; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(!validatePerson(a, pessoas) || !validatePerson(b, pessoas)) continue;
    }
}