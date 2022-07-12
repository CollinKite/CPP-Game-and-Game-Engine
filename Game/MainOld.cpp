//#include "Math\MathUtils.h" //Include your code before including other libraries
//#include "Core\Memory.h" //header file to check for mem leak
//#include <iostream>
//
//
////#include <stdio.h> c version of iostream
//
//using namespace std;
//
//template <typename T>
//class smart_ptr
//{
//public:
//	smart_ptr(T* ptr) : ptr{ ptr } {} //constructor
//	~smart_ptr() { delete ptr; } //destructor
//
//private:
//	T* ptr;
//};
//
//int notmain()
//{
//	crae::initializeMemory(); //Calls debug function for mem leak
//	cout << "c++ Hello World\n";
//
//	//int* ipp = new int[5];
//	//ipp[0] = 1;
//	//ipp[1] = 2;
//	//ipp[2] = 3;
//	//ipp[3] = 4;
//	//ipp[4] = 5;
//	//cout << ipp[0] << endl;
//	//cout << *ipp << endl;
//	//cout << ipp << endl;
//	//cout << *(ipp + 2) << endl;
//	//ipp++; //increments by datatype bytes (4) [1]
//	//ipp++; //[2]
//	//cout << *ipp << endl;
//	//ipp--;
//	//ipp--;
//	//delete[] ipp;// you have to move back to the base address before deletion
//
//	//cout << Math::sqr(9) << endl;
//	//cout << Math::half(30) << endl; //inline just does code substitution instead of calling the function in memory
//
//	//C memory allocation, can get messy
//	void* vp = malloc(sizeof(double)); //void ptr int float
//	int* ip = (int*)vp; //update saying it points to a int ptr
//	*ip = 23;
//	cout << *ip << endl;
//	free(vp);
//
//
//	//modern c++ this is a smart ptr that auto deletes it self
//	//scope is "{}" when the you go out of scope ptr auto deletes it self
//	{
//		//smart_ptr<int> sp(new int(32)); //created on heap for int
//
//		//one owner
//	unique_ptr<float> uf = make_unique<float>(12.5f); //creates float on heap new float(12.5f)
//		cout << *uf << endl; //value
//		unique_ptr<float> uf2 = move(uf); //change ownership of uf, and uf2 owns it and uf no longer exists
//
//		//multiple owners
//		shared_ptr<float> sp = make_shared<float>(3.7f);
//		cout << "use: " << sp.use_count() << endl; // 1 owner of the ptr
//		{
//			shared_ptr<float> sp2 = sp; //Both sp, and sp2 own ptr
//			cout << "use: " << sp.use_count() << endl; //2 owners of the ptr
//		}
//		cout << "use: " << sp.use_count() << endl; //we went out of scope so sp2 is deleted and there is only 1 owner again
//		cout << *sp << endl;
//		//cout << *sp2 << endl;
//	}
//
//
//
//	int* p = new int(10); //allocates on heap
//	*p = 20;
//	cout << p << endl;
//	cout << *p << endl;
//	delete p;
//
//	int i = 5; //allocates on heap
//}