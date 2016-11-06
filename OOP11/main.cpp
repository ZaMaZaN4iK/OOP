#include <windows.h> // ������������ ����, ���������� WINAPI
#include <vector>

std::vector<HWND> vec;

// �������� ������� ��������� ��������� � ���������������� ���������:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = "����� ��-�����!"; // ������ � ����������
int count = 1;
										  // ����������� �������:
int WINAPI WinMain(HINSTANCE hInst, // ���������� ���������� ����������
	HINSTANCE hPrevInst, // �� ����������
	LPSTR lpCmdLine, // �� ����������
	int nCmdShow) // ����� ����������� ������
{
	TCHAR szClassName[] = "��� �����"; // ������ � ������ ������
	HWND hMainWnd; // ������ ���������� �������� ������
	MSG msg; // ����� ��������� ��������� MSG ��� ��������� ���������
	WNDCLASSEX wc; // ������ ���������, ��� ��������� � ������ ������ WNDCLASSEX
	wc.cbSize = sizeof(wc); // ������ ��������� (� ������)
	wc.style = CS_HREDRAW | CS_VREDRAW; // ����� ������ ������
	wc.lpfnWndProc = WndProc; // ��������� �� ���������������� �������
	wc.lpszMenuName = NULL; // ��������� �� ��� ���� (� ��� ��� ���)
	wc.lpszClassName = szClassName; // ��������� �� ��� ������
	wc.cbWndExtra = NULL; // ����� ������������� ������ � ����� ���������
	wc.cbClsExtra = NULL; // ����� ������������� ������ ��� �������� ���������� ����������
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // ��������� �����������
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); // ���������� ��������� ����������� (� ����)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // ���������� �������
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���������� ����� ��� �������� ���� ����
	wc.hInstance = hInst; // ��������� �� ������, ���������� ��� ����, ������������ ��� ������
	if (!RegisterClassEx(&wc)) {
		// � ������ ���������� ����������� ������:
		MessageBox(NULL, "�� ���������� ���������������� �����!", "������", MB_OK);
		return NULL; // ����������, �������������, ������� �� WinMain
	}
	// �������, ��������� ������:
	hMainWnd = CreateWindow(
		szClassName, // ��� ������
		"����������� ������� ���������", // ��� ������ (�� ��� ������)
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, // ������ ����������� ������
		CW_USEDEFAULT, // ������� ������ �� ��� �
		NULL, // ������� ������ �� ��� � (��� ������ � �, �� ������ �� �����)
		CW_USEDEFAULT, // ������ ������
		NULL, // ������ ������ (��� ������ � ������, �� ������ �� �����)
		(HWND)NULL, // ���������� ������������� ����
		NULL, // ���������� ����
		HINSTANCE(hInst), // ���������� ���������� ����������
		NULL); // ������ �� ������� �� WndProc
	vec.push_back(hMainWnd);
	if (!hMainWnd) {
		// � ������ ������������� �������� ������ (�������� ��������� � ��):
		MessageBox(NULL, "�� ���������� ������� ����!", "������", MB_OK);
		return NULL;
	}
	ShowWindow(hMainWnd, nCmdShow); // ���������� ������
	UpdateWindow(hMainWnd); // ��������� ������
	while (GetMessage(&msg, NULL, NULL, NULL)) { // ��������� ��������� �� �������, ���������� ��-�����, ��
		TranslateMessage(&msg); // �������������� ���������
		DispatchMessage(&msg); // ������� ��������� ������� ��
	}
	return msg.wParam; // ���������� ��� ������ �� ����������
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC; // ������ ���������� ���������� ������ �� ������
	PAINTSTRUCT ps; // ���������, ���-��� ���������� � ���������� ������� (�������, ���� � ��)
	RECT rect; // ���-��, ������������ ������ ���������� �������
	COLORREF colorText = RGB(255, 0, 0); // ����� ���� ������
	switch (uMsg) {
	case WM_LBUTTONDOWN:
		SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)"tratatat");
		if (count < 5)
		{
			HWND handle; 
			handle = CreateWindow(
				"��� �����", // ��� ������
				"����������� ������� ���������", // ��� ������ (�� ��� ������)
				WS_OVERLAPPEDWINDOW | WS_VSCROLL, // ������ ����������� ������
				CW_USEDEFAULT, // ������� ������ �� ��� �
				NULL, // ������� ������ �� ��� � (��� ������ � �, �� ������ �� �����)
				CW_USEDEFAULT, // ������ ������
				NULL, // ������ ������ (��� ������ � ������, �� ������ �� �����)
				vec[count - 1], // ���������� ������������� ����
				NULL, // ���������� ����
				NULL, // ���������� ���������� ����������
				NULL); // ������ �� ������� �� WndProc
			ShowWindow(handle, SW_SHOWDEFAULT); // ���������� ������
			UpdateWindow(handle); // ��������� ������

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
		return DefWindowProc(hWnd, uMsg, wParam, lParam); // ���� ������� ������
	}
	return NULL; // ���������� ��������
}