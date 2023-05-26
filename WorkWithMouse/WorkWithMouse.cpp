#include "Header.h"

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
		HDC hDC;
		hDC = GetDC(hWnd);
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
		str = std::to_string(xPosCur);
		str = addXToString(str);
		str1 = convertStringToLPCSTR(str);
		SetWindowTextA(editText, str1);
		str = std::to_string(yPosCur);
		str = addYToString(str);
		str1 = convertStringToLPCSTR(str);
		SetWindowTextA(editText2, str1);
		//cxScreen = GetSystemMetrics(SM_CXSCREEN); размеры экрана
		//cyScreen = GetSystemMetrics(SM_CYSCREEN);
		if (xPosCur > rc.left && xPosCur < rc.right )
		{
			//addWindow();
			SetWindowTextA(ButtonWnd, "ddd");
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
	
	editText = CreateWindowA("static", " ", WS_VISIBLE | WS_CHILD, 110, 110, 100, 30, hWnd, NULL, NULL, NULL);
	editText2 = CreateWindowA("static", " ", WS_VISIBLE | WS_CHILD, 150, 110, 100, 30, hWnd, NULL, NULL, NULL);
	ButtonWnd = CreateWindowA("static", "click me", WS_VISIBLE | WS_CHILD, 10, 10, 100, 100, hWnd, (HMENU)OnButton, NULL, NULL);
}
void addWindow()
{
	HWND hWnd2;
	
	hWnd2 = CreateWindow(szProgName, L"ERROR", WS_VISIBLE | WS_OVERLAPPED, std::rand() % 200, std::rand() % 100, 400, 400, NULL, NULL, NULL, NULL);
	
}

LPCSTR convertStringToLPCSTR(std::string str)
{
	int size = str.size();
	char* baffer = new char[100];
	
	for (int i = 0; i < str.size(); i++)
	{
		baffer[i] = str[i];
	}
	baffer[str.size()] = '\0';
	
	return baffer;
	delete[] baffer;
}

std::string addXToString(std::string str)
{
	str.resize(str.size() + 1);
	str[str.size()-1] = 'X';
	str[str.size()] = '\0';
	return str;
}

std::string addYToString(std::string str)
{
	str.resize(str.size() + 1);
	str[str.size() - 1] = 'Y';
	str[str.size()] = '\0';
	return str;
}