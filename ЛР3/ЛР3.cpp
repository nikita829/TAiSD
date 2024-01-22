#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node*& head, int data);
void removeEven(Node*& head);
void Print_List(Node* head);

int main() 
{
    setlocale(0, "");
    Node* head = NULL;
    int n, num;

    cout << "Введите количество элементов в списке: ";
    cin >> n;
    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        addNode(head, num);
    }
    
    cout << "Исходный список: ";
    Print_List(head);
    cout << "Удаление из списка первого элемента с четным информационным полем:\n";
    removeEven(head);
}

void addNode(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL)
    {
        head = newNode;
    } 
    else 
    {
        Node* temp = head;
        while (temp->next != NULL)  // Поиск последнего элемента в списке
        {
            temp = temp->next;
        }
        temp->next = newNode;       // Добавление нового элемента в конец списка
    }
}

void removeEven(Node*& head) {
    if (head == NULL)               // Если список пустой, ничего не делаем
    {
        cout << "Список пуст\n";
        return;
    }
    
    if (head->data % 2 == 0)        // Если информационное поле первого элемента - четное число
    {
        Node* temp = head;          // Запоминаем адрес первого элемента для освобождения памяти
        head = head->next;          // Перемещаем голову списка на следующий элемент
        delete temp;                // Удаляем первый элемент
        Print_List(head);
        return;
    }
    
    Node* prev = head;
    Node* curr = head->next;
    
    while (curr != NULL) {
        if (curr->data % 2 == 0)    // Если информационное поле текущего элемента - четное число
        {
            prev->next = curr->next;// Пропускаем текущий элемент, обновляя ссылки
            delete curr;            // Удаляем текущий элемент
            Print_List(head);
            return;
        }
        prev = curr;                // Переходим к следующему элементу
        curr = curr->next;
    }
    cout << "В списке нет элементов с четным информационным полем\n";
}

void Print_List(Node* head) {
    Node* temp = head;
    while (temp != NULL) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
