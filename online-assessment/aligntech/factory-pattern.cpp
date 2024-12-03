#include <iostream>
#include <memory>

// Abstract Product
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Shape() {}
};

// Concrete Product 1: Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

// Concrete Product 2: Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

// Concrete Product 3: Triangle
class Triangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Triangle" << std::endl;
    }
};

// Factory Class
class ShapeFactory {
public:
    // Factory method that returns a Shape object
    static std::unique_ptr<Shape> createShape(const std::string& shapeType) {
        if (shapeType == "circle") {
            return std::make_unique<Circle>();
        } else if (shapeType == "rectangle") {
            return std::make_unique<Rectangle>();
        } else if (shapeType == "triangle") {
            return std::make_unique<Triangle>();
        } else {
            throw std::invalid_argument("Unknown shape type");
        }
    }
};

int main() {
    try {
        // Create a Circle object using the Factory
        auto shape1 = ShapeFactory::createShape("circle");
        shape1->draw();  // Output: Drawing a Circle

        // Create a Rectangle object using the Factory
        auto shape2 = ShapeFactory::createShape("rectangle");
        shape2->draw();  // Output: Drawing a Rectangle

        // Create a Triangle object using the Factory
        auto shape3 = ShapeFactory::createShape("triangle");
        shape3->draw();  // Output: Drawing a Triangle
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
