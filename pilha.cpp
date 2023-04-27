#include <iostream>

using namespace std;

struct Node
{
    int iData;
    Node* next;
};

struct Pilha
{
    Node* top;
    Node* bottom;
};

Pilha* newPilha()
{
    Pilha* temp = (Pilha*) malloc(sizeof(Pilha));
    temp -> top = nullptr;
    //temp -> bottom = nullptr;
    return temp;
}

void empilhar(Pilha* pilha, int iValor)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> next = pilha -> top;
    temp -> iData = iValor;
    pilha -> top = temp;
}

void desempilhar(Pilha* pilha)
{
    if(pilha->top == nullptr) return;
    Node* temp = pilha->top;
    pilha->top = temp->next;
    free(temp);
}

void printPilha(Pilha* pilha)
{
    if(pilha->top == nullptr)
    {
        cout << "Pilha vazia" << endl;
        return;
    }
    
    Node* temp = pilha -> top;
    while(temp->next != nullptr)
    {
        cout << temp->iData << endl;
        temp = temp -> next;
    }
    cout << temp->iData << endl;
}

int lenghtPilha(Pilha* pilha)
{
    int i = 1;
    Node* temp = pilha->top; 
    while(temp->next != nullptr)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

void newTower(Pilha* torre, int iTamanho)
{
    for(int i=iTamanho; i>0; i--)
    {
        empilhar(torre, i);
    }
}

void moveHanoi(Pilha* torre1, Pilha* torre2)
{   
    if(torre1->top == nullptr)
    {
        cout << "Movimento inválido" << endl;
        return;
    }

    else if(torre2->top == nullptr)
    {
        empilhar(torre2, torre1->top->iData);
        desempilhar(torre1);
        return;
    }

    if(torre1->top->iData > torre2->top->iData)
    {
        cout << "Movimento inválido" << endl;
    }

    else
    {
        empilhar(torre2, torre1->top->iData);
        desempilhar(torre1);
    }
}

void winHanoi(Pilha* main, Pilha* target, Pilha* aux, int n)
{
    if(n == 0)
    {
        return;
    }
    
    winHanoi(main, aux, target, n-1);
    moveHanoi(main, target);
    winHanoi(aux, target, main, n-1);
    
}


int main()
{
    Pilha* torre1 = newPilha();
    Pilha* torre2 = newPilha();
    Pilha* torre3 = newPilha();
    newTower(torre1, 3);
    
    printPilha(torre1);
    cout << "=======" << endl;

    moveHanoi(torre1, torre2);
    moveHanoi(torre1, torre3);
    moveHanoi(torre2, torre3);
    moveHanoi(torre1, torre2);
    
    moveHanoi(torre3, torre1);
    moveHanoi(torre3, torre2);
    moveHanoi(torre1, torre2);

    printPilha(torre2);
    cout << "=======" << endl;

    winHanoi(torre2, torre1, torre3, 3);

    printPilha(torre1);

    return 0;
}
