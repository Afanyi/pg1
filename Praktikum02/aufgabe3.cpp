#include <iostream>

int main() {
	int n{0};
	std::cin >> n;
	bool minus{false};
	if (n < 0) { 
		minus = true;
		n = n* -1;
	}
	for (int i=1; i<=n; i=i+2) { 
		if (minus) 
			std::cout << "-";
		std::cout << i << "² = " << i*i << std::endl;
	}
}
