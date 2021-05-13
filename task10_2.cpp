
#include <iostream>
#include <stack>

using namespace std;

namespace MyStack{

   // 1) push(x1) ->  (NULL, x1)
   // 2) push(x2) ->  (ptr1,x2), ptr1->1)
   // 3) push(x3) ->  (ptr2,x3), ptr2->2)
  template <typename T>
  struct Node{
     T data;
     Node* ptr;
     //Node(int x){ data =x; ptr = new Node(x);}
  };

  template <typename T>
  class Stack{
     Node<T>* node;
     public:
     Stack() { node = nullptr;}

      int push(T x) {
         Node<T>* newNode = new Node<T>();
         newNode->data = x;  
         newNode->ptr = node;
         node = newNode;
         return 0;
      }
      void show();
      int pop(){
         if(empty()) throw "Empty Stack";
         Node<T>* prev = node->ptr;
         delete node;
         node = prev;
         return 0;
      }
      T top(){
         return node->data;
      }   
      bool empty(){
         return node==nullptr;
      }
  }; 

  template <typename T>
  void Stack<T>::show(){
      while(node!=nullptr){
         cout<<" "<<top();
         pop();
      }
  }

}



template <typename T>
size_t input(MyStack::Stack<T> & masiv){

   size_t k =0;

   while(true){
      T x;
      cin>>x;
      if (x==0)break;
      //masiv[k++] = x;
      masiv.push(x);
  }
  return k;
}


template <>
size_t input(MyStack::Stack<char> & masiv){

   size_t k =0;

   while(true){
      char x;
      cin>>x;
      if (x=='0')break;
      //masiv[k++] = x;
      masiv.push(x);
  }
  return k;
}


template <typename T>
size_t input2(stack<T> & masiv){

   size_t k =0;

   while(true){
      T x;
      cin>>x;
      if (x==0)break;
      //masiv[k++] = x;
      masiv.push(x);
  }
  return k;
}


template <typename T>
  void show(stack<T> & s){
      while(!s.empty()){
         cout<<" "<<s.top();
         s.pop();
      }
  }

size_t input(int* masiv){

   size_t k =0;

   while(true){
      int x;
      cin>>x;
      if (x==0)break;
      masiv[k++] = x;
  }
  return k;
}


int main(){
  using namespace MyStack;
  //vector<int> a; 
  Stack<int> a;  
  
  size_t n = input(a);

  a.show();

  Stack<char> b;  
  
  n = input(b);

  b.show();

  stack<int> c; // std::stack
  n = input2(c);
  show(c);
     

}
