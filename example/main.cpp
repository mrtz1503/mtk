#include <mtk/app.h>
#include <mtk/window.h>
#include <mtk/box.h>
#include <mtk/color.h>

#include <iostream>

int main()
{
    try
    {
        mtk::app app;

        mtk::window window("mtk window");

        mtk::box a(mtk::colors::black);
        window.add(&a);

        mtk::box b(mtk::colors::gray);
        window.add(&b);

        mtk::box c(mtk::colors::white);
        window.add(&c);
        
        mtk::box d(mtk::colors::black);
        window.add(&d);


        window.show();



        app.run();
    }
    catch (const std::exception& e)
    {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}