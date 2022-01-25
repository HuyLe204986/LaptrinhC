#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1
#define INVALID_CITY_CODE -1
struct city
{
    int code;
    char name[100];
    float area;
    int population;
};
typedef struct city City;
struct LinkedList{
    City city;
    struct LinkedList *next;
};
typedef struct LinkedList *node;
//khoi tao node head
node initHead(){
    node head;
    head=NULL;
    return head;
}
//tao node
node createnode(City city){
    node temp=(node)malloc(sizeof(struct LinkedList));
    temp->next=NULL;
    temp->city=city;
    return temp;
}
//tao city
City createCity(){
    City newCity;
    printf("Nhap code: ");
    scanf("%d", &newCity.code);
    printf("Nhap ten: ");
    getchar(); // Bỏ qua '\n' trong bộ đệm
    fgets(newCity.name, 100, stdin);
    newCity.name[strlen(newCity.name)-1]='\0';
    // Xóa \n ở cuối chuỗi vừa nhập nếu có
    printf("Nhap dien tich: ");
    scanf("%f", &newCity.area);
    printf("Nhap dan so: ");
    scanf("%d", &newCity.population);
    return newCity;
}
//them vao dau
node addHead(node head,City value){
    node temp=createnode(value);
    if(head==NULL) head=temp;
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}
//them vao cuoi
node addTail(node head,City value){
    node temp=createnode(value);
    node p;
    if(head==NULL) head=temp;
    else{
        p=head;
        while (p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    return head;
}
//them vao vi tri bat ki
node addAt(node head,City value,int pos){
    if(pos==0 || head==NULL) head=addHead(head,value);
    else{
        int k=1;
        node p=head;
        while (k!=pos || p->next!=NULL)
        {
            p=p->next;
            k++;
        }
        if(k!=pos) head=addTail(head,value);
        else{
            node temp=createnode(value);
            temp->next=p->next;
            p->next=temp;
        }
    }
    return head;
}
//hoàn chỉnh thêm node
node addnode(node head){
    City newCity;
    char option;
    int pos;
    while (true)
    {
        printf("\n===========Nhap du lieu can them=============\n");
        printf("\nNhap vi tri muon them:");
        scanf("%d",&pos);
        newCity=createCity();
        head=addAt(head,newCity,pos);
        printf("\nThem thanh cong?Them tiep(Y/N)?");
        getchar();
        do
        {
            scanf("%c",&option);
            if (option!='Y' && option!='y'&& option!='n' && option!='N')
            {
                printf("\nNhap sai nhap lai:");
                scanf("%c",&option);
            }          
        } while (option!='Y' && option!='y' && option!='n' && option!='N');
        if(option=='N' || option=='n') break;       
    }
    return head;
}
//xóa đầu
node delHead(node head){
    if(head==NULL) printf("\nDanh sach rong");
    else{
        head=head->next;
    }
    return head;
}
//xóa cuối
node delTail(node head){
    if(head==NULL || head->next==NULL) return delHead(head);
    else{
        node p=head;
        while (p->next->next!=NULL)
        {
            p=p->next;
        }
        p->next=NULL;
    }
    return head;
}
//xóa node ở chỉ số (bắt đầu từ 0) bất kì
node delAt(node head,int pos){
    if(pos==0 || head==NULL || head->next==NULL){
        head=delHead(head);
    }else{
        int k=1;
        node p=head;
        while (k!=pos || p->next->next!=NULL)
        {
            p=p->next;
            k++;
        }
        if(k!=pos) head=delTail(head);
        else p->next=p->next->next;
    }
    return head;
}
//tìm chỉ số của node bằng mã thành phố(code)
int findIndexByCode(node head,int code){
    int index=-1;
    for(node p=head;p!=NULL;p->next){
        index++;
        if(p->city.code==code) return index;
    }
    return -1; //nếu không tìm thấy
}
//xóa node theo mã tỉnh thành
node removenode(node head){
    int code;
    char option;
    while (1)
    {
        printf("\n=========Chon node muon xoa===============\n");
        printf("\nNhap ma tinh thanh pho:");
        scanf("%d",&code);
        int pos=findIndexByCode(head,code);
        if(pos<0) printf("\nKhong thay,xoa tiep(Y/N)?");
        else{
            head=delAt(head,pos);
            printf("\nXoa tiep(Y/N)?");
        }
        getchar();
        scanf("%c",&option);
        if(option=='N' ||option=='n') break;
    }
    return head;
}
//sửa giá trị của node
void editnode(node head){
    int code;
    char option;
    City newcity;
    while (1)
    {
        printf("\n==========Chon node can sua===========\n");
        printf("\nNhap ma tinh/thanhpho:");
        scanf("%d",&code);
        int dem=0;
        for(node p=head;p!=NULL;p=p->next){
            if(p->city.code==code){
                newcity=createCity();
                p->city=newcity;
                dem++;
                break;
            }
        }
        if(dem){
            printf("\nSua thanh cong,sua tiep(Y/N)?");
        }else{
            printf("\nKhong tim thay du lieu,sua tiep(Y/N)?");
        }
        getchar();
        scanf("%c",&option);
        if(option=='N' || option=='n') break;
    }
}
/*xep danh sach
sap xep thep code:bycode=1;byarea=0
sap xep thep area:bycode=0;byarea=1
sap xep tang dan thi desc=0;giam dan desc=1;
*/
void swapCityData(City *a,City *b){
    City tmp=*a;
    *a=*b;
    *b=tmp;
}
void sortCities(node head,int byCode,int byArea,int Desc){
    for(node p=head;p!=NULL;p=p->next)
        for(node q=p->next;q!=NULL;q=q->next){
            if(Desc){
                if(byCode && p->city.code<q->city.code){
                    swapCityData(&p->city,&q->city);
                }else if(byArea && p->city.area<q->city.area){
                    swapCityData(&p->city,&q->city);
                }
            }else{
                if(byCode && p->city.code>q->city.code){
                    swapCityData(&p->city,&q->city);
                }else if(byArea && p->city.area>q->city.area){
                    swapCityData(&p->city,&q->city);
                }
            }
        }
}
// Hàm tính tổng diện tích các thành phố trong DSLK
float sumArea(node head){
    float sum = 0;
    for(node p = head; p != NULL; p = p->next){
        sum += p->city.area;
    }
    return sum;
}
 
 
// Hàm tìm chỉ số của node có diện tích lớn nhất (giả sử chỉ có 1)
// Nếu dữ liệu có nhiều hơn 1, chúng ta tìm max rồi duyệt lại 1 lần nữa để tìm ra các node có giá trị = max đó
int indexOfMaxArea(node head){
    int maxIndex = 0, index = 0;
    int maxArea = head->city.area;
    for(node p = head; p != NULL; p = p->next){
        if (p->city.area > maxArea){
            maxArea = p->city.area;
            maxIndex = index;
        }
        index++;
    }
    return maxIndex;
}
 
// Hàm tìm node có dân số lớn nhất
City maxByPopulation(node head){
    City city = head->city;
    for(node p = head; p != NULL; p = p->next){
        if (p->city.population > city.population){
            city = p->city;
        }
    }
    return city;
}
//duyet danh sach
void traverser(node head){
    printf("Danh sach hien tai:\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("%10s%50s%20s%20s\n", "Ma Tinh/TP", "Tinh thanh", "Dien tich", "Dan so");
    for(node p = head; p != NULL; p = p->next){
        printf("%10d%50s%20f%20d\n", p->city.code, p->city.name, p->city.area, p->city.population);
    }
    printf("------------------------------------------------------------------------------------------------------------\n");
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
// Hàm tách các thành phần của 1 dòng trong file
City handleLineData(char *line){
    City city;
    city.code = INVALID_CITY_CODE; // Khởi tạo giá trị không hợp lệ. Về sau ta có thể kiểm tra.
    const char delimiter[] = "\t";
    char *tmp;
    tmp = strtok(line, delimiter);
    if (tmp == NULL) {
        printf("Du lieu khong dung dinh dang: %s", line);
        exit(EXIT_FAILURE);
    }
   city.code = atoi(tmp);
    int index = 0;
    for (;;index++) {
        tmp = strtok(NULL, delimiter);
        if (tmp == NULL)
            break;
        if (index == 0){
            strcpy(city.name, tmp);
        }else if (index == 1){
           city.area = (float)atof(tmp);
        }else if (index == 2){
            city.population = atoi(tmp);
        }else {
            printf("Du lieu khong dung dinh dang: %s", line);
            exit(EXIT_FAILURE);
        }
    }
    return city;
}
 
// Hàm đọc dữ liệu từ tập tin
node readData(node head, const char* fileName){
    FILE* file = fopen(fileName, "r");
    if(!file){
        printf("Co loi khi mo file : %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    char line[500];
    while (fgets(line, sizeof(line), file)) {
        City city = handleLineData(line);
        if (city.code != INVALID_CITY_CODE) {
            head = addTail(head, city);
        }
    }
    fclose(file);
    return head;
}
void printMenu(){
    printf("================== MENU ====================\n");
    printf("1. Duyet danh sach\n");
    printf("2. Them du lieu (them Node)\n");
    printf("3. Sua du lieu (sua Node)\n");
    printf("4. Xoa du lieu (xoa Node)\n");
    printf("5. Tinh tong dien tich\n");
    printf("6. Tim dia chi cua Node co dien tich lon nhat\n");
    printf("7. Tim tinh co dan so lon nhat\n");
    printf("8. Sap xep danh sach theo ma tinh\n");
    printf("9. Sap xep danh sach theo dien tich\n");
    printf("10. Thoat chuong trinh\n");
    printf("============================================\n");
}
int main(){
    node head = initHead();
    head = readData(head, "DS_CAC_TINH.txt");
    traverser(head);
    int option;
    City result;
    while (TRUE) {
        printMenu();
        printf("Nhap lua chon cua ban (1-10): ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                traverser(head);
                break;
            case 2:
                head = addnode(head);
                break;
            case 3:
                editnode(head);
                break;
            case 4:
                head = removenode(head);
                break;
            case 5:
                printf("Tong dien tich: %f\n", sumArea(head));
                break;
            case 6:
                printf("Tinh co dien tich lon nhat o vi tri: %d\n", indexOfMaxArea(head) + 1); // vị trí = chỉ số + 1
                break;
            case 7:
                result = maxByPopulation(head);
                printf("%s la noi co dien tich lon nhat voi %d nguoi!\n", result.name, result.population);
                break;
            case 8:
                sortCities(head, 1, 0, 0);
                traverser(head);
                break;
            case 9:
                sortCities(head, 0, 1, 0);
                traverser(head);
                break;
            case 10:
                printf("Ket thuc chuong trinh!...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Lua chon khong dung, vui long nhap lai!\n");
                break;
        }
    }
    freelist(head);
}