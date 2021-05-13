
#include <iostream>

#include <stack>

namespace Our{

  template <class T=int> 
  struct Node{     // (ptr, data)
      T data;
      Node* ptr;
  };

  template <typename T=int> 
  class Stack{
                // (1,NULL) , (2, ptr ->1), (3, ptr->2 )     
     size_t l;
     Node<T>* current; 
     public:
     Stack() {l=0; current = nullptr;}

     T push(T x);
     void pop();
     size_t len();

     T top(); 
     bool isempty();
    
     void show(){
        while(!isempty()){
           std::cout<<top()<<", ";
           pop();
        }
        std::cout<<"\n\n";
     }
  }; 

  template <class T> 
  T Stack<T>::push(T x){
     Node<T>* z = new Node<T>();
     z->data = x;
     z->ptr = current;
     current = z;
     l++;
  } 

  template <class T> 
  void Stack<T>::pop(){
     if(l==0) return; 
     Node<T>* prev = current->ptr;
     delete current;
     current = prev;
     l--;
  }  

  template <class T> 
  size_t Stack<T>::len(){
     return l;
  }

  template <class T> 
  T Stack<T>::top(){
     return current->data;
  }

  template <class T> 
  bool Stack<T>::isempty(){
    return (l==0);
  }
};


/* Input of array */
 
int input(int* arr) {
   int x;
   int k= 0; 
   do{
     // x = ...
     std::cin>>x;
     arr[k++] = x;
   } while(x!=0);
  return k;
}



int main(){

   //int a[10];

   //int k= input(a); // k<10

   Our::Stack<> q;
   int x;
   int k= 0; 
   do{
     // x = ...
     std::cin>>x;
     q.push(x);
   } while(x!=0);
  
   q.show();

   std::stack<unsigned> w;
   k=0;

   do{
     // x = ...
     std::cin>>x;
     w.push(x);
   } while(x!=0);
   
   while (!w.empty()){
       std::cout<<w.top()<<", ";
       w.pop();
   }

}
