#include<stdio.h>
#include<stdlib.h>

int n, x, count, min, max, a[1000], b[1000], t[1000], freq[1000];

typedef struct tree
{
    int val;
    struct tree * left;
    struct tree * right;
}tree;

tree* removeOutsideRange(tree *root, int min, int max)
{
   // Base Case
   if (root == NULL)
      return NULL;

   // First fix the left and right subtrees of root
   root->left =  removeOutsideRange(root->left, min, max);
   root->right =  removeOutsideRange(root->right, min, max);

   // Now fix the root.  There are 2 possible cases for toot
   // 1.a) Root's val is smaller than min value (root is not in range)
   if (root->val < min)
   {
       tree *rChild = root->right;
       free(root);
       return rChild;
   }
   // 1.b) Root's val is greater than max value (root is not in range)
   if (root->val > max)
   {
       tree *lChild = root->left;
       free(root);
       return lChild;
   }
   // 2. Root is in range
   return root;
}

void inorderTraversal(tree* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        printf("%d ",root->val);
        inorderTraversal( root->right );
    }
}

void copy(tree * root, int node)
{
    if(t[node*2] != -999)
    {
        tree * temp = (tree *)malloc(sizeof(tree));
        root->left = temp;
        root->left->val = t[node*2];
    }
    else
        root->left = NULL;

    if(t[node*2+1] != -999)
    {
        tree * temp = (tree *)malloc(sizeof(tree));
        root->right = temp;
        root->right->val = t[node*2+1];
    }
    else
        root->right = NULL;

    if(root->left != NULL)
        copy(root->left,node*2);

    if(root->right != NULL)
        copy(root->right,node*2+1);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<n; i++)
        scanf("%d%d",&a[i],&b[i]);
    scanf("%d",&x);
    scanf("%d%d",&min,&max);

    for(int i=0; i<1000; i++)
        t[i] = -999;

    int ptr = 0;
    t[++ptr] = x;

    while(count <= n)
    {
        if(t[ptr] != -999)
            count++;
        else
        {
            ptr++;
            continue;
        }
        for(int i=1; i<=n; i++)
        {
            if(a[i] == t[ptr])
            {
                if(freq[b[i]] != 1)
                {
                    freq[b[i]] = 1;

                    if(b[i] < t[ptr])
                        t[ptr*2] = b[i];
                    else
                        t[ptr*2 + 1] = b[i];
                }
            }
            else if(b[i] == t[ptr])
            {
                if(freq[a[i]] != 1)
                {
                    freq[a[i]] = 1;

                    if(a[i] < t[ptr])
                        t[ptr*2] = a[i];
                    else
                        t[ptr*2 + 1] = a[i];
                }
            }
        }
        ptr++;
    }
    // for(int i=1; i<=10; i++)
        // printf("%d ",t[i]);

    tree * root = (tree *)malloc(sizeof(tree));
    root->val = t[1];
    copy(root, 1);

    root = removeOutsideRange(root, min, max);

    inorderTraversal(root);


    return 0;
}
