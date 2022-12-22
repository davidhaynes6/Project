#pragma
#include "application.h"

extern project::app_config project::create_application();

int main(int argc, char** argv)
{
    auto config = project::create_application();
    project::run_application(config);
    return 0;
}