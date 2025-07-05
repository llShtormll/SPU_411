#include"String.h"

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS
#define ISTREAM_OPERATOR
//#define PERFORMANCE_TEST
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "RU");

#ifdef CONSTRUCTORS_CHECK
	String str1(5);	//explicit-конструктор нельзя вызвать оператором '=', но всегда можно вызвать при помощи круглых скобок
	str1.info();
	cout << str1 << endl;

	String str2 = "Hello";
	str2 = str2;
	cout << str2 << endl;

	String str3 = str2;		//CopyConstructor
	cout << str3 << endl;

	String str4;
	str4 = str3;
	cout << str4 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;
	String str4 = str3;
	cout << delimiter << endl;
	cout << str4 << endl;
	//MoveSemantic
#endif // OPERATOR_PLUS

#ifdef ISTREAM_OPERATOR
	String str;
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	//cin >> str;
	//cin.getline(str.get_str(), str.get_size());
	getline(cin, str);
	SetConsoleCP(866);
	cout << str << endl;
#endif // ISTREAM_OPERATOR


#ifdef CALLING_CONSTRUCTORS
	String str1;		//Default constructor
	str1.info();

	String str2(8);		//Single-argument constructor ('int') 8 - размер строки в Байтах;
	str2.info();

	String str3 = "Hello";	//Single-argumentconstructor ('const char*');
	str3.info();

	cout << typeid("Hello").name() << endl;

	String str4();// пустые круглые скобки не делают явный вызов конструктора, работает как объявление функции 
	//Если нужно явно вызвать конструктор нужны {} скобки
	String str5(8);	//Создается строка 8 байт
	String str6{ 8 };//Создается строка 8 байт, т.е. ,{} вызывает конструктор
	String str7{};  //явный вызов конструктора
	//!!!!!!!!!!!!!!  {} СЛЕДУЕТ ИСПОЛЬЗОВАТЬ С ОСТОРОЖНОСТЬЮ  !!!!!!!!!!!!

	String str9 = str3; // Колструктор копирования
	str9.info();

#endif // CALLING_CONSTRUCTORS

}


/*
---------------------------------
C++11 MoveSemantic:    
MoveConstructor - Конструктор переноса;
MoveAssignment  - Переносящий оператор присваивания;
Move-методы принимают r-value reference: Class&&
CopyConstructor,CopyAssignment - DeepCopy		(Побитовое копирование);
MoveConstrcutor,MoveAssignment - ShallowCopy	(Поверхностное копирование);
---------------------------------
*/