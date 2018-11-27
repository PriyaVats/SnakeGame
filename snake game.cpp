#include<iostream>
#include<windows.h>
#define ROW 15
#define COL 55
#include <conio.h>
#include<stdlib.h>
#include<conio.h>
#include <fstream>
// Snake game in c++ With file handling!
using namespace std;
static char arrayy[15][80];
static int fnew=0;
static int pnew=0;
struct food
{
int x;
int y;
char value;
food *next;
};
struct poison
{
int x;
int y;
char value;
poison *next;
};
struct snake
{
int x;
int y;
char value;
snake *next;
};
class linked{
snake *head;
food *fhead;
poison *phead;
public:
    linked()
    {

        head=NULL;
        phead=NULL;
        fhead=NULL;
    }
    food *fcreate(int a,int b,char c)
    {
        food *f=new food;
        f->x=a;
        f->y=b;
        f->value=c;
        f->next=NULL;
        return f;
    }
    poison *pcreate(int a,int b,char c)
    {
        poison *p=new poison;
        p->x=a;
        p->y=b;
        p->value=c;
        p->next=NULL;
        return p;
    }
    snake* create(int a,int b,char c)
    {
        snake *ptr=new snake;
        ptr->x=a;
        ptr->y=b;
        ptr->value=c;
        ptr->next=NULL;
        return ptr;
    }
 void newfood(int f)
    {
       if(f==0)
       {
       inserttf(9,8,'f');

       }
       else if(f==1)
       {
        inserttf(2,4,'f');
       }
       else if(f==2)
       {
           inserttf(3,36,'f');
       }
       else
        {
            inserttf(9,15,'f');
             f=0;
             fnew=0;
         }
     }
void newpoison(int f)
{
       if(f==0)
       {
       inserttp(11,45,'p');

       }
       else if(f==1)
       {
        inserttp(4,24,'p');
       }
       else
        {
            inserttp(9,35,'p');
             f=0;
             pnew=0;
         }
     }
void welcome(){

system("color 5B");
char w[]="WELCOME";
    char t[]="  TO";
    char c[]="  Snake Game";
    int i;
for(i=0;i<89;i++)
cout<<"*";
for(i=0;i<6;i++)
    cout<<endl;
cout<<"\t\t\t\t";
cout<<w;
cout<<"";
cout<<t;
cout<<"";
cout<<c;
for(i=0;i<12;i++)
    cout<<endl;
for(i=0;i<89;i++)
cout<<"*";
cout<<endl<<"Press enter : ";
getchar();
}
    void display()
    {
         Sleep(70);
         system("cls");
        int k;
        snake *t;
        food *f;
        poison *p;
        f=fhead;
        p=phead;
        t=head;
        for(int i=0;i<ROW;i++)
        {
        for(int j=0;j<COL;j++)
        {
            if(i==0 || i==ROW-1 || j==0 || j==COL-1)
            {
             arrayy[i][j]='*';
            }
            else
            {
             arrayy[i][j]=' ';
            }
        }
        }
        for(int i=0;i<ROW;i++)
        {
        for(int j=0;j<COL;j++)
        {
            if(t!=NULL)
            {
               update(t->x,t->y,t->value);
               t=t->next;
            }
         }
       }
        for(int i=0;i<ROW;i++)
        {
        for(int j=0;j<COL;j++)
        {
            if(f!=NULL)
            {
               updatef(f->x,f->y,f->value);
               f=f->next;
            }
         }
       }
        for(int i=0;i<ROW;i++)
        {
        for(int j=0;j<COL;j++)
        {
            if(p!=NULL)
            {
               updatep(p->x,p->y,p->value);
               p=p->next;
            }
         }
       }
         Sleep(50);
        for(int i=0;i<ROW;i++)
      {
        for(int j=0;j<COL;j++)
        {
        cout<<arrayy[i][j];
        }
        cout<<endl;
      }
    }
   void updatef(int x,int y,char c)
     {
      for(int i=0;i<ROW;i++)
      {
          for(int j=0;j<COL;j++)
          {
                    if(x==i && y==j)
                {
                    arrayy[i][j]=c;
                }
          }
      }
     }
   void updatep(int x,int y,char c)
     {
      for(int i=0;i<ROW;i++)
      {
          for(int j=0;j<COL;j++)
          {
                    if(x==i && y==j)
                {
                    arrayy[i][j]=c;
                }
          }
      }
     }
     void update(int x,int y,char c)
     {
      for(int i=0;i<ROW;i++)
      {
          for(int j=0;j<COL;j++)
          {
                    if(x==i && y==j)
                {
                    arrayy[i][j]=c;
                }
          }
      }
     }
    void inserttp(int a,int b,char c)
    {
        poison *temp,*t;
     temp=pcreate(a,b,c);
     if(phead==NULL)
    {
        phead=temp;
     }else{
     t=phead;
     while(t->next!=NULL)
    {
        t=t->next;
     }
     t->next=temp;
     temp->next=NULL;
     }
    }
    void inserttf(int a,int b,char c)
    {
        food *temp,*t;
     temp=fcreate(a,b,c);
     if(fhead==NULL)
    {
        fhead=temp;
     }else{
     t=fhead;
     while(t->next!=NULL)
    {
        t=t->next;
     }
     t->next=temp;
     temp->next=NULL;
     }
    }
     void insertt(int a,int b,char c)
     {
     snake *temp,*t;
     temp=create(a,b,c);
     if(head==NULL)
    {
        head=temp;
     }else{
     t=head;
     while(t->next!=NULL)
    {
        t=t->next;
     }
     t->next=temp;
     temp->next=NULL;
     }
     }
     void shift(int x,int y)
     {
         int a1=x;
         int b1=y;
         snake *t=head;
         snake *t1=head;
         food *f=fhead;
         poison *p=phead;
         int x1,y1;
          int flag=0;
        while(t1!=NULL)
        {
            if(a1==t1->x && b1==t1->y)
            {
                flag=1;
                break;
            }
        t1=t1->next;
        }
      if(flag==1)
     {
      cout<<"Game Over!";
      exit(0);
     }
     if(flag==0)
     {
     if(f->x==a1 && f->y==b1)
     {
      fhead=NULL;
      newfood(fnew++);
      while(t->value!='T')
      {
        x1=t->x;
        y1=t->y;
        t->x=x;
        t->y=y;
        x=x1;
        y=y1;
        t=t->next;
      }
        x1=t->x;
        y1=t->y;
        t->x=x;
        t->y=y;
        t->value='#';
        x=x1;
        y=y1;
      snake *temp;
      temp=create(x,y,'T');
      t->next=temp;

     }
     else if(p->x==a1 && p->y==b1)
     {
         if(t->value=='H' && t->next->value=='T')
         {
             cout<<"Game Over !";
             exit(0);
         }else
         {
          phead=NULL;
          newpoison(pnew++);
         while(t->next->next!=NULL)
         {
            x1=t->x;
             y1=t->y;
             t->x=x;
             t->y=y;
             x=x1;
             y=y1;
             t=t->next;
         }
        t->x=x;
        t->y=y;
        t->value='T';
        t->next=NULL;
         }
     } else
     {
         while(t!=NULL)
         {
             x1=t->x;
             y1=t->y;
             t->x=x;
             t->y=y;
             x=x1;
             y=y1;
             t=t->next;

         }
    }
   }
     system("cls");
     display();
     }
     int left()
     {
       int c=0;
       snake *t,*temp;
       food *f;
       t=head;
       f=fhead;
       temp=head;
       int a=(t->x);
       int b=(t->y)-1;
       if(b==0)
       {
           b=COL-2;
           shift(a,b);
       }else
       {
           shift(a,b);
       }
       return 0;
     }

