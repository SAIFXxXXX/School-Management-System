#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void registration();
void admin();
void teacher();
void student();
void adminpannel();
void updatetec();
void updatestud();
void assign();
void menu();
void teacherlogin();
void studentlogin();
void teacherpannel();
void studentpannel();
void findstudent();
void countstudent();
void show();


struct admin{
	char name[50];
	char username[50];
	char password[20];
};

struct teachr
{
	char name[100];
    char username[100];
    char password[20];
};

struct studn
{
	char name[100];
    char username[100];
    char password[20];
};

struct course
{
	char username[50];
	char coursename[50];
};

struct marks
{
	char name[50];
	char coursename[20];
	int mark;
};

void menu()
{
	system("cls");
	printf("\n\n\n");
	printf("\t\t----WELCOME TO SCHOOL MANAGEMENT SYSTEM----\t\n");
    printf("\n\n\n\t1.Admin\n\n\t2.Teacher\n\n\t3.Student\n");
    printf("\n\n");
    printf(" Enter Your Choice : ");
    int a;
    scanf("%d",&a);
    if(a==1)admin();
    else if(a==2)teacher();
    else student();
}

void registration()  //admin will register if he is here for the 1st time
{
	system("cls");
	printf("\n\n\n");
	printf("----____CREATE YOUR ACCOUNT____-----");
	FILE *admin;
	admin=fopen("log1.txt","w");
	struct admin l;
    printf("\n\nEnter Your Name : ");
    fflush(stdin);
    gets(l.name);
    printf("Enter Your Username : ");
    fflush(stdin);
    scanf("%s",l.username);
    printf("Enter Your Password : ");
    fflush(stdin);
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,admin);
    fclose(admin);
    menu();

}

void login()
{
	system("cls");
	printf("\n\n\n");
	printf("----____LOG IN TO YOUR ACCOUNT____-----\n\n\n");
	FILE *admin;
	admin=fopen("log1.txt","rb");
	struct admin l;
	char username[50];
	char password[50];
    printf("\n  Please Enter Your Username : ");
    scanf("%s",&username);
    printf("\n  Please Enter Your Password : ");
    scanf("%s",&password);
    int a=1;
	while(fread(&l,sizeof(l),1,admin))
	{
		if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0){ //compare two strings
			printf("\n\n\t\t---LOG IN SUCCESSFULL---\n");
			Sleep(1500);
			adminpannel();
			a=0;
		}
	}
	if(a){
		printf(" LOG IN FAILED\n\n");
		printf("\n\n1.Try Again\n");
		printf(" 2.Exit\n\n");
		int b;
		scanf("%d",&b);
		if(b==1)login();
	}
}

void updatetec(char *y)
{
	FILE *teach;
	teach=fopen("teacher.txt","rb+"); //"rb+" open read and edit file
	struct teachr l;
    char username[50];
    strcpy(username,y);
    int a=1;
	while(fread(&l,sizeof(l),1,teach)){
        if(strcmp(username,l.username)==0){
          a=0;
          printf("\n\tUpdate Name :");
          fflush(stdin); //used to clear buffer
          gets(l.name);
          printf("\tUpdate Userame  :");
          fflush(stdin);
          scanf("%s",l.username);
          printf("\tUpdate Password  :");
          fflush(stdin);
          scanf("%s",&l.password);
          fseek(teach,-sizeof(l),1);
	      fwrite(&l,sizeof(l),1,teach);
          fclose(teach);
          printf("\n\tTeacher's Profile Updated Successfully\n\n");
       }
    }

    if(a){
    	printf("\n\tUsername Invalid\n\tBack To Admin Pannel\n");
    	Sleep(1500);
    	adminpannel();
    }
    else{
     Sleep(1500);
     adminpannel();
    }
    
}

void updatestud(char *x) //pointer is used to transfer char
{
	FILE *teach;
	teach=fopen("student.txt","rb+");
	struct teachr l;
	char username[50];
	strcpy(username,x);
    int a=1;
	while(fread(&l,sizeof(l),1,teach)){
        if(strcmp(username,l.username)==0){
          a=0;
          printf("\n\tUpdate Name :");
          fflush(stdin);
          gets(l.name);
          printf("\tUpdate Userame  :");
          fflush(stdin);
          scanf("%s",l.username);
          printf("\tUpdate Password  :");
          fflush(stdin);
          scanf("%s",&l.password);
          fseek(teach,-sizeof(l),1);
	      fwrite(&l,sizeof(l),1,teach);
          fclose(teach);
          printf("\n\tStudent's Profile Updated Successfully\n\n");
       }
    }
    if(a){
    	printf("\n\tUsername Invalid\n\tBakc To Admin Pannel\n");
    	Sleep(1500);
    	adminpannel();
    }
    else{
     Sleep(1500);
     adminpannel();
    }
}

void assign(char *x)
{
	//system("cls");
	struct course l;
	FILE *admin;
	admin=fopen("course.txt","a");
	//printf("\tEnter teacher's userame : ");
	fflush(stdin);
	//scanf("%s",&l.username);
	strcpy(l.username,x);
	printf("\tAssign course : ");
	fflush(stdin);
	scanf("%s",&l.coursename);
	fwrite(&l,sizeof(l),1,admin);
    Sleep(100);
    adminpannel();
}

