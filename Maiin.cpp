#include <SFML/Graphics.hpp>

using namespace sf;
const float SC_X = 800.f;
const float SC_Y = 600.f;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(SC_X, SC_Y), "SFML Works!");
	float r = 200.f;
	CircleShape c(r);
	c.move((SC_X - 2 * r) / 2, (SC_Y - 2 * r) / 2);
	c.setFillColor(Color{190,75,40 });

	const int size = 5;
	CircleShape arr_circle[size];
	for (int i = 0; i < size; i++) {
		arr_circle[i].setRadius(r - 25 * i);
		r = 200 - 25 * i;
		arr_circle[i].move((SC_X - 2 * r) / 2, (SC_Y - 2 * r) / 2);
		arr_circle[i].setFillColor(Color{ (Uint8)(255 - 30 * i),(Uint8)(50 * (i + 1)), (Uint8)(250 - 50 * i) });
	}
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
			
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		// Отрисовка окна 
		window.clear();

        window.draw(c);
		for (int i = 0; i < size; i++) {
			window.draw (arr_circle[i]);
		}
		window.display();
		
	}

	return 0;
}