     int right()
     {
       int c=0;
       snake *t,*temp;
       t=head;
        temp=head;
       int a=(t->x);
       int b=(t->y)+1;
       if(b==COL-1)
       {
           b=1;
           shift(a,b);
       }
       else
        shift(a,b);
       return 0;
     }
     int top()
     {
     snake *t;
     snake *temp;
     t=head;
     int c=0;
     int a=(t->x)-1;
     int b=t->y;
       if(a==0)
       {
           a=ROW-2;
            shift(a,b);
       }
      else
        shift(a,b);
       return 0;

     }

     int bottom()
     {
     snake *t;
     snake *temp;
     t=head;
     int c=0;
     int a=(t->x)+1;
     int b=t->y;
       if(a==ROW-1)
       {
        a=1;
        shift(a,b);
       }
       else
        shift(a,b);
     return 0;
     }

};
int main()
{
    linked l;
    l.welcome();
system("COLOR FC");
char t;
char c,c1;

l.insertt(6,34,'H');
l.insertt(7,34,'#');
l.insertt(8,34,'#');
l.insertt(9,34,'T');
l.inserttf(2,4,'f');
l.inserttp(7,2,'p');



l.display();
int flag=0;
char d;
while(flag==0)
{
    if(kbhit())
    {
        c=getche();
        if(c=='q')
       {

            cout<<endl<<"Come Next Time !"<<endl<<"END!";
            break;

        }
        else if(d=='C')
        {

            continue;
        }
    }

    if(c!='a' && c!='d' && c!='w' && c!='s')
    {
        c=c1;
    }
    if(c=='a')
    {
        flag=l.left();
    }
    if(c=='d')
    {
        flag=l.right();
    }
     if(c=='w')
    {
        flag=l.top();
    }
    if(c=='s')
    {
       flag=l.bottom();
    }

   c1=c;
}
cout<<endl<<"Come Next Time !"<<"END!";

}
