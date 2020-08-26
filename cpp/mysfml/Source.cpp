#include <SFML/Graphics.hpp>

int main(void) {
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Hello sfml");
	while (true) {
		renderWindow.clear();
		renderWindow.display();
	}
}