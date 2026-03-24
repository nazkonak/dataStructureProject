#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    char name[30];
    char surname[30];
    int year;
    float ects;
    float grade;
    
}student;

typedef struct Tnode{
    student data;
    struct Tnode* left;
    struct Tnode* right;
    int height;
}Tnode;


void CreateArray(student** student, int *count);
void SearchStudent(student* student, int count);
int Height(Tnode* root);
student CreateStudent();
Tnode* InsertBST(Tnode* root, student *newStudent);
Tnode* CreateNode(student* newStudent);
Tnode* SearchTree(Tnode* root, int id);
void CreateAVL();
Tnode* InsertAVL(Tnode* node, student* newStudent);
Tnode* LeftRotate(Tnode* x);
Tnode* RightRotate(Tnode* y);
int GetBalance(Tnode* node);
void Inorder(Tnode* root);

int main(){
    Tnode* root=NULL;
    int count=0; 
    student* students=(student*)malloc(sizeof(student));

    /*student s1 = {1, "Ali", "Yilmaz", 2020, 30.0, 85.5};
    student s2 = {2, "Ayşe", "Kara", 2021, 28.0, 90.0};
    student s3 = {3, "Fatma", "Demir", 2019, 32.0, 88.0};
    root = InsertBST(root, &s1);
    root = InsertBST(root, &s2);
    root = InsertBST(root, &s3);
    printf("Height of BST: %d\n", Height(root)); // Beklenen sonuç: 1

    return 0;*/
    
    while(1){
    printf("\nSelect option:\n");printf("1- Array Data Structre\n");printf("\n2- BST Data Structre\n");printf("\n3- AVL Data Structre\n");printf("\n4- Cikis\n");
    int id, height;
    int choice, c;
    scanf("%d", &choice);
    switch(choice){
        case 1:
        do{
            printf("\nSelect option:\n");printf("\n1- Create Array\n");printf("\n2- Search a Student\n");printf("\n3- Return Main Menu\n");
            scanf("%d", &c);
            switch(c){
                case 1:
                    CreateArray(&students, &count);
                    break;
                case 2:
                    SearchStudent(students, count);
                    break;
                case 3: 
                    break;
                default:
                    printf("\ninvalid enter, try again\n");
                }
        }while(c!=3);
        break;
        
        case 2:
        do{
         printf("\nSelect option:\n");printf("1- Create BST\n");printf("\n2- Search a student\n"); printf("\n3- Height\n");;printf("4- Delete a Node\n");printf("\n5- Return Main Menu\n");
         scanf("%d", &c);

            switch(c){
                case 1:
                student newStudent = CreateStudent();
                    root=InsertBST(root,&newStudent);
                    break;
                case 2:
                    int stid=0;
                    printf("\nEnter ID of the Student: ");
                    scanf("%d",&stid);
                    SearchTree(root, stid);
                    break;
                case 3:
                    Inorder(root);
                    Height(root);
                    printf("\nHeight of this tree: %d\n",Height(root));
                    break;
                    case 4:
                        /*printf("id: \n");
                        scanf("%d", id);
                        Delete(Tnode* root, id);*/
                        break;
                case 5:
                    break;
                default: printf("\ninvalid enter, try again\n");  
            }
        }while(c!=4);
        break;
            
        case 3:
        do{
            printf("\nSelect option:\n");printf("\n1- Create AVL\n");printf("\n2- Search a student\n");printf("\n3- Height\n"); printf("\n4-Main Menu\n");
            scanf("%d", &c);
            switch(c){
                
                case 1:
                    student newStudent= CreateStudent();
                    root=InsertAVL(root,&newStudent);
                    break;
                case 2:
                    int stid=0;
                    printf("\nEnter ID of the Student: ");
                    scanf("%d",&stid);
                    SearchTree(root, stid);
                    break;
                case 3:
                    Inorder(root);
                    Height(root);
                    printf("\nHeight of this tree: %d\n",Height(root));
                    break;
                case 4:
                    break;
                default:
                    printf("\ninvalid entry\n");
                
                }
            }while(c != 4);
            break;
        }
            if(choice==4) {printf("\nExiting program\n"); free(students); break;}   
        
    }
}
    


