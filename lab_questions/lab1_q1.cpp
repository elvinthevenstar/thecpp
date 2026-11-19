#include <iostream>

namespace Math {
	class Calculator {
		public:
			int add(int a, int b)
			{
				return (a + b);
			}
			
			double add(double a, double b)
			{
				return (a + b);
			}
			
			int substract(int a, int b)
			{
				return (a - b);
			}
			
			double substract(double a, double b)
			{
				return (a - b);
			}
			
			int multiply(int a, int b)
			{
				return (a * b);
			}
			
			double multiply(double a, double b)
			{
				return (a * b);
			}
	
			int divide(int a, int b)
			{
				return (a / b);
			}
			
			double divide(double a, double b)
			{
				return (a / b);
			}
	};
	
}

using namespace Math;

int main(){
	
	Calculator obj;
	
	int  int_1, int_2;
	
	double double_1, double_2;
	
	char op_int, op_double;
	
	std::cout << "Enter two integer numbers:";
	std::cin >> int_1 >> int_2;
	
	std::cout << "Enter two double numbers:";
	std::cin >> double_1 >> double_2;
	
	std::cout << "Enter the desired operation to perform on integer numbers: ";
	std::cin >> op_int;
	
	std::cout << "Enter the desired operation to perform on double numbers: ";
	std::cin >> op_double;
	
	std::cout << "Results for the operations: \n";
	
	// integer operations
	
	if (op_int == '+')
	{
		std::cout << "Addition of "<< int_1 << " and " << int_2 << " is: " << obj.add(int_1, int_2) << "\n";
	}
	
	else if (op_int == '-')
	{
		std::cout << "Substraction of "<< int_1 << " and " << int_2 << " is: " << obj.substract(int_1, int_2) << "\n";
	}
	
	else if (op_int == '*')
	{
		std::cout << "Multiply of "<< int_1 << " and " << int_2 << " is: " << obj.multiply(int_1, int_2) << "\n";
	}
	
	else if (op_int == '/')
	{
		if( int_2 == 0)
		{
			std::cout << "Division by zero error!" << "\n";
		}
		
		else
		std::cout << "Division of "<< int_1 << " and " << int_2 << " is: " << obj.divide(int_1, int_2) << "\n";
	}
	
	// double operations
	
	if (op_double == '+')
	{
		std::cout << "Addition of "<< double_1 << " and " << double_2 << " is: " << obj.add(double_1, double_2) << "\n";
	}
	
	else if (op_double == '-')
	{
		std::cout << "Substraction of "<< double_1 << " and " << double_2 << " is: " << obj.substract(double_1, double_2) << "\n";
	}
	
	else if (op_double == '*')
	{
		std::cout << "Multiply of "<< double_1 << " and " << double_2 << " is: " << obj.multiply(double_1, double_2) << "\n";
	}
	
	else if (op_double == '/')
	{
		if( double_2 == 0)
		{
			std::cout << "Division by zero error!" << "\n";
		}
		
		else
		std::cout << "Division of "<< double_1 << " and " << double_2 << " is: " << obj.divide(double_1, double_2) << "\n";

return(0);
	}
	
	
	return(0);
}
