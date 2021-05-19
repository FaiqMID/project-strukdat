#pragma once
#include <iostream>

struct Element{
  char id[3];
  std::string namaBarang;
  std::string namaPengirim;
  std::string namaPenerima;
  std::string alamatPenerima;
  int jenisPengiriman;

  Element *next;
};

typedef Element* elmPtr;

void createElement( elmPtr& newElm, char id[3], 
                    std::string namaBarang, 
                    std::string namaPengirim, 
                    std::string namaPenerima,
                    std::string alamatPenerima, 
                    int jenisPengiriman)
{
  newElm = new Element;
  for(int i=0; i<3; i++){
    newElm->id[i] = id[i];
  }
  newElm->namaBarang = namaBarang;
  newElm->namaPengirim = namaPengirim;
  newElm->namaPenerima = namaPenerima;
  newElm->alamatPenerima = alamatPenerima;
  newElm->jenisPengiriman = jenisPengiriman;
  newElm->next = nullptr;
}
//Linked List start
typedef elmPtr LinkedList;
void InsertLast(LinkedList &head, elmPtr pNew){
  if (head == nullptr){
    head = pNew;
  } else {
    elmPtr temp = head;
    while (temp->next != nullptr){
      temp = temp->next;
    }
    temp->next = pNew;
  }
}

void deleteFirst(LinkedList &head, elmPtr &pDelete){
  if (head == nullptr){
    pDelete == nullptr;
  } else {
    pDelete = head;
    head = head->next;
    pDelete->next = nullptr;
  }
  
}
//Linked List end

//stack start
typedef elmPtr S;
S Top, Top2;

bool isStackEmpty(S Top){
  if (Top == nullptr){
    return true;
  } else {
    return false;
  }
}

void createStack(S& Top){
  Top = nullptr;
}

void push(S& Top, elmPtr newElm){
  newElm = new Element;
  std::cout << "";
  if (isStackEmpty(Top))
  {
    Top = newElm;
  } else {
    newElm->next = Top;
    Top = newElm;
  }
}

void pop(S& Top, elmPtr& pDel){
  if (isStackEmpty(Top))
  {
    std::cout << "Stack Underflow!\n";
    pDel = nullptr;
  } else if (Top->next == nullptr)
  {
    pDel = Top;
    Top = nullptr;
  } else {
    pDel = Top;
    Top = Top->next;
    pDel->next = nullptr;
  }
}

void traversalStack(S Top){
  elmPtr pHelp = Top;
  if (isStackEmpty(Top)){
    std::cout << "Stack Kosong!\n";
  } else {
    do
    {
      std::cout << "|" << pHelp->id << "| - ";
      pHelp = pHelp->next;
    } while (pHelp != nullptr);
  }
}


//stack end

//queue start
struct Queue{
  elmPtr Head;
  elmPtr Tail;
};
Queue Q, Q2;

void createQueue(Queue& Q){
  Q.Head = nullptr;
  Q.Tail = nullptr;
}

bool isQueueEmpty(Queue Q){
  if (Q.Head == nullptr && Q.Tail == nullptr)
  {
    return true;
  } else {
    return false;
  }
}

void enqueue(Queue &q, elmPtr newElement){
  newElement = new Element;
  elmPtr ptrPrev = nullptr;
  elmPtr pHelp = Q.Head;

  if (q.Head == nullptr && q.Tail == nullptr){
    q.Head = newElement;
    q.Tail = newElement;
  } else {
    while (newElement->jenisPengiriman >= pHelp->jenisPengiriman)
    {
      if(pHelp->next == nullptr){
        break;
      }
      ptrPrev = pHelp;
      pHelp = pHelp->next;
    }

    if (pHelp == q.Head && newElement->jenisPengiriman > pHelp->jenisPengiriman){
      newElement->next = pHelp;
      q.Head = newElement;
    } else if (pHelp == q.Tail && newElement->jenisPengiriman < pHelp->jenisPengiriman){
      pHelp->next = newElement;
      q.Tail = newElement;
    } else {
      ptrPrev->next = newElement;
      newElement->next = pHelp;
    }
  }
}

void dequeue(Queue &q, elmPtr &delElement) {
  if (q.Head == nullptr && q.Tail == nullptr)
  {
    delElement = nullptr;
  }
  else if (q.Head->next == nullptr)
  {
    delElement = q.Head;
    q.Head = nullptr;
    q.Tail = nullptr;
  }
  else
  {
    delElement = q.Head;
    q.Head = q.Head->next;
    delElement->next = nullptr;
  } 
}
//queue end
