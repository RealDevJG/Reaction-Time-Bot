#include <windows.h>
#include <thread>
#include <chrono>

auto watch = true;
auto mouseX = 1000,
     mouseY = 300;

void watch_screen()
{
  while (watch)
  {
    HDC dc = GetDC(nullptr);
    COLORREF colour = GetPixel(dc, mouseX, mouseY);

    if (colour == RGB(30, 151, 80))
    {
      mouse_event(MOUSEEVENTF_LEFTDOWN, mouseX, mouseY, 0, 0);
      mouse_event(MOUSEEVENTF_LEFTDOWN, mouseX, mouseY, 0, 0);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    ReleaseDC(nullptr, dc);
  }
}

int main()
{
  watch_screen();
  return 0;
}
