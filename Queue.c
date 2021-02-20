class Node
{
public:
    int number;
    Node* last;
    Node* next;
};
 
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    Node* ptrLast = NULL;
    short action = -1;
    while(1)
    {
        printf("1. Add element\n");
        printf("2. Viewing the queue\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("0. Exit\n\n");
        printf("Select: ");
        cin>>action;
        if (action == 0)
        {
            system("CLS");
            break;
        }
        if (action == 1)
        {
            system("CLS");
            int numb = -1;
            printf("Enter a number: ");
            cin>>numb;
            Node* ptr = new Node;
            ptr->number = numb;
            ptr->next = NULL;
            tail = ptr;
            if (head == NULL)
            {
                head = ptr;
                ptrLast = ptr;
                ptr->last = NULL;
                system("CLS");
                continue;
            }
            ptr->last = ptrLast;
            ptrLast->next = ptr;
            ptrLast = ptr;
            system("CLS");
            continue;
        }
        if (action == 2)
        {
            system("CLS");
            Node* ptr = NULL;
            if (head == NULL)
            {
                printf("\t!!! Queue is Empty!!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            printf("* * * * * QUEUE * * * * *\n\n");
            ptr = tail;
            while (1)
            {
                cout<<ptr->number<<" ";
                if (ptr->last == 0)
                    break;
                ptr = ptr->last;
            }
            cout<<"\n\n";
            system("PAUSE");
            system("CLS");
            continue;
        }
        if (action == 3)
        {
            system("CLS");
            Node* ptrDelete = NULL;
            if (head == NULL)
            {
                printf("\t!!! Queue is Empty !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            if (head->next == NULL)
            {
                head = NULL;
                tail = NULL;
                delete tail;
                continue;
            }
            ptrDelete = head;
            head = ptrDelete->next;
            head->last = NULL;
            delete ptrDelete;
            continue;
        }
        if (action == 4)
        {
            system("CLS");
            Node* ptr = NULL;
            int key = -1;
            if (head == NULL)
            {
                printf("\t!!! Queue is Empty !!!\n\n");
                system("PAUSE");
                system("CLS");
                continue;
            }
            printf("Element for search: ");
            cin>>key;
            ptr = head;
            while (1)
            {
                if (key == ptr->number)
                {
                    printf("\n\t!!! THE Element IS FOUND !!!\n");
                    break;
                }
                if (ptr->next == NULL)
                {
                    printf("\n\t!!! THE Element IS NOT FOUND!!!\n");
                    break;
                }
                ptr = ptr->next;
            }
            system("PAUSE");
            system("CLS");
            continue;
        }
        if (action > 4)
        {
            system("CLS");
            printf("\t!!! WRONG CHOICE. REPEAT THE INPUT !!!\n\n");
            system("PAUSE");
            system("CLS");
            continue;
        }
    }
}