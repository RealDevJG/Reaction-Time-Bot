#include <windows.h>
#include <thread>
#include <chrono>

auto watch = true;
auto mouseX = 1000, // these are coordinites that the code loops at to find the green pixels.
     mouseY = 300;  // to find them relative to your computer take a print screen of all your monitors and put it into paint
                    // once put into paint you can see where the green pixels will appear and copy the coordinites down to these variables
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
