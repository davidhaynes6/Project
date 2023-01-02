#include <core/entry.h>

project::app_config project::create_application() {
    project::app_config config;
    config.scene = "assets/scene.yaml";
    config.title = "Flappy Plane";
    config.version = "0.0.1";
    config.width = 380;
    config.height = 720;
    return config;
}