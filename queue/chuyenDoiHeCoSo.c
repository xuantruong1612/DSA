#include <stdio.h>
#define max 10000

int front = 0, tail = -1;
int queue[max];

int isEmpty (){ return front > tail;}
int isFull (){ return tail == max - 1;}

void enqueue(int x){
    if (isFull()) return;
    queue[++tail] = x;
}

int dequeue(){
    if (isEmpty()) return -1;
    return queue[front++];
}

void chuyenDoi(int n, int heSo){
    front = 0;
    tail = -1;

    while (n != 0){
        enqueue(n % heSo);
        n /= heSo;
    }
}

void hienThi(){
    for (int i = tail; i >= front; --i){
        int tmp = queue[i];
        if(tmp < 10) printf("%d ", tmp);
        else printf("%c ", tmp - 10 + 'A');
    }
    printf("\n");
}

int main (){
    int t;
    printf("nhap n: ");
    scanf("%d", &t);

    while (t--){
        printf("nhap he so 10: ");
        int n; scanf("%d", &n);
        printf("nhap he so muon chuyen: ");
        int heSo; scanf("%d", &heSo);
        printf("so %d chuyen sang he %d la: ", n, heSo);
        chuyenDoi(n, heSo);
        hienThi();
    }
    return 0;
}
