/*
    Members name                                       IDNO

1.	Aledya Tekalgn ------------------------------------  1307786
2.	Esubalew Sintie------------------------------------  1307570
3.	Fekadu Sisay---------------------------------------  1306120
4.	Feven Tesfaye--------------------------------------  1307726
5.	Hildana Shisema -----------------------------------  1307582
6.	Nigist Genene -------------------------------------  1307538
7.	Nigist Woldemicael -------------------------------  1308041

*/

#include<iostream>
#include<fstream>
#include <iomanip>
#include<cstring>
#include<string>
#include<unistd.h>
using namespace std;
    struct Emp_node{
        Emp_node * right;
        Emp_node * left;
        char Fullname[30];
        char ID[10];
        char sex[6];
        int age;
        double salary;
        char position[20];
        char education_Level[20];
        int  height;
    };
    int nodeNum ,w;

        fstream myfile;
Emp_node * root=NULL;
int n=1;
Emp_node* searchBySalary(Emp_node*root,int salary);
//creating new employee
Emp_node* insertedNode(Emp_node *fileNode ){
 if(root == NULL)
        root = fileNode;
    else{
    Emp_node  *i = root;
    Emp_node *t=searchBySalary(root,fileNode->salary);
    if (t==NULL){
    bool isInserted = false;
    while(isInserted == false){
    if (i ->salary  > fileNode -> salary){
        if (i -> left == NULL){
            i -> left = fileNode;
            isInserted = true;
                }
            else
            i = i -> left;
            }
            else
            {
            if (i -> right == NULL){
                i -> right = fileNode;
                    isInserted = true;
                }
            else
            i = i -> right;
            }
        }
    }
    }
nodeNum++;
}
void insertKeybordtoBST( ){
Emp_node *new_node=new Emp_node();
 cout<<"\n\t\t\t\t\t\ Employee's Name: ";
 cin>>new_node->Fullname;
 s:
 cout<<"\n\t\t\t\t\t\ Enter the Id Number: ";
 cin>>new_node->ID;

 cout<<"\n\t\t\t\t\t\ sex: ";
 cin>>new_node->sex;
 w:
 cout<<"\n\t\t\t\t\t\ Enter age: ";
 cin>>new_node->age;
 if(cin.fail()){
cin.clear();
  cin.ignore();
 goto w;
 }

 cout<<"\n\t\t\t\t\t\ Enter salary: ";
 cin>>new_node->salary;
 if(cin.fail()){
cin.clear();
  cin.ignore();
 goto w;
 }
 cout<<"\n\t\t\t\t\t\ Enter the position: ";
 cin>>new_node->position;
 cout<<"\n\t\t\t\t\t\ Enter the education level: ";
  cout<<"\n\t\t\t\t\t\  ";

 cin>>new_node->education_Level;
 new_node->left=NULL;
 new_node->right=NULL;
 if(root==NULL){
        root=new_node;
        new_node->left=NULL;
        new_node->right=NULL;
      }else {
      Emp_node * temp = root;
      while (temp != NULL) {
        if (new_node -> salary == temp -> salary) {
                cout<<"\n\t\t\t\t\t\  please enter unique salary, this is already existed"<<endl<<endl;
          return;
        }
        else if ((new_node -> salary < temp -> salary) && (temp -> left == NULL)) {
          temp -> left = new_node;
          break;
        }
        else if (new_node -> salary < temp -> salary) {
          temp = temp -> left;
        }
        else if ((new_node -> salary > temp -> salary) && (temp -> right == NULL)) {
          temp -> right = new_node;
          break;
        }

      else {
          temp = temp -> right;
        }
      }
    }
}
void insertFiletoBST(){
    int employee;
     char newFullname[30];
        char newID[10];
        char newSex[6];
        int newage;
        double newsalary;
        char newposition[20];
        char neweducation_Level[20];
 ifstream file;
char filename[20];
cout<<"\n\t\t\t\t\t\t\t\ Enter the name of the file on which you want insert to BST   ";
cin>>filename;
 file.open(strcat(filename,".txt"));

    i: cout<<"\n\t\t\t\t\t\t\t\ Enter the number of employee you want to record to the file    "<<endl<<"\t\t";
  cout<<"\n\t\t\t\t\t\t\t\ >>";

    cin>>employee;
    if (cin.fail())
    {
        cout<<endl<<"\n\t\t\t\t\t\t\t\ Invalid Input."<<endl;
        cin.clear();
        cin.ignore();
        goto i;
    }
 if(file.is_open()){
    for(int i=0;i<employee;i++){
    Emp_node * temp= new Emp_node;
            file>>newFullname;
            strcpy(temp ->Fullname,newFullname);

            file>>newID;
            strcpy(temp -> ID, newID);

            file>>newSex;
             strcpy(temp ->sex,newSex);

            file>>newage;
            temp -> age = newage;
            file>>newsalary;
            temp -> salary=newsalary;

            file>>newposition;
             strcpy(temp ->position,newposition);
            file>>neweducation_Level;
             strcpy(temp ->education_Level,neweducation_Level);

            temp -> left = NULL;
            temp -> right = NULL;
            insertedNode(temp);
    }
    system("cls");
        cout<<"\n\t\t\t\t\t\t\t\ Done data has been added to the BST successfully!"<<endl;
file.close();
 }
 else
        cout<<"\n\t\t\t\t\t\t\t\ Error opening file!"<<endl;
}