void adminpannel()
{
	system("cls");
	//printf("\n\n\t\t---LOG IN SUCCESSFULL---\n");
	printf("\t\t----WELCOME TO ADMIN PANNEL-----");
	printf("\n\n");
	printf("\t1.CREATE TEACHER ACCOUNT\n\t2.CREATE STUDENT ACCOUNT\n\t3.UPDATE TEACHER ACCOUNT\n\t4.UPDATE STUDENT ACCOUNT\n\t5.ASSIGN COURSE\n\t6.LOG OUT\n");
	int a;
	
	printf("    Enter Your Choice : ");
	scanf("%d",&a);
	if(a==1)teacher();
	else if(a==2)student();
	else if(a==3){
		system("cls");
	    printf("\t\t----UPDATE TEACHER ACCOUNT----\n\n\n\n");
        char username[50];
	    printf("\tEnter Teacher's userame To UPDATE :");
	    fflush(stdin);
	    scanf("%s",&username);
		updatetec(username);
	}
	else if(a==4){
		system("cls");
	    printf("\t\t----UPDATE STUDENT ACCOUNT----\n\n\n\n");
        char username[50];
	    printf("\tEnter Student's userame To UPDATE :");
	    fflush(stdin);
	    scanf("%s",&username);
	  	updatestud(username);
	}
	else if(a==5){
		system("cls");
		printf("\n\n\t\t----Assign Course----\n\n");
		printf("\tEnter Teacher's Username : ");
		FILE *tech;
		tech=fopen("teacher.txt","rb");
		struct teachr l;
		char username[50];
		fflush(stdin);
		scanf("%s",&username);
		int b=1;
		while(fread(&l,sizeof(l),1,tech)){
			if(strcmp(username,l.username)==0){
                assign(username);
                fclose(tech);
                b=0;
			}
		}
		if(b){
			printf("\n\n\t\tInvalid Username\n\n");
			Sleep(800);
			adminpannel();
		}
	}

}

void teacher()
{
	system("cls");
	printf("\t\t----CREATE TEACHER ACCOUNT----\n\n\n\n");
	FILE *teach;
	teach=fopen("teacher.txt","a");
	struct teachr l;

	printf("\tEnter Teacher's Name :");
	fflush(stdin);
	gets(l.name);
	printf("\tEnter Teacher's Username :");
	fflush(stdin);
	scanf("%s",&l.username);
	printf("\tEnter Teacher's Password :");
	fflush(stdin);
	scanf("%s",&l.password);

	fwrite(&l,sizeof(l),1,teach);
    fclose(teach);
	printf("\n\t1.Enter Another Teacher's Account\n\t2.Back To Admin Pannel\n");
	int a;
	printf(" Enter Your Choice : ");
	scanf("%d",&a);
	if(a==1)teacher();
	else adminpannel();
}

void student()
{
	system("cls");
	printf("\t\t----CREATE STUDENT ACCOUNT----\n\n\n\n");
	FILE *stud;
	stud=fopen("student.txt","a");
	struct studn l;

	printf("\tEnter Student's Name :");
	fflush(stdin);
	gets(l.name);
	printf("\tEnter Student's Username :");
	fflush(stdin);
	scanf("%s",&l.username);
	printf("\tEnter Student's Password :");
	fflush(stdin);
	scanf("%s",&l.password);

	fwrite(&l,sizeof(l),1,stud);
    fclose(stud);
	printf("\n\t1.Enter Another Student's Account\n\t2.Back To Admin Pannel\n");
	int a;
	printf(" Enter Your Choice : ");
	scanf("%d",&a);
	if(a==1)student();
	else adminpannel();
}

void teacherlogin()
{
	system("cls");
	printf("\n\n\n");
	printf("----____LOG IN TO YOUR ACCOUNT____-----\n\n\n");
	FILE *admin;
	admin=fopen("teacher.txt","rb");
	struct teachr l;
	char username[50];
	char password[50];
    printf("\n  Please Enter Your Username : ");
    scanf("%s",&username);
    printf("\n  Please Enter Your Password : ");
    scanf("%s",&password);
    int a=1;
	while(fread(&l,sizeof(l),1,admin))
	{
		if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0){
			printf("\n\n\t\t---LOG IN SUCCESSFULL---\n");
			Sleep(1500);
			teacherpannel();
			a=0;
		}
	}
	if(a){
		printf(" LOG IN FAILED\n\n");
		printf("\n\n1.Try Again\n");
		printf(" 2.Exit\n\n");
		int b;
		scanf("%d",&b);
		if(b==1)teacherlogin();
	}

}

