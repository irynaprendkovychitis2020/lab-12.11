// lab 12.11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>
#include <string>


using namespace std;


struct Bookk
{
    int id;
    string name;
    string author;
    int publicationYear;
    int amount;
};


struct Node
{
    Bookk bookk;


    Node* Next, * Prev;
};

class List
{
    Node* Head, * Tail;
public:
    int count = 0;

    List() : Head(NULL), Tail(NULL) {};
    ~List();
    void Show();
    void Add(Bookk book);
    void Del(int id);
};

List::~List()
{
    while (Head)
    {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}

void List::Add(Bookk book)
{
    Node* temp = new Node;
    temp->Next = NULL;
    temp->bookk = book;

    if (Head != NULL)
    {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    else
    {
        temp->Prev = NULL;
        Head = Tail = temp;
    }
    count++;
}




void List::Show()
{

    cout << "\n\n";

    Node* temp = Head;
    int minYear;
    int* printedIDs = new int[count];
    int* printedYears = new int[count];

    Bookk* array = new Bookk[count];

    for (int k = 0; k < count; k++)              // filling printedIDs
    {
        printedIDs[k] = temp->bookk.id;
        printedYears[k] = temp->bookk.publicationYear;

        temp = temp->Next;
    }

    int tempID;
    int tempYear;

    for (int i = 0; i < count - 1; i++) { // sorting 'printedIDs' array
        for (int j = 0; j < count - i - 1; j++) {
            if (printedYears[j] > printedYears[j + 1]) {
                tempYear = printedYears[j];
                tempID = printedIDs[j];

                printedYears[j] = printedYears[j + 1];
                printedYears[j + 1] = tempYear;
                printedIDs[j] = printedIDs[j + 1];
                printedIDs[j + 1] = tempID;
            }
        }
    }

    temp = Head;


    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (temp->bookk.id == printedIDs[i]) {
                cout << "ID: \t\t" << temp->bookk.id << endl;
                cout << "Title: \t\t" << temp->bookk.name << endl;
                cout << "Author: \t" << temp->bookk.author << endl;
                cout << "Pub year: \t" << temp->bookk.publicationYear << endl;
                cout << "Amount: \t" << temp->bookk.amount << endl;
                cout << "\n\n";

                temp = Head;
                break;
            }

            temp = temp->Next;
        }
    }



    cout << "\n";
}


void List::Del(int id)
{
    Node* temp = new Node;
    temp = Head;

    for (int i = 0; i < count; i++) {
        if (temp->bookk.id == id) {
            if (temp->Next == NULL) {
                temp->Prev->Next = NULL;
                Tail = temp->Prev;
            }

            if (temp->Prev == NULL) {
                temp->Next->Prev = NULL;
                Head = temp->Next;
            }

            if (temp->Prev != NULL && temp->Next != NULL) {
                temp->Next->Prev = temp->Prev;
                temp->Prev->Next = temp->Next;
            }

            count--;
            break;
        }

        temp = temp->Next;
    }

}




Bookk CreateBook(int id, string name, string author, int publicationYear, int amount) 
{
    Bookk temp;
    temp.id = id;
    temp.name = name;
    temp.author = author;
    temp.publicationYear = publicationYear;
    temp.amount = amount;
    return temp;
}


Bookk enterBook()
{
    Bookk temp;
    cout << "Enter book ID: ";
    cin >> temp.id;
    cout << "Enter book title: ";
    cin >> temp.name;
    cout << "Enter book author: ";
    cin >> temp.author;
    cout << "Enter book publication year: ";
    cin >> temp.publicationYear;
    cout << "Enter amount of books: ";
    cin >> temp.amount;


    return temp;
}

void printMenuCommands() 
{
    cout << "Enter '0' to show keys" << endl;
    cout << "Enter '1' to add new book" << endl;
    cout << "Enter '2' to show books" << endl;
    cout << "Enter '3' to delete book by ID" << endl;
}

int main()
{
    List books;



    books.Add(CreateBook(1, "fdgsdf", "mava", 2010, 5));
    books.Add(CreateBook(2, "gfds", "andr", 2008, 1));
    books.Add(CreateBook(3, "hola", "ordaa", 2003, 4));
    books.Add(CreateBook(4, "mola", "lova", 2019, 3));

    int menuKey;
    printMenuCommands();
    while (true) {
        cout << "Enter menu key: ";
        cin >> menuKey;
        cout << endl;

        switch (menuKey)
        {
        case 0: printMenuCommands(); break;
        case 1: books.Add(enterBook()); break;
        case 2: books.Show(); break;
        case 3:
            int tempID;
            cout << "Enter book's ID to delete: ";
            cin >> tempID;
            books.Del(tempID);
            break;
        default: cout << "Wrong key!" << endl;
            break;
        }
    }
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
