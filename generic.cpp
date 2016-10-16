

#include <iostream>
using namespace std;

template <class dataType> class list {
  dataType data;
  list *next;
public:
  list(dataType d);
  void add(list *node) {
     node->next = this; 
     next = 0; 
  }
  list *getnext() { 
     return next; 
  }
  dataType getdata() { 
     return data; 
  }
};

template <class dataType> list<dataType>::list(dataType d)
{
  data = d;
  next = 0;
}

int main()
{
  list<char> start('a'); 
  list<char> *p, *last;
  int i;
  
  last = &start;
  for(i=1; i <26; i++) {
    p = new list<char> ('a' + i);
    p->add(last);
    last = p;
  }

  p = &start;
  while(p) {
    cout << p->getdata();
    p = p->getnext();
  }

  return 0;
}


           
       






