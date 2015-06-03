#include <cstdio>

struct Node
{
    int val;
    Node * next;
};

Node * mergesort(Node * list, int size)
{
    int sz = size;
    if (size == 1)
    {
        list[0].next = 0;
        return list;
    }
    size /= 2;
    Node *l = mergesort(list, size);
    Node *r = mergesort(list + size, sz - size);
    Node *s = 0, *x = 0;
    while (l != 0 || r != 0)
    {
        if (l != 0 && (r == 0 || l->val <= r->val))
        {
            if (x != 0)
                x->next = l;
            else
                s = l;
            x = l, l = l->next;
        }
        else
        {
            if (x != 0)
                x->next = r;
            else
                s = r;
            x = r, r = r->next;
        }
        x->next = 0;
    }
    return s;
}

int main()
{
    const int SIZE = 8;

    Node nodes[SIZE];

    Node * head = 0;
    Node * tail = 0;

    printf("Please, enter %d elements: \n", SIZE);

    head = nodes;
    tail = nodes;
    tail->next = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        scanf("%d", &nodes[i].val);

        tail->next = nodes + i;
        tail = tail->next;
        tail->next = 0;
    }

    head = mergesort(head, SIZE);

    printf("Sorted:\n");

    for (Node *pn = head; pn != 0; pn = pn->next)
    {
        printf("%d\n", pn->val);
    }

    return 0;
}
