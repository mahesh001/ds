#include<iostream>
#include <string>
using namespace std;


class person
{
public:
string name;
int age;

void SetInfo(const string _name, int _age)
{
    name = _name;
    age = _age;
}
int getAge(){ return age; }
};

int Linearsearch(person* personarray, int key)
{
for (int i = 0; i < 10; i++)
{
    if (personarray[i].age == key)
        return i;
}
return -1;
}

void bubblesort(person mylist[], int n)
{
for (int i = 1; i<n; i++)
{

    for (int j = 0; j<n - 1; j++)
    {
        if (mylist[j].getAge() > mylist[j + 1].getAge())
        {
            person temp;
            temp = mylist[j];
            mylist[j] = mylist[j + 1];
            mylist[j + 1] = temp;
        }
    }
}
}

int main()//start of program
{
int mylist[100],i,age;
cout<<"enter the no of person\n";
cin>>i;
cout<<"enter the name and age of person\n";

mylist[i].SetInfo("name",age);

//calling bubblesort()
bubblesort(mylist, i);
int index = Linearsearch(mylist, 20);
if (index == -1)
    cout << "person not found!";
else
    cout << "the person you searched for " << mylist[index].name;

cin.get();
return 0;
}
