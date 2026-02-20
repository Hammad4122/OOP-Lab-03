#include <iostream>
class Rectangle {
private:
    float length;
    float width;    
public:
    // Parameterized constructor   
    Rectangle(float l = 1.0, float w = 1.0) : length(l), width(w) {
        if (l < 0.0 || l > 20.0) {
            length = 1.0;
        }
        if (w < 0.0 || w > 20.0) {
            width = 1.0;
        }
    }
    // Destructor
    ~Rectangle() {
        std::cout << "Rectangle object is destroyed with length "<<length<<" and width "<<width << std::endl;
    }
    // Setters
    void setLength(float l) {
        length = l;
    }
    void setWidth(float w) {
        width = w;
    }
    // Getters
    float getLength() {
        return length;
    }
    float getWidth() {
        return width;
    }
    // Function to calculate perimeter
    float perimeter() {
        return 2 * (length + width);
    }
    // Function to calculate area
    float area() {
        return length * width;
    }
};
int main() {
    Rectangle rect(5.0, 3.0);
    std::cout<<"\nHardcoded Output:"<<std::endl;
    std::cout << "Length: " << rect.getLength() << std::endl;
    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;
    std::cout << "Area: " << rect.area() << std::endl;

    Rectangle rect2;
    float l,w;
    std::cout<<"Default output: "<<std::endl;
    while(true){
        std::cout<<"\nEnter length (0-20): ";
        std::cin>>l;
        if (l >= 0 && l <= 20){
            rect2.setLength(l);
        }
        else{
            std::cout<<"\nInvalid length. Enter length again."<<std::endl;
        }
    }

    while(true){
        std::cout<<"Enter width (0-20): ";
        std::cin>>w;
        if (w >= 0 && w <= 20){
            rect2.setWidth(w);
        }
        else{
            std::cout<<"\nInvalid length. Enter width again."<<std::endl;
        }
    }

    std::cout << "\nLength: " << rect2.getLength() << std::endl;
    std::cout << "Width: " << rect2.getWidth() << std::endl;
    std::cout << "Perimeter: " << rect2.perimeter() << std::endl;
    std::cout << "Area: " << rect2.area() << std::endl;
}