void assignmarks(char *x)
{
	system("cls");
	FILE *log2;
	log2=fopen("course.txt","rb");
    char username[50];
	struct course l;
	printf("\n\tAssign Student's Marks\n");
	printf("\n\tVerify Your Username : ");
    fflush(stdin);
    scanf("%s",&username);
    char d[50];
    strcpy(d,x);
    while(fread(&l,sizeof(l),1,log2)){
    	if(strcmp(username,l.username)==0){
            FILE *mak;
            mak=fopen("number.txt","a");
            struct marks m;
            fflush(stdin);
            strcpy(m.name,d);
            fflush(stdin);
            strcpy(m.coursename,l.coursename);
            printf("\n\tEnter Student's Marks in %s ",m.coursename);
            fflush(stdin);
            scanf("%d",&m.mark);
            fwrite(&m,sizeof(m),1,mak);
            fclose(mak);
    	}
    }
}

void findstudent(char *x)
{
	FILE *teach;
	teach=fopen("student.txt","rb+");
	struct teachr l;
	char username[50];
	strcpy(username,x);
    int a=1;
	while(fread(&l,sizeof(l),1,teach)){
        if(strcmp(username,l.username)==0){
          printf("\n\n\t\tStudent Found\n");
          assignmarks(username);
          fclose(teach);
          a=0;
      }
  }
   if(a){
   	  printf("\n\n\tInvalid Username\n\n");
   	  Sleep(2000);
   	  teacherpannel();
   }
   else teacherpannel();
}

void teacherpannel()
{
	system("cls");
	printf("\n\n\t   -----WELCOME TO TEACHER PANNEL-----   \n\n\n");
	printf("\n\t1.Find Student");
	printf("\n\t2.Count Student");
	printf("\n\t3.Log out\n\t");
	int a;
	scanf("%d",&a);
	if(a==1){
		printf("\n\n\tEnter The Username  Of The Student : ");
		char username[50];
		scanf("%s",&username);
		findstudent(username);
	}
	else if(a==2){
		countstudent();
	}
}

void countstudent()
{
   FILE *admin;
   admin=fopen("student.txt","rb");
   struct studn l;
   int cnt=0;
   while(fread(&l,sizeof(l),1,admin)){
   	cnt++;
   }
   fclose(admin);
   printf("\n\tTotal Student Number is %d\n\n",cnt);
   printf("\n\t\tBack To Teacher Pannel");
   Sleep(3000);
   teacherpannel();
}

void studentlogin()
{
	system("cls");
	printf("\n\n\n");
	printf("----____LOG IN TO YOUR ACCOUNT____-----\n\n\n");
	FILE *admin;
	admin=fopen("student.txt","rb");
	struct studn l;
	char username[50];
	char password[50];
    printf("\n  Please Enter Your Username : ");
    scanf("%s",&username);
    printf("\n  Please Enter Your Password : ");
    scanf("%s",&password);
    int a=1;
	while(fread(&l,sizeof(l),1,admin))
	{
		if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0){ 
			printf("\n\n\t\t---LOG IN SUCCESSFULL---\n");
			Sleep(1500);
			studentpannel();
			a=0;
		}
	}
	if(a){
		printf(" LOG IN FAILED\n\n");
		printf("\n\n1.Try Again\n");
		printf(" 2.Exit\n\n");
		int b;
		scanf("%d",&b);
		if(b==1)teacherlogin();
	}
}

void studentpannel()
{
	system("cls");
	printf("\n\n\t   -----WELCOME TO STUDENT PANNEL-----   \n\n\n");
	printf("\n\t1.Show Result");
	//printf("\n\t2.Count Student");
	printf("\n\t2.Log out\n\t");
	int a;
	scanf("%d",&a);
	if(a==1){
	  	show();
	}
	
}

void show()
{
	FILE *mak;
    mak=fopen("number.txt","rb");
    printf("\n\n\tEnter Your Username : ");
    char name[50];
    fflush(stdin);
    scanf("%s",&name);
    struct marks l;
    printf("\n\tCourse\tMarks\n");
    while(fread(&l,sizeof(l),1,mak)){
    	if(strcmp(name,l.name)==0){
    		printf("\t%s   \t%d\n",l.coursename,l.mark);
    	}
    	
    }
    fclose(mak);
    printf("\n\n\t1.Back to Student Profile\n");
    printf("\t2.Log out\n");
    int s;
    scanf("%d",&s);
    if(s==1)studentpannel();
}

void admin()
{
	system("cls");
	printf("\n\n\t1.LOG IN TO YOUR ACCOUNT\n");
	printf("\t2.CREATE AN ACCOUNT\n\n");
	printf("Enter Your Choice : ");
	int a;
	scanf("%d",&a);
	if(a==1)login();
	else registration();

}

int main()
{
	printf("\n\n\n");
    printf("\t\t----WELCOME TO SCHOOL MANAGEMENT SYSTEM----\t\n");
    printf("\n\n\n\t1.Admin\n\n\t2.Teacher\n\n\t3.Student\n");
    printf("\n\n");
    printf(" Enter Your Choice : ");
    int a;
    scanf("%d",&a);
    if(a==1)admin();
    else if(a==2)teacherlogin();
    else studentlogin();
    system("cls");//clear previous elements of the window

	printf("\n\n\n\t\t-----LOG OUT SUCCESSFULL----\n");
	Sleep(1500);//take time to do next step
}
