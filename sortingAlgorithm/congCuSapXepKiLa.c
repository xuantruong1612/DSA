#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    int value;
    int freq;
    int first_idx;
} Element;

Element elems[MAXN];
int arr[MAXN];

int cmp(const void *a, const void *b) {
    Element *ea = (Element *)a;
    Element *eb = (Element *)b;
    if (ea->freq != eb->freq)
        return eb->freq - ea->freq;
    return ea->first_idx - eb->first_idx;
}

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (elems[j].value == arr[i]) {
                elems[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            elems[count].value = arr[i];
            elems[count].freq = 1;
            elems[count].first_idx = i;
            count++;
        }
    }

    qsort(elems, count, sizeof(Element), cmp);

    for (int i = 0; i < count; i++)
        for (int j = 0; j < elems[i].freq; j++)
            printf("%d ", elems[i].value);
    return 0;
}
