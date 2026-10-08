#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) 
{ 
if (root == NULL) 
   {
    root = createNode(data);
    }
  else if (data <= root->data) 
   { root->left = insertNode(root->left, data);
    }
    else {
     root->right = insertNode(root->right, data);
    }
return root;
}

void inorderTraversal(struct Node* root) 
{
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) 
{
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) 
{
    if (root == NULL)  return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() 
{
    struct Node* root = NULL;
    int choice, value;
 while(1) 
{ 
    printf("\nBinary Tree Operations\n");
    printf("1. Insert a node\n");
    printf("2. In-order Traversal\n");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:printf("Pre-order Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:printf("Post-order Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5: printf("Exiting the program.\n");
                exit(0);
                break;

            default:printf("Invalid choice. Please try again.\n");
        }
    }
  return 0;
}
