#include <core/entry.h>

project::app_config project::create_application() {
    project::app_config config;
    config.scene = "assets/scene.yaml";
    config.version = "0.0.1";
    config.title = "Flappy Plane";
    config.height = 720;
    config.width = 320;
    return config;
}