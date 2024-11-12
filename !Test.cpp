class Base final {
    // This class cannot be inherited from
};

// Attempting to inherit from Base will cause a compilation error
class Derived : public Base {  // Error: cannot inherit from final class
};
