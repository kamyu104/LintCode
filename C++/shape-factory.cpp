// Time:  O(1)
// Space: O(1)

/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
    virtual void draw() const=0;
};

class Rectangle: public Shape {
public:
    virtual void draw() const {
        cout << " ----" << endl
             << "|    |" << endl
             << " ----" << endl;
    }
};

class Square: public Shape {
public:
    virtual void draw() const {
        cout << " ----" << endl
             << "|    |" << endl
             << "|    |" << endl
             << " ----" << endl;
    }
};

class Triangle: public Shape {
public:
    virtual void draw() const {
        cout << "  /\\" << endl
             << " /  \\" << endl
             << "/____\\" << endl;
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        if (shapeType == "Square") {
            return new Square();
        } else if (shapeType == "Triangle") {
            return new Triangle();
        } else if (shapeType == "Rectangle") {
            return new Rectangle();
        }
    }
};
