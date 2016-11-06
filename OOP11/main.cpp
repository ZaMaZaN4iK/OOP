#include <windows.h> // заголовочный файл, содержащий WINAPI
#include <vector>

std::vector<HWND> vec;

// Прототип функции обработки сообщений с пользовательским названием:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = "Какой то-текст!"; // строка с сообщением
int count = 1;
										  // Управляющая функция:
int WINAPI WinMain(HINSTANCE hInst, // дескриптор экземпляра приложения
	HINSTANCE hPrevInst, // не используем
	LPSTR lpCmdLine, // не используем
	int nCmdShow) // режим отображения окошка
{
	TCHAR szClassName[] = "Мой класс"; // строка с именем класса
	HWND hMainWnd; // создаём дескриптор будущего окошка
	MSG msg; // создём экземпляр структуры MSG для обработки сообщений
	WNDCLASSEX wc; // создаём экземпляр, для обращения к членам класса WNDCLASSEX
	wc.cbSize = sizeof(wc); // размер структуры (в байтах)
	wc.style = CS_HREDRAW | CS_VREDRAW; // стиль класса окошка
	wc.lpfnWndProc = WndProc; // указатель на пользовательскую функцию
	wc.lpszMenuName = NULL; // указатель на имя меню (у нас его нет)
	wc.lpszClassName = szClassName; // указатель на имя класса
	wc.cbWndExtra = NULL; // число освобождаемых байтов в конце структуры
	wc.cbClsExtra = NULL; // число освобождаемых байтов при создании экземпляра приложения
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // декриптор пиктограммы
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); // дескриптор маленькой пиктограммы (в трэе)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // дескриптор курсора
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // дескриптор кисти для закраски фона окна
	wc.hInstance = hInst; // указатель на строку, содержащую имя меню, применяемого для класса
	if (!RegisterClassEx(&wc)) {
		// в случае отсутствия регистрации класса:
		MessageBox(NULL, "Не получилось зарегистрировать класс!", "Ошибка", MB_OK);
		return NULL; // возвращаем, следовательно, выходим из WinMain
	}
	// Функция, создающая окошко:
	hMainWnd = CreateWindow(
		szClassName, // имя класса
		"Полноценная оконная процедура", // имя окошка (то что сверху)
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, // режимы отображения окошка
		CW_USEDEFAULT, // позиция окошка по оси х
		NULL, // позиция окошка по оси у (раз дефолт в х, то писать не нужно)
		CW_USEDEFAULT, // ширина окошка
		NULL, // высота окошка (раз дефолт в ширине, то писать не нужно)
		(HWND)NULL, // дескриптор родительского окна
		NULL, // дескриптор меню
		HINSTANCE(hInst), // дескриптор экземпляра приложения
		NULL); // ничего не передаём из WndProc
	vec.push_back(hMainWnd);
	if (!hMainWnd) {
		// в случае некорректного создания окошка (неверные параметры и тп):
		MessageBox(NULL, "Не получилось создать окно!", "Ошибка", MB_OK);
		return NULL;
	}
	ShowWindow(hMainWnd, nCmdShow); // отображаем окошко
	UpdateWindow(hMainWnd); // обновляем окошко
	while (GetMessage(&msg, NULL, NULL, NULL)) { // извлекаем сообщения из очереди, посылаемые фу-циями, ОС
		TranslateMessage(&msg); // интерпретируем сообщения
		DispatchMessage(&msg); // передаём сообщения обратно ОС
	}
	return msg.wParam; // возвращаем код выхода из приложения
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC; // создаём дескриптор ориентации текста на экране
	PAINTSTRUCT ps; // структура, сод-щая информацию о клиентской области (размеры, цвет и тп)
	RECT rect; // стр-ра, определяющая размер клиентской области
	COLORREF colorText = RGB(255, 0, 0); // задаём цвет текста
	switch (uMsg) {
	case WM_LBUTTONDOWN:
		SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)"tratatat");
		if (count < 5)
		{
			HWND handle; 
			handle = CreateWindow(
				"Мой класс", // имя класса
				"Полноценная оконная процедура", // имя окошка (то что сверху)
				WS_OVERLAPPEDWINDOW | WS_VSCROLL, // режимы отображения окошка
				CW_USEDEFAULT, // позиция окошка по оси х
				NULL, // позиция окошка по оси у (раз дефолт в х, то писать не нужно)
				CW_USEDEFAULT, // ширина окошка
				NULL, // высота окошка (раз дефолт в ширине, то писать не нужно)
				vec[count - 1], // дескриптор родительского окна
				NULL, // дескриптор меню
				NULL, // дескриптор экземпляра приложения
				NULL); // ничего не передаём из WndProc
			ShowWindow(handle, SW_SHOWDEFAULT); // отображаем окошко
			UpdateWindow(handle); // обновляем окошко

			vec.push_back(handle);

			++count;
		}
		break;
	case WM_KEYDOWN:
	case WM_CLOSE:
		MessageBox(NULL, "azazaz", "azazazazazazza", MB_OKCANCEL | MB_DEFBUTTON1);
		DestroyWindow(vec.back());
		vec.pop_back();
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam); // если закрыли окошко
	}
	return NULL; // возвращаем значение
}