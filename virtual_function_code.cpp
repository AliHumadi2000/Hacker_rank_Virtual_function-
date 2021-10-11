#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person
{
   public:
   string name ;
   int age ;
   Person()
   {
       name="";
       age=0;

   }
   Person(string name,int age)
   {
       this->name=name;
       this->age=age;
   }
   virtual void getdata()
   {

   }
   virtual void putdata()
   {

   }
};
class Student:public Person
{
    public:
    int mark[6];
   inline static int cur_id=0;
    Student()
    {
        

    }
    void getdata()
    {

        string n;
        int ag;
        cin>>n>>ag;
        name=n;
        age=ag;
        for(int i=0;i<6;i++)
        {
            cin>>mark[i];
        }
    }
    void putdata()
    {
        int sum=0;
        for(int i=0;i<6;i++)
        {
            sum+=mark[i];
        }
        cout<<name<<" "<<age<<" "<<sum<<" "<<++cur_id<<endl;
    }
};
class Professor:public Person
{
    private:
   int publications ;
    static int p_cur_id;

   public:
   Professor()
   {
      
   }

   void getdata()
   {
       string na;
       int pub,a;
       cin>>na>>a>>pub;
       name=na;
       age=a;
       publications=pub;
   }
   void putdata()
   {
       cout<<name<<" "<<age<<" "<<publications<<" "<<++p_cur_id<<endl;
   }
};
int Professor::p_cur_id=0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
