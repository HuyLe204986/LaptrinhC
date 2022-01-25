#include <stdio.h>
#include <stdlib.h>
 
typedef char elementtype;
typedef struct _Tnode
{
    elementtype inf;
    // Dữ liệu cất giữ ở nút
    struct _Tnode *left;
    struct _Tnode *right;
} Treenode;
 
Treenode *createnewnode(elementtype X){
    Treenode *newnode=(Treenode*)malloc(sizeof(Treenode));
    if(newnode==NULL){printf("Error in memoty allocation\n");exit(0);}
    newnode->inf=X;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}
 //duyet truoc G-T-P
void PREORDER( Treenode *r )
{
    if(r==NULL) return;
    printf("%c ",r->inf);
    PREORDER(r->left);
    PREORDER(r->right);
}
 //duyet sau T-P-G
void POSTORDER( Treenode *r )
{
    if(r==NULL) return;
    POSTORDER(r->left);
    POSTORDER(r->right);
    printf("%c ",r->inf);
}

//duyet giua T-G-P
void INORDER( Treenode *r )
{
    if(r==NULL) return;
    INORDER(r->left);
    printf("%c ",r->inf);
    INORDER(r->right);
}

void freetree(Treenode *r){
    if(r==NULL) return;
    freetree(r->left);
    freetree(r->right);
    free(r);
}

int sonut(Treenode *r){
    if(r==NULL) return 0;
    return 1+sonut(r->left)+sonut(r->right);
}

int sonut_trong(Treenode *r){
    if(r==NULL || (r->left==NULL && r->right==NULL)) return 0;
    return 1+sonut_trong(r->left)+sonut_trong(r->right);
}

int nut_k_con(Treenode *r,int k)
{
    if(k<0||k>2) return 0;
    int i=0,count=0;
    if(r==NULL) return 0;
    if(r->left!=NULL) i+=1;
    if(r->right!=NULL) i+=1;
    if(i==k) count+=1;
    count+=nut_k_con(r->left,k);
    count+=nut_k_con(r->right,k);
    return count;
}
int main(){
    Treenode *root=NULL;
    Treenode *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;

    root=createnewnode('A');
    nutB=createnewnode('B');
    nutC=createnewnode('C');
    nutD=createnewnode('D');
    nutE=createnewnode('E');
    nutF=createnewnode('F');
    nutG=createnewnode('G');
    nutH=createnewnode('H');
    nutI=createnewnode('I');
    nutJ=createnewnode('J');
    nutK=createnewnode('K');

    root->left=nutB;

    nutB->left=nutE;
    nutB->right=nutC;

    nutC->left=nutG;
    nutC->right=nutD;

    nutE->right=nutF;

    nutG->left=nutH;

    nutH->right=nutI;
    nutI->right=nutJ;
    nutJ->right=nutK;


    printf("-----------Duyet truoc-------\n");
    PREORDER(root);


    printf("\n-----------Duyet sau-------\n");
    POSTORDER(root);


    printf("\n-----------Duyet giua-------\n");
    INORDER(root);


    printf("\n-----------Dem so nut: %d\n",sonut(root));
    printf("\n-----------Dem so nut trong: %d\n",sonut_trong(root));
    printf("\n-----------Dem so nut 0 con la: %d\n",nut_k_con(root,0));
    printf("\n-----------Dem so nut 1 con la: %d\n",nut_k_con(root,1));
    printf("\n-----------Dem so nut 2 con la: %d\n",nut_k_con(root,2));
    printf("\n-----------Dem so nut 4 con la: %d\n",nut_k_con(root,4));

    freetree(root);
    return 1;
}
