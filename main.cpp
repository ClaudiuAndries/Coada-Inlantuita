#include <iostream>
#include "Header.hpp"
#include <queue>
//Queue<short int> front;
claudiu::Queue<short int> front;
std::queue<short int> coada;

int main()
{
	coada.push(12);

	front.Push(12);
	front.Push(21);
	front.Push(31);

	front.Front();

	front.Pop();
	front.Pop();
	front.Pop();
	front.Pop();
	front.Pop();

	front.Push(1,2, 3, 4 , 5);
	front.Pop();
	front.Pop();
	front.Pop();
	front.Pop();
	front.Pop();
	front.Pop();
}