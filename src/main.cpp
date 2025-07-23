#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

int main() {
  sf::ContextSettings settings;
  settings.majorVersion = 3;
  settings.minorVersion = 3;

  sf::Window window{sf::VideoMode{{800, 600}}, "Flora", sf::Style::Default,
                    sf::State::Windowed, settings};

  window.setFramerateLimit(60);

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
