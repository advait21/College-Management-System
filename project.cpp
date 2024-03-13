#include<iostream> 
#include<stdio.h> 
#include <iomanip> 
#include<stdlib.h> 
#include<fstream> 
#include<string.h> 
#include<conio.h> 
#include<windows.h> 
#include<ctype.h> 
#include<dos.h> 
#include<time.h> 
using namespace std; 
void password(); 
void mainmenu(void); 
void addmember(void); 
void deletemember(void); 
void searchmember(void); 
void viewmember(void); 
void editmember(void); 
void closeapp(void); 
void returnfunc(void); 
void event(void); 
int t(void); 
void addevent(void); 
void vieweevent(void); 
void deleteevent(void); 
void showing(void); 
void showing2(void); 
void displaying(void); 
 
///list of global files 
FILE *fp,*ft,*fs; 
COORD coord = {0, 0}; 
 
int fm; 
 
void gotoxy (int x, int y) 
{ 
 coord.X = x; coord.Y = y; 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
} 
 
struct member 
{ 
 int ID; 
 char name[20]; 
 char add[20]; 
 char dept[20]; 
 int Phone_no; 
 
 int no; 
 char title[20]; 
 char z[100]; 
 char date[20]; 
}; 
 
struct member stu; 
class Teacher 
{ 
public: 
 int Sr; 
 string Name; 
 string DepartmentName; 
 string Subject; 
 int Experience; 
 string Designation; 
 Teacher(int sr, string name, string department, string subject, string designation,int exp) 
 { 
 Sr = sr; 
 Name = name; 
 DepartmentName = department; 
 Subject = subject; 
 Designation = designation; 
 Experience = exp; 
 } 
}; 
class Lib 
{ 
public: 
char bookname[100],auname[50],sc[20],sc1[50]; 
int q,B,p; 
Lib() 
{ 
strcpy(bookname,"NO Book Name"); 
strcpy(auname,"No Author Name"); 
strcpy(sc,"No Book ID"); 
strcpy(sc1,"No Book ID"); 
q=0; 
B=0; 
p=0; 
} 
void get(); 
void student(); 
void pass(); 
void librarian(); 
void password(); 
void getdata(); 
void show(int); 
void booklist(int); 
void modify(); 
void see(int); 
int branch(int); 
void issue(); 
void der(char[],int,int); 
void fine(int,int,int,int,int,int); 
}; 
void Lib::getdata() 
{ 
int i; 
fflush(stdin); 
cout<<"\n\t\tEnter the details :-\n"; 
cout<<"\n\t\tEnter Book's Name : "; 
cin.getline(bookname,100); 
for(i=0;bookname[i]!='\0';i++) 
{ 
if(bookname[i]>='a'&&bookname[i]<='z') 
bookname[i]-=32; 
} 
cout<<"\n\t\tEnter Author's Name : "; 
cin.getline(auname,50); 
cout<<"\n\t\tEnter Publication name : "; 
cin.getline(sc1,50); 
cout<<"\n\t\tEnter Book's ID : "; 
cin.getline(sc,20); 
cout<<"\n\t\tEnter Book's Price : "; 
cin>>p; 
cout<<"\n\t\tEnter Book's Quantity : "; 
cin>>q; 
} 
void Lib::show(int i) 
{ 
cout<<"\n\t\tBook Name : "<<bookname<<endl; 
cout<<"\n\t\tBook's Author Name : "<<auname<<endl; 
cout<<"\n\t\tBook's ID : "<<sc<<endl; 
cout<<"\n\t\tBook's Publication : "<<sc1<<endl; 
if(i==2) 
{ 
cout<<"\n\t\tBook's Price : "<<p<<endl; 
cout<<"\n\t\tBook's Quantity : "<<q<<endl; 
} 
} 
void Lib::booklist(int i) 
{ 
int b,r=0; 
system("cls"); 
b=branch(i); 
system("cls"); 
ifstream intf("Booksdata.txt",ios::binary); 
if(!intf) 
cout<<"\n\t\tFile Not Found."; 
else 
{ 
cout<<"\n\t ************ Book List ************ \n\n"; 
intf.read((char*)this,sizeof(*this)); 
while(!intf.eof()) 
{ 
if(b==B) 
{ 
if(q==0 && i==1) 
{ 
} 
else 
{ 
r++; 
cout<<"\n\t\t********** "<<r<<". ********** \n"; 
show(i); 
} 
} 
intf.read((char*)this,sizeof(*this)); 
} 
} 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
if(i==1) 
student(); 
else 
librarian(); 
} 
void Lib::modify() 
{ 
char ch,st1[100]; 
int i=0,b,cont=0; 
system("cls"); 
cout<<"\n\t\t>>Please Choose one option :-\n"; 
cout<<"\n\t\t1.Modification In Current Books\n\n\t\t2.Add New Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n"; 
cout<<"\n\n\t\tEnter your choice : "; 
cin>>i; 
if(i==1) 
{ 
system("cls"); 
b=branch(2); 
ifstream intf1("Booksdata.txt",ios::binary); 
if(!intf1) 
{ 
cout<<"\n\t\tFile Not Found\n"; 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
librarian(); 
} 
intf1.close(); 
system("cls"); 
cout<<"\n\t\tPlease Choose One Option :-\n"; 
cout<<"\n\t\t1.Search By Book Name\n\n\t\t2.Search By Book's ID\n"; 
cout<<"\n\t\tEnter Your Choice : "; 
cin>>i; 
fflush(stdin); 
if(i==1) 
{ 
system("cls"); 
cout<<"\n\t\tEnter Book Name : "; 
cin.getline(st1,100); 
system("cls"); 
fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary); 
intf.seekg(0); 
intf.read((char*)this,sizeof(*this)); 
while(!intf.eof()) 
{ 
for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i
++); 
if(bookname[i]=='\0'&&st1[i]=='\0') 
{ 
cont++; 
getdata(); 
intf.seekp(intf.tellp()-sizeof(*this)); 
intf.write((char*)this,sizeof(*this)); 
break; 
} 
intf.read((char*)this,sizeof(*this)); 
} 
intf.close(); 
} 
else if(i==2) 
{ 
cout<<"\n\t\tEnter Book's ID : "; 
cin.getline(st1,100); 
system("cls"); 
fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary); 
intf.seekg(0); 
intf.read((char*)this,sizeof(*this)); 
while(!intf.eof()) 
{ 
for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++); 
if(sc[i]=='\0'&&st1[i]=='\0') 
{ 
cont++; 
getdata(); 
intf.seekp(intf.tellp()-sizeof(*this)); 
intf.write((char*)this,sizeof(*this)); 
break; 
} 
intf.read((char*)this,sizeof(*this)); 
} 
intf.close(); 
} 
else 
{ 
cout<<"\n\t\tIncorrect Input.....:(\n"; 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
modify(); 
} 
if(cont==0) 
{ 
cout<<"\n\t\tBook Not Found.\n"; 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
modify(); 
} 
else 
cout<<"\n\t\tUpdate Successful.\n"; 
} 
else if(i==2) 
{ 
system("cls"); 
B=branch(2); 
system("cls"); 
getdata(); 
ofstream outf("Booksdata.txt",ios::app|ios::binary); 
outf.write((char*)this,sizeof(*this)); 
outf.close(); 
cout<<"\n\t\tBook added Successfully.\n"; 
} 
else if(i==3) 
{ 
system("cls"); 
b=branch(2); 
ifstream intf1("Booksdata.txt",ios::binary); 
if(!intf1) 
{ 
cout<<"\n\t\tFile Not Found\n"; 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
intf1.close(); 
system("cls"); 
librarian(); 
} 
intf1.close(); 
system("cls"); 
cout<<"\n\t\tPlease Choose One Option for deletion:-\n"; 
cout<<"\n\t\t1.By Book Name\n\n\t\t2.By Book's ID\n"; 
cout<<"\n\t\tEnter Your Choice : "; 
cin>>i; 
fflush(stdin); 
if(i==1) 
{ 
system("cls"); 
cout<<"\n\t\tEnter Book Name : "; 
cin.getline(st1,100); 
ofstream outf("temp.txt",ios::app|ios::binary); 
ifstream intf("Booksdata.txt",ios::binary); 
intf.read((char*)this,sizeof(*this)); 
while(!intf.eof()) 
{ 
for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i
++); 
if(bookname[i]=='\0'&&st1[i]=='\0') 
{ 
cont++; 
intf.read((char*)this,sizeof(*this)); 
} 
else 
{ 
outf.write((char*)this,sizeof(*this)); 
intf.read((char*)this,sizeof(*this)); 
} 
} 
intf.close(); 
outf.close(); 
remove("Booksdata.txt"); 
rename("temp.txt","Booksdata.txt"); 
} 
else if(i==2) 
{ 
cout<<"\n\t\tEnter Book's ID : "; 
cin.getline(st1,100); 
ofstream outf("temp.txt",ios::app|ios::binary); 
ifstream intf("Booksdata.txt",ios::binary); 
intf.read((char*)this,sizeof(*this)); 
while(!intf.eof()) 
{ 
for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++); 
if(sc[i]=='\0'&&st1[i]=='\0') 
{ 
cont++; 
intf.read((char*)this,sizeof(*this)); 
} 
else 
{ 
outf.write((char*)this,sizeof(*this)); 
intf.read((char*)this,sizeof(*this)); 
} 
} 
outf.close(); 
intf.close(); 
remove("Booksdata.txt"); 
rename("temp.txt","Booksdata.txt"); 
} 
else 
{ 
cout<<"\n\t\tIncorrect Input.....:(\n"; 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
modify(); 
} 
if(cont==0) 
{ 
cout<<"\n\t\tBook Not Found.\n"; 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
modify(); 
} 
else 
cout<<"\n\t\tDeletion Successful.\n"; 
} 
else if(i==4) 
{ 
system("cls"); 
librarian(); 
} 
else 
{ 
cout<<"\n\t\tWrong Input.\n"; 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
modify(); 
} 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
librarian(); 
} 
int Lib::branch(int x) 
{ 
int i; 
cout<<"\n\t\t>>Please Choose one Branch :-\n"; 
cout<<"\n\t\t1.Class 12th\n\n\t\t2.CS\n\n\t\t3.EC\n\n\t\t4.CIVIL\n\n\t\t5.MECHANICAL\n\n\t\t6.1ST YEAR\n\n\t\t7.Go to menu\n"; 
cout<<"\n\t\tEnter your choice : "; 
cin>>i; 
switch(i) 
{ 
case 1: return 1; 
break; 
case 2: return 2; 
break; 
case 3: return 3; 
break; 
case 4: return 4; 
break; 
case 5: return 5; 
break; 
case 6: return 6; 
break; 
case 7: system("cls"); 
if(x==1) 
student(); 
else 
librarian(); 
default : cout<<"\n\t\tPlease enter correct option :("; 
getch(); 
system("cls"); 
branch(x); 
} 
} 
void Lib::see(int x) 
{ 
int i,b,cont=0; 
char ch[100]; 
system("cls"); 
b=branch(x); 
ifstream intf("Booksdata.txt",ios::binary); 
if(!intf) 
{ 
cout<<"\n\t\tFile Not Found.\n"; 
cout<<"\n\t\t->Press any key to continue....."; 
getch(); 
system("cls"); 
if(x==1) 
student(); 
else 
librarian(); 
} 
system("cls"); 
cout<<"\n\t\tPlease Choose one option :-\n"; 
cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n"; 
cout<<"\n\t\tEnter Your Choice : "; 
cin>>i; 
fflush(stdin); 
intf.read((char*)this,sizeof(*this)); 
if(i==1) 
{ 
cout<<"\n\t\tEnter Book's Name : "; 
cin.getline(ch,100); 
system("cls"); 
while(!intf.eof()) 
{ 
for(i=0;b==B&&q!=0&&bookname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bookname[i]||ch[i]==bookname[i]
+32);i++); 
if(bookname[i]=='\0'&&ch[i]=='\0') 
{ 
cout<<"\n\t\tBook Found :-\n"; 
show(x); 
cont++; 
break; 
} 
intf.read((char*)this,sizeof(*this)); 
} 
} 
else if(i==2) 
{ 
cout<<"\n\t\tEnter Book's ID : "; 
cin.getline(ch,100); 
system("cls"); 
while(!intf.eof()) 
{ 
for(i=0;b==B&&q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++); 
if(sc[i]=='\0'&&ch[i]=='\0') 
{ 
cout<<"\n\t\tBook Found :-\n"; 
show(x); 
cont++; 
break; 
} 
intf.read((char*)this,sizeof(*this)); 
} 
} 
else 
{ 
cont++; 
cout<<"\n\t\tPlease enter correct option :("; 
getch(); 
system("cls"); 
see(x); 
} 
intf.close(); 
if(cont==0) 
cout<<"\n\t\tThis Book is not available :( \n"; 
cout<<"\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
if(x==1) 
student(); 
else 
librarian(); 
} 
void Lib::issue() 
{ 
char st[50],st1[20]; 
int b,i,j,d,m,y,dd,mm,yy,cont=0; 
system("cls"); 
cout<<"\n\t\t->Please Choose one option :-\n"; 
cout<<"\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search student who issued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return Book\n\n\t\t6.Go back to menu\n\n\t\tEnter Your Choice : "; 
cin>>i; 
fflush(stdin); 
if(i==1) 
{ 
system("cls"); 
b=branch(2); 
system("cls"); 
fflush(stdin); 
cout<<"\n\t\t->Please Enter Details :-\n"; 
cout<<"\n\t\tEnter Book Name : "; 
cin.getline(bookname,100); 
cout<<"\n\t\tEnter Book's ID : "; 
cin.getline(sc,20); 
//strcpy(st,sc); 
der(sc,b,1); 
cout<<"\n\t\tEnter Student Name : "; 
cin.getline(auname,100); 
cout<<"\n\t\tEnter Student's ID : "; 
cin.getline(sc1,20); 
cout<<"\n\t\tEnter date : "; 
cin>>q>>B>>p; 
ofstream outf("student.txt",ios::binary|ios::app); 
outf.write((char*)this,sizeof(*this)); 
outf.close(); 
cout<<"\n\n\t\tIssue Successfully.\n"; 
} 
else if(i==2) 
{ 
ifstream intf("student.txt",ios::binary); 
system("cls"); 
cout<<"\n\t\t->The Details are :-\n"; 
intf.read((char*)this,sizeof(*this)); 
i=0; 
while(!intf.eof()) 
{ 
i++; 
cout<<"\n\t\t********** "<<i<<". ********** \n"; 
cout<<"\n\t\tStudent Name : "<<auname<<"\n\t\t"<<"Student's ID : "<<sc1<<"\n\t\t"<<"Book Name : "<<bookname<<"\n\t\t"<<"Book's ID : "<<sc<<"\n\t\t"<<"Date : "<<q<<"/"<<B<<"/"<<p<<"\n"; 
intf.read((char*)this,sizeof(*this)); 
} 
intf.close(); 
} 
else if(i==3) 
{ 
system("cls"); 
fflush(stdin); 
cout<<"\n\t\t->Please Enter Details :-\n"; 
cout<<"\n\n\t\tEnter Student Name : "; 
cin.getline(st,50); 
cout<<"\n\n\t\tEnter Student's ID : "; 
cin.getline(st1,20); 
system("cls"); 
ifstream intf("student.txt",ios::binary); 
intf.read((char*)this,sizeof(*this)); 
cont=0; 
while(!intf.eof()) 
{ 
for(i=0;sc1[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc1[i];i++); 
if(sc1[i]=='\0'&&st1[i]=='\0') 
{ 
cont++; 
if(cont==1) 
{ 
cout<<"\n\t\t->The Details are :-\n"; 
cout<<"\n\t\tStudent Name : "<<auname; 
cout<<"\n\t\tStudent's ID : "<<sc1; 
} 
cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n"; 
cout<<"\n\t\tBook Name : "<<bookname; 
cout<<"\n\t\tBook's ID : "<<sc; 
cout<<"\n\t\tDate : "<<q<<"/"<<B<<"/"<<p<<"\n"; 
} 
intf.read((char*)this,sizeof(*this)); 
} 
intf.close(); 
if(cont==0) 
cout<<"\n\t\tNo record found."; 
} 
else if(i==4) 
{ 
system("cls"); 
fflush(stdin); 
cout<<"\n\t\t->Please Enter Details :-\n"; 
cout<<"\n\n\t\tEnter Student's ID : "; 
cin.getline(st,50); 
cout<<"\n\t\tEnter Book's ID : "; 
cin.getline(st1,20); 
fstream intf("student.txt",ios::in|ios::out|ios::ate|ios::binary); 
intf.seekg(0); 
intf.read((char*)this,sizeof(*this)); 
while(!intf.eof()) 
{ 
for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++); 
for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++); 
if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0') 
{ 
d=q; 
m=B; 
y=p; 
cout<<"\n\t\tEnter New Date : "; 
cin>>q>>B>>p; 
fine(d,m,y,q,B,p); //fn1 
intf.seekp(intf.tellp()-sizeof(*this)); //fn3 
intf.write((char*)this,sizeof(*this)); //fn5 
cout<<"\n\n\t\tReissue successfully."; //fn3 
break; 
} 
intf.read((char*)this,sizeof(*this)); 
} 
intf.close(); 
} 
else if(i==5) 
{ 
system("cls"); 
b=branch(2); 
system("cls"); 
fflush(stdin); 
cout<<"\n\t\t->Please Enter Details :-\n"; 
cout<<"\n\t\tEnter Book's ID : "; 
cin.getline(st1,20); 
der(st1,b,2); 
cout<<"\n\n\t\tEnter Student's ID : "; 
cin.getline(st,20); 
cout<<"\n\t\tEnter Present date : "; 
cin>>d>>m>>y; 
ofstream outf("temp.txt",ios::app|ios::binary); 
ifstream intf("student.txt",ios::binary); 
intf.read((char*)this,sizeof(*this)); 
while(!intf.eof()) 
{ 
for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++); 
for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++); 
if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0) 
{ 
cont++; 
intf.read((char*)this,sizeof(*this)); 
fine(q,B,p,d,m,y); 
cout<<"\n\t\tReturned successfully."; 
} 
else 
{ 
outf.write((char*)this,sizeof(*this)); 
intf.read((char*)this,sizeof(*this)); 
} 
} 
intf.close(); 
outf.close(); 
getch(); 
remove("student.txt"); 
rename("temp.txt","student.txt"); 
} 
else if(i==6) 
{ 
system("cls"); 
librarian(); 
} 
else 
cout<<"\n\t\tWrong Input.\n"; 
cout<<"\n\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
librarian(); 
} 
void Lib::fine(int d,int m,int y,int dd,int mm,int yy) 
{ 
long int n1,n2; 
int years,l,i; 
const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31}; 
n1 = y*365 + d; 
for (i=0; i<m - 1; i++) 
n1 += monthDays[i]; //fn1353 
years = y; 
if (m <= 2) 
years--; 
l= years / 4 - years / 100 + years / 400; 
n1 += l; 
n2 = yy*365 + dd; 
for (i=0; i<mm - 1; i++) 
n2 += monthDays[i]; 
years = yy; 
if (m <= 2) 
years--; 
l= years / 4 - years / 100 + years / 400; 
n2 += l; 
n1=n2-n1; 
n2=n1-15; 
if(n2>0) 
cout<<"\n\t\tThe Total Fine is : "<<n2; 
} 
void Lib::der(char st[],int b,int x) 
{ 
int i,cont=0; 
fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary); 
intf.seekg(0); 
intf.read((char*)this,sizeof(*this)); 
while(!intf.eof()) 
{ 
for(i=0;b==B&&sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++); 
if(sc[i]=='\0'&&st[i]=='\0') 
{ 
cont++; 
if(x==1) 
{ 
q--; 
} 
else 
{ 
q++; 
} 
intf.seekp(intf.tellp()-sizeof(*this)); 
intf.write((char*)this,sizeof(*this)); 
break; 
} 
intf.read((char*)this,sizeof(*this)); 
} 
if(cont==0) 
{ 
cout<<"\n\t\tBook not found.\n"; 
cout<<"\n\n\t\tPress any key to continue....."; 
getch(); 
system("cls"); 
issue(); 
} 
intf.close(); 
} 
void Lib::get() 
{ 
int i; 
cout<<"\n\t*********** LIBRARY ***********\n"; 
cout<<"\n\t\t>>Please Choose Any Option To login \n"; 
cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n"; 
cout<<"\n\t\tEnter your choice : "; 
cin>>i; 
if(i==1) 
{ 
system("cls"); 
student(); 
} 
else if(i==2) 
pass(); 
else if(i==3) 
exit(0); 
else 
{ 
cout<<"\n\t\tPlease enter correct option :("; 
getch(); 
system("CLS"); 
get(); 
} 
} 
void Lib::student() 
{ 
int i; 
cout<<"\n\t************ WELCOME STUDENT ************\n"; 
cout<<"\n\t\t>>Please Choose One Option:\n"; 
cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n"; 
cout<<"\n\t\tEnter your choice : "; 
cin>>i; 
if(i==1) 
booklist(1); 
else if(i==2) 
see(1); 
else if(i==3) 
{ 
system("cls"); 
get(); 
} 
else if(i==4) 
exit(0); 
else 
{ 
cout<<"\n\t\tPlease enter correct option :("; 
getch(); 
system("cls"); 
student(); 
} 
} 
void Lib::pass() 
{ 
int i=0; 
char ch,st[21],ch1[21]={"admin"}; 
cout<<"\n\t\tEnter Password : "; 
while(1) 
{ 
ch=getch(); 
if(ch==13) 
{ 
st[i]='\0'; 
break; 
} 
else if(ch==8&&i>0) 
{ 
i--; 
cout<<"\b \b"; 
} 
else 
{ 
cout<<"*"; 
st[i]=ch; 
i++; 
} 
} 
ifstream inf("password.txt"); 
inf>>ch1; 
inf.close(); 
for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++); 
if(st[i]=='\0'&&ch1[i]=='\0') 
{ 
system("cls"); 
librarian(); 
} 
else 
{ 
cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n"; 
getch(); 
system("cls"); 
get(); 
} 
} 
void Lib::librarian() 
{ 
int i; 
cout<<"\n\t************ WELCOME LIBRARIAN ************\n"; 
cout<<"\n\t\t>>Please Choose One Option:\n"; 
cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Issue Book\n\n\t\t5.Go to main menu\n\n\t\t6.Change Password\n\n\t\t7.Close Application\n"; 
cout<<"\n\t\tEnter your choice : "; 
cin>>i; 
switch(i) 
{ 
case 1:booklist(2); 
break; 
case 2:see(2); 
break; 
case 3:modify(); 
break; 
case 4:issue(); 
break; 
case 5:system("cls"); 
get(); 
break; 
case 6:password(); 
break; 
case 7:exit(0); 
default:cout<<"\n\t\tPlease enter correct option :("; 
getch(); 
system("cls"); 
librarian(); 
} 
} 
void Lib::password() 
{ 
int i=0,j=0; 
char ch,st[21],ch1[21]={"admin"}; 
system("cls"); 
cout<<"\n\n\t\tEnter Old Password : "; 
while(1) 
{ 
ch=getch(); 
if(ch==13) 
{ 
st[i]='\0'; 
break; 
} 
else if(ch==8&&i>0) 
{ 
i--; 
cout<<"\b \b"; 
} 
else 
{ 
cout<<"*"; 
st[i]=ch; 
i++; 
} 
} 
ifstream intf("password.txt"); 
intf>>ch1; 
intf.close(); 
for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++); 
if(st[i]=='\0'&&ch1[i]=='\0') 
{ 
system("cls"); 
cout<<"\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n"; 
cout<<"\n\t\tEnter New Password : "; 
fflush(stdin); 
i=0; 
while(1) 
{ 
j++; 
ch=getch(); 
if(ch==13) 
{ 
for(i=0;st[i]!=' '&&st[i]!='\0';i++); 
if(j>20 || st[i]==' ') 
{ 
cout<<"\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again....."; 
getch(); 
system("cls"); 
password(); 
librarian(); 
} 
st[i]='\0'; 
break; 
} 
else if(ch==8&&i>0) 
{ 
i--; 
cout<<"\b \b"; 
} 
else 
{ 
cout<<"*"; 
st[i]=ch; 
i++; 
} 
} 
ofstream outf("password.txt"); 
outf<<st; 
outf.close(); 
cout<<"\n\n\t\tYour Password has been changed Successfully."; 
cout<<"\n\t\tPress any key to continue......"; 
getch(); 
system("cls"); 
librarian(); 
} 
else 
{ 
cout<<"\n\n\t\tPassword is incorrect.....\n"; 
cout<<"\n\t\tEnter 1 for retry or 2 for menu"; 
cin>>i; 
if(i==1) 
{ 
system("cls"); 
password(); 
} 
else 
{ 
system("cls"); 
librarian(); 
} 
} 
} 
class Student 
{ 
public: 
 int studentSr; 
 string alumniName; 
 int passingYear; 
 string departmentName; 
 string nameOfCompany; 
 string positionHeld; 
 Student(int sr, string name, int year, string department, string companyName, string position) 
 { 
 studentSr = sr; 
 alumniName = name; 
 passingYear = year; 
 departmentName = department; 
 nameOfCompany = companyName; 
 positionHeld = position; 
 } 
}; 
//Hostel part 
struct HSTL 
{ 
 int NUMBER = 1; 
 int fill = 0; 
 char CUS_NAMES[3][10]; 
 HSTL *NXT; 
 HSTL *PREVIOUS; 
}; 
class hostel 
{ 
 HSTL *TITLE[3]; 
 HSTL *WORDS; 
public: 
 hostel() 
 { 
 for (int x = 0; x < 3; x++) 
 TITLE[x] = NULL; 
 } 
 void create() 
 { 
 for (int x = 0; x < 3; x++) 
 { 
 for (int y = 0; y < 9; y++) 
 { 
 HSTL *ss = new HSTL; 
 ss->NXT = NULL; 
 ss->PREVIOUS = NULL; 
 if (TITLE[x] == NULL) 
 { 
 TITLE[x] = ss; 
 ss->NUMBER = 1; 
 } 
 else 
 { 
 HSTL *WORDS = TITLE[x]; 
 while (WORDS->NXT != NULL) 
 { 
 WORDS = WORDS->NXT; 
 } 
 if (y == 3 || y == 5 || y == 7 || y == 8) 
 { 
 WORDS->NUMBER = 3; 
 } 
 if (y == 2 || y == 4 || y == 6) 
 { 
 WORDS->NUMBER = 2; 
 } 
 WORDS->NXT = ss; 
 ss->PREVIOUS = WORDS; 
 } 
 } 
 } 
 } 
 void display() 
 { 
 int y = 0, z = 0, w = 0; 
 for (int x = 0; x < 48; x++) 
 { 
 cout << "--"; 
 } 
 cout << "\n " 
 ; 
 for (int x = 1; x < 4; x++) 
 { 
 cout << "| Floor number : "<< x << " \t\t"; 
 } 
 cout << "|\n" ; 
 for (int x = 0; x < 48; x++) 
 { 
 cout << "--"; 
 } 
 WORDS = TITLE[y]; 
 HSTL *s = TITLE[y + 1]; 
 HSTL *t = TITLE[y + 2]; 
 cout << "\n "; 
 while (WORDS != NULL) 
 { 
 if (WORDS->fill != WORDS->NUMBER && WORDS->NUMBER != 0) 
 { 
 y++; 
 cout << "| room no : "<< y; 
 cout << "->Vacant cots->"<< WORDS->NUMBER; 
 } 
 else 
 { 
 y++; 
 cout << "| room no : "<< y; 
 cout << "->Present "; 
 } 
 if (s->fill != s->NUMBER && s->NUMBER != 0) 
 { 
 z++; 
 cout << "\t | room no : "<< y; 
 cout << "->Vacant cots->"<< s->NUMBER; 
 } 
 else 
 { 
 z++; 
 cout << " \t | room no : "<< y; 
 cout << "->Present "; 
 } 
 if (t->fill != t->NUMBER && t->NUMBER != 0) 
 { 
 w++; 
 cout << "\t | room no : "<< y; 
 cout << "->Vacant cots->"<< t->NUMBER << "| "; 
 } 
 else 
 { 
 w++; 
 cout << "\t | room no : "<< y; 
 cout << "->Present "<< " | "; 
 } 
 cout << " \n "; 
 for (int x = 0; x < 48; x++) 
 { 
 cout << "--" ; 
 } 
 cout << "\n "; 
 WORDS = WORDS->NXT; 
 s = s->NXT; 
 t = t->NXT; 
 } 
 } 
 void booking(int people) 
 { 
 int fl, rom; 
 cout << "\nEnter the floor number : "; 
 cin >> fl; 
 try 
 { 
 if (fl < 0 || fl > 4) 
 { 
 throw(fl); 
 } 
 WORDS = TITLE[fl - 1]; 
 cout << "\nEnter the room number : "; 
 cin >> rom; 
 try 
 { 
 if (rom < 0 || rom > 10) 
 { 
 throw(rom); 
 } 
 else 
 { 
 int x = 1; 
 while (x < rom) 
 { 
 WORDS = WORDS->NXT; 
 x++; 
 } 
 if (WORDS->NUMBER >= people) 
 { 
 cout << "\nRoom is vacant. You can apply for room" ; 
 int count = 0; 
 while (WORDS->fill - 1 <= WORDS->NUMBER) 
 { 
 cout << "\nEnter name "<< WORDS -> fill + 1 << " : "; 
 cin >> WORDS->CUS_NAMES[WORDS->fill]; 
 count++; 
 WORDS->fill++; 
 if (count >= people) 
 { 
 break; 
 } 
 } 
 WORDS->NUMBER = WORDS->NUMBER - people; 
 } 
 else 
 { 
 cout << "\nRoom is not vacant... SORRY !!!"; 
 } 
 } 
 } 
 catch (int r) 
 { 
 cout << "\nInvalid room number : "<< r; 
 } 
 } 
 catch (int r) 
 { 
 cout << " \nInvalid floor number : " << r; 
 } 
 } 
 void cancelled(int check) 
 { 
 char checking_namess[10]; 
 int fg = 0; 
 int rms, x = 1; 
 try 
 { 
 if (check < 0 || check > 4) 
 { 
 throw(check); 
 } 
 else 
 { 
 cout << " Enter the room no : "; 
 cin >> rms; 
 try 
 { 
 if (rms < 0 || rms > 10) 
 { 
 throw(rms); 
 } 
 else 
 { 
 cout << " Enter the name to be deleted :"; 
 cin >> checking_namess; 
 WORDS = TITLE[check - 1]; 
 while (x < rms) 
 { 
 WORDS = WORDS->NXT; 
 x++; 
 } 
 x = 0; 
 while (x < 3) 
 { 
 if (!strcmp(checking_namess, WORDS -> CUS_NAMES[x])) 
 { 
 fg = 1; 
 break; 
 x = 0; 
 } 
 else 
 x++; 
 } 
 if (fg == 1 && WORDS->fill != 0) 
 { 
 cout << "\nRecord deleted : "<< WORDS -> CUS_NAMES[x]; 
 WORDS->CUS_NAMES[x][0] ='A'; 
 WORDS->CUS_NAMES[x][1] ='\0'; 
 WORDS->fill--; 
 WORDS->NUMBER++; 
 } 
 else 
 cout << "\nRecord not present "; 
 } 
 } 
 catch (int r) 
 { 
 cout << "\nInvalid room number : " << r; 
 } 
 } 
 } 
 catch (int r) 
 { 
 cout << " \n Floor dosn't exist : " << r; 
 } 
 } 
 void modify(int check) 
 { 
 char checking_namess[10]; 
 int rms, x = 1; 
 try 
 { 
 if (check < 0 || check > 4) 
 { 
 throw(check); 
 } 
 else 
 { 
 cout << " Enter the room no : "; 
 cin >> rms; 
 try 
 { 
 if (rms < 0 || rms > 10) 
 { 
 throw(rms); 
 } 
 else 
 { 
 cout << "Enter the name to be updated :"; 
 cin >> checking_namess; 
 WORDS = TITLE[check - 1]; 
 while (x < rms) 
 { 
 WORDS = WORDS->NXT; 
 x++; 
 } 
 x = 0; 
 while (x < 3) 
 { 
 if (!strcmp(checking_namess, WORDS -> CUS_NAMES[x])) 
 { 
 cout << "\nEnter updated name : " ; 
 cin >> WORDS->CUS_NAMES[x]; 
 break; 
 } 
 else 
 x++; 
 } 
 if (x >= 3) 
 cout << "Record not found "; 
 else 
 { 
 cout << "\nRecord updated\nPrevious name : "<< checking_namess << "\nUpdated name : "<< WORDS->CUS_NAMES[x]; 
 } 
 } 
 } 
 catch (int r) 
 { 
 cout << "\nInvalid room number : "<< r; 
 } 
 } 
 } 
 catch (int r) 
 { 
 cout << "\n Floor dosn't exist : "<< r; 
 } 
 } 
}; 
int main() 
{ 
 int Ambulance; 
 printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(2,2); 
 printf("\t\t|====== COLLEGE MANAGEMENT SYSTEM ======|"); 
 gotoxy(0,4); 
 printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 cout<<endl; 
 cout<<"\t\t1. STUDENT SECTION"<<endl ; 
 cout<<endl; 
 cout<<"\t\t2. TEACHER SECTION"<<endl ; 
 cout<<endl; 
 cout<<"\t\t3. ALUMNI"<<endl ; 
 cout<<endl; 
 cout<<"\t\t4. HOSTEL"<<endl ; 
 cout<<endl; 
 cout<<"\t\t5. LIBRARY"<<endl ; 
 cout<<endl; 
 cout<<"\t\tEnter your Choice : " ; 
 cin>>Ambulance ; 
 
 switch(Ambulance) 
 { 
 case 1: 
 password(); 
 break; 
 
 case 2: 
 showing(); 
 break; 
 
 case 3: 
 displaying(); 
 break; 
 
 case 4: 
 showing2(); 
 break; 
 
 case 5: 
 Lib obj; 
 obj.get(); 
 break; 
 
 
 
 
 } 
} 
//Student code 
void mainmenu() 
{ 
 int choice; 
 system("cls"); 
 gotoxy(5,2); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(5,3); 
 printf("|====== STUDENT SECTION ======|"); 
 gotoxy(5,4); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 
 gotoxy(5,5); 
 printf("------------- MAIN MENU --------------"); 
 gotoxy(5,7);printf("1. Add Students\n"); 
 gotoxy(5,9);printf("2. Delete Students\n"); 
 gotoxy(5,11);printf("3. Search Students\n"); 
 gotoxy(5,13);printf("4. View Students\n"); 
 gotoxy(5,15);printf("5. Student club Events\n"); 
 gotoxy(5,17);printf("6. Edit Student Information\n"); 
 gotoxy(5,19);printf("7. Close application\n"); 
 gotoxy(5,20);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(5,21);t(); 
 gotoxy(5,24); 
 printf("Enter Your Choice: "); 
 
switch(getch()) 
{ 
 case '1': 
 addmember(); 
 break; 
 case '2': 
 deletemember(); 
 break; 
 case '3': 
 searchmember(); 
 break; 
 case '4': 
 viewmember(); 
 break; 
 case '5': 
 event(); 
 break; 
 case'6': 
 editmember(); 
 case '7': 
 { 
 system("cls"); 
 gotoxy(16,3); 
 printf("\t STUDENT SECTION\n"); 
 gotoxy(16,5); 
 printf("\n\n*****************************************************************************"); 
 
 exit(0); 
 } 
default: 
{ 
 gotoxy(20,22);printf("Wrong!!Correct Option"); 
 if (getch()) 
 mainmenu(); 
 
} 
} 
 
 
} 
void addmember(void) 
{ 
 system("cls"); 
 
 gotoxy(5,2); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(5,3); 
 printf("|====== STUDENT SECTION ======|"); 
 gotoxy(5,4); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 
 gotoxy(5,5); 
 printf("----------- ADD NEW STUDENT -----------"); 
 int print = 5; 
 FILE *fp; 
 fp = fopen("record_nxt.txt","ab+"); 
 // SetColor(45); 
 if(fp == NULL){ 
 MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0); 
 
 } 
 else 
 
 { 
 ///fflush(stdin); 
 gotoxy(print,7);printf("STUDENT ID: ");scanf("%d",&stu.ID); 
 //here you can confirms the ID 
 fflush(stdin); 
 gotoxy(print,9);printf("Name: ");gets(stu.name); 
 gotoxy(print,11);printf("Address: ");gets(stu.add); 
 gotoxy(print,13);printf("Department name: ");gets(stu.dept); 
 gotoxy(print,15);printf("Phone Number: ");scanf("%d",&stu.Phone_no); 
 ///gotoxy(print,20);printf("Phone Number: ");scanf("%d",&stu.phone_no); 
 fwrite(&stu, sizeof(stu), 1, fp); 
 
 } 
 
 fclose(fp); 
 gotoxy(5,17); printf("The record is sucessfully added"); 
 gotoxy(5,18);printf("Save any more Y/N"); 
 if(getch()=='n') 
 mainmenu(); 
 else 
 system("cls"); 
 addmember(); 
} 
 
 
 
 
void deletemember( ) 
{ 
 system("cls"); 
 int d; 
 char another='y'; 
 while(another=='y') 
 { 
 system("cls"); 
 gotoxy(5,2); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(5,3); 
 printf("|====== STUDENT SECTION ======|"); 
 gotoxy(5,4); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 
 
 gotoxy(5,5); 
 printf("----------- DELETE STUDENT ------------"); 
 gotoxy(5,7); 
 printf("Enter the Student ID:"); 
 scanf("%d",&d); 
 fp=fopen("record_nxt.txt","rb+"); 
 rewind(fp); 
 while(fread(&stu,sizeof(stu),1,fp)==1) 
 { 
 if(stu.ID==d) 
 { 
 gotoxy(5,9); 
 printf("Student name is %s",stu.name); 
 gotoxy(5,10); 
 
 fm='Z'; 
 } 
 else{ 
 fm='M'; 
 } 
 } 
 if(fm!='Z') 
 { 
 gotoxy(5,10); 
 printf("No record is found in LIST"); 
 mainmenu(); 
 } 
 if(fm=='Z' ) 
 { 
 gotoxy(5,11); 
 printf("The Student is available"); 
 gotoxy(5,12); 
 printf("Do you want to delete it?(Y/N):"); 
 if(getch()=='y') 
 { 
 ft=fopen("test.txt","wb+"); 
 rewind(fp); 
 while(fread(&stu,sizeof(stu),1,fp)==1) 
 { 
 if(stu.ID!=d) 
 { 
 
 fwrite(&stu,sizeof(stu),1,ft); 
 } 
 } 
 fclose(ft); 
 fclose(fp); 
 remove("record_nxt.txt"); 
 rename("test.txt","record_nxt.txt"); 
 fp=fopen("record_nxt.txt","rb+"); 
 if(fm=='Z') 
 { 
 gotoxy(5,13); 
 printf("The record is sucessfully deleted"); 
 gotoxy(5,14); 
 printf("Delete another record?(Y/N)"); 
 } 
 } 
 else 
 mainmenu(); 
 fflush(stdin); 
 another=getch(); 
 } 
 } 
 gotoxy(5,15); 
 mainmenu(); 
 ///returnfunc(); 
 
} 
 
 
void searchmember(void) 
{ 
 system("cls"); 
 int s; 
 gotoxy(5,2); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(5,3); 
 printf("|====== STUDENT SECTION ======|"); 
 gotoxy(5,4); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 
 gotoxy(5,5); 
 printf("------------ SEARCH STUDENT -----------"); 
 gotoxy(5,7); 
 printf("Enter the Student ID to search:"); 
 scanf("%d",&s); 
 fp=fopen("record_nxt.txt","rb+"); 
 rewind(fp); 
 while(fread(&stu,sizeof(stu),1,fp)==1) 
 { 
 if(stu.ID==s) 
 { 
 
 gotoxy(5,9); 
 printf("The Student is available"); 
 
 gotoxy(5,11); 
 printf("ID: %d",stu.ID); 
 gotoxy(5,12); 
 printf("Name: %s",stu.name); 
 gotoxy(5,13); 
 printf("Address: %s",stu.add); 
 gotoxy(5,14); 
 printf("Department name: %s",stu.dept); 
 gotoxy(5,15); 
 printf("Phone No: %d",stu.Phone_no); 
 
 fm='Z'; 
 } 
 } 
 if(fm!='Z') 
 { 
 gotoxy(5,12); 
 printf("No record is found in LIST"); 
 if(getch()) 
 
 mainmenu(); 
 } 
 
 { 
 gotoxy(5,11); 
 printf(""); 
 fclose(fp); 
 returnfunc(); 
 getch(); 
 } 
} 
 
 
void viewmember(void) 
{ 
 
 system("cls"); 
 
 FILE *fp; 
 int i=0,j; 
 system("cls"); 
 gotoxy(5,2); 
 printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(5,3); 
 printf("\t\t|====== STUDENT SECTION ======|"); 
 gotoxy(5,4); 
 printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 
 gotoxy(5,5); 
 printf("\t\t------------ STUDENT LIST -------------"); 
 gotoxy(2,7); 
 printf(" STUDENT_ID STUDENT NAME ADDRESS DEPARTMENT PHONE_NO "); 
 j=9; 
 fp=fopen("record_nxt.txt","rb"); 
 while(fread(&stu,sizeof(stu),1,fp)==1) 
 { 
 gotoxy(3,j); 
 printf("%d",stu.ID); 
 gotoxy(14,j); 
 printf("%s",stu.name); 
 gotoxy(28,j); 
 printf("%s",stu.add); 
 gotoxy(40,j); 
 printf("%s",stu.dept); 
 gotoxy(55,j); 
 printf("%d",stu.Phone_no); 
 
 gotoxy(69,j); 
 
 printf("\n\n"); 
 j++; 
 i=i+1; 
 } 
 gotoxy(3,25); 
 printf("Total Students =%d",i); 
 fclose(fp); 
 gotoxy(35,25); 
 returnfunc(); 
 getch(); 
} 
 
 
void event(void) 
{ 
 
 system("cls"); 
 int i; 
 gotoxy(20,3); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd EVENT MENU \xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(20,5); 
 printf("1. Add Event "); 
 gotoxy(20,7); 
 printf("2. View Event"); 
 gotoxy(20,9); 
 printf("3. Delete Event"); 
 gotoxy(20,11); 
 printf("4. Mainmenu"); 
 gotoxy(20,12);printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(20,15);printf("Enter Your Choice"); 
 switch(getch()){ 
 case '1': 
 addevent(); 
 break; 
 case '2': 
 vieweevent(); 
 break; 
 case '3': 
 deleteevent(); 
 case'4': 
 mainmenu(); 
 default:{ 
 gotoxy(20,22);printf("Wrong!!Please choose valid Option\a"); 
 if (getch()) 
 mainmenu(); 
 
 } 
 } 
} 
 
 
void addevent() 
{ 
 system("cls"); 
 gotoxy(26,2); 
 printf("\xcd\xcd\xcd\xcd Add Event \xcd\xcd\xcd"); 
 int print = 25; 
 fp = fopen("record.dat","ab+"); 
 if(fp == NULL){ 
 MessageBox(0,"Error in Opening file\nMake sure your file is not protected","Warning",0); 
 
 }else{ 
 fflush(stdin); 
 gotoxy(print,5);printf("Event date:");gets(stu.date); 
 gotoxy(print,6);printf("Event name: ");gets(stu.title); 
 gotoxy(print,7);printf("Details: ");gets(stu.z); 
 fwrite(&stu, sizeof(stu), 1, fp); 
 gotoxy(40,12); printf("The record is sucessfully added"); 
 } 
 
 fclose(fp); 
 gotoxy(40,13);printf("Save any more Y/N"); 
 if (getch()=='n') 
 mainmenu(); 
 else 
 system("cls"); 
 addevent(); 
 
 gotoxy(25,20); 
 returnfunc(); 
 getch(); 
} 
 
 
void deleteevent() 
{ 
 system("cls"); 
 char date[20]; 
 fflush(stdin); 
 
 printf("\n\n\tDELETE event\n\t==========================\n\tEnter the date to delete:"); 
 
 gets(date); 
 fp=fopen("record.dat","r"); 
 ft=fopen("temp.dat","w"); 
 while(fread(&stu,sizeof(stu),1,fp)!=0) 
 if (stricmp(date,stu.date)!=0) 
 fwrite(&stu,sizeof(stu),1,ft); 
 fclose(fp); 
 fclose(ft); 
 remove("record.dat"); 
 rename("temp.dat","record.dat"); 
 printf("\n\t\tRecord is delete"); 
 
 gotoxy(25,25); 
 returnfunc(); 
 getch(); 
} 
 
 
 
