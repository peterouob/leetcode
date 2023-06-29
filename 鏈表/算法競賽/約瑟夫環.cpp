#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *next;
};

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    node *head, *p, *now, *prev;
    head = new node;
    head->data = 1;
    head->next = NULL;
    now = head;
    for (int i = 2; i <= n; i++)
    {
        p = new node;
        p->data = i;
        p->next = NULL;
        now->next = p;
        now = p;
    }
    now->next = head;
    // 建立循環動態鍊錶
    now = head;
    prev = head;
    while ((n--) > 1)
    {
        for (int i = 0; i <= m; i++)
        {
            prev = now;
            now = now->next;
        }
        cout << now->data << endl;
        prev->next = now->next;
        delete now;
        now = prev->next;
    }
    cout << now->data << endl;
    delete now;
    return 0;
}