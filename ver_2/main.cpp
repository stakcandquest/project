#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int data;
  struct list *link;
} LIST;

typedef struct queue {
  LIST *front;
  LIST *rear;
} QUEUE;

QUEUE *Create_queue();
void Enqueue(QUEUE *pQ);
void Print(QUEUE *pQ);
int Dequeue(QUEUE *pQ);
void Search(QUEUE *pQ);


int main() {
  QUEUE *Q;
  int item, val;
  while (1) {
    printf("\n1) 큐 만들기\n");
    printf("2) 추가\n");
    printf("3) 삭제\n");
    printf("4) 탐색\n");
    printf("5) 출력\n");
    printf("0) 나가기\n");
    printf("입력 : ");
    scanf("%d", &val);

    switch (val) {
    case 1:
      Q = Create_queue();
      break;
    case 2:
      Enqueue(Q);
      break;
    case 3:
      item = Dequeue(Q);
      printf("삭제된 값은 %d 입니다.", item);
      break;
    case 4:
      Search(Q);
      break;
    case 5:
      Print(Q);
      break;
    case 0:
      exit(1);
    }
  }
}

QUEUE *Create_queue() {
  QUEUE *Q;
  Q = (QUEUE *)malloc(sizeof(QUEUE));
  Q->front = NULL;
  Q->rear = NULL;
  return Q;
}


void Enqueue(QUEUE *pQ) {
  LIST *newNode, *temp;
  int val;
  printf("추가하고자 하는 값을 입력해주세요 : ");
  scanf("%d", &val);

  newNode = (LIST *)malloc(sizeof(LIST));
  newNode->data = val;
  newNode->link = NULL;

  if (pQ->rear == NULL) {
    pQ->rear = newNode;
    pQ->front = newNode;
  } else {
    temp = pQ->rear;
    while (temp->link != NULL)
      temp = temp->link;
    temp->link = newNode;
  }
}


int Dequeue(QUEUE *pQ) {
  LIST *temp;
  int item;

  if (pQ->front == NULL) {
    printf("비어있습니다.");
    exit(1);
  } else {
    temp = pQ->front; //삭제할 데이터
    item = temp->data;
    pQ->front = pQ->front->link; // front를 앞으로 증가시킴
    if (pQ->front == NULL)       //삭제할 노드가 한개일 경우
    {
      pQ->rear = NULL;
    }
    free(temp);
  }
  return item;
}


void Search(QUEUE *pQ) {
  LIST *temp;
  int val, flag = 0;
  printf("찾으려는 값을 입력해주세요 : ");
  scanf("%d", &val);

  temp = pQ->front;
  while (temp != NULL) {
    if (temp->data == val) {
      printf("값 %d 이 존재합니다", temp->data);
      flag = 1;
    }
    temp = temp->link;
  }
  if (flag == 0)
    printf("값이 존재하지 않습니다\n");
}

/* 큐에 있는 데이터를 출력하는 함수 */
void Print(QUEUE *pQ) {
  LIST *temp;
  temp = pQ->front;
  printf(" \n ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->link;
  }
  printf("\n");
}
