#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *lchild;
    struct node *rchild;
};
struct node *search(struct node *ptr,int skey);
struct node *insert(struct node *ptr,int ikey);
struct node *min(struct node *ptr);
struct node *max(struct node *ptr);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
int height(struct node *ptr);
int main()
{
    struct node *root=NULL,*ptr;
    int choice,k;
    while(1)
    {
        printf("\n");
        printf("1.Search\n");
        printf("2.Insert\n");
        printf("3.Preorder Traversal\n");
        printf("4.Inorder Traversal\n");
        printf("5.Postorder Traversal\n");
        printf("6.Height of the Tree\n");
        printf("7.Find Maximum and Minimum\n");
        printf("8.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the key to be searched : ");
                scanf("%d",&k);
                ptr=search(root,k);
                if(ptr==NULL)
                {
                    printf("Key is not present.\n");
                }
                else
                {
                    printf("Key is present.\n");
                }
                break;
            case 2:
                printf("Enter the key to be insert : ");
                scanf("%d",&k);
                root=insert(root,k);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                printf("Height of the tree is %d\n",height(root));
                break;
            case 7:
                ptr=min(root);
                if(ptr!=NULL)
                {
                    printf("Minimum key is %d\n",ptr->info);
                }
                ptr=max(root);
                if(ptr!=NULL)
                {
                    printf("Maximum key is %d\n",ptr->info);
                }
                break;
            case 8:
                exit(1);
            default:
                printf("Wrong choice...\n");
        }
    }
}
struct node *search(struct node *ptr,int skey)
{
    if(ptr==NULL)
    {
        printf("Key is not found.\n");
        return NULL;
    }
    else if(skey<ptr->info)
        return search(ptr->lchild,skey);
    else if(skey>ptr->info)
        return search(ptr->rchild,skey);
    else
        return ptr;
}
struct node *min(struct node *ptr)
{
    if(ptr==NULL)
    {
        return NULL;
    }
    else if(ptr->lchild==NULL)
        return ptr;
    else
        return min(ptr->lchild);
}
struct node *max(struct node *ptr)
{
    if(ptr==NULL)
        return NULL;
    else if(ptr->rchild==NULL)
    {
        return ptr;
    }
    else
        return max(ptr->rchild);
}
struct node *insert(struct node *ptr,int ikey)
{
    if(ptr==NULL)
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->info=ikey;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
    }
    else if(ikey<ptr->info)
        ptr->lchild=insert(ptr->lchild,ikey);
    else if(ikey>ptr->info)
        ptr->rchild=insert(ptr->rchild,ikey);
    else
        printf("Duplicate key.\n");
    return ptr;
}
int height(struct node *ptr)
{
    int h_left,h_right;
    if(ptr==NULL)
    {
        return 0;
    }
    h_left=height(ptr->lchild);
    h_right=height(ptr->rchild);
    if(h_left>h_right)
    {
        return 1 + h_left;
    }
    else
        return 1 + h_right;
}
void preorder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return ;
    }
    printf("%d ",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void inorder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return ;
    }
    inorder(ptr->lchild);
    printf("%d ",ptr->info);
    inorder(ptr->rchild);
}
void postorder(struct node *ptr)
{
    if(ptr==NULL)
    {
        return ;
    }
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->info);
}
