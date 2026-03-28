#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>


struct BankAccount{
    int AccountNumber;
    char Name[50];
    char MobileNumber[15];
    float Balance;
    int PIN;
    char transactions[5][50];
    int transactionCount;
    struct BankAccount *next;
 };
 struct BankAccount *head=NULL;
 

//  Save function 
void saveToFile(){
    FILE *fp = fopen("accounts.txt", "w");

    struct BankAccount *temp = head;

    while(temp != NULL){
        fprintf(fp, "%d %s %s %f %d %d\n",
            temp->AccountNumber,
            temp->Name,
            temp->MobileNumber,
            temp->Balance,
            temp->PIN,
            temp->transactionCount);

              // Transactions save karo
        for(int i=0; i<temp->transactionCount; i++){
            fprintf(fp, "%s\n", temp->transactions[i]);
        }
        temp = temp->next;
    }

    fclose(fp);
}

//Read function
void loadFromFile(){
    FILE *fp = fopen("accounts.txt", "r");

    if(fp == NULL){
        return;
    }

    while(1){
        struct BankAccount *newAccount;
        newAccount = (struct BankAccount*)malloc(sizeof(struct BankAccount));

        if(fscanf(fp, "%d %s %s %f %d %d",
            &newAccount->AccountNumber,
            newAccount->Name,
            newAccount->MobileNumber,
            &newAccount->Balance,
            &newAccount->PIN,
            &newAccount->transactionCount)!= 6){
            free(newAccount);
            break;
        }

          // Transactions load karo
        for(int i=0; i<newAccount->transactionCount; i++){
            fscanf(fp, " %[^\n]", newAccount->transactions[i]);
        }

        newAccount->next = head;
        head = newAccount;
    }

    fclose(fp);
}



 bool Duplicate(int accNo){
    struct BankAccount *temp = head;
    while(temp != NULL){
        if(temp->AccountNumber == accNo){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

 void CreateAccount(){
     struct BankAccount *newAccount;
     newAccount=(struct BankAccount*)malloc(sizeof(struct BankAccount));
     // Auto generate account number and check duplicate until its get a unique Accno.
    do{
    newAccount->AccountNumber = rand() % 9000 + 1000;
}while(Duplicate(newAccount->AccountNumber));

     printf("\nEnter customer/User Name:");
     scanf("%s", newAccount->Name);

     printf("\nEnter user Mobile Number:");
     scanf("%s", newAccount->MobileNumber);

     printf("\nEnter opening Amount of Your Bank:");
     scanf("%f", &newAccount->Balance);

    printf("\n you get Account Number is: %d", newAccount->AccountNumber);

    printf("\nSet 4-digit PIN: ");
    scanf("%d",&newAccount->PIN);

    newAccount->transactionCount = 0;

     newAccount->next=head;
     head=newAccount;

    printf("\nYou Create your Account in Abhi Bank Successfully !"); 
    
    saveToFile();
}

void addTransaction(struct BankAccount *acc, char msg[]){
    if(acc->transactionCount < 15){
        strcpy(acc->transactions[acc->transactionCount], msg);
        acc->transactionCount++;
    }
}



void Deposite(){
    int AccNo;
    printf("\nEnter Account Number to Deposite money....:");
    scanf("%d",&AccNo);



    struct BankAccount *temp;
    temp=head;
    bool boolean=false; 
    while(temp!=NULL){
        if(temp->AccountNumber==AccNo){

   int i=1;
int pin;
while(i<=3){
    printf("\nEnter PIN: ");
    scanf("%d",&pin);

    if(pin == temp->PIN){
        break;
    } else {
        printf("\nWrong PIN!");
        i++;
    }
}

if(i>3){
    printf("\nToo many wrong attempts!");
    return;
}
    int DepositeAmount;
    printf("\nEnter the amount You want to deposite:");
    scanf("%d",&DepositeAmount);

    temp->Balance += DepositeAmount;
    printf("\nDeposite money Successfully !");  
    printf("\nUpdated Balance: %.2f\n", temp->Balance); 


    char msg[50];
sprintf(msg, "Deposited %d", DepositeAmount);
addTransaction(temp, msg);
    
saveToFile();
     boolean=true;
     break;
     //return;

        }
temp =temp->next;
    }
    
     if(boolean==false){
    printf("\nAccount not found !");
       printf("\nAcount not found in Abhi Bank....");
    char ch;
printf("\nDo you want to create account? (y->yes/n->no): ");
scanf(" %c",&ch);

if(ch=='y' || ch=='Y'){
    CreateAccount();
}
    }

}

void Withdraw(){
     int AccNo;
    printf("\nEnter Account Number for Withdraw money....:");
    scanf("%d",&AccNo);



    struct BankAccount *temp;
    temp=head;
   bool boolean=false;
    while(temp!=NULL){
        if(temp->AccountNumber==AccNo){

   int i=1;
int pin;
while(i<=3){
    printf("\nEnter PIN: ");
    scanf("%d",&pin);

    if(pin == temp->PIN){
        break;
    } else {
        printf("\nWrong PIN!");
        i++;
    }
}

if(i>3){
    printf("\nToo many wrong attempts!");
    return;
}
         int WithdrawAmount;
    printf("\nEnter the amount You want to Withdraw:");
    scanf("%d",&WithdrawAmount);

   if(temp->Balance>=WithdrawAmount){

    temp->Balance -= WithdrawAmount;
    printf("\nWithdraw money Successfully !");
    printf("\nUpdated Balance: %.2f", temp->Balance);


    char msg[50];
sprintf(msg, "Withdrawn %d", WithdrawAmount);
addTransaction(temp, msg);

saveToFile();
        }
        else{
            printf("\nInsufficient Balance in your Account !");
        }

        boolean=true;
        break;
        //return;
    }
temp =temp->next;
    }

    if(boolean==false){
    printf("\nAccount not found !");
        printf("\nAcount not found in Abhi Bank....");
    char ch;
printf("\nDo you want to create account? (y->yes/n->no): ");
scanf(" %c",&ch);

if(ch=='y' || ch=='Y'){
    CreateAccount();
}
    }
}


void SearchAccount(){
    int AccNo;
    printf("\nEnter Account Number to search your Bank Account in abhi Bank....:");
    scanf("%d",&AccNo);

    struct BankAccount *temp=head;
    temp=head;
    bool boolean=false;
    while(temp!=NULL){
        if(temp->AccountNumber == AccNo){
            int i=1;
int pin;
while(i<=3){
    printf("\nEnter PIN: ");
    scanf("%d",&pin);

    if(pin == temp->PIN){
        break;
    } else {
        printf("\nWrong PIN!");
        i++;
    }
}

        if(i>3){
         printf("\nToo many wrong attempts!");
         return;
           }
    if(temp->PIN==pin){
            printf("\nAccount Found !");
    
            printf("\nName:%s\nBalance:%f\n Mobile Number:%s",temp->Name,temp->Balance,temp->MobileNumber);
    }     
            char select;
            printf("\nDo you want to instantDeposite or instantWithdraw Money?Deposite->d/D,withdraw->w/W and no->n/N:");
            scanf(" %c",&select);

            if(select=='w'||select=='W'){
                Withdraw();
            }
            else if(select=='d'||select=='D'){
                Deposite();
            }

             boolean=true;
             break;
             //return
            }
        temp=temp->next; 
       
    }
    
    if(boolean==false){
        printf("\nAcount not found in Abhi Bank....");
    char ch;
        printf("\nDo you want to create account? (y->yes/n->no): ");
        scanf(" %c",&ch);

    if(ch=='y' || ch=='Y'){
    CreateAccount();
         }
    }
    
}

//  strcmp(temp->Name, name) == 0

// strcmp() ek string compare function hai

// Kaise kaam karta hai:
// strcmp(string1, string2)
// Result	Meaning
// 0	dono strings SAME
// ≠0	different


void DeleteAccount(){
    int AccNo;
    char name[50];

    printf("\nEnter Account Number for Remove Account from Abhi Bank : ");
    scanf("%d", &AccNo);

    printf("\nEnter Account Holder Name: ");
    scanf("%s", name);

    struct BankAccount *temp = head;
    struct BankAccount *prev = NULL;
    bool found = false;

    while(temp != NULL){
        if(temp->AccountNumber == AccNo && strcmp(temp->Name, name) == 0){

            int i = 1, pin;
            while(i <= 3){
                printf("\nEnter PIN: ");
                scanf("%d", &pin);

                if(pin == temp->PIN){
                    break;
                } else {
                    printf("\nWrong PIN!");
                    i++;
                }
            }

            if(i > 3){
                printf("\nToo many wrong attempts! Account not deleted.");
                return;
            }

            //  DELETE LOGIC
            if(prev == NULL){
                head = temp->next;   // first node delete
            } else {
                prev->next = temp->next;
            }

            free(temp);
            printf("\nAccount deleted successfully!");

            saveToFile();  // file update

            found = true;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if(found == false){
        printf("\nAccount not found or Name mismatch!");
    }
}

///Display All Accounts...
void DisplayAccount(){
    struct BankAccount *temp;
    temp=head;

    if(temp==NULL){
      printf("\nNo Accounts Found in Abhi Bank System");
      return;
    }

    while(temp!=NULL){
        printf("\nAccount Number:%d",temp->AccountNumber);
        printf("\nName:%s",temp->Name);
        printf("\nBalance:%f",temp->Balance);
        printf("\nMobile Number:%s",temp->MobileNumber);

    printf("\nLast Transactions:\n");
for(int i=0; i<temp->transactionCount; i++){
    printf("%s\n", temp->transactions[i]);
}
        temp=temp->next;
    }
    
}

int main(){
    srand(time(0));
    loadFromFile(); 
    int choice;

    printf("\n *** Bank Managment System *** \t\t\n");
    printf("\n1.Create a Bank Account in Abhi Bank");
    printf("\n2.Search your Bank Account");
    printf("\n3.Deposite Money in Bank");
    printf("\n4.Withdraw Money from Bank");
    printf("\n5.Delete your Bank Account");
    printf("\n6.Display Money in your Bank");
    printf("\n7.Exit from Abhi Bank..... ");

do{
    printf("\nEnter your choice:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
              CreateAccount();
             break;
        case 2:
             SearchAccount();
             break;
        case 3:
              Deposite();
              break;
        case 4:
              Withdraw();
              break;
        case 5:
              DeleteAccount();
              break;
        case 6:
               DisplayAccount();
               break;
        case 7:
             printf("\nclose your Bank Account Details.... ");
             break;
        default:
               printf("Check the Option you Entered and try Again....");
               break;               
    }
}while(choice!=7);
return 0;
}
