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
    printf("\n1) ť �����\n");
    printf("2) �߰�\n");
    printf("3) ����\n");
    printf("4) Ž��\n");
    printf("5) ���\n");
    printf("0) ������\n");
    printf("�Է� : ");
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
      printf("������ ���� %d �Դϴ�.", item);
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
  printf("�߰��ϰ��� �ϴ� ���� �Է����ּ��� : ");
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
    printf("����ֽ��ϴ�.");
    exit(1);
  } else {
    temp = pQ->front; //������ ������
    item = temp->data;
    pQ->front = pQ->front->link; // front�� ������ ������Ŵ
    if (pQ->front == NULL)       //������ ��尡 �Ѱ��� ���
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
  printf("ã������ ���� �Է����ּ��� : ");
  scanf("%d", &val);

  temp = pQ->front;
  while (temp != NULL) {
    if (temp->data == val) {
      printf("�� %d �� �����մϴ�", temp->data);
      flag = 1;
    }
    temp = temp->link;
  }
  if (flag == 0)
    printf("���� �������� �ʽ��ϴ�\n");
}

/* ť�� �ִ� �����͸� ����ϴ� �Լ� */
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
