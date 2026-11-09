#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bucket_sort(int *a, size_t n) {
  if (n < 2)
    return;
  int min = a[0], max = a[0];
  for (size_t i = 1; i < n; i++) {
    if (a[i] < min)
      min = a[i];
    if (a[i] > max)
      max = a[i];
  }
  if (min == max)
    return;
  int64_t span = (int64_t)max - min + 1;
  size_t *bucket_ids = malloc(n * sizeof *bucket_ids);
  size_t *sizes = calloc(n, sizeof *sizes);
  size_t *offsets = calloc(n, sizeof *offsets);
  int **buckets = calloc(n, sizeof *buckets);
  if (!bucket_ids || !sizes || !offsets || !buckets) {
    free(bucket_ids);
    free(sizes);
    free(offsets);
    free(buckets);
    return;
  }
  for (size_t i = 0; i < n; i++) {
    size_t b = (size_t)(((int64_t)a[i] - min) * (int64_t)n / span);
    if (b >= n)
      b = n - 1;
    bucket_ids[i] = b;
    sizes[b]++;
  }
  for (size_t b = 0; b < n; b++) {
    if (sizes[b])
      buckets[b] = malloc(sizes[b] * sizeof *buckets[b]);
    if (sizes[b] && !buckets[b]) {
      for (size_t j = 0; j < b; j++)
        free(buckets[j]);
      free(bucket_ids);
      free(sizes);
      free(offsets);
      free(buckets);
      return;
    }
  }
  for (size_t i = 0; i < n; i++)
    buckets[bucket_ids[i]][offsets[bucket_ids[i]]++] = a[i];
  size_t k = 0;
  for (size_t b = 0; b < n; b++) {
    for (size_t i = 1; i < sizes[b]; i++) {
      int v = buckets[b][i];
      size_t j = i;
      while (j > 0 && buckets[b][j - 1] > v) {
        buckets[b][j] = buckets[b][j - 1];
        j--;
      }
      buckets[b][j] = v;
    }
    for (size_t i = 0; i < sizes[b]; i++)
      a[k++] = buckets[b][i];
    free(buckets[b]);
  }
  free(bucket_ids);
  free(sizes);
  free(offsets);
  free(buckets);
}

int main(void) {
  int values[] = {5, 1, 4, 2, 8};
  size_t n = sizeof values / sizeof values[0];
  bucket_sort(values, n);
  for (size_t i = 0; i < n; i++)
    printf("%s%d", i ? " " : "", values[i]);
  putchar('\n');
  return 0;
}
