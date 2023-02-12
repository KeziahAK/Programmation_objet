#include <stdlib.h>
#include "p6/p6.h"
#include <vector>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"

int main(int argc, char* argv[])
{
    { // Run the tests
        if (doctest::Context{}.run() != 0)
            return EXIT_FAILURE;
        // The CI does not have a GPU so it cannot run the rest of the code.
        const bool no_gpu_available = argc >= 2 && strcmp(argv[1], "-nogpu") == 0; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
        if (no_gpu_available)
            return EXIT_SUCCESS;
    }

    // Actual app
    auto ctx = p6::Context{{.title = "Projet_prog"}};
    ctx.maximize_window();

    // Declare your infinite update loop.
    ctx.update = [&]() {
        //ctx.background(p6::NamedColor::Blue);//Afficher la couleur du background
        //ctx.background({0.2f,0.1f,0.3f});//Nouvelle couleur de background
        // Clear the background with a fading effect
        ctx.use_stroke = false;
        ctx.fill       = {0.2f, 0.1f, 0.3f, 0.1f};
        ctx.rectangle(p6::FullScreen{});
        // Draw something
        ctx.fill = {1.f, 0.7f, 0.2f};

        //Forme de notre souris
        ctx.circle(
            p6::Center{ctx.mouse()},
            p6::Radius{0.2f}
        );
    };
    

    // Should be done last. It starts the infinite loop.
    ctx.start();

    // std::vector<int> v{};
    // int sum=0;
    // for (size_t i=0; i<v.size();i++){
    //     sum +=v[i];
    // }


}