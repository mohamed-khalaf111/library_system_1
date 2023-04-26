#include <iostream>
#include<algorithm>
#include<string>
using namespace std;
//books data
int book_id[100];
int book_quantity[100];
string book_name[100];
static int added_books;
/////////////////////////////////////////
//user data
int user_id[100];
string user_name[100];
static int added_users;
////////////////////////////////////////
//borrowing data
int counter_borrowed_books[100]={0};
string names_user_borrow[100];
string names_books_borrowed[100];
int ids_borrowed[100];
static int added_borrowed_books;
/////////////////////////////////////////
  // borrow function
 string name_of_user;
 string name_of_book;
 int flag_name=0;
 int flag_quan=0;
 int flag_nameuser=0;
 /////////////////////////////
struct borrowed{

    void b(string nameofuser, string nameofbook){
        names_user_borrow[added_borrowed_books]=nameofuser;
        names_books_borrowed[added_borrowed_books]=nameofbook;
        for(int i=0;i<added_books;i++)
        {
            if(nameofbook==book_name[i])
            {
                ids_borrowed[added_borrowed_books]=book_id[i];
            }

        }
        ++added_borrowed_books;
        return;
    }
};


struct user_info{
   void add_user(int id , string name ){
        user_id[added_users]=id;
        user_name[added_users]=name;
        ++added_users;
    }
};

struct book_info{
  void  add_book(int id , string name , int quantity){
    book_id[added_books]=id;
    book_quantity[added_books]=quantity;
    book_name[added_books]=name;
    ++added_books;

    }
};

struct books_operations{

    book_info books[100];

    void add_book()
    {
        static int pos=0;
        int id,quantity;
        string name;
        cout<<"Enter book info : id , name and qauntity \n\n";
        cin>>id>>name>>quantity;

        books[pos].add_book(id,name,quantity);
        ++pos;
    }
   void print_library_by_id() {
   for(int i=0;i<added_books;i++)
        cout<<"id = "<<book_id[i]<<" name = "<<book_name[i]<<" total_quantity = "<<book_quantity[i]<<" "<<"total_borrowed = "<<counter_borrowed_books[i]<<endl;
}

        void print_library_by_name(){
    for(int i=0;i<added_books;i++)
        cout<<"id = "<<book_id[i]<<" name = "<<book_name[i]<<" total_quantity = "<<book_quantity[i]<<" "<<"total_borrowed = "<<counter_borrowed_books[i]<<endl;
}

  void  who_borrowed(){
        string nameofbook;
        cout<<"Enter name of book \n";
        cin>>nameofbook;
        for(int i=0;i<added_borrowed_books;i++)
        {
            if(nameofbook==names_books_borrowed[i])
                cout<<names_user_borrow[i]<<endl;
        }
    }
    void searching(){
        string str;
        cout<<"Enter book perfix \n";
        cin>>str;
        int n = str.size();
        int flag_perfix=0;
        for(int j=0;j<added_books;j++)
        {
        int cnt=0;
        string name = book_name[j];
            for(int l=0;l<n;l++)
            {
                if(str[l]==name[l])
                {
                    ++cnt;
                }
        }
        if(cnt==n)
            cout<<name<<endl;
        else if(cnt==0)
            flag_perfix++;
        if(flag_perfix==added_books)
            cout<<"no books with such perfix \n";
        }
    }
};

struct user_operations{
    user_info users[100];
    borrowed borrowed_books[100];
  void  add_user(){
        int id;
        string name;
        int pos=0;
        cout<<"Enter user info : id and name  \n";
        cin>>id>>name;
        users[pos].add_user(id,name);
        ++pos;
    }
  void borrow_book(){
        cout<<"Enter name of user and name of book \n";
        cin>>name_of_user>>name_of_book;
        int vi;
        for(int i=0;i<added_users;i++)
        {
            if(name_of_user==user_name[i])
                flag_nameuser=1;
        }
        if(flag_nameuser)
        {
            for(int i=0;i<added_books;i++)
            {
                if(name_of_book==book_name[i])
                    {
                        flag_name=1;
                        vi=i;
                        if(book_quantity[i]>0)
                            flag_quan=1;
                    }
            }
        }
        else
        {
            cout<<"user name is not founded \n";
            return;
        }
        if(flag_name)
        {
            if(flag_quan)
            {
                book_quantity[vi]--;
                counter_borrowed_books[vi]++;
                borrowed_books[added_borrowed_books].b(name_of_user,name_of_book);

            }
            else
            {
                cout<<"there is not enough quantity of this book \n";
            }

        }
        else
            cout<<"name of book is not founded \n";
        flag_name=0;
        flag_nameuser=0;
        flag_quan=0;

    }
 void   return_book(){
        string nameofuser;
        string nameofbook;
        cout<<"enter name of user and name of book \n ";
        cin>>nameofuser>>nameofbook;
        int flag=0;
        for(int i=0;i<added_borrowed_books;i++)
        {
           if(nameofuser==names_user_borrow[i])
           {
               flag=1;
           }
        }
        if(flag){

        for(int i=0;i<added_books;i++)
        {
            if(nameofbook==book_name[i])
            {
                ++book_quantity[i];
                --counter_borrowed_books[i];
                break;
            }
            else
                cout<<"name of book is not founded \n";
        }
        for(int i=0;i<added_borrowed_books;i++)
        {
            if(nameofbook==names_books_borrowed[i]&&nameofuser==names_user_borrow[i])
                ids_borrowed[i]=-1;
        }}
        else
            {
                cout<<"name of user  is not founded \n";

                return;
            }

    }
   void print_users(){
        for(int i=0;i<added_users;i++)
        {
            cout<<"user "<<user_name[i]<<" with id "<<user_id[i]<<" borrowed books with ids : ";
            for(int j=0;j<added_borrowed_books;j++)
            {
                if((user_name[i]==names_user_borrow[j]))
                {
                    if(ids_borrowed[j]!=-1)

                        cout<<ids_borrowed[j]<<" ";
                }

            }
            cout<<endl;
        }

    }

};

int menue(){
    int choice=-1;
    while(choice==-1)
    {
        cout<<"Enter your choice \n";
        cout<<"1 add book \n";
        cout<<"2 print library by id  \n";
        cout<<"3 print library by name \n";
        cout<<"4 add user \n";
        cout<<"5 who borrowed this book \n";
        cout<<"6 borrow book \n";
        cout<<"7 return book \n";
        cout<<"8 print users \n";
        cout<<"9 searching \n";
        cout<<"10 exite \n";
        cin>>choice;
        if(!(choice>=1&&choice<=10))
        {
            cout<<"invalid choice \n";
            choice=-1;
        }

    }
            return choice;

}
void library_system(){
    books_operations book;
    user_operations user;
    while(true){
    int choice=menue();
    if(choice==1)
        book.add_book();
    else if(choice==2)
        book.print_library_by_id();
    else if(choice==3)
        book.print_library_by_name();
    else if(choice==4)
        user.add_user();
    else if(choice==5)
        book.who_borrowed();
    else if(choice==6)
        user.borrow_book();
    else if(choice==7)
        user.return_book();
    else if(choice==8)
        user.print_users();
    else if(choice==9)
        book.searching();
    else
        break;

        }

}

int main()
{
    library_system();

    return 0;
}
