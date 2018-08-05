#include "DxLib.h"

constexpr int start_x = 200;
constexpr int start_x2 = 600;
constexpr int start_y = 200;
constexpr int default_size = 10;

inline int DrawBone(const int x, const int y, const int w, const int h,const unsigned int c)
{
	return DrawBox(start_x + x * default_size, start_y + y * default_size, start_x + (x + w) * default_size, start_y + (y + h) * default_size, c, TRUE);
}

inline int DrawBone2(const int x, const int y, const int w, const int h, const unsigned int c)
{
	return DrawBox(start_x2 + x * default_size, start_y + y * default_size, start_x2 + (x + w) * default_size, start_y + (y + h) * default_size, c, TRUE);
}

inline int DrawPoint(const int x, const int y, const unsigned int c)
{
	return DrawCircle(start_x + x * default_size, start_y + y * default_size, default_size, c, TRUE);
}

inline int DrawPoint2(const int x, const int y, const unsigned int c)
{
	return DrawCircle(start_x2 + x * default_size, start_y + y * default_size, default_size, c, TRUE);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(960, 960, 32);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	while (CheckHitKeyAll() == 0 && ProcessMessage() == 0 && ScreenFlip() == 0)
	{
		DrawBone(-5, 8, 2, 8, GetColor(100, 100, 255));
		DrawBone(3, 8, 2, 8, GetColor(255, 100, 100));

		DrawBone(-4, 16, 8, 8, GetColor(255, 255, 255));
		DrawBone(-4, 3, 8, 8, GetColor(200, 200, 255));
		DrawBone(-3, 9, 6, 7, GetColor(200, 200, 200));

		DrawBone(-3,0, 3, 9, GetColor(200, 255, 255));
		DrawBone(0, 0, 3, 9, GetColor(200, 255, 200));
		


		DrawPoint(0, 18, GetColor(255, 0, 0));
		DrawPoint(-1, 9, GetColor(255, 0, 0));
		DrawPoint(1, 9, GetColor(255, 0, 0));

		DrawPoint(-4, 15, GetColor(255, 0, 0));
		DrawPoint(4, 15, GetColor(255, 0, 0));

		DrawBone2(-4, 6, 8, 12, GetColor(200, 255, 255));
		DrawBone2(-4, 16, 8, 8, GetColor(255, 255, 255));
		DrawBone2(-4, 0, 4, 6, GetColor(200, 200, 255));
		DrawBone2(0, 0, 4, 6, GetColor(200, 255, 200));
		DrawPoint2(0, 18, GetColor(255,0,0));
		DrawPoint2(-2, 6, GetColor(255, 0, 0));
		DrawPoint2(2, 6, GetColor(255, 0, 0));

	}

	DxLib_End();

	return 0;
}