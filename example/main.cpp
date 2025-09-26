#include <mtk/app.h>
#include <mtk/window.h>
#include <mtk/box.h>

#include <iostream>

int main()
{
    try
    {
        mtk::app app;

        mtk::window window("mtk window");
        window.show();

        mtk::box b;

        window.add(&b);





        app.run();
    }
    catch (const std::exception& e)
    {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}