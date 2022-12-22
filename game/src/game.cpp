#include <core/entry.h>

project::app_config project::create_application() {
    project::app_config config;
    config.version = "0.0.1";
    config.title = "Project2D";
    config.height = 1080;
    config.width = 720;
    return config;
}