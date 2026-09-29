#include <stdio.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

void preorder(const Node *p)
{
    if (p == NULL) { return; }
    printf(" %d", p->value);
    preorder(p->left);
    preorder(p->right);
}

void inorder(const Node *p)
{
    if (p == NULL) { return; }
    inorder(p->left);
    printf(" %d", p->value);
    inorder(p->right);
}

void postorder(const Node *p)
{
    if (p == NULL) { return; }
    postorder(p->left);
    postorder(p->right);
    printf(" %d", p->value);
}

int main(void)
{
    Node nodes[10] = {0};
    for (int i = 0; i < 10; ++i) {
        nodes[i].value = i + 1;
    }
    nodes[0].left = &nodes[1];  nodes[0].right = &nodes[6];
    nodes[1].left = &nodes[2];  nodes[1].right = &nodes[5];
    nodes[2].left = &nodes[3];  nodes[2].right = &nodes[4];
    nodes[6].left = &nodes[7];  nodes[6].right = &nodes[9];
    nodes[7].left = &nodes[8];

    printf("pre:");
    preorder(&nodes[0]);
    printf("\nin:");
    inorder(&nodes[0]);
    printf("\npost:");
    postorder(&nodes[0]);
    putchar('\n');
    return 0;
}