Emp_node* minimum(Emp_node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Emp_node* maximum(Emp_node* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
void display_fun(Emp_node* temp1)
{
     cout<<left;
     cout<<"|"<<setw(25)<<temp1->Fullname;
     cout<<"|"<<setw(10)<<temp1->ID;
      cout<<"|"<<setw(10)<<temp1->sex<<left;
      cout<<"|"<<setw(10)<<temp1->age;
      cout<<"|"<<setw(10)<<temp1->salary;
     cout<<"|"<<setw(20)<<temp1->position<<left;
     cout<<"|"<<setw(20)<<temp1->education_Level<<"|"<<endl;
    cout<<"|_________________________|__________|__________|__________|__________|____________________|____________________|"<<endl;

}
void upper_discription()
{
    cout<<"_________________________________________________________________________________________________________________"<<endl;
    cout<<left;
    cout<<"|"<<setw(25)<<"Full name";
   cout<<"|"<<setw(10)<<"ID number";
   cout<<"|"<<setw(10)<<"Sex ";
   cout<<"|"<<setw(10)<<"Age";
   cout<<"|"<<setw(10)<<"Salary";
    cout<<"|"<<setw(20)<<"Position";
    cout<<"|"<<setw(20)<<" Education Level"<<right<<"|";
    cout<<right;
    cout<<endl;
    cout<<"|_________________________|__________|__________|__________|__________|____________________|____________________|"<<endl;

}
void inorder(Emp_node* root){
    if(root==NULL){
    return;
}
else{
inorder(root->left);
display_fun(root);
    inorder(root->right);
}
}
void preorder(Emp_node* root){
    if(root==NULL)
    return;
    else{
    display_fun(root);
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(Emp_node* root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    display_fun(root);

}

Emp_node* writeBSTtofile(Emp_node *temp) {
     if(temp != NULL){
            writeBSTtofile(temp->left);
            myfile<<temp->Fullname<<" ";
            myfile<<temp->ID<<" ";
            myfile<<temp->sex<<" ";
            myfile<<temp->age<<" ";
            myfile<<temp->salary<<" ";
            myfile<<temp->position<<" ";
            myfile<<temp->education_Level<<" ";
            myfile<<endl;
            writeBSTtofile(temp->right);
    }
  }
Emp_node* searchByName(Emp_node*root,char name[]){
    if(root==NULL)
        return root;
    else{
        if(strcmp(root->Fullname,name)==0){
            return root;
        }
        else if(strcmp(root->Fullname,name)>0)
            root=searchByName(root->left,name);
        else
            root=searchByName(root->right,name);
    }
}

Emp_node* searchByAge(Emp_node*root,int age){
    if(root==NULL)
        return root;
    else{
        if(root->age==age){
            return root;
        }
        else if(root->age>age)
            root=searchByAge(root->left,age);
        else
            root=searchByAge(root->right,age);
    }
}
Emp_node* searchBySalary(Emp_node*root,int salary){
    if(root==NULL)
        return root;
    else{
        if(root->salary==salary){
            return root;
        }
        else if(root->salary>salary)
            root=searchBySalary(root->left,salary);
        else
            root=searchBySalary(root->right,salary);
    }
}
Emp_node* searchByID(Emp_node*root,char ID[]){
    if(root==NULL)
        return root;
    else{
        if(strcmp(root->ID,ID)==0){
            return root;
        }
        else if((strcmp(root->ID,ID)>0))
            root=searchByID(root->left,ID);
        else
            root=searchByID(root->right,ID);
    }
}
Emp_node* searchBySex(Emp_node*root,char Sex[]){
    if(root==NULL)
        return root;
    else{
        if(strcmp(root->sex,Sex)==0){
            return root;
        }
        else if((strcmp(root->sex,Sex)>0))
            root=searchBySex(root->left,Sex);
        else
            root=searchBySex(root->right,Sex);
    }
}
Emp_node* searchByPosition(Emp_node*root,char position[]){
    if(root==NULL)
        return root;
    else{
        if(strcmp(root->position,position)==0){
            return root;
        }
        else if((strcmp(root->position,position)>0))
            root=searchByPosition(root->left,position);
        else
            root=searchByPosition(root->right,position);
    }
}
Emp_node* searchByEducationLevel(Emp_node*root,char education_Level[]){
    if(root==NULL)
        return root;
    else{
        if(strcmp(root->education_Level,education_Level)==0){
            return root;
        }
        else if((strcmp(root->education_Level,education_Level)>0))
            root=searchByEducationLevel(root->left,education_Level);
        else
            root=searchByEducationLevel(root->right,education_Level);
    }
}
int CountNodes(Emp_node*root)
{
	if(root==NULL)
		return 0;
	else
	return 1+CountNodes(root->left)+CountNodes(root->right);
}
void deleterootNode(Emp_node* &root) {
    if (root == nullptr){
        cout<<"\n\t\t\t\t\t\t\t\ No employee found to be deleted!!!"<<endl;
    return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        root = nullptr;
           delete root;
    } else if (root->left == nullptr) {
        Emp_node* temp = root;
        root = root->right;
        delete temp;
    } else if (root->right == nullptr) {
        Emp_node* temp = root;
        root = root->left;
        delete temp;
    } else {
        Emp_node* temp = root->right;
        while (temp->left != nullptr)
            temp = temp->left;
        root->salary = temp->salary;
        delete temp;
    }
}
Emp_node* Deleteminimum(Emp_node* &root){
Emp_node* predec=root;
Emp_node* succe;
Emp_node*temp;
if(root->left==NULL && root->right==NULL){
    root=NULL;
    delete root;
}
else if(root->left==NULL){
 deleterootNode(root);
}
else{
while(predec->left!=NULL){
        succe=predec;
    predec=predec->left;
}
if(predec->right==NULL){
succe->left=NULL;
delete predec;
}
else{
    succe->left=predec->right;
    delete predec;
}
}
}
Emp_node* Deletemaximum(Emp_node* &root){
Emp_node* predec=root;
Emp_node* succe;
Emp_node*temp;
if(root->left==NULL && root->right==NULL){
    root=NULL;
    delete root;
}
else if(root->right==NULL){
 deleterootNode(root);
}
else{
while(predec->right!=NULL){
        succe=predec;
    predec=predec->right;
}
if(predec->left==NULL){
succe->right=NULL;
delete predec;
}
else{
    succe->right=predec->left;
    delete predec;
}
}
}
void inputvalidate()
{
      system("cls");
      cout<<"\n\t\t\t\t\t\ You entered wrong number!!!, Please Try Again \n\n";
      cin.clear();
      cin.ignore();
}

int height(Emp_node *root) {
if(root == nullptr) return 0;
int leftHeight = height(root->left);
int rightHeight = height(root->right);
return 1 + max(leftHeight, rightHeight);
}
void leftRotate(Emp_node *&root) {
Emp_node *newRoot = root->right;
root->right = newRoot->left;
newRoot->left = root;
root = newRoot;
}
void rightRotate(Emp_node *&root) {
Emp_node *newRoot = root->left;
root->left = newRoot->right;
newRoot->right = root;
root = newRoot;
}
void AVLBalancing(Emp_node *&root) {
int heightDifference = height(root->left) - height(root->right);
if(heightDifference > 1) {
int leftHeightDifference = height(root->left->left) - height(root->left->right);
if(leftHeightDifference > 0) {
rightRotate(root);
}
else {
leftRotate(root->left);
rightRotate(root);
}
}
else if(heightDifference < -1) {
int rightHeightDifference = height(root->right->left) - height(root->right->right);
if(rightHeightDifference < 0) {
leftRotate(root);
}
else {
rightRotate(root->right);
leftRotate(root);
}
}
}

int main(){
system("color 0A");
while(true){
D:
cout<<"\n\t\t\t\t\t\   ____________________________________________________________________________";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||               EMPLOYEE MANAGMENT SYSTEM                                    ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '1' to Insert new employee                                         ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '2' to Insert new employee from file                               ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '3' to Write all employees to the file                             ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '4' to Search employee                                             ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '5' to Count the total number of employees                         ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '6' to Delete employee                                             ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout << "\n\t\t\t\t\t\ ||   press '7' to Display all employees                                       ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '8' to Balance the employee tree using AVL balanced rotation       ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout << "\n\t\t\t\t\t\ ||   press '0' to exit                                                        ||";
cout<<"\n\t\t\t\t\t\ ||____________________________________________________________________________||";
cout << "\n\n\n\t\t\t\t\t\t\t\ What do you want to do? >>";
int a;
cin>>a;
  if(cin.fail() || a<0)
              {
              inputvalidate();
              goto D;
              }
    system("cls");
switch(a){
case 1:{cout << "\n\t\t\t\t\t\t\t\ Insert new employee"<<endl;
N:cout << "\n\t\t\t\t\t\ How many employees do you want to register      ";
int b;
cin>>b;
  if(cin.fail() || a<0)
              {
              inputvalidate();
              goto N;
              }
    system("cls");
for(int i=1;i<=b;i++){
 cout<<"\n\t\t\t\t\t\ Please enter the information Of employee "<<i<<endl;
    insertKeybordtoBST();
}
system("cls");
break;
}
case 2:{
 insertFiletoBST();
break;
}
case 3:{
  cout << "\n\t\t\t\t\t\t\t\ Write all employees to the file"<<endl;
//upper_discription_writing();
char filename[20];
cout<<"\n\t\t\t\t\t\t\t\ Enter the name of the file on which you want to write the info  "<<endl;
  cout<<"\n\t\t\t\t\t\t\t\ >>";
cin>>filename;
if(strcmp(filename,"AOA")!=0){

myfile.open( strcat(filename,".txt"),ios::out);
writeBSTtofile(root);
myfile.close();
cout<<"\n\t\t\t\t\t\t\t\ Employee list saved successfully";
}
else{

myfile.open("AOA.txt",ios::app);
writeBSTtofile(root);
myfile.close();
cout<<"\n\t\t\t\t\t\t\t\ Employee list saved successfully";
}
break;
}
case 4:{
    bool t=true;
    while(t){
   I:cout<<"\n\t\t\t\t\t\t\t   ____________________________________________________________________________";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          By which attribute do you want to search?                         ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          press 1 to search by Name                                         ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          press 2 to search by ID                                           ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          press 3 to search by Sex                                          ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          press 4 to search by Age                                          ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          press 5 to search by Salary                                       ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          press 6 to search by Position                                     ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          press 7 to search by Education Level                              ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          press 8 to return back                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||                                                                            ||";
     cout<<"\n\t\t\t\t\t\t\t ||          Press 0 to exit                                                   ||";
     cout<<"\n\t\t\t\t\t\t\t ||____________________________________________________________________________||"<<endl<<endl;
     cout<<"\n\t\t\t\t\t\                       >>";
     int f;
     cin>>f;
      if(cin.fail() || a<0)
              {
              inputvalidate();
              goto I;
              }
        system("cls");
     switch(f){
     case 1:
         {
     char d[30];
cout<<"\n\t\t\t\t\t\t\t\t Enter the name to be searched  ";
cin>>d;
Emp_node* e=new Emp_node();
e=searchByName(root,d);
if(e==NULL){
    cout<<"\n\t\t\t\t\t\t\t\t  The data you searched is not found!  ";
}
else{
upper_discription();
display_fun(e);
}

break;
     }
     case 2:{
              char d[10];
cout<<"\n\t\t\t\t\t\t\t\t  Enter the id to be searched   ";
cin>>d;
Emp_node* h=new Emp_node();
h=searchByID(root,d);
if(h==NULL){
    cout<<"\n\t\t\t\t\t\t  The data you searched is not found!"<<endl;
}
else{
upper_discription();
display_fun(h);
}

break;
         }
     case 3:{
          char d[6];
cout<<"\n\t\t\t\t\t\t\t\t  Enter the sex to be searched   ";
cin>>d;
Emp_node* e=new Emp_node();
e=searchBySex(root,d);
if(e==NULL){
    cout<<"\n\t\t\t\t\t\t\t\t  The data you searched is not found!"<<endl;
}
else{
upper_discription();
display_fun(e);
}

break;
     }
     case 4:{
   system("cls");
    int d;
J:cout<<"\n\t\t\t\t\t\t\t\t  Enter the age to be searched   ";
cin>>d;
 if(cin.fail() || a<0)
              {
              inputvalidate();
              goto J;
              }
Emp_node* g=new Emp_node();
g=searchByAge(root,d);
if(g==NULL){
    cout<<"\n\t\t\t\t\t\t\t\t  The data you searched is not found!"<<endl;
}
else{
upper_discription();
display_fun(g);
}
break;
}
case 5:{
              int d;
M:cout<<"\n\t\t\t\t\t\t\t\t  Enter the salary to be searched   ";
cin>>d;
 if(cin.fail() || a<0)
              {
              inputvalidate();
              goto M;
              }
Emp_node* h=new Emp_node();
h=searchBySalary(root,d);
if(h==NULL){
    cout<<"\n\t\t\t\t\t\t\t\t  The data you searched is not found!   ";
}
else{
upper_discription();
display_fun(h);
}

break;
}
case 6:{
    char d[20];
cout<<"\n\t\t\t\t\t\t\t\t  Enter the position of the employee to be searched    ";
cin>>d;
Emp_node* h=new Emp_node();
h=searchByPosition(root,d);
if(h==NULL){
    cout<<"\n\t\t\t\t\t\t\t\t  The data you searched is not found!"<<endl;
}
else{
upper_discription();
display_fun(h);
}

break;
}
case 7:{
              char d[10];
cout<<"\n\t\t\t\t\t\t\t\t Enter the Education level to be searched    ";
cin>>d;
Emp_node* h=new Emp_node();
h=searchByEducationLevel(root,d);
if(h==NULL){
    cout<<"\n\t\t\t\t\t\t\t\t  The data you searched is not found!"<<endl;
}
else{
upper_discription();
display_fun(h);
}

break;
     }
case 8:{
system("cls");
goto D;
    break;
}
case 0:{
exit(0);
    break;
}
default:
    cout<<"\n\t\t\t\t\t\t\t\t You entered wrong number"<<endl;
     }
     }

}
case 5:{
    cout<<"\n\t\t\t\t\t\t\t\t Count the total number of employees"<<endl;
    int count=CountNodes(root);
         cout<<"\n\t\t\t\t\t\t\t\t There are a total of "<<count<<" employees"<<endl;
break;
}
case 6:{
    bool t=true;
    while(t){
cout<<"\n\t\t\t\t\t\   ____________________________________________________________________________";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '1' to Delete the root node(employee)                              ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '2' to Delete the employee with minimum ID                         ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '3' to Delete the employee with maximum ID                         ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '4' to return back                                                 ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '0' to exit                                                        ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||____________________________________________________________________________||"<<endl<<endl<<endl;
cout<<"\n\t\t\t\t\t\                       >>";
 int choice;
 cin>>choice;
 switch(choice){
      case 1:{
    system("cls");
cout<<"\n\t\t\t\t\t\t\t\t Delete the root node"<<endl;
deleterootNode(root);
cout<<"\n\t\t\t\t\t\t\t\t\t You have deleted the root node successfully!!!"<<endl;
break;
}
case 2:{
system("cls");
cout<<"\n\t\t\t\t\t\t\t\t Delete the employee with minimum salary"<<endl;
Deleteminimum(root);
 cout<<"\n\t\t\t\t\t\t\t\t\t You have deleted the node with the minimum salary successfully!!!"<<endl;
break;
}
case 3:{
system("cls");
cout<<"\n\t\t\t\t\t\t\t\t Delete the employee with maximum salary"<<endl;
Deletemaximum(root);
 cout<<"\n\t\t\t\t\t\t\t\t\t You have deleted the node with the maximum salary successfully!!!"<<endl;
break;
}
case 4:{
      system("cls");
   goto D;
}
case 0:{
exit(0);
break;
}
default:{
cout<<"\n\t\t\t\t\t\t\t\ you entered wrong number";
break;
}
}
}
}
case 7:{
    bool t=true;
    while(t){
cout<<"\n\t\t\t\t\t\  ____________________________________________________________________________";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '1' to Display all employees using preorder                        ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '2' to Display all employees using postorder                       ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '3' to Display all employees using inorder                         ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '4' to Display the employee with the minimum ID                    ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '5' to Display the employee with the maximum ID                    ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||   press '6' to return back                                                 ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||  press '0' to exit                                                         ||";
cout<<"\n\t\t\t\t\t\ ||                                                                            ||";
cout<<"\n\t\t\t\t\t\ ||____________________________________________________________________________||"<<endl<<endl<<endl;
cout<<"\n\t\t\t\t\t\                       >>";

int choice;
 cin>>choice;
 switch(choice){
     case 1:{
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t Display all employees using preorder"<<endl;
    upper_discription();
preorder(root);
break;
}
case 2:{
system("cls");
cout<<"\n\t\t\t\t\t\t\t\ Display all employees using postorder"<<endl;
upper_discription();
postorder(root);
break;
}
case 3:{
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t Display all employees using inorder"<<endl;
upper_discription();
inorder(root);
break;
}
case 4:{
    system("cls");
cout<<"\n\t\t\t\t\t\t\t\ Display the employee with the minimum Salary"<<endl;
Emp_node * c=new Emp_node();
c=minimum(root);
upper_discription();
display_fun(c);
break;
}
case 5:{
    system("cls");
cout<<"\n\t\t\t\t\t\t\t\ Display the employee with the maximum Salary"<<endl;
Emp_node * c=new Emp_node();
c=maximum(root);
upper_discription();
display_fun(c);
break;
}
case 6:{
        system("cls");
   goto D;
}
case 0:{
exit(0);
break;
}
default:{
cout<<"\n\t\t\t\t\t\t\t\ you entered wrong number";
break;
}
}
}
}
case 8:{
     system("cls");
cout<<"\n\t\t\t\t\t\t\t\  Balance the employee tree using AVL balanced rotation"<<endl;
AVLBalancing(root);
break;
}
case 0:exit(0);
break;
default:cout<<"\n\t\t\t\t\t\t\t\ Wrong input!!!"<<endl;
}
}
}
