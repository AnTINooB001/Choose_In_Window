#include "windows.h"
#include <iostream>

POINT p;
INPUT m;


#define OnButton 1
int i = 0;
void AddWndVidget(HWND hWnd);
HWND editText;
HWND ButtonWnd;
//#define WM_NCMOUSEMOVE 
void addWindow(HWND hWnd);
//Создаём прототип функции окна
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

LPCWSTR szIconName = L"MYICON"; //имя иконки
LPCWSTR szProgName = L"Progname"; //имя программы
LPCWSTR szText = L"Поздравляю, теперь вы умеете работать с мышью!";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	HWND hWnd; //идентификатор окна
	MSG lpMsg; //идентификатор сообщения
	WNDCLASS w; //создаём экземпляр структуры WNDCLASS
	HWND hwnd;

	//И начинаем её заполнять
	w.lpszClassName = szProgName; //имя программы - объявлено выше
	w.hInstance = hInstance; //идентификатор текущего приложения
	w.lpfnWndProc = WndProc; //указатель на функцию окна
	w.hCursor = LoadCursor(NULL, IDC_ARROW); //загружаем курсор
	w.hIcon = LoadIcon(hInstance, szIconName); //загружаем нашу иконку
	w.lpszMenuName = 0; //меню пока не будет
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //цвет фона окна
	w.style = CS_HREDRAW | CS_VREDRAW; //стиль - перерисовываемое по х и по у
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	//Если не удалось зарегистрировать класс окна - выходим
	if (!RegisterClass(&w))
		return 0;

	//Создадим окно в памяти, заполнив аргументы CreateWindow
	hWnd = CreateWindow(szProgName, //Имя программы
		L"Моя первая программа!", //Заголовок окна
		WS_OVERLAPPEDWINDOW, //Стиль окна - перекрывающееся
		100, //положение окна на экране по х
		100, //по у
		500, //размеры по х
		400, //по у
		(HWND)NULL, //идентификатор родительского окна
		(HMENU)NULL, //идентификатор меню
		(HINSTANCE)hInstance, //идентификатор экземпляра программы
		(HINSTANCE)NULL); //отсутствие дополнительных параметров


	//Выводим окно из памяти на экран

	ShowWindow(hWnd, nCmdShow);

	//Обновим содержимое окна
	UpdateWindow(hWnd);


	//Цикл обработки сообщений

	

	while (GetMessage(&lpMsg, NULL, 0, 0)) { //Получаем сообщение из очереди
		TranslateMessage(&lpMsg); //Преобразует сообщения клавиш в символы
		DispatchMessage(&lpMsg); //Передаёт сообщение соответствующей функции окна
	}
	return(lpMsg.wParam);
}

//Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc; //создаём контекст устройства
	PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода

	//Цикл обработки сообщений
	switch (messg)
	{
	case WM_COMMAND:
	{
		
		switch (wParam)
		{
			
		//case OnButton:
		//	
		//	//addWindow(hWnd);
		//	
		//	while (i != 1000)
		//	{
		//		
		//		addWindow(hWnd);
		//		i++;
		//	}
			break;
	
		
		break;

		default:
			break;
		}
		break;
	}
	int xPosCur;
	int yPosCur;
	int cxScreen;
	int cyScreen;
	int a, b;
	case WM_MOUSEMOVE:

		RECT rc;
		
		WINDOWPLACEMENT wpls;

		//m.type = INPUT_MOUSE;
		//m.mi.dwFlags = MOUSEEVENTF_MOVE;
		//m.mi.dx = p.x;
		//m.mi.dy = p.y;
		
		GetWindowRect(ButtonWnd, &rc);

		POINT mousePoint;

		GetCursorPos(&mousePoint);
		GetWindowPlacement(ButtonWnd, &wpls);

		xPosCur = LOWORD(lParam); //узнаём координаты
		yPosCur = HIWORD(lParam);
		
		//cxScreen = GetSystemMetrics(SM_CXSCREEN); размеры экрана
		//cyScreen = GetSystemMetrics(SM_CYSCREEN);
		if ((xPosCur > rc.left && yPosCur < rc.top) && (xPosCur < rc.right && yPosCur > rc.bottom))
		{
			addWindow(hWnd);
			SetWindowTextA(editText, "ddd");
		}
		
	
		break;
	//	int x, y; //координаты

	//	//Если был щелчок левой или правой кнопкой
	//case WM_RBUTTONDOWN:
	//case WM_LBUTTONDOWN:
	//	char* str;
	//	HDC hDC;
	//	
	//	hDC = GetDC(hWnd);
	//	x = LOWORD(lParam); //узнаём координаты
	//	y = HIWORD(lParam);
	//	
	//	

	//	TextOut(hDC, x, y, szText , strlen("Поздравляю, теперь вы умеете работать с мышью!"));
	//	
	//	/*int X, Y;
	//	X = LOWORD(lParam);
	//	Y = HIWORD(lParam);
	//	SetWindowTextA(editText, (LPCSTR)X);*/
	//	break;
		case WM_CREATE:
			
			AddWndVidget(hWnd);
			
			break;
		//сообщение выхода - разрушение окна
	case WM_DESTROY:
		PostQuitMessage(0); //Посылаем сообщение выхода с кодом 0 - нормальное завершение
		break;

	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam)); //освобождаем очередь приложения от нераспознаных
	}
	return 0;
}

void AddWndVidget(HWND hWnd)
{
	
	editText = CreateWindowA("edit", "fffffffffffffffffffff", WS_VISIBLE | WS_CHILD, 110, 110, 100, 30, hWnd, NULL, NULL, NULL);
	ButtonWnd = CreateWindowA("button", "click me", WS_VISIBLE | WS_CHILD, 10, 10, 100, 100, hWnd, (HMENU)OnButton, NULL, NULL);
}
void addWindow(HWND hWnd)
{
	HWND hWnd2;
	
	hWnd2 = CreateWindow(szProgName, L"ERROR", WS_VISIBLE | WS_OVERLAPPED, std::rand() % 2000, std::rand() % 1000, 100, 100, hWnd, NULL, NULL, NULL);
	
}