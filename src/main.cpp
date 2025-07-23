#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include "glad/glad.h"

static const std::array<GLfloat, 6> s_vertices = {
  -0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f
};

static const std::string s_vertex_source = R"glsl(#version 450 core
in vec2 position;
void main() {
  gl_Position = vec4(position, 0.0f, 1.0f);
}
)glsl";

static const std::string s_fragment_source R"glsl(#version 450 core
out vec4 f_color;
void main() {
  f_color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
)glsl";

int main() {
  sf::ContextSettings settings;
  settings.majorVersion = 4;
  settings.minorVersion = 5;

  sf::Window window{
    sf::VideoMode{{800, 600}},
    "Flora",
    sf::Style::Default,
    sf::State::Windowed,
    settings,
  };

  window.setFramerateLimit(60);

  // Set up vertex data
  GLuint va;
  glGenVertexArrays(1, &va);
  glBindVertexArray(va);

  GLuint vb;
  glGenBuffers(1, &vb);
  glBindBuffer(GL_ARRAY_BUFFER, vb);
  glBufferData(
    GL_ARRAY_BUFFER,
    s_vertices.size() * sizeof(decltype(s_vertices)::value_type),
    s_vertices.data(),
    GL_STATIC_DRAW
  );

  // Set up buffer layout
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
  glEnableVertexAttribArray(0);

  // Set up shaders

  bool window_is_open = true;
  while (window_is_open) {
    while (std::optional<sf::Event> event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window_is_open = false;
      }
    }

    glClear(GL_COLOR_BUFFER_BIT);
    window.display();
  }
}
