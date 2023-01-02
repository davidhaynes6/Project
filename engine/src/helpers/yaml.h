#pragma once
#include "math/vec2.h"
#include "yaml-cpp/yaml.h"

namespace YAML {
    template <>
    struct convert<project::vec2f> {
        PROJECT_INLINE static Node encode(const project::vec2f &rhs) {
            Node node;
            node.push_back(rhs.x);
            node.push_back(rhs.y);
            node.SetStyle(EmitterStyle::Flow);
            return node;
        }

        PROJECT_INLINE static bool decode(const Node &node, project::vec2f &rhs) {
            if (!node.IsSequence() || node.size() != 2) {
                return false;
            }
            rhs.x = node[0].as<float>();
            rhs.y = node[1].as<float>();
            return true;
        }
    };

    // stream operator
    PROJECT_INLINE Emitter &operator<<(Emitter &emitter, const project::vec2f &v) {
        emitter << Flow;
        emitter << BeginSeq << v.x << v.y << EndSeq;
        return emitter;
    }
}