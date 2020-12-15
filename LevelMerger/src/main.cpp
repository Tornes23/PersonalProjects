#include "System/System.hpp"

int main(int argc, const char *argv[])
{
    auto &system = System::instance();

    system.create(1280, 720, "LevelMerger", false);

    auto &window = system.window();

    while (window.update())
    {
        }

    return 0;
}