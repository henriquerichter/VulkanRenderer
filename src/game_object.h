#pragma once

#include "model.h"

#include "glm/gtc/matrix_transform.hpp"

#include <memory>

struct TransformComponent {
    glm::vec3 translation{};
    glm::vec3 scale{1.0f, 1.0f, 1.0f};
    glm::vec3 rotation{};

    //y(1), x(2), z(3)
    // https://en.wikipedia.org/wiki/Euler_angles#Rotation_matrix
    glm::mat4 mat4();

    glm::mat3 normalMatrix();
};

class GameObject {
  public:
    GameObject(const GameObject &) = delete;
    GameObject &operator=(const GameObject &) = delete;
    GameObject(GameObject &&) = default;
    GameObject &operator=(GameObject &&) = default;

    using id_t = unsigned int;

    std::shared_ptr<Model> model{};
    glm::vec3 color{};
    TransformComponent transform{};

    static GameObject createGameObject() {
        static id_t currentId = 0;
        return GameObject{currentId++};
    }

    id_t getId() {
        return id;
    }

  private:
    GameObject(id_t objId) : id(objId) {}

    id_t id;
};
