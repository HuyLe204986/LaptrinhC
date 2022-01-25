#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList{
    int data;
    struct LinkedList *next;
}*node;
node CreateNode(int value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cấp phát vùng nhớ dùng malloc()
    temp->next = NULL;// Cho next trỏ tới NULL
    temp->data = value; // Gán giá trị cho Node
    return temp;//Trả về node mới đã có giá trị
}

node Add_Head(node head,int value){
    node temp=CreateNode(value);
    if(head==NULL)
        head=temp;
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}
node Add_Tail(node head,int value){
    node temp=CreateNode(value);
    node p;
    if(head==NULL)
        head=temp;
    else{
        p=head;
        while (p->next!=NULL)
            p=p->next;
        p->next=temp;
    }
    return head;
}
//them node vao vi tri bat ki
node Add_Mid(node head,int value,int position){
    if(position==0||head==NULL)
        head=Add_Head(head,value);
    else{
        int k=1;
        node p=head;
        while (p!=NULL && k!= position)
        {
            p=p->next;
            k++;
        }
        //pos > soptu cua dslk
        if(k!=position)
            head=Add_Tail(head,value);
        else{
            node temp=CreateNode(value);
            temp->next=p->next;
            p->next=temp;
        }
    }
    return head;
}
node del_Head(node head){
    if(head==NULL) printf("\ndanh sach rong");
    else head=head->next;
    return head;
}
node del_Tail(node head){
    if(head==NULL || head->next==NULL) del_Head(head);
    node p=head;
//duyệt đến chỗ thằng (cuối-1) và cho  (cuối-1)->next=null
    while (p->next->next!=NULL)
        p=p->next;
    p->next=NULL;
//cho node (cuối-1) là thằng có p->next->next=NULL;
    return head;
}
//xoa bat ki
node del_mid(node head,int pos){
    if(pos==0 || head==NULL ||head->next==NULL)
        head=del_Head(head);
    else{
        int k=1;
        node p=head;
        //chỉ cần duyệt đến vị trí (cuối-1)
        while (p->next->next!=NULL && k!= pos)
        {
            p=p->next;
            k++;
        } 
        if(k!=pos) head=del_Tail(head);
        else{
            p->next=p->next->next;
        }
    }
    return head;
}
//lấy gia trị ở vị trí bất kì
int get(node head,int index){
    int k=0;
    node p=head;
    while (p->next!=NULL && k!=index)
    {
        k++;
        p=p->next;
    }
    return p->data;
} 
//tìm kiếm trong danh sách nếu không thấy trả về -1
int search(node head,int value){
    int pos=0;
    for(node p=head;p!=NULL;p=p->next){
        if(p->data==value) return pos;
        pos++;
    }
    return -1;
}
//xóa các node có giá trị chỉ định
node DelByValue(node head,int value){
    int pos=search(head,value);
    printf("\nxoa o vi tri %d",pos);
    while (pos!=-1)
    {   
        del_mid(head,pos);
        pos=search(head,value);   
    }
    return head;  
}
//duyet ds
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
}
///hàm đếm số ptu
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
//khởi tạo node head
node InitHead(){
    node head;
    head = NULL;
    return head;
}
//Nhập
node Input(){
    node head = InitHead();
    int n, value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
    for(int i = 0; i < n; i++){
        printf("\nNhap gia tri can them: ");
        scanf("%d", &value);
        head = Add_Tail(head, value);
    }
    return head;
}
void freelist(node head){
    node tg=head,temp;
    while (tg!=NULL)
    {
        temp=tg->next;
        free(tg);
        tg=temp;
    }
}
int main(){
    printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
 
    printf("\n==Thu them 1 phan tu vao linked list==");
    head = Add_Mid(head, 100, 2);
    Traverser(head);
 
    printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = del_mid(head, 0);
    head = del_mid(head, 0);
    Traverser(head);
 
    printf("\n==Thu tim kiem 1 phan tu trong linked list==");
    int index = search(head, 5);
    printf("\nTim thay tai chi so %d", index);
    freelist(head);
    //delbyvalue xoas phan tu dau tien->bi loi
}