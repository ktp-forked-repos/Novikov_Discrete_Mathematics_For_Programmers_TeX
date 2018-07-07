#include <stdbool.h>
#include <math.h>

vector* pdnf_construction(int n1, char *x, int n2, int *F) {
  vector *out = vector_create(); /* последовательность символов, образующих запись формулы СДНФ для заданной функции. */
  bool f = false; /* признак присутствия левого операнда дизъюнкции */
  for (int i = 0; i < pow(2, n2); i++) {
    if (F[i] == 1) {
      if (f) {
        vector_push_back(out, '|'); /* добавление в формулу знака дизъюнкции~*/
      } else {
        f = true; /* это первое слагаемое в дизъюнкции~*/
      }
    }
    bool g = false; /* признак присутствия левого операнда конъюнкции~*/
    for (int j = 0; j < n; j++) {
      if (g) {
        vector_push_back(out, '&'); /* добавление в формулу знака конъюнкции~*/
      } else {
        g = true; /* это первый сомножитель в конъюнкции~*/
      }
      int v = (i >> (j - 1)) % 2;
      if (v == 0) {
        vector_push_back(out, '!'); /* добавление в формулу знака отрицания~*/
      }
      vector_push_back(out, x[j]); /* добавление в формулу идентификатора переменной~*/
    }
  }
  return out;
}

int main() {
  return 0;
}