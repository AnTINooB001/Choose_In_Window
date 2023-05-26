#include "Header.h"

//Создаём прототип функции окна
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

LPCWSTR szIconName = L"MYICON"; //имя иконки
LPCWSTR szProgName = L"Progname"; //имя программы
LPCWSTR szText = L"Поздравляю, теперь вы умеете работать с мышью!";

int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
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
	w.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //цвет фона окна
	w.style = CS_HREDRAW | CS_VREDRAW; //стиль - перерисовываемое по х и по у
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	//Если не удалось зарегистрировать класс окна - выходим
	if (!RegisterClass(&w))
		return 0;

	//Создадим окно в памяти, заполнив аргументы CreateWindow
	hWnd = CreateWindow(szProgName, //Имя программы
		L"ТЫ ГЕЙ?", //Заголовок окна
		WS_OVERLAPPEDWINDOW, //Стиль окна - перекрывающееся
		600, //положение окна на экране по х
		300, //по у
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
	int xPosCur;
	int yPosCur;

	//Цикл обработки сообщений
	switch (messg)
	{
	
	case WM_MOUSEMOVE:

		RECT rc;
		
		GetWindowRect(ButtonWnd, &rc);

		xPosCur = LOWORD(lParam); //узнаём координаты
		yPosCur = HIWORD(lParam);
		
		//showCursCoordinates(xPosCur, yPosCur);

		WndP1 = Convert(hWnd, rc.left, rc.top);
		WndP2 = Convert(hWnd, rc.right, rc.bottom);

		//ShowWndPos(WndP2);
		
		if (!((yPosCur <= WndP1.y && xPosCur <= WndP1.x)|| (yPosCur >= WndP2.y && xPosCur >= WndP2.x)))
		{
			
			SetWindowTextA(ButtonWnd, "НЕТ");
			SetWindowPos(ButtonWnd, NULL, std::rand() % 300, std::rand() % 250, 40, 40, NULL);
		};	
		
		break;

		case WM_CREATE:
		{
			AddWndVidget(hWnd);
		}
			break;
		case WM_COMMAND:
		{

			switch (wParam)
			{

			case OnYes:
				MessageBoxA(hWnd, "ХЕ ХЕ ", "Я ТОЖЕ", MB_OK);

			}

		}
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
	
	editText = CreateWindowA("static", " ", WS_VISIBLE | WS_CHILD, 1100, 110, 100, 30, hWnd, NULL, NULL, NULL);
	editText2 = CreateWindowA("static", " ", WS_VISIBLE | WS_CHILD, 1500, 110, 100, 30, hWnd, NULL, NULL, NULL);
	ButtonWnd = CreateWindowA("button", "НЕТ", WS_VISIBLE | WS_CHILD, 10, 10, 40, 40, hWnd, NULL, NULL, NULL);
	WndText = CreateWindowA("static", " ", WS_VISIBLE | WS_CHILD, 2100, 210, 100, 30, hWnd, NULL, NULL, NULL);
	WndText2 = CreateWindowA("static", " ", WS_VISIBLE | WS_CHILD, 2500, 210, 100, 30, hWnd, NULL, NULL, NULL);
	YesButt = CreateWindowA("button", "ДА", WS_VISIBLE | WS_CHILD , 230, 125, 40, 40, hWnd, (HMENU)OnYes, NULL, NULL);
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

void showCursCoordinates(int xPosCur, int yPosCur)
{
	Curstr = std::to_string(xPosCur);
	Curstr = addXToString(Curstr);
	Curstr1 = convertStringToLPCSTR(Curstr);
	SetWindowTextA(editText, Curstr1);
	Curstr = std::to_string(yPosCur);
	Curstr = addYToString(Curstr);
	Curstr1 = convertStringToLPCSTR(Curstr);
	SetWindowTextA(editText2, Curstr1);

	if (!(xPosCur > 999 || yPosCur > 999))
	{
		SetWindowPos(editText, NULL, xPosCur + 13, yPosCur + 13, 40, 20, NULL);
		SetWindowPos(editText2, NULL, xPosCur + 53, yPosCur + 13, 40, 20, NULL);
	}
	else
	{
		SetWindowPos(editText, NULL, xPosCur + 13, yPosCur + 13, 50, 20, NULL);
		SetWindowPos(editText2, NULL, xPosCur + 63, yPosCur + 13, 45, 20, NULL);
	}
	
}

POINT Convert( HWND w, LONG& x, LONG& y)
{
	POINT tmp;
	tmp.x = x; tmp.y = y;
	ScreenToClient(w, &tmp);
	x = tmp.x; y = tmp.y;
	return tmp;

}


void ShowWndPos(POINT p)
{
	str = std::to_string(p.x);
	str = addXToString(str);
	str1 = convertStringToLPCSTR(str);
	SetWindowTextA(WndText, str1);
	str = std::to_string(p.y);
	str = addYToString(str);
	str1 = convertStringToLPCSTR(str);
	SetWindowTextA(WndText2, str1);

	SetWindowPos(WndText, NULL, p.x + 13, p.y + 13, 40, 20, NULL);
	SetWindowPos(WndText2, NULL, p.x + 53, p.y + 13, 40, 20, NULL);
}