void CreateArray(student** array, int *count){
    printf("\nEnter details of student:\n");

    printf("ID: ");
    scanf("%d", &(*array)[*count].id);
    printf("Enter Name:");
    scanf("%s", (*array)[*count].name);
    printf("Enter Surname:");
    scanf("%s", (*array)[*count].surname);
    printf("Enter Year:");
    scanf("%d", &(*array)[*count].year);
    printf("Enter ECTS:");
    scanf("%f", &(*array)[*count].ects);
    printf("Enter Grade:");
    scanf("%f", &(*array)[*count].grade);

    (*count)++;
    *array = realloc(*array, (*count + 1) * sizeof(student));
    printf("\nstudent successfully added\n");

}

void SearchStudent(student* array, int count){
    if(count==0){printf("no student in the list"); return;}
        
    else{
        printf("Enter ID of the Student: ");
        int stid=0;
        scanf("%d",&stid);

        for(int i=0;i <count;i++){
            if(array[i].id==stid){
                printf("\nStudent Details:\n");
                printf("\nID: %d",array[i].id);
                printf("\nName: %s",array[i].name);
                printf("\nSurname: %s",array[i].surname);
                printf("\nYear: %d",array[i].year);
                printf("\nECTS: %.2lf",array[i].ects);
                printf("\nGrade: %.2lf",array[i].grade);
                return;
            }
        }
        printf("\nStudent with ID %d not found.\n", stid);
    } 
}
student CreateStudent(){
    
    student newStudent;
    printf("ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter Name:");
    scanf("%s", newStudent.name);
    printf("Enter Surname:");
    scanf("%s",  newStudent.surname);
    printf("Enter Year:");
    scanf("%d", &newStudent.year);
    printf("Enter ECTS:");
    scanf("%f", &newStudent.ects);
    printf("Enter Grade:");
    scanf("%f", &newStudent.grade);
    return newStudent;
}
Tnode *CreateNode(student *newStudent){
    
    Tnode* newNode=(Tnode*)malloc(sizeof(Tnode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }   
    newNode->data= *newStudent;
    newNode->left=newNode->right=NULL;
    printf("\nstudent successfully added\n");
    return newNode;    
}
/*Tnode* Delete(Tnode* root, int x){
    Tnode* p, *q;
    if(root==NULL) return NULL;
    if(root->data==x){
        if(root->left==root->right){free(root); return NULL;}
        else{
            if(root->left==NULL){p=root->right; free(root); return p;}
            else if(root->right==NULL){p=root->left; free(root);return p;}
            else{
                p=q=root->right;
                while(p->left!=NULL){
                    p=p->left;
                }
                p->left=root->left;
                free(root);
                return q;
            }        
        }
    }
    else if(root->data < x){root->right=Delete(root->right,x);}
    else{root->left=Delete(root->left,x);}
    return root;
}*/
Tnode* InsertBST(Tnode* root, student *newStudent){
    if (root == NULL){
        return CreateNode(newStudent); // Yeni düğüm root olur
    }
    if (newStudent->id < root->data.id) {
        root->left = InsertBST(root->left, newStudent);
    } else if (newStudent->id > root->data.id) {
        root->right = InsertBST(root->right, newStudent);
    } else {
        printf("Duplicate ID! Node not inserted.\n");
    }
    return root; // Kök düğümü geri döndür
}

Tnode* SearchTree(Tnode *root, int stid){
    
     if(root==NULL){printf("\nno student in the list\n"); return root;}
        
    else{
        if (root->data.id == stid) {
            printf("\nStudent Details:\n");
            printf("\nID: %d", root->data.id);
            printf("\nName: %s", root->data.name);
            printf("\nSurname: %s", root->data.surname);
            printf("\nYear: %d", root->data.year);
            printf("\nECTS: %.2lf", root->data.ects);
            printf("\nGrade: %.2lf", root->data.grade);
            return root;
    } else if (stid < root->data.id) {
        return SearchTree(root->left, stid); // Search in the left subtree
    } else {
        return SearchTree(root->right, stid); // Search in the right subtree
    }
    printf("\nStudent with ID %d not found.\n", stid);
    }
    
}

int Height(Tnode* root){
    if(root==NULL){return -1;}
    else{
        int left_height=Height(root->left);
        int right_height=Height(root->right);
        if(right_height>left_height)
            {return right_height+1;}
        else
        {return left_height+1;}
    }
}

void Inorder(Tnode* root){
    if(root!=NULL){
        Inorder(root->left);
        printf("ID: %d, Name: %s,Surname: %s\n", 
        root->data.id, 
        root->data.name, 
        root->data.surname);
        Inorder(root->right);
    }
}

int AVLHeight(Tnode* node) {
    if (node == NULL) {
        return 0; // NULL düğüm için yükseklik 0 kabul edilir
    }
    return node->height;
}

int GetBalance(Tnode* node) {
    if (node == NULL) {
        return 0;
    }
    return AVLHeight(node->left) - AVLHeight(node->right);
}

Tnode* LeftRotate(Tnode* x) {
    Tnode* y = x->right;
    Tnode* temp=y->left;

    // Rotasyon işlemi
    y->left = x;
    x->right = temp;

    // Yükseklikleri güncelle
    if (AVLHeight(x->left) > AVLHeight(x->right)) {
    x->height = 1 + AVLHeight(x->left);
    } else {
    x->height = 1 + AVLHeight(x->right);
    }

    if (AVLHeight(y->left) > AVLHeight(y->right)) {
    y->height = 1 + AVLHeight(y->left);
    } else {
    y->height = 1 + AVLHeight(y->right);
    }

    return y;  // Yeni kök
}

Tnode* RightRotate(Tnode* y) {
    Tnode* x = y->left;
    Tnode* temp = x->right;

    // Rotasyon işlemi
    x->right = y;
    y->left = temp;

    // Yükseklikleri güncelle
    if (AVLHeight(y->left) > AVLHeight(y->right)) {
    y->height = 1 + AVLHeight(y->left);
    } else {
    y->height = 1 + AVLHeight(y->right);
    }

    if (AVLHeight(x->left) > AVLHeight(x->right)) {
    x->height = 1 + AVLHeight(x->left);
    } else {
    x->height = 1 + AVLHeight(x->right);
    }
    return x;  // Yeni kök
}

Tnode* InsertAVL(Tnode* node, student* newStudent){
    if (node == NULL) {
        Tnode* newNode = CreateNode(newStudent);
        return newNode;
    }

    if (newStudent->id < node->data.id) {
        node->left = InsertAVL(node->left, newStudent);
    } else if (newStudent->id > node->data.id) {
        node->right = InsertAVL(node->right, newStudent);
    } else {
        printf("Duplicate ID! Node not inserted.\n");
        return node;
    }

    // 2. Yükseklikleri güncelle
    if (AVLHeight(node->left) > AVLHeight(node->right)) {
    node->height = 1 + AVLHeight(node->left);
    } else {
    node->height = 1 + AVLHeight(node->right);
    }   

    // 3. Dengeyi kontrol et ve gerekirse rotasyon yap
    int balance = GetBalance(node);

    // Sol sol durumu (Left Left Case)
    if (balance > 1 && newStudent->id < node->left->data.id) {
        return RightRotate(node);
    }

    // Sağ sağ durumu (Right Right Case)
    if (balance < -1 && newStudent->id > node->right->data.id) {
        return LeftRotate(node);
    }

    // Sol sağ durumu (Left Right Case)
    
    

    // Sağ sol durumu (Right Left Case)
    if (balance < -1 && newStudent->id < node->right->data.id) {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    // Düğümün dengelendiği durumda, düğümü geri döndür
    return node;
}









   





