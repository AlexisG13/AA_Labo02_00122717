#include<iostream>
#include <math.h>
using namespace std;

struct nodo{
    int info;
    struct nodo *sig;
};


class Queue{
    private:
        nodo *atras;
        nodo *delante;
    public:
        Queue();
        void push(int data);
        void pop();
        void mostrar();
        void invertir();
        void suma();

};

Queue::Queue(){
    atras = NULL;
    delante = NULL;
}

void Queue::push(int data){
    nodo *temp = new nodo;
    temp->info = data;
    temp->sig = NULL;
    if(delante == NULL){
        delante = temp;
    }else{
        atras->sig = temp;
    }
    atras = temp;
}


void Queue::pop(){
    nodo *temp = new nodo;
    if(delante == NULL){
        cout<<"\nNo hay elementos\n";
    }else{
        temp = delante;
        delante = delante->sig;
        delete temp;
    }
}


void Queue::mostrar(){
    nodo *p = new nodo;
    p = delante;
    if(delante == NULL){
        cout<<"\nNo hay elementos\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->sig;
        }
    }
}

void Queue::invertir(){
    nodo *p = new nodo;
    p = delante;
    if(delante==NULL){
        return;
    }
    int data = p->info;
    pop();
    invertir();
    push(data);
}

void Queue::suma(){
    Queue colacao;
    nodo *p = new nodo;
    int acum = 0;
    int cont = 0;
    p = delante;
    if(delante==NULL){
        cout << "No hay elementos\n";
        return;
    }else{
        while(p!=NULL){
            acum+=p->info;
            cont++;
            p=p->sig;
        }
    }
    p=delante;
    int promedio = floor(acum/cont);
    while(p!=NULL){
        if(!(p->info%promedio)){
            colacao.push(p->info);
        }
        p=p->sig;
    }
    colacao.mostrar();
}


int main(){

    Queue queue;
    int opcion;
    int data=0;
    while(true){
        cout<<"\n1.Push\n2. Pop\n3. Mostrar\n 4.Invertir + Multiplos del promedio\n";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<< "Ingresa el numero\n";
                cin>>data;
                queue.push(data);
                break;
            case 2:
                queue.pop();
                break;
            case 3:
                queue.mostrar();
                break;
            case 4:
                queue.invertir();
                queue.suma();
                break;
            default:
                exit(0);
                break;
        }
    }
    return 0;
}