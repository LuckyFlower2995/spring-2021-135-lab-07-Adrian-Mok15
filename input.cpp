/*Adrian Mok
CSCI 135
                    Professor Tong Yi
Project 1d*/
// Program takes calculator instructions prints out the output (only positive numbers). Supports multiple lines when separated by ';'
                                                #include <iostream>
                                                                                    using namespace std;


                        int find_number(){// look at each number and evaluate the square if there is one
	                                   int number;
	char c;
	                                       cin >> number;
	                                               cin >> c;
	if (c == '^'){
		              number = number*number;
	}
	                                               else{
		cin.putback(c);//puts the char back to keep the flow of chars and ints aligned
	                           }
	                   return number;
}
int main(){
	                       char op;
	int sum = find_number();//set first number as sum
	                       while(cin >> op){
		                             int num = find_number();
		                                      if(op == '-'){
			                                                 sum -= num;
		}
		              else if(op == '+'){
			sum += num;
	}
		                  else if(op == ';'){
			cout << sum << "\n";
			                     sum = num;//num isn't used in the loop so it should be declared as the new sum for the new line.
		}
	                   }
}
