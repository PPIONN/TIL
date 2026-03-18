#include <iostream>
#include <string>
#include "inventory.h"
using namespace std;



void main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();

	delete itemInventory;


}
///
//- `T* pItems_`: 아이템 객체들을 저장할 * *동적 배열을 가리키는 포인터 * *입니다.
//- `new T[]`를 통해 메모리를 할당받습니다.
//- `int capacity_`: 인벤토리가 최대로 저장할 수 있는 공간의 크기입니다.
//- `int size_`: 현재 인벤토리에 저장된 아이템의 실제 개수입니다.