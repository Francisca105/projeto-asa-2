#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <iostream>

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
    }
}