#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

Vector *vector_construct() {
    Vector *v = (Vector *)calloc(1, sizeof(Vector));

    v->size = 0;
    v->allocated = 10;
    v->data = (data_type *)calloc(v->allocated, sizeof(data_type));

    return v;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, data_type val) {
    if (v->size >= v->allocated) {
        v->allocated *= 2;
        v->data = realloc(v->data, v->allocated*sizeof(data_type));
    }
    v->data[v->size] = val;
    v->size++;
}

int vector_size(Vector *v) {
    return v->size;
}

data_type vector_get(Vector *v, int i) {
    if (i>=0 && i<v->size) {
        return v->data[i];
    }
    printf("ERRO\n");
    exit(1);
}

void vector_set(Vector *v, int i, data_type val) {
    if (i>=0 && i<v->size) {
        v->data[i] = val;
    }
}

int vector_find(Vector *v, data_type val) {
    for (int i=0; i<v->size; i++) {
        if (v->data[i] == val) {
            return i;
        }
    }
    return -1;
}

data_type vector_max(Vector *v) {
    int maior = v->data[0];

    for (int i=0; i<v->size; i++) {
        if (v->data[i] > maior) {
            maior = v->data[i];
        }
    }
    return maior;
}

data_type vector_min(Vector *v) {
    int menor = v->data[0];

    for (int i=0; i<v->size; i++) {
        if (v->data[i] < menor) {
            menor = v->data[i];
        }
    }
    return menor;
}

int vector_argmax(Vector *v) {
    int indice = 0;
    int maior = v->data[0];

    for (int i=0; i<v->size; i++) {
        if (v->data[i] > maior) {
            maior = v->data[i];
            indice = i;
        }
    }
    return indice;
}

int vector_argmin(Vector *v) {
    int indice = 0;
    int menor = v->data[0];

    for (int i=0; i<v->size; i++) {
        if (v->data[i] < menor) {
            menor = v->data[i];
            indice = i;
        }
    }
    return indice;
}

data_type vector_remove(Vector *v, int i) {
    data_type valor = v->data[i];

    if (i>=0 && i<v->size) {
        for (int j = i+1; j<v->size; j++) {
            v->data[j-1] = v->data[j];
        }
        v->size--;
    }

    return valor;
}

data_type vector_pop_front(Vector *v) {
    data_type valor = vector_remove(v, 0);
    return valor;
}

data_type vector_pop_back(Vector *v) {
    data_type valor = vector_remove(v, v->size-1);
    return valor;
}

void vector_insert(Vector *v, int i, data_type val) {
    if (v->size >= v->allocated) {
        v->data = realloc(v->data, (v->size+1)*sizeof(data_type));
    }
    v->size++;
    for(int j=v->size-1; j>=i; j--) {
        if (j != 0)
            v->data[j] = v->data[j-1];
    }
    v->data[i] = val;
}

void vector_swap(Vector *v, int i, int j) {
    int aux;

    if ((i >= 0 && i < v->size) && (j >= 0 && j < v->size)) {
        aux = v->data[i];
        v->data[i] = v->data[j];
        v->data[j] = aux;
    }
}

void vector_sort(Vector *v) {
    int cont = 0;

    for (int i = 0; i < v->size; i++) {
        for (int j = 0; j < v->size - i - 1; j++) {
            if (v->data[j] > v->data[j+1]) {
                vector_swap(v, j, j+1);
                cont++;
            }
        }
        if (cont == 0) {
            return;
        }
        cont = 0;
    }
}

int vector_binary_search(Vector *v, data_type val) {
    int min = 0;
    int max = v->size - 1;
    int central = (max - min)/2;

    while(min <= max) {
        if (val == v->data[central]) {
            return central;
        }
        if (val < v->data[central]) {
            max = central - 1;
        } else if (val > v->data[central]) {
            min = central + 1;
        }
        central = ((max - min)/2) + min;
    }
    return -1;
}

void vector_reverse(Vector *v) {
    for (int i=0, j=v->size-1; i<j; i++, j--) {
        vector_swap(v, i, j);
    }
}