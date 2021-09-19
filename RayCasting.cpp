#include <SFML/Graphics.hpp>
#include "Light.h"
#include <iostream>
#include <math.h>
#include <vector>;
#include "Board.h"
#include "Block.h"
#include "BigBlock.h"
using namespace sf;
using namespace std;

void oldStuff() {
    /*ector<vector<RectangleShape>> lines;
    vector<RectangleShape> line;
    /// need way to draw lines well // 
    int x = 0;
    int y = 500;
    int xD = 1;
    int yD = -2; // must calcuate max amount of pixels//
    int time = 4;
    //int val = pixelsToEdge(window, x, y) / 255;
    cout << val;
    for (int c = 0; c < 255; c += val) {
        RectangleShape temp({ 1,1 });
        Color co(c, c, c);
        temp.setFillColor(co);
        temp.setPosition(x, y);
        for (int i = 0; i < time; ++i) {
            line.push_back(temp);
            temp.setPosition(x += xD, y += yD);
        }

    }
    lines.push_back(line);
    for (int j = 0; j < lines.size(); ++j) {
        for (int i = 0; i < line.size(); ++i) {
            window.draw(lines.at(j).at(i));
        }
    }
    */
}
int main()
{
    RenderWindow window(sf::VideoMode(1000,1000), "SFML works!");
    Light light;
    Mouse mouse;
    vector<Block*> line;
    Block* temp = new Block(400, 500);
    

    float x = light.getPosition().x + light.getRadius();
    float y = light.getPosition().y + light.getRadius();
    for (int i = 0; i < line.size(); ++i) {
        line.at(i)->makeShadow(x, y);
        line.at(i)->drawShadow(window);
    }
    Board board(100);
    float a = .1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        while (Mouse::isButtonPressed(Mouse::Button::Left)) { // light follows mouse //
            light.setPosition(mouse.getPosition().x - window.getPosition().x - light.getRadius(), mouse.getPosition().y - window.getPosition().y - 2*light.getRadius());
            
            
            window.clear();
            
           
            board.drawAllPixels(window);
            
           board.updateShades(light.getPosition().x + light.getRadius(),light.getPosition().y + light.getRadius(),a);
           
           float x = light.getPosition().x + light.getRadius();
           float y = light.getPosition().y + light.getRadius();
           for (int i = 0; i < line.size(); ++i) {
               line.at(i)->updateShadow(x,y);
               line.at(i)->drawShadow(window);
           }
            window.draw(light);
            
            window.display();
        }
        a += .01;
        
      
      
       
        window.draw(light);
        board.updateShades(light.getPosition().x + light.getRadius(), light.getPosition().y + light.getRadius(), a);
        board.drawAllPixels(window);
        float x = light.getPosition().x + light.getRadius();
           float y = light.getPosition().y + light.getRadius();
           for (int i = 0; i < line.size(); ++i) {
               line.at(i)->updateShadow(x,y);
               line.at(i)->drawShadow(window);
           }
        window.display();
        window.clear();
        

    }

    return 0;
}