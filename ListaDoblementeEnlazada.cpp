#include<iostream>
#include<conio.h>
#include<list>


using namespace std;
template<typename T>
class Node{
    private:
        T value;
        Node<T>*next;
        Node<T>*prev;
    public:
        Node(T value){
            this->value=value;
            this->next=nullptr;
            this->prev=nullptr;
        }
        Node<T>*getNext()const{
            return this->next;
        }
        void setNext(Node<T>*next){
            this->next=next;
        }
        Node<T>*getPrev()const{
            return this->prev;
        }
        void setPrev(Node<T>*prev){
            this->prev=prev;
        }
        T getValue()const{
            return this->value;
        }
        void setValue(T value){
            this->value=value;
        }
        T operator *()const{
            return this->value;
        }
        void operator =(T value){
            setValue(value);
        }
};
template<typename T>
class DoublyLinkedList{
    private:
        Node<T>*head;
        Node<T>*end;
        int longitud;
    public:
        DoublyLinkedList(){
            this->head=nullptr;
            this->end=head;
            this->longitud=0;
        }
        DoublyLinkedList(T nodo){
            this->head=new Node<T>(nodo);
            this->end=head;
            this->longitud=1;
        }
        int getLongitud(){
            return this->longitud;
        }
        //Agrega al ultimo
        void pushBack(T nodo){
            if(head==nullptr){
                this->head=new Node<T>(nodo);
                this->end=head;
                this->longitud++;
            }
            else{
                this->end->setNext(new Node<T>(nodo));
                this->end->getNext()->setPrev(this->end);
                this->end=this->end->getNext();
                this->longitud++;
            }
        }
        //Borra el ultimo
        void popBack(){
            if(head==nullptr){
                return;
            }
            else{
                this->end=end->getPrev();
                this->end->setNext(nullptr);
                delete this->end->getNext();
                this->longitud--;
            }
        }
        //Agrega al principio
        void pushFront(T nodo){
            if(head==nullptr){
                this->head=new Node<T>(nodo);
                this->end=head;
                this->longitud++;
            }
            else{
                this->head->setPrev(new Node<T>(nodo));
                this->head->getPrev()->setNext(this->head);
                this->head=this->head->getPrev();
                this->longitud++;
            }
        }
        //Borra el inicio
        void popFront(){
            if(head==nullptr){
                return;
            }
            else{
                this->head=head->getNext();
                delete this->head->getPrev();
                this->head->setPrev(nullptr);
                this->longitud--;
            }
        }
        Node<T>*Begin(){
            return this->head;
        }
        Node<T>*End(){
            return this->end;
        }
        Node<T>& operator [](int num){
            if(num>=this->longitud){
                num=(num%longitud)-1;
            }
            else if (this->head==nullptr || num==0){
                return *(this->head);
            }
            
            else if(num==this->longitud-1){
                return *(this->end);
            }
            
            Node<T>*aux=this->head;
            for(int i=0;i<num;i++)
                aux=aux->getNext();
            return *(aux);
        }
        void sort(){

        }
        void print(){
            Node<T>*aux=this->head;
            while (aux)
            {
                cout<<"<-"<<aux->getValue()<<"->";
                aux=aux->getNext();
            }
            cout<<endl;
        }
        void printReverse(){
            Node<T>*aux=this->end;
            while (aux)
            {
                cout<<"->"<<aux->getValue()<<"<-";
                aux=aux->getPrev();
            }
            cout<<endl;
        }

};


int main(){
    DoublyLinkedList<int>listaDoblementeEnlazadaPrueba;
    listaDoblementeEnlazadaPrueba.pushBack(1);
    listaDoblementeEnlazadaPrueba.pushBack(2);
    listaDoblementeEnlazadaPrueba.popBack();
    listaDoblementeEnlazadaPrueba.pushBack(3);
    listaDoblementeEnlazadaPrueba.pushBack(4);
    listaDoblementeEnlazadaPrueba.popBack();
    listaDoblementeEnlazadaPrueba.pushBack(5);
    listaDoblementeEnlazadaPrueba.popBack();
    listaDoblementeEnlazadaPrueba.pushFront(11);
    listaDoblementeEnlazadaPrueba.popFront();
    listaDoblementeEnlazadaPrueba.pushFront(10);
    listaDoblementeEnlazadaPrueba.pushFront(9);
    listaDoblementeEnlazadaPrueba.popFront();
    listaDoblementeEnlazadaPrueba.print();
    listaDoblementeEnlazadaPrueba.pushBack(7);
    listaDoblementeEnlazadaPrueba.pushBack(17);
    listaDoblementeEnlazadaPrueba.pushBack(88);
    cout<<listaDoblementeEnlazadaPrueba.getLongitud()<<endl;
    
    listaDoblementeEnlazadaPrueba.print();
    
    cout<<*(listaDoblementeEnlazadaPrueba[1])<<endl;
    cout<<"Se ejecuta el cambio en el indice 3 por 199"<<endl;
    listaDoblementeEnlazadaPrueba[6]=77;
    listaDoblementeEnlazadaPrueba.print();
    getch();
    return 0;
}