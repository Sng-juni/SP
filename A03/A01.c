#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {false, true} bool;

typedef char Data;

typedef struct _NODE {
    Data items;
    struct _NODE* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void InitStack(Stack *pstack);

bool IsEmpty(Stack *pstack);

Data Peek(Stack *pstack);

void Push(Stack *pstack, Data item);

void Pop(Stack *pstack);

void Count_ABC(char* str, int len);

void Print_Mode(char* str, int len);

void ReverseStr(char* str, int len);

void PrintStr(char* str, int len);

void SWAP(char* str, int idx1, int idx2);

int Partition(char* str, int left, int right);

void SortStr(char* str, int left,int right);

int IsPalindrome(char* str, int len);

int Can_Palindrome(char* str, int* Count_Alphabet,int len);

void Swap(char* a, char* b);

void Generator_odd(char* str, int* Count_Alphabet,int len);

void Generator_even(char* str, int* Count_Alphabet,int len);

void Generator(char* str, int* Count_Alphabet,int len);


int main()
{
    char check_str[100] = {"WASDICHNICHTUMBRINGTMACHTDICHNURSTAERKERDICHMACHTNURSTAERKERNICHTDICHWASUMBRINGT"};
    int Alphabet[26] = {0, };

    Count_ABC(check_str, strlen(check_str));
    Print_Mode(check_str, strlen(check_str));
    ReverseStr(check_str,strlen(check_str));
    SortStr(check_str, 0, strlen(check_str) - 1);
    PrintStr(check_str, strlen(check_str));
    Generator(check_str, Alphabet,strlen(check_str));

    return 0;
}   

void InitStack(Stack *pstack)
{
    pstack->top = NULL;
}

bool IsEmpty(Stack *pstack)
{
    return pstack->top == NULL;
}

Data Peek(Stack *pstack)
{
    if (IsEmpty(pstack))
        exit(1);
    return pstack->top->items;
}

void Push(Stack *pstack, Data item)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->items = item;
    newNode->next = pstack->top;
    pstack->top = newNode;
}

void Pop(Stack *pstack)
{
    Node* temp;
    if (IsEmpty(pstack))
        exit(1);
    
    temp = pstack->top;
    pstack->top = pstack->top->next;
    free(temp);
}

void Count_ABC(char* str, int len)
{
    int Count_ABC[26] = {0, };

    for (int i = 0; i < len; i++)
    {
        Count_ABC[str[i] - 65]++;
    }
    
    printf("A : %d\n", Count_ABC[0]);
    printf("B : %d\n", Count_ABC[1]);
    printf("C : %d\n", Count_ABC[2]);
    printf("D : %d\n", Count_ABC[3]);
    printf("E : %d\n", Count_ABC[4]);
    printf("F : %d\n", Count_ABC[5]);
    printf("G : %d\n", Count_ABC[6]);
    printf("H : %d\n", Count_ABC[7]);
    printf("I : %d\n", Count_ABC[8]);
    printf("J : %d\n", Count_ABC[9]);
    printf("K : %d\n", Count_ABC[10]);
    printf("L : %d\n", Count_ABC[11]);
    printf("M : %d\n", Count_ABC[12]);
    printf("N : %d\n", Count_ABC[13]);
    printf("O : %d\n", Count_ABC[14]);
    printf("P : %d\n", Count_ABC[15]);
    printf("Q : %d\n", Count_ABC[16]);
    printf("R : %d\n", Count_ABC[17]);
    printf("S : %d\n", Count_ABC[18]);
    printf("T : %d\n", Count_ABC[19]);
    printf("U : %d\n", Count_ABC[20]);
    printf("V : %d\n", Count_ABC[21]);
    printf("W : %d\n", Count_ABC[22]);
    printf("X : %d\n", Count_ABC[23]);
    printf("Y : %d\n", Count_ABC[24]);
    printf("Z : %d\n", Count_ABC[25]);
}

void Print_Mode(char* str, int len)
{
    char Mode_Alpha = 0;
    int Count_ABC[26] = {0, };

    for (int i = 0; i < len; i++)
    {
        Count_ABC[str[i] - 65]++;
    }

    for (int i = 1; i < 26; i++)
    {
        if (Count_ABC[i - 1] > Count_ABC[i])
            Mode_Alpha = Count_ABC[i] + 65;
    }
    printf("Mode Alphabet : %c\n", Mode_Alpha);
}

