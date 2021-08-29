#include <iostream>
 
int main()
{
	int n;
	std::cin >> n;
 
	for(int i = 1; i <= n; i++)
	{
		for(int k = 1; k <= (n - i); k++)
			std::cout << " ";
 
		std::cout << "Hello NPLC!" << std::endl;
	}
 
	return 0;
}