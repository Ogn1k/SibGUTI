#include <string>
#include <iostream>

struct Student
{
    std::string surname;
    int grades[4];

    Student(const std::string& surname, int grade1, int grade2, int grade3, int grade4) 
        : surname(surname) 
    {
        grades[0] = grade1;
        grades[1] = grade2;
        grades[2] = grade3;
        grades[3] = grade4;
    }  

    bool failGrade() const
    {
        for(int grade : grades)
            if(grade <= 2)
                return true;
        return false;
    }
};

struct Node
{
    Student student;
    Node* prev; // left
    Node* next; // right

    Node(const Student& s) : student(s), prev(nullptr), next(nullptr) {}
};

class LList
{
    Node* head;
    Node* tail;

public:
    LList() : head(nullptr), tail(nullptr) {}

    ~LList()
    {
        Node* cur = head;
        while (cur != nullptr)
        {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    void Insert(const Student& student)
    {
        Node* newNode = new Node(student);
        if(head == nullptr || student.surname < head->student.surname)
        {
            newNode->next = head;
            head = newNode;
        } 
        else
        {
            Node* cur = head;
            while(cur->next != nullptr && student.surname > cur->next->student.surname)
                cur = cur->next;
            newNode->next = cur->next;
            cur->next =  newNode;
        }
    }

    void Insert2nd(const Student& student)
    {
        Node* newNode = new Node(student);
        if(head == nullptr)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void RemoveFailStud()
    {
        Node* cur = head;
        while(cur != nullptr)
            if(cur->student.failGrade())
            {
                if(cur == head)
                {
                    head = cur->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                }
                else if(cur == tail)
                {
                    tail = cur->prev;
                    tail->next = nullptr;
                }
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
            else
                cur = cur->next;
    }

    void Print() const
    {
        Node* cur = head;
        while(cur != nullptr)
        {
            std::cout << cur->student.surname << " ";
            for(int grade : cur->student.grades)
                std::cout << grade << " ";
        
            std::cout << std::endl;
            cur = cur->next;
        }
    }
};

class TreeList
{
    Node* root;

    Node* InsertRec(Node* node, const Student& student)
    {
        if(node == nullptr)
            return new Node(student);

        if(student.surname < node->student.surname)
            node->prev = InsertRec(node->prev, student); // left
        else if(student.surname > node->student.surname)
            node->next = InsertRec(node->next, student); // right
        
        return node;
    }

    void PrintAscRec(const Node* node) const
    {
        if(node == nullptr)
            return;
        
        PrintAscRec(node->prev); // left
        std::cout << node->student.surname << std::endl;
        PrintAscRec(node->next); // right
    }

    void PrintDescRec(const Node* node) const
    {
        if(node == nullptr)
            return;
        
        PrintDescRec(node->next); // right
        std::cout << node->student.surname << std::endl;
        PrintDescRec(node->prev); // left
    }

    Student* SearchRec(Node* node, const std::string& surname) const
    {
        if(node == nullptr || node->student.surname == surname)
            return (node == nullptr) ? nullptr : &node->student;
        
        if(surname < node->student.surname)
            return SearchRec(node->prev, surname); // left
        else
            return SearchRec(node->next, surname);
        
    }

    void DestroyTree(Node* node)
    {
        if(node != nullptr)
        {
            DestroyTree(node->prev); // left
            DestroyTree(node->next); // right
            delete node;
        }
    }

public:
    TreeList() : root(nullptr) {}

    ~TreeList() { DestroyTree(root); }
        
    void Insert(const Student& student) { root = InsertRec(root, student); }

    void PrintAscend() const { PrintAscRec(root); }

    void PrintDescend() const { PrintDescRec(root); }

    Student* Search(const std::string& surname) const { return SearchRec(root, surname); }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    // {
    //     LList list;

    //     list.Insert(Student("Всеволод Штукатуров", 3, 3, 3, 3));
    //     list.Insert(Student("Цидармян Гена", 2, 2, 2, 2));
    //     list.Insert(Student("Пурнегров Нашам", 5, 4, 3, 2));

    //     list.Print();
    //     std::cout << std::endl;
    // }
    //2
    // {
    //     LList list;

    //     list.Insert2nd(Student("Всеволод Штукатуров", 3, 3, 3, 3));
    //     list.Insert2nd(Student("Цидармян Гена", 2, 2, 2, 2));
    //     list.Insert2nd(Student("Пурнегров Нашам", 5, 4, 3, 2));

    //     list.Print();   

    //     std::cout << std::endl;

    //     list.RemoveFailStud();

    //     list.Print();
    // }
    //3
    {
        TreeList tlist;

        tlist.Insert(Student("Всеволод Штукатуров", 3, 3, 3, 3));
        tlist.Insert(Student("Цидармян Гена", 2, 2, 2, 2));
        tlist.Insert(Student("Пурнегров Нашам", 5, 4, 3, 2));

        tlist.PrintAscend();
        std::cout << std::endl;

        tlist.PrintDescend();
        std::cout << std::endl;

        Student* foundSt = tlist.Search("Цидармян Гена");
        if(foundSt)
            std::cout << foundSt->surname << std::endl;
        else
            std::cout << "not found" << std::endl;
    }

    return 0;
}