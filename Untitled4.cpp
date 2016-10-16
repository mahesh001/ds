#include <iostream>
#include <string.h>

using namespace std;
const int size=5;
const int TRUE=1;
const int FALSE=0;
class Stack
{
private:
	int top;
	char num[size];
public:
	Stack();
	void push(char);
	char pop();
	char isempty();
	char isfull();
	char sort();
};

Stack::Stack()
{
	top = -1;
}

void Stack::push(char value)
{
	top++;
	num[top] = value;
}
char Stack::pop()
{
	char topval;
	topval=num[top]; // retrieve the top element
	top--; // decrement the index stored in top
	return(topval);
}

char Stack::sort()
{
	char ch1, ch2;
	ch1 = num[top];
	ch2 = num[top-1];
	if (ch1 < ch2)
		return ch1;
	else
		return ch2;
}

char Stack::isempty()
{
	if(top==-1)
		return TRUE;
	else
		return FALSE;
}

char Stack::isfull()
{
	if(top==size-1)
		return TRUE;
	else
		return FALSE;
}

void bubble(char *string[], const int k)
{
   int pass, i;
   char *temp;

   for (pass=0; pass < k - 1; pass++) {
      for (i=0; i<k - 1; i++) {
         if (strcmp(string[i], string[i+1]) > 0) {
            temp = string[i];
            string[i] = string[i+1];
            string[i+1] = temp;
         }
      }
   }
}

int main()
{
	Stack s; // define a Stack named digits
	Stack one;
	char *sorting = new char[size];
	//sorting = new char[sorting];
	char n;
	cout<<"Enter as many digits as you wish, one per line."
	    <<"\nTo stop entering digits, enter a number greater than 9. \n";
	while(1)
	{
		cout<<"Enter a digit: ";
		cin>>n;
		if (n == 'x')
			break;
		if(s.isfull()) //check overflow
		{
			cout<<"\nNo more storage allocation space."
				<<"\nThe last digit has not been entered on the stack."<<endl;
			break;
		}
		else
			s.push(n); // push value onto the stack
	}
// pop and display digits from the stack.
	cout<<"\nThe values popped from the stack are: \n";
	while(!s.isempty()) // check the underflow
	{
		for(int x = 0; x < size; x++)
		{
			char popval = s.pop();
			sorting[x] = popval;
			cout<<popval<<endl;
		}
	}
	bubble(sorting, size); 
	cout<<"Sorted Array"<<endl;
	for(int z=0; z<size; z++)
		cout<<sorting[z]<<endl;
	return 0;
}
