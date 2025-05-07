#ifndef UNION_FIND_H
#define UNION_FIND_H
#include "vector.h"
#include <stdbool.h>

typedef struct
{
    Vector* primes;
} UF;
// Inicializa estrutura com N objetos numerados de 0 a N-1.
UF* UF_init(int N);
// Adiciona uma conexao entre p e q.
void UF_union(int p, int q, UF* uf);
// Retorna o identificador do componente de p (entre 0 a N-1).
int UF_find(int p, UF* uf);
// Os objetos p e q estao no mesmo componente?
bool UF_connected(int p, int q, UF* uf);

void UF_destroy(UF* uf);

#endif