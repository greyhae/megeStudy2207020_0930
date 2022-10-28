#include <iostream>
#include <list>

using namespace std;

class Object
{
public:
	int Kor;
	int Eng;
	int Math;

	int Mean;
};

Object* CreateObject(int _kor, int _eng, int _math);
// 함수 정의할때 형태만 사용해도 됨
//Object* CreaObject(int, int, int);

bool Compare(Object*, Object*);

int main(void)
{
	list<Object*> Objects;

	Objects.push_back(CreateObject(20, 21, 22));
	Objects.push_back(CreateObject(30, 31, 32));
	Objects.push_back(CreateObject(40, 41, 42));
	Objects.push_back(CreateObject(50, 51, 52));

	Objects.push_front(CreateObject(10, 11, 12));

	for (list<Object*>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter)
	{
		cout << (*iter)->Kor << endl;
		cout << (*iter)->Eng << endl;
		cout << (*iter)->Math << endl << endl;
	}

	cout << endl << Objects.back()->Kor << endl;
	cout << Objects.back()->Eng << endl;
	cout << Objects.back()->Math << endl << endl;

	cout << "size : " << Objects.size() << endl << endl;

	// ** 가장 마지막에 있는 원소를 삭제
	Objects.pop_back();

	// ** 가장 첫번째에 있는 원소를 삭제
	Objects.pop_front();

	{
		/*
		// ** 해당 원소 찾기
		Object* pNode = nullptr; // list
		//int index = 0; // vector

		for (list<Object*>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter)
		{
			if ((*iter)->Mean > 30 && (*iter)->Mean < 40)
			{
				//index = i;
				pNode = (*iter);
			}
		}

		cout << endl << "Node : " << pNode->Kor << endl;
		cout << "Node : " << pNode->Eng << endl;
		cout << "Node : " << pNode->Math << endl << endl;
		*/
	}


	list<Object*>::iterator iter = Objects.begin();
	iter++;
	iter++;
	iter++;

	Objects.insert(iter, CreateObject(60, 61, 62));

	Objects.sort(Compare);

	cout << "[insert]" << endl;
	for (list<Object*>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter)
	{
		cout << (*iter)->Kor << endl;
		cout << (*iter)->Eng << endl;
		cout << (*iter)->Math << endl << endl;

		delete (*iter);
		(*iter) = nullptr;
	}


	Objects.clear();

	if (Objects.empty())
		cout << "Objects 없음" << endl;


	/*
	Objects.push_back();
	Objects.push_front();

	Objects.begin();
	Objects.end();

	Objects.front();
	Objects.back();

	Objects.empty();
	Objects.clear();
	Objects.insert();

	Objects.size();
	Objects.sort();
	*/


	return 0;
}

Object* CreateObject(int _kor, int _eng, int _math)
{
	Object* pObj = new Object;

	pObj->Kor = _kor;
	pObj->Eng = _eng;
	pObj->Math = _math;


	pObj->Mean = (pObj->Kor + pObj->Eng + pObj->Math)/3;
	return pObj;
}

bool Compare(Object* _temp, Object* _dest)
{
	// < : 오름차순
	// > : 내림차순
	return _temp->Mean < _dest->Mean;
}