void vieweevent() 
{ 
 system("cls"); 
 
 int j=5; 
 gotoxy(1,1); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd view events \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(1,3);printf("Event date Event name Details"); 
 
 fp=fopen("record.dat","rb"); 
 while(fread(&stu,sizeof(stu),1,fp)==1) 
 { 
 
 gotoxy(1,j); 
 printf("%s",stu.date); 
 gotoxy(18,j); 
 printf("%s",stu.title); 
 gotoxy(46,j); 
 printf("%s",stu.z); 
 j++; 
 } 
 fclose(fp); 
 
 gotoxy(25,25); 
 returnfunc(); 
 getch(); 
} 
 
 
void editmember(void) 
{ 
 system("cls"); 
 
 int s,print=37; 
 gotoxy(15,3); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd Edit STUDENT info \xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(10,5); 
 printf("Enter the STUDENT ID to edit:"); 
 scanf("%d",&s); 
 fp=fopen("record_nxt.txt","rb+"); 
 
 while(fread(&stu,sizeof(stu),1,fp)==1) 
 { 
 if(stu.ID==s) 
 { 
 
 gotoxy(10,7); 
 printf("The Student is available"); 
 
 fflush(stdin); 
 gotoxy(print,12);printf("Name: ");gets(stu.name); 
 gotoxy(print,14);printf("Address: ");gets(stu.add); 
 gotoxy(print,16);printf("Department name: ");gets(stu.dept); 
 gotoxy(print,18);printf("Phone Number: ");scanf("%d",&stu.Phone_no); 
 gotoxy(print,22);printf("The record is modified"); 
 fseek(fp,-sizeof(stu), SEEK_CUR); 
 fwrite(&stu,sizeof(stu), 1, fp); 
 
 fm=1; 
 break; 
 } 
 } 
 if(fm!=1) 
 { 
 gotoxy(10,10); 
 printf("No record is found in LIST"); 
 if(getch()) 
 mainmenu(); 
 } 
 
 fclose(fp); 
 
 gotoxy(37,22); 
 returnfunc(); 
 getch(); 
} 
 
 
 
