
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

int heightofbinarytree(node *root){
    int leftsubtree, rightsubtree;
    if (root == NULL){
        return 0;
    }
    else{
        leftsubtree = heightofbinarytree(root->left);
        rightsubtree = heightofbinarytree(root->right);
        if (leftsubtree>rightsubtree){
            return (leftsubtree+1);
        }
        else{
            return (rightsubtree+1);
        }
    }
    
    
}
void printlevel(node *root, int level){
   // printf("level %d: ", level);
    if (root== NULL){
        return;
    }
    if (level == 1){
        printf("%d ", root->data);
    }
    else if (level>1){
        printlevel(root->left, level-1);
        printlevel(root->right, level-1);
    }
        
    
}


void LevelOrder(node * root)
    
{
    int height = heightofbinarytree(root);
    
    int i,d;
    for (i=1;i<=height;i++){
        printlevel(root, i);
        
    }
    
    
    
    
    
  
  
}
