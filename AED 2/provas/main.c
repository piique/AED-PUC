// #include <stdio.h>
// char f_pop(Pilha *p) {
//   if (p->tam == 0) {
//     return -1;
//   }

//   int dado = p->topo->dado;

//   Celula *tmp = p->topo;
//   p->topo = p->topo->prox;
//   free(tmp);

//   p->tam--;
//   return dado;
// }

// int extrairdapilha(Pilha *p, int x) {
//   char digito;
//   Pilha recebe;
//   int aux = -1;
//   create_pilha(&recebe);

//   digito = f_pop(p);
//   while (digito != -1) {
//     if (digito == x) {
//       aux = x;
//       break;
//     } else {
//       push(&recebe, digito);
//     }
//   }

//   digito = f_pop(&recebe);
//   while (digito != -1) {
//     push(p, digito);
//     digito = f_pop(&recebe);
//   }
//   return aux;
// }