void returnfunc(void) 
{ 
 { 
 gotoxy(25,25); 
 printf("Press ENTER to return the main menu"); 
 } 
 if(getch()==13) 
 mainmenu(); 
} 
int t(void) 
{ 
 time_t t; 
 time(&t); 
 printf("Date and time:%s\n",ctime(&t)); 
 
 return 0 ; 
} 
 
void fordelay(int j) 
{ 
 int i,k; 
 for(i=0;i<j;i++) 
 k=i; 
} 
 
 
void password(void) 
{ 
 system("cls"); 
 char pass[10],ch,password[10]="admin"; 
 int i=0; 
 gotoxy(5,2); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(5,3); 
 printf("|====== STUDENT SECTION ======|"); 
 gotoxy(5,4); 
 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"); 
 gotoxy(5,5); 
 printf("Enter the password:"); 
 
 while(ch!=13) 
 { 
 ch=getch(); 
 
 if(ch!=13 && ch!=8){ 
 putch('*'); 
 pass[i] = ch; 
 i++; 
 } 
 } 
 pass[i] = '\0'; 
 
 
 if(strcmp(pass,password)==0){ 
 gotoxy(5,8); 
 printf("Password Matched!!"); 
 gotoxy(5,9); 
 printf("Loading "); 
 for(i=0;i<=6;i++) 
 { 
 fordelay(100000000); 
 
 printf("."); 
 } 
 system("cls"); 
 mainmenu(); 
 } 
 else 
 gotoxy(5,13); 
 printf("Password is invalid!!\a"); 
 printf("\tENTER correct password"); 
 getch(); 
 main(); 
} 
//Teacher code 
void showing(void) 
{ 
 cout<<"\n\n\t\t\t################ TEACHERS TABLE #########################\n\n"; 
 Teacher teacherArray[47] = { Teacher(1,"Ms.S.N.Deshmukh", "--", "--","Dean Administration", 20), 
 Teacher(2,"Mr.S.U.Aboti", "--", "--","Office Suprintendent", 20), 
 Teacher(3,"Dr.R.J.Yadav", "--", "--","Dean R&D", 21), 
 Teacher(4,"Dr.P.K.Katare", "--", "--","Dean Academics", 22), 
 Teacher(5,"Dr.K.R.Patil", "--", "--","MMCIII Coordinator", 20), 
 Teacher(6,"Dr.V.R.Deulgaonkar", "--", "--","Dean Student Affairs", 20), 
 Teacher(7, "Dr.H.K.Khanuja", "Computer", "--", "HOD",10), 
 Teacher(8,"Dr.V.S.Bidve", "IT", "--","HOD", 10), 
 Teacher(9,"Ms.P.S.Sawant", "ENTC" ,"--", "HOD",10), 
 Teacher(10,"Dr.P.S.Purandare", "Mechanical", " --", "HOD",10), 
 Teacher(11,"Dr.V.N.Gohokar", "Electrical", " --", "HOD",10), 
 Teacher(12,"Ms.Shubhda Mone", "Computer", "FDS","Assist.Prof", 10), 
 Teacher(13,"Ms.Asma Shaikh", "Computer", "OOP","Assist.prof", 10), 
 Teacher(14,"Ms.Vandana Rupnur", "Computer", "CG","Assist.Prof", 10), 
 Teacher(15,"Dr.Arti Agarkar", "Computer", "DM","Assist.prof", 10), 
 Teacher(16,"Ms.Ila Savant", "Computer", "DELD","Assis.prof", 10), 
 Teacher(17,"Ms.Poornima Muchute", "Computer", "BCSL","Assist.prof", 10), 
 Teacher(18,"Dr.Dhanshree Ghare", "Computer", "HSS","Assist.prof", 10), 
 Teacher(19,"Dr.S.M.Chawre", "Computer", "--","Assist.prof", 22), 
 Teacher(20,"Ms.P.S.Mehta", "Computer", "--","Assist.prof", 10), 
 Teacher(21,"Ms. Chopade R.M", "IT", "--","Assist.prof", 14), 
 Teacher(22,"Ms. Joshi P.S. ", "IT", "--","Assist.prof", 12), 
 Teacher(23,"Ms. Kuche P.R", "IT", "--","Assist.prof", 14), 
 Teacher(24,"Ms. Kakad S.A. ", "IT", "--","Assist.prof", 11), 
 Teacher(25,"Ms. Bhattad R.M. ", "IT", "--","Assist.prof", 10), 
 Teacher(26,"Mr. Dhavse N.S. ", "IT", "--","Assist.prof", 7), 
 Teacher(27,"Mr. Kamble P.B", "IT", "--","Assist.prof", 6), 
 Teacher(28,"Ms.R.R.Malekar", "ENTC", "EC","Assist.prof", 10), 
 Teacher(29,"Dr.H.N.Burande", "ENTC", "DC","Assist.prof", 10), 
 Teacher(30,"Mr.J.M.Bakliwal", "ENTC", "Electrical","Assist.Prof", 10), 
 Teacher(31,"Dr.M.R.Pangaonkar", "ENTC", "DS","Assist.Prof", 10), 
 Teacher(32,"Mr.V.B.Deokamble", "ENTC", "E.S.D","Assist.prof", 10), 
 Teacher(33,"Ms.Mayuri Rathod", "ENTC", "DS","Assist.prof", 10), 
 Teacher(34,"Mr.M.P.Rode", "Mechanical", "SOM","Assist.Prof", 10), 
 Teacher(35,"Dr.V.W.Bhatkar", "Mechanical", "THERM","Assist.Prof", 10), 
 Teacher(36,"Mr.P.S.Khude", "Mecanical", "EMM","Assist.Prof", 10), 
 Teacher(37,"Mr.M.P.Pandagale", "Mechanical", "SM&D","Assist.Prof", 10), 
 Teacher(38,"Ms.S.S.Bakshi", "Mechanical", "EEE","Assist.Prof", 10), 
 Teacher(39,"Dr.Tarambale.M.R", "Electrical", "--","Assist.Prof", 13), 
 Teacher(40,"Mr.Bhure B.B.", "Electrical", "--","Assist.Prof", 14), 
 Teacher(41,"Ms.Upasani S.A", "Electrical", "--","Assist.Prof", 15), 
 Teacher(42,"Mr.Harite S. M.", "Electrical", "--","Assist.Prof", 15), 
 Teacher(43,"Mr. Jadhav S.C.", "Electrical", "--","Assist.Prof", 16), 
 Teacher(44,"Mr. Choube P. R.", "Electrical", "--","Assist.Prof", 7), 
 Teacher(45,"Ms. Thottan C. P.", "Electrical", "--","Assist.Prof", 5), 
 Teacher(46,"Mr. Suryawanshi A. M.", "Electrical", "--","Assist.Prof", 5), 
 Teacher(47,"Ms. Hume D. S.", "Electrical", "--","Assist.Prof", 3)}; 
 cout <<left 
 <<setw(10) 
 << "Sr.No" 
 << left 
 << setw(25) 
 << " Name" 
 << left 
 << setw(15) 
 << " Department" 
 << left 
 << setw(12) 
 << " Subject" 
 << left 
 << setw(25) 
 << " Designation" 
 << left 
 << setw(30) 
 << " Experience(in.years)" <<endl; 
 for (int i = 0; i < 48; i++) 
 { 
 cout <<left 
 <<setw(10) 
 <<teacherArray[i].Sr 
 << left 
 << setw(25) 
 << teacherArray[i].Name 
 << left 
 << setw(15) 
 << teacherArray[i].DepartmentName 
 << left 
 << setw(14) 
 << teacherArray[i].Subject 
 << left 
 << setw(25) 
 << teacherArray[i].Designation 
 << left 
 << setw(30) 
 << teacherArray[i].Experience 
 
 << endl; 
 } 
} 
void displaying(void) 
{ 
 cout<<"\n\n\t\t\t######### PROMINENT ALUMNI ###########\n\n"; 
 Student studentArray[21] = {Student(1,"Mr.Abhijit Navghane", 2015, "MBA","Nexa", "Relationship Manager"), 
 Student(2,"Ms.Ashwini Rathi", 2016, "MBA", "Bentley Systems", "Sales Manager"), 
 Student(3,"Ms.Neha Ghatkar", 2017, "MBA", "Calsoft Inc", "HR Executive"), 
 Student(4,"Ms.Shravani Jadhav", 2017, "MBA", "Allianz", "HR Executive"), 
 Student(5,"Mr.Vinod Khute", 2010, "Computer", "Vispwallet, Pune", "Founder &CEO"), 
 Student(6,"Mr.Akshayrj Kore", 2011, "Computer", "Oracle,Arligton,VA", "India’s 32ndGrandmaster(chess)"), 
 Student(7,"Mr.Piyush Kulkarni", 2012, "Computer", "Muktaayan,Art Theartre,Pune", "Founder,Music director"), 
 Student(8,"Mr.Rohan Thuse", 2013, "Computer", "Ripein, Pune", "Founder &CEO"), 
 Student(9,"Mr.Shubham Kulkarni", 2017, "Computer", "CeleryHQ, Pune", "Head of Busines &Cofounder"), 
 Student(10,"Mr.Manoj Potdar", 2010, "Mechanical", "MCad Solutions (I) Ltd.", "Founder &CEO"), 
 Student(11,"Mr.Rupesh Gosavi", 2012, "Mechanical","IECERA", "Technology Director"), 
 Student(12,"Mr.Bhagwan Shinde", 2015, "Mechanical", "Shree Quality Sevice", "Sales Manager"), 
 Student(13,"Mr.Abhimanyu Pataharkar", 2016, "Mechanical","Indian Army", "Officer"), 
 Student(14,"Mr.Nitin Sadubattula", 2011, "IT", "--", "Founder,Director"), 
 Student(15,"Mr.Nachiket Dhaval", 2011, "IT", "--","Director"), 
 Student(16,"Mr.Siddhart Thoke", 2012, "IT", "R.T.O","Assistant"), 
 Student(17,"Mr.Prateek Sonare", 2012, "IT", "--","Assistant Commandant"), 
 Student(18,"Mr.Jaideep Honap", 2010, "E&TC", "Senior Consultant Area", "Financial Services Advisory"), 
 Student(19,"Mr.Avadhoot Herlekar", 2011, "E&TC", "Intelux Electronic Pvt.Ltd", "HR Excecutive"), 
 Student(20,"Mr.Ankur Khangaonkar", 2013, "E&TC", "--","Senior Strategist"), 
 Student(21,"Mr.Nihan Pol", 2015, "E&TC", "--", "Pursuing Phd in Astrophysics") 
 }; 
 cout 
 << left 
 << setw(6) 
 << "Sr.No" 
 << left 
 << setw(24) 
 << "Alumni Name" 
 << left 
 << setw(13) 
 << "Passing Year" 
 << left 
 << setw(18) 
 << "Department Name" 
 << left 
 << setw(30) 
 << "Name of Company" 
 << left 
 << setw(40) 
 << "Position Held" 
 << endl; 
 cout<<"\n"; 
 for (int i = 0; i < 21; i++) 
 { 
 cout 
 << left 
 << setw(6) 
 << studentArray[i].studentSr 
 << left 
 << setw(24) 
 << studentArray[i].alumniName 
 << left 
 << setw(13) 
 << studentArray[i].passingYear 
 << left 
 << setw(18) 
 << studentArray[i].departmentName 
 << left 
 << setw(30) 
 << studentArray[i].nameOfCompany 
 << left 
 << setw(40) 
 << studentArray[i].positionHeld 
 << endl; 
 
 } 
 cout<<"\n\n\nOur alumni have played an important role in building the credibility of our institute. In fact, they are our ambassadors who shine the light of our beliefs everywhere they go. The institute involves the alumni in its educational and research activities whenever possible, by inviting them for the following activities:-"; 
 cout<<"\n\t1.Participate on advisory boards "<<"\n\t2.For taking expert lectures for students as guest speakers for training programs"<<"\n\t3.For assistance in placement/internship related activities consultancy services"; 
 cout<<"\n\nBenefits of Alumni Meet:-"; 
 cout<<"\n\t1.Assistance for Placements"<<"\n\t2.And Industrial visits"<<"\n\t3.Donation of equipment/books to the institute"<<"\n\t4.Assistance for higher studies"<<"\n\t5.Assisting the graduating students for M.S and Ph. D programs in India and abroad"; 
 cout<<"\n\nWe genuinely appreciate the efforts taken by our alumni for our college and we are proud of what our students have accomplished today."; 
 cout<<"\n\n\t\t#We wish them best of luck with all of their future endeavours#"; 
} 
void showing2(void) 
{ 
 hostel objectives; 
 int key_rooms; 
 char channels; 
 int checking_floors; 
 objectives.create(); 
 do 
 { 
 cout << "\n1. Book a single occupied room\n2. Book a 2 sharing room\n3. Book a 3 sharing room\n4. Display the current status of rooms\n5. Cancel a booking\n6. Modify\n7. Exit"<< endl; 
 cout << " Enter your choice : " ; 
 cin >> key_rooms; 
 switch (key_rooms) 
 { 
 case 1: 
 { 
 objectives.booking(1); 
 break; 
 } 
 case 2: 
 { 
 objectives.booking(2); 
 break; 
 } 
 case 3: 
 { 
 objectives.booking(3); 
 break; 
 } 
 case 4: 
 { 
 objectives.display(); 
 break; 
 } 
 case 5: 
 { 
 cout << "Enter floor number : "; 
 cin >> checking_floors; 
 objectives.cancelled(checking_floors); 
 break; 
 } 
 case 6: 
 { 
 cout << "Enter floor number : "; 
 cin >> checking_floors; 
 objectives.modify(checking_floors); 
 break; 
 } 
 case 7: 
 break; 
 default: 
 cout << "\nInvalid choice "; 
 } 
 cout << "\nDo you want to continue(Y / N) "; 
 cin >> channels; 
 } while (channels =='Y'|| channels =='y'); 
} 
