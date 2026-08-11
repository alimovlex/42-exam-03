#include <iostream>
#include <vector>
#include <string>

void ft_twist_sequence(const std::vector<std::string> &args)
{
	// Extract length and k from arguments (args[0] is the program name)
	std::vector<std::string>::const_iterator itr;
  itr = args.begin();
  int len = std::stoi(*++itr);
	int k = std::stoi(*++itr);

	// Handle empty array edge case safely
	if (len == 0)
	{
		std::cout << std::endl;
		return;
	}

	// Normalize k in case k is larger than the array length
	k %= len;

	// elements is an iterator pointing at the start of the array values
	std::vector<std::string>::const_iterator elements = args.begin() + 3;
	std::vector<std::string>::const_iterator it = elements + (len - k);

	// Step 1: print the last 'k' elements (they rotate to the front)
	for (;it != elements + len; ++it)
		std::cout << *it << " ";
	// Step 2: print the remaining head elements
	it = elements;
	for (;it != elements + (len - k); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 3)
		std::cout << std::endl;
  else
  {
	  std::vector<std::string> args(argv, argv + argc);
	  ft_twist_sequence(args);
  }
	return 0;
}