#include "SFML/Graphics.hpp"
using namespace sf;
const int R = 50;
int main(int argc, char** argv)
{
	RenderWindow window(VideoMode(640, 480), "Circle", Style::Titlebar | Style::Close | Style::Resize);
	View view = window.getDefaultView();
	CircleShape circle(R, 100);
	circle.setFillColor(Color::Red);
	
	while (window.isOpen()) {
		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::Resized:
				window.setView(sf::View(sf::FloatRect(0, 0, evnt.size.width, evnt.size.height)));
			}
		}

		Vector2f circlePosition = (Vector2f(window.getSize()) / 2.0f) - Vector2f(R, R);
		circle.setPosition(circlePosition);		
		window.clear(Color::White);		
		window.draw(circle);
		window.display();
	}
}
