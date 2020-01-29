
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    srand(time(NULL));

    const int WIDTH  = 1000;
    const int HEIGHT = 1000;
    const int R = 30; //promien kuli (strzały)

    int _i;
    float _x, _y, sin, cos, alpha;

    int p_width = 30; // szerokosc platformy (tarczy)
    int p_hieght = 150; // wysokosc platformy (tarczy)
    float p_dx = 12; // szypkosc platform (tarczy)
    int margin = 20; // odleglość platrofmy (tarczy) od sciany (brzegu)

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Hit The Bucket");
    window.setFramerateLimit(60);

    sf::RectangleShape p[2]; // 0 - lewy; 1 - prawy

    p[0].setPosition(sf::Vector2f(margin, (HEIGHT-p_hieght)/2 ));
    p[0].setFillColor(sf::Color::Red);
    p[0].setSize(sf::Vector2f(p_width, p_hieght));

    p[1].setPosition(sf::Vector2f(WIDTH-p_width-margin, (HEIGHT-p_hieght)/2 ));
    p[1].setFillColor(sf::Color::Red);
    p[1].setSize(sf::Vector2f(p_width, p_hieght));

    // pierwszy strzal
    float v = 12.0, vx = 12.0, vy = 0.0;
    if(rand()%2){
        vx = -vx;
    }

    // kula
    sf::CircleShape ball;
    ball.setRadius(R);
    ball.setFillColor(sf::Color::Blue);
    ball.setPosition(sf::Vector2f(WIDTH/2-R, HEIGHT/2-R));

    while( window.isOpen() )
    {
        // czy zamknac program
        sf::Event e;
        while( window.pollEvent(e) )
        {
            // jesli escape lub przyciksk zamkniecia okna
            if( e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) )
                window.close();
                
        }

        // pozycja platform
        // lewa
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        {
            _x = p[0].getPosition().x;
            _y = p[0].getPosition().y;
            _y -= p_dx;

            if( _y <= 0 )
                _y = 0;
            p[0].setPosition(sf::Vector2f(_x, _y));
        }
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        {
            _x = p[0].getPosition().x;
            _y = p[0].getPosition().y;
            _y += p_dx;

            if( _y >= HEIGHT - p_hieght )
                _y = HEIGHT - p_hieght;
            p[0].setPosition(sf::Vector2f(_x, _y));
        }
        // prawa
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
        {
            _x = p[1].getPosition().x;
            _y = p[1].getPosition().y;
            _y -= p_dx;

            if( _y <= 0 )
                _y = 0;
            p[1].setPosition(sf::Vector2f(_x, _y));
        }
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
        {
            _x = p[1].getPosition().x;
            _y = p[1].getPosition().y;
            _y += p_dx;

            if( _y >= HEIGHT - p_hieght )
                _y = HEIGHT - p_hieght;
            p[1].setPosition(sf::Vector2f(_x, _y));
        }
        
        // odbija kule jesli trafi na tarcze
        _x = ball.getPosition().x;
        _y = ball.getPosition().y;
        _x += vx;
        _y += vy;
        ball.setPosition(sf::Vector2f(_x, _y));
        // lewy
        if( _x < margin + R && ball.getGlobalBounds().intersects(p[0].getGlobalBounds()) )
        {
            ball.setPosition(sf::Vector2f(margin + R, _y));
            vx *= -1;
        }
        // prawy
        if( _x > WIDTH - p_width - margin - 2*R && ball.getGlobalBounds().intersects(p[1].getGlobalBounds()) )
        {
            ball.setPosition(sf::Vector2f(WIDTH - p_width - margin - 2*R, _y));
            vx *= -1;
        }

        // odbija pilke jesli trafi na gurna lub dolna krawec
        if( _y < 0 )
        {
            _y = 0;
            vy *= -1;
        }
        else if( _y > HEIGHT - 2*R )
        {
            _y = HEIGHT - 2*R;
            vy *= -1;
        }

        //rysuje
        window.clear();

        window.draw(ball);
        window.draw(p[0]);
        window.draw(p[1]);

        window.display();
    }

    return 0;

}