void ReverseStr(char* str, int len)
{
    printf("ReverseStr :");
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void PrintStr(char* str, int len)
{
    printf("SortStr : ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void SWAP(char* str, int idx1, int idx2)
{
    char temp = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = temp;
}

int Partition(char* str, int left, int right)
{
    int pivot = str[left];
    int low = left + 1;
    int high = right;

    while (low <= high)
    {
        while (pivot >= str[low] && low <= right)
            low++;

        while (pivot <= str[high] && high >= (left + 1))
            high--;

        if (low <= high)
            SWAP(str, low, high);
    }

    SWAP(str, left, high);

    return high;
}

void SortStr(char* str, int left, int right)
{
    char* temp_str = str;

    if (left <= right)
    {
        int pivot = Partition(temp_str, left, right);
        SortStr(temp_str, left, pivot - 1);
        SortStr(temp_str, pivot + 1, right);
    }
}

int IsPalindrome(char* str, int len)
{
    Stack stack;
    int res = 1;

    InitStack(&stack);
    for (int i = 0; i < len; i++)
    {
        Push(&stack, str[i]);
    }

    while (!IsEmpty(&stack))
    {
        for (int i = 0; i < len; i++)
        {
            if (str[i] != Peek(&stack))
            {
                Pop(&stack);
                res = 0;
            }
            else
                Pop(&stack);
        }
    }
    if (res == 0)
        return 0;
    else
        return 1;
}

int Can_Palindrome(char* str, int* Count_Alphabet, int len)
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        Count_Alphabet[str[i] - 65]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (Count_Alphabet[i] % 2 == 1)
            count += 1;
    }
    if (count > 1)
        return 0;
    else
        return 1;
}

void Swap(char* a, char* b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Generator_odd(char* str, int* Count_Alphabet,int len)
{
    char odd_char = 0;
    int Swap_Count = 0;

    for (int i = 0; i < 26; i++)
    {
        if (Count_Alphabet[i] == 1)
            odd_char = i + 65;
    }
    if (str[len / 2] == odd_char)
        str[len / 2] = odd_char;
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (str[i] == odd_char)
            {
                Swap(&str[len / 2], &str[i]);
                Swap_Count += 1;
                break;
            }
        }
    }
    for (int i = 1; i <= (len / 2); i++)
    {
        if (str[(len / 2) - i] == str[(len / 2) + i])
            str[(len / 2) - i] = str[(len / 2) + i];
        else
        {
            for (int j = 0; j < len; j++)
            {
                if (j != (len / 2) - i && str[j] == str[(len / 2) - i])
                {
                    Swap(&str[(len / 2) + i], &str[j]);
                    Swap_Count += 1;
                    break;
                }
            }
        }
    }
    printf("%s\n", str);
    printf("%d\n", Swap_Count);
}

void Generator_even(char* str, int* Count_Alphabet,int len)
{
    int Swap_Count = 0;

    for (int i = 0; i < (len / 2); i++)
    {
        if (str[(len / 2) - 1 - i] == str[(len / 2) + i])
            str[(len / 2) - 1 - i] = str[(len / 2) + i];
        else
        {
            for (int j = 0; j < len; j++)
            {
                if (j != (len / 2) - 1 - i && str[j] == str[(len / 2) - 1 - i])
                {
                    Swap(&str[(len / 2) + i], &str[j]);
                    Swap_Count += 1;
                    break;
                }
            }
        }
    }
    printf("%s\n", str);
    printf("%d\n", Swap_Count);
}

void Generator(char* str, int* Count_Alphabet, int len)
{
    if (!IsPalindrome(str, len))
    {
        if (!Can_Palindrome(str, Count_Alphabet,len))
        {
            printf("Impossible\n");
        }
        else if ((len % 2) == 1)
            Generator_odd(str, Count_Alphabet,len);
        else if ((len % 2) == 0)
            Generator_even(str, Count_Alphabet,len);
    }
}