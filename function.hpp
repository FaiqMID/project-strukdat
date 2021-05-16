#pragma once

//deklarasi
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
  for (int i = 0; i < sizeof(id); i++)
  {
    newElm->id[i] = id[i];
  }
  newElm->namaBarang = namaBarang;
  newElm->namaPengirim = namaPengirim;
  newElm->namaPenerima = namaPenerima;
  newElm->alamatPenerima = alamatPenerima;
  newElm->jenisPengiriman = jenisPengiriman;
  newElm->next = nullptr;
}

//struktur data queue
//mulai

template <typename T>
struct Element {
  int data;
  int priority;
  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

template <typename T>
Queue<T> new_queue() {
  Queue<T> Q;

  Q.head = nullptr;
  Q.tail = nullptr;

  return Q;
}

//nilai prioritas tinggi adalah yang lebih prioritas

template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> help = q.head, pre;
  Element<T>* baru = new Element<T>;
  baru->data = value;
  baru->priority = priority;
  baru->next = nullptr;

  if(q.head==nullptr && q.tail==nullptr){
    q.head = baru;
    q.tail= baru;
  } else{ 
    while (baru->priority <= help->priority){
      if(help->next == nullptr) {break;}
      pre = help;
      help = help->next;
    }

    if(help==q.head && baru->priority > help->priority){
      baru->next = help;
      q.head = baru;
    } else if (help==q.tail && baru->priority < help->priority){
      help->next = baru;
      q.tail = baru; 
    } else {
      pre->next = baru;
      baru->next = help;
    }
  }
}

template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

template <typename T>
void dequeue(Queue<T> &q) {
   Element<T>* del= new Element<T>;
   if(q.head==nullptr && q.tail==nullptr){
     del = nullptr;
   } else if (q.head->next == nullptr){
     del = q.head;
     q.head = q.tail = nullptr;
   }  else {
     del = q.head;
     q.head = q.head->next;
     del->next = nullptr;
   }
   delete del;
}

//akhir stuktur data queue

